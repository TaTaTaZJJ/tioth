#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

extern const u16 gUnknown_08D85620[];

// this file's functions
static void ChooseMoveUsedParticle(u8 *textPtr);
static void ChooseTypeOfMoveUsedString(u8 *dst);
static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst);

// EWRAM vars
static EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// const rom data
// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
static const u8 sText_PkmnGainedEXP[] = 
#ifdef CHINESE
_("{B_BUFF1}获得了{B_BUFF2}\n{B_BUFF3}点经验！\p");
#else
_("{B_BUFF1} gained{B_BUFF2}\n{B_BUFF3} EXP. Points!\p");
#endif
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = 
#ifdef CHINESE
_("提升");
#else
_(" a boosted");
#endif
static const u8 sText_PkmnGrewToLv[] = 
#ifdef CHINESE
_("{B_BUFF1}升到了\n等级{B_BUFF2}!{WAIT_SE}\p");
#else
_("{B_BUFF1} grew to\nLV. {B_BUFF2}!{WAIT_SE}\p");
#endif

static const u8 sText_PkmnLearnedMove[] = 
#ifdef CHINESE
_("{B_BUFF1}学会了\n{B_BUFF2}！{WAIT_SE}\p");
#else
_("{B_BUFF1} learned\n{B_BUFF2}!{WAIT_SE}\p");
#endif

static const u8 sText_TryToLearnMove1[] = 
#ifdef CHINESE
_("{B_BUFF1} 想\n学习新的技能 {B_BUFF2}.\p");    //TODO 汉化
#else
_("{B_BUFF1} is trying to\nlearn {B_BUFF2}.\p");
#endif

static const u8 sText_TryToLearnMove2[] = 
#ifdef CHINESE
_("But, {B_BUFF1} 但是\n已经记住4个技能了.\p");   //TODO 汉化
#else
_("But, {B_BUFF1} can't learn\nmore than four moves.\p");
#endif

static const u8 sText_TryToLearnMove3[] = 
#ifdef CHINESE
_("是否忘记一个技能\n来学习 {B_BUFF2}?");    //TODO 汉化
#else
_("Delete a move to make\nroom for {B_BUFF2}?");
#endif

static const u8 sText_PkmnForgotMove[] = 
#ifdef CHINESE
_("{B_BUFF1} 忘记了\n{B_BUFF2}。\p");    //TODO 汉化
#else
_("{B_BUFF1} forgot\n{B_BUFF2}.\p");
#endif

static const u8 sText_StopLearningMove[] = 
#ifdef CHINESE
_("{PAUSE 32}停止学习\n{B_BUFF2}?");   //TODO 汉化
#else
_("{PAUSE 32}Stop learning\n{B_BUFF2}?");
#endif

static const u8 sText_DidNotLearnMove[] = 
#ifdef CHINESE
_("{B_BUFF1} 没有学会\n{B_BUFF2}。\p"); //TODO 汉化
#else
_("{B_BUFF1} did not learn\n{B_BUFF2}.\p");
#endif

static const u8 sText_UseNextPkmn[] = 
#ifdef CHINESE
_("使用下一只宝可梦?"); //TODO 汉化
#else
_("Use next POKéMON?");
#endif

static const u8 sText_AttackMissed[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}的\n攻击落空了!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s\nattack missed!");
#endif

static const u8 sText_PkmnProtectedItself[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}\n保护自己!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}\nprotected itself!");
#endif

static const u8 sText_AvoidedDamage[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} avoided\ndamage with {B_DEF_ABILITY}!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} avoided\ndamage with {B_DEF_ABILITY}!");
#endif

static const u8 sText_PkmnMakesGroundMiss[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} makes GROUND\nmoves miss with {B_DEF_ABILITY}!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} makes GROUND\nmoves miss with {B_DEF_ABILITY}!");
#endif

static const u8 sText_PkmnAvoidedAttack[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 躲过了\n攻击！"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} avoided\nthe attack!");
#endif

static const u8 sText_ItDoesntAffect[] = 
#ifdef CHINESE
_("效果很小\n{B_DEF_NAME_WITH_PREFIX}…");  //TODO 汉化
#else
_("It doesn't affect\n{B_DEF_NAME_WITH_PREFIX}…");
#endif

static const u8 sText_AttackerFainted[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}\n倒下了!\p");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}\nfainted!\p");
#endif

static const u8 sText_TargetFainted[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}\n被击败了!\p");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}\nfainted!\p");
#endif

static const u8 sText_PlayerGotMoney[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME} 获得 ¥{B_BUFF1}\nfor winning!\p");    //TODO 汉化
#else
_("{B_PLAYER_NAME} got ¥{B_BUFF1}\nfor winning!\p");
#endif

static const u8 sText_PlayerWhiteout[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME} 没有\n可以战斗的 POKéMON!\p");  //TODO 汉化
#else
_("{B_PLAYER_NAME} is out of\nusable POKéMON!\p");
#endif

static const u8 sText_PlayerWhiteout2[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME} 一片空白!{PAUSE_UNTIL_PRESS}");    //TODO 汉化
#else
_("{B_PLAYER_NAME} whited out!{PAUSE_UNTIL_PRESS}");
#endif

static const u8 sText_PreventsEscape[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} 无法\n逃脱 {B_SCR_ACTIVE_ABILITY}!\p");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} prevents\nescape with {B_SCR_ACTIVE_ABILITY}!\p");
#endif

static const u8 sText_CantEscape2[] = 
#ifdef CHINESE
_("无法逃走！\p");   //TODO 汉化
#else
_("Can't escape!\p");
#endif

static const u8 sText_AttackerCantEscape[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 无法逃走！");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} can't escape!");
#endif

static const u8 sText_HitXTimes[] = 
#ifdef CHINESE
_("击中 {B_BUFF1} 次！");    //TODO 汉化
#else
_("Hit {B_BUFF1} time(s)!");
#endif

static const u8 sText_PkmnFellAsleep[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX}\n陷入沉睡！");    //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX}\nfell asleep!");
#endif

static const u8 sText_PkmnMadeSleep[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nmade {B_EFF_NAME_WITH_PREFIX} 睡着了!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nmade {B_EFF_NAME_WITH_PREFIX} sleep!");
#endif

static const u8 sText_PkmnAlreadyAsleep[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} is\n已经睡着了!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} is\nalready asleep!");
#endif

static const u8 sText_PkmnAlreadyAsleep2[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is\n已经睡着了!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is\nalready asleep!");
#endif

static const u8 sText_PkmnWasntAffected[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}\n没有效果!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}\nwasn't affected!");
#endif

static const u8 sText_PkmnWasPoisoned[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX}\n中毒了!");   //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX}\nwas poisoned!");
#endif

static const u8 sText_PkmnPoisonedBy[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX} 由于中毒\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_BUFF1}!");    //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX} was poisoned by\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_BUFF1}!");
#endif

static const u8 sText_PkmnHurtByPoison[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 受到伤害\n因为中毒!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is hurt\nby poison!");
#endif

static const u8 sText_PkmnAlreadyPoisoned[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 已经\n中毒了.");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} is already\npoisoned.");
#endif

static const u8 sText_PkmnBadlyPoisoned[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX} 剧\n毒!");  //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX} is badly\npoisoned!");
#endif

static const u8 sText_PkmnEnergyDrained[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} had its\n体力耗尽!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} had its\nenergy drained!");
#endif

static const u8 sText_PkmnWasBurned[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX} 烧伤!");  //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX} was burned!");
#endif

