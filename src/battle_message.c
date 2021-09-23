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
static const u8 sText_PkmnGainedEXP[] = _("{B_BUFF1}获得了{B_BUFF2}\n{B_BUFF3}点经验值！\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _("提升");
static const u8 sText_PkmnGrewToLv[] = _("{B_BUFF1}\n升到了{B_BUFF2}级！{WAIT_SE}\p");
static const u8 sText_PkmnLearnedMove[] = _("{B_BUFF1}习得\n技能{B_BUFF2}！{WAIT_SE}\p");
static const u8 sText_TryToLearnMove1[] = _("{B_BUFF1}想要习得\n技能{B_BUFF2}。\p");
static const u8 sText_TryToLearnMove2[] = _("但是，{B_BUFF1}已经不能\n习得更多的技能。\p");
static const u8 sText_TryToLearnMove3[] = _("删除一个技能给\n{B_BUFF2}留下空间？");
static const u8 sText_PkmnForgotMove[] = _("{B_BUFF1}忘记了\n{B_BUFF2}。\p");
static const u8 sText_StopLearningMove[] = _("{PAUSE 32}放弃习得\n技能{B_BUFF2}？");
static const u8 sText_DidNotLearnMove[] = _("{B_BUFF1}没有习得\n技能{B_BUFF2}。\p");
static const u8 sText_UseNextPkmn[] = _("要更换宝可梦吗？");
static const u8 sText_AttackMissed[] = _("{B_ATK_NAME_WITH_PREFIX}的\n攻击没有命中！");
static const u8 sText_PkmnProtectedItself[] = _("{B_DEF_NAME_WITH_PREFIX}\n保护了自己！");
static const u8 sText_AvoidedDamage[] = _("{B_DEF_NAME_WITH_PREFIX}因{B_DEF_ABILITY}\n避免了伤害！");
static const u8 sText_PkmnMakesGroundMiss[] = _("{B_DEF_NAME_WITH_PREFIX}因{B_DEF_ABILITY}\n抵御了地上系技能！");
static const u8 sText_PkmnAvoidedAttack[] = _("{B_DEF_NAME_WITH_PREFIX}抵御了攻击！");
static const u8 sText_ItDoesntAffect[] = _("对{B_DEF_NAME_WITH_PREFIX}\n没有效果……");
static const u8 sText_AttackerFainted[] = _("{B_ATK_NAME_WITH_PREFIX}\n倒下了！\p");
static const u8 sText_TargetFainted[] = _("{B_DEF_NAME_WITH_PREFIX}\n倒下了！\p");
static const u8 sText_PlayerGotMoney[] = _("{B_PLAYER_NAME}收到了\n{B_BUFF1}元作为奖励！\p");
static const u8 sText_PlayerGotItem[] = _("{B_PLAYER_NAME}收到了作为奖励的\n{B_BUFF2}！\p");
static const u8 sText_PlayerGotItem2[] = _("{B_PLAYER_NAME}收到了作为奖励的\n{B_BUFF2}和{B_BUFF3}！\p");
static const u8 sText_PlayerWhiteout[] = _("{B_PLAYER_NAME}\n已经没有可用的宝可梦了！\p");
static const u8 sText_PlayerWhiteout2[] = _("{B_PLAYER_NAME}被击败了！{PAUSE_UNTIL_PRESS}");
static const u8 sText_PreventsEscape[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}用{B_SCR_ACTIVE_ABILITY}\n阻止逃跑！\p");
static const u8 sText_CantEscape2[] = _("不能逃跑！\p");
static const u8 sText_AttackerCantEscape[] = _("{B_ATK_NAME_WITH_PREFIX}不能逃跑！");
static const u8 sText_HitXTimes[] = _("连续命中{B_BUFF1}次！");
static const u8 sText_PkmnFellAsleep[] = _("{B_EFF_NAME_WITH_PREFIX}\n睡着了！");
static const u8 sText_PkmnMadeSleep[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n使{B_EFF_NAME_WITH_PREFIX}睡着了！");
static const u8 sText_PkmnAlreadyAsleep[] = _("{B_DEF_NAME_WITH_PREFIX}\n已经睡着了！");
static const u8 sText_PkmnAlreadyAsleep2[] = _("{B_ATK_NAME_WITH_PREFIX}\n已经睡着了！");
static const u8 sText_PkmnWasntAffected[] = _("{B_DEF_NAME_WITH_PREFIX}\n没有受到影响！");
static const u8 sText_PkmnWasPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX}\n中毒了！");
static const u8 sText_PkmnPoisonedBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_BUFF1}\n使{B_EFF_NAME_WITH_PREFIX}中毒了！");
static const u8 sText_PkmnHurtByPoison[] = _("{B_ATK_NAME_WITH_PREFIX}因中毒\n受到了伤害！");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{B_DEF_NAME_WITH_PREFIX}\n中毒了。");
static const u8 sText_PkmnBadlyPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX}\n中了剧毒！");
static const u8 sText_PkmnEnergyDrained[] = _("{B_DEF_NAME_WITH_PREFIX}\n被吸取了能量！");
static const u8 sText_PkmnWasBurned[] = _("{B_EFF_NAME_WITH_PREFIX}烧伤了！");
static const u8 sText_PkmnBurnedBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n使{B_EFF_NAME_WITH_PREFIX}烧伤了！");
static const u8 sText_PkmnHurtByBurn[] = _("{B_ATK_NAME_WITH_PREFIX}\n因烧伤受到了伤害！");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX}\n已经烧伤了。");
static const u8 sText_PkmnWasFrozen[] = _("{B_EFF_NAME_WITH_PREFIX}\n被冰冻！");
static const u8 sText_PkmnFrozenBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n使{B_EFF_NAME_WITH_PREFIX}被冰冻了！");
static const u8 sText_PkmnIsFrozen[] = _("{B_ATK_NAME_WITH_PREFIX}被\n冰冻了！");
static const u8 sText_PkmnWasDefrosted[] = _("{B_DEF_NAME_WITH_PREFIX}\n解除了冰冻！");
static const u8 sText_PkmnWasDefrosted2[] = _("{B_ATK_NAME_WITH_PREFIX}\n解除了冰冻！");
static const u8 sText_PkmnWasDefrostedBy[] = _("{B_ATK_NAME_WITH_PREFIX}因{B_CURRENT_MOVE}\n解除了冰冻！");
static const u8 sText_PkmnWasParalyzed[] = _("{B_EFF_NAME_WITH_PREFIX}麻痹了！\n可能无法行动！");
static const u8 sText_PkmnWasParalyzedBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n使{B_EFF_NAME_WITH_PREFIX}麻痹了！\l可能无法行动！");
static const u8 sText_PkmnIsParalyzed[] = _("{B_ATK_NAME_WITH_PREFIX}麻痹了！\n无法行动！");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("{B_DEF_NAME_WITH_PREFIX}\n已经麻痹了！");
static const u8 sText_PkmnHealedParalysis[] = _("{B_DEF_NAME_WITH_PREFIX}的身体\n不再麻痹了！");
static const u8 sText_PkmnDreamEaten[] = _("{B_DEF_NAME_WITH_PREFIX}的梦\n被吃了！");
static const u8 sText_StatsWontIncrease[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_BUFF1}\n已经无法上升了！");
static const u8 sText_StatsWontDecrease[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_BUFF1}\n已经无法下降了！");
static const u8 sText_TeamStoppedWorking[] = _("我方的{B_BUFF1}\n失去了作用！");
static const u8 sText_FoeStoppedWorking[] = _("对手的{B_BUFF1}\n失去了作用！");
static const u8 sText_PkmnIsConfused[] = _("{B_ATK_NAME_WITH_PREFIX}\n混乱了！");
static const u8 sText_PkmnHealedConfusion[] = _("{B_ATK_NAME_WITH_PREFIX}\n解除了混乱！");
static const u8 sText_PkmnWasConfused[] = _("{B_EFF_NAME_WITH_PREFIX}\n开始混乱了！");
static const u8 sText_PkmnAlreadyConfused[] = _("{B_DEF_NAME_WITH_PREFIX}\n已经混乱了！");
static const u8 sText_PkmnFellInLove[] = _("{B_DEF_NAME_WITH_PREFIX}\n被迷倒了！");
static const u8 sText_PkmnInLove[] = _("{B_ATK_NAME_WITH_PREFIX}因\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}迷倒了！");
static const u8 sText_PkmnImmobilizedByLove[] = _("{B_ATK_NAME_WITH_PREFIX}因\n迷倒无法行动！");
static const u8 sText_PkmnBlownAway[] = _("{B_DEF_NAME_WITH_PREFIX}被\n吹飞了！");
static const u8 sText_PkmnChangedType[] = _("{B_ATK_NAME_WITH_PREFIX}变成了\n{B_BUFF1}系！");
static const u8 sText_PkmnFlinched[] = _("{B_ATK_NAME_WITH_PREFIX}动弹不得！");
static const u8 sText_PkmnRegainedHealth[] = _("{B_DEF_NAME_WITH_PREFIX}\n恢复了健康！");
static const u8 sText_PkmnHPFull[] = _("{B_DEF_NAME_WITH_PREFIX}的\nHP满了！");
static const u8 sText_PkmnRaisedSpDef[] = _("{B_ATK_PREFIX2}的{B_CURRENT_MOVE}\n提升了特防！");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("{B_ATK_PREFIX2}的{B_CURRENT_MOVE}\n稍微提升了特防！");
static const u8 sText_PkmnRaisedDef[] = _("{B_ATK_PREFIX2}的{B_CURRENT_MOVE}\n提升了防御！");
static const u8 sText_PkmnRaisedDefALittle[] = _("{B_ATK_PREFIX2}的{B_CURRENT_MOVE}\n稍微提升了防御！");
static const u8 sText_PkmnCoveredByVeil[] = _("{B_ATK_PREFIX2}的一方\n被罩子包裹了！");
static const u8 sText_PkmnUsedSafeguard[] = _("{B_DEF_NAME_WITH_PREFIX}的一方被\n神秘护身保护了！");
static const u8 sText_PkmnSafeguardExpired[] = _("{B_ATK_PREFIX3}的一方\n不再受神秘护身保护了！");
static const u8 sText_PkmnWentToSleep[] = _("{B_ATK_NAME_WITH_PREFIX}\n睡着了！");
static const u8 sText_PkmnSleptHealthy[] = _("{B_ATK_NAME_WITH_PREFIX}睡着了\n并且恢复了体力！");
static const u8 sText_PkmnWhippedWhirlwind[] = _("{B_ATK_NAME_WITH_PREFIX}\n使出了旋风！");
static const u8 sText_PkmnTookSunlight[] = _("{B_ATK_NAME_WITH_PREFIX}\n吸收了阳光！");
static const u8 sText_PkmnLoweredHead[] = _("{B_ATK_NAME_WITH_PREFIX}的头\n往后缩了下！");
static const u8 sText_PkmnIsGlowing[] = _("{B_ATK_NAME_WITH_PREFIX}正在发光！");
static const u8 sText_PkmnFlewHigh[] = _("{B_ATK_NAME_WITH_PREFIX}\n飞向了高空！");
static const u8 sText_PkmnDugHole[] = _("{B_ATK_NAME_WITH_PREFIX}挖向了地下！");
static const u8 sText_PkmnHidUnderwater[] = _("{B_ATK_NAME_WITH_PREFIX}潜入水中！");
static const u8 sText_PkmnSprangUp[] = _("{B_ATK_NAME_WITH_PREFIX}跳了起来！");
static const u8 sText_PkmnSqueezedByBind[] = _("{B_DEF_NAME_WITH_PREFIX}因\n{B_ATK_NAME_WITH_PREFIX}的绑紧被绑住了！");
static const u8 sText_PkmnTrappedInVortex[] = _("{B_DEF_NAME_WITH_PREFIX}被困于\n漩涡中！");
static const u8 sText_PkmnTrappedBySandTomb[] = _("{B_DEF_NAME_WITH_PREFIX}被困于\n流沙地狱中！");
static const u8 sText_PkmnWrappedBy[] = _("{B_DEF_NAME_WITH_PREFIX}被\n{B_ATK_NAME_WITH_PREFIX}捆绑了！");
static const u8 sText_PkmnClamped[] = _("{B_ATK_NAME_WITH_PREFIX}的壳夹着\n{B_DEF_NAME_WITH_PREFIX}！");
static const u8 sText_PkmnHurtBy[] = _("{B_ATK_NAME_WITH_PREFIX}因\n{B_BUFF1}受到伤害！");
static const u8 sText_PkmnFreedFrom[] = _("{B_ATK_NAME_WITH_PREFIX}不受\n{B_BUFF1}的影响了！");
static const u8 sText_PkmnCrashed[] = _("强力的冲击使{B_ATK_NAME_WITH_PREFIX}\n摔倒了!！");
const u8 gText_PkmnShroudedInMist[] = _("{B_ATK_PREFIX2}\n被白雾笼罩了！");
static const u8 sText_PkmnProtectedByMist[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}\n被白雾保护了！");
const u8 gText_PkmnGettingPumped[] = _("{B_ATK_NAME_WITH_PREFIX}\n变得兴奋了！");
static const u8 sText_PkmnHitWithRecoil[] = _("{B_ATK_NAME_WITH_PREFIX}\n受到了反馈伤害！");
static const u8 sText_PkmnProtectedItself2[] = _("{B_ATK_NAME_WITH_PREFIX}\n保护了自己！");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("{B_ATK_NAME_WITH_PREFIX}因\n沙暴受到了伤害！");
static const u8 sText_PkmnPeltedByHail[] = _("{B_ATK_NAME_WITH_PREFIX}因\n冰雹受到了伤害！");
static const u8 sText_PkmnsXWoreOff[] = _("{B_ATK_PREFIX1}的{B_BUFF1}\n消失了！");
static const u8 sText_PkmnSeeded[] = _("{B_DEF_NAME_WITH_PREFIX}被种了种子！");
static const u8 sText_PkmnEvadedAttack[] = _("{B_DEF_NAME_WITH_PREFIX}\n回避了攻击！");
static const u8 sText_PkmnSappedByLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX}的HP\n因寄生种子减少了！");
static const u8 sText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX}熟睡了。");
static const u8 sText_PkmnWokeUp[] = _("{B_ATK_NAME_WITH_PREFIX}醒来了！");
static const u8 sText_PkmnUproarKeptAwake[] = _("但是，{B_SCR_ACTIVE_NAME_WITH_PREFIX}的吵闹\n让它保持了清醒！");
static const u8 sText_PkmnWokeUpInUproar[] = _("{B_ATK_NAME_WITH_PREFIX}在\n吵闹中睡着了！");
static const u8 sText_PkmnCausedUproar[] = _("{B_ATK_NAME_WITH_PREFIX}\n引起了吵闹！");
static const u8 sText_PkmnMakingUproar[] = _("{B_ATK_NAME_WITH_PREFIX}\n在制造吵闹！");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX}平静了下来。");
static const u8 sText_PkmnCantSleepInUproar[] = _("但是，{B_DEF_NAME_WITH_PREFIX}无法在\n吵闹中睡眠！");
static const u8 sText_PkmnStockpiled[] = _("{B_ATK_NAME_WITH_PREFIX}储存了\n{B_BUFF1}！");
static const u8 sText_PkmnCantStockpile[] = _("{B_ATK_NAME_WITH_PREFIX}\n不能再储存了！");
static const u8 sText_PkmnCantSleepInUproar2[] = _("但是，{B_DEF_NAME_WITH_PREFIX}在\n吵闹中不会睡着！");
static const u8 sText_UproarKeptPkmnAwake[] = _("但是，吵闹使得\n{B_DEF_NAME_WITH_PREFIX}保持清醒！");
static const u8 sText_PkmnStayedAwakeUsing[] = _("{B_DEF_NAME_WITH_PREFIX}在清醒中\n使用它的{B_DEF_ABILITY}！");
static const u8 sText_PkmnStoringEnergy[] = _("{B_ATK_NAME_WITH_PREFIX}\n积蓄了能量！");
static const u8 sText_PkmnUnleashedEnergy[] = _("{B_ATK_NAME_WITH_PREFIX}\n释放了能量！");
static const u8 sText_PkmnFatigueConfusion[] = _("{B_ATK_NAME_WITH_PREFIX}由于\n疲劳变得混乱！");
static const u8 sText_PlayerPickedUpMoney[] = _("{B_PLAYER_NAME}捡到了\n{B_BUFF1}$！\p");
static const u8 sText_PkmnUnaffected[] = _("{B_DEF_NAME_WITH_PREFIX}\n没受到影响！");
static const u8 sText_PkmnTransformedInto[] = _("{B_ATK_NAME_WITH_PREFIX}变身为\n{B_BUFF1}！");
static const u8 sText_PkmnMadeSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX}\n制造了一个替身！");
static const u8 sText_PkmnHasSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX}已经\n有一个替身了！");
static const u8 sText_SubstituteDamaged[] = _("替身为\n{B_DEF_NAME_WITH_PREFIX}承受了伤害！\p");
static const u8 sText_PkmnSubstituteFaded[] = _("{B_DEF_NAME_WITH_PREFIX}的\n替身消失了！\p");
static const u8 sText_PkmnMustRecharge[] = _("{B_ATK_NAME_WITH_PREFIX}\n必须恢复能量！");
static const u8 sText_PkmnRageBuilding[] = _("{B_DEF_NAME_WITH_PREFIX}\n已经愤怒了！");
static const u8 sText_PkmnMoveWasDisabled[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_BUFF1}\n无法起作用！");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("{B_ATK_NAME_WITH_PREFIX}\n不再起作用！");
static const u8 sText_PkmnGotEncore[] = _("{B_DEF_NAME_WITH_PREFIX}\n中了再来一次！");
static const u8 sText_PkmnEncoreEnded[] = _("{B_ATK_NAME_WITH_PREFIX}对\n再来一次免疫！");
static const u8 sText_PkmnTookAim[] = _("{B_ATK_NAME_WITH_PREFIX}\n瞄准了{B_DEF_NAME_WITH_PREFIX}！");
static const u8 sText_PkmnSketchedMove[] = _("{B_ATK_NAME_WITH_PREFIX}对\n{B_BUFF1}做素描！");
static const u8 sText_PkmnTryingToTakeFoe[] = _("{B_ATK_NAME_WITH_PREFIX}试图\n与对手同归于尽！");
static const u8 sText_PkmnTookFoe[] = _("{B_DEF_NAME_WITH_PREFIX}与\n{B_ATK_NAME_WITH_PREFIX}同归于尽！");
static const u8 sText_PkmnReducedPP[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_BUFF1}减少了\n{B_BUFF2}点！");
static const u8 sText_PkmnStoleItem[] = _("{B_ATK_NAME_WITH_PREFIX}偷窃了\n{B_DEF_NAME_WITH_PREFIX}的{B_LAST_ITEM}！");
static const u8 sText_TargetCantEscapeNow[] = _("{B_DEF_NAME_WITH_PREFIX}暂时\n不能逃跑！");
static const u8 sText_PkmnFellIntoNightmare[] = _("{B_DEF_NAME_WITH_PREFIX}\n堕入了恶梦之中！");
static const u8 sText_PkmnLockedInNightmare[] = _("{B_ATK_NAME_WITH_PREFIX}\n被困于恶梦之中！");
static const u8 sText_PkmnLaidCurse[] = _("{B_ATK_NAME_WITH_PREFIX}减半了自身的HP，\n并给{B_DEF_NAME_WITH_PREFIX}施加了诅咒！");
static const u8 sText_PkmnAfflictedByCurse[] = _("{B_ATK_NAME_WITH_PREFIX}受到了\n诅咒造成的伤害！");
static const u8 sText_SpikesScattered[] = _("铁菱已经遍布\n对手的周围！");
static const u8 sText_PkmnHurtBySpikes[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}受到\n铁菱的伤害！");
static const u8 sText_PkmnIdentified[] = _("{B_ATK_NAME_WITH_PREFIX}鉴别了\n{B_DEF_NAME_WITH_PREFIX}！");
static const u8 sText_PkmnPerishCountFell[] = _("{B_ATK_NAME_WITH_PREFIX}的灭亡回合\n只剩下{B_BUFF1}回合！");
static const u8 sText_PkmnBracedItself[] = _("{B_ATK_NAME_WITH_PREFIX}挺住了！");
static const u8 sText_PkmnEnduredHit[] = _("{B_DEF_NAME_WITH_PREFIX}忍耐了攻击！");
static const u8 sText_MagnitudeStrength[] = _("震级{B_BUFF1}！");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("{B_ATK_NAME_WITH_PREFIX}的HP减少了，\n并且攻击上升至最高！");
static const u8 sText_PkmnCopiedStatChanges[] = _("{B_ATK_NAME_WITH_PREFIX}复制了\n{B_DEF_NAME_WITH_PREFIX}的能力等级！");
static const u8 sText_PkmnGotFree[] = _("{B_ATK_NAME_WITH_PREFIX}解脱了\n{B_DEF_NAME_WITH_PREFIX}的{B_BUFF1}！");
static const u8 sText_PkmnShedLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX}\n摆脱了寄生种子！");
static const u8 sText_PkmnBlewAwaySpikes[] = _("{B_ATK_NAME_WITH_PREFIX}\n清除了铁菱！");
static const u8 sText_PkmnFledFromBattle[] = _("{B_ATK_NAME_WITH_PREFIX}从对战中\n逃脱了！");
static const u8 sText_PkmnForesawAttack[] = _("{B_ATK_NAME_WITH_PREFIX}\n预知了攻击！");
static const u8 sText_PkmnTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX}挡下了\n{B_BUFF1}的攻击！");
static const u8 sText_PkmnChoseXAsDestiny[] = _("{B_ATK_NAME_WITH_PREFIX}准备和\n{B_CURRENT_MOVE}一同倒下！");
static const u8 sText_PkmnAttack[] = _("{B_BUFF1}的攻击！");
static const u8 sText_PkmnCenterAttention[] = _("{B_ATK_NAME_WITH_PREFIX}将\n焦点集中在自身！");
static const u8 sText_PkmnChargingPower[] = _("{B_ATK_NAME_WITH_PREFIX}\n开始积蓄能量！");
static const u8 sText_NaturePowerTurnedInto[] = _("自然能力变成了\n{B_CURRENT_MOVE}！");
static const u8 sText_PkmnStatusNormal[] = _("{B_ATK_NAME_WITH_PREFIX}的状态\n恢复了正常！");
static const u8 sText_PkmnSubjectedToTorment[] = _("{B_DEF_NAME_WITH_PREFIX}\n受到了无理取闹的影响！");
static const u8 sText_PkmnTighteningFocus[] = _("{B_ATK_NAME_WITH_PREFIX}\n集中了力量！");
static const u8 sText_PkmnFellForTaunt[] = _("{B_DEF_NAME_WITH_PREFIX}\n受到了挑衅！");
static const u8 sText_PkmnReadyToHelp[] = _("{B_ATK_NAME_WITH_PREFIX}\n准备帮助{B_DEF_NAME_WITH_PREFIX}！");
static const u8 sText_PkmnSwitchedItems[] = _("{B_ATK_NAME_WITH_PREFIX}与对手\n交换了携带道具！");
static const u8 sText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX}获得了\n{B_BUFF1}。");
static const u8 sText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX}获得了\n{B_BUFF2}。");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX}获得了\n{B_BUFF1}。\p{B_DEF_NAME_WITH_PREFIX}获得了\n{B_BUFF2}。");
static const u8 sText_PkmnCopiedFoe[] = _("{B_ATK_NAME_WITH_PREFIX}模仿了\n{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}！");
static const u8 sText_PkmnMadeWish[] = _("{B_ATK_NAME_WITH_PREFIX}许了一个愿！");
static const u8 sText_PkmnWishCameTrue[] = _("{B_BUFF1}的许愿\n实现了！");
static const u8 sText_PkmnPlantedRoots[] = _("{B_ATK_NAME_WITH_PREFIX}扎下了根！");
static const u8 sText_PkmnAbsorbedNutrients[] = _("{B_ATK_NAME_WITH_PREFIX}\n汲取了根茎的养分！");
static const u8 sText_PkmnAnchoredItself[] = _("{B_DEF_NAME_WITH_PREFIX}把自身\n用根茎紧紧固定住了！");
static const u8 sText_PkmnWasMadeDrowsy[] = _("{B_ATK_NAME_WITH_PREFIX}使得\n{B_DEF_NAME_WITH_PREFIX}昏昏欲睡！");
static const u8 sText_PkmnKnockedOff[] = _("{B_ATK_NAME_WITH_PREFIX}打破了\n{B_DEF_NAME_WITH_PREFIX}的{B_LAST_ITEM}！");
static const u8 sText_PkmnSwappedAbilities[] = _("{B_ATK_NAME_WITH_PREFIX}\n与对手互换了特性！");
static const u8 sText_PkmnSealedOpponentMove[] = _("{B_ATK_NAME_WITH_PREFIX}\n封印了对手的技能！");
static const u8 sText_PkmnWantsGrudge[] = _("{B_ATK_NAME_WITH_PREFIX}\n让对手背负怨恨！");
static const u8 sText_PkmnLostPPGrudge[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_BUFF1}\n失去了所有的PP！");
static const u8 sText_PkmnShroudedItself[] = _("{B_ATK_NAME_WITH_PREFIX}将\n自身笼罩在{B_CURRENT_MOVE}中！");
static const u8 sText_PkmnMoveBounced[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_CURRENT_MOVE}\n因为魔术外衣被反弹了！");
static const u8 sText_PkmnWaitsForTarget[] = _("{B_ATK_NAME_WITH_PREFIX}等待目标\n以便复制技能！");
static const u8 sText_PkmnSnatchedMove[] = _("{B_DEF_NAME_WITH_PREFIX}抢夺了\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}的技能！");
static const u8 sText_ElectricityWeakened[] = _("电的力量\n减弱了！");
static const u8 sText_FireWeakened[] = _("炎的力量\n减弱了！");
static const u8 sText_XFoundOneY[] = _("{B_ATK_NAME_WITH_PREFIX}发现了\n一个{B_LAST_ITEM}！");
static const u8 sText_SoothingAroma[] = _("一股沁心的香气\n弥漫了开来！");
static const u8 sText_ItemsCantBeUsedNow[] = _("道具暂不起作用。{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("对于{B_SCR_ACTIVE_NAME_WITH_PREFIX}，\n{B_LAST_ITEM} {B_BUFF1} 。");
static const u8 sText_PkmnUsedXToGetPumped[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}使用\n{B_LAST_ITEM}来变得兴奋！");
static const u8 sText_PkmnLostFocus[] = _("{B_ATK_NAME_WITH_PREFIX}失去了焦点\n不能出招！");
static const u8 sText_PkmnWasDraggedOut[] = _("{B_DEF_NAME_WITH_PREFIX}被\n拖入了战斗！\p");
static const u8 sText_TheWallShattered[] = _("墙壁粉碎了！");
static const u8 sText_ButNoEffect[] = _("但是不起任何作用！");
static const u8 sText_PkmnHasNoMovesLeft[] = _("{B_ACTIVE_NAME_WITH_PREFIX}\n已经没有技能了！\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("{B_ACTIVE_NAME_WITH_PREFIX}的{B_CURRENT_MOVE}\n不起作用！\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("{B_ACTIVE_NAME_WITH_PREFIX}不能\n使用相同的技能！\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("{B_ACTIVE_NAME_WITH_PREFIX}受到假指控后，\n无法使用{B_CURRENT_MOVE}！\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("{B_ACTIVE_NAME_WITH_PREFIX}不能使用\n被封印的{B_CURRENT_MOVE}！\p");
static const u8 sText_PkmnCantUseMoveThroatChop[] = _("{B_ACTIVE_NAME_WITH_PREFIX} 无法使用\n{B_CURRENT_MOVE}失声!\p");
static const u8 sText_PkmnMadeItRain[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n使天空下起雨！");
static const u8 sText_PkmnRaisedSpeed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n提升了速度！");
static const u8 sText_PkmnProtectedBy[] = _("{B_DEF_NAME_WITH_PREFIX}受到了\n{B_DEF_ABILITY}的保护！");
static const u8 sText_PkmnPreventsUsage[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n防止了{B_ATK_NAME_WITH_PREFIX}\l使用{B_CURRENT_MOVE}！");
static const u8 sText_PkmnRestoredHPUsing[] = _("{B_DEF_NAME_WITH_PREFIX}因{B_DEF_ABILITY}\n恢复了HP！");
static const u8 sText_PkmnsXMadeYUseless[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n使{B_CURRENT_MOVE}不起作用！");
static const u8 sText_PkmnChangedTypeWith[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n使它变成{B_BUFF1}！");
static const u8 sText_PkmnPreventsParalysisWith[] = _("{B_EFF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n抵御了麻痹！");
static const u8 sText_PkmnPreventsRomanceWith[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n抵御了迷人！");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("{B_EFF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n抵御了中毒！");
static const u8 sText_PkmnPreventsConfusionWith[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n抵御了混乱！");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n提升了炎系技能的威力！");
static const u8 sText_PkmnAnchorsItselfWith[] = _("{B_DEF_NAME_WITH_PREFIX}因\n{B_DEF_ABILITY}固定住了自身！");
static const u8 sText_PkmnCutsAttackWith[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n降低了{B_DEF_NAME_WITH_PREFIX}的攻击！");
static const u8 sText_PkmnPreventsStatLossWith[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n防止了能力等级下降！");
static const u8 sText_PkmnHurtsWith[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_BUFF1}\n对{B_ATK_NAME_WITH_PREFIX}造成了伤害！");
static const u8 sText_PkmnTraced[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}追踪了\n{B_BUFF1}的{B_BUFF2}！");
static const u8 sText_PkmnsXPreventsBurns[] = _("{B_EFF_NAME_WITH_PREFIX}的{B_EFF_ABILITY}\n防止了烧伤！");
static const u8 sText_PkmnsXBlocksY[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n阻止了{B_CURRENT_MOVE}！");
static const u8 sText_PkmnsXBlocksY2[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n阻止了{B_CURRENT_MOVE}！");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_ATK_ABILITY}\n使HP稍微恢复了！");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n在场上扬起了沙暴！");
static const u8 sText_PkmnsXIntensifiedSun[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n使阳光更加强烈！");
static const u8 sText_PkmnsXPreventsYLoss[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n防止了{B_BUFF1}下降！");
static const u8 sText_PkmnsXInfatuatedY[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n迷倒了{B_ATK_NAME_WITH_PREFIX}！");
static const u8 sText_PkmnsXMadeYIneffective[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n使{B_CURRENT_MOVE}无效化了！");
static const u8 sText_PkmnsXCuredYProblem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n治愈了{B_BUFF1}！");
static const u8 sText_ItSuckedLiquidOoze[] = _("吸收了黏液！");
static const u8 sText_PkmnTransformed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}变身了！");
static const u8 sText_PkmnsXTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n承受了攻击！");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_BUFF1}的{B_LAST_ABILITY}\n防止了替换！\p");
static const u8 sText_PreventedFromWorking[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n防止了{B_SCR_ACTIVE_NAME_WITH_PREFIX}的\l{B_BUFF1}起作用！");
static const u8 sText_PkmnsXMadeItIneffective[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n使它无效化了！");
static const u8 sText_PkmnsXPreventsFlinching[] = _("{B_EFF_NAME_WITH_PREFIX}的{B_EFF_ABILITY}\n防止了害怕！");
static const u8 sText_PkmnsXPreventsYsZ[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_ATK_ABILITY}\n防止了{B_DEF_NAME_WITH_PREFIX}的\l{B_DEF_ABILITY}起作用！");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n治愈了它的{B_BUFF1}！");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n对{B_EFF_NAME_WITH_PREFIX}不起作用！");
const u8 gText_StatSharply[] = _("急剧");
const u8 gText_StatRose[] = _("提升！");
static const u8 sText_StatHarshly[] = _("大幅");
static const u8 sText_StatFell[] = _("下降！");
static const u8 sText_AttackersStatRose[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_BUFF1}\n{B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_BUFF1}\n{B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("使用了{B_LAST_ITEM}，{B_BUFF1}\n的{B_SCR_ACTIVE_NAME_WITH_PREFIX}{B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_BUFF1}\n{B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_BUFF1}\n{B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("{B_ATK_NAME_WITH_PREFIX}的能力\n不能再提升了！");
static const u8 sText_StatsWontDecrease2[] = _("{B_DEF_NAME_WITH_PREFIX}的能力\n不能再降低了！");
static const u8 sText_CriticalHit[] = _("命中要害！");
static const u8 sText_OneHitKO[] = _("一击必杀！");
static const u8 sText_123Poof[] = _("{PAUSE 32}1，{PAUSE 15}2，然后{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}叮咚！\p");
static const u8 sText_AndEllipsis[] = _("那…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("暂时无法忘记秘传技能。\p");
static const u8 sText_NotVeryEffective[] = _("收效甚微…");
static const u8 sText_SuperEffective[] = _("效果拔群！");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}成功逃走了！\p");
static const u8 sText_PkmnFledUsingIts[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX}\n使用了{B_LAST_ITEM}后逃走了！\p");
static const u8 sText_PkmnFledUsing[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX}\n使用了{B_ATK_ABILITY}后逃走了！\p");
static const u8 sText_WildPkmnFled[] = _("{PLAY_SE SE_FLEE}野生{B_BUFF1}逃走了！");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("你打败了\n{B_LINK_OPPONENT1_NAME}！");
static const u8 sText_TwoLinkTrainersDefeated[] = _("你打败了{B_LINK_OPPONENT1_NAME}\n和{B_LINK_OPPONENT2_NAME}！");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("你输给了\n{B_LINK_OPPONENT1_NAME}！");
static const u8 sText_PlayerLostToTwo[] = _("你输给了{B_LINK_OPPONENT1_NAME}\n和{B_LINK_OPPONENT2_NAME}！");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("你与\n{B_LINK_OPPONENT1_NAME}打成了平手！");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("你与{B_LINK_OPPONENT1_NAME}\n和{B_LINK_OPPONENT2_NAME}打成了平手！");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME}逃了！");
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME}和\n{B_LINK_OPPONENT2_NAME}逃走了！");
static const u8 sText_NoRunningFromTrainers[] = _("不可以！训练家要堂堂正正地\n面对战斗！\p");
static const u8 sText_CantEscape[] = _("不能逃跑！\p");
static const u8 sText_DontLeaveBirch[] = _("小田卷博士：不要像那样不管我！\p");
static const u8 sText_ButNothingHappened[] = _("但是什么都没发生！");
static const u8 sText_ButItFailed[] = _("但是它失败了！");
static const u8 sText_ItHurtConfusion[] = _("因混乱对自己\n造成了伤害！");
static const u8 sText_MirrorMoveFailed[] = _("鹦鹉学舌失败了！");
static const u8 sText_StartedToRain[] = _("下起了雨！");
static const u8 sText_DownpourStarted[] = _("下起了大雨！"); // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
static const u8 sText_RainContinues[] = _("雨一直在下。");
static const u8 sText_DownpourContinues[] = _("大雨一直在下。"); // unused
static const u8 sText_RainStopped[] = _("雨不再下了。");
static const u8 sText_SandstormBrewed[] = _("扬起了沙暴！");
static const u8 sText_SandstormRages[] = _("飞沙走石。");
static const u8 sText_SandstormSubsided[] = _("沙暴停止了。");
static const u8 sText_SunlightGotBright[] = _("阳光变猛烈了！");
static const u8 sText_SunlightStrong[] = _("阳光很猛烈。");
static const u8 sText_SunlightFaded[] = _("阳光不再猛烈。");
static const u8 sText_StartedHail[] = _("下起了冰雹！");
static const u8 sText_HailContinues[] = _("冰雹还在持续。");
static const u8 sText_HailStopped[] = _("冰雹停止了。");
static const u8 sText_FailedToSpitUp[] = _("无法使出喷出！");
static const u8 sText_FailedToSwallow[] = _("无法使出吞下！");
static const u8 sText_WindBecameHeatWave[] = _("风变成\n热风了！");
static const u8 sText_StatChangesGone[] = _("能力等级\n都还原成初始状态了！");
static const u8 sText_CoinsScattered[] = _("钱币散落一地！");
static const u8 sText_TooWeakForSubstitute[] = _("HP太低了，\n以致无法制造替身！");
static const u8 sText_SharedPain[] = _("平分了双方的HP！");
static const u8 sText_BellChimed[] = _("铃铛响了起来！");
static const u8 sText_FaintInThree[] = _("受到影响的宝可梦\n将在3回合内倒下！");
static const u8 sText_NoPPLeft[] = _("该技能没有PP，\n无法使用！\p");
static const u8 sText_ButNoPPLeft[] = _("但是该技能没有PP！");
static const u8 sText_PkmnIgnoresAsleep[] = _("{B_ATK_NAME_WITH_PREFIX}在睡眠时\n无法听从命令！");
static const u8 sText_PkmnIgnoredOrders[] = _("{B_ATK_NAME_WITH_PREFIX}无法\n听从命令！");
static const u8 sText_PkmnBeganToNap[] = _("{B_ATK_NAME_WITH_PREFIX}开始打盹了！");
static const u8 sText_PkmnLoafing[] = _("{B_ATK_NAME_WITH_PREFIX}在\n周围闲逛！");
static const u8 sText_PkmnWontObey[] = _("{B_ATK_NAME_WITH_PREFIX}不\n听从命令！");
static const u8 sText_PkmnTurnedAway[] = _("{B_ATK_NAME_WITH_PREFIX}转身离开！");
static const u8 sText_PkmnPretendNotNotice[] = _("{B_ATK_NAME_WITH_PREFIX}假装\n没有注意到！");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n就要换上{B_BUFF2}了。\p{B_PLAYER_NAME}要替换\n宝可梦吗？");
static const u8 sText_PkmnLearnedMove2[] = _("{B_ATK_NAME_WITH_PREFIX}习得了\n{B_BUFF1}！");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("你打败了\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}！\p");
static const u8 sText_CreptCloser[] = _("{B_PLAYER_NAME}悄悄靠近了\n{B_OPPONENT_MON1_NAME}！");
static const u8 sText_CantGetCloser[] = _("{B_PLAYER_NAME}不能再靠近了！");
static const u8 sText_PkmnWatchingCarefully[] = _("{B_OPPONENT_MON1_NAME}小心地\n注视着！");
static const u8 sText_PkmnCuriousAboutX[] = _("{B_OPPONENT_MON1_NAME}对\n{B_BUFF1}感到好奇！");
static const u8 sText_PkmnEnthralledByX[] = _("{B_OPPONENT_MON1_NAME}被\n{B_BUFF1}迷倒了！");
static const u8 sText_PkmnIgnoredX[] = _("{B_OPPONENT_MON1_NAME}完全忽视了\n{B_BUFF1}！");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("{B_PLAYER_NAME}朝{B_OPPONENT_MON1_NAME}投掷了\n{POKEBLOCK}！");
static const u8 sText_OutOfSafariBalls[] = _("{PLAY_SE SE_DING_DONG}提示：\n你用完了原野球！游戏结束！\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME}出现了！\p");
static const u8 sText_WildPkmnAppeared[] = _("野生的{B_OPPONENT_MON1_NAME}跳了出来！\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("野生的{B_OPPONENT_MON1_NAME}跳了出来！\p");
static const u8 sText_WildPkmnAppearedPause[] = _("野生的{B_OPPONENT_MON1_NAME}跳了出来！{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("野生的{B_OPPONENT_MON1_NAME}和\n{B_OPPONENT_MON2_NAME}跳了出来！\p");
static const u8 sText_Trainer1WantsToBattle[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n想要来场对战！\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("{B_LINK_OPPONENT1_NAME}\n想要对战！");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("{B_LINK_OPPONENT1_NAME}和{B_LINK_OPPONENT2_NAME}\n想要对战！");
static const u8 sText_Trainer1SentOutPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n派出了{B_OPPONENT_MON1_NAME}！");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n派出了{B_OPPONENT_MON1_NAME}和{B_OPPONENT_MON2_NAME}！");
static const u8 sText_Trainer1SentOutPkmn2[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n派出了{B_BUFF1}！");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME}派出了\n{B_OPPONENT_MON1_NAME}！");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{B_LINK_OPPONENT1_NAME}派出了\n{B_OPPONENT_MON1_NAME}和{B_OPPONENT_MON2_NAME}！");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME}派出了{B_LINK_OPPONENT_MON1_NAME}！\n{B_LINK_OPPONENT2_NAME}派出了{B_LINK_OPPONENT_MON2_NAME}！");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{B_LINK_OPPONENT1_NAME}派出了\n{B_BUFF1}！");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{B_LINK_SCR_TRAINER_NAME}派出了\n{B_BUFF1}！");
static const u8 sText_GoPkmn[] = _("就决定是你了！{B_PLAYER_MON1_NAME}！");
static const u8 sText_GoTwoPkmn[] = _("就决定是你们了！\n{B_PLAYER_MON1_NAME}、{B_PLAYER_MON2_NAME}！");
static const u8 sText_GoPkmn2[] = _("就决定是你了！{B_BUFF1}！");
static const u8 sText_DoItPkmn[] = _("拜托了！{B_BUFF1}！");
static const u8 sText_GoForItPkmn[] = _("好好加油吧，{B_BUFF1}！");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("对手很虚弱！\n机会来了，{B_BUFF1}！");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("{B_LINK_PARTNER_NAME}派出了{B_LINK_PLAYER_MON2_NAME}！\n去吧！{B_LINK_PLAYER_MON1_NAME}！");
static const u8 sText_PkmnThatsEnough[] = _("{B_BUFF1}，辛苦你了！\n回来吧！");
static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}，回来吧！");
static const u8 sText_PkmnOkComeBack[] = _("{B_BUFF1}\n干得好！回来吧！");
static const u8 sText_PkmnGoodComeBack[] = _("{B_BUFF1}\n做得漂亮！回来吧！");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n收回了{B_BUFF1}！");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{B_LINK_OPPONENT1_NAME}收回了\n{B_BUFF1}！");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{B_LINK_SCR_TRAINER_NAME}收回了\n{B_BUFF1}！");
static const u8 sText_WildPkmnPrefix[] = _("野生的");
static const u8 sText_FoePkmnPrefix[] = _("对方的");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("对方");
static const u8 sText_AllyPkmnPrefix[] = _("我方");
static const u8 sText_FoePkmnPrefix3[] = _("对方");
static const u8 sText_AllyPkmnPrefix2[] = _("我方");
static const u8 sText_FoePkmnPrefix4[] = _("对方");
static const u8 sText_AllyPkmnPrefix3[] = _("我方");
static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX}使用\n{B_BUFF3}！");
static const u8 sText_ExclamationMark[] = _("！");
static const u8 sText_ExclamationMark2[] = _("！");
static const u8 sText_ExclamationMark3[] = _("！");
static const u8 sText_ExclamationMark4[] = _("！");
static const u8 sText_ExclamationMark5[] = _("！");
static const u8 sText_Accuracy[] = _("命中率");
static const u8 sText_Evasiveness[] = _("回避率");

const u8 * const gStatNamesTable[NUM_BATTLE_STATS] =
{
    gText_HP3, gText_Attack, gText_Defense,
    gText_Speed, gText_SpAtk, gText_SpDef,
    sText_Accuracy, sText_Evasiveness
};

static const u8 sText_PokeblockWasTooSpicy[] = _("太辣！");
static const u8 sText_PokeblockWasTooDry[] = _("太涩！");
static const u8 sText_PokeblockWasTooSweet[] = _("太甜！");
static const u8 sText_PokeblockWasTooBitter[] = _("太苦！");
static const u8 sText_PokeblockWasTooSour[] = _("太酸！");

const u8 * const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};

static const u8 sText_PlayerUsedItem[] = _("{B_PLAYER_NAME}使用\n{B_LAST_ITEM}！");
static const u8 sText_WallyUsedItem[] = _("满充使用了\n{B_LAST_ITEM}！");
static const u8 sText_Trainer1UsedItem[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n使用了{B_LAST_ITEM}！");
static const u8 sText_TrainerBlockedBall[] = _("训练家挡下了精灵球！");
static const u8 sText_DontBeAThief[] = _("不要做贼！");
static const u8 sText_ItDodgedBall[] = _("它躲开了精灵球！\n这只宝可梦不能被收服！");
static const u8 sText_YouMissedPkmn[] = _("你错过了这只宝可梦！");
static const u8 sText_PkmnBrokeFree[] = _("哦，不！\n宝可梦逃走了！");
static const u8 sText_ItAppearedCaught[] = _("啊！\n似乎要被抓住了！");
static const u8 sText_AarghAlmostHadIt[] = _("哎呀！\n再加把劲！");
static const u8 sText_ShootSoClose[] = _("可恶！\n就差一点点了！");
static const u8 sText_GotchaPkmnCaught[] = _("搞定！\n{B_DEF_NAME}被收服了！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
static const u8 sText_GotchaPkmnCaught2[] = _("搞定！\n{B_DEF_NAME}被收服了！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("要给{B_DEF_NAME}取一个昵称么？");
static const u8 sText_PkmnSentToPC[] = _("{B_DEF_NAME}被送到了\n{B_PC_CREATOR_NAME}电脑。");
static const u8 sText_Someones[] = _("某人的");
static const u8 sText_Lanettes[] = _("真弓的");
static const u8 sText_PkmnDataAddedToDex[] = _("{B_DEF_NAME}的数据\n登记到了宝可梦图鉴。\p");
static const u8 sText_ItIsRaining[] = _("现在在下雨。");
static const u8 sText_SandstormIsRaging[] = _("沙暴很猛烈。");
static const u8 sText_BoxIsFull[] = _("盒子已经满了！\n不能再收服更多了！\p");
static const u8 sText_EnigmaBerry[] = _("谜之果");
static const u8 sText_BerrySuffix[] = _("树果");
static const u8 sText_PkmnsItemCuredParalysis[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n治愈了麻痹！");
static const u8 sText_PkmnsItemCuredPoison[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n治愈了中毒！");
static const u8 sText_PkmnsItemHealedBurn[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n治愈了灼烧！");
static const u8 sText_PkmnsItemDefrostedIt[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n解除了冰冻！");
static const u8 sText_PkmnsItemWokeIt[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n让它从睡眠中苏醒了！");
static const u8 sText_PkmnsItemSnappedOut[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n使它解除了混乱！");
static const u8 sText_PkmnsItemCuredProblem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n治愈了它的{B_BUFF1}状态！");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n治愈了异常状态！");
static const u8 sText_PkmnsItemRestoredHealth[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n恢复了HP！");
static const u8 sText_PkmnsItemRestoredPP[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n恢复了{B_BUFF1}的PP！");
static const u8 sText_PkmnsItemRestoredStatus[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n治愈了异常状态！");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n稍微恢复了HP！");
static const u8 sText_ItemAllowsOnlyYMove[] = _("{B_LAST_ITEM}只允许\n使用{B_CURRENT_MOVE}！\p");
static const u8 sText_PkmnHungOnWithX[] = _("{B_DEF_NAME_WITH_PREFIX}靠它的\n{B_LAST_ITEM}顶住了！");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("现在要扔出精灵球了是吧？\n我…我会全力以赴！");

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
static const s8 sText_EnduredViaSturdy[] = _("{B_DEF_NAME_WITH_PREFIX} 挺住了\n攻击 {B_DEF_ABILITY}!");
static const s8 sText_PowerHerbActivation[] = _("{B_ATK_NAME_WITH_PREFIX} 完全充能了\n因为它的 {B_LAST_ITEM}!");
static const s8 sText_HurtByItem[] = _("{B_ATK_NAME_WITH_PREFIX}受伤了\n因为它的{B_LAST_ITEM}！");
static const s8 sText_BadlyPoisonedByItem[] = _("{B_EFF_NAME_WITH_PREFIX}中剧毒了\n因为{B_LAST_ITEM}！");
static const s8 sText_BurnedByItem[] = _("{B_EFF_NAME_WITH_PREFIX}烧伤了\n因为{B_LAST_ITEM}！");
static const s8 sText_TargetAbilityActivates[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}发动了！");
static const u8 sText_GravityIntensified[] = _("重力加强了！");
static const u8 sText_TargetIdentified[] = _("{B_DEF_NAME_WITH_PREFIX}被\n识破了！");
static const u8 sText_TargetWokeUp[] = _("{B_DEF_NAME_WITH_PREFIX}醒了！");
static const u8 sText_PkmnStoleAndAteItem[] = _("{B_ATK_NAME_WITH_PREFIX}偷到并\n吃掉了{B_DEF_NAME_WITH_PREFIX}的{B_LAST_ITEM}！");
static const u8 sText_TailWindBlew[] = _("{B_ATK_TEAM2}的身后\n吹起了顺风！");
static const u8 sText_PkmnWentBack[] = _("{B_ATK_NAME_WITH_PREFIX}回\n到{B_ATK_TRAINER_CLASS}{B_ATK_TRAINER_NAME}");
static const u8 sText_PkmnCantUseItemsAnymore[] = _("{B_DEF_NAME_WITH_PREFIX}不能使用\n道具了！");
static const u8 sText_PkmnFlung[] = _("{B_ATK_NAME_WITH_PREFIX}扔掉了\n{B_LAST_ITEM}！");
static const u8 sText_PkmnPreventedFromHealing[] = _("{B_DEF_NAME_WITH_PREFIX}被阻止\n回复！");
static const u8 sText_PkmnSwitchedAtkAndDef[] = _("{B_ATK_NAME_WITH_PREFIX}交换了它的\n攻击和防御！");
static const u8 sText_PkmnsAbilitySuppressed[] = _("{B_DEF_NAME_WITH_PREFIX}的特性\n被压制了！");
static const u8 sText_ShieldedFromCriticalHits[] = _("{B_CURRENT_MOVE}保护{B_ATK_TEAM2}\n的队伍不被击中要害！");
static const u8 sText_SwitchedAtkAndSpAtk[] = _("{B_ATK_NAME_WITH_PREFIX}与目标交换了\n攻击和\p和特攻！");
static const u8 sText_SwitchedDefAndSpDef[] = _("{B_ATK_NAME_WITH_PREFIX}与目标交换了\n防御和\p和特防！");
static const u8 sText_PkmnAcquiredAbility[] = _("{B_DEF_NAME_WITH_PREFIX}获得了\n{B_DEF_ABILITY}！");
static const u8 sText_PoisonSpikesScattered[] = _("毒菱散落在\n对方队伍的脚下！");
static const u8 sText_PkmnSwitchedStatChanges[] = _("{B_ATK_NAME_WITH_PREFIX}与目标交换了\n能力等级！");
static const u8 sText_PkmnSurroundedWithVeilOfWater[] = _("{B_ATK_NAME_WITH_PREFIX}身边围绕着\n一层水幕！");
static const u8 sText_PkmnLevitatedOnElectromagnetism[] = _("{B_ATK_NAME_WITH_PREFIX}通过电磁力\n漂浮了起来！");
static const u8 sText_PkmnTwistedDimensions[] = _("{B_ATK_NAME_WITH_PREFIX}扭曲了\n时空！");
static const u8 sText_PointedStonesFloat[] = _("尖锐的岩石漂浮在了\n {B_DEF_TEAM2} 的队伍周围!");
static const u8 sText_CloakedInMysticalMoonlight[] = _("被神秘的月光\n笼罩!");
static const u8 sText_TrappedBySwirlingMagma[] = _("{B_DEF_NAME_WITH_PREFIX} 被\n旋转的岩浆困住了!");
static const u8 sText_VanishedInstantly[] = _("{B_ATK_NAME_WITH_PREFIX} 突然\n消失了!");
static const u8 sText_ProtectedTeam[] = _("{B_CURRENT_MOVE} 保护了\n{B_ATK_TEAM2} 的队伍!");
static const u8 sText_SharedItsGuard[] = _("{B_ATK_NAME_WITH_PREFIX} 与目标\n平分了防御!");
static const u8 sText_SharedItsPower[] = _("{B_ATK_NAME_WITH_PREFIX} 与目标\n平分了攻击!");
static const u8 sText_SwapsDefAndSpDefOfAllPkmn[] = _("制造出了\n防御与特防能力值互换的奇妙空间!");
static const u8 sText_BecameNimble[] = _("{B_ATK_NAME_WITH_PREFIX} 变得灵活了!");
static const u8 sText_HurledIntoTheAir[] = _("{B_DEF_NAME_WITH_PREFIX} 被投向了\n空中!");
static const u8 sText_HeldItemsLoseEffects[] = _("制造出了\n道具无效的魔法空间!");
static const u8 sText_FellStraightDown[] = _("{B_DEF_NAME_WITH_PREFIX} 被\n击落!");
static const u8 sText_TransformedIntoWaterType[] = _("{B_DEF_NAME_WITH_PREFIX} 变成了\n水属性!");
static const u8 sText_PkmnAcquiredSimple[] = _("{B_DEF_NAME_WITH_PREFIX} 获得了\n单纯!");
static const u8 sText_KindOffer[] = _("{B_DEF_NAME_WITH_PREFIX}\n接受了好意!");
static const u8 sText_ResetsTargetsStatLevels[] = _("{B_DEF_NAME_WITH_PREFIX}的能力\n被清除了!");
static const u8 sText_AllySwitchPosition[] = _("{B_ATK_NAME_WITH_PREFIX} 和\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} 交换了位置!");
static const u8 sText_RestoreTargetsHealth[] = _("{B_DEF_NAME_WITH_PREFIX}的HP回复了!");
static const u8 sText_TookPkmnIntoTheSky[] = _("{B_ATK_NAME_WITH_PREFIX} 把\n{B_DEF_NAME_WITH_PREFIX} 抓向天空!");
static const u8 sText_FreedFromSkyDrop[] = _("{B_DEF_NAME_WITH_PREFIX} 从自由落体状态\n逃脱了!");
static const u8 sText_PostponeTargetMove[] = _("{B_DEF_NAME_WITH_PREFIX}的行动\n延后了!");
static const u8 sText_ReflectTargetsType[] = _("{B_ATK_NAME_WITH_PREFIX}的属性\n变成了 {B_DEF_NAME_WITH_PREFIX}'s!");
static const u8 sText_TransferHeldItem[] = _("{B_DEF_NAME_WITH_PREFIX} 收到了 {B_LAST_ITEM}\n来自 {B_ATK_NAME_WITH_PREFIX}");
static const u8 sText_EmbargoEnds[] = _("{B_ATK_NAME_WITH_PREFIX}可以\n再次使用道具了！");
static const u8 sText_Electromagnetism[] = _("电磁浮游");
static const u8 sText_BufferEnds[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_BUFF1}\n解除了！");
static const u8 sText_ThroatChopEnds[] = _("{B_ATK_NAME_WITH_PREFIX}能再次使用\n声音类招式了！");
static const u8 sText_TelekinesisEnds[] = _("{B_ATK_NAME_WITH_PREFIX}从意念移物\n状态中逃脱了！");
static const u8 sText_TailwindEnds[] = _("{B_ATK_TEAM1}队伍的顺风\n停止了！");
static const u8 sText_LuckyChantEnds[] = _("{B_ATK_TEAM1}队伍的幸运咒语\n结束了！");
static const u8 sText_TrickRoomEnds[] = _("扭曲的空间\n复原了！");
static const u8 sText_WonderRoomEnds[] = _("奇妙空间结束了,防御\n与特防能力值恢复了正常！");
static const u8 sText_MagicRoomEnds[] = _("魔法空间结束了,道具\n效果恢复了正常！");
static const u8 sText_MudSportEnds[] = _("玩泥巴的效果消失了.");
static const u8 sText_WaterSportEnds[] = _("玩水的效果消失了.");
static const u8 sText_GravityEnds[] = _("重力恢复了正常！");
static const u8 sText_AquaRingHeal[] = _("水流环回复了\n{B_ATK_NAME_WITH_PREFIX}'的HP！");
static const u8 sText_TargetAbilityRaisedStat[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n提高了它的{B_BUFF1}！");
static const u8 sText_TargetAbilityLoweredStat[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n降低了它的{B_BUFF1}！");
static const u8 sText_AttackerAbilityRaisedStat[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_ATK_ABILITY}\n提高了它的{B_BUFF1}！");
static const u8 sText_ScriptingAbilityRaisedStat[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n提高了它的{B_BUFF1}！");
static const u8 sText_AuroraVeilEnds[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}\n消失了！");
static const u8 sText_ElectricTerrainEnds[] = _("脚下的电光\n不见了.");
static const u8 sText_MistyTerrainEnds[] = _("脚下的雾气\n不见了.");
static const u8 sText_PsychicTerrainEnds[] = _("脚下奇妙的感觉\n不见了.");
static const u8 sText_GrassyTerrainEnds[] = _("脚下的青草\n不见了.");
static const u8 sText_TargetsStatWasMaxedOut[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}最大化了\n它的{B_BUFF1}！");
static const u8 sText_PoisonHealHpUp[] = _("毒素回复了{B_ATK_NAME_WITH_PREFIX}\n的少量体力！");
static const u8 sText_BadDreamsDmg[] = _("{B_DEF_NAME_WITH_PREFIX}正在被\n折磨\n{B_ATK_ABILITY}！");
static const u8 sText_MoldBreakerEnters[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}打破了常规！");
static const u8 sText_TeravoltEnters[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}正在释放\n溅射气场！");
static const u8 sText_TurboblazeEnters[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}正在释放\n炽热气场！");
static const u8 sText_SlowStartEnters[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}错失先机！");
static const u8 sText_SlowStartEnd[] = _("{B_ATK_NAME_WITH_PREFIX}最终聚集了\n它所有的力量！");
static const u8 sText_SolarPowerHpDrop[] = _("The{B_ATK_NAME_WITH_PREFIX}的{B_ATK_ABILITY}\n受到了伤害！");
static const u8 sText_AftermathDmg[] = _("{B_ATK_NAME_WITH_PREFIX}受伤了！");
static const u8 sText_AnticipationActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}发抖了！");
static const u8 sText_ForewarnActivates[] = _("{B_SCR_ACTIVE_ABILITY}的预知梦预知到了{B_SCR_ACTIVE_NAME_WITH_PREFIX}\n的{B_DEF_NAME_WITH_PREFIX}'s{B_BUFF1}！");
static const u8 sText_IceBodyHpGain[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_ATK_ABILITY}\n回复了少量体力！");
static const u8 sText_SnowWarningHail[] = _("开始下冰雹了！");
static const u8 sText_FriskActivates[] = _("{B_ATK_NAME_WITH_PREFIX}察觉到了{B_DEF_NAME_WITH_PREFIX}\n的{B_LAST_ITEM}！");
static const u8 sText_UnnerveEnters[] = _("对手的队伍太紧张以致于\n无法吃下树果！");
static const u8 sText_HarvestBerry[] = _("{B_ATK_NAME_WITH_PREFIX}收获了\n它的{B_LAST_ITEM}！");
static const u8 sText_LastAbilityRaisedBuff1[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_LAST_ABILITY}\n提高了它的{B_BUFF1}！");
static const u8 sText_MagicBounceActivates[] = _("{B_DEF_NAME_WITH_PREFIX}弹回了\n{B_ATK_NAME_WITH_PREFIX}！");
static const u8 sText_ProteanTypeChange[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_ATK_ABILITY}变身\n成了{B_BUFF1}属性！");
static const u8 sText_SymbiosisItemPass[] = _("{B_ATK_NAME_WITH_PREFIX}通过{B_ATK_ABILITY}把它的{B_LAST_ITEM}\n传递给{B_SCR_ACTIVE_NAME_WITH_PREFIX}！");
static const u8 sText_StealthRockDmg[] = _("锋利的岩石扎进了对手的\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}！");
static const u8 sText_ToxicSpikesAbsorbed[] = _("毒菱从对方的队伍\n周围消失了！");
static const u8 sText_ToxicSpikesPoisoned[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}中毒了！");
static const u8 sText_StickyWebSwitchIn[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}陷入了\n粘网！");
static const u8 sText_HealingWishCameTrue[] = _("治愈之愿降临\n在了{B_ATK_NAME_WITH_PREFIX}！");
static const u8 sText_HealingWishHealed[] = _("{B_ATK_NAME_WITH_PREFIX}恢复了健康！");
static const u8 sText_LunarDanceCameTrue[] = _("{B_ATK_NAME_WITH_PREFIX}被神秘的月光\n笼罩！");
static const u8 sText_CursedBodyDisabled[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_BUFF1}被{B_DEF_NAME_WITH_PREFIX}的{B_DEF_ABILITY}定住了！");
static const u8 sText_AttackerAquiredAbility[] = _("{B_ATK_NAME_WITH_PREFIX}获得了{B_LAST_ABILITY}！");
static const u8 sText_TargetStatWontGoHigher[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_BUFF1}\n不能变得更高了！");
static const u8 sText_PkmnMoveBouncedViaAbility[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_CURRENT_MOVE}被\n{B_DEF_NAME_WITH_PREFIX}的\l{B_DEF_ABILITY}弹回了！");
static const u8 sText_ImposterTransform[] = _("{B_ATK_NAME_WITH_PREFIX}变身成了\n{B_DEF_NAME_WITH_PREFIX}并发动了{B_LAST_ABILITY}！");
static const u8 sText_NotDoneYet[] = _("这个招式的效果还没做完！\p");
static const u8 sText_PkmnBlewAwayToxicSpikes[] = _("{B_ATK_NAME_WITH_PREFIX}清除了\n毒菱！");
static const u8 sText_PkmnBlewAwayStickyWeb[] = _("{B_ATK_NAME_WITH_PREFIX}清除了\n黏黏网！");
static const u8 sText_PkmnBlewAwayStealthRock[] = _("{B_ATK_NAME_WITH_PREFIX}清除了\n隐形岩！");
static const u8 sText_StickyWebUsed[] = _("一张黏黏网展开在了{B_DEF_TEAM2}队伍的周围！");
static const u8 sText_QuashSuccess[] = _("对方{B_ATK_NAME_WITH_PREFIX}的行动延后了！");
static const u8 sText_IonDelugeOn[] = _("离子风暴正在\n肆虐！");
static const u8 sText_TopsyTurvySwitchedStats[] = _("{B_DEF_NAME_WITH_PREFIX}的能力被\n清除了！");
static const u8 sText_TerrainBecomesMisty[] = _("脚下雾气缭绕！");
static const u8 sText_TerrainBecomesGrassy[] = _("脚下绿草如茵！");
static const u8 sText_TerrainBecomesElectric[] = _("脚下电光飞闪！");
static const u8 sText_TerrainBecomesPsychic[] = _("脚下传来了奇妙的感觉！");
static const u8 sText_TargetElectrified[] = _("The {B_DEF_NAME_WITH_PREFIX}的招式\n带电了!");
static const u8 sText_AssaultVestDoesntAllow[] = _("{B_LAST_ITEM} 的效果让这个\n招式无法被使用!\p");
static const u8 sText_GravityPreventsUsage[] = _("{B_ATK_NAME_WITH_PREFIX} 不能使用 {B_CURRENT_MOVE}\n由于重力的影响!\p");
static const u8 sText_HealBlockPreventsUsage[] = _("{B_ATK_NAME_WITH_PREFIX} 无法\n使用治愈招式!\p");
static const u8 sText_MegaEvoReacting[] = _("{B_ATK_NAME_WITH_PREFIX}的 {B_LAST_ITEM} 对 \n{B_ATK_TRAINER_NAME}'s 超级环有反应了!");
static const u8 sText_FerventWishReached[] = _("{B_ATK_TRAINER_NAME}'热切的心意\n传达到了{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_MegaEvoEvolved[] = _("{B_ATK_NAME_WITH_PREFIX} 超级进化为\n超级{B_BUFF1}!");
static const u8 sText_drastically[] = _("巨幅提升 ");
static const u8 sText_severely[] = _("巨幅下降 ");
static const u8 sText_Infestation[] = _("{B_DEF_NAME_WITH_PREFIX} 遭受着\n {B_ATK_NAME_WITH_PREFIX}的死缠烂打!");
static const u8 sText_NoEffectOnTarget[] = _("对{B_DEF_NAME_WITH_PREFIX}\n没有效果！");
static const u8 sText_BurstingFlames[] = _("烈焰溅射到了\n {B_SCR_ACTIVE_NAME_WITH_PREFIX}！");
static const u8 sText_BestowItemGiving[] = _("{B_DEF_NAME_WITH_PREFIX} 从{B_ATK_NAME_WITH_PREFIX}\n收到了 {B_LAST_ITEM}!");
static const u8 sText_ThirdTypeAdded[] = _("{B_BUFF1} 被附加到了\n{B_DEF_NAME_WITH_PREFIX}上");
static const u8 sText_FellForFeint[] = _("{B_DEF_NAME_WITH_PREFIX} 摔倒\n了!");
static const u8 sText_PokemonCannotUseMove[] = _("{B_ATK_NAME_WITH_PREFIX} 无法\n使用 {B_CURRENT_MOVE}!");
static const u8 sText_CoveredInPowder[] = _("{B_DEF_NAME_WITH_PREFIX}被粉尘覆盖！");
static const u8 sText_PowderExplodes[] = _("宝可梦身上的粉尘被火焰碰到后爆炸了！");
static const u8 sText_BelchCantUse[] = _("无法使用打嗝！");
static const u8 sText_SpectralThiefSteal[] = _("{B_ATK_NAME_WITH_PREFIX} 偷取了目标\n提升的能力!");
static const u8 sText_GravityGrounding[] = _("{B_DEF_NAME_WITH_PREFIX} 因为重力\n不能停留空中!");
static const u8 sText_MistyTerrainPreventsStatus[] = _("{B_DEF_NAME_WITH_PREFIX} 的脚下\n雾气缭绕!");
static const u8 sText_GrassyTerrainHeals[] = _("{B_ATK_NAME_WITH_PREFIX}因为青草场地\n恢复了少量HP!");
static const u8 sText_ElectricTerrainPreventsSleep[] = _("{B_DEF_NAME_WITH_PREFIX}的脚下\n电光飞闪!");
static const u8 sText_PsychicTerrainPreventsPriority[] = _("{B_DEF_NAME_WITH_PREFIX}的脚下\n传来了奇妙的感觉!");
static const u8 sText_SafetyGooglesProtected[] = _("多亏了它的{B_LAST_ITEM}\n{B_DEF_NAME_WITH_PREFIX}没有起效果!");
static const u8 sText_FlowerVeilProtected[] = _("{B_DEF_NAME_WITH_PREFIX}用花幕\n包裹了自己!");
static const u8 sText_SweetVeilProtected[] = _("{B_DEF_NAME_WITH_PREFIX}用甜幕\n包裹了自己!");
static const u8 sText_AromaVeilProtected[] = _("{B_DEF_NAME_WITH_PREFIX}被芳香幕\n保护了!");
static const u8 sText_CelebrateMessage[] = _("祝贺, {B_PLAYER_NAME}!");
static const u8 sText_UsedInstructedMove[] = _("由于号令的{B_BUFF1}\n{B_ATK_NAME_WITH_PREFIX}使出了招式!");
static const u8 sText_LaserFocusMessage[] = _("{B_ATK_NAME_WITH_PREFIX}\n高度集中!");
static const u8 sText_GemActivates[] = _("{B_LAST_ITEM} 增强了\n{B_ATK_NAME_WITH_PREFIX}的力量!");
static const u8 sText_BerryDmgReducing[] = _("{B_LAST_ITEM}为{B_DEF_NAME_WITH_PREFIX}\n减少了伤害!");
static const u8 sText_TargetAteItem[] = _("{B_DEF_NAME_WITH_PREFIX}吃掉了它的{B_LAST_ITEM}!");
static const u8 sText_AirBalloonFloat[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}用它的{B_LAST_ITEM}\n飘在了空中!");
static const u8 sText_AirBalloonPop[] = _("{B_DEF_NAME_WITH_PREFIX}的{B_LAST_ITEM}破了!");
static const u8 sText_IncinerateBurn[] = _("{B_EFF_NAME_WITH_PREFIX}的{B_LAST_ITEM}\n被烧掉了!");
static const u8 sText_BugBite[] = _("{B_ATK_NAME_WITH_PREFIX} 偷走并吃掉了\n{B_EFF_NAME_WITH_PREFIX}的{B_LAST_ITEM}!");
static const u8 sText_IllusionWoreOff[] = _("{B_DEF_NAME_WITH_PREFIX}的幻象被识破了!");
static const u8 sText_AttackerCuredTargetStatus[] = _("{B_ATK_NAME_WITH_PREFIX} 治愈了\n{B_DEF_NAME_WITH_PREFIX}的问题!");
static const u8 sText_AttackerLostFireType[] = _("{B_ATK_NAME_WITH_PREFIX} 燃尽了自己！");
static const u8 sText_HealerCure[] = _("{B_ATK_NAME_WITH_PREFIX}的{B_LAST_ABILITY}\n治愈了{B_SCR_ACTIVE_NAME_WITH_PREFIX}的问题!");
static const u8 sText_ReceiverAbilityTakeOver[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的 {B_SCR_ACTIVE_ABILITY}\n被继承了!");
static const u8 sText_PkmnAbsorbingPower[] = _("{B_ATK_NAME_WITH_PREFIX}正在吸收力量!");
static const u8 sText_NoOneWillBeAbleToRun[] = _("在下一回合中\n没有宝可梦能够逃跑！");
static const u8 sText_DestinyKnotActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} 爱上了\n因为 {B_LAST_ITEM}!");
static const u8 sText_CloakedInAFreezingLight[] = _("{B_ATK_NAME_WITH_PREFIX} 被冷光\n包围了!");
static const u8 sText_StatWasNotLowered[] = _("{B_DEF_NAME_WITH_PREFIX}的 {B_BUFF1}\n没有被降低!");
static const u8 sText_AuraFlaredToLife[] = _("{B_DEF_NAME_WITH_PREFIX}灵光焕发!");
static const u8 sText_AirLockActivates[] = _("天气带来的效果\n消失了。");
static const u8 sText_PressureActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}正在施加\n压迫感！");
static const u8 sText_DarkAuraActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}正在释放\n暗黑气场！");
static const u8 sText_FairyAuraActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}正在释放\n妖精气场！");
static const u8 sText_AuraBreakActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}反转了所有\n其它宝可梦的气场！");
static const u8 sText_ComatoseActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}正在打瞌睡！");
static const u8 sText_ScreenCleanerActivates[] = _("所有的墙都被\n清除了！");
static const u8 sText_FetchedPokeBall[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}回收了\n一个{B_LAST_ITEM}！");
static const u8 sText_BattlerAbilityRaisedStat[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}的{B_SCR_ACTIVE_ABILITY}\n提高了它的{B_BUFF1}！");
static const u8 sText_ASandstormKickedUp[] = _("刮起了沙暴！");
static const u8 sText_PkmnsWillPerishIn3Turns[] = _("所有宝可梦都会在\n三回合后倒下！");
static const u8 sText_AbilityRaisedStatDrastically[] = _("{B_DEF_ABILITY}巨幅提升了{B_DEF_NAME_WITH_PREFIX}的\n{B_BUFF1}！");
static const u8 sText_AsOneEnters[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}同时具备两种特性！");
static const u8 sText_CuriousMedicineEnters[] = _("{B_EFF_NAME_WITH_PREFIX}的\n能力变化还原了！");
static const u8 sText_CanActFaster[] = _("多亏了{B_LAST_ITEM}，\n{B_ATK_NAME_WITH_PREFIX}能更快地行动！");
static const u8 sText_MicleBerryActivates[] = _("通过使用{B_LAST_ITEM}\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}提高了它的命中率！");
static const u8 sText_PkmnShookOffTheTaunt[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}从挑衅状态中\n解除了！");
static const u8 sText_PkmnGotOverItsInfatuation[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}不再迷恋\n对方了！");

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
    [STRINGID_PLAYERGOTITEM - 12] = sText_PlayerGotItem,
    [STRINGID_PLAYERGOTITEM2 - 12] = sText_PlayerGotItem2,
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

const u8 gText_PkmnIsEvolving[] = _("咦？\n{STR_VAR_1}开始进化了！");
const u8 gText_CongratsPkmnEvolved[] = _("恭喜！你的{STR_VAR_1}\n进化成{STR_VAR_2}！{WAIT_SE}A\p");
const u8 gText_PkmnStoppedEvolving[] = _("嗯？{STR_VAR_1}\n停止进化了！\p");
const u8 gText_EllipsisQuestionMark[] = _("……？\p");
const u8 gText_WhatWillPkmnDo[] = _("想要\n{B_ACTIVE_NAME2}做什么？");
const u8 gText_WhatWillPkmnDo2[] = _("想要\n{B_PLAYER_NAME}做什么？");
const u8 gText_WhatWillWallyDo[] = _("满充要做\n什么？");
const u8 gText_LinkStandby[] = _("{PAUSE 16}准备连线中…");
const u8 gText_BattleMenu[] = _("战斗{CLEAR_TO 56}背包\n宝可梦{CLEAR_TO 56}逃跑");
const u8 gText_SafariZoneMenu[] = _("精灵球{CLEAR_TO 56}{POKEBLOCK}\n靠近{CLEAR_TO 56}逃跑");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("属性/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\n属性/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}要忘记\n哪个技能？");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}是\n否");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}与哪个\n换位？");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

// Unused
static const u8 * const sStatNamesTable2[] =
{
    gText_HP3, gText_SpAtk, gText_Attack,
    gText_SpDef, gText_Defense, gText_Speed
};

const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GRAY}狩猎球");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GRAY}Left: $" "{HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("睡眠");
const u8 gText_Poison[] = _("中毒");
const u8 gText_Burn[] = _("灼烧");
const u8 gText_Paralysis[] = _("麻痹");
const u8 gText_Ice[] = _("冰冻");
const u8 gText_Confusion[] = _("混乱");
const u8 gText_Love[] = _("着迷");
const u8 gText_SpaceAndSpace[] = _("和");
const u8 gText_CommaSpace[] = _("，");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("是");
const u8 gText_Are2[] = _("是");
const u8 gText_BadEgg[] = _("坏蛋");
const u8 gText_BattleWallyName[] = _("满充");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}胜");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}败");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}和");
static const u8 sText_SpaceIs[] = _("是");
static const u8 sText_ApostropheS[] = _("的");

// For displaying names of invalid moves
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][17] =
{
    [TYPE_NORMAL] = _("一般属性招式"),
    [TYPE_FIGHTING] = _("格斗属性招式"),
    [TYPE_FLYING] = _("飞行属性招式"),
    [TYPE_POISON] = _("毒属性招式"),
    [TYPE_GROUND] = _("地面属性招式"),
    [TYPE_ROCK] = _("岩石属性招式"),
    [TYPE_BUG] = _("虫属性招式"),
    [TYPE_GHOST] = _("鬼属性招式"),
    [TYPE_STEEL] = _("钢属性招式"),
    [TYPE_MYSTERY] = _("未知属性招式"),
    [TYPE_FIRE] = _("火属性招式"),
    [TYPE_WATER] = _("水属性招式"),
    [TYPE_GRASS] = _("草属性招式"),
    [TYPE_ELECTRIC] = _("电属性招式"),
    [TYPE_PSYCHIC] = _("超能力属性招式"),
    [TYPE_ICE] = _("冰属性招式"),
    [TYPE_DRAGON] = _("龙属性招式"),
    [TYPE_DARK] = _("恶属性招式"),
    [TYPE_FAIRY] = _("妖精属性招式"),
};

const u8 gText_BattleTourney[] = _("战斗巡回赛");
static const u8 sText_Round1[] = _("第1回合");
static const u8 sText_Round2[] = _("第2回合");
static const u8 sText_Semifinal[] = _("半决赛");
static const u8 sText_Final[] = _("决赛");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = sText_Round1,
    [DOME_ROUND2]    = sText_Round2,
    [DOME_SEMIFINAL] = sText_Semifinal,
    [DOME_FINAL]     = sText_Final
};

const u8 gText_TheGreatNewHope[] = _("伟大的新希望!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("冠军梦会实现吗？！\p");
const u8 gText_AFormerChampion[] = _("曾经的冠军！\p");
const u8 gText_ThePreviousChampion[] = _("上届冠军！\p");
const u8 gText_TheUnbeatenChampion[] = _("不败的冠军！\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("对决");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("头脑");
const u8 gText_Skill[] = _("技巧");
const u8 gText_Body[] = _("身体");
const u8 gText_Judgement[] = _("{B_BUFF1}{CLEAR 13}判定{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}派出了\n{B_OPPONENT_MON1_NAME}！\p{B_TRAINER2_CLASS} {B_TRAINER2_NAME}派出了\n{B_OPPONENT_MON2_NAME}！");
static const u8 sText_Trainer2SentOutPkmn[] = _("{B_TRAINER2_CLASS} {B_TRAINER2_NAME}派出了\n{B_BUFF1}！");
static const u8 sText_TwoTrainersWantToBattle[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}和\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\l想要对战！\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{B_PARTNER_CLASS} {B_PARTNER_NAME}派出了\n{B_PLAYER_MON2_NAME}！\l去吧，{B_PLAYER_MON1_NAME}！");
static const u8 sText_TwoInGameTrainersDefeated[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME}和\n{B_TRAINER2_CLASS}{B_TRAINER2_NAME}\l被打败了！\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("{B_ATK_NAME_WITH_PREFIX}似乎无法\n使出力量！");
static const u8 sText_GlintAppearsInEye[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}眼中闪烁\n着亮光！");
static const u8 sText_PkmnGettingIntoPosition[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}准备\n就位！");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}发出了咆哮！");
static const u8 sText_PkmnEagerForMore[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}想要更多！");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

static const u8 sText_RefIfNothingIsDecided[] = _("裁判：如果3回合无法决出胜负，\n将由我们来裁定结果！");
static const u8 sText_RefThatsIt[] = _("裁判：到此为止！现在将由我们\n裁定谁是胜利者！");
static const u8 sText_RefJudgeMind[] = _("裁判：判定类别 1，头脑！\n宝可梦展示出最大勇气！\p");
static const u8 sText_RefJudgeSkill[] = _("裁判：判定类别 2，技巧！\n宝可梦最优化使用技能！\p");
static const u8 sText_RefJudgeBody[] = _("裁判：判定类别 3，身体！\n宝可梦拥有最强生命力！\p");
static const u8 sText_RefPlayerWon[] = _("裁判：裁定结果：{B_BUFF1}与{B_BUFF2}！\n胜利者是{B_PLAYER_NAME}的{B_PLAYER_MON1_NAME}！\p");
static const u8 sText_RefOpponentWon[] = _("裁判：裁定结果：{B_BUFF1}与{B_BUFF2}！\n胜利者是{B_TRAINER1_NAME}的{B_DEF_NAME}！\p");
static const u8 sText_RefDraw[] = _("裁判：裁定结果：3比3！\n你们打成了平手！\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("裁判裁定{B_PLAYER_MON1_NAME}击败了\n对手{B_OPPONENT_MON1_NAME}！");
static const u8 sText_LostToOpponentByReferee[] = _("裁判裁定{B_PLAYER_MON1_NAME}输给了\n对手{B_OPPONENT_MON1_NAME}！");
static const u8 sText_TiedOpponentByReferee[] = _("裁判裁定{B_PLAYER_MON1_NAME}与\n{B_OPPONENT_MON1_NAME}打成了平手！");
static const u8 sText_RefCommenceBattle[] = _("裁判：{B_PLAYER_MON1_NAME}对抗{B_OPPONENT_MON1_NAME}！\n战斗开始！");

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

static const u8 sText_QuestionForfeitMatch[] = _("想放弃参赛资格，\n并退出比赛吗？");
static const u8 sText_ForfeitedMatch[] = _("{B_PLAYER_NAME}放弃了参赛资格！");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _("{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS}{B_TRAINER1_NAME}逃跑了！");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("你输给了\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}！");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("你跟\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}打成了平手！");
const u8 gText_RecordBattleToPass[] = _("你想将这场对战记录\n在你的开拓区通行证上吗？");
const u8 gText_BattleRecordedOnPass[] = _("{B_PLAYER_NAME}的对战结果\n已经记录在开拓区通行证上了。");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("{B_LINK_OPPONENT1_NAME}\n想要对战！{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("{B_LINK_OPPONENT1_NAME}和{B_LINK_OPPONENT2_NAME}\n想要对战！{PAUSE 49}");
static const u8 sText_Your1[] = _("我方");
static const u8 sText_Opposing1[] = _("对方");
static const u8 sText_Your2[] = _("我方");
static const u8 sText_Opposing2[] = _("对方");

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
