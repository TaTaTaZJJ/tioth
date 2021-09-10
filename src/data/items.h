#include "config.h"

const struct Item gItems[] =
    {
        [ITEM_NONE] =
            {
                .name = _("????????"),
                .itemId = ITEM_NONE,
                .price = 0,
                .description = sDummyDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        // Pokeballs

        [ITEM_MASTER_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Master Ball"), //TODO 汉化
#else
                    _("Master Ball"),
#endif
                .itemId = ITEM_MASTER_BALL,
                .price = 0,
                .description = sMasterBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_MASTER_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_MASTER_BALL - FIRST_BALL,
            },

        [ITEM_ULTRA_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Ultra Ball"), //TODO 汉化
#else
                    _("Ultra Ball"),
#endif
                .itemId = ITEM_ULTRA_BALL,
                .price = 800,
                .description = sUltraBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_ULTRA_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_ULTRA_BALL - FIRST_BALL,
            },

        [ITEM_GREAT_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Great Ball"), //TODO 汉化
#else
                    _("Great Ball"),
#endif
                .itemId = ITEM_GREAT_BALL,
                .price = 600,
                .description = sGreatBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_GREAT_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_GREAT_BALL - FIRST_BALL,
            },

        [ITEM_POKE_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Poké Ball"), //TODO 汉化
#else
                    _("Poké Ball"),
#endif
                .itemId = ITEM_POKE_BALL,
                .price = 200,
                .description = sPokeBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_POKE_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_POKE_BALL - FIRST_BALL,
            },

        [ITEM_SAFARI_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Safari Ball"), //TODO 汉化
#else
                    _("Safari Ball"),
#endif
                .itemId = ITEM_SAFARI_BALL,
                .price = 0,
                .description = sSafariBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_SAFARI_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_SAFARI_BALL - FIRST_BALL,
            },

        [ITEM_NET_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Net Ball"), //TODO 汉化
#else
                    _("Net Ball"),
#endif
                .itemId = ITEM_NET_BALL,
                .price = 1000,
                .description = sNetBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_NET_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_NET_BALL - FIRST_BALL,
            },

        [ITEM_DIVE_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Dive Ball"), //TODO 汉化
#else
                    _("Dive Ball"),
#endif
                .itemId = ITEM_DIVE_BALL,
                .price = 1000,
                .description = sDiveBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_DIVE_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_DIVE_BALL - FIRST_BALL,
            },

        [ITEM_NEST_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Nest Ball"), //TODO 汉化
#else
                    _("Nest Ball"),
#endif
                .itemId = ITEM_NEST_BALL,
                .price = 1000,
                .description = sNestBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_NEST_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_NEST_BALL - FIRST_BALL,
            },

        [ITEM_REPEAT_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Repeat Ball"), //TODO 汉化
#else
                    _("Repeat Ball"),
#endif
                .itemId = ITEM_REPEAT_BALL,
                .price = 1000,
                .description = sRepeatBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_REPEAT_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_REPEAT_BALL - FIRST_BALL,
            },

        [ITEM_TIMER_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Timer Ball"), //TODO 汉化
#else
                    _("Timer Ball"),
#endif
                .itemId = ITEM_TIMER_BALL,
                .price = 1000,
                .description = sTimerBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_TIMER_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_TIMER_BALL - FIRST_BALL,
            },

        [ITEM_LUXURY_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Luxury Ball"), //TODO 汉化
#else
                    _("Luxury Ball"),
#endif
                .itemId = ITEM_LUXURY_BALL,
                .price = 1000,
                .description = sLuxuryBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_LUXURY_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_LUXURY_BALL - FIRST_BALL,
            },

        [ITEM_PREMIER_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Premier Ball"), //TODO 汉化
#else
                    _("Premier Ball"),
#endif
                .itemId = ITEM_PREMIER_BALL,
                .price = 20,
                .description = sPremierBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_PREMIER_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_PREMIER_BALL - FIRST_BALL,
            },

        [ITEM_LEVEL_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Level Ball"), //TODO 汉化
#else
                    _("Level Ball"),
#endif
                .itemId = ITEM_LEVEL_BALL,
                .price = 0,
                .description = sLevelBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_LEVEL_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_LEVEL_BALL - FIRST_BALL,
            },

        [ITEM_LURE_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Lure Ball"), //TODO 汉化
#else
                    _("Lure Ball"),
#endif
                .itemId = ITEM_LURE_BALL,
                .price = 0,
                .description = sLureBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_LURE_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_LURE_BALL - FIRST_BALL,
            },

        [ITEM_MOON_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Moon Ball"), //TODO 汉化
#else
                    _("Moon Ball"),
#endif
                .itemId = ITEM_MOON_BALL,
                .price = 0,
                .description = sMoonBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_MOON_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_MOON_BALL - FIRST_BALL,
            },

        [ITEM_FRIEND_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Friend Ball"), //TODO 汉化
#else
                    _("Friend Ball"),
#endif
                .itemId = ITEM_FRIEND_BALL,
                .price = 0,
                .description = sFriendBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_FRIEND_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_FRIEND_BALL - FIRST_BALL,
            },

        [ITEM_LOVE_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Love Ball"), //TODO 汉化
#else
                    _("Love Ball"),
#endif
                .itemId = ITEM_LOVE_BALL,
                .price = 0,
                .description = sLoveBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_LOVE_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_LOVE_BALL - FIRST_BALL,
            },

        [ITEM_HEAVY_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Heavy Ball"), //TODO 汉化
#else
                    _("Heavy Ball"),
#endif
                .itemId = ITEM_HEAVY_BALL,
                .price = 0,
                .description = sHeavyBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_HEAVY_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_HEAVY_BALL - FIRST_BALL,
            },

        [ITEM_FAST_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Fast Ball"), //TODO 汉化
#else
                    _("Fast Ball"),
#endif
                .itemId = ITEM_FAST_BALL,
                .price = 0,
                .description = sFastBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_FAST_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_FAST_BALL - FIRST_BALL,
            },

        [ITEM_HEAL_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Heal Ball"), //TODO 汉化
#else
                    _("Heal Ball"),
#endif
                .itemId = ITEM_HEAL_BALL,
                .price = 300,
                .description = sHealBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_HEAL_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_HEAL_BALL - FIRST_BALL,
            },

        [ITEM_QUICK_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Quick Ball"), //TODO 汉化
#else
                    _("Quick Ball"),
#endif
                .itemId = ITEM_QUICK_BALL,
                .price = 1000,
                .description = sQuickBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_QUICK_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_QUICK_BALL - FIRST_BALL,
            },

        [ITEM_DUSK_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Dusk Ball"), //TODO 汉化
#else
                    _("Dusk Ball"),
#endif
                .itemId = ITEM_DUSK_BALL,
                .price = 1000,
                .description = sDuskBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_DUSK_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_DUSK_BALL - FIRST_BALL,
            },

        [ITEM_CHERISH_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Cherish Ball"), //TODO 汉化
#else
                    _("Cherish Ball"),
#endif
                .itemId = ITEM_CHERISH_BALL,
                .price = 0,
                .description = sCherishBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_CHERISH_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_CHERISH_BALL - FIRST_BALL,
            },

        [ITEM_SPORT_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Sport Ball"), //TODO 汉化
#else
                    _("Sport Ball"),
#endif
                .itemId = ITEM_SPORT_BALL,
                .price = 0,
                .description = sSportBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_SPORT_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_SPORT_BALL - FIRST_BALL,
            },

        [ITEM_PARK_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Park Ball"), //TODO 汉化
#else
                    _("Park Ball"),
#endif
                .itemId = ITEM_PARK_BALL,
                .price = 0,
                .description = sParkBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_PARK_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_PARK_BALL - FIRST_BALL,
            },

        [ITEM_DREAM_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Dream Ball"), //TODO 汉化
#else
                    _("Dream Ball"),
#endif
                .itemId = ITEM_DREAM_BALL,
                .price = 0,
                .description = sDreamBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_DREAM_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_DREAM_BALL - FIRST_BALL,
            },

        [ITEM_BEAST_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Beast Ball"), //TODO 汉化
#else
                    _("Beast Ball"),
#endif
                .itemId = ITEM_BEAST_BALL,
                .price = 0,
                .description = sBeastBallDesc,
                .pocket = POCKET_POKE_BALLS,
                .type = ITEM_BEAST_BALL - FIRST_BALL,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_PokeBall,
                .secondaryId = ITEM_BEAST_BALL - FIRST_BALL,
            },

        // Medicine

        [ITEM_POTION] =
            {
                .name =
#ifdef CHINESE
                    _("Potion"), //TODO 汉化
#else
                    _("Potion"),
#endif
                .itemId = ITEM_POTION,
                .price = 200,
                .holdEffectParam = 20,
                .description = sPotionDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_ANTIDOTE] =
            {
                .name =
#ifdef CHINESE
                    _("Antidote"), //TODO 汉化
#else
                    _("Antidote"),
#endif
                .itemId = ITEM_ANTIDOTE,
                .price = 200,
                .description = sAntidoteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_BURN_HEAL] =
            {
                .name =
#ifdef CHINESE
                    _("Burn Heal"), //TODO 汉化
#else
                    _("Burn Heal"),
#endif
                .itemId = ITEM_BURN_HEAL,
                .price = 300,
                .description = sBurnHealDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_ICE_HEAL] =
            {
                .name =
#ifdef CHINESE
                    _("Ice Heal"), //TODO 汉化
#else
                    _("Ice Heal"),
#endif
                .itemId = ITEM_ICE_HEAL,
                .price = 100,
                .description = sIceHealDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_AWAKENING] =
            {
                .name =
#ifdef CHINESE
                    _("Awakening"), //TODO 汉化
#else
                    _("Awakening"),
#endif
                .itemId = ITEM_AWAKENING,
                .price = 100,
                .description = sAwakeningDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_PARALYZE_HEAL] =
            {
                .name =
#ifdef CHINESE
                    _("Paralyze Heal"), //TODO 汉化
#else
                    _("Paralyze Heal"),
#endif
                .itemId = ITEM_PARALYZE_HEAL,
                .price = 300,
                .description = sParalyzeHealDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_FULL_RESTORE] =
            {
                .name =
#ifdef CHINESE
                    _("Full Restore"), //TODO 汉化
#else
                    _("Full Restore"),
#endif
                .itemId = ITEM_FULL_RESTORE,
                .price = 3000,
                .holdEffectParam = 255,
                .description = sFullRestoreDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_MAX_POTION] =
            {
                .name =
#ifdef CHINESE
                    _("Max Potion"), //TODO 汉化
#else
                    _("Max Potion"),
#endif
                .itemId = ITEM_MAX_POTION,
                .price = 2500,
                .holdEffectParam = 255,
                .description = sMaxPotionDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_HYPER_POTION] =
            {
                .name =
#ifdef CHINESE
                    _("Hyper Potion"), //TODO 汉化
#else
                    _("Hyper Potion"),
#endif
                .itemId = ITEM_HYPER_POTION,
                .price = 1500,
                .holdEffectParam = 120,
                .description = sHyperPotionDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_SUPER_POTION] =
            {
                .name =
#ifdef CHINESE
                    _("Super Potion"), //TODO 汉化
#else
                    _("Super Potion"),
#endif
                .itemId = ITEM_SUPER_POTION,
                .price = 700,
                .holdEffectParam = 60,
                .description = sSuperPotionDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_FULL_HEAL] =
            {
                .name =
#ifdef CHINESE
                    _("Full Heal"), //TODO 汉化
#else
                    _("Full Heal"),
#endif
                .itemId = ITEM_FULL_HEAL,
                .price = 400,
                .description = sFullHealDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_REVIVE] =
            {
                .name =
#ifdef CHINESE
                    _("Revive"), //TODO 汉化
#else
                    _("Revive"),
#endif
                .itemId = ITEM_REVIVE,
                .price = 2000,
                .description = sReviveDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_MAX_REVIVE] =
            {
                .name =
#ifdef CHINESE
                    _("Max Revive"), //TODO 汉化
#else
                    _("Max Revive"),
#endif
                .itemId = ITEM_MAX_REVIVE,
                .price = 4000,
                .description = sMaxReviveDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_FRESH_WATER] =
            {
                .name =
#ifdef CHINESE
                    _("Fresh Water"), //TODO 汉化
#else
                    _("Fresh Water"),
#endif
                .itemId = ITEM_FRESH_WATER,
                .price = 200,
                .holdEffectParam = 30,
                .description = sFreshWaterDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_SODA_POP] =
            {
                .name =
#ifdef CHINESE
                    _("Soda Pop"), //TODO 汉化
#else
                    _("Soda Pop"),
#endif
                .itemId = ITEM_SODA_POP,
                .price = 300,
                .holdEffectParam = 50,
                .description = sSodaPopDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_LEMONADE] =
            {
                .name =
#ifdef CHINESE
                    _("Lemonade"), //TODO 汉化
#else
                    _("Lemonade"),
#endif
                .itemId = ITEM_LEMONADE,
                .price = 400,
                .holdEffectParam = 70,
                .description = sLemonadeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_MOOMOO_MILK] =
            {
                .name =
#ifdef CHINESE
                    _("Moomoo Milk"), //TODO 汉化
#else
                    _("Moomoo Milk"),
#endif
                .itemId = ITEM_MOOMOO_MILK,
                .price = 600,
                .holdEffectParam = 100,
                .description = sMoomooMilkDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_ENERGY_POWDER] =
            {
                .name =
#ifdef CHINESE
                    _("Energy Powder"), //TODO 汉化
#else
                    _("Energy Powder"),
#endif
                .itemId = ITEM_ENERGY_POWDER,
                .price = 500,
                .description = sEnergyPowderDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_ENERGY_ROOT] =
            {
                .name =
#ifdef CHINESE
                    _("Energy Root"), //TODO 汉化
#else
                    _("Energy Root"),
#endif
                .itemId = ITEM_ENERGY_ROOT,
                .price = 1200,
                .description = sEnergyRootDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_HEAL_POWDER] =
            {
                .name =
#ifdef CHINESE
                    _("Heal Powder"), //TODO 汉化
#else
                    _("Heal Powder"),
#endif
                .itemId = ITEM_HEAL_POWDER,
                .price = 300,
                .description = sHealPowderDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_REVIVAL_HERB] =
            {
                .name =
#ifdef CHINESE
                    _("Revival Herb"), //TODO 汉化
#else
                    _("Revival Herb"),
#endif
                .itemId = ITEM_REVIVAL_HERB,
                .price = 2800,
                .description = sRevivalHerbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_ETHER] =
            {
                .name =
#ifdef CHINESE
                    _("Ether"), //TODO 汉化
#else
                    _("Ether"),
#endif
                .itemId = ITEM_ETHER,
                .price = 1200,
                .holdEffectParam = 10,
                .description = sEtherDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_PPRecovery,
            },

        [ITEM_MAX_ETHER] =
            {
                .name =
#ifdef CHINESE
                    _("Max Ether"), //TODO 汉化
#else
                    _("Max Ether"),
#endif
                .itemId = ITEM_MAX_ETHER,
                .price = 2000,
                .holdEffectParam = 255,
                .description = sMaxEtherDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_PPRecovery,
            },

        [ITEM_ELIXIR] =
            {
                .name =
#ifdef CHINESE
                    _("Elixir"), //TODO 汉化
#else
                    _("Elixir"),
#endif
                .itemId = ITEM_ELIXIR,
                .price = 3000,
                .holdEffectParam = 10,
                .description = sElixirDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_PPRecovery,
            },

        [ITEM_MAX_ELIXIR] =
            {
                .name =
#ifdef CHINESE
                    _("Max Elixir"), //TODO 汉化
#else
                    _("Max Elixir"),
#endif
                .itemId = ITEM_MAX_ELIXIR,
                .price = 4500,
                .holdEffectParam = 255,
                .description = sMaxElixirDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_PPRecovery,
            },

        [ITEM_LAVA_COOKIE] =
            {
                .name =
#ifdef CHINESE
                    _("Lava Cookie"), //TODO 汉化
#else
                    _("Lava Cookie"),
#endif
                .itemId = ITEM_LAVA_COOKIE,
                .price = 350,
                .description = sLavaCookieDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_BLUE_FLUTE] =
            {
                .name =
#ifdef CHINESE
                    _("Blue Flute"), //TODO 汉化
#else
                    _("Blue Flute"),
#endif
                .itemId = ITEM_BLUE_FLUTE,
                .price = 20,
                .description = sBlueFluteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_YELLOW_FLUTE] =
            {
                .name =
#ifdef CHINESE
                    _("Yellow Flute"), //TODO 汉化
#else
                    _("Yellow Flute"),
#endif
                .itemId = ITEM_YELLOW_FLUTE,
                .price = 20,
                .description = sYellowFluteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_RED_FLUTE] =
            {
                .name =
#ifdef CHINESE
                    _("Red Flute"), //TODO 汉化
#else
                    _("Red Flute"),
#endif
                .itemId = ITEM_RED_FLUTE,
                .price = 20,
                .description = sRedFluteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_BLACK_FLUTE] =
            {
                .name =
#ifdef CHINESE
                    _("Black Flute"), //TODO 汉化
#else
                    _("Black Flute"),
#endif
                .itemId = ITEM_BLACK_FLUTE,
                .price = 20,
                .holdEffectParam = 50,
                .description = sBlackFluteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
            },

        [ITEM_WHITE_FLUTE] =
            {
                .name =
#ifdef CHINESE
                    _("White Flute"), //TODO 汉化
#else
                    _("White Flute"),
#endif
                .itemId = ITEM_WHITE_FLUTE,
                .price = 20,
                .holdEffectParam = 150,
                .description = sWhiteFluteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
            },

        [ITEM_BERRY_JUICE] =
            {
                .name =
#ifdef CHINESE
                    _("Berry Juice"), //TODO 汉化
#else
                    _("Berry Juice"),
#endif
                .itemId = ITEM_BERRY_JUICE,
                .price = 200,
                .holdEffect = HOLD_EFFECT_RESTORE_HP,
                .holdEffectParam = 20,
                .description = sBerryJuiceDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_SWEET_HEART] =
            {
                .name =
#ifdef CHINESE
                    _("Sweet Heart"), //TODO 汉化
#else
                    _("Sweet Heart"),
#endif
                .itemId = ITEM_SWEET_HEART,
                .price = 3000,
                .holdEffectParam = 20,
                .description = sSweetHeartDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_BIG_MALASADA] =
            {
                .name =
#ifdef CHINESE
                    _("Big Malasada"), //TODO 汉化
#else
                    _("Big Malasada"),
#endif
                .itemId = ITEM_BIG_MALASADA,
                .price = 350,
                .description = sBigMalasadaDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_OLD_GATEAU] =
            {
                .name =
#ifdef CHINESE
                    _("Old Gateau"), //TODO 汉化
#else
                    _("Old Gateau"),
#endif
                .itemId = ITEM_OLD_GATEAU,
                .price = 350,
                .description = sOldGateauDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_SACRED_ASH] =
            {
                .name =
#ifdef CHINESE
                    _("Sacred Ash"), //TODO 汉化
#else
                    _("Sacred Ash"),
#endif
                .itemId = ITEM_SACRED_ASH,
                .price = 50000,
                .description = sSacredAshDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
            },

        // Collectibles

        [ITEM_SHOAL_SALT] =
            {
                .name =
#ifdef CHINESE
                    _("Shoal Salt"), //TODO 汉化
#else
                    _("Shoal Salt"),
#endif
                .itemId = ITEM_SHOAL_SALT,
                .price = 20,
                .description = sShoalSaltDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SHOAL_SHELL] =
            {
                .name =
#ifdef CHINESE
                    _("Shoal Shell"), //TODO 汉化
#else
                    _("Shoal Shell"),
#endif
                .itemId = ITEM_SHOAL_SHELL,
                .price = 20,
                .description = sShoalShellDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RED_SHARD] =
            {
                .name =
#ifdef CHINESE
                    _("Red Shard"), //TODO 汉化
#else
                    _("Red Shard"),
#endif
                .itemId = ITEM_RED_SHARD,
                .price = 1000,
                .description = sRedShardDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLUE_SHARD] =
            {
                .name =
#ifdef CHINESE
                    _("Blue Shard"), //TODO 汉化
#else
                    _("Blue Shard"),
#endif
                .itemId = ITEM_BLUE_SHARD,
                .price = 1000,
                .description = sBlueShardDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_YELLOW_SHARD] =
            {
                .name =
#ifdef CHINESE
                    _("Yellow Shard"), //TODO 汉化
#else
                    _("Yellow Shard"),
#endif
                .itemId = ITEM_YELLOW_SHARD,
                .price = 1000,
                .description = sYellowShardDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GREEN_SHARD] =
            {
                .name =
#ifdef CHINESE
                    _("Green Shard"), //TODO 汉化
#else
                    _("Green Shard"),
#endif
                .itemId = ITEM_GREEN_SHARD,
                .price = 1000,
                .description = sGreenShardDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        // Vitamins

        [ITEM_HP_UP] =
            {
                .name =
#ifdef CHINESE
                    _("HP Up"), //TODO 汉化
#else
                    _("HP Up"),
#endif
                .itemId = ITEM_HP_UP,
                .price = 10000,
                .description = sHPUpDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_PROTEIN] =
            {
                .name =
#ifdef CHINESE
                    _("Protein"), //TODO 汉化
#else
                    _("Protein"),
#endif
                .itemId = ITEM_PROTEIN,
                .price = 10000,
                .description = sProteinDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_IRON] =
            {
                .name =
#ifdef CHINESE
                    _("Iron"), //TODO 汉化
#else
                    _("Iron"),
#endif
                .itemId = ITEM_IRON,
                .price = 10000,
                .description = sIronDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_CARBOS] =
            {
                .name =
#ifdef CHINESE
                    _("Carbos"), //TODO 汉化
#else
                    _("Carbos"),
#endif
                .itemId = ITEM_CARBOS,
                .price = 10000,
                .description = sCarbosDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_CALCIUM] =
            {
                .name =
#ifdef CHINESE
                    _("Calcium"), //TODO 汉化
#else
                    _("Calcium"),
#endif
                .itemId = ITEM_CALCIUM,
                .price = 10000,
                .description = sCalciumDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_RARE_CANDY] =
            {
                .name =
#ifdef CHINESE
                    _("Rare Candy"), //TODO 汉化
#else
                    _("Rare Candy"),
#endif
                .itemId = ITEM_RARE_CANDY,
                .price = 10000,
                .description = sRareCandyDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
            },

        [ITEM_PP_UP] =
            {
                .name =
#ifdef CHINESE
                    _("PP Up"), //TODO 汉化
#else
                    _("PP Up"),
#endif
                .itemId = ITEM_PP_UP,
                .price = 10000,
                .description = sPPUpDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_PPUp,
            },

        [ITEM_ZINC] =
            {
                .name =
#ifdef CHINESE
                    _("Zinc"), //TODO 汉化
#else
                    _("Zinc"),
#endif
                .itemId = ITEM_ZINC,
                .price = 10000,
                .description = sZincDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_PP_MAX] =
            {
                .name =
#ifdef CHINESE
                    _("PP Max"), //TODO 汉化
#else
                    _("PP Max"),
#endif
                .itemId = ITEM_PP_MAX,
                .price = 10000,
                .description = sPPMaxDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_PPUp,
            },

        // Battle items

        [ITEM_GUARD_SPEC] =
            {
                .name =
#ifdef CHINESE
                    _("Guard Spec."), //TODO 汉化
#else
                    _("Guard Spec."),
#endif
                .itemId = ITEM_GUARD_SPEC,
                .price = 1500,
                .description = sGuardSpecDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_StatIncrease,
            },

        [ITEM_DIRE_HIT] =
            {
                .name =
#ifdef CHINESE
                    _("Dire Hit"), //TODO 汉化
#else
                    _("Dire Hit"),
#endif
                .itemId = ITEM_DIRE_HIT,
                .price = 1000,
                .description = sDireHitDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_StatIncrease,
            },

        [ITEM_X_ATTACK] =
            {
                .name =
#ifdef CHINESE
                    _("X Attack"), //TODO 汉化
#else
                    _("X Attack"),
#endif
                .itemId = ITEM_X_ATTACK,
                .price = 1000,
                .description = sXAttackDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_StatIncrease,
            },

        [ITEM_X_DEFENSE] =
            {
                .name =
#ifdef CHINESE
                    _("X Defense"), //TODO 汉化
#else
                    _("X Defense"),
#endif
                .itemId = ITEM_X_DEFENSE,
                .price = 2000,
                .description = sXDefendDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_StatIncrease,
            },

        [ITEM_X_SPEED] =
            {
                .name =
#ifdef CHINESE
                    _("X Speed"), //TODO 汉化
#else
                    _("X Speed"),
#endif
                .itemId = ITEM_X_SPEED,
                .price = 1000,
                .description = sXSpeedDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_StatIncrease,
            },

        [ITEM_X_ACCURACY] =
            {
                .name =
#ifdef CHINESE
                    _("X Accuracy"), //TODO 汉化
#else
                    _("X Accuracy"),
#endif
                .itemId = ITEM_X_ACCURACY,
                .price = 1000,
                .description = sXAccuracyDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_StatIncrease,
            },

        [ITEM_X_SP_ATK] =
            {
                .name =
#ifdef CHINESE
                    _("X Sp. Atk"), //TODO 汉化
#else
                    _("X Sp. Atk"),
#endif
                .itemId = ITEM_X_SP_ATK,
                .price = 1000,
                .description = sXSpecialAttackDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_StatIncrease,
            },

        [ITEM_X_SP_DEF] =
            {
                .name =
#ifdef CHINESE
                    _("X Sp. Def"), //TODO 汉化
#else
                    _("X Sp. Def"),
#endif
                .itemId = ITEM_X_SP_DEF,
                .price = 2000,
                .description = sXSpecialDefenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_StatIncrease,
            },

        [ITEM_POKE_DOLL] =
            {
                .name =
#ifdef CHINESE
                    _("Poké Doll"), //TODO 汉化
#else
                    _("Poké Doll"),
#endif
                .itemId = ITEM_POKE_DOLL,
                .price = 100,
                .description = sPokeDollDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_Escape,
            },

        [ITEM_FLUFFY_TAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Fluffy Tail"), //TODO 汉化
#else
                    _("Fluffy Tail"),
#endif
                .itemId = ITEM_FLUFFY_TAIL,
                .price = 100,
                .description = sFluffyTailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_OTHER,
                .battleUseFunc = ItemUseInBattle_Escape,
            },

        // Field items

        [ITEM_SUPER_REPEL] =
            {
                .name =
#ifdef CHINESE
                    _("Super Repel"), //TODO 汉化
#else
                    _("Super Repel"),
#endif
                .itemId = ITEM_SUPER_REPEL,
                .price = 700,
                .holdEffectParam = 200,
                .description = sSuperRepelDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Repel,
            },

        [ITEM_MAX_REPEL] =
            {
                .name =
#ifdef CHINESE
                    _("Max Repel"), //TODO 汉化
#else
                    _("Max Repel"),
#endif
                .itemId = ITEM_MAX_REPEL,
                .price = 900,
                .holdEffectParam = 250,
                .description = sMaxRepelDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Repel,
            },

        [ITEM_ABILITY_CAPSULE] =
            {
                .name =
#ifdef CHINESE
                    _("AbilityCapsle"), //TODO 汉化
#else
                    _("AbilityCapsle"),
#endif
                .itemId = ITEM_ABILITY_CAPSULE,
                .price = 10000,
                .holdEffectParam = 0,
                .description = sAbilityCapsuleDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_AbilityCapsule,
            },

        [ITEM_ESCAPE_ROPE] =
            {
                .name =
#ifdef CHINESE
                    _("Escape Rope"), //TODO 汉化
#else
                    _("Escape Rope"),
#endif
                .itemId = ITEM_ESCAPE_ROPE,
                .description = sEscapeRopeDesc,
#if I_KEY_ESCAPE_ROPE >= GEN_8
                .price = 0,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
#else
                .price = 1000,
                .pocket = POCKET_ITEMS,
#endif
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
            },

        [ITEM_REPEL] =
            {
                .name =
#ifdef CHINESE
                    _("Repel"), //TODO 汉化
#else
                    _("Repel"),
#endif
                .itemId = ITEM_REPEL,
                .price = 400,
                .holdEffectParam = 100,
                .description = sRepelDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Repel,
            },

        // Evolution stones

        [ITEM_SUN_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Sun Stone"), //TODO 汉化
#else
                    _("Sun Stone"),
#endif
                .itemId = ITEM_SUN_STONE,
                .price = 3000,
                .description = sSunStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        [ITEM_MOON_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Moon Stone"), //TODO 汉化
#else
                    _("Moon Stone"),
#endif
                .itemId = ITEM_MOON_STONE,
                .price = 3000,
                .description = sMoonStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        [ITEM_FIRE_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Fire Stone"), //TODO 汉化
#else
                    _("Fire Stone"),
#endif
                .itemId = ITEM_FIRE_STONE,
                .price = 3000,
                .description = sFireStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        [ITEM_THUNDER_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Thunder Stone"), //TODO 汉化
#else
                    _("Thunder Stone"),
#endif
                .itemId = ITEM_THUNDER_STONE,
                .price = 3000,
                .description = sThunderStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        [ITEM_WATER_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Water Stone"), //TODO 汉化
#else
                    _("Water Stone"),
#endif
                .itemId = ITEM_WATER_STONE,
                .price = 3000,
                .description = sWaterStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        [ITEM_LEAF_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Leaf Stone"), //TODO 汉化
#else
                    _("Leaf Stone"),
#endif
                .itemId = ITEM_LEAF_STONE,
                .price = 3000,
                .description = sLeafStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        [ITEM_DAWN_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Dawn Stone"), //TODO 汉化
#else
                    _("Dawn Stone"),
#endif
                .itemId = ITEM_DAWN_STONE,
                .price = 3000,
                .description = sDawnStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        [ITEM_DUSK_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Dusk Stone"), //TODO 汉化
#else
                    _("Dusk Stone"),
#endif
                .itemId = ITEM_DUSK_STONE,
                .price = 3000,
                .description = sDuskStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        [ITEM_SHINY_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Shiny Stone"), //TODO 汉化
#else
                    _("Shiny Stone"),
#endif
                .itemId = ITEM_SHINY_STONE,
                .price = 3000,
                .description = sShinyStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        [ITEM_ICE_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Ice Stone"), //TODO 汉化
#else
                    _("Ice Stone"),
#endif
                .itemId = ITEM_ICE_STONE,
                .price = 3000,
                .description = sIceStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
            },

        // Valuable items

        [ITEM_RED_APRICORN] =
            {
                .name =
#ifdef CHINESE
                    _("Red Apricorn"), //TODO 汉化
#else
                    _("Red Apricorn"),
#endif
                .itemId = ITEM_RED_APRICORN,
                .price = 200,
                .description = sRedApricornDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLUE_APRICORN] =
            {
                .name =
#ifdef CHINESE
                    _("Blue Apricorn"), //TODO 汉化
#else
                    _("Blue Apricorn"),
#endif
                .itemId = ITEM_BLUE_APRICORN,
                .price = 200,
                .description = sBlueApricornDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_YELLOW_APRICORN] =
            {
                .name =
#ifdef CHINESE
                    _("YellwApricorn"), //TODO 汉化
#else
                    _("YellwApricorn"),
#endif
                .itemId = ITEM_YELLOW_APRICORN,
                .price = 200,
                .description = sYellowApricornDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GREEN_APRICORN] =
            {
                .name =
#ifdef CHINESE
                    _("GreenApricorn"), //TODO 汉化
#else
                    _("GreenApricorn"),
#endif
                .itemId = ITEM_GREEN_APRICORN,
                .price = 200,
                .description = sGreenApricornDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PINK_APRICORN] =
            {
                .name =
#ifdef CHINESE
                    _("Pink Apricorn"), //TODO 汉化
#else
                    _("Pink Apricorn"),
#endif
                .itemId = ITEM_PINK_APRICORN,
                .price = 200,
                .description = sPinkApricornDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WHITE_APRICORN] =
            {
                .name =
#ifdef CHINESE
                    _("WhiteApricorn"), //TODO 汉化
#else
                    _("WhiteApricorn"),
#endif
                .itemId = ITEM_WHITE_APRICORN,
                .price = 200,
                .description = sWhiteApricornDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLACK_APRICORN] =
            {
                .name =
#ifdef CHINESE
                    _("BlackApricorn"), //TODO 汉化
#else
                    _("BlackApricorn"),
#endif
                .itemId = ITEM_BLACK_APRICORN,
                .price = 200,
                .description = sBlackApricornDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TINY_MUSHROOM] =
            {
                .name =
#ifdef CHINESE
                    _("Tiny Mushroom"), //TODO 汉化
#else
                    _("Tiny Mushroom"),
#endif
                .itemId = ITEM_TINY_MUSHROOM,
                .price = 500,
                .description = sTinyMushroomDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BIG_MUSHROOM] =
            {
                .name =
#ifdef CHINESE
                    _("Big Mushroom"), //TODO 汉化
#else
                    _("Big Mushroom"),
#endif
                .itemId = ITEM_BIG_MUSHROOM,
                .price = 5000,
                .description = sBigMushroomDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PEARL] =
            {
                .name =
#ifdef CHINESE
                    _("Pearl"), //TODO 汉化
#else
                    _("Pearl"),
#endif
                .itemId = ITEM_PEARL,
                .price = 2000,
                .description = sPearlDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BIG_PEARL] =
            {
                .name =
#ifdef CHINESE
                    _("Big Pearl"), //TODO 汉化
#else
                    _("Big Pearl"),
#endif
                .itemId = ITEM_BIG_PEARL,
                .price = 8000,
                .description = sBigPearlDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_STARDUST] =
            {
                .name =
#ifdef CHINESE
                    _("Stardust"), //TODO 汉化
#else
                    _("Stardust"),
#endif
                .itemId = ITEM_STARDUST,
                .price = 3000,
                .description = sStardustDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_STAR_PIECE] =
            {
                .name =
#ifdef CHINESE
                    _("Star Piece"), //TODO 汉化
#else
                    _("Star Piece"),
#endif
                .itemId = ITEM_STAR_PIECE,
                .price = 12000,
                .description = sStarPieceDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_NUGGET] =
            {
                .name =
#ifdef CHINESE
                    _("Nugget"), //TODO 汉化
#else
                    _("Nugget"),
#endif
                .itemId = ITEM_NUGGET,
                .price = 10000,
                .description = sNuggetDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_HEART_SCALE] =
            {
                .name =
#ifdef CHINESE
                    _("Heart Scale"), //TODO 汉化
#else
                    _("Heart Scale"),
#endif
                .itemId = ITEM_HEART_SCALE,
                .price = 100,
                .description = sHeartScaleDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RED_NECTAR] =
            {
                .name =
#ifdef CHINESE
                    _("Red Nectar"), //TODO 汉化
#else
                    _("Red Nectar"),
#endif
                .itemId = ITEM_RED_NECTAR,
                .price = 300,
                .holdEffectParam = 0,
                .description = sRedNectarDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Placeholder
            },

        [ITEM_YELLOW_NECTAR] =
            {
                .name =
#ifdef CHINESE
                    _("Yellow Nectar"), //TODO 汉化
#else
                    _("Yellow Nectar"),
#endif
                .itemId = ITEM_YELLOW_NECTAR,
                .price = 300,
                .holdEffectParam = 0,
                .description = sYellowNectarDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Placeholder
            },

        [ITEM_PINK_NECTAR] =
            {
                .name =
#ifdef CHINESE
                    _("Pink Nectar"), //TODO 汉化
#else
                    _("Pink Nectar"),
#endif
                .itemId = ITEM_PINK_NECTAR,
                .price = 300,
                .holdEffectParam = 0,
                .description = sPinkNectarDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Placeholder
            },

        [ITEM_PURPLE_NECTAR] =
            {
                .name =
#ifdef CHINESE
                    _("Purple Nectar"), //TODO 汉化
#else
                    _("Purple Nectar"),
#endif
                .itemId = ITEM_PURPLE_NECTAR,
                .price = 300,
                .holdEffectParam = 0,
                .description = sPurpleNectarDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Placeholder
            },

        [ITEM_RARE_BONE] =
            {
                .name =
#ifdef CHINESE
                    _("Rare Bone"), //TODO 汉化
#else
                    _("Rare Bone"),
#endif
                .itemId = ITEM_RARE_BONE,
                .price = 5000,
                .description = sRareBoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        // Mail
        [ITEM_ORANGE_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Orange Mail"), //TODO 汉化
#else
                    _("Orange Mail"),
#endif
                .itemId = ITEM_ORANGE_MAIL,
                .price = 50,
                .description = sOrangeMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
            },

        [ITEM_HARBOR_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Harbor Mail"), //TODO 汉化
#else
                    _("Harbor Mail"),
#endif
                .itemId = ITEM_HARBOR_MAIL,
                .price = 50,
                .description = sHarborMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
            },

        [ITEM_GLITTER_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Glitter Mail"), //TODO 汉化
#else
                    _("Glitter Mail"),
#endif
                .itemId = ITEM_GLITTER_MAIL,
                .price = 50,
                .description = sGlitterMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
            },

        [ITEM_MECH_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Mech Mail"), //TODO 汉化
#else
                    _("Mech Mail"),
#endif
                .itemId = ITEM_MECH_MAIL,
                .price = 50,
                .description = sMechMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
            },

        [ITEM_WOOD_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Wood Mail"), //TODO 汉化
#else
                    _("Wood Mail"),
#endif
                .itemId = ITEM_WOOD_MAIL,
                .price = 50,
                .description = sWoodMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
            },

        [ITEM_WAVE_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Wave Mail"), //TODO 汉化
#else
                    _("Wave Mail"),
#endif
                .itemId = ITEM_WAVE_MAIL,
                .price = 50,
                .description = sWaveMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
            },

        [ITEM_BEAD_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Bead Mail"), //TODO 汉化
#else
                    _("Bead Mail"),
#endif
                .itemId = ITEM_BEAD_MAIL,
                .price = 50,
                .description = sBeadMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
            },

        [ITEM_SHADOW_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Shadow Mail"), //TODO 汉化
#else
                    _("Shadow Mail"),
#endif
                .itemId = ITEM_SHADOW_MAIL,
                .price = 50,
                .description = sShadowMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
            },

        [ITEM_TROPIC_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Tropic Mail"), //TODO 汉化
#else
                    _("Tropic Mail"),
#endif
                .itemId = ITEM_TROPIC_MAIL,
                .price = 50,
                .description = sTropicMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
            },

        [ITEM_DREAM_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Dream Mail"), //TODO 汉化
#else
                    _("Dream Mail"),
#endif
                .itemId = ITEM_DREAM_MAIL,
                .price = 50,
                .description = sDreamMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
            },

        [ITEM_FAB_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Fab Mail"), //TODO 汉化
#else
                    _("Fab Mail"),
#endif
                .itemId = ITEM_FAB_MAIL,
                .price = 50,
                .description = sFabMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
            },

        [ITEM_RETRO_MAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Retro Mail"), //TODO 汉化
#else
                    _("Retro Mail"),
#endif
                .itemId = ITEM_RETRO_MAIL,
                .price = 50,
                .description = sRetroMailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_MAIL,
                .fieldUseFunc = ItemUseOutOfBattle_Mail,
                .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
            },

        // Berries

        [ITEM_CHERI_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Cheri Berry"), //TODO 汉化
#else
                    _("Cheri Berry"),
#endif
                .itemId = ITEM_CHERI_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CURE_PAR,
                .description = sCheriBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_CHESTO_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Chesto Berry"), //TODO 汉化
#else
                    _("Chesto Berry"),
#endif
                .itemId = ITEM_CHESTO_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CURE_SLP,
                .description = sChestoBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_PECHA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Pecha Berry"), //TODO 汉化
#else
                    _("Pecha Berry"),
#endif
                .itemId = ITEM_PECHA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CURE_PSN,
                .description = sPechaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_RAWST_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Rawst Berry"), //TODO 汉化
#else
                    _("Rawst Berry"),
#endif
                .itemId = ITEM_RAWST_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CURE_BRN,
                .description = sRawstBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_ASPEAR_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Aspear Berry"), //TODO 汉化
#else
                    _("Aspear Berry"),
#endif
                .itemId = ITEM_ASPEAR_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CURE_FRZ,
                .description = sAspearBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_LEPPA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Leppa Berry"), //TODO 汉化
#else
                    _("Leppa Berry"),
#endif
                .itemId = ITEM_LEPPA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESTORE_PP,
                .holdEffectParam = 10,
                .description = sLeppaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_PPRecovery,
            },

        [ITEM_ORAN_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Oran Berry"), //TODO 汉化
#else
                    _("Oran Berry"),
#endif
                .itemId = ITEM_ORAN_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESTORE_HP,
                .holdEffectParam = 10,
                .description = sOranBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_PERSIM_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Persim Berry"), //TODO 汉化
#else
                    _("Persim Berry"),
#endif
                .itemId = ITEM_PERSIM_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
                .description = sPersimBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_LUM_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Lum Berry"), //TODO 汉化
#else
                    _("Lum Berry"),
#endif
                .itemId = ITEM_LUM_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CURE_STATUS,
                .description = sLumBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_SITRUS_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Sitrus Berry"), //TODO 汉化
#else
                    _("Sitrus Berry"),
#endif
                .itemId = ITEM_SITRUS_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESTORE_HP,
                .holdEffectParam = 30,
                .description = sSitrusBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_Medicine,
            },

        [ITEM_FIGY_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Figy Berry"), //TODO 汉化
#else
                    _("Figy Berry"),
#endif
                .itemId = ITEM_FIGY_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
                .holdEffectParam = 8,
                .description = sFigyBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WIKI_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Wiki Berry"), //TODO 汉化
#else
                    _("Wiki Berry"),
#endif
                .itemId = ITEM_WIKI_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
                .holdEffectParam = 8,
                .description = sWikiBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MAGO_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Mago Berry"), //TODO 汉化
#else
                    _("Mago Berry"),
#endif
                .itemId = ITEM_MAGO_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
                .holdEffectParam = 8,
                .description = sMagoBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_AGUAV_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Aguav Berry"), //TODO 汉化
#else
                    _("Aguav Berry"),
#endif
                .itemId = ITEM_AGUAV_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
                .holdEffectParam = 8,
                .description = sAguavBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_IAPAPA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Iapapa Berry"), //TODO 汉化
#else
                    _("Iapapa Berry"),
#endif
                .itemId = ITEM_IAPAPA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
                .holdEffectParam = 8,
                .description = sIapapaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RAZZ_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Razz Berry"), //TODO 汉化
#else
                    _("Razz Berry"),
#endif
                .itemId = ITEM_RAZZ_BERRY,
                .price = 20,
                .description = sRazzBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLUK_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Bluk Berry"), //TODO 汉化
#else
                    _("Bluk Berry"),
#endif
                .itemId = ITEM_BLUK_BERRY,
                .price = 20,
                .description = sBlukBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_NANAB_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Nanab Berry"), //TODO 汉化
#else
                    _("Nanab Berry"),
#endif
                .itemId = ITEM_NANAB_BERRY,
                .price = 20,
                .description = sNanabBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WEPEAR_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Wepear Berry"), //TODO 汉化
#else
                    _("Wepear Berry"),
#endif
                .itemId = ITEM_WEPEAR_BERRY,
                .price = 20,
                .description = sWepearBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PINAP_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Pinap Berry"), //TODO 汉化
#else
                    _("Pinap Berry"),
#endif
                .itemId = ITEM_PINAP_BERRY,
                .price = 20,
                .description = sPinapBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_POMEG_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Pomeg Berry"), //TODO 汉化
#else
                    _("Pomeg Berry"),
#endif
                .itemId = ITEM_POMEG_BERRY,
                .price = 20,
                .description = sPomegBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
            },

        [ITEM_KELPSY_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Kelpsy Berry"), //TODO 汉化
#else
                    _("Kelpsy Berry"),
#endif
                .itemId = ITEM_KELPSY_BERRY,
                .price = 20,
                .description = sKelpsyBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
            },

        [ITEM_QUALOT_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Qualot Berry"), //TODO 汉化
#else
                    _("Qualot Berry"),
#endif
                .itemId = ITEM_QUALOT_BERRY,
                .price = 20,
                .description = sQualotBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
            },

        [ITEM_HONDEW_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Hondew Berry"), //TODO 汉化
#else
                    _("Hondew Berry"),
#endif
                .itemId = ITEM_HONDEW_BERRY,
                .price = 20,
                .description = sHondewBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
            },

        [ITEM_GREPA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Grepa Berry"), //TODO 汉化
#else
                    _("Grepa Berry"),
#endif
                .itemId = ITEM_GREPA_BERRY,
                .price = 20,
                .description = sGrepaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
            },

        [ITEM_TAMATO_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Tamato Berry"), //TODO 汉化
#else
                    _("Tamato Berry"),
#endif
                .itemId = ITEM_TAMATO_BERRY,
                .price = 20,
                .description = sTamatoBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
            },

        [ITEM_CORNN_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Cornn Berry"), //TODO 汉化
#else
                    _("Cornn Berry"),
#endif
                .itemId = ITEM_CORNN_BERRY,
                .price = 20,
                .description = sCornnBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MAGOST_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Magost Berry"), //TODO 汉化
#else
                    _("Magost Berry"),
#endif
                .itemId = ITEM_MAGOST_BERRY,
                .price = 20,
                .description = sMagostBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RABUTA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Rabuta Berry"), //TODO 汉化
#else
                    _("Rabuta Berry"),
#endif
                .itemId = ITEM_RABUTA_BERRY,
                .price = 20,
                .description = sRabutaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_NOMEL_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Nomel Berry"), //TODO 汉化
#else
                    _("Nomel Berry"),
#endif
                .itemId = ITEM_NOMEL_BERRY,
                .price = 20,
                .description = sNomelBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SPELON_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Spelon Berry"), //TODO 汉化
#else
                    _("Spelon Berry"),
#endif
                .itemId = ITEM_SPELON_BERRY,
                .price = 20,
                .description = sSpelonBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PAMTRE_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Pamtre Berry"), //TODO 汉化
#else
                    _("Pamtre Berry"),
#endif
                .itemId = ITEM_PAMTRE_BERRY,
                .price = 20,
                .description = sPamtreBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WATMEL_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Watmel Berry"), //TODO 汉化
#else
                    _("Watmel Berry"),
#endif
                .itemId = ITEM_WATMEL_BERRY,
                .price = 20,
                .description = sWatmelBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DURIN_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Durin Berry"), //TODO 汉化
#else
                    _("Durin Berry"),
#endif
                .itemId = ITEM_DURIN_BERRY,
                .price = 20,
                .description = sDurinBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BELUE_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Belue Berry"), //TODO 汉化
#else
                    _("Belue Berry"),
#endif
                .itemId = ITEM_BELUE_BERRY,
                .price = 20,
                .description = sBelueBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LIECHI_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Liechi Berry"), //TODO 汉化
#else
                    _("Liechi Berry"),
#endif
                .itemId = ITEM_LIECHI_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_ATTACK_UP,
                .holdEffectParam = 4,
                .description = sLiechiBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GANLON_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Ganlon Berry"), //TODO 汉化
#else
                    _("Ganlon Berry"),
#endif
                .itemId = ITEM_GANLON_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_DEFENSE_UP,
                .holdEffectParam = 4,
                .description = sGanlonBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SALAC_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Salac Berry"), //TODO 汉化
#else
                    _("Salac Berry"),
#endif
                .itemId = ITEM_SALAC_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_SPEED_UP,
                .holdEffectParam = 4,
                .description = sSalacBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PETAYA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Petaya Berry"), //TODO 汉化
#else
                    _("Petaya Berry"),
#endif
                .itemId = ITEM_PETAYA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
                .holdEffectParam = 4,
                .description = sPetayaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_APICOT_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Apicot Berry"), //TODO 汉化
#else
                    _("Apicot Berry"),
#endif
                .itemId = ITEM_APICOT_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
                .holdEffectParam = 4,
                .description = sApicotBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LANSAT_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Lansat Berry"), //TODO 汉化
#else
                    _("Lansat Berry"),
#endif
                .itemId = ITEM_LANSAT_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CRITICAL_UP,
                .holdEffectParam = 4,
                .description = sLansatBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_STARF_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Starf Berry"), //TODO 汉化
#else
                    _("Starf Berry"),
#endif
                .itemId = ITEM_STARF_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
                .holdEffectParam = 4,
                .description = sStarfBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MICLE_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Micle Berry"), //TODO 汉化
#else
                    _("Micle Berry"),
#endif
                .itemId = ITEM_MICLE_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_MICLE_BERRY,
                .holdEffectParam = 4,
                .description = sMicleBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ENIGMA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Enigma Berry"), //TODO 汉化
#else
                    _("Enigma Berry"),
#endif
                .itemId = ITEM_ENIGMA_BERRY,
                .price = 20,
                .description = sEnigmaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
                .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
                .battleUsage = ITEM_B_USE_MEDICINE,
                .battleUseFunc = ItemUseInBattle_EnigmaBerry,
            },

        [ITEM_OCCA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Occa Berry"), //TODO 汉化
#else
                    _("Occa Berry"),
#endif
                .itemId = ITEM_OCCA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_FIRE,
                .description = sOccaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PASSHO_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Passho Berry"), //TODO 汉化
#else
                    _("Passho Berry"),
#endif
                .itemId = ITEM_PASSHO_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_WATER,
                .description = sPasshoBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WACAN_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Wacan Berry"), //TODO 汉化
#else
                    _("Wacan Berry"),
#endif
                .itemId = ITEM_WACAN_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_ELECTRIC,
                .description = sWacanBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RINDO_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Rindo Berry"), //TODO 汉化
#else
                    _("Rindo Berry"),
#endif
                .itemId = ITEM_RINDO_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_GRASS,
                .description = sRindoBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_YACHE_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Yache Berry"), //TODO 汉化
#else
                    _("Yache Berry"),
#endif
                .itemId = ITEM_YACHE_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_ICE,
                .description = sYacheBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CHOPLE_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Chople Berry"), //TODO 汉化
#else
                    _("Chople Berry"),
#endif
                .itemId = ITEM_CHOPLE_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_FIGHTING,
                .description = sChopleBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_KEBIA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Kebia Berry"), //TODO 汉化
#else
                    _("Kebia Berry"),
#endif
                .itemId = ITEM_KEBIA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_POISON,
                .description = sKebiaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SHUCA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Shuca Berry"), //TODO 汉化
#else
                    _("Shuca Berry"),
#endif
                .itemId = ITEM_SHUCA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_GROUND,
                .description = sShucaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_COBA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Coba Berry"), //TODO 汉化
#else
                    _("Coba Berry"),
#endif
                .itemId = ITEM_COBA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_FIGHTING,
                .description = sCobaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PAYAPA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Payapa Berry"), //TODO 汉化
#else
                    _("Payapa Berry"),
#endif
                .itemId = ITEM_PAYAPA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_PSYCHIC,
                .description = sPayapaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TANGA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Tanga Berry"), //TODO 汉化
#else
                    _("Tanga Berry"),
#endif
                .itemId = ITEM_TANGA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_BUG,
                .description = sTangaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CHARTI_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Charti Berry"), //TODO 汉化
#else
                    _("Charti Berry"),
#endif
                .itemId = ITEM_CHARTI_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_ROCK,
                .description = sChartiBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_KASIB_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Kasib Berry"), //TODO 汉化
#else
                    _("Kasib Berry"),
#endif
                .itemId = ITEM_KASIB_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_GHOST,
                .description = sKasibBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_HABAN_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Haban Berry"), //TODO 汉化
#else
                    _("Haban Berry"),
#endif
                .itemId = ITEM_HABAN_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_DRAGON,
                .description = sHabanBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_COLBUR_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Colbur Berry"), //TODO 汉化
#else
                    _("Colbur Berry"),
#endif
                .itemId = ITEM_COLBUR_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_DARK,
                .description = sColburBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BABIRI_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Babiri Berry"), //TODO 汉化
#else
                    _("Babiri Berry"),
#endif
                .itemId = ITEM_BABIRI_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_STEEL,
                .description = sBabiriBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CHILAN_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Chilan Berry"), //TODO 汉化
#else
                    _("Chilan Berry"),
#endif
                .itemId = ITEM_CHILAN_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_NORMAL,
                .description = sChilanBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROSELI_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Roseli Berry"), //TODO 汉化
#else
                    _("Roseli Berry"),
#endif
                .itemId = ITEM_ROSELI_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_RESIST_BERRY,
                .holdEffectParam = TYPE_FAIRY,
                .description = sRoseliBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CUSTAP_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Custap Berry"), //TODO 汉化
#else
                    _("Custap Berry"),
#endif
                .itemId = ITEM_CUSTAP_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_CUSTAP_BERRY,
                .holdEffectParam = 4,
                .description = sCustapBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_JABOCA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Jaboca Berry"), //TODO 汉化
#else
                    _("Jaboca Berry"),
#endif
                .itemId = ITEM_JABOCA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_JABOCA_BERRY,
                .description = sJabocaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROWAP_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Rowap Berry"), //TODO 汉化
#else
                    _("Rowap Berry"),
#endif
                .itemId = ITEM_ROWAP_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_ROWAP_BERRY,
                .description = sRowapBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_KEE_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Kee Berry"), //TODO 汉化
#else
                    _("Kee Berry"),
#endif
                .itemId = ITEM_KEE_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_KEE_BERRY,
                .description = sKeeBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MARANGA_BERRY] =
            {
                .name =
#ifdef CHINESE
                    _("Maranga Berry"), //TODO 汉化
#else
                    _("Maranga Berry"),
#endif
                .itemId = ITEM_MARANGA_BERRY,
                .price = 20,
                .holdEffect = HOLD_EFFECT_MARANGA_BERRY,
                .description = sMarangaBerryDesc,
                .pocket = POCKET_BERRIES,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        // Hold items

        [ITEM_BRIGHT_POWDER] =
            {
                .name =
#ifdef CHINESE
                    _("Bright Powder"), //TODO 汉化
#else
                    _("Bright Powder"),
#endif
                .itemId = ITEM_BRIGHT_POWDER,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_EVASION_UP,
                .holdEffectParam = 10,
                .description = sBrightPowderDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WHITE_HERB] =
            {
                .name =
#ifdef CHINESE
                    _("White Herb"), //TODO 汉化
#else
                    _("White Herb"),
#endif
                .itemId = ITEM_WHITE_HERB,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_RESTORE_STATS,
                .description = sWhiteHerbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MACHO_BRACE] =
            {
                .name =
#ifdef CHINESE
                    _("Macho Brace"), //TODO 汉化
#else
                    _("Macho Brace"),
#endif
                .itemId = ITEM_MACHO_BRACE,
                .price = 3000,
                .holdEffect = HOLD_EFFECT_MACHO_BRACE,
                .description = sMachoBraceDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_EXP_SHARE] =
            {
                .name =
#ifdef CHINESE
                    _("Exp. Share"), //TODO 汉化
#else
                    _("Exp. Share"),
#endif
                .itemId = ITEM_EXP_SHARE,
                .price = 3000,
                .holdEffect = HOLD_EFFECT_EXP_SHARE,
                .description = sExpShareDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_QUICK_CLAW] =
            {
                .name =
#ifdef CHINESE
                    _("Quick Claw"), //TODO 汉化
#else
                    _("Quick Claw"),
#endif
                .itemId = ITEM_QUICK_CLAW,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_QUICK_CLAW,
                .holdEffectParam = 20,
                .description = sQuickClawDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SOOTHE_BELL] =
            {
                .name =
#ifdef CHINESE
                    _("Soothe Bell"), //TODO 汉化
#else
                    _("Soothe Bell"),
#endif
                .itemId = ITEM_SOOTHE_BELL,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
                .description = sSootheBellDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MENTAL_HERB] =
            {
                .name =
#ifdef CHINESE
                    _("Mental Herb"), //TODO 汉化
#else
                    _("Mental Herb"),
#endif
                .itemId = ITEM_MENTAL_HERB,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_CURE_ATTRACT,
                .description = sMentalHerbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CHOICE_BAND] =
            {
                .name =
#ifdef CHINESE
                    _("Choice Band"), //TODO 汉化
#else
                    _("Choice Band"),
#endif
                .itemId = ITEM_CHOICE_BAND,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_CHOICE_BAND,
                .description = sChoiceBandDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_KINGS_ROCK] =
            {
                .name =
#ifdef CHINESE
                    _("King's Rock"), //TODO 汉化
#else
                    _("King's Rock"),
#endif
                .itemId = ITEM_KINGS_ROCK,
                .price = 5000,
                .holdEffect = HOLD_EFFECT_FLINCH,
                .holdEffectParam = 10,
                .description = sKingsRockDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SILVER_POWDER] =
            {
                .name =
#ifdef CHINESE
                    _("Silver Powder"), //TODO 汉化
#else
                    _("Silver Powder"),
#endif
                .itemId = ITEM_SILVER_POWDER,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_BUG_POWER,
                .holdEffectParam = 20,
                .description = sSilverPowderDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_AMULET_COIN] =
            {
                .name =
#ifdef CHINESE
                    _("Amulet Coin"), //TODO 汉化
#else
                    _("Amulet Coin"),
#endif
                .itemId = ITEM_AMULET_COIN,
                .price = 10000,
                .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
                .holdEffectParam = 10,
                .description = sAmuletCoinDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CLEANSE_TAG] =
            {
                .name =
#ifdef CHINESE
                    _("Cleanse Tag"), //TODO 汉化
#else
                    _("Cleanse Tag"),
#endif
                .itemId = ITEM_CLEANSE_TAG,
                .price = 5000,
                .holdEffect = HOLD_EFFECT_REPEL,
                .description = sCleanseTagDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SOUL_DEW] =
            {
                .name =
#ifdef CHINESE
                    _("Soul Dew"), //TODO 汉化
#else
                    _("Soul Dew"),
#endif
                .itemId = ITEM_SOUL_DEW,
                .price = 0,
                .holdEffect = HOLD_EFFECT_SOUL_DEW,
                .description = sSoulDewDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DEEP_SEA_TOOTH] =
            {
                .name =
#ifdef CHINESE
                    _("DeepSeaTooth"), //TODO 汉化
#else
                    _("DeepSeaTooth"),
#endif
                .itemId = ITEM_DEEP_SEA_TOOTH,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
                .description = sDeepSeaToothDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DEEP_SEA_SCALE] =
            {
                .name =
#ifdef CHINESE
                    _("DeepSeaScale"), //TODO 汉化
#else
                    _("DeepSeaScale"),
#endif
                .itemId = ITEM_DEEP_SEA_SCALE,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
                .description = sDeepSeaScaleDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SMOKE_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Smoke Ball"), //TODO 汉化
#else
                    _("Smoke Ball"),
#endif
                .itemId = ITEM_SMOKE_BALL,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
                .description = sSmokeBallDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_EVERSTONE] =
            {
                .name =
#ifdef CHINESE
                    _("Everstone"), //TODO 汉化
#else
                    _("Everstone"),
#endif
                .itemId = ITEM_EVERSTONE,
                .price = 3000,
                .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
                .description = sEverstoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_FOCUS_BAND] =
            {
                .name =
#ifdef CHINESE
                    _("Focus Band"), //TODO 汉化
#else
                    _("Focus Band"),
#endif
                .itemId = ITEM_FOCUS_BAND,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_FOCUS_BAND,
                .holdEffectParam = 10,
                .description = sFocusBandDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LUCKY_EGG] =
            {
                .name =
#ifdef CHINESE
                    _("Lucky Egg"), //TODO 汉化
#else
                    _("Lucky Egg"),
#endif
                .itemId = ITEM_LUCKY_EGG,
                .price = 10000,
                .holdEffect = HOLD_EFFECT_LUCKY_EGG,
                .description = sLuckyEggDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SCOPE_LENS] =
            {
                .name =
#ifdef CHINESE
                    _("Scope Lens"), //TODO 汉化
#else
                    _("Scope Lens"),
#endif
                .itemId = ITEM_SCOPE_LENS,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SCOPE_LENS,
                .description = sScopeLensDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_METAL_COAT] =
            {
                .name =
#ifdef CHINESE
                    _("Metal Coat"), //TODO 汉化
#else
                    _("Metal Coat"),
#endif
                .itemId = ITEM_METAL_COAT,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_STEEL_POWER,
                .holdEffectParam = 20,
                .description = sMetalCoatDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LEFTOVERS] =
            {
                .name =
#ifdef CHINESE
                    _("Leftovers"), //TODO 汉化
#else
                    _("Leftovers"),
#endif
                .itemId = ITEM_LEFTOVERS,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_LEFTOVERS,
                .holdEffectParam = 10,
                .description = sLeftoversDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DRAGON_SCALE] =
            {
                .name =
#ifdef CHINESE
                    _("Dragon Scale"), //TODO 汉化
#else
                    _("Dragon Scale"),
#endif
                .itemId = ITEM_DRAGON_SCALE,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_DRAGON_SCALE,
                .holdEffectParam = 10,
                .description = sDragonScaleDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_OVAL_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Oval Stone"), //TODO 汉化
#else
                    _("Oval Stone"),
#endif
                .itemId = ITEM_OVAL_STONE,
                .price = 2000,
                .description = sOvalStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PROTECTOR] =
            {
                .name =
#ifdef CHINESE
                    _("Protector"), //TODO 汉化
#else
                    _("Protector"),
#endif
                .itemId = ITEM_PROTECTOR,
                .price = 2000,
                .description = sProtectorDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ELECTIRIZER] =
            {
                .name =
#ifdef CHINESE
                    _("Electirizer"), //TODO 汉化
#else
                    _("Electirizer"),
#endif
                .itemId = ITEM_ELECTIRIZER,
                .price = 2000,
                .description = sElectirizerDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MAGMARIZER] =
            {
                .name =
#ifdef CHINESE
                    _("Magmarizer"), //TODO 汉化
#else
                    _("Magmarizer"),
#endif
                .itemId = ITEM_MAGMARIZER,
                .price = 2000,
                .description = sMagmarizerDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DUBIOUS_DISC] =
            {
                .name =
#ifdef CHINESE
                    _("Dubious Disc"), //TODO 汉化
#else
                    _("Dubious Disc"),
#endif
                .itemId = ITEM_DUBIOUS_DISC,
                .price = 2000,
                .description = sDubiousDiscDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_REAPER_CLOTH] =
            {
                .name =
#ifdef CHINESE
                    _("Reaper Cloth"), //TODO 汉化
#else
                    _("Reaper Cloth"),
#endif
                .itemId = ITEM_REAPER_CLOTH,
                .price = 2000,
                .description = sReaperClothDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RAZOR_CLAW] =
            {
                .name =
#ifdef CHINESE
                    _("Razor Claw"), //TODO 汉化
#else
                    _("Razor Claw"),
#endif
                .itemId = ITEM_RAZOR_CLAW,
                .price = 5000,
                .holdEffect = HOLD_EFFECT_SCOPE_LENS,
                .description = sRazorClawDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RAZOR_FANG] =
            {
                .name =
#ifdef CHINESE
                    _("Razor Fang"), //TODO 汉化
#else
                    _("Razor Fang"),
#endif
                .itemId = ITEM_RAZOR_FANG,
                .price = 5000,
                .holdEffect = HOLD_EFFECT_FLINCH,
                .holdEffectParam = 10,
                .description = sRazorFangDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PRISM_SCALE] =
            {
                .name =
#ifdef CHINESE
                    _("Prism Scale"), //TODO 汉化
#else
                    _("Prism Scale"),
#endif
                .itemId = ITEM_PRISM_SCALE,
                .price = 2000,
                .description = sPrismScaleDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WHIPPED_DREAM] =
            {
                .name =
#ifdef CHINESE
                    _("Whipped Dream"), //TODO 汉化
#else
                    _("Whipped Dream"),
#endif
                .itemId = ITEM_WHIPPED_DREAM,
                .price = 2000,
                .description = sWhippedDreamDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SACHET] =
            {
                .name =
#ifdef CHINESE
                    _("Sachet"), //TODO 汉化
#else
                    _("Sachet"),
#endif
                .itemId = ITEM_SACHET,
                .price = 2000,
                .description = sSachetDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LIGHT_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Light Ball"), //TODO 汉化
#else
                    _("Light Ball"),
#endif
                .itemId = ITEM_LIGHT_BALL,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_LIGHT_BALL,
                .description = sLightBallDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SOFT_SAND] =
            {
                .name =
#ifdef CHINESE
                    _("Soft Sand"), //TODO 汉化
#else
                    _("Soft Sand"),
#endif
                .itemId = ITEM_SOFT_SAND,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_GROUND_POWER,
                .holdEffectParam = 20,
                .description = sSoftSandDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_HARD_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Hard Stone"), //TODO 汉化
#else
                    _("Hard Stone"),
#endif
                .itemId = ITEM_HARD_STONE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_ROCK_POWER,
                .holdEffectParam = 20,
                .description = sHardStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MIRACLE_SEED] =
            {
                .name =
#ifdef CHINESE
                    _("Miracle Seed"), //TODO 汉化
#else
                    _("Miracle Seed"),
#endif
                .itemId = ITEM_MIRACLE_SEED,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_GRASS_POWER,
                .holdEffectParam = 20,
                .description = sMiracleSeedDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLACK_GLASSES] =
            {
                .name =
#ifdef CHINESE
                    _("Black Glasses"), //TODO 汉化
#else
                    _("Black Glasses"),
#endif
                .itemId = ITEM_BLACK_GLASSES,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_DARK_POWER,
                .holdEffectParam = 20,
                .description = sBlackGlassesDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLACK_BELT] =
            {
                .name =
#ifdef CHINESE
                    _("Black Belt"), //TODO 汉化
#else
                    _("Black Belt"),
#endif
                .itemId = ITEM_BLACK_BELT,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_FIGHTING_POWER,
                .holdEffectParam = 20,
                .description = sBlackBeltDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MAGNET] =
            {
                .name =
#ifdef CHINESE
                    _("Magnet"), //TODO 汉化
#else
                    _("Magnet"),
#endif
                .itemId = ITEM_MAGNET,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_ELECTRIC_POWER,
                .holdEffectParam = 20,
                .description = sMagnetDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MYSTIC_WATER] =
            {
                .name =
#ifdef CHINESE
                    _("Mystic Water"), //TODO 汉化
#else
                    _("Mystic Water"),
#endif
                .itemId = ITEM_MYSTIC_WATER,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_WATER_POWER,
                .holdEffectParam = 20,
                .description = sMysticWaterDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SHARP_BEAK] =
            {
                .name =
#ifdef CHINESE
                    _("Sharp Beak"), //TODO 汉化
#else
                    _("Sharp Beak"),
#endif
                .itemId = ITEM_SHARP_BEAK,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_FLYING_POWER,
                .holdEffectParam = 20,
                .description = sSharpBeakDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_POISON_BARB] =
            {
                .name =
#ifdef CHINESE
                    _("Poison Barb"), //TODO 汉化
#else
                    _("Poison Barb"),
#endif
                .itemId = ITEM_POISON_BARB,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_POISON_POWER,
                .holdEffectParam = 20,
                .description = sPoisonBarbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_NEVER_MELT_ICE] =
            {
                .name =
#ifdef CHINESE
                    _("Never-MeltIce"), //TODO 汉化
#else
                    _("Never-MeltIce"),
#endif
                .itemId = ITEM_NEVER_MELT_ICE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_ICE_POWER,
                .holdEffectParam = 20,
                .description = sNeverMeltIceDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SPELL_TAG] =
            {
                .name =
#ifdef CHINESE
                    _("Spell Tag"), //TODO 汉化
#else
                    _("Spell Tag"),
#endif
                .itemId = ITEM_SPELL_TAG,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_GHOST_POWER,
                .holdEffectParam = 20,
                .description = sSpellTagDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TWISTED_SPOON] =
            {
                .name =
#ifdef CHINESE
                    _("Twisted Spoon"), //TODO 汉化
#else
                    _("Twisted Spoon"),
#endif
                .itemId = ITEM_TWISTED_SPOON,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
                .holdEffectParam = 20,
                .description = sTwistedSpoonDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CHARCOAL] =
            {
                .name =
#ifdef CHINESE
                    _("Charcoal"), //TODO 汉化
#else
                    _("Charcoal"),
#endif
                .itemId = ITEM_CHARCOAL,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_FIRE_POWER,
                .holdEffectParam = 20,
                .description = sCharcoalDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DRAGON_FANG] =
            {
                .name =
#ifdef CHINESE
                    _("Dragon Fang"), //TODO 汉化
#else
                    _("Dragon Fang"),
#endif
                .itemId = ITEM_DRAGON_FANG,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_DRAGON_POWER,
                .holdEffectParam = 20,
                .description = sDragonFangDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SILK_SCARF] =
            {
                .name =
#ifdef CHINESE
                    _("Silk Scarf"), //TODO 汉化
#else
                    _("Silk Scarf"),
#endif
                .itemId = ITEM_SILK_SCARF,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_NORMAL_POWER,
                .holdEffectParam = 20,
                .description = sSilkScarfDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_UP_GRADE] =
            {
                .name =
#ifdef CHINESE
                    _("Upgrade"), //TODO 汉化
#else
                    _("Upgrade"),
#endif
                .itemId = ITEM_UP_GRADE,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_UP_GRADE,
                .description = sUpGradeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SHELL_BELL] =
            {
                .name =
#ifdef CHINESE
                    _("Shell Bell"), //TODO 汉化
#else
                    _("Shell Bell"),
#endif
                .itemId = ITEM_SHELL_BELL,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SHELL_BELL,
                .holdEffectParam = 8,
                .description = sShellBellDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_POWER_BRACER] =
            {
                .name =
#ifdef CHINESE
                    _("Power Bracer"), //TODO 汉化
#else
                    _("Power Bracer"),
#endif
                .itemId = ITEM_POWER_BRACER,
                .price = 3000,
                .holdEffect = HOLD_EFFECT_POWER_ITEM,
                .holdEffectParam = 8,
                .description = sPowerBracerDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = STAT_ATK,
            },

        [ITEM_POWER_BELT] =
            {
                .name =
#ifdef CHINESE
                    _("Power Belt"), //TODO 汉化
#else
                    _("Power Belt"),
#endif
                .itemId = ITEM_POWER_BELT,
                .price = 3000,
                .holdEffect = HOLD_EFFECT_POWER_ITEM,
                .holdEffectParam = 8,
                .description = sPowerBeltDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = STAT_DEF,
            },

        [ITEM_POWER_LENS] =
            {
                .name =
#ifdef CHINESE
                    _("Power Lens"), //TODO 汉化
#else
                    _("Power Lens"),
#endif
                .itemId = ITEM_POWER_LENS,
                .price = 3000,
                .holdEffect = HOLD_EFFECT_POWER_ITEM,
                .holdEffectParam = 8,
                .description = sPowerLensDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = STAT_SPATK,
            },

        [ITEM_POWER_BAND] =
            {
                .name =
#ifdef CHINESE
                    _("Power Band"), //TODO 汉化
#else
                    _("Power Band"),
#endif
                .itemId = ITEM_POWER_BAND,
                .price = 3000,
                .holdEffect = HOLD_EFFECT_POWER_ITEM,
                .holdEffectParam = 8,
                .description = sPowerBandDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = STAT_SPDEF,
            },

        [ITEM_POWER_ANKLET] =
            {
                .name =
#ifdef CHINESE
                    _("Power Anklet"), //TODO 汉化
#else
                    _("Power Anklet"),
#endif
                .itemId = ITEM_POWER_ANKLET,
                .price = 3000,
                .holdEffect = HOLD_EFFECT_POWER_ITEM,
                .holdEffectParam = 8,
                .description = sPowerAnkletDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = STAT_SPEED,
            },

        [ITEM_POWER_WEIGHT] =
            {
                .name =
#ifdef CHINESE
                    _("Power Weight"), //TODO 汉化
#else
                    _("Power Weight"),
#endif
                .itemId = ITEM_POWER_WEIGHT,
                .price = 3000,
                .holdEffect = HOLD_EFFECT_POWER_ITEM,
                .holdEffectParam = 8,
                .description = sPowerWeightDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = STAT_HP,
            },

        [ITEM_SEA_INCENSE] =
            {
                .name =
#ifdef CHINESE
                    _("Sea Incense"), //TODO 汉化
#else
                    _("Sea Incense"),
#endif
                .itemId = ITEM_SEA_INCENSE,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_WATER_POWER,
                .holdEffectParam = 20,
                .description = sSeaIncenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LAX_INCENSE] =
            {
                .name =
#ifdef CHINESE
                    _("Lax Incense"), //TODO 汉化
#else
                    _("Lax Incense"),
#endif
                .itemId = ITEM_LAX_INCENSE,
                .price = 5000,
                .holdEffect = HOLD_EFFECT_EVASION_UP,
                .holdEffectParam = 10,
                .description = sLaxIncenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ODD_INCENSE] =
            {
                .name =
#ifdef CHINESE
                    _("Odd Incense"), //TODO 汉化
#else
                    _("Odd Incense"),
#endif
                .itemId = ITEM_ODD_INCENSE,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
                .holdEffectParam = 20,
                .description = sOddIncenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROCK_INCENSE] =
            {
                .name =
#ifdef CHINESE
                    _("Rock Incense"), //TODO 汉化
#else
                    _("Rock Incense"),
#endif
                .itemId = ITEM_ROCK_INCENSE,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_ROCK_POWER,
                .holdEffectParam = 20,
                .description = sRockIncenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_FULL_INCENSE] =
            {
                .name =
#ifdef CHINESE
                    _("Full Incense"), //TODO 汉化
#else
                    _("Full Incense"),
#endif
                .itemId = ITEM_FULL_INCENSE,
                .price = 5000,
                .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
                .holdEffectParam = 5,
                .description = sFullIncenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WAVE_INCENSE] =
            {
                .name =
#ifdef CHINESE
                    _("Wave Incense"), //TODO 汉化
#else
                    _("Wave Incense"),
#endif
                .itemId = ITEM_WAVE_INCENSE,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_WATER_POWER,
                .holdEffectParam = 20,
                .description = sWaveIncenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROSE_INCENSE] =
            {
                .name =
#ifdef CHINESE
                    _("Rose Incense"), //TODO 汉化
#else
                    _("Rose Incense"),
#endif
                .itemId = ITEM_ROSE_INCENSE,
                .price = 2000,
                .holdEffect = HOLD_EFFECT_GRASS_POWER,
                .holdEffectParam = 20,
                .description = sRoseIncenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LUCK_INCENSE] =
            {
                .name =
#ifdef CHINESE
                    _("Luck Incense"), //TODO 汉化
#else
                    _("Luck Incense"),
#endif
                .itemId = ITEM_LUCK_INCENSE,
                .price = 11000,
                .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
                .holdEffectParam = 10,
                .description = sLuckIncenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PURE_INCENSE] =
            {
                .name =
#ifdef CHINESE
                    _("Pure Incense"), //TODO 汉化
#else
                    _("Pure Incense"),
#endif
                .itemId = ITEM_PURE_INCENSE,
                .price = 6000,
                .holdEffect = HOLD_EFFECT_REPEL,
                .description = sPureIncenseDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LUCKY_PUNCH] =
            {
                .name =
#ifdef CHINESE
                    _("Lucky Punch"), //TODO 汉化
#else
                    _("Lucky Punch"),
#endif
                .itemId = ITEM_LUCKY_PUNCH,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
                .description = sLuckyPunchDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_METAL_POWDER] =
            {
                .name =
#ifdef CHINESE
                    _("Metal Powder"), //TODO 汉化
#else
                    _("Metal Powder"),
#endif
                .itemId = ITEM_METAL_POWDER,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_METAL_POWDER,
                .description = sMetalPowderDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_THICK_CLUB] =
            {
                .name =
#ifdef CHINESE
                    _("Thick Club"), //TODO 汉化
#else
                    _("Thick Club"),
#endif
                .itemId = ITEM_THICK_CLUB,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_THICK_CLUB,
                .description = sThickClubDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_STICK] =
            {
                .name =
#ifdef CHINESE
                    _("Leek"), //TODO 汉化
#else
                    _("Leek"),
#endif
                .itemId = ITEM_STICK,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_STICK,
                .description = sStickDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RED_SCARF] =
            {
                .name =
#ifdef CHINESE
                    _("Red Scarf"), //TODO 汉化
#else
                    _("Red Scarf"),
#endif
                .itemId = ITEM_RED_SCARF,
                .price = 100,
                .description = sRedScarfDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLUE_SCARF] =
            {
                .name =
#ifdef CHINESE
                    _("Blue Scarf"), //TODO 汉化
#else
                    _("Blue Scarf"),
#endif
                .itemId = ITEM_BLUE_SCARF,
                .price = 100,
                .description = sBlueScarfDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PINK_SCARF] =
            {
                .name =
#ifdef CHINESE
                    _("Pink Scarf"), //TODO 汉化
#else
                    _("Pink Scarf"),
#endif
                .itemId = ITEM_PINK_SCARF,
                .price = 100,
                .description = sPinkScarfDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GREEN_SCARF] =
            {
                .name =
#ifdef CHINESE
                    _("Green Scarf"), //TODO 汉化
#else
                    _("Green Scarf"),
#endif
                .itemId = ITEM_GREEN_SCARF,
                .price = 100,
                .description = sGreenScarfDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_YELLOW_SCARF] =
            {
                .name =
#ifdef CHINESE
                    _("Yellow Scarf"), //TODO 汉化
#else
                    _("Yellow Scarf"),
#endif
                .itemId = ITEM_YELLOW_SCARF,
                .price = 100,
                .description = sYellowScarfDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        // Key items

        [ITEM_MACH_BIKE] =
            {
                .name =
#ifdef CHINESE
                    _("Mach Bike"), //TODO 汉化
#else
                    _("Mach Bike"),
#endif
                .itemId = ITEM_MACH_BIKE,
                .price = 0,
                .description = sMachBikeDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_Bike,
                .secondaryId = MACH_BIKE,
            },

        [ITEM_COIN_CASE] =
            {
                .name =
#ifdef CHINESE
                    _("Coin Case"), //TODO 汉化
#else
                    _("Coin Case"),
#endif
                .itemId = ITEM_COIN_CASE,
                .price = 0,
                .description = sCoinCaseDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
            },

        [ITEM_ITEMFINDER] =
            {
                .name =
#ifdef CHINESE
                    _("Dowsing MCHN"), //TODO 汉化
#else
                    _("Dowsing MCHN"),
#endif
                .itemId = ITEM_ITEMFINDER,
                .price = 0,
                .description = sItemfinderDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
            },

        [ITEM_OLD_ROD] =
            {
                .name =
#ifdef CHINESE
                    _("Old Rod"), //TODO 汉化
#else
                    _("Old Rod"),
#endif
                .itemId = ITEM_OLD_ROD,
                .price = 0,
                .description = sOldRodDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_Rod,
                .secondaryId = OLD_ROD,
            },

        [ITEM_GOOD_ROD] =
            {
                .name =
#ifdef CHINESE
                    _("Good Rod"), //TODO 汉化
#else
                    _("Good Rod"),
#endif
                .itemId = ITEM_GOOD_ROD,
                .price = 0,
                .description = sGoodRodDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_Rod,
                .secondaryId = GOOD_ROD,
            },

        [ITEM_SUPER_ROD] =
            {
                .name =
#ifdef CHINESE
                    _("Super Rod"), //TODO 汉化
#else
                    _("Super Rod"),
#endif
                .itemId = ITEM_SUPER_ROD,
                .price = 0,
                .description = sSuperRodDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_Rod,
                .secondaryId = SUPER_ROD,
            },

        [ITEM_SS_TICKET] =
            {
                .name =
#ifdef CHINESE
                    _("S.S. Ticket"), //TODO 汉化
#else
                    _("S.S. Ticket"),
#endif
                .itemId = ITEM_SS_TICKET,
                .price = 0,
                .description = sSSTicketDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CONTEST_PASS] =
            {
                .name =
#ifdef CHINESE
                    _("Contest Pass"), //TODO 汉化
#else
                    _("Contest Pass"),
#endif
                .itemId = ITEM_CONTEST_PASS,
                .price = 0,
                .description = sContestPassDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WAILMER_PAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Wailmer Pail"), //TODO 汉化
#else
                    _("Wailmer Pail"),
#endif
                .itemId = ITEM_WAILMER_PAIL,
                .price = 0,
                .description = sWailmerPailDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
            },

        [ITEM_DEVON_GOODS] =
            {
                .name =
#ifdef CHINESE
                    _("Devon Parts"), //TODO 汉化
#else
                    _("Devon Parts"),
#endif
                .itemId = ITEM_DEVON_GOODS,
                .price = 0,
                .description = sDevonGoodsDesc,
                .importance = 2,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SOOT_SACK] =
            {
                .name =
#ifdef CHINESE
                    _("Soot Sack"), //TODO 汉化
#else
                    _("Soot Sack"),
#endif
                .itemId = ITEM_SOOT_SACK,
                .price = 0,
                .description = sSootSackDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BASEMENT_KEY] =
            {
                .name =
#ifdef CHINESE
                    _("Basement Key"), //TODO 汉化
#else
                    _("Basement Key"),
#endif
                .itemId = ITEM_BASEMENT_KEY,
                .price = 0,
                .description = sBasementKeyDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ACRO_BIKE] =
            {
                .name =
#ifdef CHINESE
                    _("Acro Bike"), //TODO 汉化
#else
                    _("Acro Bike"),
#endif
                .itemId = ITEM_ACRO_BIKE,
                .price = 0,
                .description = sAcroBikeDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_Bike,
                .secondaryId = ACRO_BIKE,
            },

        [ITEM_POKEBLOCK_CASE] =
            {
                .name =
#ifdef CHINESE
                    _("{POKEBLOCK} CASE"), //TODO 汉化
#else
                    _("{POKEBLOCK} CASE"),
#endif
                .itemId = ITEM_POKEBLOCK_CASE,
                .price = 0,
                .description = sPokeblockCaseDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_PBLOCK_CASE,
                .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
            },

        [ITEM_LETTER] =
            {
                .name =
#ifdef CHINESE
                    _("Letter"), //TODO 汉化
#else
                    _("Letter"),
#endif
                .itemId = ITEM_LETTER,
                .price = 0,
                .description = sLetterDesc,
                .importance = 2,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_EON_TICKET] =
            {
                .name =
#ifdef CHINESE
                    _("Eon Ticket"), //TODO 汉化
#else
                    _("Eon Ticket"),
#endif
                .itemId = ITEM_EON_TICKET,
                .price = 0,
                .description = sEonTicketDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 1,
            },

        [ITEM_RED_ORB] =
            {
                .name =
#ifdef CHINESE
                    _("Red Orb"), //TODO 汉化
#else
                    _("Red Orb"),
#endif
                .itemId = ITEM_RED_ORB,
                .price = 0,
                .description = sRedOrbDesc,
                .importance = 2,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLUE_ORB] =
            {
                .name =
#ifdef CHINESE
                    _("Blue Orb"), //TODO 汉化
#else
                    _("Blue Orb"),
#endif
                .itemId = ITEM_BLUE_ORB,
                .price = 0,
                .description = sBlueOrbDesc,
                .importance = 2,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SCANNER] =
            {
                .name =
#ifdef CHINESE
                    _("Scanner"), //TODO 汉化
#else
                    _("Scanner"),
#endif
                .itemId = ITEM_SCANNER,
                .price = 0,
                .description = sScannerDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GO_GOGGLES] =
            {
                .name =
#ifdef CHINESE
                    _("Go-Goggles"), //TODO 汉化
#else
                    _("Go-Goggles"),
#endif
                .itemId = ITEM_GO_GOGGLES,
                .price = 0,
                .description = sGoGogglesDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_METEORITE] =
            {
                .name =
#ifdef CHINESE
                    _("Meteorite"), //TODO 汉化
#else
                    _("Meteorite"),
#endif
                .itemId = ITEM_METEORITE,
                .price = 0,
                .description = sMeteoriteDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROOM_1_KEY] =
            {
                .name =
#ifdef CHINESE
                    _("Key to Room 1"), //TODO 汉化
#else
                    _("Key to Room 1"),
#endif
                .itemId = ITEM_ROOM_1_KEY,
                .price = 0,
                .description = sRoom1KeyDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROOM_2_KEY] =
            {
                .name =
#ifdef CHINESE
                    _("Key to Room 2"), //TODO 汉化
#else
                    _("Key to Room 2"),
#endif
                .itemId = ITEM_ROOM_2_KEY,
                .price = 0,
                .description = sRoom2KeyDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROOM_4_KEY] =
            {
                .name =
#ifdef CHINESE
                    _("Key to Room 4"), //TODO 汉化
#else
                    _("Key to Room 4"),
#endif
                .itemId = ITEM_ROOM_4_KEY,
                .price = 0,
                .description = sRoom4KeyDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROOM_6_KEY] =
            {
                .name =
#ifdef CHINESE
                    _("Key to Room 6"), //TODO 汉化
#else
                    _("Key to Room 6"),
#endif
                .itemId = ITEM_ROOM_6_KEY,
                .price = 0,
                .description = sRoom6KeyDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_STORAGE_KEY] =
            {
                .name =
#ifdef CHINESE
                    _("Storage Key"), //TODO 汉化
#else
                    _("Storage Key"),
#endif
                .itemId = ITEM_STORAGE_KEY,
                .price = 0,
                .description = sStorageKeyDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DEVON_SCOPE] =
            {
                .name =
#ifdef CHINESE
                    _("Devon Scope"), //TODO 汉化
#else
                    _("Devon Scope"),
#endif
                .itemId = ITEM_DEVON_SCOPE,
                .price = 0,
                .description = sDevonScopeDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        // TMs/HMs

        [ITEM_TM01_FOCUS_PUNCH] =
            {
                .name =
#ifdef CHINESE
                    _("TM01"), //TODO 汉化
#else
                    _("TM01"),
#endif
                .itemId = ITEM_TM01_FOCUS_PUNCH,
                .price = 3000,
                .description = sTM01Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM02_DRAGON_CLAW] =
            {
                .name =
#ifdef CHINESE
                    _("TM02"), //TODO 汉化
#else
                    _("TM02"),
#endif
                .itemId = ITEM_TM02_DRAGON_CLAW,
                .price = 3000,
                .description = sTM02Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM03_WATER_PULSE] =
            {
                .name =
#ifdef CHINESE
                    _("TM03"), //TODO 汉化
#else
                    _("TM03"),
#endif
                .itemId = ITEM_TM03_WATER_PULSE,
                .price = 3000,
                .description = sTM03Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM04_CALM_MIND] =
            {
                .name =
#ifdef CHINESE
                    _("TM04"), //TODO 汉化
#else
                    _("TM04"),
#endif
                .itemId = ITEM_TM04_CALM_MIND,
                .price = 3000,
                .description = sTM04Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM05_ROAR] =
            {
                .name =
#ifdef CHINESE
                    _("TM05"), //TODO 汉化
#else
                    _("TM05"),
#endif
                .itemId = ITEM_TM05_ROAR,
                .price = 1000,
                .description = sTM05Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM06_TOXIC] =
            {
                .name =
#ifdef CHINESE
                    _("TM06"), //TODO 汉化
#else
                    _("TM06"),
#endif
                .itemId = ITEM_TM06_TOXIC,
                .price = 3000,
                .description = sTM06Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM07_HAIL] =
            {
                .name =
#ifdef CHINESE
                    _("TM07"), //TODO 汉化
#else
                    _("TM07"),
#endif
                .itemId = ITEM_TM07_HAIL,
                .price = 3000,
                .description = sTM07Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM08_BULK_UP] =
            {
                .name =
#ifdef CHINESE
                    _("TM08"), //TODO 汉化
#else
                    _("TM08"),
#endif
                .itemId = ITEM_TM08_BULK_UP,
                .price = 3000,
                .description = sTM08Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM09_BULLET_SEED] =
            {
                .name =
#ifdef CHINESE
                    _("TM09"), //TODO 汉化
#else
                    _("TM09"),
#endif
                .itemId = ITEM_TM09_BULLET_SEED,
                .price = 3000,
                .description = sTM09Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM10_HIDDEN_POWER] =
            {
                .name =
#ifdef CHINESE
                    _("TM10"), //TODO 汉化
#else
                    _("TM10"),
#endif
                .itemId = ITEM_TM10_HIDDEN_POWER,
                .price = 3000,
                .description = sTM10Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM11_SUNNY_DAY] =
            {
                .name =
#ifdef CHINESE
                    _("TM11"), //TODO 汉化
#else
                    _("TM11"),
#endif
                .itemId = ITEM_TM11_SUNNY_DAY,
                .price = 2000,
                .description = sTM11Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM12_TAUNT] =
            {
                .name =
#ifdef CHINESE
                    _("TM12"), //TODO 汉化
#else
                    _("TM12"),
#endif
                .itemId = ITEM_TM12_TAUNT,
                .price = 3000,
                .description = sTM12Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM13_ICE_BEAM] =
            {
                .name =
#ifdef CHINESE
                    _("TM13"), //TODO 汉化
#else
                    _("TM13"),
#endif
                .itemId = ITEM_TM13_ICE_BEAM,
                .price = 3000,
                .description = sTM13Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM14_BLIZZARD] =
            {
                .name =
#ifdef CHINESE
                    _("TM14"), //TODO 汉化
#else
                    _("TM14"),
#endif
                .itemId = ITEM_TM14_BLIZZARD,
                .price = 5500,
                .description = sTM14Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM15_HYPER_BEAM] =
            {
                .name =
#ifdef CHINESE
                    _("TM15"), //TODO 汉化
#else
                    _("TM15"),
#endif
                .itemId = ITEM_TM15_HYPER_BEAM,
                .price = 7500,
                .description = sTM15Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM16_LIGHT_SCREEN] =
            {
                .name =
#ifdef CHINESE
                    _("TM16"), //TODO 汉化
#else
                    _("TM16"),
#endif
                .itemId = ITEM_TM16_LIGHT_SCREEN,
                .price = 3000,
                .description = sTM16Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM17_PROTECT] =
            {
                .name =
#ifdef CHINESE
                    _("TM17"), //TODO 汉化
#else
                    _("TM17"),
#endif
                .itemId = ITEM_TM17_PROTECT,
                .price = 3000,
                .description = sTM17Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM18_RAIN_DANCE] =
            {
                .name =
#ifdef CHINESE
                    _("TM18"), //TODO 汉化
#else
                    _("TM18"),
#endif
                .itemId = ITEM_TM18_RAIN_DANCE,
                .price = 2000,
                .description = sTM18Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM19_GIGA_DRAIN] =
            {
                .name =
#ifdef CHINESE
                    _("TM19"), //TODO 汉化
#else
                    _("TM19"),
#endif
                .itemId = ITEM_TM19_GIGA_DRAIN,
                .price = 3000,
                .description = sTM19Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM20_SAFEGUARD] =
            {
                .name =
#ifdef CHINESE
                    _("TM20"), //TODO 汉化
#else
                    _("TM20"),
#endif
                .itemId = ITEM_TM20_SAFEGUARD,
                .price = 3000,
                .description = sTM20Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM21_FRUSTRATION] =
            {
                .name =
#ifdef CHINESE
                    _("TM21"), //TODO 汉化
#else
                    _("TM21"),
#endif
                .itemId = ITEM_TM21_FRUSTRATION,
                .price = 1000,
                .description = sTM21Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM22_SOLARBEAM] =
            {
                .name =
#ifdef CHINESE
                    _("TM22"), //TODO 汉化
#else
                    _("TM22"),
#endif
                .itemId = ITEM_TM22_SOLARBEAM,
                .price = 3000,
                .description = sTM22Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM23_IRON_TAIL] =
            {
                .name =
#ifdef CHINESE
                    _("TM23"), //TODO 汉化
#else
                    _("TM23"),
#endif
                .itemId = ITEM_TM23_IRON_TAIL,
                .price = 3000,
                .description = sTM23Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM24_THUNDERBOLT] =
            {
                .name =
#ifdef CHINESE
                    _("TM24"), //TODO 汉化
#else
                    _("TM24"),
#endif
                .itemId = ITEM_TM24_THUNDERBOLT,
                .price = 3000,
                .description = sTM24Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM25_THUNDER] =
            {
                .name =
#ifdef CHINESE
                    _("TM25"), //TODO 汉化
#else
                    _("TM25"),
#endif
                .itemId = ITEM_TM25_THUNDER,
                .price = 5500,
                .description = sTM25Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM26_EARTHQUAKE] =
            {
                .name =
#ifdef CHINESE
                    _("TM26"), //TODO 汉化
#else
                    _("TM26"),
#endif
                .itemId = ITEM_TM26_EARTHQUAKE,
                .price = 3000,
                .description = sTM26Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM27_RETURN] =
            {
                .name =
#ifdef CHINESE
                    _("TM27"), //TODO 汉化
#else
                    _("TM27"),
#endif
                .itemId = ITEM_TM27_RETURN,
                .price = 1000,
                .description = sTM27Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM28_DIG] =
            {
                .name =
#ifdef CHINESE
                    _("TM28"), //TODO 汉化
#else
                    _("TM28"),
#endif
                .itemId = ITEM_TM28_DIG,
                .price = 2000,
                .description = sTM28Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM29_PSYCHIC] =
            {
                .name =
#ifdef CHINESE
                    _("TM29"), //TODO 汉化
#else
                    _("TM29"),
#endif
                .itemId = ITEM_TM29_PSYCHIC,
                .price = 2000,
                .description = sTM29Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM30_SHADOW_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("TM30"), //TODO 汉化
#else
                    _("TM30"),
#endif
                .itemId = ITEM_TM30_SHADOW_BALL,
                .price = 3000,
                .description = sTM30Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM31_BRICK_BREAK] =
            {
                .name =
#ifdef CHINESE
                    _("TM31"), //TODO 汉化
#else
                    _("TM31"),
#endif
                .itemId = ITEM_TM31_BRICK_BREAK,
                .price = 3000,
                .description = sTM31Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM32_DOUBLE_TEAM] =
            {
                .name =
#ifdef CHINESE
                    _("TM32"), //TODO 汉化
#else
                    _("TM32"),
#endif
                .itemId = ITEM_TM32_DOUBLE_TEAM,
                .price = 2000,
                .description = sTM32Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM33_REFLECT] =
            {
                .name =
#ifdef CHINESE
                    _("TM33"), //TODO 汉化
#else
                    _("TM33"),
#endif
                .itemId = ITEM_TM33_REFLECT,
                .price = 3000,
                .description = sTM33Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM34_SHOCK_WAVE] =
            {
                .name =
#ifdef CHINESE
                    _("TM34"), //TODO 汉化
#else
                    _("TM34"),
#endif
                .itemId = ITEM_TM34_SHOCK_WAVE,
                .price = 3000,
                .description = sTM34Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM35_FLAMETHROWER] =
            {
                .name =
#ifdef CHINESE
                    _("TM35"), //TODO 汉化
#else
                    _("TM35"),
#endif
                .itemId = ITEM_TM35_FLAMETHROWER,
                .price = 3000,
                .description = sTM35Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM36_SLUDGE_BOMB] =
            {
                .name =
#ifdef CHINESE
                    _("TM36"), //TODO 汉化
#else
                    _("TM36"),
#endif
                .itemId = ITEM_TM36_SLUDGE_BOMB,
                .price = 1000,
                .description = sTM36Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM37_SANDSTORM] =
            {
                .name =
#ifdef CHINESE
                    _("TM37"), //TODO 汉化
#else
                    _("TM37"),
#endif
                .itemId = ITEM_TM37_SANDSTORM,
                .price = 2000,
                .description = sTM37Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM38_FIRE_BLAST] =
            {
                .name =
#ifdef CHINESE
                    _("TM38"), //TODO 汉化
#else
                    _("TM38"),
#endif
                .itemId = ITEM_TM38_FIRE_BLAST,
                .price = 5500,
                .description = sTM38Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM39_ROCK_TOMB] =
            {
                .name =
#ifdef CHINESE
                    _("TM39"), //TODO 汉化
#else
                    _("TM39"),
#endif
                .itemId = ITEM_TM39_ROCK_TOMB,
                .price = 3000,
                .description = sTM39Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM40_AERIAL_ACE] =
            {
                .name =
#ifdef CHINESE
                    _("TM40"), //TODO 汉化
#else
                    _("TM40"),
#endif
                .itemId = ITEM_TM40_AERIAL_ACE,
                .price = 3000,
                .description = sTM40Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM41_TORMENT] =
            {
                .name =
#ifdef CHINESE
                    _("TM41"), //TODO 汉化
#else
                    _("TM41"),
#endif
                .itemId = ITEM_TM41_TORMENT,
                .price = 3000,
                .description = sTM41Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM42_FACADE] =
            {
                .name =
#ifdef CHINESE
                    _("TM42"), //TODO 汉化
#else
                    _("TM42"),
#endif
                .itemId = ITEM_TM42_FACADE,
                .price = 3000,
                .description = sTM42Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM43_SECRET_POWER] =
            {
                .name =
#ifdef CHINESE
                    _("TM43"), //TODO 汉化
#else
                    _("TM43"),
#endif
                .itemId = ITEM_TM43_SECRET_POWER,
                .price = 3000,
                .description = sTM43Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM44_REST] =
            {
                .name =
#ifdef CHINESE
                    _("TM44"), //TODO 汉化
#else
                    _("TM44"),
#endif
                .itemId = ITEM_TM44_REST,
                .price = 3000,
                .description = sTM44Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM45_ATTRACT] =
            {
                .name =
#ifdef CHINESE
                    _("TM45"), //TODO 汉化
#else
                    _("TM45"),
#endif
                .itemId = ITEM_TM45_ATTRACT,
                .price = 3000,
                .description = sTM45Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM46_THIEF] =
            {
                .name =
#ifdef CHINESE
                    _("TM46"), //TODO 汉化
#else
                    _("TM46"),
#endif
                .itemId = ITEM_TM46_THIEF,
                .price = 3000,
                .description = sTM46Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM47_STEEL_WING] =
            {
                .name =
#ifdef CHINESE
                    _("TM47"), //TODO 汉化
#else
                    _("TM47"),
#endif
                .itemId = ITEM_TM47_STEEL_WING,
                .price = 3000,
                .description = sTM47Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM48_SKILL_SWAP] =
            {
                .name =
#ifdef CHINESE
                    _("TM48"), //TODO 汉化
#else
                    _("TM48"),
#endif
                .itemId = ITEM_TM48_SKILL_SWAP,
                .price = 3000,
                .description = sTM48Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM49_SNATCH] =
            {
                .name =
#ifdef CHINESE
                    _("TM49"), //TODO 汉化
#else
                    _("TM49"),
#endif
                .itemId = ITEM_TM49_SNATCH,
                .price = 3000,
                .description = sTM49Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_TM50_OVERHEAT] =
            {
                .name =
#ifdef CHINESE
                    _("TM50"), //TODO 汉化
#else
                    _("TM50"),
#endif
                .itemId = ITEM_TM50_OVERHEAT,
                .price = 3000,
                .description = sTM50Desc,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_HM01_CUT] =
            {
                .name =
#ifdef CHINESE
                    _("HM01"), //TODO 汉化
#else
                    _("HM01"),
#endif
                .itemId = ITEM_HM01_CUT,
                .price = 0,
                .description = sHM01Desc,
                .importance = 1,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_HM02_FLY] =
            {
                .name =
#ifdef CHINESE
                    _("HM02"), //TODO 汉化
#else
                    _("HM02"),
#endif
                .itemId = ITEM_HM02_FLY,
                .price = 0,
                .description = sHM02Desc,
                .importance = 1,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_HM03_SURF] =
            {
                .name =
#ifdef CHINESE
                    _("HM03"), //TODO 汉化
#else
                    _("HM03"),
#endif
                .itemId = ITEM_HM03_SURF,
                .price = 0,
                .description = sHM03Desc,
                .importance = 1,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_HM04_STRENGTH] =
            {
                .name =
#ifdef CHINESE
                    _("HM04"), //TODO 汉化
#else
                    _("HM04"),
#endif
                .itemId = ITEM_HM04_STRENGTH,
                .price = 0,
                .description = sHM04Desc,
                .importance = 1,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_HM05_FLASH] =
            {
                .name =
#ifdef CHINESE
                    _("HM05"), //TODO 汉化
#else
                    _("HM05"),
#endif
                .itemId = ITEM_HM05_FLASH,
                .price = 0,
                .description = sHM05Desc,
                .importance = 1,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_HM06_ROCK_SMASH] =
            {
                .name =
#ifdef CHINESE
                    _("HM06"), //TODO 汉化
#else
                    _("HM06"),
#endif
                .itemId = ITEM_HM06_ROCK_SMASH,
                .price = 0,
                .description = sHM06Desc,
                .importance = 1,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_HM07_WATERFALL] =
            {
                .name =
#ifdef CHINESE
                    _("HM07"), //TODO 汉化
#else
                    _("HM07"),
#endif
                .itemId = ITEM_HM07_WATERFALL,
                .price = 0,
                .description = sHM07Desc,
                .importance = 1,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        [ITEM_HM08_DIVE] =
            {
                .name =
#ifdef CHINESE
                    _("HM08"), //TODO 汉化
#else
                    _("HM08"),
#endif
                .itemId = ITEM_HM08_DIVE,
                .price = 0,
                .description = sHM08Desc,
                .importance = 1,
                .pocket = POCKET_TM_HM,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_TMHM,
            },

        // FireRed/LeafGreen key items

        [ITEM_OAKS_PARCEL] =
            {
                .name =
#ifdef CHINESE
                    _("Parcel"), //TODO 汉化
#else
                    _("Parcel"),
#endif
                .itemId = ITEM_OAKS_PARCEL,
                .price = 0,
                .description = sOaksParcelDesc,
                .importance = 2,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_POKE_FLUTE] =
            {
                .name =
#ifdef CHINESE
                    _("Poké Flute"), //TODO 汉化
#else
                    _("Poké Flute"),
#endif
                .itemId = ITEM_POKE_FLUTE,
                .price = 0,
                .description = sPokeFluteDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SECRET_KEY] =
            {
                .name =
#ifdef CHINESE
                    _("Secret Key"), //TODO 汉化
#else
                    _("Secret Key"),
#endif
                .itemId = ITEM_SECRET_KEY,
                .price = 0,
                .description = sSecretKeyDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BIKE_VOUCHER] =
            {
                .name =
#ifdef CHINESE
                    _("Bike Voucher"), //TODO 汉化
#else
                    _("Bike Voucher"),
#endif
                .itemId = ITEM_BIKE_VOUCHER,
                .price = 0,
                .description = sBikeVoucherDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GOLD_TEETH] =
            {
                .name =
#ifdef CHINESE
                    _("Gold Teeth"), //TODO 汉化
#else
                    _("Gold Teeth"),
#endif
                .itemId = ITEM_GOLD_TEETH,
                .price = 0,
                .description = sGoldTeethDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_OLD_AMBER] =
            {
                .name =
#ifdef CHINESE
                    _("Old Amber"), //TODO 汉化
#else
                    _("Old Amber"),
#endif
                .itemId = ITEM_OLD_AMBER,
                .description = sOldAmberDesc,
#if I_KEY_FOSSILS >= GEN_4
                .price = 10000,
                .pocket = POCKET_ITEMS,
#else
                .price = 0,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
#endif
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CARD_KEY] =
            {
                .name =
#ifdef CHINESE
                    _("Card Key"), //TODO 汉化
#else
                    _("Card Key"),
#endif
                .itemId = ITEM_CARD_KEY,
                .price = 0,
                .description = sCardKeyDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LIFT_KEY] =
            {
                .name =
#ifdef CHINESE
                    _("Lift Key"), //TODO 汉化
#else
                    _("Lift Key"),
#endif
                .itemId = ITEM_LIFT_KEY,
                .price = 0,
                .description = sLiftKeyDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ARMOR_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Armor Fossil"), //TODO 汉化
#else
                    _("Armor Fossil"),
#endif
                .itemId = ITEM_ARMOR_FOSSIL,
                .price = 7000,
                .description = sArmorFossilDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SKULL_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Skull Fossil"), //TODO 汉化
#else
                    _("Skull Fossil"),
#endif
                .itemId = ITEM_SKULL_FOSSIL,
                .price = 7000,
                .description = sSkullFossilDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_HELIX_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Helix Fossil"), //TODO 汉化
#else
                    _("Helix Fossil"),
#endif
                .itemId = ITEM_HELIX_FOSSIL,
                .description = sHelixFossilDesc,
#if I_KEY_FOSSILS >= GEN_4
                .price = 7000,
                .pocket = POCKET_ITEMS,
#else
                .price = 0,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
#endif
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DOME_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Dome Fossil"), //TODO 汉化
#else
                    _("Dome Fossil"),
#endif
                .itemId = ITEM_DOME_FOSSIL,
                .description = sDomeFossilDesc,
#if I_KEY_FOSSILS >= GEN_4
                .price = 7000,
                .pocket = POCKET_ITEMS,
#else
                .price = 0,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
#endif
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROOT_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Root Fossil"), //TODO 汉化
#else
                    _("Root Fossil"),
#endif
                .itemId = ITEM_ROOT_FOSSIL,
                .description = sRootFossilDesc,
#if I_KEY_FOSSILS >= GEN_4
                .price = 7000,
                .pocket = POCKET_ITEMS,
#else
                .price = 0,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
#endif
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CLAW_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Claw Fossil"), //TODO 汉化
#else
                    _("Claw Fossil"),
#endif
                .itemId = ITEM_CLAW_FOSSIL,
                .description = sClawFossilDesc,
#if I_KEY_FOSSILS >= GEN_4
                .price = 7000,
                .pocket = POCKET_ITEMS,
#else
                .price = 0,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
#endif
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_COVER_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Cover Fossil"), //TODO 汉化
#else
                    _("Cover Fossil"),
#endif
                .itemId = ITEM_COVER_FOSSIL,
                .price = 7000,
                .description = sCoverFossilDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PLUME_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Plume Fossil"), //TODO 汉化
#else
                    _("Plume Fossil"),
#endif
                .itemId = ITEM_PLUME_FOSSIL,
                .price = 7000,
                .description = sPlumeFossilDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_JAW_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Jaw Fossil"), //TODO 汉化
#else
                    _("Jaw Fossil"),
#endif
                .itemId = ITEM_JAW_FOSSIL,
                .price = 7000,
                .description = sJawFossilDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SAIL_FOSSIL] =
            {
                .name =
#ifdef CHINESE
                    _("Sail Fossil"), //TODO 汉化
#else
                    _("Sail Fossil"),
#endif
                .itemId = ITEM_SAIL_FOSSIL,
                .price = 7000,
                .description = sSailFossilDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SILPH_SCOPE] =
            {
                .name =
#ifdef CHINESE
                    _("Silph Scope"), //TODO 汉化
#else
                    _("Silph Scope"),
#endif
                .itemId = ITEM_SILPH_SCOPE,
                .price = 0,
                .description = sSilphScopeDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BICYCLE] =
            {
                .name =
#ifdef CHINESE
                    _("Bicycle"), //TODO 汉化
#else
                    _("Bicycle"),
#endif
                .itemId = ITEM_BICYCLE,
                .price = 0,
                .description = sBicycleDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TOWN_MAP] =
            {
                .name =
#ifdef CHINESE
                    _("Town Map"), //TODO 汉化
#else
                    _("Town Map"),
#endif
                .itemId = ITEM_TOWN_MAP,
                .price = 0,
                .description = sTownMapDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_VS_SEEKER] =
            {
                .name =
#ifdef CHINESE
                    _("Vs. Seeker"), //TODO 汉化
#else
                    _("Vs. Seeker"),
#endif
                .itemId = ITEM_VS_SEEKER,
                .price = 0,
                .description = sVSSeekerDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_FAME_CHECKER] =
            {
                .name =
#ifdef CHINESE
                    _("Fame Checker"), //TODO 汉化
#else
                    _("Fame Checker"),
#endif
                .itemId = ITEM_FAME_CHECKER,
                .price = 0,
                .description = sFameCheckerDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TM_CASE] =
            {
                .name =
#ifdef CHINESE
                    _("TM Case"), //TODO 汉化
#else
                    _("TM Case"),
#endif
                .itemId = ITEM_TM_CASE,
                .price = 0,
                .description = sTMCaseDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BERRY_POUCH] =
            {
                .name =
#ifdef CHINESE
                    _("Berry Pouch"), //TODO 汉化
#else
                    _("Berry Pouch"),
#endif
                .itemId = ITEM_BERRY_POUCH,
                .price = 0,
                .description = sBerryPouchDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TEACHY_TV] =
            {
                .name =
#ifdef CHINESE
                    _("Teachy TV"), //TODO 汉化
#else
                    _("Teachy TV"),
#endif
                .itemId = ITEM_TEACHY_TV,
                .price = 0,
                .description = sTeachyTVDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_FIELD,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TRI_PASS] =
            {
                .name =
#ifdef CHINESE
                    _("Tri-Pass"), //TODO 汉化
#else
                    _("Tri-Pass"),
#endif
                .itemId = ITEM_TRI_PASS,
                .price = 0,
                .description = sTriPassDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RAINBOW_PASS] =
            {
                .name =
#ifdef CHINESE
                    _("Rainbow Pass"), //TODO 汉化
#else
                    _("Rainbow Pass"),
#endif
                .itemId = ITEM_RAINBOW_PASS,
                .price = 0,
                .description = sRainbowPassDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TEA] =
            {
                .name =
#ifdef CHINESE
                    _("Tea"), //TODO 汉化
#else
                    _("Tea"),
#endif
                .itemId = ITEM_TEA,
                .price = 0,
                .description = sTeaDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MYSTIC_TICKET] =
            {
                .name =
#ifdef CHINESE
                    _("Mystic Ticket"), //TODO 汉化
#else
                    _("Mystic Ticket"),
#endif
                .itemId = ITEM_MYSTIC_TICKET,
                .price = 0,
                .description = sMysticTicketDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_AURORA_TICKET] =
            {
                .name =
#ifdef CHINESE
                    _("Aurora Ticket"), //TODO 汉化
#else
                    _("Aurora Ticket"),
#endif
                .itemId = ITEM_AURORA_TICKET,
                .price = 0,
                .description = sAuroraTicketDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_POWDER_JAR] =
            {
                .name =
#ifdef CHINESE
                    _("Powder Jar"), //TODO 汉化
#else
                    _("Powder Jar"),
#endif
                .itemId = ITEM_POWDER_JAR,
                .price = 0,
                .description = sPowderJarDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
            },

        [ITEM_RUBY] =
            {
                .name =
#ifdef CHINESE
                    _("Ruby"), //TODO 汉化
#else
                    _("Ruby"),
#endif
                .itemId = ITEM_RUBY,
                .price = 0,
                .description = sRubyDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SAPPHIRE] =
            {
                .name =
#ifdef CHINESE
                    _("Sapphire"), //TODO 汉化
#else
                    _("Sapphire"),
#endif
                .itemId = ITEM_SAPPHIRE,
                .price = 0,
                .description = sSapphireDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        // Emerald-specific key items

        [ITEM_MAGMA_EMBLEM] =
            {
                .name =
#ifdef CHINESE
                    _("Magma Emblem"), //TODO 汉化
#else
                    _("Magma Emblem"),
#endif
                .itemId = ITEM_MAGMA_EMBLEM,
                .price = 0,
                .description = sMagmaEmblemDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_OLD_SEA_MAP] =
            {
                .name =
#ifdef CHINESE
                    _("Old Sea Map"), //TODO 汉化
#else
                    _("Old Sea Map"),
#endif
                .itemId = ITEM_OLD_SEA_MAP,
                .price = 0,
                .description = sOldSeaMapDesc,
                .importance = 1,
                .unk19 = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        // New items

        [ITEM_WIDE_LENS] =
            {
                .name =
#ifdef CHINESE
                    _("Wide Lens"), //TODO 汉化
#else
                    _("Wide Lens"),
#endif
                .itemId = ITEM_WIDE_LENS,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_WIDE_LENS,
                .holdEffectParam = 10,
                .description = sWideLensDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MUSCLE_BAND] =
            {
                .name =
#ifdef CHINESE
                    _("Muscle Band"), //TODO 汉化
#else
                    _("Muscle Band"),
#endif
                .itemId = ITEM_MUSCLE_BAND,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_MUSCLE_BAND,
                .holdEffectParam = 10,
                .description = sMuscleBandDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WISE_GLASSES] =
            {
                .name =
#ifdef CHINESE
                    _("Wise Glasses"), //TODO 汉化
#else
                    _("Wise Glasses"),
#endif
                .itemId = ITEM_WISE_GLASSES,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_WISE_GLASSES,
                .holdEffectParam = 10,
                .description = sWiseGlassesDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_EXPERT_BELT] =
            {
                .name =
#ifdef CHINESE
                    _("Expert Belt"), //TODO 汉化
#else
                    _("Expert Belt"),
#endif
                .itemId = ITEM_EXPERT_BELT,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_EXPERT_BELT,
                .holdEffectParam = 20,
                .description = sExpertBeltDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LIGHT_CLAY] =
            {
                .name =
#ifdef CHINESE
                    _("Light Clay"), //TODO 汉化
#else
                    _("Light Clay"),
#endif
                .itemId = ITEM_LIGHT_CLAY,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_LIGHT_CLAY,
                .description = sLightClayDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LIFE_ORB] =
            {
                .name =
#ifdef CHINESE
                    _("Life Orb"), //TODO 汉化
#else
                    _("Life Orb"),
#endif
                .itemId = ITEM_LIFE_ORB,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_LIFE_ORB,
                .description = sLifeOrbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_POWER_HERB] =
            {
                .name =
#ifdef CHINESE
                    _("Power Herb"), //TODO 汉化
#else
                    _("Power Herb"),
#endif
                .itemId = ITEM_POWER_HERB,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_POWER_HERB,
                .description = sPowerHerbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TOXIC_ORB] =
            {
                .name =
#ifdef CHINESE
                    _("Toxic Orb"), //TODO 汉化
#else
                    _("Toxic Orb"),
#endif
                .itemId = ITEM_TOXIC_ORB,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_TOXIC_ORB,
                .description = sToxicOrbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_FLAME_ORB] =
            {
                .name =
#ifdef CHINESE
                    _("Flame Orb"), //TODO 汉化
#else
                    _("Flame Orb"),
#endif
                .itemId = ITEM_FLAME_ORB,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_FLAME_ORB,
                .description = sFlameOrbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_QUICK_POWDER] =
            {
                .name =
#ifdef CHINESE
                    _("Quick Powder"), //TODO 汉化
#else
                    _("Quick Powder"),
#endif
                .itemId = ITEM_QUICK_POWDER,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_QUICK_POWDER,
                .description = sQuickPowderDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_FOCUS_SASH] =
            {
                .name =
#ifdef CHINESE
                    _("Focus Sash"), //TODO 汉化
#else
                    _("Focus Sash"),
#endif
                .itemId = ITEM_FOCUS_SASH,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_FOCUS_SASH,
                .description = sFocusSashDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ZOOM_LENS] =
            {
                .name =
#ifdef CHINESE
                    _("Zoom Lens"), //TODO 汉化
#else
                    _("Zoom Lens"),
#endif
                .itemId = ITEM_ZOOM_LENS,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_ZOOM_LENS,
                .holdEffectParam = 20,
                .description = sZoomLensDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_METRONOME] =
            {
                .name =
#ifdef CHINESE
                    _("Metronome"), //TODO 汉化
#else
                    _("Metronome"),
#endif
                .itemId = ITEM_METRONOME,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_METRONOME,
                .holdEffectParam = 20,
                .description = sMetronomeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_IRON_BALL] =
            {
                .name =
#ifdef CHINESE
                    _("Iron Ball"), //TODO 汉化
#else
                    _("Iron Ball"),
#endif
                .itemId = ITEM_IRON_BALL,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_IRON_BALL,
                .description = sIronBallDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LAGGING_TAIL] =
            {
                .name =
#ifdef CHINESE
                    _("Lagging Tail"), //TODO 汉化
#else
                    _("Lagging Tail"),
#endif
                .itemId = ITEM_LAGGING_TAIL,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
                .description = sLaggingTailDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DESTINY_KNOT] =
            {
                .name =
#ifdef CHINESE
                    _("Destiny Knot"), //TODO 汉化
#else
                    _("Destiny Knot"),
#endif
                .itemId = ITEM_DESTINY_KNOT,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_DESTINY_KNOT,
                .description = sDestinyKnotDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLACK_SLUDGE] =
            {
                .name =
#ifdef CHINESE
                    _("Black Sludge"), //TODO 汉化
#else
                    _("Black Sludge"),
#endif
                .itemId = ITEM_BLACK_SLUDGE,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_BLACK_SLUDGE,
                .description = sBlackSludgeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ICY_ROCK] =
            {
                .name =
#ifdef CHINESE
                    _("Icy Rock"), //TODO 汉化
#else
                    _("Icy Rock"),
#endif
                .itemId = ITEM_ICY_ROCK,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_ICY_ROCK,
                .description = sIcyRockDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SMOOTH_ROCK] =
            {
                .name =
#ifdef CHINESE
                    _("Smooth Rock"), //TODO 汉化
#else
                    _("Smooth Rock"),
#endif
                .itemId = ITEM_SMOOTH_ROCK,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SMOOTH_ROCK,
                .description = sSmoothRockDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_HEAT_ROCK] =
            {
                .name =
#ifdef CHINESE
                    _("Heat Rock"), //TODO 汉化
#else
                    _("Heat Rock"),
#endif
                .itemId = ITEM_HEAT_ROCK,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_HEAT_ROCK,
                .description = sHeatRockDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DAMP_ROCK] =
            {
                .name =
#ifdef CHINESE
                    _("Damp Rock"), //TODO 汉化
#else
                    _("Damp Rock"),
#endif
                .itemId = ITEM_DAMP_ROCK,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_DAMP_ROCK,
                .description = sDampRockDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GRIP_CLAW] =
            {
                .name =
#ifdef CHINESE
                    _("Grip Claw"), //TODO 汉化
#else
                    _("Grip Claw"),
#endif
                .itemId = ITEM_GRIP_CLAW,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GRIP_CLAW,
                .description = sGripClawDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CHOICE_SCARF] =
            {
                .name =
#ifdef CHINESE
                    _("Choice Scarf"), //TODO 汉化
#else
                    _("Choice Scarf"),
#endif
                .itemId = ITEM_CHOICE_SCARF,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_CHOICE_SCARF,
                .description = sChoiceScarfDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_STICKY_BARB] =
            {
                .name =
#ifdef CHINESE
                    _("Sticky Barb"), //TODO 汉化
#else
                    _("Sticky Barb"),
#endif
                .itemId = ITEM_STICKY_BARB,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_STICKY_BARB,
                .description = sStickyBarbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SHED_SHELL] =
            {
                .name =
#ifdef CHINESE
                    _("Shed Shell"), //TODO 汉化
#else
                    _("Shed Shell"),
#endif
                .itemId = ITEM_SHED_SHELL,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SHED_SHELL,
                .description = sShedShellDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BIG_ROOT] =
            {
                .name =
#ifdef CHINESE
                    _("Big Root"), //TODO 汉化
#else
                    _("Big Root"),
#endif
                .itemId = ITEM_BIG_ROOT,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_BIG_ROOT,
                .holdEffectParam = 30,
                .description = sBigRootDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CHOICE_SPECS] =
            {
                .name =
#ifdef CHINESE
                    _("Choice Specs"), //TODO 汉化
#else
                    _("Choice Specs"),
#endif
                .itemId = ITEM_CHOICE_SPECS,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_CHOICE_SPECS,
                .description = sChoiceSpecsDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ODD_KEYSTONE] =
            {
                .name =
#ifdef CHINESE
                    _("Odd Keystone"), //TODO 汉化
#else
                    _("Odd Keystone"),
#endif
                .itemId = ITEM_ODD_KEYSTONE,
                .price = 2100,
                .description = sOddKeystoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ADAMANT_ORB] =
            {
                .name =
#ifdef CHINESE
                    _("Adamant Orb"), //TODO 汉化
#else
                    _("Adamant Orb"),
#endif
                .itemId = ITEM_ADAMANT_ORB,
                .price = 0,
                .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
                .description = sAdamantOrbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LUSTROUS_ORB] =
            {
                .name =
#ifdef CHINESE
                    _("Lustrous Orb"), //TODO 汉化
#else
                    _("Lustrous Orb"),
#endif
                .itemId = ITEM_LUSTROUS_ORB,
                .price = 0,
                .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
                .description = sLustrousOrbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GRISEOUS_ORB] =
            {
                .name =
#ifdef CHINESE
                    _("Griseous Orb"), //TODO 汉化
#else
                    _("Griseous Orb"),
#endif
                .itemId = ITEM_GRISEOUS_ORB,
                .price = 0,
                .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
                .description = sGriseousOrbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GRACIDEA] =
            {
                .name =
#ifdef CHINESE
                    _("Gracidea"), //TODO 汉化
#else
                    _("Gracidea"),
#endif
                .itemId = ITEM_GRACIDEA,
                .price = 0,
                .holdEffect = HOLD_EFFECT_GRACIDEA,
                .description = sGracideaDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BUG_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Bug Memory"), //TODO 汉化
#else
                    _("Bug Memory"),
#endif
                .itemId = ITEM_BUG_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sBugMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_BUG,
            },

        [ITEM_DARK_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Dark Memory"), //TODO 汉化
#else
                    _("Dark Memory"),
#endif
                .itemId = ITEM_DARK_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sDarkMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_DARK,
            },

        [ITEM_DRAGON_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Dragon Memory"), //TODO 汉化
#else
                    _("Dragon Memory"),
#endif
                .itemId = ITEM_DRAGON_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sDragonMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_DRAGON,
            },

        [ITEM_ELECTRIC_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("ElectrcMemory"), //TODO 汉化
#else
                    _("ElectrcMemory"),
#endif
                .itemId = ITEM_ELECTRIC_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sElectricMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ELECTRIC,
            },

        [ITEM_FAIRY_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Fairy Memory"), //TODO 汉化
#else
                    _("Fairy Memory"),
#endif
                .itemId = ITEM_FAIRY_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sFairyMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FAIRY,
            },

        [ITEM_FIGHTING_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("FightngMemory"), //TODO 汉化
#else
                    _("FightngMemory"),
#endif
                .itemId = ITEM_FIGHTING_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sFightingMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FIGHTING,
            },

        [ITEM_FIRE_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Fire Memory"), //TODO 汉化
#else
                    _("Fire Memory"),
#endif
                .itemId = ITEM_FIRE_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sFireMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FIRE,
            },

        [ITEM_FLYING_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Flying Memory"), //TODO 汉化
#else
                    _("Flying Memory"),
#endif
                .itemId = ITEM_FLYING_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sFlyingMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FLYING,
            },

        [ITEM_GHOST_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Ghost Memory"), //TODO 汉化
#else
                    _("Ghost Memory"),
#endif
                .itemId = ITEM_GHOST_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sGhostMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GHOST,
            },

        [ITEM_GRASS_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Grass Memory"), //TODO 汉化
#else
                    _("Grass Memory"),
#endif
                .itemId = ITEM_GRASS_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sGrassMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GRASS,
            },

        [ITEM_GROUND_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Ground Memory"), //TODO 汉化
#else
                    _("Ground Memory"),
#endif
                .itemId = ITEM_GROUND_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sGroundMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GROUND,
            },

        [ITEM_ICE_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Ice Memory"), //TODO 汉化
#else
                    _("Ice Memory"),
#endif
                .itemId = ITEM_ICE_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sIceMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ICE,
            },

        [ITEM_POISON_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Poison Memory"), //TODO 汉化
#else
                    _("Poison Memory"),
#endif
                .itemId = ITEM_POISON_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sPoisonMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_POISON,
            },

        [ITEM_PSYCHIC_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("PsychicMemory"), //TODO 汉化
#else
                    _("PsychicMemory"),
#endif
                .itemId = ITEM_PSYCHIC_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sPsychicMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_PSYCHIC,
            },

        [ITEM_ROCK_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Rock Memory"), //TODO 汉化
#else
                    _("Rock Memory"),
#endif
                .itemId = ITEM_ROCK_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sRockMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ROCK,
            },

        [ITEM_STEEL_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Steel Memory"), //TODO 汉化
#else
                    _("Steel Memory"),
#endif
                .itemId = ITEM_STEEL_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sSteelMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_STEEL,
            },

        [ITEM_WATER_MEMORY] =
            {
                .name =
#ifdef CHINESE
                    _("Water Memory"), //TODO 汉化
#else
                    _("Water Memory"),
#endif
                .itemId = ITEM_WATER_MEMORY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_MEMORY,
                .holdEffectParam = 0,
                .description = sWaterMemoryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_WATER,
            },

        [ITEM_FLAME_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Flame Plate"), //TODO 汉化
#else
                    _("Flame Plate"),
#endif
                .itemId = ITEM_FLAME_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sFlamePlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FIRE,
            },

        [ITEM_SPLASH_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Splash Plate"), //TODO 汉化
#else
                    _("Splash Plate"),
#endif
                .itemId = ITEM_SPLASH_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sSplashPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_WATER,
            },

        [ITEM_ZAP_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Zap Plate"), //TODO 汉化
#else
                    _("Zap Plate"),
#endif
                .itemId = ITEM_ZAP_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sZapPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ELECTRIC,
            },

        [ITEM_MEADOW_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Meadow Plate"), //TODO 汉化
#else
                    _("Meadow Plate"),
#endif
                .itemId = ITEM_MEADOW_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sMeadowPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GRASS,
            },

        [ITEM_ICICLE_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Icicle Plate"), //TODO 汉化
#else
                    _("Icicle Plate"),
#endif
                .itemId = ITEM_ICICLE_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sIciclePlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ICE,
            },

        [ITEM_FIST_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Fist Plate"), //TODO 汉化
#else
                    _("Fist Plate"),
#endif
                .itemId = ITEM_FIST_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sFistPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FIGHTING,
            },

        [ITEM_TOXIC_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Toxic Plate"), //TODO 汉化
#else
                    _("Toxic Plate"),
#endif
                .itemId = ITEM_TOXIC_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sToxicPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_POISON,
            },

        [ITEM_EARTH_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Earth Plate"), //TODO 汉化
#else
                    _("Earth Plate"),
#endif
                .itemId = ITEM_EARTH_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sEarthPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GROUND,
            },

        [ITEM_SKY_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Sky Plate"), //TODO 汉化
#else
                    _("Sky Plate"),
#endif
                .itemId = ITEM_SKY_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sSkyPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FLYING,
            },

        [ITEM_MIND_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Mind Plate"), //TODO 汉化
#else
                    _("Mind Plate"),
#endif
                .itemId = ITEM_MIND_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sMindPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_PSYCHIC,
            },

        [ITEM_INSECT_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Insect Plate"), //TODO 汉化
#else
                    _("Insect Plate"),
#endif
                .itemId = ITEM_INSECT_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sInsectPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_BUG,
            },

        [ITEM_STONE_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Stone Plate"), //TODO 汉化
#else
                    _("Stone Plate"),
#endif
                .itemId = ITEM_STONE_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sStonePlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ROCK,
            },

        [ITEM_SPOOKY_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Spooky Plate"), //TODO 汉化
#else
                    _("Spooky Plate"),
#endif
                .itemId = ITEM_SPOOKY_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sSpookyPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GHOST,
            },

        [ITEM_DRACO_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Draco Plate"), //TODO 汉化
#else
                    _("Draco Plate"),
#endif
                .itemId = ITEM_DRACO_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sDracoPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_DRAGON,
            },

        [ITEM_DREAD_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Dread Plate"), //TODO 汉化
#else
                    _("Dread Plate"),
#endif
                .itemId = ITEM_DREAD_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sDreadPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_DARK,
            },

        [ITEM_IRON_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Iron Plate"), //TODO 汉化
#else
                    _("Iron Plate"),
#endif
                .itemId = ITEM_IRON_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sIronPlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_STEEL,
            },

        [ITEM_EVIOLITE] =
            {
                .name =
#ifdef CHINESE
                    _("Eviolite"), //TODO 汉化
#else
                    _("Eviolite"),
#endif
                .itemId = ITEM_EVIOLITE,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_EVIOLITE,
                .holdEffectParam = 50,
                .description = sEvioliteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_FLOAT_STONE] =
            {
                .name =
#ifdef CHINESE
                    _("Float Stone"), //TODO 汉化
#else
                    _("Float Stone"),
#endif
                .itemId = ITEM_FLOAT_STONE,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_FLOAT_STONE,
                .description = sFloatStoneDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ROCKY_HELMET] =
            {
                .name =
#ifdef CHINESE
                    _("Rocky Helmet"), //TODO 汉化
#else
                    _("Rocky Helmet"),
#endif
                .itemId = ITEM_ROCKY_HELMET,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_ROCKY_HELMET,
                .holdEffectParam = 0,
                .description = sRockyHelmetDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_AIR_BALLOON] =
            {
                .name =
#ifdef CHINESE
                    _("Air Balloon"), //TODO 汉化
#else
                    _("Air Balloon"),
#endif
                .itemId = ITEM_AIR_BALLOON,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_AIR_BALLOON,
                .holdEffectParam = 0,
                .description = sAirBalloonDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RED_CARD] =
            {
                .name =
#ifdef CHINESE
                    _("Red Card"), //TODO 汉化
#else
                    _("Red Card"),
#endif
                .itemId = ITEM_RED_CARD,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_RED_CARD,
                .holdEffectParam = 0,
                .description = sRedCardDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_RING_TARGET] =
            {
                .name =
#ifdef CHINESE
                    _("Ring Target"), //TODO 汉化
#else
                    _("Ring Target"),
#endif
                .itemId = ITEM_RING_TARGET,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_RING_TARGET,
                .holdEffectParam = 0,
                .description = sRingTargetDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BINDING_BAND] =
            {
                .name =
#ifdef CHINESE
                    _("Binding Band"), //TODO 汉化
#else
                    _("Binding Band"),
#endif
                .itemId = ITEM_BINDING_BAND,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_BINDING_BAND,
                .description = sBindingBandDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_EJECT_BUTTON] =
            {
                .name =
#ifdef CHINESE
                    _("Eject Button"), //TODO 汉化
#else
                    _("Eject Button"),
#endif
                .itemId = ITEM_EJECT_BUTTON,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_EJECT_BUTTON,
                .holdEffectParam = 0,
                .description = sEjectButtonDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ABSORB_BULB] =
            {
                .name =
#ifdef CHINESE
                    _("Absorb Bulb"), //TODO 汉化
#else
                    _("Absorb Bulb"),
#endif
                .itemId = ITEM_ABSORB_BULB,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_ABSORB_BULB,
                .holdEffectParam = 0,
                .description = sAbsorbBulbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CELL_BATTERY] =
            {
                .name =
#ifdef CHINESE
                    _("Cell Battery"), //TODO 汉化
#else
                    _("Cell Battery"),
#endif
                .itemId = ITEM_CELL_BATTERY,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_CELL_BATTERY,
                .holdEffectParam = 0,
                .description = sCellBatteryDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LUMINOUS_MOSS] =
            {
                .name =
#ifdef CHINESE
                    _("Luminous Moss"), //TODO 汉化
#else
                    _("Luminous Moss"),
#endif
                .itemId = ITEM_LUMINOUS_MOSS,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_LUMINOUS_MOSS,
                .holdEffectParam = 0,
                .description = sLuminousMossDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SNOWBALL] =
            {
                .name =
#ifdef CHINESE
                    _("Snowball"), //TODO 汉化
#else
                    _("Snowball"),
#endif
                .itemId = ITEM_SNOWBALL,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SNOWBALL,
                .holdEffectParam = 0,
                .description = sSnowballDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_WEAKNESS_POLICY] =
            {
                .name =
#ifdef CHINESE
                    _("WeaknssPolicy"), //TODO 汉化
#else
                    _("WeaknssPolicy"),
#endif
                .itemId = ITEM_WEAKNESS_POLICY,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_WEAKNESS_POLICY,
                .holdEffectParam = 0,
                .description = sWeaknessPolicyDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DOUSE_DRIVE] =
            {
                .name =
#ifdef CHINESE
                    _("Douse Drive"), //TODO 汉化
#else
                    _("Douse Drive"),
#endif
                .itemId = ITEM_DOUSE_DRIVE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_DRIVE,
                .description = sDouseDriveDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_WATER,
            },

        [ITEM_SHOCK_DRIVE] =
            {
                .name =
#ifdef CHINESE
                    _("Shock Drive"), //TODO 汉化
#else
                    _("Shock Drive"),
#endif
                .itemId = ITEM_SHOCK_DRIVE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_DRIVE,
                .description = sShockDriveDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ELECTRIC,
            },

        [ITEM_BURN_DRIVE] =
            {
                .name =
#ifdef CHINESE
                    _("Burn Drive"), //TODO 汉化
#else
                    _("Burn Drive"),
#endif
                .itemId = ITEM_BURN_DRIVE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_DRIVE,
                .description = sBurnDriveDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FIRE,
            },

        [ITEM_CHILL_DRIVE] =
            {
                .name =
#ifdef CHINESE
                    _("Chill Drive"), //TODO 汉化
#else
                    _("Chill Drive"),
#endif
                .itemId = ITEM_CHILL_DRIVE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_DRIVE,
                .description = sChillDriveDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ICE,
            },

        [ITEM_FIRE_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Fire Gem"), //TODO 汉化
#else
                    _("Fire Gem"),
#endif
                .itemId = ITEM_FIRE_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sFireGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FIRE,
            },

        [ITEM_WATER_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Water Gem"), //TODO 汉化
#else
                    _("Water Gem"),
#endif
                .itemId = ITEM_WATER_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sWaterGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_WATER,
            },

        [ITEM_ELECTRIC_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Electric Gem"), //TODO 汉化
#else
                    _("Electric Gem"),
#endif
                .itemId = ITEM_ELECTRIC_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sElectricGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ELECTRIC,
            },

        [ITEM_GRASS_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Grass Gem"), //TODO 汉化
#else
                    _("Grass Gem"),
#endif
                .itemId = ITEM_GRASS_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sGrassGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GRASS,
            },

        [ITEM_ICE_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Ice Gem"), //TODO 汉化
#else
                    _("Ice Gem"),
#endif
                .itemId = ITEM_ICE_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sIceGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ICE,
            },

        [ITEM_FIGHTING_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Fighting Gem"), //TODO 汉化
#else
                    _("Fighting Gem"),
#endif
                .itemId = ITEM_FIGHTING_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sFightingGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FIGHTING,
            },

        [ITEM_POISON_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Poison Gem"), //TODO 汉化
#else
                    _("Poison Gem"),
#endif
                .itemId = ITEM_POISON_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sPoisonGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_POISON,
            },

        [ITEM_GROUND_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Ground Gem"), //TODO 汉化
#else
                    _("Ground Gem"),
#endif
                .itemId = ITEM_GROUND_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sGroundGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GROUND,
            },

        [ITEM_FLYING_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Flying Gem"), //TODO 汉化
#else
                    _("Flying Gem"),
#endif
                .itemId = ITEM_FLYING_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sFlyingGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FLYING,
            },

        [ITEM_PSYCHIC_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Psychic Gem"), //TODO 汉化
#else
                    _("Psychic Gem"),
#endif
                .itemId = ITEM_PSYCHIC_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sPsychicGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_PSYCHIC,
            },

        [ITEM_BUG_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Bug Gem"), //TODO 汉化
#else
                    _("Bug Gem"),
#endif
                .itemId = ITEM_BUG_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sBugGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_BUG,
            },

        [ITEM_ROCK_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Rock Gem"), //TODO 汉化
#else
                    _("Rock Gem"),
#endif
                .itemId = ITEM_ROCK_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sRockGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ROCK,
            },

        [ITEM_GHOST_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Ghost Gem"), //TODO 汉化
#else
                    _("Ghost Gem"),
#endif
                .itemId = ITEM_GHOST_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sGhostGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GHOST,
            },

        [ITEM_DRAGON_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Dragon Gem"), //TODO 汉化
#else
                    _("Dragon Gem"),
#endif
                .itemId = ITEM_DRAGON_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sDragonGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_DRAGON,
            },

        [ITEM_DARK_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Dark Gem"), //TODO 汉化
#else
                    _("Dark Gem"),
#endif
                .itemId = ITEM_DARK_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sDarkGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_DARK,
            },

        [ITEM_STEEL_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Steel Gem"), //TODO 汉化
#else
                    _("Steel Gem"),
#endif
                .itemId = ITEM_STEEL_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sSteelGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_STEEL,
            },

        [ITEM_NORMAL_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Normal Gem"), //TODO 汉化
#else
                    _("Normal Gem"),
#endif
                .itemId = ITEM_NORMAL_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sNormalGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_NORMAL,
            },

        [ITEM_FAIRY_GEM] =
            {
                .name =
#ifdef CHINESE
                    _("Fairy Gem"), //TODO 汉化
#else
                    _("Fairy Gem"),
#endif
                .itemId = ITEM_FAIRY_GEM,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_GEMS,
                .holdEffectParam = 30,
                .description = sFairyGemDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FAIRY,
            },

        [ITEM_ASSAULT_VEST] =
            {
                .name =
#ifdef CHINESE
                    _("Assault Vest"), //TODO 汉化
#else
                    _("Assault Vest"),
#endif
                .itemId = ITEM_ASSAULT_VEST,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_ASSAULT_VEST,
                .holdEffectParam = 50,
                .description = sAssaultVestDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PIXIE_PLATE] =
            {
                .name =
#ifdef CHINESE
                    _("Pixie Plate"), //TODO 汉化
#else
                    _("Pixie Plate"),
#endif
                .itemId = ITEM_PIXIE_PLATE,
                .price = 1000,
                .holdEffect = HOLD_EFFECT_PLATE,
                .holdEffectParam = 20,
                .description = sPixiePlateDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FAIRY,
            },

        [ITEM_SAFETY_GOGGLES] =
            {
                .name =
#ifdef CHINESE
                    _("SafetyGoggles"), //TODO 汉化
#else
                    _("SafetyGoggles"),
#endif
                .itemId = ITEM_SAFETY_GOGGLES,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SAFETY_GOOGLES,
                .description = sSafetyGogglesDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GENGARITE] =
            {
                .name =
#ifdef CHINESE
                    _("Gengarite"), //TODO 汉化
#else
                    _("Gengarite"),
#endif
                .itemId = ITEM_GENGARITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sGengariteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GARDEVOIRITE] =
            {
                .name =
#ifdef CHINESE
                    _("Gardevoirite"), //TODO 汉化
#else
                    _("Gardevoirite"),
#endif
                .itemId = ITEM_GARDEVOIRITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sGardevoiriteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_AMPHAROSITE] =
            {
                .name =
#ifdef CHINESE
                    _("Ampharosite"), //TODO 汉化
#else
                    _("Ampharosite"),
#endif
                .itemId = ITEM_AMPHAROSITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sAmpharositeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_VENUSAURITE] =
            {
                .name =
#ifdef CHINESE
                    _("Venusaurite"), //TODO 汉化
#else
                    _("Venusaurite"),
#endif
                .itemId = ITEM_VENUSAURITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sVenusauriteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CHARIZARDITE_X] =
            {
                .name =
#ifdef CHINESE
                    _("CharizarditeX"), //TODO 汉化
#else
                    _("CharizarditeX"),
#endif
                .itemId = ITEM_CHARIZARDITE_X,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sCharizarditeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLASTOISINITE] =
            {
                .name =
#ifdef CHINESE
                    _("Blastoisinite"), //TODO 汉化
#else
                    _("Blastoisinite"),
#endif
                .itemId = ITEM_BLASTOISINITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sBlastoisiniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MEWTWONITE_X] =
            {
                .name =
#ifdef CHINESE
                    _("Mewtwonite X"), //TODO 汉化
#else
                    _("Mewtwonite X"),
#endif
                .itemId = ITEM_MEWTWONITE_X,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sMewtwoniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MEWTWONITE_Y] =
            {
                .name =
#ifdef CHINESE
                    _("Mewtwonite Y"), //TODO 汉化
#else
                    _("Mewtwonite Y"),
#endif
                .itemId = ITEM_MEWTWONITE_Y,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sMewtwoniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BLAZIKENITE] =
            {
                .name =
#ifdef CHINESE
                    _("Blazikenite"), //TODO 汉化
#else
                    _("Blazikenite"),
#endif
                .itemId = ITEM_BLAZIKENITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sBlazikeniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MEDICHAMITE] =
            {
                .name =
#ifdef CHINESE
                    _("Medichamite"), //TODO 汉化
#else
                    _("Medichamite"),
#endif
                .itemId = ITEM_MEDICHAMITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sMedichamiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_HOUNDOOMINITE] =
            {
                .name =
#ifdef CHINESE
                    _("Houndoominite"), //TODO 汉化
#else
                    _("Houndoominite"),
#endif
                .itemId = ITEM_HOUNDOOMINITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sHoundoominiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_AGGRONITE] =
            {
                .name =
#ifdef CHINESE
                    _("Aggronite"), //TODO 汉化
#else
                    _("Aggronite"),
#endif
                .itemId = ITEM_AGGRONITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sAggroniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BANETTITE] =
            {
                .name =
#ifdef CHINESE
                    _("Banettite"), //TODO 汉化
#else
                    _("Banettite"),
#endif
                .itemId = ITEM_BANETTITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sBanettiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TYRANITARITE] =
            {
                .name =
#ifdef CHINESE
                    _("Tyranitarite"), //TODO 汉化
#else
                    _("Tyranitarite"),
#endif
                .itemId = ITEM_TYRANITARITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sTyranitariteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SCIZORITE] =
            {
                .name =
#ifdef CHINESE
                    _("Scizorite"), //TODO 汉化
#else
                    _("Scizorite"),
#endif
                .itemId = ITEM_SCIZORITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sScizoriteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PINSIRITE] =
            {
                .name =
#ifdef CHINESE
                    _("Pinsirite"), //TODO 汉化
#else
                    _("Pinsirite"),
#endif
                .itemId = ITEM_PINSIRITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sPinsiriteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_AERODACTYLITE] =
            {
                .name =
#ifdef CHINESE
                    _("Aerodactylite"), //TODO 汉化
#else
                    _("Aerodactylite"),
#endif
                .itemId = ITEM_AERODACTYLITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sAerodactyliteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LUCARIONITE] =
            {
                .name =
#ifdef CHINESE
                    _("Lucarionite"), //TODO 汉化
#else
                    _("Lucarionite"),
#endif
                .itemId = ITEM_LUCARIONITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sLucarioniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ABOMASITE] =
            {
                .name =
#ifdef CHINESE
                    _("Abomasite"), //TODO 汉化
#else
                    _("Abomasite"),
#endif
                .itemId = ITEM_ABOMASITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sAbomasiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_KANGASKHANITE] =
            {
                .name =
#ifdef CHINESE
                    _("Kangaskhanite"), //TODO 汉化
#else
                    _("Kangaskhanite"),
#endif
                .itemId = ITEM_KANGASKHANITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sKangaskhaniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GYARADOSITE] =
            {
                .name =
#ifdef CHINESE
                    _("Gyaradosite"), //TODO 汉化
#else
                    _("Gyaradosite"),
#endif
                .itemId = ITEM_GYARADOSITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sGyaradositeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ABSOLITE] =
            {
                .name =
#ifdef CHINESE
                    _("Absolite"), //TODO 汉化
#else
                    _("Absolite"),
#endif
                .itemId = ITEM_ABSOLITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sAbsoliteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CHARIZARDITE_Y] =
            {
                .name =
#ifdef CHINESE
                    _("CharizarditeY"), //TODO 汉化
#else
                    _("CharizarditeY"),
#endif
                .itemId = ITEM_CHARIZARDITE_Y,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sCharizarditeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ALAKAZITE] =
            {
                .name =
#ifdef CHINESE
                    _("Alakazite"), //TODO 汉化
#else
                    _("Alakazite"),
#endif
                .itemId = ITEM_ALAKAZITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sAlakaziteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_HERACRONITE] =
            {
                .name =
#ifdef CHINESE
                    _("Heracronite"), //TODO 汉化
#else
                    _("Heracronite"),
#endif
                .itemId = ITEM_HERACRONITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sHeracroniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MAWILITE] =
            {
                .name =
#ifdef CHINESE
                    _("Mawilite"), //TODO 汉化
#else
                    _("Mawilite"),
#endif
                .itemId = ITEM_MAWILITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sMawiliteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MANECTITE] =
            {
                .name =
#ifdef CHINESE
                    _("Manectite"), //TODO 汉化
#else
                    _("Manectite"),
#endif
                .itemId = ITEM_MANECTITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sManectiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GARCHOMPITE] =
            {
                .name =
#ifdef CHINESE
                    _("Garchompite"), //TODO 汉化
#else
                    _("Garchompite"),
#endif
                .itemId = ITEM_GARCHOMPITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sGarchompiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LATIASITE] =
            {
                .name =
#ifdef CHINESE
                    _("Latiasite"), //TODO 汉化
#else
                    _("Latiasite"),
#endif
                .itemId = ITEM_LATIASITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sLatiasiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LATIOSITE] =
            {
                .name =
#ifdef CHINESE
                    _("Latiosite"), //TODO 汉化
#else
                    _("Latiosite"),
#endif
                .itemId = ITEM_LATIOSITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sLatiositeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SWAMPERTITE] =
            {
                .name =
#ifdef CHINESE
                    _("Swampertite"), //TODO 汉化
#else
                    _("Swampertite"),
#endif
                .itemId = ITEM_SWAMPERTITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sSwampertiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SCEPTILITE] =
            {
                .name =
#ifdef CHINESE
                    _("Sceptilite"), //TODO 汉化
#else
                    _("Sceptilite"),
#endif
                .itemId = ITEM_SCEPTILITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sSceptiliteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SABLENITE] =
            {
                .name =
#ifdef CHINESE
                    _("Sablenite"), //TODO 汉化
#else
                    _("Sablenite"),
#endif
                .itemId = ITEM_SABLENITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sSableniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ALTARIANITE] =
            {
                .name =
#ifdef CHINESE
                    _("Altarianite"), //TODO 汉化
#else
                    _("Altarianite"),
#endif
                .itemId = ITEM_ALTARIANITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sAltarianiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GALLADITE] =
            {
                .name =
#ifdef CHINESE
                    _("Galladite"), //TODO 汉化
#else
                    _("Galladite"),
#endif
                .itemId = ITEM_GALLADITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sGalladiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_AUDINITE] =
            {
                .name =
#ifdef CHINESE
                    _("Audinite"), //TODO 汉化
#else
                    _("Audinite"),
#endif
                .itemId = ITEM_AUDINITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sAudiniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_METAGROSSITE] =
            {
                .name =
#ifdef CHINESE
                    _("Metagrossite"), //TODO 汉化
#else
                    _("Metagrossite"),
#endif
                .itemId = ITEM_METAGROSSITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sMetagrossiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SHARPEDONITE] =
            {
                .name =
#ifdef CHINESE
                    _("Sharpedonite"), //TODO 汉化
#else
                    _("Sharpedonite"),
#endif
                .itemId = ITEM_SHARPEDONITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sSharpedoniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SLOWBRONITE] =
            {
                .name =
#ifdef CHINESE
                    _("Slowbronite"), //TODO 汉化
#else
                    _("Slowbronite"),
#endif
                .itemId = ITEM_SLOWBRONITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sSlowbroniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_STEELIXITE] =
            {
                .name =
#ifdef CHINESE
                    _("Steelixite"), //TODO 汉化
#else
                    _("Steelixite"),
#endif
                .itemId = ITEM_STEELIXITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sSteelixiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PIDGEOTITE] =
            {
                .name =
#ifdef CHINESE
                    _("Pidgeotite"), //TODO 汉化
#else
                    _("Pidgeotite"),
#endif
                .itemId = ITEM_PIDGEOTITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sPidgeotiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GLALITITE] =
            {
                .name =
#ifdef CHINESE
                    _("Glalitite"), //TODO 汉化
#else
                    _("Glalitite"),
#endif
                .itemId = ITEM_GLALITITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sGlalititeDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_DIANCITE] =
            {
                .name =
#ifdef CHINESE
                    _("Diancite"), //TODO 汉化
#else
                    _("Diancite"),
#endif
                .itemId = ITEM_DIANCITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sDianciteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_CAMERUPTITE] =
            {
                .name =
#ifdef CHINESE
                    _("Cameruptite"), //TODO 汉化
#else
                    _("Cameruptite"),
#endif
                .itemId = ITEM_CAMERUPTITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sCameruptiteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_LOPUNNITE] =
            {
                .name =
#ifdef CHINESE
                    _("Lopunnite"), //TODO 汉化
#else
                    _("Lopunnite"),
#endif
                .itemId = ITEM_LOPUNNITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sLopunniteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SALAMENCITE] =
            {
                .name =
#ifdef CHINESE
                    _("Salamencite"), //TODO 汉化
#else
                    _("Salamencite"),
#endif
                .itemId = ITEM_SALAMENCITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sSalamenciteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_BEEDRILLITE] =
            {
                .name =
#ifdef CHINESE
                    _("Beedrillite"), //TODO 汉化
#else
                    _("Beedrillite"),
#endif
                .itemId = ITEM_BEEDRILLITE,
                .price = 0,
                .holdEffect = HOLD_EFFECT_MEGA_STONE,
                .description = sBeedrilliteDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MEGA_BRACELET] =
            {
                .name =
#ifdef CHINESE
                    _("Mega Bracelet"), //TODO 汉化
#else
                    _("Mega Bracelet"),
#endif
                .itemId = ITEM_MEGA_BRACELET,
                .price = 0,
                .importance = 1,
                .description = sMegaBraceletDesc,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PROTECTIVE_PADS] =
            {
                .name =
#ifdef CHINESE
                    _("ProtectvePads"), //TODO 汉化
#else
                    _("ProtectvePads"),
#endif
                .itemId = ITEM_PROTECTIVE_PADS,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_PROTECTIVE_PADS,
                .description = sProtectPadsDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_TERRAIN_EXTENDER] =
            {
                .name =
#ifdef CHINESE
                    _("TerainExtendr"), //TODO 汉化
#else
                    _("TerainExtendr"),
#endif
                .itemId = ITEM_TERRAIN_EXTENDER,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_TERRAIN_EXTENDER,
                .description = sTerrainExtenderDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ELECTRIC_SEED] =
            {
                .name =
#ifdef CHINESE
                    _("Electric Seed"), //TODO 汉化
#else
                    _("Electric Seed"),
#endif
                .itemId = ITEM_ELECTRIC_SEED,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SEEDS,
                .description = sElectricSeedDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_GRASSY_SEED] =
            {
                .name =
#ifdef CHINESE
                    _("Grassy Seed"), //TODO 汉化
#else
                    _("Grassy Seed"),
#endif
                .itemId = ITEM_GRASSY_SEED,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SEEDS,
                .description = sGrassySeedDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_MISTY_SEED] =
            {
                .name =
#ifdef CHINESE
                    _("Misty Seed"), //TODO 汉化
#else
                    _("Misty Seed"),
#endif
                .itemId = ITEM_MISTY_SEED,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SEEDS,
                .description = sMistySeedDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_PSYCHIC_SEED] =
            {
                .name =
#ifdef CHINESE
                    _("Psychic Seed"), //TODO 汉化
#else
                    _("Psychic Seed"),
#endif
                .itemId = ITEM_PSYCHIC_SEED,
                .price = 4000,
                .holdEffect = HOLD_EFFECT_SEEDS,
                .description = sPsychicSeedDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_ADRENALINE_ORB] =
            {
                .name =
#ifdef CHINESE
                    _("AdrenalineOrb"), //TODO 汉化
#else
                    _("AdrenalineOrb"),
#endif
                .itemId = ITEM_ADRENALINE_ORB,
                .price = 300,
                .holdEffect = HOLD_EFFECT_ADRENALINE_ORB,
                .description = sAdrenalineOrbDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_HONEY] =
            {
                .name =
#ifdef CHINESE
                    _("Honey"), //TODO 汉化
#else
                    _("Honey"),
#endif
                .itemId = ITEM_HONEY,
                .price = 300,
                .description = sHoneyDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_HEALTH_FEATHER] =
            {
                .name =
#ifdef CHINESE
                    _("HealthFeather"), //TODO 汉化
#else
                    _("HealthFeather"),
#endif
                .itemId = ITEM_HEALTH_FEATHER,
                .price = 300,
                .description = sHealthFeatherDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_MUSCLE_FEATHER] =
            {
                .name =
#ifdef CHINESE
                    _("MuscleFeather"), //TODO 汉化
#else
                    _("MuscleFeather"),
#endif
                .itemId = ITEM_MUSCLE_FEATHER,
                .price = 300,
                .description = sMuscleFeatherDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_RESIST_FEATHER] =
            {
                .name =
#ifdef CHINESE
                    _("ResistFeather"), //TODO 汉化
#else
                    _("ResistFeather"),
#endif
                .itemId = ITEM_RESIST_FEATHER,
                .price = 300,
                .description = sResistFeatherDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_GENIUS_FEATHER] =
            {
                .name =
#ifdef CHINESE
                    _("GeniusFeather"), //TODO 汉化
#else
                    _("GeniusFeather"),
#endif
                .itemId = ITEM_GENIUS_FEATHER,
                .price = 300,
                .description = sGeniusFeatherDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_CLEVER_FEATHER] =
            {
                .name =
#ifdef CHINESE
                    _("CleverFeather"), //TODO 汉化
#else
                    _("CleverFeather"),
#endif
                .itemId = ITEM_CLEVER_FEATHER,
                .price = 300,
                .description = sCleverFeatherDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_SWIFT_FEATHER] =
            {
                .name =
#ifdef CHINESE
                    _("SwiftFeather"), //TODO 汉化
#else
                    _("SwiftFeather"),
#endif
                .itemId = ITEM_SWIFT_FEATHER,
                .price = 300,
                .description = sSwiftFeatherDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_PARTY_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_Medicine,
            },

        [ITEM_PRETTY_FEATHER] =
            {
                .name =
#ifdef CHINESE
                    _("PrettyFeather"), //TODO 汉化
#else
                    _("PrettyFeather"),
#endif
                .itemId = ITEM_PRETTY_FEATHER,
                .price = 1000,
                .description = sPrettyFeatherDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_SHINY_CHARM] =
            {
                .name =
#ifdef CHINESE
                    _("Shiny Charm"), //TODO 汉化
#else
                    _("Shiny Charm"),
#endif
                .itemId = ITEM_SHINY_CHARM,
                .price = 0,
                .importance = 1,
                .description = sShinyCharmDesc,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_OVAL_CHARM] =
            {
                .name =
#ifdef CHINESE
                    _("Oval Charm"), //TODO 汉化
#else
                    _("Oval Charm"),
#endif
                .itemId = ITEM_OVAL_CHARM,
                .price = 0,
                .importance = 1,
                .description = sOvalCharmDesc,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_Z_RING] =
            {
                .name =
#ifdef CHINESE
                    _("Z-Ring"), //TODO 汉化
#else
                    _("Z-Ring"),
#endif
                .itemId = ITEM_Z_RING,
                .price = 0,
                .holdEffect = HOLD_EFFECT_NONE,
                .description = sZRingDesc,
                .importance = 1,
                .pocket = POCKET_KEY_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
            },

        [ITEM_NORMALIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Normalium Z"), //TODO 汉化
#else
                    _("Normalium Z"),
#endif
                .itemId = ITEM_NORMALIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sNormaliumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_NORMAL},

        [ITEM_FIGHTINIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Fightinium Z"), //TODO 汉化
#else
                    _("Fightinium Z"),
#endif
                .itemId = ITEM_FIGHTINIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sFightiniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FIGHTING},

        [ITEM_FLYINIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Flyinium Z"), //TODO 汉化
#else
                    _("Flyinium Z"),
#endif
                .itemId = ITEM_FLYINIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sFlyiniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FLYING},

        [ITEM_POISONIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Poisinium Z"), //TODO 汉化
#else
                    _("Poisinium Z"),
#endif
                .itemId = ITEM_POISONIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sPoisoniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_POISON},

        [ITEM_GROUNDIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Groundium Z"), //TODO 汉化
#else
                    _("Groundium Z"),
#endif
                .itemId = ITEM_GROUNDIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sGroundiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GROUND},

        [ITEM_ROCKIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Rockium Z"), //TODO 汉化
#else
                    _("Rockium Z"),
#endif
                .itemId = ITEM_ROCKIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sRockiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ROCK},

        [ITEM_BUGINIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Buginium Z"), //TODO 汉化
#else
                    _("Buginium Z"),
#endif
                .itemId = ITEM_BUGINIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sBuginiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_BUG},

        [ITEM_GHOSTIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Ghostium Z"), //TODO 汉化
#else
                    _("Ghostium Z"),
#endif
                .itemId = ITEM_GHOSTIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sGhostiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GHOST},

        [ITEM_STEELIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Steelium Z"), //TODO 汉化
#else
                    _("Steelium Z"),
#endif
                .itemId = ITEM_STEELIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sSteeliumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_STEEL},

        [ITEM_FIRIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Firium Z"), //TODO 汉化
#else
                    _("Firium Z"),
#endif
                .itemId = ITEM_FIRIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sFiriumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FIRE},

        [ITEM_WATERIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Waterium Z"), //TODO 汉化
#else
                    _("Waterium Z"),
#endif
                .itemId = ITEM_WATERIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sWateriumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_WATER},

        [ITEM_GRASSIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Grassium Z"), //TODO 汉化
#else
                    _("Grassium Z"),
#endif
                .itemId = ITEM_GRASSIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sGrassiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_GRASS},

        [ITEM_ELECTRIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Electrium Z"), //TODO 汉化
#else
                    _("Electrium Z"),
#endif
                .itemId = ITEM_ELECTRIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sElectriumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ELECTRIC},

        [ITEM_PSYCHIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Psychium Z"), //TODO 汉化
#else
                    _("Psychium Z"),
#endif
                .itemId = ITEM_PSYCHIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sPsychiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_PSYCHIC},

        [ITEM_ICIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Icium Z"), //TODO 汉化
#else
                    _("Icium Z"),
#endif
                .itemId = ITEM_ICIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sIciumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_ICE},

        [ITEM_DRAGONIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Dragonium Z"), //TODO 汉化
#else
                    _("Dragonium Z"),
#endif
                .itemId = ITEM_DRAGONIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sDragoniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_DRAGON},

        [ITEM_DARKINIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Darkinium Z"), //TODO 汉化
#else
                    _("Darkinium Z"),
#endif
                .itemId = ITEM_DARKINIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sDarkiniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_DARK},

        [ITEM_FAIRIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Fairium Z"), //TODO 汉化
#else
                    _("Fairium Z"),
#endif
                .itemId = ITEM_FAIRIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sFairiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = TYPE_FAIRY},

        [ITEM_ALORAICHIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Aloraichium Z"), //TODO 汉化
#else
                    _("Aloraichium Z"),
#endif
                .itemId = ITEM_ALORAICHIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sAloraichiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_DECIDIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Decidium Z"), //TODO 汉化
#else
                    _("Decidium Z"),
#endif
                .itemId = ITEM_DECIDIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sDecidiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_EEVIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Eevium Z"), //TODO 汉化
#else
                    _("Eevium Z"),
#endif
                .itemId = ITEM_EEVIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sEeviumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_INCINIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Incinium Z"), //TODO 汉化
#else
                    _("Incinium Z"),
#endif
                .itemId = ITEM_INCINIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sInciniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_KOMMONIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Kommonium Z"), //TODO 汉化
#else
                    _("Kommonium Z"),
#endif
                .itemId = ITEM_KOMMONIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sKommoniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_LUNALIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Lunalium Z"), //TODO 汉化
#else
                    _("Lunalium Z"),
#endif
                .itemId = ITEM_LUNALIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sLunaliumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_LYCANIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Lycanium Z"), //TODO 汉化
#else
                    _("Lycanium Z"),
#endif
                .itemId = ITEM_LYCANIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sLycaniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_MARSHADIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Marshadium Z"), //TODO 汉化
#else
                    _("Marshadium Z"),
#endif
                .itemId = ITEM_MARSHADIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sMarshadiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_MEWNIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Mewnium Z"), //TODO 汉化
#else
                    _("Mewnium Z"),
#endif
                .itemId = ITEM_MEWNIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sMewniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_MIMIKIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Mimikium Z"), //TODO 汉化
#else
                    _("Mimikium Z"),
#endif
                .itemId = ITEM_MIMIKIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sMimikiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_PIKANIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Pikanium Z"), //TODO 汉化
#else
                    _("Pikanium Z"),
#endif
                .itemId = ITEM_PIKANIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sPikaniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_PIKASHUNIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Pikashunium Z"), //TODO 汉化
#else
                    _("Pikashunium Z"),
#endif
                .itemId = ITEM_PIKASHUNIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sPikashuniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_PRIMARIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Primarium Z"), //TODO 汉化
#else
                    _("Primarium Z"),
#endif
                .itemId = ITEM_PRIMARIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sPrimariumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_SNORLIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Snorlium Z"), //TODO 汉化
#else
                    _("Snorlium Z"),
#endif
                .itemId = ITEM_SNORLIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sSnorliumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_SOLGANIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Solganium Z"), //TODO 汉化
#else
                    _("Solganium Z"),
#endif
                .itemId = ITEM_SOLGANIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sSolganiumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 // signature z move
            },

        [ITEM_TAPUNIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("Tapunium Z"), //TODO 汉化
#else
                    _("Tapunium Z"),
#endif
                .itemId = ITEM_TAPUNIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sTapuniumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 //signature z move
            },

        [ITEM_ULTRANECROZIUM_Z] =
            {
                .name =
#ifdef CHINESE
                    _("U-Necrozium Z"), //TODO 汉化
#else
                    _("U-Necrozium Z"),
#endif
                .itemId = ITEM_ULTRANECROZIUM_Z,
                .price = 0,
                .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
                .description = sUltranecroziumZDesc,
                .pocket = POCKET_ITEMS,
                .type = ITEM_USE_BAG_MENU,
                .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
                .secondaryId = 255 //signature z move
            },
};