static const u8 sText_PkmnBurnedBy[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n烧伤 {B_EFF_NAME_WITH_PREFIX}!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nburned {B_EFF_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_PkmnHurtByBurn[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 受到伤害\n因为烧伤!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is hurt\nby its burn!");
#endif

static const u8 sText_PkmnAlreadyHasBurn[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 已经\n烧伤了."); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} already\nhas a burn.");
#endif

static const u8 sText_PkmnWasFrozen[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX} was\n冰冻 solid!");   //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX} was\nfrozen solid!");
#endif

static const u8 sText_PkmnFrozenBy[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n冻结 {B_EFF_NAME_WITH_PREFIX} solid!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nfroze {B_EFF_NAME_WITH_PREFIX} solid!");
#endif

static const u8 sText_PkmnIsFrozen[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is\n冻住了!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is\nfrozen solid!");
#endif

static const u8 sText_PkmnWasDefrosted[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} was\n解除冰冻!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was\ndefrosted!");
#endif

static const u8 sText_PkmnWasDefrosted2[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} was\n解除冰冻!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} was\ndefrosted!");
#endif

static const u8 sText_PkmnWasDefrostedBy[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} was\n解除冰冻 {B_CURRENT_MOVE}!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} was\ndefrosted by {B_CURRENT_MOVE}!");
#endif

static const u8 sText_PkmnWasParalyzed[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX} 被麻痹了!\n无法行动!"); //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX} is paralyzed!\nIt may be unable to move!");
#endif

static const u8 sText_PkmnWasParalyzedBy[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n麻痹了 {B_EFF_NAME_WITH_PREFIX}!\无法行动!");  //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n麻痹了 {B_EFF_NAME_WITH_PREFIX}!\lIt may be unable to move!");
#endif

static const u8 sText_PkmnIsParalyzed[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 被麻痹了!\n无法行动!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is paralyzed!\nIt can't move!");
#endif

static const u8 sText_PkmnIsAlreadyParalyzed[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} is\n已经麻痹了!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} is\nalready paralyzed!");
#endif

static const u8 sText_PkmnHealedParalysis[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} was\n麻痹解除了!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was\nhealed of paralysis!");
#endif

static const u8 sText_PkmnDreamEaten[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s\n梦被吃掉了!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s\ndream was eaten!");
#endif

static const u8 sText_StatsWontIncrease[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\nwon't go higher!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\nwon't go higher!");
#endif

static const u8 sText_StatsWontDecrease[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\n不能被降低!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\nwon't go lower!");
#endif

static const u8 sText_TeamStoppedWorking[] = 
#ifdef CHINESE
_("你的 {B_BUFF1}\n在闲逛!");   //TODO 汉化
#else
_("Your team's {B_BUFF1}\nstopped working!");
#endif

static const u8 sText_FoeStoppedWorking[] = 
#ifdef CHINESE
_("敌人的 {B_BUFF1}\n在闲逛!"); //TODO 汉化
#else
_("The foe's {B_BUFF1}\nstopped working!");
#endif

static const u8 sText_PkmnIsConfused[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is\n开始混乱了!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is\nconfused!");
#endif

static const u8 sText_PkmnHealedConfusion[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} snapped\n解除混乱!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} snapped\nout of confusion!");
#endif

static const u8 sText_PkmnWasConfused[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX} became\n混乱了!");    //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX} became\nconfused!");
#endif

static const u8 sText_PkmnAlreadyConfused[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} is\n已经混乱了!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} is\nalready confused!");
#endif

static const u8 sText_PkmnFellInLove[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}\n被迷倒了!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}\nfell in love!");
#endif

static const u8 sText_PkmnInLove[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is 被迷倒了\nwith {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is in love\nwith {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_PkmnImmobilizedByLove[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is\n已经被迷倒了!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is\nimmobilized by love!");
#endif

static const u8 sText_PkmnBlownAway[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} was\n吹走!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was\nblown away!");
#endif

static const u8 sText_PkmnChangedType[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} transformed\ninto the {B_BUFF1} type!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} transformed\ninto the {B_BUFF1} type!");
#endif

static const u8 sText_PkmnFlinched[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 畏缩!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} flinched!");
#endif

static const u8 sText_PkmnRegainedHealth[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 恢复\n健康!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} regained\nhealth!");
#endif

static const u8 sText_PkmnHPFull[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s\n生命值已经满了!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s\nHP is full!");
#endif

static const u8 sText_PkmnRaisedSpDef[] = 
#ifdef CHINESE
_("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\nPP值提升了!");   //TODO 汉化
#else
_("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\nraised SP. DEF!");
#endif

static const u8 sText_PkmnRaisedSpDefALittle[] = 
#ifdef CHINESE
_("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\n提升了一点PP值!");  //TODO 汉化
#else
_("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\nraised SP. DEF a little!");
#endif

static const u8 sText_PkmnRaisedDef[] = 
#ifdef CHINESE
_("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\n防御力提高了!");   //TODO 汉化
#else
_("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\nraised DEFENSE!");
#endif

static const u8 sText_PkmnRaisedDefALittle[] = 
#ifdef CHINESE
_("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\n提高了一点防御!");  //TODO 汉化
#else
_("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE}\nraised DEFENSE a little!");
#endif

static const u8 sText_PkmnCoveredByVeil[] = 
#ifdef CHINESE
_("{B_ATK_PREFIX2}'s 我方全体\n披上了神秘面纱!");    //TODO 汉化
#else
_("{B_ATK_PREFIX2}'s party is covered\nby a veil!");
#endif

static const u8 sText_PkmnUsedSafeguard[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s 我方全体\n得到了保护!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s party is protected\nby SAFEGUARD!");
#endif

static const u8 sText_PkmnSafeguardExpired[] = 
#ifdef CHINESE
_("{B_ATK_PREFIX3}'s 我方全体不再\n受到保护!"); //TODO 汉化
#else
_("{B_ATK_PREFIX3}'s party is no longer\nprotected by SAFEGUARD!");
#endif

static const u8 sText_PkmnWentToSleep[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 使用了\n睡觉!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} went\nto sleep!");
#endif

static const u8 sText_PkmnSleptHealthy[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 睡着了并且\n恢复了健康!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} slept and\nbecame healthy!");
#endif

static const u8 sText_PkmnWhippedWhirlwind[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} whipped\n刮起一阵旋风!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} whipped\nup a whirlwind!");
#endif

static const u8 sText_PkmnTookSunlight[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 使用\n大晴天!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} took\nin sunlight!");
#endif

static const u8 sText_PkmnLoweredHead[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} lowered\nits head!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} lowered\nits head!");
#endif

static const u8 sText_PkmnIsGlowing[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 变得闪耀!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is glowing!");
#endif

static const u8 sText_PkmnFlewHigh[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 飞上\n天空!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} flew\nup high!");
#endif

static const u8 sText_PkmnDugHole[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 挖洞!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} dug a hole!");
#endif

static const u8 sText_PkmnHidUnderwater[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 潜入\n水中!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} hid\nunderwater!");
#endif

static const u8 sText_PkmnSprangUp[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 攀瀑!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} sprang up!");
#endif

static const u8 sText_PkmnSqueezedByBind[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 被挤压\n{B_ATK_NAME_WITH_PREFIX}'s BIND!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was squeezed by\n{B_ATK_NAME_WITH_PREFIX}'s BIND!");
#endif

static const u8 sText_PkmnTrappedInVortex[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 被困在\n漩涡中!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was trapped\nin the vortex!");
#endif

static const u8 sText_PkmnTrappedBySandTomb[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 被困在\n流沙地狱!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was trapped\nby SAND TOMB!");
#endif

static const u8 sText_PkmnWrappedBy[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 被包围\n{B_ATK_NAME_WITH_PREFIX}!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was WRAPPED by\n{B_ATK_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_PkmnClamped[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 夹紧\n{B_DEF_NAME_WITH_PREFIX}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} CLAMPED\n{B_DEF_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_PkmnHurtBy[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 受到伤害\nby {B_BUFF1}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is hurt\nby {B_BUFF1}!");
#endif

static const u8 sText_PkmnFreedFrom[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 逃脱了\n从 {B_BUFF1}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} was freed\nfrom {B_BUFF1}!");
#endif

static const u8 sText_PkmnCrashed[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 连续\n攻击!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} kept going\nand crashed!");
#endif

const u8 gText_PkmnShroudedInMist[] = 
#ifdef CHINESE
_("{B_ATK_PREFIX2} became\n薄雾笼罩着!"); //TODO 汉化
#else
_("{B_ATK_PREFIX2} became\nshrouded in MIST!");
#endif

static const u8 sText_PkmnProtectedByMist[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} 被保护着\n薄雾!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is protected\nby MIST!");
#endif

const u8 gText_PkmnGettingPumped[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is getting\npumped!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is getting\npumped!");
#endif

static const u8 sText_PkmnHitWithRecoil[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is hit\n畏缩了!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is hit\nwith recoil!");
#endif

static const u8 sText_PkmnProtectedItself2[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 保护\n自我!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} protected\nitself!");
#endif

static const u8 sText_PkmnBuffetedBySandstorm[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 飞沙走石\n刮起了沙尘暴!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is buffeted\nby the sandstorm!");
#endif

static const u8 sText_PkmnPeltedByHail[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 被砸到了\n下起了冰雹!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is pelted\nby HAIL!");
#endif

static const u8 sText_PkmnsXWoreOff[] = 
#ifdef CHINESE
_("{B_ATK_PREFIX1}'s {B_BUFF1}\nwore off!");    //TODO 汉化
#else
_("{B_ATK_PREFIX1}'s {B_BUFF1}\nwore off!");
#endif

static const u8 sText_PkmnSeeded[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 种下种子!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was seeded!");
#endif

static const u8 sText_PkmnEvadedAttack[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 闪避\n攻击!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} evaded\nthe attack!");
#endif

static const u8 sText_PkmnSappedByLeechSeed[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s 体力值\n寄生种子!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s health is\nsapped by LEECH SEED!");
#endif

static const u8 sText_PkmnFastAsleep[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 很快\n睡着."); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is fast\nasleep.");
#endif

static const u8 sText_PkmnWokeUp[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 醒来!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} woke up!");
#endif

static const u8 sText_PkmnUproarKeptAwake[] = 
#ifdef CHINESE
_("But {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s 吵闹\n不能入睡!");  //TODO 汉化
#else
_("But {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s UPROAR\nkept it awake!");
#endif

static const u8 sText_PkmnWokeUpInUproar[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 醒来\n吵闹中!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} woke up\nin the UPROAR!");
#endif

static const u8 sText_PkmnCausedUproar[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 变得\n大吵大闹!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} caused\nan UPROAR!");
#endif

static const u8 sText_PkmnMakingUproar[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 正在\n大吵大闹!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is making\nan UPROAR!");
#endif

static const u8 sText_PkmnCalmedDown[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 冷静下来了."); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} calmed down.");
#endif

static const u8 sText_PkmnCantSleepInUproar[] = 
#ifdef CHINESE
_("But {B_DEF_NAME_WITH_PREFIX} 不能\n在大吵大闹中睡着!");   //TODO 汉化
#else
_("But {B_DEF_NAME_WITH_PREFIX} can't\nsleep in an UPROAR!");
#endif

static const u8 sText_PkmnStockpiled[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 蓄力\n{B_BUFF1}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} STOCKPILED\n{B_BUFF1}!");
#endif

static const u8 sText_PkmnCantStockpile[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} can't\n不在蓄力!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} can't\nSTOCKPILE any more!");
#endif

static const u8 sText_PkmnCantSleepInUproar2[] = 
#ifdef CHINESE
_("But {B_DEF_NAME_WITH_PREFIX} 不能\n睡觉中大吵大闹!");   //TODO 汉化
#else
_("But {B_DEF_NAME_WITH_PREFIX} can't\nsleep in an UPROAR!");
#endif

static const u8 sText_UproarKeptPkmnAwake[] = 
#ifdef CHINESE
_("吵闹保持\n{B_DEF_NAME_WITH_PREFIX} 清醒!");  //TODO 汉化
#else
_("But the UPROAR kept\n{B_DEF_NAME_WITH_PREFIX} awake!");
#endif

static const u8 sText_PkmnStayedAwakeUsing[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 保持清醒\nusing its {B_DEF_ABILITY}!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} stayed awake\nusing its {B_DEF_ABILITY}!");
#endif

static const u8 sText_PkmnStoringEnergy[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 正在储存\n能量!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is storing\nenergy!");
#endif

static const u8 sText_PkmnUnleashedEnergy[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 释放\能量!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} unleashed\nenergy!");
#endif

static const u8 sText_PkmnFatigueConfusion[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} became\nconfused due to fatigue!"); //TODO 汉化 123
#else
_("{B_ATK_NAME_WITH_PREFIX} became\nconfused due to fatigue!");
#endif

static const u8 sText_PlayerPickedUpMoney[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME} 捡到了\n¥{B_BUFF1}!\p");  //TODO 汉化
#else
_("{B_PLAYER_NAME} picked up\n¥{B_BUFF1}!\p");
#endif

static const u8 sText_PkmnUnaffected[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} is\n没有效果!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} is\nunaffected!");
#endif

static const u8 sText_PkmnTransformedInto[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 变成\ninto {B_BUFF1}!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} transformed\ninto {B_BUFF1}!");
#endif

static const u8 sText_PkmnMadeSubstitute[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 制造了\n一个替身!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} made\na SUBSTITUTE!");
#endif

static const u8 sText_PkmnHasSubstitute[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 已经\n制造了一个替身!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} already\nhas a SUBSTITUTE!");
#endif

static const u8 sText_SubstituteDamaged[] = 
#ifdef CHINESE
_("替身受到了伤害\nfor {B_DEF_NAME_WITH_PREFIX}!\p");   //TODO 汉化
#else
_("The SUBSTITUTE took damage\nfor {B_DEF_NAME_WITH_PREFIX}!\p");
#endif

static const u8 sText_PkmnSubstituteFaded[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s\n替身消失了!\p");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s\nSUBSTITUTE faded!\p");
#endif

static const u8 sText_PkmnMustRecharge[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} must\n开始充电!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} must\nrecharge!");
#endif

static const u8 sText_PkmnRageBuilding[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s RAGE\nis building!"); //TODO 汉化   one
#else
_("{B_DEF_NAME_WITH_PREFIX}'s RAGE\nis building!");
#endif

static const u8 sText_PkmnMoveWasDisabled[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\n被封印!");   //TODO 汉化    one
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\nwas disabled!");
#endif

static const u8 sText_PkmnMoveDisabledNoMore[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is disabled\nno more!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is disabled\nno more!");
#endif

static const u8 sText_PkmnGotEncore[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} got\n再来一次!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} got\nan ENCORE!");
#endif

static const u8 sText_PkmnEncoreEnded[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s 再来一次\n终止了!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s ENCORE\nended!");
#endif

static const u8 sText_PkmnTookAim[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} took aim\nat {B_DEF_NAME_WITH_PREFIX}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} took aim\nat {B_DEF_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_PkmnSketchedMove[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 素描了\n{B_BUFF1}!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} SKETCHED\n{B_BUFF1}!");
#endif

static const u8 sText_PkmnTryingToTakeFoe[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is trying\nto take its foe with it!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is trying\nto take its foe with it!");
#endif

static const u8 sText_PkmnTookFoe[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} took\n{B_ATK_NAME_WITH_PREFIX} with it!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} took\n{B_ATK_NAME_WITH_PREFIX} with it!");
#endif

static const u8 sText_PkmnReducedPP[] = 
#ifdef CHINESE
_("变轻了 {B_DEF_NAME_WITH_PREFIX}'s\n{B_BUFF1} by {B_BUFF2}!");   //TODO 汉化
#else
_("Reduced {B_DEF_NAME_WITH_PREFIX}'s\n{B_BUFF1} by {B_BUFF2}!");
#endif

static const u8 sText_PkmnStoleItem[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 偷取\n{B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} stole\n{B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
#endif

static const u8 sText_TargetCantEscapeNow[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} can't\n现在不能逃跑!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} can't\nescape now!");
#endif

static const u8 sText_PkmnFellIntoNightmare[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 陷入了\n噩梦!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} fell into\na NIGHTMARE!");
#endif

static const u8 sText_PkmnLockedInNightmare[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 被缠住\n噩梦!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is locked\nin a NIGHTMARE!");
#endif

static const u8 sText_PkmnLaidCurse[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 削减了自己的生命并且\n诅咒了 {B_DEF_NAME_WITH_PREFIX}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} cut its own HP and\nlaid a CURSE on {B_DEF_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_PkmnAfflictedByCurse[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 受到伤害\n来自诅咒!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is afflicted\nby the CURSE!");
#endif

static const u8 sText_SpikesScattered[] = 
#ifdef CHINESE
_("铁菱遍布\n对手的四周!");    //TODO 汉化
#else
_("SPIKES were scattered all around\nthe opponent's side!");
#endif

static const u8 sText_PkmnHurtBySpikes[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} 受到伤害\n铁菱!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is hurt\nby SPIKES!");
#endif

static const u8 sText_PkmnIdentified[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 认出\n{B_DEF_NAME_WITH_PREFIX}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} identified\n{B_DEF_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_PkmnPerishCountFell[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s 倒计时\n灭亡 {B_BUFF1}!");   //TODO 汉化 （死亡灭歌）
#else
_("{B_ATK_NAME_WITH_PREFIX}'s PERISH count\nfell to {B_BUFF1}!");
#endif

static const u8 sText_PkmnBracedItself[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 撑住了\nitself!");  //TODO 汉化   (挺住）
#else
_("{B_ATK_NAME_WITH_PREFIX} braced\nitself!");
#endif

static const u8 sText_PkmnEnduredHit[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 忍住\n攻击!");    //TODO 汉化 （忍耐）
#else
_("{B_DEF_NAME_WITH_PREFIX} ENDURED\nthe hit!");
#endif

static const u8 sText_MagnitudeStrength[] = 
#ifdef CHINESE
_("震级变化 {B_BUFF1}!");  //TODO 汉化 （震级变化）
#else
_("MAGNITUDE {B_BUFF1}!");
#endif

static const u8 sText_PkmnCutHPMaxedAttack[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 减少了自己的HP\n并且攻击提升到最高!");    //TODO 汉化 （腹鼓）
#else
_("{B_ATK_NAME_WITH_PREFIX} cut its own HP\nand maximized ATTACK!");
#endif

static const u8 sText_PkmnCopiedStatChanges[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} copied\n{B_DEF_NAME_WITH_PREFIX}'s stat changes!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} copied\n{B_DEF_NAME_WITH_PREFIX}'s stat changes!");
#endif

static const u8 sText_PkmnGotFree[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} got free of\n{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} got free of\n{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!");
#endif

static const u8 sText_PkmnShedLeechSeed[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} shed\nLEECH SEED!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} shed\nLEECH SEED!");
#endif

static const u8 sText_PkmnBlewAwaySpikes[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 清除\n钉子!");   //TODO 汉化  (高速旋转/扫钉）
#else
_("{B_ATK_NAME_WITH_PREFIX} blew away\nSPIKES!");
#endif

static const u8 sText_PkmnFledFromBattle[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} fled from\nbattle!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} fled from\nbattle!");
#endif

static const u8 sText_PkmnForesawAttack[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 预知了\n攻击");  //TODO 汉化   （预知未来   初始）
#else
_("{B_ATK_NAME_WITH_PREFIX} foresaw\nan attack!");
#endif

static const u8 sText_PkmnTookAttack[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 受到了\n{B_BUFF1} 未来攻击!");  //TODO 汉化  （预知未来   后续 ）
#else
_("{B_DEF_NAME_WITH_PREFIX} took the\n{B_BUFF1} attack!");
#endif

static const u8 sText_PkmnChoseXAsDestiny[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} chose\n{B_CURRENT_MOVE} as its destiny!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} chose\n{B_CURRENT_MOVE} as its destiny!");
#endif

static const u8 sText_PkmnAttack[] = 
#ifdef CHINESE
_("{B_BUFF1}'s attack!");   //TODO 汉化
#else
_("{B_BUFF1}'s attack!");
#endif

static const u8 sText_PkmnCenterAttention[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 吸引了\n全场的注意力!"); //TODO 汉化  （看我嘛）
#else
_("{B_ATK_NAME_WITH_PREFIX} became the\ncenter of attention!");
#endif

static const u8 sText_PkmnChargingPower[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 开启了\n充电模式!");   //TODO 汉化  （充电）
#else
_("{B_ATK_NAME_WITH_PREFIX} began\ncharging power!");
#endif

static const u8 sText_NaturePowerTurnedInto[] = 
#ifdef CHINESE
_("自然能力变成了\n{B_CURRENT_MOVE}!");   //TODO 汉化   （自然之力）
#else
_("NATURE POWER turned into\n{B_CURRENT_MOVE}!");
#endif

static const u8 sText_PkmnStatusNormal[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s 异常状态\n恢复!");    //TODO 汉化  （焕然一新） ？
#else
_("{B_ATK_NAME_WITH_PREFIX}'s status\nreturned to normal!");
#endif

static const u8 sText_PkmnSubjectedToTorment[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} was subjected\nto TORMENT!");   //TODO 汉化 
#else
_("{B_DEF_NAME_WITH_PREFIX} was subjected\nto TORMENT!");
#endif

static const u8 sText_PkmnTighteningFocus[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is tightening\nits focus!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is tightening\nits focus!");
#endif

static const u8 sText_PkmnFellForTaunt[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 遭到了\n挑衅!"); //TODO 汉化    （挑衅）
#else
_("{B_DEF_NAME_WITH_PREFIX} fell for\nthe Taunt!");
#endif

static const u8 sText_PkmnReadyToHelp[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 准备好\n帮助 {B_DEF_NAME_WITH_PREFIX}!");  //TODO 汉化   （帮助）
#else
_("{B_ATK_NAME_WITH_PREFIX} is ready to\nhelp {B_DEF_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_PkmnSwitchedItems[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 交换了\n对手的携带道具!");   //TODO 汉化   （戏法）
#else
_("{B_ATK_NAME_WITH_PREFIX} switched\nitems with its opponent!");
#endif

static const u8 sText_PkmnObtainedX[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} obtained\n{B_BUFF1}."); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} obtained\n{B_BUFF1}.");
#endif

static const u8 sText_PkmnObtainedX2[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} obtained\n{B_BUFF2}."); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} obtained\n{B_BUFF2}.");
#endif

static const u8 sText_PkmnObtainedXYObtainedZ[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} obtained\n{B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} obtained\n{B_BUFF2}.");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} obtained\n{B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} obtained\n{B_BUFF2}.");
#endif

static const u8 sText_PkmnCopiedFoe[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 模仿\n{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!");  //TODO 汉化     (模仿）   ？？？？
#else
_("{B_ATK_NAME_WITH_PREFIX} copied\n{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!");
#endif

static const u8 sText_PkmnMadeWish[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 许愿!"); //TODO 汉化  （祈愿）
#else
_("{B_ATK_NAME_WITH_PREFIX} made a WISH!");
#endif

static const u8 sText_PkmnWishCameTrue[] = 
#ifdef CHINESE
_("{B_BUFF1}'s 愿望\n实现了!");  //TODO 汉化  （祈愿  后续）
#else
_("{B_BUFF1}'s WISH\ncame true!");
#endif

static const u8 sText_PkmnPlantedRoots[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 扎根!");   //TODO 汉化       （扎根）
#else
_("{B_ATK_NAME_WITH_PREFIX} planted its roots!");
#endif

static const u8 sText_PkmnAbsorbedNutrients[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 吸收了\n根部的营养!");  //TODO 汉化 （扎根 后续）
#else
_("{B_ATK_NAME_WITH_PREFIX} absorbed\nnutrients with its roots!");
#endif

static const u8 sText_PkmnAnchoredItself[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 牢牢地\n把根深入地下!"); //TODO 汉化   (扎根   不能被脱离战斗的描述）
#else
_("{B_DEF_NAME_WITH_PREFIX} anchored\nitself with its roots!");
#endif

static const u8 sText_PkmnWasMadeDrowsy[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 使得\n{B_DEF_NAME_WITH_PREFIX} 昏昏欲睡!");   //TODO 汉化   （哈欠）
#else
_("{B_ATK_NAME_WITH_PREFIX} made\n{B_DEF_NAME_WITH_PREFIX} drowsy!");
#endif

static const u8 sText_PkmnKnockedOff[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} knocked off\n{B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} knocked off\n{B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
#endif

static const u8 sText_PkmnSwappedAbilities[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 交换了特性\n和对方!");    //TODO 汉化  （特性互换）
#else
_("{B_ATK_NAME_WITH_PREFIX} swapped abilities\nwith its opponent!");
#endif

static const u8 sText_PkmnSealedOpponentMove[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} sealed the\nopponent's move(s)!");  //TODO 汉化  （封印）      ？？？？
#else
_("{B_ATK_NAME_WITH_PREFIX} sealed the\nopponent's move(s)!");
#endif

static const u8 sText_PkmnWantsGrudge[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 想让\n对手背负怨念!");    //TODO 汉化  （怨念）  
#else
_("{B_ATK_NAME_WITH_PREFIX} wants the\nopponent to bear a GRUDGE!");
#endif

static const u8 sText_PkmnLostPPGrudge[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} 失去\n因为怨念所有的PP值!");  //TODO 汉化 （怨念   后续）
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} lost\nall its PP due to the GRUDGE!");
#endif

static const u8 sText_PkmnShroudedItself[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} shrouded\nitself in {B_CURRENT_MOVE}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} shrouded\nitself in {B_CURRENT_MOVE}!");
#endif

static const u8 sText_PkmnMoveBounced[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE}\n被魔术外衣反弹回来了!");  //TODO 汉化  （魔法反射） 
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE}\nwas bounced back by MAGIC COAT!");
#endif

static const u8 sText_PkmnWaitsForTarget[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} waits for a target\nto make a move!");  //TODO 汉化    等待目标 /采取行动
#else
_("{B_ATK_NAME_WITH_PREFIX} waits for a target\nto make a move!");
#endif

static const u8 sText_PkmnSnatchedMove[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} SNATCHED\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s move!");    //TODO 汉化     抢夺 移动 (抢先一步*4） ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX} SNATCHED\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s move!");
#endif

static const u8 sText_ElectricityWeakened[] = 
#ifdef CHINESE
_("电气的力量\n减弱了");    //TODO 汉化   （玩泥巴）
#else
_("Electricity's power was\nweakened!");
#endif

static const u8 sText_FireWeakened[] = 
#ifdef CHINESE
_("火焰的力量\n减弱了!");   //TODO 汉化    （玩水）
#else
_("Fire's power was\nweakened!");
#endif

static const u8 sText_XFoundOneY[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} found\none {B_LAST_ITEM}!");    //TODO 汉化  （找到/建立 1） ？？？
#else
_("{B_ATK_NAME_WITH_PREFIX} found\none {B_LAST_ITEM}!");
#endif

static const u8 sText_SoothingAroma[] = 
#ifdef CHINESE
_("一股沁人的香气\n弥漫开来!");    //TODO 汉化   （芳香治疗）
#else
_("A soothing aroma wafted\nthrough the area!");
#endif

static const u8 sText_ItemsCantBeUsedNow[] = 
#ifdef CHINESE
_("Items can't be used now.{PAUSE 64}");    //TODO 汉化  （现在物品不能使用） ？？？
#else
_("Items can't be used now.{PAUSE 64}");
#endif

static const u8 sText_ForXCommaYZ[] = 
#ifdef CHINESE
_("For {B_SCR_ACTIVE_NAME_WITH_PREFIX},\n{B_LAST_ITEM} {B_BUFF1}"); //TODO 汉化      ？？？
#else
_("For {B_SCR_ACTIVE_NAME_WITH_PREFIX},\n{B_LAST_ITEM} {B_BUFF1}");
#endif

static const u8 sText_PkmnUsedXToGetPumped[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} used\n{B_LAST_ITEM} to get pumped!");    //TODO 汉化 （吸取 吸血 吸收 ） ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} used\n{B_LAST_ITEM} to get pumped!");
#endif

static const u8 sText_PkmnLostFocus[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} lost its\nfocus and couldn't move!");   //TODO 汉化 丢失，动弹不得 （击掌奇袭） ？？？
#else
_("{B_ATK_NAME_WITH_PREFIX} lost its\nfocus and couldn't move!");
#endif

static const u8 sText_PkmnWasDraggedOut[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} was\ndragged out!\p");  //TODO 汉化  拖出 ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX} was\ndragged out!\p");
#endif

static const u8 sText_TheWallShattered[] = 
#ifdef CHINESE
_("墙被打破了!");   //TODO 汉化  （瓦劈）
#else
_("The wall shattered!");
#endif

static const u8 sText_ButNoEffect[] = 
#ifdef CHINESE
_("But it had no effect!"); //TODO 汉化 （没有效果） ？？？
#else
_("But it had no effect!");
#endif

static const u8 sText_PkmnHasNoMovesLeft[] = 
#ifdef CHINESE
_("{B_ACTIVE_NAME_WITH_PREFIX} has no\nmoves left!\p"); //TODO 汉化 向左移动 离场 ？？？
#else
_("{B_ACTIVE_NAME_WITH_PREFIX} has no\nmoves left!\p");
#endif

static const u8 sText_PkmnMoveIsDisabled[] = 
#ifdef CHINESE
_("{B_ACTIVE_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE}\nis disabled!\p");    //TODO 汉化 丧失 能力  ？？？
#else
_("{B_ACTIVE_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE}\nis disabled!\p");
#endif

static const u8 sText_PkmnCantUseMoveTorment[] = 
#ifdef CHINESE
_("{B_ACTIVE_NAME_WITH_PREFIX} can't use the same\nmove in a row due to the Torment!\p");   //TODO 汉化 无法重复 受折磨连续移动 ？？？
#else
_("{B_ACTIVE_NAME_WITH_PREFIX} can't use the same\nmove in a row due to the Torment!\p");
#endif

static const u8 sText_PkmnCantUseMoveTaunt[] = 
#ifdef CHINESE
_("{B_ACTIVE_NAME_WITH_PREFIX} 无法使用\n{B_CURRENT_MOVE} 在挑衅后!\p");    //TODO 汉化 （挑衅 后续）
#else
_("{B_ACTIVE_NAME_WITH_PREFIX} can't use\n{B_CURRENT_MOVE} after the Taunt!\p");
#endif

static const u8 sText_PkmnCantUseMoveSealed[] = 
#ifdef CHINESE
_("{B_ACTIVE_NAME_WITH_PREFIX} 无法使用\n封印 {B_CURRENT_MOVE}!\p"); //TODO 汉化  （封印） ？？？
#else
_("{B_ACTIVE_NAME_WITH_PREFIX} can't use the\nsealed {B_CURRENT_MOVE}!\p");
#endif

static const u8 sText_PkmnCantUseMoveThroatChop[] = 
#ifdef CHINESE
_("{B_ACTIVE_NAME_WITH_PREFIX} 无法使用\n{B_CURRENT_MOVE} 失声!\p"); //TODO 汉化 （失声的  唱歌） ？？？
#else
_("{B_ACTIVE_NAME_WITH_PREFIX} can't use\n{B_CURRENT_MOVE} due to Throat Chop!\p");
#endif

static const u8 sText_PkmnMadeItRain[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n下起了雨!");   //TODO 汉化 （祈雨）
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nmade it rain!");
#endif

static const u8 sText_PkmnRaisedSpeed[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n速度等级提升了!");   //TODO 汉化 （提高速度） ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nraised its SPEED!");
#endif

static const u8 sText_PkmnProtectedBy[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} was protected\nby {B_DEF_ABILITY}!");   //TODO 汉化 受到保护 ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX} was protected\nby {B_DEF_ABILITY}!");
#endif

static const u8 sText_PkmnPreventsUsage[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents {B_ATK_NAME_WITH_PREFIX}\lfrom using {B_CURRENT_MOVE}!");   //TODO 汉化  阻止使用 ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents {B_ATK_NAME_WITH_PREFIX}\lfrom using {B_CURRENT_MOVE}!");
#endif

static const u8 sText_PkmnRestoredHPUsing[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} restored HP\nusing its {B_DEF_ABILITY}!");  //TODO 汉化 恢复使用   ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX} restored HP\nusing its {B_DEF_ABILITY}!");
#endif

static const u8 sText_PkmnsXMadeYUseless[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nmade {B_CURRENT_MOVE} useless!");    //TODO 汉化  让XX无效  ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nmade {B_CURRENT_MOVE} useless!");
#endif

static const u8 sText_PkmnChangedTypeWith[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nmade it the {B_BUFF1} type!");   //TODO 汉化  成功 ** 类型 ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nmade it the {B_BUFF1} type!");
#endif

static const u8 sText_PkmnPreventsParalysisWith[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents paralysis!");   //TODO 汉化 防止麻痹  ？？？
#else
_("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents paralysis!");
#endif

static const u8 sText_PkmnPreventsRomanceWith[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents romance!"); //TODO 汉化 防止迷人 ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents romance!");
#endif

static const u8 sText_PkmnPreventsPoisoningWith[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents poisoning!");   //TODO 汉化  防止中毒 ？？？
#else
_("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents poisoning!");
#endif

static const u8 sText_PkmnPreventsConfusionWith[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents confusion!");   //TODO 汉化 防止混乱 ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevents confusion!");
#endif

static const u8 sText_PkmnRaisedFirePowerWith[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\n火系威力提升!");    //TODO 汉化 提升火系伤害 ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nraised its FIRE power!");
#endif

static const u8 sText_PkmnAnchorsItselfWith[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} anchors\nitself with {B_DEF_ABILITY}!");    //TODO 汉化 （自我暗示）？？？
#else
_("{B_DEF_NAME_WITH_PREFIX} anchors\nitself with {B_DEF_ABILITY}!");
#endif

static const u8 sText_PkmnCutsAttackWith[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\ncuts {B_DEF_NAME_WITH_PREFIX}'s ATTACK!"); //TODO 汉化  消减攻击力 ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\ncuts {B_DEF_NAME_WITH_PREFIX}'s ATTACK!");
#endif

static const u8 sText_PkmnPreventsStatLossWith[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nprevents stat loss!"); //TODO 汉化  ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nprevents stat loss!");
#endif

static const u8 sText_PkmnHurtsWith[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} was hurt by\n{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!");   //TODO 汉化 受到伤害 ？？？
#else
_("{B_ATK_NAME_WITH_PREFIX} was hurt by\n{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!");
#endif

static const u8 sText_PkmnTraced[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} TRACED\n{B_BUFF1}'s {B_BUFF2}!");    //TODO 汉化 （追击） ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} TRACED\n{B_BUFF1}'s {B_BUFF2}!");
#endif

static const u8 sText_PkmnsXPreventsBurns[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY}\nprevents burns!");   //TODO 汉化 防止烧伤 ？？？
#else
_("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY}\nprevents burns!");
#endif

static const u8 sText_PkmnsXBlocksY[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nblocks {B_CURRENT_MOVE}!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nblocks {B_CURRENT_MOVE}!");
#endif

static const u8 sText_PkmnsXBlocksY2[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nblocks {B_CURRENT_MOVE}!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nblocks {B_CURRENT_MOVE}!");
#endif

static const u8 sText_PkmnsXRestoredHPALittle2[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\n恢复了一点生命值!"); //TODO 汉化       YYY
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\nrestored its HP a little!");
#endif

static const u8 sText_PkmnsXWhippedUpSandstorm[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n扬起了沙尘暴!"); //TODO 汉化          YYY
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nwhipped up a sandstorm!");
#endif

static const u8 sText_PkmnsXIntensifiedSun[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n阳光变得耀眼!"); //TODO 汉化   YYY
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nintensified the sun's rays!");
#endif

static const u8 sText_PkmnsXPreventsYLoss[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nprevents {B_BUFF1} loss!");    //TODO 汉化  ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nprevents {B_BUFF1} loss!");
#endif

static const u8 sText_PkmnsXInfatuatedY[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\n陷入爱河 {B_ATK_NAME_WITH_PREFIX}!");  //TODO 汉化   YYY
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\ninfatuated {B_ATK_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_PkmnsXMadeYIneffective[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nmade {B_CURRENT_MOVE} 没有效果!");    //TODO 汉化  ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nmade {B_CURRENT_MOVE} ineffective!");
#endif

static const u8 sText_PkmnsXCuredYProblem[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n治愈了它的 {B_BUFF1} 异常状态!");    //TODO 汉化  ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\ncured its {B_BUFF1} problem!");
#endif

static const u8 sText_ItSuckedLiquidOoze[] = 
#ifdef CHINESE
_("它吸取了\n体力值!");    //TODO 汉化  ？？？
#else
_("It sucked up the\nLIQUID OOZE!");
#endif

static const u8 sText_PkmnTransformed[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} 改变了形态!");  //TODO 汉化 ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} transformed!");
#endif

static const u8 sText_PkmnsXTookAttack[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\n受到伤害!");  //TODO 汉化 ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\ntook the attack!");
#endif

const u8 gText_PkmnsXPreventsSwitching[] = 
#ifdef CHINESE
_("{B_BUFF1}'s {B_LAST_ABILITY}\n阻止交换!\p");   //TODO 汉化  ？？？
#else
_("{B_BUFF1}'s {B_LAST_ABILITY}\nprevents switching!\p");
#endif

static const u8 sText_PreventedFromWorking[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\n阻止 {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s\l{B_BUFF1} 从战斗中!");  //TODO 汉化  ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nprevented {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s\l{B_BUFF1} from working!");
#endif

static const u8 sText_PkmnsXMadeItIneffective[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n使它不起作用!");    //TODO 汉化    ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nmade it ineffective!");
#endif

static const u8 sText_PkmnsXPreventsFlinching[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY}\n防止畏缩!");   //TODO 汉化 ？？？
#else
_("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY}\nprevents flinching!");
#endif

static const u8 sText_PkmnsXPreventsYsZ[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\n防止 {B_DEF_NAME_WITH_PREFIX}'s\l{B_DEF_ABILITY} 从战斗中!");    //TODO 汉化  ？？？
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\nprevents {B_DEF_NAME_WITH_PREFIX}'s\l{B_DEF_ABILITY} from working!");
#endif

static const u8 sText_PkmnsXCuredItsYProblem[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n治愈了他的 {B_BUFF1} 异常状态!");    //TODO 汉化   ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\ncured its {B_BUFF1} problem!");
#endif

static const u8 sText_PkmnsXHadNoEffectOnY[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\n没有影响 {B_EFF_NAME_WITH_PREFIX}!");  //TODO 汉化  ？？？
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nhad no effect on {B_EFF_NAME_WITH_PREFIX}!");
#endif

const u8 gText_StatSharply[] = 
#ifdef CHINESE
_("sharply ");  //TODO 汉化   猛烈的  ？？？
#else
_("sharply ");
#endif

const u8 gText_StatRose[] = 
#ifdef CHINESE
_("rose!"); //TODO 汉化  状态上升 ？？？
#else
_("rose!");
#endif

static const u8 sText_StatHarshly[] = 
#ifdef CHINESE
_("harshly ");  //TODO 汉化   刺耳的 ？？？
#else
_("harshly ");
#endif

static const u8 sText_StatFell[] = 
#ifdef CHINESE
_("fell!"); //TODO 汉化   状态下降 ？？
#else
_("fell!");
#endif

static const u8 sText_AttackersStatRose[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");   //TODO   汉化 攻击力上升
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");
#endif

const u8 gText_DefendersStatRose[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");   //TODO 汉化   防御力上升
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");
#endif

static const u8 sText_UsingItemTheStatOfPkmnRose[] = 
#ifdef CHINESE
_("Using {B_LAST_ITEM}, the {B_BUFF1}\nof {B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");  //TODO 汉化  ？？？
#else
_("Using {B_LAST_ITEM}, the {B_BUFF1}\nof {B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
#endif

static const u8 sText_AttackersStatFell[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");   //TODO 汉化  攻击力下降？？？
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");
#endif

static const u8 sText_DefendersStatFell[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");   //TODO 汉化  防御力下降 ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\n{B_BUFF2}");
#endif

static const u8 sText_StatsWontIncrease2[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s 能力不能\ng提升的更高了!");    //TODO 汉化  能力不能提升的更高了 达到6级  ？？？
#else
_("{B_ATK_NAME_WITH_PREFIX}'s stats won't\ngo any higher!");
#endif

static const u8 sText_StatsWontDecrease2[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s 能力不能\n降的更低了!"); //TODO 汉化   能力不能再降低 达到6级  ？？？
#else
_("{B_DEF_NAME_WITH_PREFIX}'s stats won't\ngo any lower!");
#endif

static const u8 sText_CriticalHit[] = 
#ifdef CHINESE
_("击中要害!");   //TODO 汉化 击中要害 ？？？
#else
_("A critical hit!");
#endif

static const u8 sText_OneHitKO[] = 
#ifdef CHINESE
_("一击必杀!");    //TODO 汉化  一击必杀 ？？？
#else
_("It's a one-hit KO!");
#endif

static const u8 sText_123Poof[] = 
#ifdef CHINESE
_("{PAUSE 32}1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p");  //TODO 汉化  ？？？
#else
_("{PAUSE 32}1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p");
#endif

static const u8 sText_AndEllipsis[] = 
#ifdef CHINESE
_("和…\p");    //TODO 汉化   YYY
#else
_("And…\p");
#endif

static const u8 sText_HMMovesCantBeForgotten[] = 
#ifdef CHINESE
_("招式不能\n现在忘掉.\p");   //TODO 汉化   技能招式现在还不能遗忘  ？？？  
#else
_("HM moves can't be\nforgotten now.\p");
#endif

static const u8 sText_NotVeryEffective[] = 
#ifdef CHINESE
_("I这不是很有效…");  //TODO 汉化  YYY
#else
_("It's not very effective…");
#endif

static const u8 sText_SuperEffective[] = 
#ifdef CHINESE
_("它的效果十分明显!"); //TODO 汉化 YYY
#else
_("It's super effective!");
#endif

static const u8 sText_GotAwaySafely[] = 
#ifdef CHINESE
_("{PLAY_SE SE_FLEE}安全的逃走了!\p");   //TODO 汉化  YYY
#else
_("{PLAY_SE SE_FLEE}Got away safely!\p");
#endif

static const u8 sText_PkmnFledUsingIts[] = 
#ifdef CHINESE
_("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} 逃跑\n使用了它的 {B_LAST_ITEM}!\p");    //TODO 汉化  使用它的 逃跑 技能？？？
#else
_("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fled\nusing its {B_LAST_ITEM}!\p");
#endif

static const u8 sText_PkmnFledUsing[] = 
#ifdef CHINESE
_("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} 逃跑\n使用 {B_ATK_ABILITY}!\p");  //TODO 汉化   使用 道具 逃跑？？？
#else
_("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fled\nusing {B_ATK_ABILITY}!\p");
#endif

static const u8 sText_WildPkmnFled[] = 
#ifdef CHINESE
_("{PLAY_SE SE_FLEE}Wild {B_BUFF1} 逃脱了"); //TODO 汉化 野生精灵手里跑掉 YYY
#else
_("{PLAY_SE SE_FLEE}Wild {B_BUFF1} fled!");
#endif

static const u8 sText_PlayerDefeatedLinkTrainer[] = 
#ifdef CHINESE
_("你被打败了\n{B_LINK_OPPONENT1_NAME}!"); //TODO 汉化 失败 YYY
#else
_("Player defeated\n{B_LINK_OPPONENT1_NAME}!");
#endif

static const u8 sText_TwoLinkTrainersDefeated[] = 
#ifdef CHINESE
_("你打败了 {B_LINK_OPPONENT1_NAME}\n和 {B_LINK_OPPONENT2_NAME}!"); //TODO 汉化  打败了 NPC1/NPC2 双胞胎那种 YYY
#else
_("Player beat {B_LINK_OPPONENT1_NAME}\nand {B_LINK_OPPONENT2_NAME}!");
#endif

static const u8 sText_PlayerLostAgainstLinkTrainer[] = 
#ifdef CHINESE
_("你输给了对手\n{B_LINK_OPPONENT1_NAME}!"); //TODO 汉化  教练 道馆馆主 ？？？
#else
_("Player lost against\n{B_LINK_OPPONENT1_NAME}!");
#endif

static const u8 sText_PlayerLostToTwo[] = 
#ifdef CHINESE
_("你输给了{B_LINK_OPPONENT1_NAME}\nand {B_LINK_OPPONENT2_NAME}!");  //TODO 汉化 ？？？
#else
_("Player lost to {B_LINK_OPPONENT1_NAME}\nand {B_LINK_OPPONENT2_NAME}!");
#endif

static const u8 sText_PlayerBattledToDrawLinkTrainer[] = 
#ifdef CHINESE
_("你和对手打成平局\n{B_LINK_OPPONENT1_NAME}!");    //TODO 汉化 平局 ？？？
#else
_("Player battled to a draw against\n{B_LINK_OPPONENT1_NAME}!");
#endif

static const u8 sText_PlayerBattledToDrawVsTwo[] = 
#ifdef CHINESE
_("你打平了\n{B_LINK_OPPONENT1_NAME} 和 {B_LINK_OPPONENT2_NAME}!");    //TODO 汉化  和2个npc打平 ？？？
#else
_("Player battled to a draw against\n{B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
#endif

static const u8 sText_WildFled[] = 
#ifdef CHINESE
_("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} 逃离!");    //TODO 汉化 
#else
_("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} fled!");
#endif

static const u8 sText_TwoWildFled[] = 
#ifdef CHINESE
_("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} 和\n{B_LINK_OPPONENT2_NAME} 逃离!");   //TODO 汉化 ？？？
#else
_("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} and\n{B_LINK_OPPONENT2_NAME} fled!");
#endif

static const u8 sText_NoRunningFromTrainers[] = 
#ifdef CHINESE
_("不行! 不能逃跑\n和训练师对战时!\p");  //TODO 汉化   战斗中无法逃跑提示 YYY
#else
_("No! There's no running\nfrom a TRAINER battle!\p");
#endif

static const u8 sText_CantEscape[] = 
#ifdef CHINESE
_("不能逃走!\p");   //TODO 汉化
#else
_("Can't escape!\p");
#endif

static const u8 sText_DontLeaveBirch[] = 
#ifdef CHINESE
_("小田卷博士: 不要就这样离开我!\p");  //TODO 汉化
#else
_("PROF. BIRCH: Don't leave me like this!\p");
#endif

static const u8 sText_ButNothingHappened[] = 
#ifdef CHINESE
_("但无事发生!"); //TODO 汉化
#else
_("But nothing happened!");
#endif

static const u8 sText_ButItFailed[] = 
#ifdef CHINESE
_("但它失败了!");    //TODO 汉化
#else
_("But it failed!");
#endif

static const u8 sText_ItHurtConfusion[] = 
#ifdef CHINESE
_("它在混乱中\n击中了自己!"); //TODO 汉化
#else
_("It hurt itself in its\nconfusion!");
#endif

static const u8 sText_MirrorMoveFailed[] = 
#ifdef CHINESE
_("鹦鹉学舌失败了!");   //TODO 汉化
#else
_("The MIRROR MOVE failed!");
#endif

static const u8 sText_StartedToRain[] = 
#ifdef CHINESE
_("开始下雨了!");   //TODO 汉化
#else
_("It started to rain!");
#endif

static const u8 sText_DownpourStarted[] = 
#ifdef CHINESE
_("开始下起了暴雨!"); // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC   //TODO 汉化
#else
_("A downpour started!"); // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
#endif

static const u8 sText_RainContinues[] = 
#ifdef CHINESE
_("雨继续下.");   //TODO 汉化
#else
_("Rain continues to fall.");
#endif

static const u8 sText_DownpourContinues[] = 
#ifdef CHINESE
_("暴雨势头不减."); // unused //TODO 汉化
#else
_("The downpour continues."); // unused
#endif

static const u8 sText_RainStopped[] = 
#ifdef CHINESE
_("雨停了."); //TODO 汉化
#else
_("The rain stopped.");
#endif

static const u8 sText_SandstormBrewed[] = 
#ifdef CHINESE
_("开始刮沙暴了!");   //TODO 汉化
#else
_("A sandstorm brewed!");
#endif

static const u8 sText_SandstormRages[] = 
#ifdef CHINESE
_("沙暴肆虐.");  //TODO 汉化
#else
_("The sandstorm rages.");
#endif

static const u8 sText_SandstormSubsided[] = 
#ifdef CHINESE
_("沙暴停止了.");   //TODO 汉化
#else
_("The sandstorm subsided.");
#endif

static const u8 sText_SunlightGotBright[] = 
#ifdef CHINESE
_("日照变强了!");  //TODO 汉化
#else
_("The sunlight got bright!");
#endif

static const u8 sText_SunlightStrong[] = 
#ifdef CHINESE
_("日照很强.");   //TODO 汉化
#else
_("The sunlight is strong.");
#endif

static const u8 sText_SunlightFaded[] = 
#ifdef CHINESE
_("日照复原了.");   //TODO 汉化
#else
_("The sunlight faded.");
#endif

static const u8 sText_StartedHail[] = 
#ifdef CHINESE
_("开始下冰雹了!");   //TODO 汉化
#else
_("It started to hail!");
#endif

static const u8 sText_HailContinues[] = 
#ifdef CHINESE
_("冰雹继续肆虐.");   //TODO 汉化
#else
_("Hail continues to fall.");
#endif

static const u8 sText_HailStopped[] = 
#ifdef CHINESE
_("冰雹不下了."); //TODO 汉化
#else
_("The hail stopped.");
#endif

static const u8 sText_FailedToSpitUp[] = 
#ifdef CHINESE
_("但它的喷出失败了!");    //TODO 汉化
#else
_("But it failed to SPIT UP\na thing!");
#endif

static const u8 sText_FailedToSwallow[] = 
#ifdef CHINESE
_("但它的吞下失败了!");    //TODO 汉化
#else
_("But it failed to SWALLOW\na thing!");
#endif

static const u8 sText_WindBecameHeatWave[] = 
#ifdef CHINESE
_("风转变为\n热风!");    //TODO 汉化
#else
_("The wind turned into a\nHEAT WAVE!");
#endif

static const u8 sText_StatChangesGone[] = 
#ifdef CHINESE
_("所有能力变化都\n消除了!");    //TODO 汉化
#else
_("All stat changes were\neliminated!");
#endif

static const u8 sText_CoinsScattered[] = 
#ifdef CHINESE
_("金币散落一地!");   //TODO 汉化
#else
_("Coins scattered everywhere!");
#endif

static const u8 sText_TooWeakForSubstitute[] = 
#ifdef CHINESE
_("它的体力不足以制造\n替身!");    //TODO 汉化
#else
_("It was too weak to make\na SUBSTITUTE!");
#endif

static const u8 sText_SharedPain[] = 
#ifdef CHINESE
_("双方平分了\n体力!");  //TODO 汉化
#else
_("The battlers shared\ntheir pain!");
#endif

static const u8 sText_BellChimed[] = 
#ifdef CHINESE
_("铃铛响了起来!");    //TODO 汉化
#else
_("A bell chimed!");
#endif

static const u8 sText_FaintInThree[] = 
#ifdef CHINESE
_("所有作用到的宝可梦将\n在3回合后倒下!");  //TODO 汉化
#else
_("All affected POKéMON will\nfaint in three turns!");
#endif

static const u8 sText_NoPPLeft[] = 
#ifdef CHINESE
_("这个招式已经\n没有PP了\p");  //TODO 汉化
#else
_("There's no PP left for\nthis move!\p");
#endif

static const u8 sText_ButNoPPLeft[] = 
#ifdef CHINESE
_("但这个招式已经\n没有PP了!");   //TODO 汉化
#else
_("But there was no PP left\nfor the move!");
#endif

static const u8 sText_PkmnIgnoresAsleep[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 无视了\n指令开始睡觉!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} ignored\norders while asleep!");
#endif

static const u8 sText_PkmnIgnoredOrders[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 无视了\n指令"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} ignored\norders!");
#endif

static const u8 sText_PkmnBeganToNap[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 开始睡觉了!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} began to nap!");
#endif

static const u8 sText_PkmnLoafing[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 在\n周围闲逛!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is\nloafing around!");
#endif

static const u8 sText_PkmnWontObey[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 不服从\n指令"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} won't\nobey!");
#endif

static const u8 sText_PkmnTurnedAway[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 转身离开了!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} turned away!");
#endif

static const u8 sText_PkmnPretendNotNotice[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 假装\n没注意到!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} pretended\nnot to notice!");
#endif

static const u8 sText_EnemyAboutToSwitchPkmn[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} 即将\n派出 {B_BUFF2}.\p {B_PLAYER_NAME} 想要交换\n宝可梦吗?");   //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} is\nabout to use {B_BUFF2}.\pWill {B_PLAYER_NAME} change\nPOKéMON?");
#endif

static const u8 sText_PkmnLearnedMove2[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 学会了\n{B_BUFF1}!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} learned\n{B_BUFF1}!");
#endif

static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = 
#ifdef CHINESE
_("Player defeated\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");  //TODO 汉化
#else
_("Player defeated\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");
#endif

static const u8 sText_CreptCloser[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME} 悄悄靠近\n{B_OPPONENT_MON1_NAME}!");  //TODO 汉化
#else
_("{B_PLAYER_NAME} crept closer to\n{B_OPPONENT_MON1_NAME}!");
#endif

static const u8 sText_CantGetCloser[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME} 不能靠得更近了!"); //TODO 汉化
#else
_("{B_PLAYER_NAME} can't get any closer!");
#endif

static const u8 sText_PkmnWatchingCarefully[] = 
#ifdef CHINESE
_("{B_OPPONENT_MON1_NAME} 在仔细\n观察!");    //TODO 汉化
#else
_("{B_OPPONENT_MON1_NAME} is watching\ncarefully!");
#endif

static const u8 sText_PkmnCuriousAboutX[] = 
#ifdef CHINESE
_("{B_OPPONENT_MON1_NAME} 很好奇\n这个 {B_BUFF1}!");   //TODO 汉化
#else
_("{B_OPPONENT_MON1_NAME} is curious about\nthe {B_BUFF1}!");
#endif

static const u8 sText_PkmnEnthralledByX[] = 
#ifdef CHINESE
_("{B_OPPONENT_MON1_NAME} 迷上了\n这个 {B_BUFF1}!");   //TODO 汉化
#else
_("{B_OPPONENT_MON1_NAME} is enthralled by\nthe {B_BUFF1}!");
#endif

static const u8 sText_PkmnIgnoredX[] = 
#ifdef CHINESE
_("{B_OPPONENT_MON1_NAME} 完全无视\n这个 {B_BUFF1}!"); //TODO 汉化
#else
_("{B_OPPONENT_MON1_NAME} completely ignored\nthe {B_BUFF1}!");
#endif

static const u8 sText_ThrewPokeblockAtPkmn[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME} 扔了一个 {POKEBLOCK}\n在 {B_OPPONENT_MON1_NAME}!");   //TODO 汉化
#else
_("{B_PLAYER_NAME} threw a {POKEBLOCK}\nat the {B_OPPONENT_MON1_NAME}!");
#endif

static const u8 sText_OutOfSafariBalls[] = 
#ifdef CHINESE
_("{PLAY_SE SE_DING_DONG}播报员: 你已经没有\n狩猎球了! Game over!\p");    //TODO 汉化
#else
_("{PLAY_SE SE_DING_DONG}ANNOUNCER: You're out of\nSAFARI BALLS! Game over!\p");
#endif

static const u8 sText_OpponentMon1Appeared[] = 
#ifdef CHINESE
_("{B_OPPONENT_MON1_NAME} 出现了\p");    //TODO 汉化
#else
_("{B_OPPONENT_MON1_NAME} appeared!\p");
#endif

static const u8 sText_WildPkmnAppeared[] = 
#ifdef CHINESE
_("野生的 {B_OPPONENT_MON1_NAME} 出现了!\p");   //TODO 汉化
#else
_("Wild {B_OPPONENT_MON1_NAME} appeared!\p");
#endif

static const u8 sText_LegendaryPkmnAppeared[] = 
#ifdef CHINESE
_("野生的 {B_OPPONENT_MON1_NAME} 出现了!\p");   //TODO 汉化
#else
_("Wild {B_OPPONENT_MON1_NAME} appeared!\p");
#endif

static const u8 sText_WildPkmnAppearedPause[] = 
#ifdef CHINESE
_("野生的 {B_OPPONENT_MON1_NAME} 出现了!{PAUSE 127}");  //TODO 汉化
#else
_("Wild {B_OPPONENT_MON1_NAME} appeared!{PAUSE 127}");
#endif

static const u8 sText_TwoWildPkmnAppeared[] = 
#ifdef CHINESE
_("野生的 {B_OPPONENT_MON1_NAME} 和\n{B_OPPONENT_MON2_NAME} 出现了!\p");   //TODO 汉化
#else
_("Wild {B_OPPONENT_MON1_NAME} and\n{B_OPPONENT_MON2_NAME} appeared!\p");
#endif

static const u8 sText_Trainer1WantsToBattle[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n想要发起挑战!\p"); //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nwould like to battle!\p");
#endif

static const u8 sText_LinkTrainerWantsToBattle[] = 
#ifdef CHINESE
_("{B_LINK_OPPONENT1_NAME}\n想要发起挑战!"); //TODO 汉化
#else
_("{B_LINK_OPPONENT1_NAME}\nwants to battle!");
#endif

static const u8 sText_TwoLinkTrainersWantToBattle[] = 
#ifdef CHINESE
_("{B_LINK_OPPONENT1_NAME} 和 {B_LINK_OPPONENT2_NAME}\n想要发起挑战!");  //TODO 汉化
#else
_("{B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}\nwant to battle!");
#endif

static const u8 sText_Trainer1SentOutPkmn[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} 派\n出了 {B_OPPONENT_MON1_NAME}!");    //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_OPPONENT_MON1_NAME}!");
#endif

static const u8 sText_Trainer1SentOutTwoPkmn[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} 派\n出了 {B_OPPONENT_MON1_NAME} 和 {B_OPPONENT_MON2_NAME}!"); //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} 派\n出了 {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
#endif

static const u8 sText_Trainer1SentOutPkmn2[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} 派\n出了 {B_BUFF1}!"); //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_BUFF1}!");
#endif

static const u8 sText_LinkTrainerSentOutPkmn[] = 
#ifdef CHINESE
_("{B_LINK_OPPONENT1_NAME} 派出了\n{B_OPPONENT_MON1_NAME}!"); //TODO 汉化
#else
_("{B_LINK_OPPONENT1_NAME} sent out\n{B_OPPONENT_MON1_NAME}!");
#endif

static const u8 sText_LinkTrainerSentOutTwoPkmn[] = 
#ifdef CHINESE
_("{B_LINK_OPPONENT1_NAME} 派出了\n{B_OPPONENT_MON1_NAME} 和 {B_OPPONENT_MON2_NAME}!");  //TODO 汉化
#else
_("{B_LINK_OPPONENT1_NAME} sent out\n{B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
#endif

static const u8 sText_TwoLinkTrainersSentOutPkmn[] = 
#ifdef CHINESE
_("{B_LINK_OPPONENT1_NAME} 派出了 {B_LINK_OPPONENT_MON1_NAME}!\n{B_LINK_OPPONENT2_NAME} 派出了 {B_LINK_OPPONENT_MON2_NAME}!");  //TODO 汉化
#else
_("{B_LINK_OPPONENT1_NAME} sent out {B_LINK_OPPONENT_MON1_NAME}!\n{B_LINK_OPPONENT2_NAME} sent out {B_LINK_OPPONENT_MON2_NAME}!");
#endif

static const u8 sText_LinkTrainerSentOutPkmn2[] = 
#ifdef CHINESE
_("{B_LINK_OPPONENT1_NAME} 派出了\n{B_BUFF1}!");  //TODO 汉化
#else
_("{B_LINK_OPPONENT1_NAME} sent out\n{B_BUFF1}!");
#endif

static const u8 sText_LinkTrainerMultiSentOutPkmn[] = 
#ifdef CHINESE
_("{B_LINK_SCR_TRAINER_NAME} 派出了\n{B_BUFF1}!");    //TODO 汉化
#else
_("{B_LINK_SCR_TRAINER_NAME} sent out\n{B_BUFF1}!");
#endif

static const u8 sText_GoPkmn[] = 
#ifdef CHINESE
_("去吧! {B_PLAYER_MON1_NAME}!"); //TODO 汉化
#else
_("Go! {B_PLAYER_MON1_NAME}!");
#endif

static const u8 sText_GoTwoPkmn[] = 
#ifdef CHINESE
_("去吧! {B_PLAYER_MON1_NAME} 和\n{B_PLAYER_MON2_NAME}!");   //TODO 汉化
#else
_("Go! {B_PLAYER_MON1_NAME} and\n{B_PLAYER_MON2_NAME}!");
#endif

static const u8 sText_GoPkmn2[] = 
#ifdef CHINESE
_("去吧! {B_BUFF1}!");    //TODO 汉化
#else
_("Go! {B_BUFF1}!");
#endif

static const u8 sText_DoItPkmn[] = 
#ifdef CHINESE
_("加油! {B_BUFF1}!"); //TODO 汉化
#else
_("Do it! {B_BUFF1}!");
#endif

static const u8 sText_GoForItPkmn[] = 
#ifdef CHINESE
_("去吧, {B_BUFF1}!"); //TODO 汉化
#else
_("Go for it, {B_BUFF1}!");
#endif

static const u8 sText_YourFoesWeakGetEmPkmn[] = 
#ifdef CHINESE
_("对手很虚弱!\n拿下他们, {B_BUFF1}!"); //TODO 汉化
#else
_("Your foe's weak!\nGet 'em, {B_BUFF1}!");
#endif

static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = 
#ifdef CHINESE
_("{B_LINK_PARTNER_NAME} 派出了 {B_LINK_PLAYER_MON2_NAME}!\n去吧! {B_LINK_PLAYER_MON1_NAME}!"); //TODO 汉化
#else
_("{B_LINK_PARTNER_NAME} sent out {B_LINK_PLAYER_MON2_NAME}!\nGo! {B_LINK_PLAYER_MON1_NAME}!");
#endif

static const u8 sText_PkmnThatsEnough[] = 
#ifdef CHINESE
_("{B_BUFF1}, 你已经做得很好了!\n回来吧!"); //TODO 汉化
#else
_("{B_BUFF1}, that's enough!\nCome back!");
#endif

static const u8 sText_PkmnComeBack[] = 
#ifdef CHINESE
_("{B_BUFF1}, 回来吧!"); //TODO 汉化
#else
_("{B_BUFF1}, come back!");
#endif

static const u8 sText_PkmnOkComeBack[] = 
#ifdef CHINESE
_("{B_BUFF1}, 足够了!\n回来吧!");    //TODO 汉化
#else
_("{B_BUFF1}, OK!\nCome back!");
#endif

static const u8 sText_PkmnGoodComeBack[] = 
#ifdef CHINESE
_("{B_BUFF1}, 干得好!\n回来吧!");  //TODO 汉化
#else
_("{B_BUFF1}, good!\nCome back!");
#endif

static const u8 sText_Trainer1WithdrewPkmn[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n收回了 {B_BUFF1}!"); //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nwithdrew {B_BUFF1}!");
#endif

static const u8 sText_LinkTrainer1WithdrewPkmn[] = 
#ifdef CHINESE
_("{B_LINK_OPPONENT1_NAME} 收回了\n{B_BUFF1}!");  //TODO 汉化
#else
_("{B_LINK_OPPONENT1_NAME} withdrew\n{B_BUFF1}!");
#endif

static const u8 sText_LinkTrainer2WithdrewPkmn[] = 
#ifdef CHINESE
_("{B_LINK_SCR_TRAINER_NAME} 收回了\n{B_BUFF1}!");    //TODO 汉化
#else
_("{B_LINK_SCR_TRAINER_NAME} withdrew\n{B_BUFF1}!");
#endif

static const u8 sText_WildPkmnPrefix[] = 
#ifdef CHINESE
_("野生的 "); //TODO 汉化
#else
_("Wild ");
#endif

static const u8 sText_FoePkmnPrefix[] = 
#ifdef CHINESE
_("对方 ");  //TODO 汉化
#else
_("Foe ");
#endif

static const u8 sText_EmptyString8[] = 
#ifdef CHINESE
_("");  //TODO 汉化
#else
_("");
#endif

static const u8 sText_FoePkmnPrefix2[] = 
#ifdef CHINESE
_("对方");   //TODO 汉化
#else
_("Foe");
#endif

static const u8 sText_AllyPkmnPrefix[] = 
#ifdef CHINESE
_("队友");  //TODO 汉化
#else
_("Ally");
#endif

static const u8 sText_FoePkmnPrefix3[] = 
#ifdef CHINESE
_("对方");   //TODO 汉化
#else
_("Foe");
#endif

static const u8 sText_AllyPkmnPrefix2[] = 
#ifdef CHINESE
_("队友");  //TODO 汉化
#else
_("Ally");
#endif

static const u8 sText_FoePkmnPrefix4[] = 
#ifdef CHINESE
_("对方");   //TODO 汉化
#else
_("Foe");
#endif

static const u8 sText_AllyPkmnPrefix3[] = 
#ifdef CHINESE
_("队友");  //TODO 汉化
#else
_("Ally");
#endif

static const u8 sText_AttackerUsedX[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 使用了\n{B_BUFF3}!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} used\n{B_BUFF3}!");
#endif

static const u8 sText_ExclamationMark[] = 
#ifdef CHINESE
_("!"); //TODO 汉化
#else
_("!");
#endif

static const u8 sText_ExclamationMark2[] = 
#ifdef CHINESE
_("!"); //TODO 汉化
#else
_("!");
#endif

static const u8 sText_ExclamationMark3[] = 
#ifdef CHINESE
_("!"); //TODO 汉化
#else
_("!");
#endif

static const u8 sText_ExclamationMark4[] = 
#ifdef CHINESE
_("!"); //TODO 汉化
#else
_("!");
#endif

static const u8 sText_ExclamationMark5[] = 
#ifdef CHINESE
_("!"); //TODO 汉化
#else
_("!");
#endif

static const u8 sText_Accuracy[] = 
#ifdef CHINESE
_("命中");  //TODO 汉化
#else
_("accuracy");
#endif

static const u8 sText_Evasiveness[] = 
#ifdef CHINESE
_("闪避");   //TODO 汉化
#else
_("evasiveness");
#endif


const u8 * const gStatNamesTable[NUM_BATTLE_STATS] =
{
    gText_HP3, gText_Attack, gText_Defense,
    gText_Speed, gText_SpAtk, gText_SpDef,
    sText_Accuracy, sText_Evasiveness
};

static const u8 sText_PokeblockWasTooSpicy[] = 
#ifdef CHINESE
_("太辣了!");    //TODO 汉化
#else
_("was too spicy!");
#endif

static const u8 sText_PokeblockWasTooDry[] = 
#ifdef CHINESE
_("太涩了!");  //TODO 汉化
#else
_("was too dry!");
#endif

static const u8 sText_PokeblockWasTooSweet[] = 
#ifdef CHINESE
_("太甜了!");    //TODO 汉化
#else
_("was too sweet!");
#endif

static const u8 sText_PokeblockWasTooBitter[] = 
#ifdef CHINESE
_("太苦了!");   //TODO 汉化
#else
_("was too bitter!");
#endif

static const u8 sText_PokeblockWasTooSour[] = 
#ifdef CHINESE
_("太酸了!"); //TODO 汉化
#else
_("was too sour!");
#endif


const u8 * const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};

static const u8 sText_PlayerUsedItem[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME} 使用了\n{B_LAST_ITEM}!");  //TODO 汉化
#else
_("{B_PLAYER_NAME} used\n{B_LAST_ITEM}!");
#endif

static const u8 sText_WallyUsedItem[] = 
#ifdef CHINESE
_("满充使用了\n{B_LAST_ITEM}!");    //TODO 汉化
#else
_("WALLY used\n{B_LAST_ITEM}!");
#endif

static const u8 sText_Trainer1UsedItem[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n使用了 {B_LAST_ITEM}!"); //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nused {B_LAST_ITEM}!");
#endif

static const u8 sText_TrainerBlockedBall[] = 
#ifdef CHINESE
_("训练家挡下了精灵球!"); //TODO 汉化
#else
_("The TRAINER blocked the BALL!");
#endif

static const u8 sText_DontBeAThief[] = 
#ifdef CHINESE
_("别当小偷!"); //TODO 汉化
#else
_("Don't be a thief!");
#endif

static const u8 sText_ItDodgedBall[] = 
#ifdef CHINESE
_("它躲开了!\n这只宝可梦不能被捕捉!"); //TODO 汉化
#else
_("It dodged the thrown BALL!\nThis POKéMON can't be caught!");
#endif

static const u8 sText_YouMissedPkmn[] = 
#ifdef CHINESE
_("你错过了这只宝可梦");   //TODO 汉化
#else
_("You missed the POKéMON!");
#endif

static const u8 sText_PkmnBrokeFree[] = 
#ifdef CHINESE
_("哦不!\n宝可梦挣脱了!");  //TODO 汉化
#else
_("Oh, no!\nThe POKéMON broke free!");
#endif

static const u8 sText_ItAppearedCaught[] = 
#ifdef CHINESE
_("哇!\n好像要被抓住了!");   //TODO 汉化
#else
_("Aww!\nIt appeared to be caught!");
#endif

static const u8 sText_AarghAlmostHadIt[] = 
#ifdef CHINESE
_("啊!\n差一点就抓住了!");    //TODO 汉化
#else
_("Aargh!\nAlmost had it!");
#endif

static const u8 sText_ShootSoClose[] = 
#ifdef CHINESE
_("Shoot!\nIt was so close, too!"); //TODO 汉化
#else
_("Shoot!\nIt was so close, too!");
#endif

static const u8 sText_GotchaPkmnCaught[] = 
#ifdef CHINESE
_("成功!\n{B_DEF_NAME} 被抓住了!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p"); //TODO 汉化
#else
_("Gotcha!\n{B_DEF_NAME} was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
#endif

static const u8 sText_GotchaPkmnCaught2[] = 
#ifdef CHINESE
_("成功!\n{B_DEF_NAME} 被抓住了!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");    //TODO 汉化
#else
_("Gotcha!\n{B_DEF_NAME} was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
#endif

static const u8 sText_GiveNicknameCaptured[] = 
#ifdef CHINESE
_("给刚捕获的宝可梦\n起个名字吗 {B_DEF_NAME}?");    //TODO 汉化
#else
_("Give a nickname to the\ncaptured {B_DEF_NAME}?");
#endif

static const u8 sText_PkmnSentToPC[] = 
#ifdef CHINESE
_("{B_DEF_NAME} 被传送到\n{B_PC_CREATOR_NAME} 电脑."); //TODO 汉化
#else
_("{B_DEF_NAME} was sent to\n{B_PC_CREATOR_NAME} PC.");
#endif

static const u8 sText_Someones[] = 
#ifdef CHINESE
_("某人的"); //TODO 汉化
#else
_("someone's");
#endif

static const u8 sText_Lanettes[] = 
#ifdef CHINESE
_("真由美's"); //TODO 汉化
#else
_("LANETTE's");
#endif

static const u8 sText_PkmnDataAddedToDex[] = 
#ifdef CHINESE
_("{B_DEF_NAME}的数据\n添加到宝可梦图鉴了.\p");  //TODO 汉化
#else
_("{B_DEF_NAME}'s data was\nadded to the POKéDEX.\p");
#endif

static const u8 sText_ItIsRaining[] = 
#ifdef CHINESE
_("在下雨.");    //TODO 汉化
#else
_("It is raining.");
#endif

static const u8 sText_SandstormIsRaging[] = 
#ifdef CHINESE
_("在刮沙暴.");    //TODO 汉化
#else
_("A sandstorm is raging.");
#endif

static const u8 sText_BoxIsFull[] = 
#ifdef CHINESE
_("盒子满了!\n你不能再放入了\p"); //TODO 汉化
#else
_("The BOX is full!\nYou can't catch any more!\p");
#endif

static const u8 sText_EnigmaBerry[] = 
#ifdef CHINESE
_("谜芝果");  //TODO 汉化
#else
_("ENIGMA BERRY");
#endif

static const u8 sText_BerrySuffix[] = 
#ifdef CHINESE
_(" 果");    //TODO 汉化
#else
_(" BERRY");
#endif

static const u8 sText_PkmnsItemCuredParalysis[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n麻痹了!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\ncured paralysis!");
#endif

static const u8 sText_PkmnsItemCuredPoison[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n中毒了!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\ncured poison!");
#endif

static const u8 sText_PkmnsItemHealedBurn[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n被烧伤了!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nhealed its burn!");
#endif

static const u8 sText_PkmnsItemDefrostedIt[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n被冰冻了!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\ndefrosted it!");
#endif

static const u8 sText_PkmnsItemWokeIt[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n从睡梦中醒来了!");  //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nwoke it from its sleep!");
#endif

static const u8 sText_PkmnsItemSnappedOut[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n从混乱中清醒了!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nsnapped it out of confusion!");
#endif

static const u8 sText_PkmnsItemCuredProblem[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n解决了 {B_BUFF1} 的问题!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\ncured its {B_BUFF1} problem!");
#endif

static const u8 sText_PkmnsItemNormalizedStatus[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n使它恢复了正常!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nnormalized its status!");
#endif

static const u8 sText_PkmnsItemRestoredHealth[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n恢复了健康"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nrestored health!");
#endif

static const u8 sText_PkmnsItemRestoredPP[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n回复了 {B_BUFF1}的PP!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nrestored {B_BUFF1}'s PP!");
#endif

static const u8 sText_PkmnsItemRestoredStatus[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n恢复了它的能力等级!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nrestored its status!");
#endif

static const u8 sText_PkmnsItemRestoredHPALittle[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_LAST_ITEM}\n回复了它的少量HP!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nrestored its HP a little!");
#endif

static const u8 sText_ItemAllowsOnlyYMove[] = 
#ifdef CHINESE
_("{B_LAST_ITEM} 只能\n使用 {B_CURRENT_MOVE}!\p"); //TODO 汉化
#else
_("{B_LAST_ITEM} allows the\nuse of only {B_CURRENT_MOVE}!\p");
#endif

static const u8 sText_PkmnHungOnWithX[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 坚持\n使用它的 {B_LAST_ITEM}!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} hung on\nusing its {B_LAST_ITEM}!");
#endif

const u8 gText_EmptyString3[] = 
#ifdef CHINESE
_("");  //TODO 汉化
#else
_("");
#endif

static const u8 sText_YouThrowABallNowRight[] = 
#ifdef CHINESE
_("你现在扔一个球, 对面?\n我… 我会努力做到最好的!"); //TODO 汉化
#else
_("You throw a BALL now, right?\nI… I'll do my best!");
#endif


// early declaration of strings
static const u8 sText_PkmnIncapableOfPower[];
static const u8 sText_GlintAppearsInEye[];
static const u8 sText_PkmnGettingIntoPosition[];
static const u8 sText_PkmnBeganGrowlingDeeply[];
static const u8 sText_PkmnEagerForMore[];
static const u8 sText_DefeatedOpponentByReferee[];
static const u8 sText_LostToOpponentByReferee[];
static const u8 sText_TiedOpponentByReferee[];
static const u8 sText_QuestionForfeitMatch[];
static const u8 sText_ForfeitedMatch[];
static const u8 sText_Trainer1WinText[];
static const u8 sText_Trainer2WinText[];
static const u8 sText_TwoInGameTrainersDefeated[];
static const u8 sText_Trainer2LoseText[];

// New battle strings.
static const s8 sText_EnduredViaSturdy[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 挺住了\n攻击 {B_DEF_ABILITY}!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} ENDURED\nthe hit using {B_DEF_ABILITY}!");
#endif

static const s8 sText_PowerHerbActivation[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 完全充能了\n因为它的 {B_LAST_ITEM}!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} became fully charged\ndue to its {B_LAST_ITEM}!");
#endif

static const s8 sText_HurtByItem[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 受伤了\n因为它的 {B_LAST_ITEM}!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} was hurt\nby its {B_LAST_ITEM}!");
#endif

static const s8 sText_BadlyPoisonedByItem[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX} 中剧毒了 \n因为 {B_LAST_ITEM}!");   //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX} was badly \npoisoned by the {B_LAST_ITEM}!");
#endif

static const s8 sText_BurnedByItem[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX} 烧伤了\n因为 {B_LAST_ITEM}!");    //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX} was burned\nby the {B_LAST_ITEM}!");
#endif

static const s8 sText_TargetAbilityActivates[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}的 {B_DEF_ABILITY} 发动了!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} activates!");
#endif

static const u8 sText_GravityIntensified[] = 
#ifdef CHINESE
_("重力加强了!");  //TODO 汉化
#else
_("GRAVITY intensified!");
#endif

static const u8 sText_TargetIdentified[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 被 \n识破了!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was \nidentified!");
#endif

static const u8 sText_TargetWokeUp[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 醒了!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} woke up!");
#endif

static const u8 sText_PkmnStoleAndAteItem[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 偷到并\n吃掉了 {B_DEF_NAME_WITH_PREFIX}的 {B_LAST_ITEM}!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} stole and\nate {B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
#endif

static const u8 sText_TailWindBlew[] = 
#ifdef CHINESE
_("吹起了顺风\n {B_ATK_TEAM2} 队伍的身后!");    //TODO 汉化
#else
_("The tailwind blew from\nbehind {B_ATK_TEAM2} team!");
#endif

static const u8 sText_PkmnWentBack[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 回\n到 {B_ATK_TRAINER_CLASS} {B_ATK_TRAINER_NAME}"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} went back\nto {B_ATK_TRAINER_CLASS} {B_ATK_TRAINER_NAME}");
#endif

static const u8 sText_PkmnCantUseItemsAnymore[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 不能使用\n道具了!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} can't use\nitems anymore!");
#endif

static const u8 sText_PkmnFlung[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 扔掉了\n{B_LAST_ITEM}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} flung its\n{B_LAST_ITEM}!");
#endif

static const u8 sText_PkmnPreventedFromHealing[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 被阻止\n回复!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} was prevented\nfrom healing!");
#endif

static const u8 sText_PkmnSwitchedAtkAndDef[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 交换了它的\n攻击和防御!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} switched its\nAttack and Defense!");
#endif

static const u8 sText_PkmnsAbilitySuppressed[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}的特性\n被压制了!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s ability\nwas suppressed!");
#endif

static const u8 sText_ShieldedFromCriticalHits[] = 
#ifdef CHINESE
_(" {B_CURRENT_MOVE} 保护 {B_ATK_TEAM2}\n的队伍不被击中要害!"); //TODO 汉化
#else
_("The {B_CURRENT_MOVE} shielded {B_ATK_TEAM2}\nteam from critical hits!");
#endif

static const u8 sText_SwitchedAtkAndSpAtk[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 与目标交换了\n攻击和\p和特攻!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} switched all its\nchanges to its Attack and\pSp. Atk with the target!");
#endif

static const u8 sText_SwitchedDefAndSpDef[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 与目标交换了\n防御和\p和特防!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} switched all its\nchanges to its Defense and\pSp. Def with the target!");
#endif

static const u8 sText_PkmnAcquiredAbility[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 获得了\n{B_DEF_ABILITY}!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} acquired\n{B_DEF_ABILITY}!");
#endif

static const u8 sText_PoisonSpikesScattered[] = 
#ifdef CHINESE
_("毒菱散落在\n对方队伍的脚下!");    //TODO 汉化
#else
_("Poison Spikes were scattered all\naround the opposing team's feet!");
#endif

static const u8 sText_PkmnSwitchedStatChanges[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 与目标交换了\n能力等级!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} switched stat changes\nwith the target!");
#endif

static const u8 sText_PkmnSurroundedWithVeilOfWater[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 身边围绕着\n一层水幕!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} surrounded itself\nwith a veil of water!");
#endif

static const u8 sText_PkmnLevitatedOnElectromagnetism[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 通过电磁力\n漂浮了起来!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} levitated on\nelectromagnetism!");
#endif

static const u8 sText_PkmnTwistedDimensions[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 扭曲了\n时空!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} twisted\nthe dimensions!");
#endif

static const u8 sText_PointedStonesFloat[] =
#ifdef CHINESE
_("尖锐的岩石漂浮在了\n {B_DEF_TEAM2} 的队伍周围!");   //TODO 汉化
#else
_("Pointed stones float in the air\naround {B_DEF_TEAM2} team!");
#endif

static const u8 sText_CloakedInMysticalMoonlight[] =
#ifdef CHINESE
_("被神秘的月光\n笼罩!");   //TODO 汉化
#else
_("It became cloaked in mystical\nmoonlight!");
#endif

static const u8 sText_TrappedBySwirlingMagma[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} 被\n旋转的岩浆困住了!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} became\ntrapped by swirling magma!");
#endif

static const u8 sText_VanishedInstantly[] =
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 突然\n消失了!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} vanished\ninstantly!");
#endif

static const u8 sText_ProtectedTeam[] =
#ifdef CHINESE
_("{B_CURRENT_MOVE} 保护了\n{B_ATK_TEAM2} 的队伍!");   //TODO 汉化
#else
_("{B_CURRENT_MOVE} protected\n{B_ATK_TEAM2} team!");
#endif

static const u8 sText_SharedItsGuard[] =
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 与目标\n平分了防御!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} shared its\nguard with the target!");
#endif

static const u8 sText_SharedItsPower[] =
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 与目标\n平分了攻击!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} shared its\npower with the target!");
#endif

static const u8 sText_SwapsDefAndSpDefOfAllPkmn[] =
#ifdef CHINESE
_("It created a bizarre area in which the\nDefense and Sp.Def stats are swapped!");   //TODO 汉化
#else
    "It created a bizarre area in which the\nDefense and Sp.Def stats are swapped!");
#endif

static const u8 sText_BecameNimble[] =
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} became nimble!");   //TODO 汉化
#else
    "{B_ATK_NAME_WITH_PREFIX} became nimble!");
#endif

static const u8 sText_HurledIntoTheAir[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} was hurled\ninto the air!");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX} was hurled\ninto the air!");
#endif

static const u8 sText_HeldItemsLoseEffects[] =
#ifdef CHINESE
_("It created a bizarre area in which\nPokémon's held items lose their effects!");   //TODO 汉化
#else
    "It created a bizarre area in which\nPokémon's held items lose their effects!");
#endif

static const u8 sText_FellStraightDown[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} fell\nstraight down!");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX} fell\nstraight down!");
#endif

static const u8 sText_TransformedIntoWaterType[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} transformed\ninto the water type!");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX} transformed\ninto the water type!");
#endif

static const u8 sText_PkmnAcquiredSimple[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} acquired\nSimple!");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX} acquired\nSimple!");
#endif

static const u8 sText_KindOffer[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}\ntook the kind offer!");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX}\ntook the kind offer!");
#endif

static const u8 sText_ResetsTargetsStatLevels[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s stat changes\nwere removed!");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX}'s stat changes\nwere removed!");
#endif

static const u8 sText_AllySwitchPosition[] =
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} and\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} switched places!");   //TODO 汉化
#else
    "{B_ATK_NAME_WITH_PREFIX} and\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} switched places!");
#endif

static const u8 sText_RestoreTargetsHealth[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s HP was restored!");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX}'s HP was restored!");
#endif

static const u8 sText_TookPkmnIntoTheSky[] =
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} took\n{B_DEF_NAME_WITH_PREFIX} into the sky!");   //TODO 汉化
#else
    "{B_ATK_NAME_WITH_PREFIX} took\n{B_DEF_NAME_WITH_PREFIX} into the sky!");
#endif

static const u8 sText_FreedFromSkyDrop[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} was freed\nfrom the Sky Drop!");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX} was freed\nfrom the Sky Drop!");
#endif

static const u8 sText_PostponeTargetMove[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s move\nwas postponed!");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX}'s move\nwas postponed!");
#endif

static const u8 sText_ReflectTargetsType[] =
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s type\nchanged to match the {B_DEF_NAME_WITH_PREFIX}'s!");   //TODO 汉化
#else
    "{B_ATK_NAME_WITH_PREFIX}'s type\nchanged to match the {B_DEF_NAME_WITH_PREFIX}'s!");
#endif

static const u8 sText_TransferHeldItem[] =
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} received {B_LAST_ITEM}\nfrom {B_ATK_NAME_WITH_PREFIX}");   //TODO 汉化
#else
    "{B_DEF_NAME_WITH_PREFIX} received {B_LAST_ITEM}\nfrom {B_ATK_NAME_WITH_PREFIX}");
#endif

static const u8 sText_EmbargoEnds[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} can\nuse items again!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} can\nuse items again!");
#endif

static const u8 sText_Electromagnetism[] = 
#ifdef CHINESE
_("electromagnetism");  //TODO 汉化
#else
_("electromagnetism");
#endif

static const u8 sText_BufferEnds[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\nwore off!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1}\nwore off!");
#endif

static const u8 sText_ThroatChopEnds[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} can\nuse sound-based moves again!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} can\nuse sound-based moves again!");
#endif

static const u8 sText_TelekinesisEnds[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} was freed\nfrom the telekinesis!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} was freed\nfrom the telekinesis!");
#endif

static const u8 sText_TailwindEnds[] = 
#ifdef CHINESE
_("{B_ATK_TEAM1} team's tailwind\n petered out!");  //TODO 汉化
#else
_("{B_ATK_TEAM1} team's tailwind\n petered out!");
#endif

static const u8 sText_LuckyChantEnds[] = 
#ifdef CHINESE
_("{B_ATK_TEAM1} team's Lucky Chant\n wore off!");  //TODO 汉化
#else
_("{B_ATK_TEAM1} team's Lucky Chant\n wore off!");
#endif

static const u8 sText_TrickRoomEnds[] = 
#ifdef CHINESE
_("The twisted dimensions returned to\nnormal!");   //TODO 汉化
#else
_("The twisted dimensions returned to\nnormal!");
#endif

static const u8 sText_WonderRoomEnds[] = 
#ifdef CHINESE
_("Wonder Room wore off, and Defense\nand Sp. Def stats returned to normal!");  //TODO 汉化
#else
_("Wonder Room wore off, and Defense\nand Sp. Def stats returned to normal!");
#endif

static const u8 sText_MagicRoomEnds[] = 
#ifdef CHINESE
_("Magic Room wore off, and held items'\neffects returned to normal!"); //TODO 汉化
#else
_("Magic Room wore off, and held items'\neffects returned to normal!");
#endif

static const u8 sText_MudSportEnds[] = 
#ifdef CHINESE
_("The effects of Mud Sport have faded.");  //TODO 汉化
#else
_("The effects of Mud Sport have faded.");
#endif

static const u8 sText_WaterSportEnds[] = 
#ifdef CHINESE
_("The effects of Water Sport have faded.");    //TODO 汉化
#else
_("The effects of Water Sport have faded.");
#endif

static const u8 sText_GravityEnds[] = 
#ifdef CHINESE
_("Gravity returned to normal!");   //TODO 汉化
#else
_("Gravity returned to normal!");
#endif

static const u8 sText_AquaRingHeal[] = 
#ifdef CHINESE
_("Aqua Ring restored\n{B_ATK_NAME_WITH_PREFIX}'s HP!");    //TODO 汉化
#else
_("Aqua Ring restored\n{B_ATK_NAME_WITH_PREFIX}'s HP!");
#endif

static const u8 sText_TargetAbilityRaisedStat[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nraised its {B_BUFF1}!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nraised its {B_BUFF1}!");
#endif

static const u8 sText_TargetAbilityLoweredStat[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nlowered its {B_BUFF1}!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nlowered its {B_BUFF1}!");
#endif

static const u8 sText_AttackerAbilityRaisedStat[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\nraised its {B_BUFF1}!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\nraised its {B_BUFF1}!");
#endif

static const u8 sText_ScriptingAbilityRaisedStat[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nraised its {B_BUFF1}!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nraised its {B_BUFF1}!");
#endif

static const u8 sText_AuroraVeilEnds[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nwore off!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}\nwore off!");
#endif

static const u8 sText_ElectricTerrainEnds[] = 
#ifdef CHINESE
_("The electricity disappeared\nfrom the battlefield.");    //TODO 汉化
#else
_("The electricity disappeared\nfrom the battlefield.");
#endif

static const u8 sText_MistyTerrainEnds[] = 
#ifdef CHINESE
_("The mist disappeared\nfrom the battlefield.");   //TODO 汉化
#else
_("The mist disappeared\nfrom the battlefield.");
#endif

static const u8 sText_PsychicTerrainEnds[] = 
#ifdef CHINESE
_("The weirdness disappeared\nfrom the battlefield.");  //TODO 汉化
#else
_("The weirdness disappeared\nfrom the battlefield.");
#endif

static const u8 sText_GrassyTerrainEnds[] = 
#ifdef CHINESE
_("The grass disappeared\nfrom the battlefield.");  //TODO 汉化
#else
_("The grass disappeared\nfrom the battlefield.");
#endif

static const u8 sText_TargetsStatWasMaxedOut[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} maxed\nits {B_BUFF1}!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} maxed\nits {B_BUFF1}!");
#endif

static const u8 sText_PoisonHealHpUp[] = 
#ifdef CHINESE
_("The poisoning healed {B_ATK_NAME_WITH_PREFIX}\na little bit!");  //TODO 汉化
#else
_("The poisoning healed {B_ATK_NAME_WITH_PREFIX}\na little bit!");
#endif

static const u8 sText_BadDreamsDmg[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} is tormented\nby {B_ATK_ABILITY}!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} is tormented\nby {B_ATK_ABILITY}!");
#endif

static const u8 sText_MoldBreakerEnters[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} breaks the mold!");  //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} breaks the mold!");
#endif

static const u8 sText_TeravoltEnters[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating \na bursting aura!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating \na bursting aura!");
#endif

static const u8 sText_TurboblazeEnters[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating\na blazing aura!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating\na blazing aura!");
#endif

static const u8 sText_SlowStartEnters[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} can't get it going!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} can't get it going!");
#endif

static const u8 sText_SlowStartEnd[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} finally got\nits act together!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} finally got\nits act together!");
#endif

static const u8 sText_SolarPowerHpDrop[] = 
#ifdef CHINESE
_("The {B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\ntakes its toll!");   //TODO 汉化
#else
_("The {B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\ntakes its toll!");
#endif

static const u8 sText_AftermathDmg[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is hurt!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is hurt!");
#endif

static const u8 sText_AnticipationActivates[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} shuddered\nin anticipation!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} shuddered\nin anticipation!");
#endif

static const u8 sText_ForewarnActivates[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_ABILITY} alerted {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nto the {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!");  //TODO 汉化
#else
_("{B_SCR_ACTIVE_ABILITY} alerted {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nto the {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!");
#endif

static const u8 sText_IceBodyHpGain[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\nhealed it a little bit!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY}\nhealed it a little bit!");
#endif

static const u8 sText_SnowWarningHail[] = 
#ifdef CHINESE
_("It started to hail!");   //TODO 汉化
#else
_("It started to hail!");
#endif

static const u8 sText_FriskActivates[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} frisked {B_DEF_NAME_WITH_PREFIX} and\nfound its {B_LAST_ITEM}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} frisked {B_DEF_NAME_WITH_PREFIX} and\nfound its {B_LAST_ITEM}!");
#endif

static const u8 sText_UnnerveEnters[] = 
#ifdef CHINESE
_("The opposing team is too nervous\nto eat Berries!"); //TODO 汉化
#else
_("The opposing team is too nervous\nto eat Berries!");
#endif

static const u8 sText_HarvestBerry[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} harvested\nits {B_LAST_ITEM}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} harvested\nits {B_LAST_ITEM}!");
#endif

static const u8 sText_LastAbilityRaisedBuff1[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY}\nraised its {B_BUFF1}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY}\nraised its {B_BUFF1}!");
#endif

static const u8 sText_MagicBounceActivates[] = 
#ifdef CHINESE
_("The {B_DEF_NAME_WITH_PREFIX} bounced the\n{B_ATK_NAME_WITH_PREFIX} back!");  //TODO 汉化
#else
_("The {B_DEF_NAME_WITH_PREFIX} bounced the\n{B_ATK_NAME_WITH_PREFIX} back!");
#endif

static const u8 sText_ProteanTypeChange[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} transformed\nit into the {B_BUFF1} type!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} transformed\nit into the {B_BUFF1} type!");
#endif

static const u8 sText_SymbiosisItemPass[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} passed its {B_LAST_ITEM}\nto {B_SCR_ACTIVE_NAME_WITH_PREFIX} through {B_ATK_ABILITY}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} passed its {B_LAST_ITEM}\nto {B_SCR_ACTIVE_NAME_WITH_PREFIX} through {B_ATK_ABILITY}!");
#endif

static const u8 sText_StealthRockDmg[] = 
#ifdef CHINESE
_("Pointed stones dug into\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}!"); //TODO 汉化
#else
_("Pointed stones dug into\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_ToxicSpikesAbsorbed[] = 
#ifdef CHINESE
_("The poison spikes disappeared\nfrom around the opposing team's feet!");  //TODO 汉化
#else
_("The poison spikes disappeared\nfrom around the opposing team's feet!");
#endif

static const u8 sText_ToxicSpikesPoisoned[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} was poisoned!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} was poisoned!");
#endif

static const u8 sText_StickyWebSwitchIn[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} was\ncaught in a Sticky Web!");  //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} was\ncaught in a Sticky Web!");
#endif

static const u8 sText_HealingWishCameTrue[] = 
#ifdef CHINESE
_("The healing wish came true\nfor {B_ATK_NAME_WITH_PREFIX}!"); //TODO 汉化
#else
_("The healing wish came true\nfor {B_ATK_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_HealingWishHealed[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} regained health!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} regained health!");
#endif

static const u8 sText_LunarDanceCameTrue[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} became cloaked\nin mystical moonlight!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} became cloaked\nin mystical moonlight!");
#endif

static const u8 sText_CursedBodyDisabled[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled\nby {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled\nby {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!");
#endif

static const u8 sText_AttackerAquiredAbility[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} acquired {B_LAST_ABILITY}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} acquired {B_LAST_ABILITY}!");
#endif

static const u8 sText_TargetStatWontGoHigher[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\nwon't go higher!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\nwon't go higher!");
#endif

static const u8 sText_PkmnMoveBouncedViaAbility[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} was\nbounced back by {B_DEF_NAME_WITH_PREFIX}'s\l{B_DEF_ABILITY}!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} was\nbounced back by {B_DEF_NAME_WITH_PREFIX}'s\l{B_DEF_ABILITY}!");
#endif

static const u8 sText_ImposterTransform[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} transformed into\n{B_DEF_NAME_WITH_PREFIX} using {B_LAST_ABILITY}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} transformed into\n{B_DEF_NAME_WITH_PREFIX} using {B_LAST_ABILITY}!");
#endif

static const u8 sText_NotDoneYet[] = 
#ifdef CHINESE
_("This move effect is not done yet!\p");   //TODO 汉化
#else
_("This move effect is not done yet!\p");
#endif

static const u8 sText_PkmnBlewAwayToxicSpikes[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} blew away\nTOXIC SPIKES!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} blew away\nTOXIC SPIKES!");
#endif

static const u8 sText_PkmnBlewAwayStickyWeb[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} blew away\nSTICKY WEB!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} blew away\nSTICKY WEB!");
#endif

static const u8 sText_PkmnBlewAwayStealthRock[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} blew away\nSTEALTH ROCK!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} blew away\nSTEALTH ROCK!");
#endif

static const u8 sText_StickyWebUsed[] = 
#ifdef CHINESE
_("A sticky web spreads out on the\nground around {B_DEF_TEAM2} team!");    //TODO 汉化
#else
_("A sticky web spreads out on the\nground around {B_DEF_TEAM2} team!");
#endif

static const u8 sText_QuashSuccess[] = 
#ifdef CHINESE
_("The opposing {B_ATK_NAME_WITH_PREFIX}'s move was postponed!");   //TODO 汉化
#else
_("The opposing {B_ATK_NAME_WITH_PREFIX}'s move was postponed!");
#endif

static const u8 sText_IonDelugeOn[] = 
#ifdef CHINESE
_("A deluge of ions showers\nthe battlefield!");    //TODO 汉化
#else
_("A deluge of ions showers\nthe battlefield!");
#endif

static const u8 sText_TopsyTurvySwitchedStats[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s stat changes were\nall reversed!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s stat changes were\nall reversed!");
#endif

static const u8 sText_TerrainBecomesMisty[] = 
#ifdef CHINESE
_("Mist swirled about\nthe battlefield!");  //TODO 汉化
#else
_("Mist swirled about\nthe battlefield!");
#endif

static const u8 sText_TerrainBecomesGrassy[] = 
#ifdef CHINESE
_("Grass grew to cover\nthe battlefield!"); //TODO 汉化
#else
_("Grass grew to cover\nthe battlefield!");
#endif

static const u8 sText_TerrainBecomesElectric[] = 
#ifdef CHINESE
_("An electric current runs across\nthe battlefield!"); //TODO 汉化
#else
_("An electric current runs across\nthe battlefield!");
#endif

static const u8 sText_TerrainBecomesPsychic[] = 
#ifdef CHINESE
_("The battlefield got weird!");    //TODO 汉化
#else
_("The battlefield got weird!");
#endif

static const u8 sText_TargetElectrified[] = 
#ifdef CHINESE
_("The {B_DEF_NAME_WITH_PREFIX}'s moves\nhave been electrified!");  //TODO 汉化
#else
_("The {B_DEF_NAME_WITH_PREFIX}'s moves\nhave been electrified!");
#endif

static const u8 sText_AssaultVestDoesntAllow[] = 
#ifdef CHINESE
_("The effects of the {B_LAST_ITEM} prevent status\nmoves from being used!\p"); //TODO 汉化
#else
_("The effects of the {B_LAST_ITEM} prevent status\nmoves from being used!\p");
#endif

static const u8 sText_GravityPreventsUsage[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} can't use {B_CURRENT_MOVE}\nbecause of gravity!\p");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} can't use {B_CURRENT_MOVE}\nbecause of gravity!\p");
#endif

static const u8 sText_HealBlockPreventsUsage[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} was\nprevented from healing!\p");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} was\nprevented from healing!\p");
#endif

static const u8 sText_MegaEvoReacting[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ITEM} is \nreacting to {B_ATK_TRAINER_NAME}'s Mega Ring!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ITEM} is \nreacting to {B_ATK_TRAINER_NAME}'s Mega Ring!");
#endif

static const u8 sText_FerventWishReached[] = 
#ifdef CHINESE
_("{B_ATK_TRAINER_NAME}'s fervent wish\nhas reached {B_ATK_NAME_WITH_PREFIX}!");    //TODO 汉化
#else
_("{B_ATK_TRAINER_NAME}'s fervent wish\nhas reached {B_ATK_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_MegaEvoEvolved[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} has Mega\nEvolved into Mega {B_BUFF1}!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} has Mega\nEvolved into Mega {B_BUFF1}!");
#endif

static const u8 sText_drastically[] = 
#ifdef CHINESE
_("drastically ");  //TODO 汉化
#else
_("drastically ");
#endif

static const u8 sText_severely[] = 
#ifdef CHINESE
_("severely "); //TODO 汉化
#else
_("severely ");
#endif

static const u8 sText_Infestation[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} has been afflicted\nwith an infestation by {B_ATK_NAME_WITH_PREFIX}!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} has been afflicted\nwith an infestation by {B_ATK_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_NoEffectOnTarget[] = 
#ifdef CHINESE
_("It had no effect\non {B_DEF_NAME_WITH_PREFIX}!");    //TODO 汉化
#else
_("It had no effect\non {B_DEF_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_BurstingFlames[] = 
#ifdef CHINESE
_("The bursting flames\nhit {B_SCR_ACTIVE_NAME_WITH_PREFIX}!"); //TODO 汉化
#else
_("The bursting flames\nhit {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_BestowItemGiving[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} received {B_LAST_ITEM}\nfrom {B_ATK_NAME_WITH_PREFIX}!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} received {B_LAST_ITEM}\nfrom {B_ATK_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_ThirdTypeAdded[] = 
#ifdef CHINESE
_("{B_BUFF1} type was added to\n{B_DEF_NAME_WITH_PREFIX}!");    //TODO 汉化
#else
_("{B_BUFF1} type was added to\n{B_DEF_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_FellForFeint[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} fell for\nthe feint!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} fell for\nthe feint!");
#endif

static const u8 sText_PokemonCannotUseMove[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 无法\n使用 {B_CURRENT_MOVE}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} cannot\nuse {B_CURRENT_MOVE}!");
#endif

static const u8 sText_CoveredInPowder[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} is covered in powder!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} is covered in powder!");
#endif

static const u8 sText_PowderExplodes[] = 
#ifdef CHINESE
_("When the flame touched the powder\non the Pokémon, it exploded!");   //TODO 汉化
#else
_("When the flame touched the powder\non the Pokémon, it exploded!");
#endif

static const u8 sText_BelchCantUse[] = 
#ifdef CHINESE
_("Belch cannot be used!\p");   //TODO 汉化
#else
_("Belch cannot be used!\p");
#endif

static const u8 sText_SpectralThiefSteal[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} stole the target's\nboosted stats!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} stole the target's\nboosted stats!");
#endif

static const u8 sText_GravityGrounding[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} can't stay airborne\nbecause of gravity!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} can't stay airborne\nbecause of gravity!");
#endif

static const u8 sText_MistyTerrainPreventsStatus[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} surrounds itself\nwith a protective mist!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} surrounds itself\nwith a protective mist!");
#endif

static const u8 sText_GrassyTerrainHeals[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is healed\nby the grassy terrain!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is healed\nby the grassy terrain!");
#endif

static const u8 sText_ElectricTerrainPreventsSleep[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} surrounds itself\nwith electrified terrain!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} surrounds itself\nwith electrified terrain!");
#endif

static const u8 sText_PsychicTerrainPreventsPriority[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} surrounds itself\nwith psychic terrain!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} surrounds itself\nwith psychic terrain!");
#endif

static const u8 sText_SafetyGooglesProtected[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} is not affected\nthanks to its {B_LAST_ITEM}!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} is not affected\nthanks to its {B_LAST_ITEM}!");
#endif

static const u8 sText_FlowerVeilProtected[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} surrounded itself\nwith a veil of petals!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} surrounded itself\nwith a veil of petals!");
#endif

static const u8 sText_SweetVeilProtected[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} surrounded itself\nwith a veil of sweetness!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} surrounded itself\nwith a veil of sweetness!");
#endif

static const u8 sText_AromaVeilProtected[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} is protected\nby an aromatic veil!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} is protected\nby an aromatic veil!");
#endif

static const u8 sText_CelebrateMessage[] = 
#ifdef CHINESE
_("Congratulations, {B_PLAYER_NAME}!"); //TODO 汉化
#else
_("Congratulations, {B_PLAYER_NAME}!");
#endif

static const u8 sText_UsedInstructedMove[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} used the move\ninstructed by {B_BUFF1}!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} used the move\ninstructed by {B_BUFF1}!");
#endif

static const u8 sText_LaserFocusMessage[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}\nconcentrated intensely!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}\nconcentrated intensely!");
#endif

static const u8 sText_GemActivates[] = 
#ifdef CHINESE
_("{B_LAST_ITEM} strengthened\n{B_ATK_NAME_WITH_PREFIX}'s power!"); //TODO 汉化
#else
_("{B_LAST_ITEM} strengthened\n{B_ATK_NAME_WITH_PREFIX}'s power!");
#endif

static const u8 sText_BerryDmgReducing[] = 
#ifdef CHINESE
_("{B_LAST_ITEM} weakened the damage\nto {B_DEF_NAME_WITH_PREFIX}!");   //TODO 汉化
#else
_("{B_LAST_ITEM} weakened the damage\nto {B_DEF_NAME_WITH_PREFIX}!");
#endif

static const u8 sText_TargetAteItem[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX} ate its {B_LAST_ITEM}!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX} ate its {B_LAST_ITEM}!");
#endif

static const u8 sText_AirBalloonFloat[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} floats in the air\nwith its {B_LAST_ITEM}!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} floats in the air\nwith its {B_LAST_ITEM}!");
#endif

static const u8 sText_AirBalloonPop[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM} popped!");  //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM} popped!");
#endif

static const u8 sText_IncinerateBurn[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nwas burnt up!");   //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}\nwas burnt up!");
#endif

static const u8 sText_BugBite[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} stole and ate\n{B_EFF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} stole and ate\n{B_EFF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
#endif

static const u8 sText_IllusionWoreOff[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s Illusion wore off!"); //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s Illusion wore off!");
#endif

static const u8 sText_AttackerCuredTargetStatus[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} cured\n{B_DEF_NAME_WITH_PREFIX}'s problem!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} cured\n{B_DEF_NAME_WITH_PREFIX}'s problem!");
#endif

static const u8 sText_AttackerLostFireType[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} 燃尽了自己！");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} burned itself out!");
#endif

static const u8 sText_HealerCure[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY}\ncured {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s problem!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY}\ncured {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s problem!");
#endif

static const u8 sText_ReceiverAbilityTakeOver[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nwas taken over!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nwas taken over!");
#endif

static const u8 sText_PkmnAbsorbingPower[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} is absorbing power!");  //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} is absorbing power!");
#endif

static const u8 sText_NoOneWillBeAbleToRun[] = 
#ifdef CHINESE
_("在下一回合中\n没有宝可梦能够逃跑！");    //TODO 汉化
#else
_("No one will be able to run away\nduring the next turn!");
#endif

static const u8 sText_DestinyKnotActivates[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} fell in love\nfrom the {B_LAST_ITEM}!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} fell in love\nfrom the {B_LAST_ITEM}!");
#endif

static const u8 sText_CloakedInAFreezingLight[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} became cloaked\nin a freezing light!"); //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} became cloaked\nin a freezing light!");
#endif

static const u8 sText_StatWasNotLowered[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\nwas not lowered!");    //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}\nwas not lowered!");
#endif

static const u8 sText_AuraFlaredToLife[] = 
#ifdef CHINESE
_("{B_DEF_NAME_WITH_PREFIX}'s aura flared to life!");   //TODO 汉化
#else
_("{B_DEF_NAME_WITH_PREFIX}'s aura flared to life!");
#endif

static const u8 sText_AirLockActivates[] = 
#ifdef CHINESE
_("天气带来的效果\n消失了。");  //TODO 汉化
#else
_("The effects of weather\ndisappeared.");
#endif

static const u8 sText_PressureActivates[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is exerting its\npressure!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is exerting its\npressure!");
#endif

static const u8 sText_DarkAuraActivates[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating\na dark aura!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating\na dark aura!");
#endif

static const u8 sText_FairyAuraActivates[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating\na fairy aura!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating\na fairy aura!");
#endif

static const u8 sText_AuraBreakActivates[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} reversed all\nother POKéMON's auras!");  //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} reversed all\nother POKéMON's auras!");
#endif

static const u8 sText_ComatoseActivates[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is drowsing!");  //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is drowsing!");
#endif

static const u8 sText_ScreenCleanerActivates[] = 
#ifdef CHINESE
_("All screens on the field were\ncleansed!");  //TODO 汉化
#else
_("All screens on the field were\ncleansed!");
#endif

static const u8 sText_FetchedPokeBall[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} found\na {B_LAST_ITEM}!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} found\na {B_LAST_ITEM}!");
#endif

static const u8 sText_BattlerAbilityRaisedStat[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nraised its {B_BUFF1}!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY}\nraised its {B_BUFF1}!");
#endif

static const u8 sText_ASandstormKickedUp[] = 
#ifdef CHINESE
_("A sandstorm kicked up!");    //TODO 汉化
#else
_("A sandstorm kicked up!");
#endif

static const u8 sText_PkmnsWillPerishIn3Turns[] = 
#ifdef CHINESE
_("Both Pokémon will perish\nin three turns!"); //TODO 汉化
#else
_("Both Pokémon will perish\nin three turns!");
#endif

static const u8 sText_AbilityRaisedStatDrastically[] = 
#ifdef CHINESE
_("{B_DEF_ABILITY} raised {B_DEF_NAME_WITH_PREFIX}'s\n{B_BUFF1} drastically!"); //TODO 汉化
#else
_("{B_DEF_ABILITY} raised {B_DEF_NAME_WITH_PREFIX}'s\n{B_BUFF1} drastically!");
#endif

static const u8 sText_AsOneEnters[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} has two Abilities!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} has two Abilities!");
#endif

static const u8 sText_CuriousMedicineEnters[] = 
#ifdef CHINESE
_("{B_EFF_NAME_WITH_PREFIX}'s\nstat changes were reset!");  //TODO 汉化
#else
_("{B_EFF_NAME_WITH_PREFIX}'s\nstat changes were reset!");
#endif

static const u8 sText_CanActFaster[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} can act faster,\nthanks to {B_LAST_ITEM}!");    //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} can act faster,\nthanks to {B_LAST_ITEM}!");
#endif

static const u8 sText_MicleBerryActivates[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} boosted the accuracy of its\nnext move using {B_LAST_ITEM}!");   //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} boosted the accuracy of its\nnext move using {B_LAST_ITEM}!");
#endif

static const u8 sText_PkmnShookOffTheTaunt[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} shook off\nthe taunt!"); //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} shook off\nthe taunt!");
#endif

static const u8 sText_PkmnGotOverItsInfatuation[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} got over\nits infatuation!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} got over\nits infatuation!");
#endif


const u8 *const gBattleStringsTable[BATTLESTRINGS_COUNT] =
{
    [STRINGID_PKMNGOTOVERITSINFATUATION - 12] = sText_PkmnGotOverItsInfatuation,
    [STRINGID_PKMNSHOOKOFFTHETAUNT - 12] = sText_PkmnShookOffTheTaunt,
    [STRINGID_MICLEBERRYACTIVATES - 12] = sText_MicleBerryActivates,
    [STRINGID_CANACTFASTERTHANKSTO - 12] = sText_CanActFaster,
    [STRINGID_CURIOUSMEDICINEENTERS - 12] = sText_CuriousMedicineEnters,
    [STRINGID_ASONEENTERS - 12] = sText_AsOneEnters,
    [STRINGID_ABILITYRAISEDSTATDRASTICALLY - 12] = sText_AbilityRaisedStatDrastically,
    [STRINGID_PKMNSWILLPERISHIN3TURNS - 12] = sText_PkmnsWillPerishIn3Turns,
    [STRINGID_ASANDSTORMKICKEDUP - 12] = sText_ASandstormKickedUp,
    [STRINGID_BATTLERABILITYRAISEDSTAT - 12] = sText_BattlerAbilityRaisedStat,
    [STRINGID_FETCHEDPOKEBALL - 12] = sText_FetchedPokeBall,
    [STRINGID_STATWASNOTLOWERED - 12] = sText_StatWasNotLowered,
    [STRINGID_CLOAKEDINAFREEZINGLIGHT - 12] = sText_CloakedInAFreezingLight,
    [STRINGID_DESTINYKNOTACTIVATES - 12] = sText_DestinyKnotActivates,
    [STRINGID_NOONEWILLBEABLETORUNAWAY - 12] = sText_NoOneWillBeAbleToRun,
    [STRINGID_PKNMABSORBINGPOWER - 12] = sText_PkmnAbsorbingPower,
    [STRINGID_RECEIVERABILITYTAKEOVER - 12] = sText_ReceiverAbilityTakeOver,
    [STRINGID_SCRIPTINGABILITYSTATRAISE - 12] = sText_ScriptingAbilityRaisedStat,
    [STRINGID_HEALERCURE - 12] = sText_HealerCure,
    [STRINGID_ATTACKERLOSTFIRETYPE - 12] = sText_AttackerLostFireType,
    [STRINGID_ATTACKERCUREDTARGETSTATUS - 12] = sText_AttackerCuredTargetStatus,
    [STRINGID_ILLUSIONWOREOFF - 12] = sText_IllusionWoreOff,
    [STRINGID_BUGBITE - 12] = sText_BugBite,
    [STRINGID_INCINERATEBURN - 12] = sText_IncinerateBurn,
    [STRINGID_AIRBALLOONPOP - 12] = sText_AirBalloonPop,
    [STRINGID_AIRBALLOONFLOAT - 12] = sText_AirBalloonFloat,
    [STRINGID_TARGETATEITEM - 12] = sText_TargetAteItem,
    [STRINGID_BERRYDMGREDUCES - 12] = sText_BerryDmgReducing,
    [STRINGID_GEMACTIVATES - 12] = sText_GemActivates,
    [STRINGID_LASERFOCUS - 12] = sText_LaserFocusMessage,
    [STRINGID_THROATCHOPENDS - 12] = sText_ThroatChopEnds,
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP - 12] = sText_PkmnCantUseMoveThroatChop,
    [STRINGID_USEDINSTRUCTEDMOVE - 12] = sText_UsedInstructedMove,
    [STRINGID_CELEBRATEMESSAGE - 12] = sText_CelebrateMessage,
    [STRINGID_AROMAVEILPROTECTED - 12] = sText_AromaVeilProtected,
    [STRINGID_SWEETVEILPROTECTED - 12] = sText_SweetVeilProtected,
    [STRINGID_FLOWERVEILPROTECTED - 12] = sText_FlowerVeilProtected,
    [STRINGID_SAFETYGOOGLESPROTECTED - 12] = sText_SafetyGooglesProtected,
    [STRINGID_SPECTRALTHIEFSTEAL - 12] = sText_SpectralThiefSteal,
    [STRINGID_BELCHCANTSELECT - 12] = sText_BelchCantUse,
    [STRINGID_TRAINER1LOSETEXT - 12] = sText_Trainer1LoseText,
    [STRINGID_PKMNGAINEDEXP - 12] = sText_PkmnGainedEXP,
    [STRINGID_PKMNGREWTOLV - 12] = sText_PkmnGrewToLv,
    [STRINGID_PKMNLEARNEDMOVE - 12] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1 - 12] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2 - 12] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3 - 12] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE - 12] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE - 12] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE - 12] = sText_DidNotLearnMove,
    [STRINGID_PKMNLEARNEDMOVE2 - 12] = sText_PkmnLearnedMove2,
    [STRINGID_ATTACKMISSED - 12] = sText_AttackMissed,
    [STRINGID_PKMNPROTECTEDITSELF - 12] = sText_PkmnProtectedItself,
    [STRINGID_STATSWONTINCREASE2 - 12] = sText_StatsWontIncrease2,
    [STRINGID_AVOIDEDDAMAGE - 12] = sText_AvoidedDamage,
    [STRINGID_ITDOESNTAFFECT - 12] = sText_ItDoesntAffect,
    [STRINGID_ATTACKERFAINTED - 12] = sText_AttackerFainted,
    [STRINGID_TARGETFAINTED - 12] = sText_TargetFainted,
    [STRINGID_PLAYERGOTMONEY - 12] = sText_PlayerGotMoney,
    [STRINGID_PLAYERWHITEOUT - 12] = sText_PlayerWhiteout,
    [STRINGID_PLAYERWHITEOUT2 - 12] = sText_PlayerWhiteout2,
    [STRINGID_PREVENTSESCAPE - 12] = sText_PreventsEscape,
    [STRINGID_HITXTIMES - 12] = sText_HitXTimes,
    [STRINGID_PKMNFELLASLEEP - 12] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP - 12] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP - 12] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2 - 12] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED - 12] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED - 12] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY - 12] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNHURTBYPOISON - 12] = sText_PkmnHurtByPoison,
    [STRINGID_PKMNALREADYPOISONED - 12] = sText_PkmnAlreadyPoisoned,
    [STRINGID_PKMNBADLYPOISONED - 12] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED - 12] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED - 12] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY - 12] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN - 12] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN - 12] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY - 12] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN - 12] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED - 12] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2 - 12] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY - 12] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED - 12] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY - 12] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED - 12] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED - 12] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS - 12] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN - 12] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE - 12] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE - 12] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING - 12] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING - 12] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED - 12] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION - 12] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED - 12] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED - 12] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE - 12] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE - 12] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE - 12] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY - 12] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE - 12] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED - 12] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH - 12] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL - 12] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF - 12] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF - 12] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL - 12] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD - 12] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED - 12] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP - 12] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY - 12] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND - 12] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT - 12] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD - 12] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING - 12] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH - 12] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE - 12] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND - 12] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX - 12] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY - 12] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED - 12] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY - 12] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM - 12] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED - 12] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST - 12] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST - 12] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED - 12] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL - 12] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNPROTECTEDITSELF2 - 12] = sText_PkmnProtectedItself2,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM - 12] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL - 12] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED - 12] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK - 12] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED - 12] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP - 12] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP - 12] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE - 12] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR - 12] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR - 12] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR - 12] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN - 12] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR - 12] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED - 12] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE - 12] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2 - 12] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE - 12] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING - 12] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY - 12] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY - 12] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION - 12] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY - 12] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNUNAFFECTED - 12] = sText_PkmnUnaffected,
    [STRINGID_PKMNTRANSFORMEDINTO - 12] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE - 12] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE - 12] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED - 12] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED - 12] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE - 12] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING - 12] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED - 12] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED - 12] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE - 12] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE - 12] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED - 12] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM - 12] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE - 12] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE - 12] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE - 12] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP - 12] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM - 12] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW - 12] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE - 12] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE - 12] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE - 12] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE - 12] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED - 12] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES - 12] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED - 12] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL - 12] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF - 12] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT - 12] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH - 12] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK - 12] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES - 12] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNGOTFREE - 12] = sText_PkmnGotFree,
    [STRINGID_PKMNSHEDLEECHSEED - 12] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES - 12] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE - 12] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK - 12] = sText_PkmnForesawAttack,
    [STRINGID_PKMNTOOKATTACK - 12] = sText_PkmnTookAttack,
    [STRINGID_PKMNATTACK - 12] = sText_PkmnAttack,
    [STRINGID_PKMNCENTERATTENTION - 12] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER - 12] = sText_PkmnChargingPower,
    [STRINGID_NATUREPOWERTURNEDINTO - 12] = sText_NaturePowerTurnedInto,
    [STRINGID_PKMNSTATUSNORMAL - 12] = sText_PkmnStatusNormal,
    [STRINGID_PKMNHASNOMOVESLEFT - 12] = sText_PkmnHasNoMovesLeft,
    [STRINGID_PKMNSUBJECTEDTOTORMENT - 12] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT - 12] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS - 12] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT - 12] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT - 12] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP - 12] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS - 12] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE - 12] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH - 12] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE - 12] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS - 12] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS - 12] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF - 12] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY - 12] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF - 12] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES - 12] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE - 12] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED - 12] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE - 12] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE - 12] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF - 12] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED - 12] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET - 12] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE - 12] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN - 12] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED - 12] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY - 12] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE - 12] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING - 12] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH - 12] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH - 12] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH - 12] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH - 12] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH - 12] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH - 12] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH - 12] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH - 12] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH - 12] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH - 12] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED - 12] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY - 12] = gText_StatSharply,
    [STRINGID_STATROSE - 12] = gText_StatRose,
    [STRINGID_STATHARSHLY - 12] = sText_StatHarshly,
    [STRINGID_STATFELL - 12] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE - 12] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE - 12] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL - 12] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL - 12] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT - 12] = sText_CriticalHit,
    [STRINGID_ONEHITKO - 12] = sText_OneHitKO,
    [STRINGID_123POOF - 12] = sText_123Poof,
    [STRINGID_ANDELLIPSIS - 12] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE - 12] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE - 12] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY - 12] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED - 12] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS - 12] = sText_NoRunningFromTrainers,
    [STRINGID_CANTESCAPE - 12] = sText_CantEscape,
    [STRINGID_DONTLEAVEBIRCH - 12] = sText_DontLeaveBirch,
    [STRINGID_BUTNOTHINGHAPPENED - 12] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED - 12] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION - 12] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED - 12] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN - 12] = sText_StartedToRain,
    [STRINGID_DOWNPOURSTARTED - 12] = sText_DownpourStarted,
    [STRINGID_RAINCONTINUES - 12] = sText_RainContinues,
    [STRINGID_DOWNPOURCONTINUES - 12] = sText_DownpourContinues,
    [STRINGID_RAINSTOPPED - 12] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED - 12] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES - 12] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED - 12] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT - 12] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG - 12] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED - 12] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL - 12] = sText_StartedHail,
    [STRINGID_HAILCONTINUES - 12] = sText_HailContinues,
    [STRINGID_HAILSTOPPED - 12] = sText_HailStopped,
    [STRINGID_FAILEDTOSPITUP - 12] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW - 12] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE - 12] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE - 12] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED - 12] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE - 12] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN - 12] = sText_SharedPain,
    [STRINGID_BELLCHIMED - 12] = sText_BellChimed,
    [STRINGID_FAINTINTHREE - 12] = sText_FaintInThree,
    [STRINGID_NOPPLEFT - 12] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT - 12] = sText_ButNoPPLeft,
    [STRINGID_PLAYERUSEDITEM - 12] = sText_PlayerUsedItem,
    [STRINGID_WALLYUSEDITEM - 12] = sText_WallyUsedItem,
    [STRINGID_TRAINERBLOCKEDBALL - 12] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF - 12] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL - 12] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN - 12] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE - 12] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT - 12] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT - 12] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE - 12] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHT - 12] = sText_GotchaPkmnCaught,
    [STRINGID_GOTCHAPKMNCAUGHT2 - 12] = sText_GotchaPkmnCaught2,
    [STRINGID_GIVENICKNAMECAPTURED - 12] = sText_GiveNicknameCaptured,
    [STRINGID_PKMNSENTTOPC - 12] = sText_PkmnSentToPC,
    [STRINGID_PKMNDATAADDEDTODEX - 12] = sText_PkmnDataAddedToDex,
    [STRINGID_ITISRAINING - 12] = sText_ItIsRaining,
    [STRINGID_SANDSTORMISRAGING - 12] = sText_SandstormIsRaging,
    [STRINGID_CANTESCAPE2 - 12] = sText_CantEscape2,
    [STRINGID_PKMNIGNORESASLEEP - 12] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS - 12] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP - 12] = sText_PkmnBeganToNap,
    [STRINGID_PKMNLOAFING - 12] = sText_PkmnLoafing,
    [STRINGID_PKMNWONTOBEY - 12] = sText_PkmnWontObey,
    [STRINGID_PKMNTURNEDAWAY - 12] = sText_PkmnTurnedAway,
    [STRINGID_PKMNPRETENDNOTNOTICE - 12] = sText_PkmnPretendNotNotice,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN - 12] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_CREPTCLOSER - 12] = sText_CreptCloser,
    [STRINGID_CANTGETCLOSER - 12] = sText_CantGetCloser,
    [STRINGID_PKMNWATCHINGCAREFULLY - 12] = sText_PkmnWatchingCarefully,
    [STRINGID_PKMNCURIOUSABOUTX - 12] = sText_PkmnCuriousAboutX,
    [STRINGID_PKMNENTHRALLEDBYX - 12] = sText_PkmnEnthralledByX,
    [STRINGID_PKMNIGNOREDX - 12] = sText_PkmnIgnoredX,
    [STRINGID_THREWPOKEBLOCKATPKMN - 12] = sText_ThrewPokeblockAtPkmn,
    [STRINGID_OUTOFSAFARIBALLS - 12] = sText_OutOfSafariBalls,
    [STRINGID_PKMNSITEMCUREDPARALYSIS - 12] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON - 12] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN - 12] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT - 12] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT - 12] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT - 12] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM - 12] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH - 12] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP - 12] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS - 12] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE - 12] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE - 12] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX - 12] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3 - 12] = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS - 12] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY - 12] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2 - 12] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM - 12] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS - 12] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY - 12] = sText_PkmnsXInfatuatedY,
    [STRINGID_PKMNSXMADEYINEFFECTIVE - 12] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM - 12] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE - 12] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED - 12] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED - 12] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED - 12] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER - 12] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP - 12] = sText_PkmnSprangUp,
    [STRINGID_HMMOVESCANTBEFORGOTTEN - 12] = sText_HMMovesCantBeForgotten,
    [STRINGID_XFOUNDONEY - 12] = sText_XFoundOneY,
    [STRINGID_PLAYERDEFEATEDTRAINER1 - 12] = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA - 12] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW - 12] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ - 12] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE - 12] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED - 12] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNSXMADEYUSELESS - 12] = sText_PkmnsXMadeYUseless,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB - 12] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4 - 12] = sText_EmptyString4,
    [STRINGID_ABOOSTED - 12] = sText_ABoosted,
    [STRINGID_PKMNSXINTENSIFIEDSUN - 12] = sText_PkmnsXIntensifiedSun,
    [STRINGID_PKMNMAKESGROUNDMISS - 12] = sText_PkmnMakesGroundMiss,
    [STRINGID_YOUTHROWABALLNOWRIGHT - 12] = sText_YouThrowABallNowRight,
    [STRINGID_PKMNSXTOOKATTACK - 12] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY - 12] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNLOSTFOCUS - 12] = sText_PkmnLostFocus,
    [STRINGID_USENEXTPKMN - 12] = sText_UseNextPkmn,
    [STRINGID_PKMNFLEDUSINGITS - 12] = sText_PkmnFledUsingIts,
    [STRINGID_PKMNFLEDUSING - 12] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT - 12] = sText_PkmnWasDraggedOut,
    [STRINGID_PREVENTEDFROMWORKING - 12] = sText_PreventedFromWorking,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS - 12] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_TRAINER1USEDITEM - 12] = sText_Trainer1UsedItem,
    [STRINGID_BOXISFULL - 12] = sText_BoxIsFull,
    [STRINGID_PKMNAVOIDEDATTACK - 12] = sText_PkmnAvoidedAttack,
    [STRINGID_PKMNSXMADEITINEFFECTIVE - 12] = sText_PkmnsXMadeItIneffective,
    [STRINGID_PKMNSXPREVENTSFLINCHING - 12] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN - 12] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2 - 12] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXBLOCKSY2 - 12] = sText_PkmnsXBlocksY2,
    [STRINGID_PKMNSXWOREOFF - 12] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE - 12] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE - 12] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED - 12] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ - 12] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM - 12] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_ATTACKERCANTESCAPE - 12] = sText_AttackerCantEscape,
    [STRINGID_PKMNOBTAINEDX - 12] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2 - 12] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ - 12] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_BUTNOEFFECT - 12] = sText_ButNoEffect,
    [STRINGID_PKMNSXHADNOEFFECTONY - 12] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_TWOENEMIESDEFEATED - 12] = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT - 12] = sText_Trainer2LoseText,
    [STRINGID_PKMNINCAPABLEOFPOWER - 12] = sText_PkmnIncapableOfPower,
    [STRINGID_GLINTAPPEARSINEYE - 12] = sText_GlintAppearsInEye,
    [STRINGID_PKMNGETTINGINTOPOSITION - 12] = sText_PkmnGettingIntoPosition,
    [STRINGID_PKMNBEGANGROWLINGDEEPLY - 12] = sText_PkmnBeganGrowlingDeeply,
    [STRINGID_PKMNEAGERFORMORE - 12] = sText_PkmnEagerForMore,
    [STRINGID_DEFEATEDOPPONENTBYREFEREE - 12] = sText_DefeatedOpponentByReferee,
    [STRINGID_LOSTTOOPPONENTBYREFEREE - 12] = sText_LostToOpponentByReferee,
    [STRINGID_TIEDOPPONENTBYREFEREE - 12] = sText_TiedOpponentByReferee,
    [STRINGID_QUESTIONFORFEITMATCH - 12] = sText_QuestionForfeitMatch,
    [STRINGID_FORFEITEDMATCH - 12] = sText_ForfeitedMatch,
    [STRINGID_PKMNTRANSFERREDSOMEONESPC - 12] = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC - 12] = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL - 12] = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL - 12] = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT - 12] = sText_Trainer1WinText,
    [STRINGID_TRAINER2WINTEXT - 12] = sText_Trainer2WinText,
    [STRINGID_ENDUREDSTURDY - 12] = sText_EnduredViaSturdy,
    [STRINGID_POWERHERB - 12] = sText_PowerHerbActivation,
    [STRINGID_HURTBYITEM - 12] = sText_HurtByItem,
    [STRINGID_PSNBYITEM - 12] = sText_BadlyPoisonedByItem,
    [STRINGID_BRNBYITEM - 12] = sText_BurnedByItem,
    [STRINGID_DEFABILITYIN - 12] = sText_TargetAbilityActivates,
    [STRINGID_GRAVITYINTENSIFIED - 12] = sText_GravityIntensified,
    [STRINGID_TARGETIDENTIFIED - 12] = sText_TargetIdentified,
    [STRINGID_TARGETWOKEUP - 12] = sText_TargetWokeUp,
    [STRINGID_PKMNSTOLEANDATEITEM - 12] = sText_PkmnStoleAndAteItem,
    [STRINGID_TAILWINDBLEW - 12] = sText_TailWindBlew,
    [STRINGID_PKMNWENTBACK - 12] = sText_PkmnWentBack,
    [STRINGID_PKMNCANTUSEITEMSANYMORE - 12] = sText_PkmnCantUseItemsAnymore,
    [STRINGID_PKMNFLUNG - 12] = sText_PkmnFlung,
    [STRINGID_PKMNPREVENTEDFROMHEALING - 12] = sText_PkmnPreventedFromHealing,
    [STRINGID_PKMNSWITCHEDATKANDDEF - 12] = sText_PkmnSwitchedAtkAndDef,
    [STRINGID_PKMNSABILITYSUPPRESSED - 12] = sText_PkmnsAbilitySuppressed,
    [STRINGID_SHIELDEDFROMCRITICALHITS - 12] = sText_ShieldedFromCriticalHits,
    [STRINGID_SWITCHEDATKANDSPATK - 12] = sText_SwitchedAtkAndSpAtk,
    [STRINGID_SWITCHEDDEFANDSPDEF - 12] = sText_SwitchedDefAndSpDef,
    [STRINGID_PKMNACQUIREDABILITY - 12] = sText_PkmnAcquiredAbility,
    [STRINGID_POISONSPIKESSCATTERED - 12] = sText_PoisonSpikesScattered,
    [STRINGID_PKMNSWITCHEDSTATCHANGES - 12] = sText_PkmnSwitchedStatChanges,
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER - 12] = sText_PkmnSurroundedWithVeilOfWater,
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM - 12] = sText_PkmnLevitatedOnElectromagnetism,
    [STRINGID_PKMNTWISTEDDIMENSIONS - 12] = sText_PkmnTwistedDimensions,
    [STRINGID_POINTEDSTONESFLOAT - 12] = sText_PointedStonesFloat,
    [STRINGID_CLOAKEDINMYSTICALMOONLIGHT - 12] = sText_CloakedInMysticalMoonlight,
    [STRINGID_TRAPPERBYSWIRLINGMAGMA - 12] = sText_TrappedBySwirlingMagma,
    [STRINGID_VANISHEDINSTANTLY - 12] = sText_VanishedInstantly,
    [STRINGID_PROTECTEDTEAM - 12] = sText_ProtectedTeam,
    [STRINGID_SHAREDITSGUARD - 12] = sText_SharedItsGuard,
    [STRINGID_SHAREDITSPOWER - 12] = sText_SharedItsPower,
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON - 12] = sText_SwapsDefAndSpDefOfAllPkmn,
    [STRINGID_BECAMENIMBLE - 12] = sText_BecameNimble,
    [STRINGID_HURLEDINTOTHEAIR - 12] = sText_HurledIntoTheAir,
    [STRINGID_HELDITEMSLOSEEFFECTS - 12] = sText_HeldItemsLoseEffects,
    [STRINGID_FELLSTRAIGHTDOWN - 12] = sText_FellStraightDown,
    [STRINGID_TRANSFORMEDINTOWATERTYPE - 12] = sText_TransformedIntoWaterType,
    [STRINGID_PKMNACQUIREDSIMPLE - 12] = sText_PkmnAcquiredSimple,
    [STRINGID_EMPTYSTRING5 - 12] = sText_EmptyString4,
    [STRINGID_KINDOFFER - 12] = sText_KindOffer,
    [STRINGID_RESETSTARGETSSTATLEVELS - 12] = sText_ResetsTargetsStatLevels,
    [STRINGID_EMPTYSTRING6 - 12] = sText_EmptyString4,
    [STRINGID_ALLYSWITCHPOSITION - 12] = sText_AllySwitchPosition,
    [STRINGID_RESTORETARGETSHEALTH - 12] = sText_RestoreTargetsHealth,
    [STRINGID_TOOKPJMNINTOTHESKY - 12] = sText_TookPkmnIntoTheSky,
    [STRINGID_FREEDFROMSKYDROP - 12] = sText_FreedFromSkyDrop,
    [STRINGID_POSTPONETARGETMOVE - 12] = sText_PostponeTargetMove,
    [STRINGID_REFLECTTARGETSTYPE - 12] = sText_ReflectTargetsType,
    [STRINGID_TRANSFERHELDITEM - 12] = sText_TransferHeldItem,
    [STRINGID_EMBARGOENDS - 12] = sText_EmbargoEnds,
    [STRINGID_ELECTROMAGNETISM - 12] = sText_Electromagnetism,
    [STRINGID_BUFFERENDS - 12] = sText_BufferEnds,
    [STRINGID_TELEKINESISENDS - 12] = sText_TelekinesisEnds,
    [STRINGID_TAILWINDENDS - 12] = sText_TailwindEnds,
    [STRINGID_LUCKYCHANTENDS - 12] = sText_LuckyChantEnds,
    [STRINGID_TRICKROOMENDS - 12] = sText_TrickRoomEnds,
    [STRINGID_WONDERROOMENDS - 12] = sText_WonderRoomEnds,
    [STRINGID_MAGICROOMENDS - 12] = sText_MagicRoomEnds,
    [STRINGID_MUDSPORTENDS - 12] = sText_MudSportEnds,
    [STRINGID_WATERSPORTENDS - 12] = sText_WaterSportEnds,
    [STRINGID_GRAVITYENDS - 12] = sText_GravityEnds,
    [STRINGID_AQUARINGHEAL - 12] = sText_AquaRingHeal,
    [STRINGID_AURORAVEILENDS - 12] = sText_AuroraVeilEnds,
    [STRINGID_ELECTRICTERRAINENDS - 12] = sText_ElectricTerrainEnds,
    [STRINGID_MISTYTERRAINENDS - 12] = sText_MistyTerrainEnds,
    [STRINGID_PSYCHICTERRAINENDS - 12] = sText_PsychicTerrainEnds,
    [STRINGID_GRASSYTERRAINENDS - 12] = sText_GrassyTerrainEnds,
    [STRINGID_TARGETABILITYSTATRAISE - 12] = sText_TargetAbilityRaisedStat,
    [STRINGID_TARGETSSTATWASMAXEDOUT - 12] = sText_TargetsStatWasMaxedOut,
    [STRINGID_ATTACKERABILITYSTATRAISE - 12] = sText_AttackerAbilityRaisedStat,
    [STRINGID_POISONHEALHPUP - 12] = sText_PoisonHealHpUp,
    [STRINGID_BADDREAMSDMG - 12] = sText_BadDreamsDmg,
    [STRINGID_MOLDBREAKERENTERS - 12] = sText_MoldBreakerEnters,
    [STRINGID_TERAVOLTENTERS - 12] = sText_TeravoltEnters,
    [STRINGID_TURBOBLAZEENTERS - 12] = sText_TurboblazeEnters,
    [STRINGID_SLOWSTARTENTERS - 12] = sText_SlowStartEnters,
    [STRINGID_SLOWSTARTEND - 12] = sText_SlowStartEnd,
    [STRINGID_SOLARPOWERHPDROP - 12] = sText_SolarPowerHpDrop,
    [STRINGID_AFTERMATHDMG - 12] = sText_AftermathDmg,
    [STRINGID_ANTICIPATIONACTIVATES - 12] = sText_AnticipationActivates,
    [STRINGID_FOREWARNACTIVATES - 12] = sText_ForewarnActivates,
    [STRINGID_ICEBODYHPGAIN - 12] = sText_IceBodyHpGain,
    [STRINGID_SNOWWARNINGHAIL - 12] = sText_SnowWarningHail,
    [STRINGID_FRISKACTIVATES - 12] = sText_FriskActivates,
    [STRINGID_UNNERVEENTERS - 12] = sText_UnnerveEnters,
    [STRINGID_HARVESTBERRY - 12] = sText_HarvestBerry,
    [STRINGID_LASTABILITYRAISEDSTAT - 12] = sText_LastAbilityRaisedBuff1,
    [STRINGID_MAGICBOUNCEACTIVATES - 12] = sText_MagicBounceActivates,
    [STRINGID_PROTEANTYPECHANGE - 12] = sText_ProteanTypeChange,
    [STRINGID_SYMBIOSISITEMPASS - 12] = sText_SymbiosisItemPass,
    [STRINGID_STEALTHROCKDMG - 12] = sText_StealthRockDmg,
    [STRINGID_TOXICSPIKESABSORBED - 12] = sText_ToxicSpikesAbsorbed,
    [STRINGID_TOXICSPIKESPOISONED - 12] = sText_ToxicSpikesPoisoned,
    [STRINGID_STICKYWEBSWITCHIN - 12] = sText_StickyWebSwitchIn,
    [STRINGID_HEALINGWISHCAMETRUE - 12] = sText_HealingWishCameTrue,
    [STRINGID_HEALINGWISHHEALED - 12] = sText_HealingWishHealed,
    [STRINGID_LUNARDANCECAMETRUE - 12] = sText_LunarDanceCameTrue,
    [STRINGID_CUSEDBODYDISABLED - 12] = sText_CursedBodyDisabled,
    [STRINGID_ATTACKERACQUIREDABILITY - 12] = sText_AttackerAquiredAbility,
    [STRINGID_TARGETABILITYSTATLOWER - 12] = sText_TargetAbilityLoweredStat,
    [STRINGID_TARGETSTATWONTGOHIGHER - 12] = sText_TargetStatWontGoHigher,
    [STRINGID_PKMNMOVEBOUNCEDABILITY - 12] = sText_PkmnMoveBouncedViaAbility,
    [STRINGID_IMPOSTERTRANSFORM - 12] = sText_ImposterTransform,
    [STRINGID_ASSAULTVESTDOESNTALLOW - 12] = sText_AssaultVestDoesntAllow,
    [STRINGID_GRAVITYPREVENTSUSAGE - 12] = sText_GravityPreventsUsage,
    [STRINGID_HEALBLOCKPREVENTSUSAGE - 12] = sText_HealBlockPreventsUsage,
    [STRINGID_NOTDONEYET - 12] = sText_NotDoneYet,
    [STRINGID_STICKYWEBUSED - 12] = sText_StickyWebUsed,
    [STRINGID_QUASHSUCCESS - 12] = sText_QuashSuccess,
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES - 12] = sText_PkmnBlewAwayToxicSpikes,
    [STRINGID_PKMNBLEWAWAYSTICKYWEB - 12] = sText_PkmnBlewAwayStickyWeb,
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK - 12] = sText_PkmnBlewAwayStealthRock,
    [STRINGID_IONDELUGEON - 12] = sText_IonDelugeOn,
    [STRINGID_TOPSYTURVYSWITCHEDSTATS - 12] = sText_TopsyTurvySwitchedStats,
    [STRINGID_TERRAINBECOMESMISTY - 12] = sText_TerrainBecomesMisty,
    [STRINGID_TERRAINBECOMESGRASSY - 12] = sText_TerrainBecomesGrassy,
    [STRINGID_TERRAINBECOMESELECTRIC - 12] = sText_TerrainBecomesElectric,
    [STRINGID_TERRAINBECOMESPSYCHIC - 12] = sText_TerrainBecomesPsychic,
    [STRINGID_TARGETELECTRIFIED - 12] = sText_TargetElectrified,
    [STRINGID_MEGAEVOREACTING - 12] = sText_MegaEvoReacting,
    [STRINGID_FERVENTWISHREACHED - 12] = sText_FerventWishReached,
    [STRINGID_MEGAEVOEVOLVED - 12] = sText_MegaEvoEvolved,
    [STRINGID_DRASTICALLY - 12] = sText_drastically,
    [STRINGID_SEVERELY - 12] = sText_severely,
    [STRINGID_INFESTATION - 12] = sText_Infestation,
    [STRINGID_NOEFFECTONTARGET - 12] = sText_NoEffectOnTarget,
    [STRINGID_BURSTINGFLAMESHIT - 12] = sText_BurstingFlames,
    [STRINGID_BESTOWITEMGIVING - 12] = sText_BestowItemGiving,
    [STRINGID_THIRDTYPEADDED - 12] = sText_ThirdTypeAdded,
    [STRINGID_FELLFORFEINT - 12] = sText_FellForFeint,
    [STRINGID_POKEMONCANNOTUSEMOVE - 12] = sText_PokemonCannotUseMove,
    [STRINGID_COVEREDINPOWDER - 12] = sText_CoveredInPowder,
    [STRINGID_POWDEREXPLODES - 12] = sText_PowderExplodes,
    [STRINGID_GRAVITYGROUNDING - 12] = sText_GravityGrounding,
    [STRINGID_MISTYTERRAINPREVENTS - 12] = sText_MistyTerrainPreventsStatus,
    [STRINGID_GRASSYTERRAINHEALS - 12] = sText_GrassyTerrainHeals,
    [STRINGID_ELECTRICTERRAINPREVENTS - 12] = sText_ElectricTerrainPreventsSleep,
    [STRINGID_PSYCHICTERRAINPREVENTS - 12] = sText_PsychicTerrainPreventsPriority,
    [STRINGID_AURAFLAREDTOLIFE - 12] = sText_AuraFlaredToLife,
    [STRINGID_AIRLOCKACTIVATES - 12] = sText_AirLockActivates,
    [STRINGID_PRESSUREENTERS - 12] = sText_PressureActivates,
    [STRINGID_DARKAURAENTERS - 12] = sText_DarkAuraActivates,
    [STRINGID_FAIRYAURAENTERS - 12] = sText_FairyAuraActivates,
    [STRINGID_AURABREAKENTERS - 12] = sText_AuraBreakActivates,
    [STRINGID_COMATOSEENTERS - 12] = sText_ComatoseActivates,
    [STRINGID_SCREENCLEANERENTERS - 12] = sText_ScreenCleanerActivates,
};

