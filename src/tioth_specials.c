#include "global.h"
#include "tioth_specials.h"
#include "overworld.h"
#include "pokemon.h"
#include "random.h"
#include "script.h"
#include "field_screen_effect.h"
#include "field_player_avatar.h"
#include "event_data.h"
#include "string_util.h"
#include "constants/game_stat.h"
#include "constants/maps.h"
#include "constants/items.h"

EWRAM_DATA u8 playerFacingAtBeforeWarp = DIR_NONE; // 记录玩家转移前的面向
EWRAM_DATA bool8 insideDreamWorld = FALSE;

struct DreamWorld
{
    s8 mapGroup;
    s8 mapNum;
    s8 mapGroup2;
    s8 mapNum2;
};

struct PokemonLoot
{
    u16 item1;
    u16 item2;
};

// 对应梦世界地图的表格
static const struct DreamWorld sDreamWorlds[] = {
    {MAP_GROUP(SPAWN_PLACE), MAP_NUM(SPAWN_PLACE), MAP_GROUP(SPAWN_PLACE_MIRROR), MAP_NUM(SPAWN_PLACE_MIRROR)},
    {-1, -1, -1, -1}, //结束判定点
};

// 特定的掉落道具
static const struct PokemonLoot sPokemonLoots[NUM_SPECIES] =
    {
        [SPECIES_BULBASAUR] = {.item1 = ITEM_LEAF_STONE},
};

#define GENERAL_LOOTS_COUNT 3

// TODO 通用掉落道具
static const u16 sGeneralLoots[GENERAL_LOOTS_COUNT] =
    {
        ITEM_NUGGET, //1
        ITEM_POTION, //2
        ITEM_RARE_CANDY, //3
};

// 切换性别
static void SwitchGender(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
        gSaveBlock2Ptr->playerGender = FEMALE;
    else
        gSaveBlock2Ptr->playerGender = MALE;
}

// 从表提取对应目标切换地图
void GetDreamWorldTargetLocation(s8 *targetMapGroup, s8 *targetmapNum, s16 *x, s16 *y)
{
    const struct MapHeader *mapHeader;
    int i = 0;
    while (sDreamWorlds[i].mapGroup != -1)
    {
        if (sDreamWorlds[i].mapGroup == gSaveBlock1Ptr->location.mapGroup && sDreamWorlds[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            *targetMapGroup = sDreamWorlds[i].mapGroup2;
            *targetmapNum = sDreamWorlds[i].mapNum2;
            break;
        }
        else if (sDreamWorlds[i].mapGroup2 == gSaveBlock1Ptr->location.mapGroup && sDreamWorlds[i].mapNum2 == gSaveBlock1Ptr->location.mapNum)
        {
            *targetMapGroup = sDreamWorlds[i].mapGroup2;
            *targetmapNum = sDreamWorlds[i].mapNum;
            break;
        }
        i++;
    }

    if (*targetMapGroup != -1 || *targetmapNum != -1)
    {
        *x = gSaveBlock1Ptr->pos.x;
        *y = gSaveBlock1Ptr->pos.y;
        mapHeader = Overworld_GetMapHeaderByGroupAndId(*targetMapGroup, *targetmapNum);

        for (i = 0; i < mapHeader->events->objectEventCount; i++)
        {
            if (mapHeader->events->objectEvents[i].x == *x && mapHeader->events->objectEvents[i].y == *y) // 有NPC就无法传送
            {
                *targetMapGroup = -1;
                *targetmapNum = -1;
            }
        }
    }
}

// 返回玩家是否可以切换梦世界
bool8 CanSwitchDreamWorld(void)
{
    s8 targetMapGroup = -1;
    s8 targetmapNum = -1;
    s16 x = -1;
    s16 y = -1;
    GetDreamWorldTargetLocation(&targetMapGroup, &targetmapNum, &x, &y);

    if (targetMapGroup != -1 || targetmapNum != -1)
        return TRUE;
    return FALSE;
}

void SwitchDreamWorld(void)
{
    s8 targetMapGroup = -1;
    s8 targetmapNum = -1;
    s16 x = -1;
    s16 y = -1;

    GetDreamWorldTargetLocation(&targetMapGroup, &targetmapNum, &x, &y);

    if (targetMapGroup != -1 || targetmapNum != -1)
    {
        SwitchGender();
        SetWarpDestination(targetMapGroup, targetmapNum, -1, x, y);
        playerFacingAtBeforeWarp = GetPlayerFacingDirection();
        DoWarp();
        if (insideDreamWorld == FALSE)
        {
            insideDreamWorld = TRUE;
            gGlobalFieldTintMode = QL_TINT_GRAYSCALE;
        }
        else
        {
            insideDreamWorld = FALSE;
            gGlobalFieldTintMode = QL_TINT_NONE;
        }
    }
}

// 获取梦世界里玩家应该面向的位置，然后重置内存
u8 GetDreamWorldTransitionDirection(void)
{
    u8 direction = playerFacingAtBeforeWarp;
    playerFacingAtBeforeWarp = DIR_NONE;
    return direction;
}

// 返回玩家是否在梦世界
bool8 IsDreamWorld(void)
{
    return insideDreamWorld;
}

// 设置限时事件，
// VAR_0x8000=事件编号
// VAR_0x8001=天，单位为游戏时间VAR_0x8002
// VAR_0x8002=小时，单位为游戏时间
// VAR_0x8003=分钟，单位为游戏时间
// 脚本设在loadword 0
void SetTimeEvent(void)
{
    const u8 *script;
    u8 slot = VarGet(VAR_0x8000);
    u8 days = VarGet(VAR_0x8001);

    //换算成真实时间
    int playTimeMinutes = VarGet(VAR_0x8002) + days * 24;
    int playTimeSeconds = VarGet(VAR_0x8003);
    int playTimeHours;
    script = (const u8 *)ReadWord(0);

    if (slot < LIMITED_TIME_EVENT_COUNT)
    {
        //算出脚本触发时机
        playTimeSeconds += gSaveBlock2Ptr->playTimeSeconds;
        playTimeMinutes += gSaveBlock2Ptr->playTimeMinutes;
        playTimeHours = gSaveBlock2Ptr->playTimeHours;

        if (playTimeSeconds >= 60)
        {
            playTimeMinutes += playTimeSeconds / 60;
            playTimeSeconds %= 60;
        }

        if (playTimeMinutes >= 60)
        {
            playTimeHours += playTimeMinutes / 60;
            playTimeMinutes %= 60;
        }

        gSaveBlock1Ptr->limitedTimeEvent[slot].script = script;
        gSaveBlock1Ptr->limitedTimeEvent[slot].playTimeHours = playTimeHours;
        gSaveBlock1Ptr->limitedTimeEvent[slot].playTimeMinutes = playTimeMinutes;
        gSaveBlock1Ptr->limitedTimeEvent[slot].playTimeSeconds = playTimeSeconds;
        gSaveBlock1Ptr->limitedTimeEvent[slot].playTimeVBlanks = gSaveBlock2Ptr->playTimeVBlanks;
    }
}

//清除限时事件，VAR_0x8000=时间事件编号
void ClearTimeEvent(void)
{
    u8 slot = VarGet(VAR_0x8000);
    if (slot < LIMITED_TIME_EVENT_COUNT)
    {
        gSaveBlock1Ptr->limitedTimeEvent[slot].script = 0;
    }
}

void GetWildPokemonBeatensCount(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetGameStat(GAME_STAT_WILD_POKEMON_BEATENS), STR_CONV_MODE_LEFT_ALIGN, 5);
}