const u16 gTerrainStringIds[] =
{
    STRINGID_TERRAINBECOMESMISTY, STRINGID_TERRAINBECOMESGRASSY, STRINGID_TERRAINBECOMESELECTRIC, STRINGID_TERRAINBECOMESPSYCHIC
};

const u16 gTerrainPreventsStringIds[] =
{
    STRINGID_MISTYTERRAINPREVENTS, STRINGID_ELECTRICTERRAINPREVENTS, STRINGID_PSYCHICTERRAINPREVENTS
};

const u16 gMagicCoatBounceStringIds[] =
{
    STRINGID_PKMNMOVEBOUNCED, STRINGID_PKMNMOVEBOUNCEDABILITY
};

const u16 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE, STRINGID_LUNARDANCECAMETRUE
};

const u16 gDmgHazardsStringIds[] =
{
    STRINGID_PKMNHURTBYSPIKES, STRINGID_STEALTHROCKDMG
};

const u16 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_TERAVOLT] = STRINGID_TERAVOLTENTERS,
    [B_MSG_SWITCHIN_TURBOBLAZE] = STRINGID_TURBOBLAZEENTERS,
    [B_MSG_SWITCHIN_SLOWSTART] = STRINGID_SLOWSTARTENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_ASONE] = STRINGID_ASONEENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
};

const u16 gSandStormHailContinuesStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gSandStormHailEndStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED
};

const u16 gRainContinuesStringIds[] =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_DOWNPOUR_CONTINUES] = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEFALITTLE,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEFALITTLE,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gStockpileUsedStringIds[] =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gSwallowFailStringIds[] =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
    [B_MSG_STAYED_AWAKE_USING] = STRINGID_PKMNSTAYEDAWAKEUSING,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]     = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index read from sTWOTURN_STRINGID
const u16 gFirstTurnOfTwoStringIds[] =
{
    [B_MSG_TURN1_RAZOR_WIND]    = STRINGID_PKMNWHIPPEDWHIRLWIND,
    [B_MSG_TURN1_SOLAR_BEAM]    = STRINGID_PKMNTOOKSUNLIGHT,
    [B_MSG_TURN1_SKULL_BASH]    = STRINGID_PKMNLOWEREDHEAD,
    [B_MSG_TURN1_SKY_ATTACK]    = STRINGID_PKMNISGLOWING,
    [B_MSG_TURN1_FLY]           = STRINGID_PKMNFLEWHIGH,
    [B_MSG_TURN1_DIG]           = STRINGID_PKMNDUGHOLE,
    [B_MSG_TURN1_DIVE]          = STRINGID_PKMNHIDUNDERWATER,
    [B_MSG_TURN1_BOUNCE]        = STRINGID_PKMNSPRANGUP,
    [B_MSG_TURN1_PHANTOM_FORCE] = STRINGID_VANISHEDINSTANTLY,
    [B_MSG_TURN1_GEOMANCY]      = STRINGID_PKNMABSORBINGPOWER,
    [B_MSG_TURN1_FREEZE_SHOCK]  = STRINGID_CLOAKEDINAFREEZINGLIGHT,
};