void GetTrainerBeatensCount(void)
{
    ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_TRAINER_BEATENS), STR_CONV_MODE_LEFT_ALIGN, 5);
}

// 计算掉落道具
u16 GetPokemonLootItem(u16 speciesId)
{
    u16 item1 = sPokemonLoots[speciesId].item1;
    u16 item2 = sPokemonLoots[speciesId].item2;
    s32 rand = Random() % 100;

    if (item1 != ITEM_NONE && item2 != ITEM_NONE && item1 == item2)
        return item1;
    if (item1 == ITEM_NONE)
        item1 = sGeneralLoots[rand % GENERAL_LOOTS_COUNT]; // 添补通用道具
    if (item2 == ITEM_NONE)
        item2 = sGeneralLoots[rand % GENERAL_LOOTS_COUNT]; // 添补通用道具
    if (rand < 50)
        return item1; // 50%概率获得
    if (rand >= 95)
        return item2; // 5%概率获得
    return ITEM_NONE;
}

void CreateWildHuntingQuest(void)
{
    u16 species = VarGet(VAR_0x8000);
    u16 targetCount = VarGet(VAR_0x8001);
    u16 mapGroup = VarGet(VAR_0x8002);
    u16 mapNum = VarGet(VAR_0x8003);

    gSaveBlock1Ptr->wildHutingQuest.completedCount = 0;
    gSaveBlock1Ptr->wildHutingQuest.species = species;
    gSaveBlock1Ptr->wildHutingQuest.targetCount = targetCount;
    gSaveBlock1Ptr->wildHutingQuest.mapGroup = mapGroup;
    gSaveBlock1Ptr->wildHutingQuest.mapNum = mapNum;
}

void ClearWildHuntingQuest(void)
{
    gSaveBlock1Ptr->wildHutingQuest.species = SPECIES_NONE;
}

bool8 IsWildHuntingQuestActived(void)
{
    return gSaveBlock1Ptr->wildHutingQuest.species != SPECIES_NONE;
}

bool8 IsWildHuntingQuestCompleted(void)
{
    return IsWildHuntingQuestActived() == TRUE && gSaveBlock1Ptr->wildHutingQuest.completedCount == gSaveBlock1Ptr->wildHutingQuest.targetCount;
}

u16 GetWildHuntingTargetCount(void)
{
    return IsWildHuntingQuestActived() ? gSaveBlock1Ptr->wildHutingQuest.targetCount : 0;
}

u16 GetWildHuntingCompletedCount(void)
{
    return IsWildHuntingQuestActived() ? gSaveBlock1Ptr->wildHutingQuest.completedCount : 0;
}

void setMonIVFullStat(void)
{
    u8 slotId = VarGet(VAR_0x8000);
    u8 field = VarGet(VAR_0x8001);
    u32 data = 31;
    field += MON_DATA_HP_IV;
    if (field > MON_DATA_SPDEF_IV || slotId >= PARTY_SIZE)
        return;
    SetMonData(&gPlayerParty[slotId], field, &data);
}

void setMonEVFullStat(void)
{
    u8 slotId = VarGet(VAR_0x8000);
    u8 field = VarGet(VAR_0x8001);
    u32 data = 31;
    field += MON_DATA_HP_EV;
    if (field > MON_DATA_SPDEF_EV || slotId >= PARTY_SIZE)
        return;
    SetMonData(&gPlayerParty[slotId], field, &data);
}