// Index copied from move's index in gTrappingMoves
const u16 gWrappedStringIds[] =
{
    STRINGID_PKMNSQUEEZEDBYBIND,   // MOVE_BIND
    STRINGID_PKMNWRAPPEDBY,        // MOVE_WRAP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_FIRE_SPIN
    STRINGID_PKMNCLAMPED,          // MOVE_CLAMP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_WHIRLPOOL
    STRINGID_PKMNTRAPPEDBYSANDTOMB,// MOVE_SAND_TOMB
    STRINGID_INFESTATION,          // MOVE_INFESTATION
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_ITISRAINING,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_ITISRAINING,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTSTRONG,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 gTrainerItemCuredStatusStringIds[] =
{
    [AI_HEAL_CONFUSION] = STRINGID_PKMNSITEMSNAPPEDOUT,
    [AI_HEAL_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [AI_HEAL_FREEZE]    = STRINGID_PKMNSITEMDEFROSTEDIT,
    [AI_HEAL_BURN]      = STRINGID_PKMNSITEMHEALEDBURN,
    [AI_HEAL_POISON]    = STRINGID_PKMNSITEMCUREDPOISON,
    [AI_HEAL_SLEEP]     = STRINGID_PKMNSITEMWOKEIT
};

const u16 gBerryEffectStringIds[] =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gBRNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPRLZPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPSNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]  = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]  = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL] = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL] = STRINGID_PKMNBOXLANETTESPCFULL,
};

const u16 gTrappingMoves[] =
{
    MOVE_BIND, MOVE_WRAP, MOVE_FIRE_SPIN, MOVE_CLAMP, MOVE_WHIRLPOOL, MOVE_SAND_TOMB, MOVE_INFESTATION, 0xFFFF
};

const u16 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u16 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP
};

const u8 gText_PkmnIsEvolving[] = 
#ifdef CHINESE
_("What?\n{STR_VAR_1} is evolving!");   //TODO 汉化
#else
_("What?\n{STR_VAR_1} is evolving!");
#endif

const u8 gText_CongratsPkmnEvolved[] = 
#ifdef CHINESE
_("恭喜！你的 {STR_VAR_1}\n进化成为 {STR_VAR_2}了！{WAIT_SE}\p");   //TODO 汉化
#else
_("Congratulations! Your {STR_VAR_1}\nevolved into {STR_VAR_2}!{WAIT_SE}\p");
#endif

const u8 gText_PkmnStoppedEvolving[] = 
#ifdef CHINESE
_("嗯？ {STR_VAR_1}\n停止了进化！\p"); //TODO 汉化
#else
_("Huh? {STR_VAR_1}\nstopped evolving!\p");
#endif

const u8 gText_EllipsisQuestionMark[] = 
#ifdef CHINESE
_("……？\p"); //TODO 汉化
#else
_("……?\p");
#endif

const u8 gText_WhatWillPkmnDo[] = 
#ifdef CHINESE
_("{B_ACTIVE_NAME2}\n会做什么？");   //TODO 汉化
#else
_("What will\n{B_ACTIVE_NAME2} do?");
#endif

const u8 gText_WhatWillPkmnDo2[] = 
#ifdef CHINESE
_("What will\n{B_PLAYER_NAME} do?");    //TODO 汉化
#else
_("What will\n{B_PLAYER_NAME} do?");
#endif

const u8 gText_WhatWillWallyDo[] = 
#ifdef CHINESE
_("What will\nWALLY do?");  //TODO 汉化
#else
_("What will\nWALLY do?");
#endif

const u8 gText_LinkStandby[] = 
#ifdef CHINESE
_("{PAUSE 16}Link standby…");   //TODO 汉化
#else
_("{PAUSE 16}Link standby…");
#endif

const u8 gText_BattleMenu[] = 
#ifdef CHINESE
_("FIGHT{CLEAR_TO 56}BAG\nPOKéMON{CLEAR_TO 56}RUN");    //TODO 汉化
#else
_("FIGHT{CLEAR_TO 56}BAG\nPOKéMON{CLEAR_TO 56}RUN");
#endif

const u8 gText_SafariZoneMenu[] = 
#ifdef CHINESE
_("BALL{CLEAR_TO 56}{POKEBLOCK}\nGO NEAR{CLEAR_TO 56}RUN"); //TODO 汉化
#else
_("BALL{CLEAR_TO 56}{POKEBLOCK}\nGO NEAR{CLEAR_TO 56}RUN");
#endif

const u8 gText_MoveInterfacePP[] = 
#ifdef CHINESE
_("PP ");   //TODO 汉化
#else
_("PP ");
#endif

const u8 gText_MoveInterfaceType[] = 
#ifdef CHINESE
_("TYPE/"); //TODO 汉化
#else
_("TYPE/");
#endif

const u8 gText_MoveInterfacePpType[] = 
#ifdef CHINESE
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nTYPE/"); //TODO 汉化
#else
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nTYPE/");
#endif

const u8 gText_MoveInterfaceDynamicColors[] = 
#ifdef CHINESE
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");  //TODO 汉化
#else
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
#endif

const u8 gText_WhichMoveToForget4[] = 
#ifdef CHINESE
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Which move should\nbe forgotten?");  //TODO 汉化
#else
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Which move should\nbe forgotten?");
#endif

const u8 gText_BattleYesNoChoice[] = 
#ifdef CHINESE
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Yes\nNo");   //TODO 汉化
#else
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Yes\nNo");
#endif

const u8 gText_BattleSwitchWhich[] = 
#ifdef CHINESE
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Switch\nwhich?");    //TODO 汉化
#else
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Switch\nwhich?");
#endif

const u8 gText_BattleSwitchWhich2[] = 
#ifdef CHINESE
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");  //TODO 汉化
#else
_("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
#endif

const u8 gText_BattleSwitchWhich3[] = 
#ifdef CHINESE
_("{UP_ARROW}");    //TODO 汉化
#else
_("{UP_ARROW}");
#endif

const u8 gText_BattleSwitchWhich4[] = 
#ifdef CHINESE
_("{ESCAPE 4}");    //TODO 汉化
#else
_("{ESCAPE 4}");
#endif

const u8 gText_BattleSwitchWhich5[] = 
#ifdef CHINESE
_("-"); //TODO 汉化
#else
_("-");
#endif


// Unused
static const u8 * const sStatNamesTable2[] =
{
    gText_HP3, gText_SpAtk, gText_Attack,
    gText_SpDef, gText_Defense, gText_Speed
};

const u8 gText_SafariBalls[] = 
#ifdef CHINESE
_("{HIGHLIGHT DARK_GRAY}SAFARI BALLS"); //TODO 汉化
#else
_("{HIGHLIGHT DARK_GRAY}SAFARI BALLS");
#endif

const u8 gText_SafariBallLeft[] = 
#ifdef CHINESE
_("{HIGHLIGHT DARK_GRAY}Left: $" "{HIGHLIGHT DARK_GRAY}");  //TODO 汉化
#else
_("{HIGHLIGHT DARK_GRAY}Left: $" "{HIGHLIGHT DARK_GRAY}");
#endif

const u8 gText_Sleep[] = 
#ifdef CHINESE
_("sleep"); //TODO 汉化
#else
_("sleep");
#endif

const u8 gText_Poison[] = 
#ifdef CHINESE
_("poison");    //TODO 汉化
#else
_("poison");
#endif

const u8 gText_Burn[] = 
#ifdef CHINESE
_("burn");  //TODO 汉化
#else
_("burn");
#endif

const u8 gText_Paralysis[] = 
#ifdef CHINESE
_("paralysis"); //TODO 汉化
#else
_("paralysis");
#endif

const u8 gText_Ice[] = 
#ifdef CHINESE
_("ice");   //TODO 汉化
#else
_("ice");
#endif

const u8 gText_Confusion[] = 
#ifdef CHINESE
_("confusion"); //TODO 汉化
#else
_("confusion");
#endif

const u8 gText_Love[] = 
#ifdef CHINESE
_("love");  //TODO 汉化
#else
_("love");
#endif

const u8 gText_SpaceAndSpace[] = 
#ifdef CHINESE
_(" and "); //TODO 汉化
#else
_(" and ");
#endif

const u8 gText_CommaSpace[] = 
#ifdef CHINESE
_(", ");    //TODO 汉化
#else
_(", ");
#endif

const u8 gText_Space2[] = 
#ifdef CHINESE
_(" "); //TODO 汉化
#else
_(" ");
#endif

const u8 gText_LineBreak[] = 
#ifdef CHINESE
_("\l");    //TODO 汉化
#else
_("\l");
#endif

const u8 gText_NewLine[] = 
#ifdef CHINESE
_("\n");    //TODO 汉化
#else
_("\n");
#endif

const u8 gText_Are[] = 
#ifdef CHINESE
_("are");   //TODO 汉化
#else
_("are");
#endif

const u8 gText_Are2[] = 
#ifdef CHINESE
_("are");   //TODO 汉化
#else
_("are");
#endif

const u8 gText_BadEgg[] = 
#ifdef CHINESE
_("Bad EGG");   //TODO 汉化
#else
_("Bad EGG");
#endif

const u8 gText_BattleWallyName[] = 
#ifdef CHINESE
_("WALLY"); //TODO 汉化
#else
_("WALLY");
#endif

const u8 gText_Win[] = 
#ifdef CHINESE
_("{HIGHLIGHT TRANSPARENT}Win");    //TODO 汉化
#else
_("{HIGHLIGHT TRANSPARENT}Win");
#endif

const u8 gText_Loss[] = 
#ifdef CHINESE
_("{HIGHLIGHT TRANSPARENT}Loss");   //TODO 汉化
#else
_("{HIGHLIGHT TRANSPARENT}Loss");
#endif

const u8 gText_Draw[] = 
#ifdef CHINESE
_("{HIGHLIGHT TRANSPARENT}Draw");   //TODO 汉化
#else
_("{HIGHLIGHT TRANSPARENT}Draw");
#endif

static const u8 sText_SpaceIs[] = 
#ifdef CHINESE
_(" is");   //TODO 汉化
#else
_(" is");
#endif

static const u8 sText_ApostropheS[] = 
#ifdef CHINESE
_("'s");    //TODO 汉化
#else
_("'s");
#endif


// For displaying names of invalid moves
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][17] =
{
    [TYPE_NORMAL]   = 
    #ifdef CHINESE
    _("a NORMAL move"), //TODO 汉化
    #else
        _("a NORMAL move"),
        #endif
        
    [TYPE_FIGHTING] = 
    #ifdef CHINESE
    _("a FIGHTING move"),   //TODO 汉化
    #else
        _("a FIGHTING move"),
        #endif
        
    [TYPE_FLYING]   = 
    #ifdef CHINESE
    _("a FLYING move"), //TODO 汉化
    #else
        _("a FLYING move"),
        #endif
        
    [TYPE_POISON]   = 
    #ifdef CHINESE
    _("a POISON move"), //TODO 汉化
    #else
        _("a POISON move"),
        #endif
        
    [TYPE_GROUND]   = 
    #ifdef CHINESE
    _("a GROUND move"), //TODO 汉化
    #else
        _("a GROUND move"),
        #endif
        
    [TYPE_ROCK]     = 
    #ifdef CHINESE
    _("a ROCK move"),   //TODO 汉化
    #else
        _("a ROCK move"),
        #endif
        
    [TYPE_BUG]      = 
    #ifdef CHINESE
    _("a BUG move"),    //TODO 汉化
    #else
        _("a BUG move"),
        #endif
        
    [TYPE_GHOST]    = 
    #ifdef CHINESE
    _("a GHOST move"),  //TODO 汉化
    #else
        _("a GHOST move"),
        #endif
        
    [TYPE_STEEL]    = 
    #ifdef CHINESE
    _("a STEEL move"),  //TODO 汉化
    #else
        _("a STEEL move"),
        #endif
        
    [TYPE_MYSTERY]  = 
    #ifdef CHINESE
    _("a ??? move"),    //TODO 汉化
    #else
        _("a ??? move"),
        #endif
        
    [TYPE_FIRE]     = 
    #ifdef CHINESE
    _("a FIRE move"),   //TODO 汉化
    #else
        _("a FIRE move"),
        #endif
        
    [TYPE_WATER]    = 
    #ifdef CHINESE
    _("a WATER move"),  //TODO 汉化
    #else
        _("a WATER move"),
        #endif
        
    [TYPE_GRASS]    = 
    #ifdef CHINESE
    _("a GRASS move"),  //TODO 汉化
    #else
        _("a GRASS move"),
        #endif
        
    [TYPE_ELECTRIC] = 
    #ifdef CHINESE
    _("an ELECTRIC move"),  //TODO 汉化
    #else
        _("an ELECTRIC move"),
        #endif
        
    [TYPE_PSYCHIC]  = 
    #ifdef CHINESE
    _("a PSYCHIC move"),    //TODO 汉化
    #else
        _("a PSYCHIC move"),
        #endif
        
    [TYPE_ICE]      = 
    #ifdef CHINESE
    _("an ICE move"),   //TODO 汉化
    #else
        _("an ICE move"),
        #endif
        
    [TYPE_DRAGON]   = 
    #ifdef CHINESE
    _("a DRAGON move"), //TODO 汉化
    #else
        _("a DRAGON move"),
        #endif
        
    [TYPE_DARK]     = 
    #ifdef CHINESE
    _("a DARK move"),   //TODO 汉化
    #else
        _("a DARK move"),
        #endif
        
    [TYPE_FAIRY]    = 
    #ifdef CHINESE
    _("a FAIRY move"),  //TODO 汉化
    #else
        _("a FAIRY move"),
        #endif
        
};

const u8 gText_BattleTourney[] = 
#ifdef CHINESE
_("BATTLE TOURNEY");    //TODO 汉化
#else
_("BATTLE TOURNEY");
#endif

static const u8 sText_Round1[] = 
#ifdef CHINESE
_("Round 1");   //TODO 汉化
#else
_("Round 1");
#endif

static const u8 sText_Round2[] = 
#ifdef CHINESE
_("Round 2");   //TODO 汉化
#else
_("Round 2");
#endif

static const u8 sText_Semifinal[] = 
#ifdef CHINESE
_("Semifinal"); //TODO 汉化
#else
_("Semifinal");
#endif

static const u8 sText_Final[] = 
#ifdef CHINESE
_("Final"); //TODO 汉化
#else
_("Final");
#endif


const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = sText_Round1,
    [DOME_ROUND2]    = sText_Round2,
    [DOME_SEMIFINAL] = sText_Semifinal,
    [DOME_FINAL]     = sText_Final
};

const u8 gText_TheGreatNewHope[] = 
#ifdef CHINESE
_("The great new hope!\p"); //TODO 汉化
#else
_("The great new hope!\p");
#endif

const u8 gText_WillChampionshipDreamComeTrue[] = 
#ifdef CHINESE
_("Will the championship dream come true?!\p"); //TODO 汉化
#else
_("Will the championship dream come true?!\p");
#endif

const u8 gText_AFormerChampion[] = 
#ifdef CHINESE
_("A former CHAMPION!\p");  //TODO 汉化
#else
_("A former CHAMPION!\p");
#endif

const u8 gText_ThePreviousChampion[] = 
#ifdef CHINESE
_("The previous CHAMPION!\p");  //TODO 汉化
#else
_("The previous CHAMPION!\p");
#endif

const u8 gText_TheUnbeatenChampion[] = 
#ifdef CHINESE
_("The unbeaten CHAMPION!\p");  //TODO 汉化
#else
_("The unbeaten CHAMPION!\p");
#endif

const u8 gText_PlayerMon1Name[] = 
#ifdef CHINESE
_("{B_PLAYER_MON1_NAME}");  //TODO 汉化
#else
_("{B_PLAYER_MON1_NAME}");
#endif

const u8 gText_Vs[] = 
#ifdef CHINESE
_("VS");    //TODO 汉化
#else
_("VS");
#endif

const u8 gText_OpponentMon1Name[] = 
#ifdef CHINESE
_("{B_OPPONENT_MON1_NAME}");    //TODO 汉化
#else
_("{B_OPPONENT_MON1_NAME}");
#endif

const u8 gText_Mind[] = 
#ifdef CHINESE
_("Mind");  //TODO 汉化
#else
_("Mind");
#endif

const u8 gText_Skill[] = 
#ifdef CHINESE
_("Skill"); //TODO 汉化
#else
_("Skill");
#endif

const u8 gText_Body[] = 
#ifdef CHINESE
_("Body");  //TODO 汉化
#else
_("Body");
#endif

const u8 gText_Judgement[] = 
#ifdef CHINESE
_("{B_BUFF1}{CLEAR 13}Judgment{CLEAR 13}{B_BUFF2}");    //TODO 汉化
#else
_("{B_BUFF1}{CLEAR 13}Judgment{CLEAR 13}{B_BUFF2}");
#endif

static const u8 sText_TwoTrainersSentPkmn[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_OPPONENT_MON1_NAME}!\p{B_TRAINER2_CLASS} {B_TRAINER2_NAME} sent\nout {B_OPPONENT_MON2_NAME}!");    //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} sent\nout {B_OPPONENT_MON1_NAME}!\p{B_TRAINER2_CLASS} {B_TRAINER2_NAME} sent\nout {B_OPPONENT_MON2_NAME}!");
#endif

static const u8 sText_Trainer2SentOutPkmn[] = 
#ifdef CHINESE
_("{B_TRAINER2_CLASS} {B_TRAINER2_NAME} sent\nout {B_BUFF1}!"); //TODO 汉化
#else
_("{B_TRAINER2_CLASS} {B_TRAINER2_NAME} sent\nout {B_BUFF1}!");
#endif

static const u8 sText_TwoTrainersWantToBattle[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} and\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lwant to battle!\p"); //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} and\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lwant to battle!\p");
#endif

static const u8 sText_InGamePartnerSentOutZGoN[] = 
#ifdef CHINESE
_("{B_PARTNER_CLASS} {B_PARTNER_NAME} sent\nout {B_PLAYER_MON2_NAME}!\lGo, {B_PLAYER_MON1_NAME}!"); //TODO 汉化
#else
_("{B_PARTNER_CLASS} {B_PARTNER_NAME} sent\nout {B_PLAYER_MON2_NAME}!\lGo, {B_PLAYER_MON1_NAME}!");
#endif

static const u8 sText_TwoInGameTrainersDefeated[] = 
#ifdef CHINESE
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} and\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lwere defeated!\p");  //TODO 汉化
#else
_("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} and\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lwere defeated!\p");
#endif

static const u8 sText_Trainer2LoseText[] = 
#ifdef CHINESE
_("{B_TRAINER2_LOSE_TEXT}");    //TODO 汉化
#else
_("{B_TRAINER2_LOSE_TEXT}");
#endif

static const u8 sText_PkmnIncapableOfPower[] = 
#ifdef CHINESE
_("{B_ATK_NAME_WITH_PREFIX} appears incapable\nof using its power!");   //TODO 汉化
#else
_("{B_ATK_NAME_WITH_PREFIX} appears incapable\nof using its power!");
#endif

static const u8 sText_GlintAppearsInEye[] = 
#ifdef CHINESE
_("A glint appears in\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s eyes!");   //TODO 汉化
#else
_("A glint appears in\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s eyes!");
#endif

static const u8 sText_PkmnGettingIntoPosition[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is getting into\nposition!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is getting into\nposition!");
#endif

static const u8 sText_PkmnBeganGrowlingDeeply[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} began growling deeply!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} began growling deeply!");
#endif

static const u8 sText_PkmnEagerForMore[] = 
#ifdef CHINESE
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is eager for more!");    //TODO 汉化
#else
_("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is eager for more!");
#endif


const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

static const u8 sText_RefIfNothingIsDecided[] = 
#ifdef CHINESE
_("REFEREE: If nothing is decided in\n3 turns, we will go to judging!");    //TODO 汉化
#else
_("REFEREE: If nothing is decided in\n3 turns, we will go to judging!");
#endif

static const u8 sText_RefThatsIt[] = 
#ifdef CHINESE
_("REFEREE: That's it! We will now go to\njudging to determine the winner!");   //TODO 汉化
#else
_("REFEREE: That's it! We will now go to\njudging to determine the winner!");
#endif

static const u8 sText_RefJudgeMind[] = 
#ifdef CHINESE
_("REFEREE: Judging category 1, Mind!\nThe POKéMON showing the most guts!\p");  //TODO 汉化
#else
_("REFEREE: Judging category 1, Mind!\nThe POKéMON showing the most guts!\p");
#endif

static const u8 sText_RefJudgeSkill[] = 
#ifdef CHINESE
_("REFEREE: Judging category 2, Skill!\nThe POKéMON using moves the best!\p");  //TODO 汉化
#else
_("REFEREE: Judging category 2, Skill!\nThe POKéMON using moves the best!\p");
#endif

static const u8 sText_RefJudgeBody[] = 
#ifdef CHINESE
_("REFEREE: Judging category 3, Body!\nThe POKéMON with the most vitality!\p"); //TODO 汉化
#else
_("REFEREE: Judging category 3, Body!\nThe POKéMON with the most vitality!\p");
#endif

static const u8 sText_RefPlayerWon[] = 
#ifdef CHINESE
_("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}!\nThe winner is {B_PLAYER_NAME}'s {B_PLAYER_MON1_NAME}!\p");   //TODO 汉化
#else
_("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}!\nThe winner is {B_PLAYER_NAME}'s {B_PLAYER_MON1_NAME}!\p");
#endif

static const u8 sText_RefOpponentWon[] = 
#ifdef CHINESE
_("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}!\nThe winner is {B_TRAINER1_NAME}'s {B_OPPONENT_MON1_NAME}!\p");   //TODO 汉化
#else
_("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}!\nThe winner is {B_TRAINER1_NAME}'s {B_OPPONENT_MON1_NAME}!\p");
#endif

static const u8 sText_RefDraw[] = 
#ifdef CHINESE
_("REFEREE: Judgment: 3 to 3!\nWe have a draw!\p"); //TODO 汉化
#else
_("REFEREE: Judgment: 3 to 3!\nWe have a draw!\p");
#endif

static const u8 sText_DefeatedOpponentByReferee[] = 
#ifdef CHINESE
_("{B_PLAYER_MON1_NAME} defeated the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE's decision!");   //TODO 汉化
#else
_("{B_PLAYER_MON1_NAME} defeated the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE's decision!");
#endif

static const u8 sText_LostToOpponentByReferee[] = 
#ifdef CHINESE
_("{B_PLAYER_MON1_NAME} lost to the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE's decision!");    //TODO 汉化
#else
_("{B_PLAYER_MON1_NAME} lost to the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE's decision!");
#endif

static const u8 sText_TiedOpponentByReferee[] = 
#ifdef CHINESE
_("{B_PLAYER_MON1_NAME} tied the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE's decision!");   //TODO 汉化
#else
_("{B_PLAYER_MON1_NAME} tied the opponent\n{B_OPPONENT_MON1_NAME} in a REFEREE's decision!");
#endif

static const u8 sText_RefCommenceBattle[] = 
#ifdef CHINESE
_("REFEREE: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nCommence battling!");  //TODO 汉化
#else
_("REFEREE: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nCommence battling!");
#endif


const u8 * const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = sText_RefIfNothingIsDecided,
    [B_MSG_REF_THATS_IT]           = sText_RefThatsIt,
    [B_MSG_REF_JUDGE_MIND]         = sText_RefJudgeMind,
    [B_MSG_REF_JUDGE_SKILL]        = sText_RefJudgeSkill,
    [B_MSG_REF_JUDGE_BODY]         = sText_RefJudgeBody,
    [B_MSG_REF_PLAYER_WON]         = sText_RefPlayerWon,
    [B_MSG_REF_OPPONENT_WON]       = sText_RefOpponentWon,
    [B_MSG_REF_DRAW]               = sText_RefDraw,
    [B_MSG_REF_COMMENCE_BATTLE]    = sText_RefCommenceBattle,
};

static const u8 sText_QuestionForfeitMatch[] = 
#ifdef CHINESE
_("Would you like to forfeit the match\nand quit now?");    //TODO 汉化
#else
_("Would you like to forfeit the match\nand quit now?");
#endif

static const u8 sText_ForfeitedMatch[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME} forfeited the match!");  //TODO 汉化
#else
_("{B_PLAYER_NAME} forfeited the match!");
#endif

static const u8 sText_Trainer1WinText[] = 
#ifdef CHINESE
_("{B_TRAINER1_WIN_TEXT}"); //TODO 汉化
#else
_("{B_TRAINER1_WIN_TEXT}");
#endif

static const u8 sText_Trainer2WinText[] = 
#ifdef CHINESE
_("{B_TRAINER2_WIN_TEXT}"); //TODO 汉化
#else
_("{B_TRAINER2_WIN_TEXT}");
#endif

static const u8 sText_Trainer1Fled[] = _( "{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS} {B_TRAINER1_NAME} fled!");
static const u8 sText_PlayerLostAgainstTrainer1[] = 
#ifdef CHINESE
_("Player lost against\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");    //TODO 汉化
#else
_("Player lost against\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
#endif

static const u8 sText_PlayerBattledToDrawTrainer1[] = 
#ifdef CHINESE
_("Player battled to a draw against\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");   //TODO 汉化
#else
_("Player battled to a draw against\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
#endif

const u8 gText_RecordBattleToPass[] = 
#ifdef CHINESE
_("Would you like to record your battle\non your FRONTIER PASS?");  //TODO 汉化
#else
_("Would you like to record your battle\non your FRONTIER PASS?");
#endif

const u8 gText_BattleRecordedOnPass[] = 
#ifdef CHINESE
_("{B_PLAYER_NAME}'s battle result was recorded\non the FRONTIER PASS.");   //TODO 汉化
#else
_("{B_PLAYER_NAME}'s battle result was recorded\non the FRONTIER PASS.");
#endif

static const u8 sText_LinkTrainerWantsToBattlePause[] = 
#ifdef CHINESE
_("{B_LINK_OPPONENT1_NAME}\nwants to battle!{PAUSE 49}");   //TODO 汉化
#else
_("{B_LINK_OPPONENT1_NAME}\nwants to battle!{PAUSE 49}");
#endif

static const u8 sText_TwoLinkTrainersWantToBattlePause[] = 
#ifdef CHINESE
_("{B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}\nwant to battle!{PAUSE 49}");    //TODO 汉化
#else
_("{B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}\nwant to battle!{PAUSE 49}");
#endif

static const u8 sText_Your1[] = 
#ifdef CHINESE
_("Your");  //TODO 汉化
#else
_("Your");
#endif

static const u8 sText_Opposing1[] = 
#ifdef CHINESE
_("The opposing");  //TODO 汉化
#else
_("The opposing");
#endif

static const u8 sText_Your2[] = 
#ifdef CHINESE
_("your");  //TODO 汉化
#else
_("your");
#endif

static const u8 sText_Opposing2[] = 
#ifdef CHINESE
_("the opposing");  //TODO 汉化
#else
_("the opposing");
#endif


// This is four lists of moves which use a different attack string in Japanese
// to the default. See the documentation for ChooseTypeOfMoveUsedString for more detail.
static const u16 sGrammarMoveUsedTable[] =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, 0,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, 0,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, 0,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VISE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, 0
};

static const u8 sDummyWeirdStatusString[] = {EOS, EOS, EOS, EOS, EOS, EOS, EOS, EOS, 0, 0};

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
// The corresponding WindowTemplate is gStandardBattleWindowTemplates[] within src/battle_bg.c
    { // 0 Standard battle message
        .fillValue = PIXEL_FILL(0xF),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    { // 1 "What will (pokemon) do?"
        .fillValue = PIXEL_FILL(0xF),
        .fontId = 1,
        .x = 1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    { // 2 "Fight/Pokemon/Bag/Run"
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 3 Top left move
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 4 Top right move
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 5 Bottom left move
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 6 Bottom right move
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 7 "PP"
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    { // 8
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 9 PP remaining
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 2,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    { // 10 "type"
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 11 "switch which?"
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 12 "gText_BattleYesNoChoice"
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 13
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 14
        .fillValue = PIXEL_FILL(0),
        .fontId = 1,
        .x = 32,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 0,
        .shadowColor = 2,
    },
    { // 15
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 16
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 17
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 18
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 19
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 20
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 21
        .fillValue = PIXEL_FILL(0),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 0,
        .shadowColor = 6,
    },
    { // 22
        .fillValue = PIXEL_FILL(0),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 0,
        .shadowColor = 6,
    },
    { // 23
        .fillValue = PIXEL_FILL(0x0),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 0,
        .shadowColor = 6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    { // 0
        .fillValue = PIXEL_FILL(0xF),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    { // 1
        .fillValue = PIXEL_FILL(0xF),
        .fontId = 1,
        .x = 1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    { // 2
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 3
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 4
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 5
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 6
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 7
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    { // 8
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 9
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 2,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    { // 10
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 11
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 12
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 13
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 14
        .fillValue = PIXEL_FILL(0),
        .fontId = 1,
        .x = 32,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 0,
        .shadowColor = 2,
    },
    { // 15
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 16
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 17
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 18
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 19
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 20
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 21
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 1,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    { // 22
        .fillValue = PIXEL_FILL(0x1),
        .fontId = 1,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    sTextOnWindowsInfo_Normal, sTextOnWindowsInfo_Arena
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

// code
void BufferStringBattle(u16 stringID)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData*)(&gBattleResources->bufferA[gActiveBattler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->field_52 = gBattleMsgDataPtr->unk1605E;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    else
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else
                {
                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1WantsToBattle;
                else if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) // interesting, looks like they had something planned for wild double battles
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            if (gTrainerBattleOpponent_A == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (GetBattlerSide(gBattleScripting.battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // pokemon used a move msg
        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
            StringCopy(gBattleTextBuff3, sATypeMove_Table[*(&gBattleStruct->stringMoveType)]);
        else
            StringCopy(gBattleTextBuff3, gMoveNames[gBattleMsgDataPtr->currentMove]);

        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default: // load a string from the table
        if (stringID >= BATTLESTRINGS_COUNT + BATTLESTRINGS_ID_ADDER)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID - BATTLESTRINGS_ID_ADDER];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8* src)
{
    BattleStringExpandPlaceholders(src, gDisplayedStringBattle);
}

static const u8* TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8* statusPtr;

    memcpy(status, sDummyWeirdStatusString, 8);

    statusPtr = status;
    for (i = 0; i < 8; i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32*)(&status[0]);
    chars2 = *(u32*)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32*)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32*)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

static void GetBattlerNick(u32 battlerId, u8 *dst)
{
    struct Pokemon *mon, *illusionMon;

    if (GET_BATTLER_SIDE(battlerId) == B_SIDE_PLAYER)
        mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];
    else
        mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];

    illusionMon = GetIllusionMonPtr(battlerId);
    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGetEnd10(dst);
}

#define HANDLE_NICKNAME_STRING_CASE(battlerId)                          \
    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)                     \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battlerId, text);                                    \
    toCpy = text;

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId, u8 *text, u8 multiplayerId, u8 battlerId)
{
    const u8 *toCpy;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u32 i;
        for (i = 0; i < ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
            text[i] = gBattleResources->secretBase->trainerName[i];
        text[i] = EOS;
        ConvertInternationalString(text, gBattleResources->secretBase->language);
        toCpy = text;
    }
    else if (trainerId == TRAINER_UNION_ROOM)
    {
        toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_LINK_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battlerId)].name;
        else
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battlerId) & BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        GetFrontierTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        GetTrainerHillTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        GetEreaderTrainerName(text);
        toCpy = text;
    }
    else
    {
        toCpy = gTrainers[trainerId].trainerName;
    }

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 *text, u8 multiplayerId, u8 battlerId)
{
    const u8 *toCpy;

    switch (GetBattlerPosition(battlerId))
    {
    case B_POSITION_OPPONENT_LEFT:
        toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, battlerId);
        break;
    case B_POSITION_OPPONENT_RIGHT:
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT)
            toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_B, text, multiplayerId, battlerId);
        else
            toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, battlerId);
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetPlayerName(u8 *text, u8 battlerId)
{
    const u8 *toCpy;

    switch (GetBattlerPosition(battlerId))
    {
    case B_POSITION_PLAYER_LEFT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            toCpy = gLinkPlayers[0].name;
        else
            toCpy = gSaveBlock2Ptr->playerName;
        break;
    case B_POSITION_PLAYER_RIGHT:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_MULTI))
        {
            toCpy = gLinkPlayers[2].name;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            GetFrontierTrainerName(text, gPartnerTrainerId);
            toCpy = text;
        }
        else
        {
            toCpy = gSaveBlock2Ptr->playerName;
        }
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 *text, u8 multiplayerId, u8 battlerId)
{
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        return BattleStringGetPlayerName(text, battlerId);
    else
        return BattleStringGetOpponentName(text, multiplayerId, battlerId);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
        toCpy = gTrainerClassNames[GetSecretBaseTrainerClass()];
    else if (trainerId == TRAINER_UNION_ROOM)
        toCpy = gTrainerClassNames[GetUnionRoomTrainerClass()];
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        toCpy = gTrainerClassNames[GetFrontierBrainTrainerClass()];
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        toCpy = gTrainerClassNames[GetFrontierOpponentClass(trainerId)];
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(trainerId)];
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
        toCpy = gTrainerClassNames[GetEreaderTrainerClassId()];
    else
        toCpy = gTrainerClassNames[gTrainers[trainerId].trainerClass];

    return toCpy;
}

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u8 text[30];
    u8 multiplayerId;
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    while (*src != EOS)
    {
        toCpy = NULL;
        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                    toCpy = gBattleTextBuff2;
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                    toCpy = gBattleTextBuff3;
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 1, text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 2, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 3, text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // Unused, to change into sth else.
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(BATTLE_PARTNER(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_ACTIVE_NAME: // active name
                GetBattlerNick(gActiveBattler, text);
                toCpy = text;
                break;
            case B_TXT_ACTIVE_NAME2: // active battlerId name with prefix, no illusion
                if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_NICKNAME, text);
                else
                    GetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_NICKNAME, text);
                StringGetEnd10(text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_ACTIVE_NAME_WITH_PREFIX: // active battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gActiveBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->currentMove];
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->originallyUsedMove];
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                                toCpy = sText_EnigmaBerry;
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilityNames[gLastUsedAbility];
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerAttacker]];
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerTarget]];
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattleScripting.battler]];
                break;
            case B_TXT_EFF_ABILITY: // effect battlerId ability
                toCpy = gAbilityNames[sBattlerAbilities[gEffectBattler]];
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_26: // ?
                if (GetBattlerSide(gBattleScripting.battler) != B_SIDE_PLAYER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = sText_FoePkmnPrefix;
                    else
                        toCpy = sText_WildPkmnPrefix;
                    while (*toCpy != EOS)
                    {
                        dst[dstID] = *toCpy;
                        dstID++;
                        toCpy++;
                    }
                    GetMonData(&gEnemyParty[gBattleStruct->field_52], MON_DATA_NICKNAME, text);
                }
                else
                {
                    GetMonData(&gPlayerParty[gBattleStruct->field_52], MON_DATA_NICKNAME, text);
                }
                StringGetEnd10(text);
                toCpy = text;
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_B);
                break;
            case B_TXT_TRAINER2_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_B, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(text, multiplayerId, gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (GetBattlerPosition(gBattlerAttacker))
                {
                case B_POSITION_PLAYER_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                        toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                    break;
                case B_POSITION_OPPONENT_LEFT:
                    toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                    break;
                case B_POSITION_OPPONENT_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                        toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_B);
                    else
                        toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                    break;
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            }

            if (toCpy != NULL)
            {
                while (*toCpy != EOS)
                {
                    dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

static void IllusionNickHack(u32 battlerId, u32 partyId, u8 *dst)
{
    s32 id, i;
    // we know it's gEnemyParty
    struct Pokemon *mon = &gEnemyParty[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(battlerId)))
            partnerMon = &gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(battlerId)]];
        else
            partnerMon = mon;

        // Find last alive non-egg pokemon.
        for (i = PARTY_SIZE - 1; i >= 0; i--)
        {
            id = i;
            if (GetMonData(&gEnemyParty[id], MON_DATA_SANITY_HAS_SPECIES)
                && GetMonData(&gEnemyParty[id], MON_DATA_HP)
                && &gEnemyParty[id] != mon
                && &gEnemyParty[id] != partnerMon)
            {
                GetMonData(&gEnemyParty[id], MON_DATA_NICKNAME, dst);
                return;
            }
        }
    }

    GetMonData(mon, MON_DATA_NICKNAME, dst);
}

static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 text[12];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword - BATTLESTRINGS_ID_ADDER]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, gMoveNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypeNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, text);
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, text);
            }
            StringGetEnd10(text);
            StringAppend(dst, text);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            GetSpeciesName(dst, T1_READ_16(&src[srcID + 1]));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGetEnd10(dst);
            }
            else
            {
                if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                else
                    GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGetEnd10(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilityNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

// Loads one of two text strings into the provided buffer. This is functionally
// unused, since the value loaded into the buffer is not read; it loaded one of
// two particles (either "?" or "?") which works in tandem with ChooseTypeOfMoveUsedString
// below to effect changes in the meaning of the line.
static void ChooseMoveUsedParticle(u8* textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

// Appends "!" to the text buffer `dst`. In the original Japanese this looked
// into the table of moves at sGrammarMoveUsedTable and varied the line accordingly.
//
// sText_ExclamationMark was a plain "!", used for any attack not on the list.
// It resulted in the translation "<NAME>'s <ATTACK>!".
//
// sText_ExclamationMark2 was "? ????!". This resulted in the translation
// "<NAME> used <ATTACK>!", which was used for all attacks in English.
//
// sText_ExclamationMark3 was "??!". This was used for those moves whose
// names were verbs, such as Recover, and resulted in translations like "<NAME>
// recovered itself!".
//
// sText_ExclamationMark4 was "? ??!" This resulted in a translation of
// "<NAME> did an <ATTACK>!".
//
// sText_ExclamationMark5 was " ????!" This resulted in a translation of
// "<NAME>'s <ATTACK> attack!".
static void ChooseTypeOfMoveUsedString(u8* dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & 0x80)
    {
        windowId &= ~(0x80);
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == 0x16)
        gTextFlags.useAlternateDownArrow = 0;
    else
        gTextFlags.useAlternateDownArrow = 1;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED))
        gTextFlags.autoScroll = 1;
    else
        gTextFlags.autoScroll = 0;

    if (windowId == 0 || windowId == 0x16)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, 3);
    }
}

void SetPpNumbersPaletteInMoveSelection(void)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct*)(&gBattleResources->bufferA[gActiveBattler][4]);
    const u16 *palPtr = gUnknown_08D85620;
    u8 var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[gActiveBattler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[gActiveBattler]]);

    gPlttBufferUnfaded[92] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[91] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[92], &gPlttBufferFaded[92], sizeof(u16));
    CpuCopy16(&gPlttBufferUnfaded[91], &gPlttBufferFaded[91], sizeof(u16));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}

struct TrainerSlide
{
    u16 trainerId;
    const u8 *msgLastSwitchIn;
    const u8 *msgLastLowHp;
    const u8 *msgFirstDown;
};

static const struct TrainerSlide sTrainerSlides[] =
{
    {0x291, sText_AarghAlmostHadIt, sText_BoxIsFull, sText_123Poof},
};

static u32 GetEnemyMonCount(bool32 onlyAlive)
{
    u32 i, count = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES2, NULL);
        if (species != SPECIES_NONE
            && species != SPECIES_EGG
            && (!onlyAlive || GetMonData(&gEnemyParty[i], MON_DATA_HP, NULL)))
            count++;
    }

    return count;
}

static bool32 IsBattlerHpLow(u32 battler)
{
    if ((gBattleMons[battler].hp * 100) / gBattleMons[battler].maxHP < 25)
        return TRUE;
    else
        return FALSE;
}

bool32 ShouldDoTrainerSlide(u32 battlerId, u32 trainerId, u32 which)
{
    s32 i;

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || GetBattlerSide(battlerId) != B_SIDE_OPPONENT)
        return FALSE;

    for (i = 0; i < ARRAY_COUNT(sTrainerSlides); i++)
    {
        if (trainerId == sTrainerSlides[i].trainerId)
        {
            gBattleScripting.battler = battlerId;
            switch (which)
            {
            case TRAINER_SLIDE_LAST_SWITCHIN:
                if (sTrainerSlides[i].msgLastSwitchIn != NULL && GetEnemyMonCount(TRUE) == 1)
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastSwitchIn;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_LAST_LOW_HP:
                if (sTrainerSlides[i].msgLastLowHp != NULL
                    && GetEnemyMonCount(TRUE) == 1
                    && IsBattlerHpLow(battlerId)
                    && !gBattleStruct->trainerSlideLowHpMsgDone)
                {
                    gBattleStruct->trainerSlideLowHpMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastLowHp;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_DOWN:
                if (sTrainerSlides[i].msgFirstDown != NULL && GetEnemyMonCount(TRUE) == GetEnemyMonCount(FALSE) - 1)
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstDown;
                    return TRUE;
                }
                break;
            }
            break;
        }
    }

    return FALSE;
}
