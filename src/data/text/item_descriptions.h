#include "config.h"

static const u8 sDummyDesc[] = _(
    "?????");

#ifdef CHINESE //TODO 补充汉化及分行
// Pokeballs
static const u8 sMasterBallDesc[] = _(
    "必定能捉到野生宝可梦的，性能\n"
    "最好的球。");

static const u8 sUltraBallDesc[] = _(
    "比起超级球来更容易捉到宝可梦\n"
    "的，性能非常不错的球。");

static const u8 sGreatBallDesc[] = _(
    "比起精灵球来更容易捉到宝可梦\n"
    "的，性能还算不错的球。");

static const u8 sPokeBallDesc[] = _(
    "用于投向野生宝可梦并将其捕捉\n"
    "的球。它是胶囊样式的。");

static const u8 sSafariBallDesc[] = _(
    "曾在狩猎地带被使用。是一种特\n"
    "殊的球。");

static const u8 sNetBallDesc[] = _(
    "有点与众不同的球。能很容易地\n"
    "捕捉水属性和虫属性的宝可梦。");

static const u8 sDiveBallDesc[] = _(
    "有点与众不同的球。能很容易地\n"
    "捕捉生活在水世界里的宝可梦。");

static const u8 sNestBallDesc[] = _(
    "有点与众不同的球。捕捉的野生\n"
    "宝可梦越弱，就会越容易捕捉。");

static const u8 sRepeatBallDesc[] = _(
    "有点与众不同的球。能很容易地\n"
    "捕捉以前曾捉到过的宝可梦。");

static const u8 sTimerBallDesc[] = _(
    "有点与众不同的球。回合数花费\n"
    "得越多，宝可梦就会越容易捕捉。");

static const u8 sLuxuryBallDesc[] = _(
    "住着十分惬意的球。捉到的野生宝可梦会变得容易和训练家亲密。");

static const u8 sPremierBallDesc[] = _(
    "住着十分惬意的球。捉到的野生\n"
    "宝可梦会变得容易和训练家亲密。");

static const u8 sLevelBallDesc[] = _(
    "有点与众不同的球。要捕捉的\n"
    "宝可梦比自己宝可梦的等级\n"
    "越低，就会越容易捕捉。");

static const u8 sLureBallDesc[] = _(
    "有点与众不同的球。能很容易\n"
    "地捕捉用钓竿钓上来的宝可梦。");

static const u8 sMoonBallDesc[] = _(
    "有点与众不同的球。能很容易\n"
    "地捕捉使用月之石进化的宝可梦。");

static const u8 sFriendBallDesc[] = _(
    "有点与众不同的球。捉到的\n"
    "野生宝可梦会立刻变得和训\n"
    "练家亲密起来。");

static const u8 sLoveBallDesc[] = _(
    "有点与众不同的球。能很容易\n"
    "地捕捉和自己宝可梦性\n"
    "别不同的宝可梦。");

static const u8 sHeavyBallDesc[] = _(
    "有点与众不同的球。能很容易\n"
    "地捕捉身体沉重的宝可梦。");

static const u8 sFastBallDesc[] = _(
    "有点与众不同的球。能很容易\n"
    "地捕捉逃跑速度很快的宝可梦。");

static const u8 sHealBallDesc[] = _(
    "有点温柔的球。能回复捉到的\n"
    "宝可梦的HP并治愈异常状态。");

static const u8 sQuickBallDesc[] = _(
    "有点与众不同的球。如果战斗\n"
    "开始后立刻使用，就能\n"
    "很容易地捉到宝可梦。");

static const u8 sDuskBallDesc[] = _(
    "有点与众不同的球。能很容易\n"
    "地在夜晚或洞窟等阴暗\n"
    "的地方捕捉宝可梦。");

static const u8 sCherishBallDesc[] = _(
    "相当珍贵的球。特制出来的\n"
    "某种纪念品。");

static const u8 sSportBallDesc[] = _(
    "曾在城都地区的捕虫大赛上\n"
    "使用的特殊的球。");

static const u8 sParkBallDesc[] = _(
    "在伙伴公园里使用的特殊的球。");

static const u8 sDreamBallDesc[] = _(
    "在连入之森中，不知何时出现\n"
    "在包包里的梦中球。能捉到任\n"
    "何宝可梦。");

static const u8 sBeastBallDesc[] = _(
    "为捕捉究极异兽而制作的特殊\n"
    "精灵球。很难捕捉究极异兽之\n"
    "外的宝可梦。");

// Medicine
static const u8 sPotionDesc[] = _(
    "喷雾式伤药。能让1只宝可梦\n"
    "回复20HP。");

static const u8 sAntidoteDesc[] = _(
    "喷雾式药水。能治愈1只宝可梦\n"
    "的中毒状态。");

static const u8 sBurnHealDesc[] = _(
    "喷雾式药水。能治愈1只宝可梦\n"
    "的灼伤状态。");

static const u8 sIceHealDesc[] = _(
    "喷雾式药水。能治愈1只宝可梦\n"
    "的冰冻状态。");

static const u8 sAwakeningDesc[] = _(
    "喷雾式药水。能治愈1只宝可梦\n"
    "的睡眠状态。");

static const u8 sParalyzeHealDesc[] = _(
    "喷雾式药水。能治愈1只宝可梦\n"
    "的麻痹状态。");

static const u8 sFullRestoreDesc[] = _(
    "能回复1只宝可梦的所有HP并\n"
    "治愈所有异常状态。");

static const u8 sMaxPotionDesc[] = _(
    "喷雾式伤药。能让1只宝可梦\n"
    "回复所有HP。");

static const u8 sHyperPotionDesc[] = _(
    "喷雾式伤药。能让1只宝可梦\n"
    "回复120HP。");

static const u8 sSuperPotionDesc[] = _(
    "喷雾式伤药。能让1只宝可梦\n"
    "回复60HP。");

static const u8 sFullHealDesc[] = _(
    "喷雾式药水。能治愈1只宝可梦\n"
    "的所有异常状态。");

static const u8 sReviveDesc[] = _(
    "能让1只陷入濒死的宝可梦重获\n"
    "生机，并回复一半HP。");

static const u8 sMaxReviveDesc[] = _(
    "能让1只陷入濒死的宝可梦重获\n"
    "生机，并回复所有HP。");

static const u8 sFreshWaterDesc[] = _(
    "富含矿物质的水。能让1只宝可\n"
    "梦回复30HP。");

static const u8 sSodaPopDesc[] = _(
    "翻腾着气泡的汽水。能让1只\n"
    "宝可梦回复50HP。");

static const u8 sLemonadeDesc[] = _(
    "非常香甜的牛奶。能让1只宝可\n"
    "梦回复70HP。");

static const u8 sMoomooMilkDesc[] = _(
    "营养百分百的牛奶。能让1只宝\n"
    "可梦回复100HP。");

static const u8 sEnergyPowderDesc[] = _(
    "非常苦的药粉。能让1只宝可梦\n"
    "回复60HP。");

static const u8 sEnergyRootDesc[] = _(
    "非常苦的根。能让1只宝可梦\n"
    "回复120HP。");

static const u8 sHealPowderDesc[] = _(
    "非常苦的药粉。能治愈1只宝可\n"
    "梦的所有异常状态。");

static const u8 sRevivalHerbDesc[] = _(
    "非常苦的药草。能让1只濒死的\n"
    "宝可梦回复所有HP。");

static const u8 sEtherDesc[] = _(
    "能让宝可梦学会的其中1个招式\n"
    "回复10PP。");

static const u8 sMaxEtherDesc[] = _(
    "能让宝可梦学会的其中1个\n"
    "招式回复所有PP。");

static const u8 sElixirDesc[] = _(
    "能让宝可梦学会的4个招式\n"
    "各回复10PP。");

static const u8 sMaxElixirDesc[] = _(
    "能让宝可梦学会的4个招式\n"
    "回复所有PP。");

static const u8 sLavaCookieDesc[] = _(
    "釜炎特产的仙贝。能治愈1\n"
    "只宝可梦的所有异常状态。");

static const u8 sBlueFluteDesc[] = _(
    "以蓝色玻璃制成的哨子。可\n"
    "以治愈睡眠状态。");

static const u8 sYellowFluteDesc[] = _(
    "以黄色玻璃制成的哨子。可以\n"
    "治愈混乱状态。");

static const u8 sRedFluteDesc[] = _(
    "以红色玻璃制成的哨子。可以\n"
    "治愈着迷状态。");

static const u8 sBlackFluteDesc[] = _(
    "以黑色玻璃制成的哨子。在使\n"
    "用的地方更容易遇到强大的\n"
    "宝可梦。");

static const u8 sWhiteFluteDesc[] = _(
    "以白色玻璃制成的哨子。在\n"
    "使用的地方更容易遇到弱小\n"
    "的宝可梦。");

static const u8 sBerryJuiceDesc[] = _(
    "100%树果果汁。能让1只宝\n"
    "可梦回复20HP。");

static const u8 sSweetHeartDesc[] = _(
    "非常甜腻的巧克力。能让1只\n"
    "宝可梦回复20HP。");

static const u8 sBigMalasadaDesc[] = _(
    "阿罗拉特产的油炸面包。能治\n"
    "愈1只宝可梦的所有异常状态。");

static const u8 sOldGateauDesc[] = _(
    "百代不为人知的特产。能治\n"
    "愈1只宝可梦的所有异常状态。");

static const u8 sSacredAshDesc[] = _(
    "能让陷入濒死的全部宝可梦\n"
    "回复所有HP。");

// Collectibles
static const u8 sShoalSaltDesc[] = _(
    "在浅滩洞穴这地方找到\n"
    "的海盐。");

static const u8 sShoalShellDesc[] = _(
    "在浅滩洞穴这地方找到\n"
    "的贝壳。");

static const u8 sRedShardDesc[] = _(
    "红色的小碎片。好像是以前\n"
    "制作的某道具的一部分。");

static const u8 sBlueShardDesc[] = _(
    "蓝色的小碎片。好像是以前\n"
    "制作的某道具的一部分。");

static const u8 sYellowShardDesc[] = _(
    "黄色的小碎片。好像是以前\n"
    "制作的某道具的一部分。");

static const u8 sGreenShardDesc[] = _(
    "绿色的小碎片。好像是以前\n"
    "制作的某道具的一部分。");

// Vitamins
static const u8 sHPUpDesc[] = _(
    "宝可梦的营养饮料。能提高\n"
    "1只宝可梦的HP的基础点数。");

static const u8 sProteinDesc[] = _(
    "宝可梦的营养饮料。能提高\n"
    "1只宝可梦的攻击的基础点数。");

static const u8 sIronDesc[] = _(
    "宝可梦的营养饮料。能提高\n"
    "1只宝可梦的防御的基础点数。");

static const u8 sCarbosDesc[] = _(
    "宝可梦的营养饮料。能提高\n"
    "1只宝可梦的速度的基础点数。");

static const u8 sCalciumDesc[] = _(
    "宝可梦的营养饮料。能提高\n"
    "1只宝可梦的特攻的基础点数。");

static const u8 sRareCandyDesc[] = _(
    "宝可梦的等级提高1。");

static const u8 sPPUpDesc[] = _(
    "能让宝可梦学会的其中1个招\n"
    "式的PP最大值少量提高");

static const u8 sZincDesc[] = _(
    "宝可梦的营养饮料。能提高\n"
    "1只宝可梦的特防的基础点数。");

static const u8 sPPMaxDesc[] = _(
    "能将宝可梦学会的其中1个招\n"
    "式的PP最大值提至最高。");

// Battle items
static const u8 sGuardSpecDesc[] = _(
    "在战斗中，5回合内不让我方\n"
    "能力降低的道具。");

static const u8 sDireHitDesc[] = _(
    "击中要害的几率会大幅提高。\n"
    "只能使用1次。离场后，效果\n"
    "便会消失。");

static const u8 sXAttackDesc[] = _(
    "大幅提高战斗中宝可梦攻击\n"
    "的道具。离场后，效果便会\n"
    "消失。");

static const u8 sXDefendDesc[] = _(
    "大幅提高战斗中宝可梦防御\n"
    "的道具。离场后，效果便会\n"
    "消失。");

static const u8 sXSpeedDesc[] = _(
    "大幅提高战斗中宝可梦速度\n"
    "的道具。离场后，效果便会\n"
    "消失。");

static const u8 sXAccuracyDesc[] = _(
    "大幅提高战斗中宝可梦命中\n"
    "的道具。离场后，效果便会\n"
    "消失。");

static const u8 sXSpecialAttackDesc[] = _(
    "大幅提高战斗中宝可梦特攻\n"
    "的道具。离场后，效果便会\n"
    "消失。");

static const u8 sXSpecialDefenseDesc[] = _(
    "大幅提高战斗中宝可梦特防\n"
    "的道具。离场后，效果便会\n"
    "消失。");

static const u8 sPokeDollDesc[] = _(
    "能吸引宝可梦注意的道具。\n"
    "在和野生宝可梦的战斗中绝\n"
    "对可以逃走。");

static const u8 sFluffyTailDesc[] = _(
    "能吸引宝可梦注意的道具。\n"
    "在和野生宝可梦的战斗中绝\n"
    "对可以逃走。");

// Field items
static const u8 sSuperRepelDesc[] = _(
    "弱小的野生宝可梦将完全不\n"
    "会出现。效果比除虫喷雾更\n"
    "持久。");

static const u8 sMaxRepelDesc[] = _(
    "弱小的野生宝可梦将完全不\n"
    "会出现。效果比白银喷雾更\n"
    "持久。");

static const u8 sAbilityCapsuleDesc[] = _(
    "使用后会改变宝可梦的特性。");

static const u8 sEscapeRopeDesc[] = _(
    "结实的长绳。可以从洞窟或\n"
    "迷宫中脱身。");

static const u8 sRepelDesc[] = _(
    "使用后，在较短的一段时间\n"
    "内，弱小的野生宝可梦将完\n"
    "全不会出现。");

// Evolution stones
static const u8 sSunStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。像太阳一样赤红。");

static const u8 sMoonStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。像夜空一样乌黑。");

static const u8 sFireStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。看上去是橙黄色的。");

static const u8 sThunderStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。有着闪电般的花纹。");

static const u8 sWaterStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。看上去是澄蓝色的。");

static const u8 sLeafStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。有着叶子般的花纹。");

static const u8 sDawnStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。像眼眸一般光彩动人。");

static const u8 sDuskStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。像黑夜一般漆黑。");

static const u8 sShinyStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。像光芒一样耀眼。");

static const u8 sIceStoneDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇石头。有着雪花般的花纹。");

// Valuable items

static const u8 sRedApricornDesc[] = _(
    "红色的球果。有种刺鼻的气味。");

static const u8 sBlueApricornDesc[] = _(
    "蓝色的球果。略有一股青草\n"
    "的香味。");

static const u8 sYellowApricornDesc[] = _(
    "黄色的球果。有种清爽的香味。");

static const u8 sGreenApricornDesc[] = _(
    "绿色的球果。有种焦香的香味，\n"
    "非常神奇。");

static const u8 sPinkApricornDesc[] = _(
    "粉红色的球果。有种甜甜的，\n"
    "好闻的香味。");

static const u8 sWhiteApricornDesc[] = _(
    "白色的球果。没有任何气味。");

static const u8 sBlackApricornDesc[] = _(
    "黑色的球果。有种无法形容\n"
    "的气味。");

static const u8 sTinyMushroomDesc[] = _(
    "珍稀的小蘑菇。在一些爱好\n"
    "者中有着相当高的人气。");

static const u8 sBigMushroomDesc[] = _(
    "珍稀的大蘑菇。在一些爱好\n"
    "者中有着非常高的人气。");

static const u8 sPearlDesc[] = _(
    "散发着美丽银辉且有点小的\n"
    "珍珠。可以在商店低价出售。");

static const u8 sBigPearlDesc[] = _(
    "散发着美丽银辉且相当大颗\n"
    "的珍珠。可以在商店高价出售。");

static const u8 sStardustDesc[] = _(
    "手感细腻且十分美丽的红色\n"
    "沙子。可以在商店低价出售。");

static const u8 sStarPieceDesc[] = _(
    "闪着红光且十分美丽的宝石\n"
    "碎片。可以在商店高价出售。");

static const u8 sNuggetDesc[] = _(
    "闪着金光，以纯金制成的珠\n"
    "子。可以在商店高价出售。");

static const u8 sHeartScaleDesc[] = _(
    "有着美丽心形外形且非常珍稀的鳞片。有些人收到会很高兴。");

static const u8 sRedNectarDesc[] = _(
    "在乌拉乌拉花园里获得的花蜜。可以改变特定宝可梦的样子。");

static const u8 sYellowNectarDesc[] = _(
    "在美乐美乐花园里获得的花蜜。可以改变特定宝可梦的样子。");

static const u8 sPinkNectarDesc[] = _(
    "在皇家大道的花园里获得的花蜜。可以改变特定宝可梦的样子。");

static const u8 sPurpleNectarDesc[] = _(
    "在波尼花园里获得的花蜜。可以改变特定宝可梦的样子。");

static const u8 sRareBoneDesc[] = _(
    "在宝可梦考古学上非常贵重\n"
    "的骨头。可以在商店高价出售。");

// Mail
static const u8 sOrangeMailDesc[] = _(
    "印有蛇纹熊的信纸，可以让\n"
    "宝可梦携带。");

static const u8 sHarborMailDesc[] = _(
    "印有长翅鸥的信纸，可以让\n"
    "宝可梦携带。");

static const u8 sGlitterMailDesc[] = _(
    "印有皮卡丘的信纸，可以让\n"
    "宝可梦携带。");

static const u8 sMechMailDesc[] = _(
    "印有小磁怪的信纸，可以让\n"
    "宝可梦携带。");

static const u8 sWoodMailDesc[] = _(
    "印有懒人獭的信纸，可以让\n"
    "宝可梦携带。");

static const u8 sWaveMailDesc[] = _(
    "印有吼吼鲸的信纸，可以让\n"
    "宝可梦携带。");

static const u8 sBeadMailDesc[] = _(
    "一张能显示持有者的图像的\n"
    "信纸，可以让宝可梦携带。");

static const u8 sShadowMailDesc[] = _(
    "印有夜巡灵的信纸，可以让\n"
    "宝可梦携带。");

static const u8 sTropicMailDesc[] = _(
    "印有美丽花的信纸，可以让\n"
    "宝可梦携带。");

static const u8 sDreamMailDesc[] = _(
    "一张能显示持有者的图像的\n"
    "信纸，可以让宝可梦携带。");

static const u8 sFabMailDesc[] = _(
    "一张华丽的信纸，可以让宝\n"
    "可梦携带。");

static const u8 sRetroMailDesc[] = _(
    "印有三种宝可梦的信纸，可\n"
    "以让宝可梦携带。");

// Berries
static const u8 sCheriBerryDesc[] = _(
    "让宝可梦携带后，可以治愈\n"
    "麻痹。");

static const u8 sChestoBerryDesc[] = _(
    "让宝可梦携带后，可以治愈\n"
    "睡眠。");

static const u8 sPechaBerryDesc[] = _(
    "让宝可梦携带后，可以治愈\n"
    "中毒。");

static const u8 sRawstBerryDesc[] = _(
    "让宝可梦携带后，可以治愈\n"
    "灼伤。");

static const u8 sAspearBerryDesc[] = _(
    "让宝可梦携带后，可以治愈\n"
    "冰冻。");

static const u8 sLeppaBerryDesc[] = _(
    "让宝可梦携带后，可以回复\n"
    "10PP。");

static const u8 sOranBerryDesc[] = _(
    "让宝可梦携带后，可以回复\n"
    "10HP。");

static const u8 sPersimBerryDesc[] = _(
    "让宝可梦携带后，可以治愈\n"
    "混乱。");

static const u8 sLumBerryDesc[] = _(
    "让宝可梦携带后，可以治愈\n"
    "所有异常状态。");

static const u8 sSitrusBerryDesc[] = _(
    "让宝可梦携带后，可以回复\n"
    "少量HP。");

static const u8 sFigyBerryDesc[] = _(
    "让宝可梦携带后，危机时可\n"
    "以回复HP。如果讨厌这味道就会混乱。");

static const u8 sWikiBerryDesc[] = _(
    "让宝可梦携带后，危机时可\n"
    "以回复HP。如果讨厌这味道就会混乱。");

static const u8 sMagoBerryDesc[] = _(
    "让宝可梦携带后，危机时可\n"
    "以回复HP。如果讨厌这味道就会混乱。");

static const u8 sAguavBerryDesc[] = _(
    "让宝可梦携带后，危机时可\n"
    "以回复HP。如果讨厌这味道就会混乱。");

static const u8 sIapapaBerryDesc[] = _(
    "让宝可梦携带后，危机时可\n"
    "以回复HP。如果讨厌这味道就会混乱。");

static const u8 sRazzBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨强\n"
    "壮。黄色的果实尝起来是酸的。");

static const u8 sBlukBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨美\n"
    "丽。蓝色的果实尝起来是涩的。");

static const u8 sNanabBerryDesc[] = _(
    "捕捉宝可梦时，把这树果交\n"
    "给宝可梦就能稍微平复一下\n"
    "对方的情绪。");

static const u8 sWepearBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨聪\n"
    "明。绿色的果实尝起来是苦的。");

static const u8 sPinapBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨强\n"
    "壮。黄色的果实尝起来是酸的。");

static const u8 sPomegBerryDesc[] = _(
    "如果把它交给宝可梦，宝可\n"
    "梦就会变得非常容易和训练\n"
    "家亲密，但HP的基础点数会降低。");

static const u8 sKelpsyBerryDesc[] = _(
    "如果把它交给宝可梦，宝可\n"
    "梦就会变得非常容易和训练\n"
    "家亲密，但攻击的基础点数会降低。");

static const u8 sQualotBerryDesc[] = _(
    "如果把它交给宝可梦，宝可\n"
    "梦就会变得非常容易和训练\n"
    "家亲密，但防御的基础点数会降低。");

static const u8 sHondewBerryDesc[] = _(
    "如果把它交给宝可梦，宝可\n"
    "梦就会变得非常容易和训练\n"
    "家亲密，但特攻的基础点数会降低。");

static const u8 sGrepaBerryDesc[] = _(
    "如果把它交给宝可梦，宝可\n"
    "梦就会变得非常容易和训练\n"
    "家亲密，但特防的基础点数会降低。");

static const u8 sTamatoBerryDesc[] = _(
    "如果把它交给宝可梦，宝可\n"
    "梦就会变得非常容易和训练\n"
    "家亲密，但速度的基础点数会降低。");

static const u8 sCornnBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨美\n"
    "丽。在其他地区很少见的树果。");

static const u8 sMagostBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨可\n"
    "爱。在其他地区很少见的树果。");

static const u8 sRabutaBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨聪\n"
    "明。在其他地区很少见的树果。");

static const u8 sNomelBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨强\n"
    "壮。在其他地区很少见的树果。");

static const u8 sSpelonBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨可\n"
    "爱。在其他地区很少见的树果。");

static const u8 sPamtreBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨美\n"
    "丽。在其他地区很少见的树果。");

static const u8 sWatmelBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨聪\n"
    "明。在其他地区很少见的树果。");

static const u8 sDurinBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨聪\n"
    "明。在其他地区很少见的树果。");

static const u8 sBelueBerryDesc[] = _(
    "用于制作宝可方块，制作出\n"
    "来的宝可方块可用来打磨美\n"
    "丽。在其他地区很少见的树果。");

static const u8 sLiechiBerryDesc[] = _(
    "让宝可梦携带后，危机时，\n"
    "自己的攻击就会提高。");

static const u8 sGanlonBerryDesc[] = _(
    "让宝可梦携带后，危机时，\n"
    "自己的防御就会提高。");

static const u8 sSalacBerryDesc[] = _(
    "让宝可梦携带后，危机时，\n"
    "自己的速度就会提高。");

static const u8 sPetayaBerryDesc[] = _(
    "让宝可梦携带后，危机时，\n"
    "自己的特攻就会提高。");

static const u8 sApicotBerryDesc[] = _(
    "让宝可梦携带后，危机时，\n"
    "自己的特防就会提高。");

static const u8 sLansatBerryDesc[] = _(
    "让宝可梦携带后，危机时，\n"
    "攻击会变得容易击中要害。");

static const u8 sStarfBerryDesc[] = _(
    "让宝可梦携带后，危机时，\n"
    "某一项能力就会大幅提高。");

static const u8 sMicleBerryDesc[] = _(
    "让宝可梦携带后，危机时，\n"
    "招式的命中率仅会提高1次。");

static const u8 sEnigmaBerryDesc[] = _(
    "Pokéblock ingredient.\n"
    "Plant in loamy soil\n"
    "to grow a mystery.");

static const u8 sOccaBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的火属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sPasshoBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的水属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sWacanBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的电属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sRindoBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的草属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sYacheBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的冰属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sChopleBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的格斗属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sKebiaBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的毒属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sShucaBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的地面属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sCobaBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的飞行属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sPayapaBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的超能力属性招式\n"
    "攻击时，能令其威力减弱。");

static const u8 sTangaBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的虫属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sChartiBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的岩石属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sKasibBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的幽灵属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sHabanBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的龙属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sColburBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的恶属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sBabiriBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "效果绝佳的钢属性招式攻击\n"
    "时，能令其威力减弱。");

static const u8 sChilanBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "一般属性招式攻击时，能\n"
    "令其威力减弱。");

static const u8 sRoseliBerryDesc[] = _(
    "如果宝可梦携带了它，可以\n"
    "在对战中降低妖精属性招式\n"
    "效果绝佳的效果。");

static const u8 sCustapBerryDesc[] = _(
    "让宝可梦携带后，危机时，\n"
    "行动仅会变快1次。");

static const u8 sJabocaBerryDesc[] = _(
    "让宝可梦携带后，在受到\n"
    "物理招式攻击时，能给予对\n"
    "手伤害。");

static const u8 sRowapBerryDesc[] = _(
    "让宝可梦携带后，在受到特\n"
    "殊招式攻击时，能给予对手\n"
    "伤害。");

static const u8 sKeeBerryDesc[] = _(
    "如果宝可梦携带了它，可以\n"
    "在对战中受到物理招式攻击\n"
    "时，防御提升1级。");

static const u8 sMarangaBerryDesc[] = _(
    "如果宝可梦携带了它，可以\n"
    "在对战中受到特殊招式攻击\n"
    "时，特防提升1级。");

// Hold items
static const u8 sBrightPowderDesc[] = _(
    "闪闪发光的粉末。携带后，\n"
    "光芒会迷惑对手，从而使其\n"
    "招式变得不容易命中。");

static const u8 sWhiteHerbDesc[] = _(
    "当携带它的宝可梦能力降低\n"
    "时，仅能回到之前的状态1次。");

static const u8 sMachoBraceDesc[] = _(
    "又硬又重的锻炼器。虽然携\n"
    "带后速度会降低，但会比平\n"
    "时更容易茁壮成长。");

static const u8 sExpShareDesc[] = _(
    "打开开关后，能让同行的\n"
    "所有宝可梦获得经验值的装置。");

static const u8 sQuickClawDesc[] = _(
    "又轻又尖锐的爪子。携带\n"
    "后，有时能比对手先一步行动。");

static const u8 sSootheBellDesc[] = _(
    "音色悦耳的铃铛。携带它的\n"
    "宝可梦会受到安抚，变得容\n"
    "易和训练家亲密。");

static const u8 sMentalHerbDesc[] = _(
    "当携带它的宝可梦无法自由\n"
    "使出招式时，仅会回复1次。");

static const u8 sChoiceBandDesc[] = _(
    "有点讲究的头带。虽然携带\n"
    "后攻击会提高，但只能使出\n"
    "相同的招式。");

static const u8 sKingsRockDesc[] = _(
    "携带后进行攻击，在造成伤\n"
    "害时，有时会让对手畏缩。");

static const u8 sSilverPowderDesc[] = _(
    "散发着银色光辉的粉末。\n"
    "携带后，虫属性的招式威力\n"
    "就会提高。");

static const u8 sAmuletCoinDesc[] = _(
    "只要携带它的宝可梦在战斗\n"
    "时出场一次，就能获得2倍\n"
    "金钱。");

static const u8 sCleanseTagDesc[] = _(
    "让排在最前面的宝可梦携带\n"
    "后，野生宝可梦就会不容易\n"
    "出现。");

static const u8 sSoulDewDesc[] = _(
    "让拉帝欧斯或拉帝亚斯携带\n"
    "后，超能力和龙属性的招式\n"
    "威力就会提高的神奇珠子。");

static const u8 sDeepSeaToothDesc[] = _(
    "让珍珠贝携带后，特攻就会提高的牙齿。散发着闪亮的银光。");

static const u8 sDeepSeaScaleDesc[] = _(
    "让珍珠贝携带后，特防就会提高的鳞片。散发着淡淡的粉红色光芒。");

static const u8 sSmokeBallDesc[] = _(
    "携带它的宝可梦在和野生宝\n"
    "可梦的战斗中绝对可以逃走。");

static const u8 sEverstoneDesc[] = _(
    "宝可梦在此期间不\n"
    "会进化的神奇石头。");

static const u8 sFocusBandDesc[] = _(
    "携带后，即便受到可能会导\n"
    "致濒死的招式，有时也能仅\n"
    "以1HP撑过去。");

static const u8 sLuckyEggDesc[] = _(
    "满载着幸福的蛋。携带它的\n"
    "宝可梦获得的经验值会少量\n"
    "增加。");

static const u8 sScopeLensDesc[] = _(
    "能看见弱点的镜片。携带它\n"
    "的宝可梦的招式会变得容易\n"
    "击中要害。");

static const u8 sMetalCoatDesc[] = _(
    "特殊的金属膜。携带后，钢\n"
    "属性的招式威力就会提高。");

static const u8 sLeftoversDesc[] = _(
    "携带后，宝可梦的HP会在战\n"
    "斗期间缓缓回复。");

static const u8 sDragonScaleDesc[] = _(
    "又硬又坚固的鳞片。龙属性\n"
    "宝可梦有时会携带它。");

static const u8 sOvalStoneDesc[] = _(
    "能让某些特定宝可梦进化的神奇石头。像珠子一般圆润。");

static const u8 sProtectorDesc[] = _(
    "某种护具。非常坚硬而且沉重。\n"
    "某种宝可梦很喜欢它。");

static const u8 sElectirizerDesc[] = _(
    "积蓄着庞大电气力量的箱子。\n"
    "某种宝可梦很喜欢它。");

static const u8 sMagmarizerDesc[] = _(
    "积蓄着庞大熔岩能量的箱子。\n"
    "某种宝可梦很喜欢它。");

static const u8 sDubiousDiscDesc[] = _(
    "内部储存了奇怪信息的透明机器。\n"
    "制造者不明。");

static const u8 sReaperClothDesc[] = _(
    "蕴含着惊人强大灵力的布。\n"
    "某种宝可梦很喜欢它。");

static const u8 sRazorClawDesc[] = _(
    "尖锐的爪子。携带后，招式\n"
    "会变得容易击中要害。");

static const u8 sRazorFangDesc[] = _(
    "携带后，在给予伤害时，\n"
    "有时会让对手畏缩。");

static const u8 sPrismScaleDesc[] = _(
    "能让某些特定宝可梦进化的\n"
    "神奇鳞片。散发着虹色光辉。");

static const u8 sWhippedDreamDesc[] = _(
    "软软起着泡的，稍微有\n"
    "点甜的奶油。某种宝可梦很\n"
    "喜欢它。");

static const u8 sSachetDesc[] = _(
    "装着散发微浓香气的香料的\n"
    "袋子。某种宝可梦很喜欢它。");

static const u8 sLightBallDesc[] = _(
    "让皮卡丘携带后，攻击和特\n"
    "攻的威力就会提高的神奇之球。");

static const u8 sSoftSandDesc[] = _(
    "手感细腻的沙子。携带后，\n"
    "地面属性的招式威力就会提高。");

static const u8 sHardStoneDesc[] = _(
    "绝对不会裂开的石头。携带\n"
    "后，岩石属性的招式威力就\n"
    "会提高。");

static const u8 sMiracleSeedDesc[] = _(
    "孕育生命的种子。携带后，\n"
    "草属性的招式威力就会提高。");

static const u8 sBlackGlassesDesc[] = _(
    "看上去很奇怪的眼镜。携带\n"
    "后，恶属性的招式威力就会\n"
    "提高。");

static const u8 sBlackBeltDesc[] = _(
    "能振作精神的带子。携带后，\n"
    "格斗属性的招式威力就会\n"
    "提高。");

static const u8 sMagnetDesc[] = _(
    "强力的磁铁。携带后，电属\n"
    "性的招式威力就会提高。");

static const u8 sMysticWaterDesc[] = _(
    "水滴形状的宝石。携带后，\n"
    "水属性的招式威力就会提高。");

static const u8 sSharpBeakDesc[] = _(
    "又长又尖的鸟嘴。携带后，\n"
    "飞行属性的招式威力就会提高。");

static const u8 sPoisonBarbDesc[] = _(
    "有毒的小针。携带后，毒属\n"
    "性的招式威力就会提高。");

static const u8 sNeverMeltIceDesc[] = _(
    "能隔绝热量的冰。携带后，\n"
    "冰属性的招式威力就会提高。");

static const u8 sSpellTagDesc[] = _(
    "古怪可怕的咒符。携带后，\n"
    "幽灵属性的招式威力就会提高。");

static const u8 sTwistedSpoonDesc[] = _(
    "注入了念力的汤匙。携带后，\n"
    "超能力属性的招式威力就会\n"
    "提高。");

static const u8 sCharcoalDesc[] = _(
    "焚烧用的燃料。携带后，火\n"
    "属性的招式威力就会提高。");

static const u8 sDragonFangDesc[] = _(
    "坚硬锐利的牙齿。携带后，\n"
    "龙属性的招式威力就会提高。");

static const u8 sSilkScarfDesc[] = _(
    "一个携带后可以提高普通属性\n"
    "攻击技能的道具。");

static const u8 sUpGradeDesc[] = _(
    "内部储存了各种信息的透明\n"
    "机器。西尔佛公司制造。");

static const u8 sShellBellDesc[] = _(
    "当携带它的宝可梦攻击对手\n"
    "并造成伤害时，能回复少量HP。");

static const u8 sPowerBracerDesc[] = _(
    "虽然携带后速度会降低，\n"
    "但宝可梦的攻击会比平时\n"
    "成长得更高。");

static const u8 sPowerBeltDesc[] = _(
    "虽然携带后速度会降低，\n"
    "但宝可梦的防御会比平时\n"
    "成长得更高。");

static const u8 sPowerLensDesc[] = _(
    "虽然携带后速度会降低，\n"
    "但宝可梦的特攻会比平时\n"
    "成长得更高。");

static const u8 sPowerBandDesc[] = _(
    "虽然携带后速度会降低，\n"
    "但宝可梦的特防会比平时\n"
    "成长得更高。");

static const u8 sPowerAnkletDesc[] = _(
    "虽然携带后速度会降低，\n"
    "但宝可梦的速度会比平时\n"
    "成长得更高。");

static const u8 sPowerWeightDesc[] = _(
    "虽然携带后速度会降低，\n"
    "但宝可梦的HP会比平时\n"
    "成长得更高。");

static const u8 sSeaIncenseDesc[] = _(
    "有着神奇香气的薰香。携带后，\n"
    "水属性的招式威力就会提高。");

static const u8 sLaxIncenseDesc[] = _(
    "携带后，薰香的神奇香气会迷惑\n"
    "对手，其招式会变得不容易命中。");

static const u8 sOddIncenseDesc[] = _(
    "有着神奇香气的薰香。携带后，\n"
    "超能力属性的招式威力就会提高。");

static const u8 sRockIncenseDesc[] = _(
    "有着神奇香气的薰香。携带后，\n"
    "岩石属性的招式威力就会提高。");

static const u8 sFullIncenseDesc[] = _(
    "有着神奇香气的薰香。携带后，\n"
    "宝可梦的行动会比平时更加迟缓。");

static const u8 sWaveIncenseDesc[] = _(
    "有着神奇香气的薰香。携带后，\n"
    "水属性的招式威力就会提高。");

static const u8 sRoseIncenseDesc[] = _(
    "有着神奇香气的薰香。携带后，\n"
    "草属性的招式威力就会提高。");

static const u8 sLuckIncenseDesc[] = _(
    "只要携带它的宝可梦在战斗时\n"
    "出场一次，就能获得2倍金钱。");

static const u8 sPureIncenseDesc[] = _(
    "让排在最前面的宝可梦携带后，\n"
    "野生宝可梦就会不容易出现。");

static const u8 sLuckyPunchDesc[] = _(
    "能带来幸运的拳套。让吉利蛋\n"
    "携带后，招式会变得容易击中要害。");

static const u8 sMetalPowderDesc[] = _(
    "让百变怪携带后，防御就会提高\n"
    "的神奇粉末。非常细腻坚硬。");

static const u8 sThickClubDesc[] = _(
    "某种坚硬的骨头。让卡拉卡拉\n"
    "或嘎啦嘎啦携带后，攻击就会提高。");

static const u8 sStickDesc[] = _(
    "非常长且坚硬的茎。让大葱鸭\n"
    "携带后，招式会变得容易击中要害。");

static const u8 sRedScarfDesc[] = _(
    "携带它去参加华丽大赛的\n"
    "宝可梦会比平时看上去更加帅气。");

static const u8 sBlueScarfDesc[] = _(
    "携带它去参加华丽大赛的\n"
    "宝可梦会比平时看上去更加美丽。");

static const u8 sPinkScarfDesc[] = _(
    "携带它去参加华丽大赛的\n"
    "宝可梦会比平时看上去更加可爱。");

static const u8 sGreenScarfDesc[] = _(
    "携带它去参加华丽大赛的\n"
    "宝可梦会比平时看上去更加聪明。");

static const u8 sYellowScarfDesc[] = _(
    "携带它去参加华丽大赛的\n"
    "宝可梦会比平时看上去更加强壮。");

// Key items
static const u8 sMachBikeDesc[] = _(
    "能以2倍以上的速度移动的折叠式\n"
    "自行车。");

static const u8 sCoinCaseDesc[] = _(
    "可以存放代币的盒子。最多能放入\n"
    "9999枚在游戏城获得的代币。");

static const u8 sItemfinderDesc[] = _(
    "会对看不见的道具起反应，\n"
    "并发出声音告诉你。");

static const u8 sOldRodDesc[] = _(
    "又破又旧的钓竿。在有水的地方\n"
    "使用的话，可以钓到宝可梦。");

static const u8 sGoodRodDesc[] = _(
    "不错的新钓竿。在有水的地方\n"
    "使用的话，可以钓到宝可梦。");

static const u8 sSuperRodDesc[] = _(
    "最新的厉害钓竿。在有水的地方\n"
    "使用的话，可以钓到宝可梦。");

static const u8 sSSTicketDesc[] = _(
    "乘坐高速船时所需的船票。\n"
    "上面绘有船的图案。");

static const u8 sContestPassDesc[] = _(
    "拿着它就可以参加宝可梦华丽大赛。\n"
    "上面印有纪念奖章。");

static const u8 sWailmerPailDesc[] = _(
    "浇水的道具。能让埋在土壤里的\n"
    "树果快快长大。");

static const u8 sDevonGoodsDesc[] = _(
    "此物品里面放着的是得文\n"
    "制造的某种零件。");

static const u8 sSootSackDesc[] = _(
    "将堆积起来的火山灰\n"
    "收集起来的袋子。");

static const u8 sBasementKeyDesc[] = _(
    "用来打开地道大门的钥匙。");

static const u8 sAcroBikeDesc[] = _(
    "能做出跳跃或抬前轮动作的\n"
    "折叠式自行车。");

static const u8 sPokeblockCaseDesc[] = _(
    "可以用来放置用树果混合器\n"
    "制造的宝可方块的盒子。");

static const u8 sLetterDesc[] = _(
    "从阿克罗玛博士那里得到的信，\n"
    "需要交给4号道路的阿戴克。");

static const u8 sEonTicketDesc[] = _(
    "前往南方孤岛时需要的船票。\n"
    "上面印着岛屿的图片。");

static const u8 sRedOrbDesc[] = _(
    "散发着红色光辉的宝珠。\n"
    "据说蕴含着超古代的力量。");

static const u8 sBlueOrbDesc[] = _(
    "散发着蓝色光辉的宝珠。\n"
    "据说蕴含着超古代的力量。");

static const u8 sScannerDesc[] = _(
    "在弃船中找到的道具。");

static const u8 sGoGogglesDesc[] = _(
    "能在沙漠的沙暴中\n"
    "保护眼睛的出色护目镜。");

static const u8 sMeteoriteDesc[] = _(
    "原本是落入流星瀑布里的陨石。\n"
    "是在烟囱山获得的。");

static const u8 sRoom1KeyDesc[] = _(
    "进入弃船的房间时所需的\n"
    "钥匙。");

static const u8 sRoom2KeyDesc[] = _(
    "进入弃船的房间时所需的\n"
    "钥匙。");

static const u8 sRoom4KeyDesc[] = _(
    "进入弃船的房间时所需的\n"
    "钥匙。");

static const u8 sRoom6KeyDesc[] = _(
    "进入弃船的房间时所需的\n"
    "钥匙。");

static const u8 sStorageKeyDesc[] = _(
    "进入弃船的仓库时所需的钥匙。");

static const u8 sRootFossilDesc[] = _(
    "很久以前栖息在海里的古代\n"
    "宝可梦的化石。好像是根的一部分。");

static const u8 sClawFossilDesc[] = _(
    "很久以前栖息在海里的\n"
    "古代宝可梦的化石。\n"
    "好像是爪子的一部分。");

static const u8 sDevonScopeDesc[] = _(
    "会对看不见的宝可梦起反应，\n"
    "并发出声音的得文特制产品。");

// TMs/HMs
static const u8 sTM01Desc[] = _(
    "集中精神出拳。在招式使出前若受到攻击则会失败。");

static const u8 sTM02Desc[] = _(
    "用尖锐的巨爪劈开对手进行攻击。");

static const u8 sTM03Desc[] = _(
    "用水的震动攻击对手。有时会使对手混乱。");

static const u8 sTM04Desc[] = _(
    "静心凝神，从而提高自己的特攻和特防。");

static const u8 sTM05Desc[] = _(
    "放走对手，强制拉后备宝可梦上场。如果对手为野生宝可梦，战斗将直接结束。");

static const u8 sTM06Desc[] = _(
    "让对手陷入剧毒状态。随着回合的推进，中毒伤害会增加。");

static const u8 sTM07Desc[] = _(
    "在5回合内一直降冰雹，除冰属性的宝可梦以外，给予全体宝可梦伤害。");

static const u8 sTM08Desc[] = _(
    "使出全身力气绷紧肌肉，从而提高自己的攻击和防御。");

static const u8 sTM09Desc[] = _(
    "向对手猛烈地发射种子进行攻击。连续攻击2～5次。");

static const u8 sTM10Desc[] = _(
    "招式的属性会随着使用此招式的宝可梦而改变。");

static const u8 sTM11Desc[] = _(
    "在5回合内阳光变得强烈，从而提高火属性的招式威力。水属性的招式威力则降低。");

static const u8 sTM12Desc[] = _(
    "使对手愤怒。在3回合内让对手只能使出给予伤害的招式。");

static const u8 sTM13Desc[] = _(
    "向对手发射冰冻光束进行攻击。有时会让对手陷入冰冻状态。");

static const u8 sTM14Desc[] = _(
    "将猛烈的暴风雪刮向对手进行攻击。有时会让对手陷入冰冻状态。");

static const u8 sTM15Desc[] = _(
    "向对手发射强烈的光线进行攻击。下一回合自己将无法动弹。");

static const u8 sTM16Desc[] = _(
    "在5回合内使用神奇的墙，减弱从对手那受到的特殊攻击的伤害。");

static const u8 sTM17Desc[] = _(
    "完全抵挡对手的攻击。连续使出则容易失败。");

static const u8 sTM18Desc[] = _(
    "在5回合内一直降雨，从而提高水属性的招式威力。火属性的招式威力则降低。");

static const u8 sTM19Desc[] = _(
    "吸取对手的养分进行攻击。可以回复给予对手伤害的一半HP。");

static const u8 sTM20Desc[] = _(
    "在5回合内被神奇的力量守护，从而不会陷入异常状态。");

static const u8 sTM21Desc[] = _(
    "为了发泄不满而全力攻击对手。亲密度越低，威力越大。");

static const u8 sTM22Desc[] = _(
    "第1回合收集满满的日光，第2回合发射光束进行攻击。");

static const u8 sTM23Desc[] = _(
    "使用坚硬的尾巴摔打对手进行攻击。有时会降低对手的防御。");

static const u8 sTM24Desc[] = _(
    "向对手发出强力电击进行攻击。有时会让对手陷入麻痹状态。");

static const u8 sTM25Desc[] = _(
    "向对手劈下暴雷进行攻击。有时会让对手陷入麻痹状态。");

static const u8 sTM26Desc[] = _(
    "利用地震的冲击，攻击自己周围所有的宝可梦。");

static const u8 sTM27Desc[] = _(
    "为了训练家而全力攻击对手。亲密度越高，威力越大。");

static const u8 sTM28Desc[] = _(
    "第1回合钻入，第2回合攻击对手。");

static const u8 sTM29Desc[] = _(
    "向对手发送强大的念力进行攻击。有时会降低对手的特防。");

static const u8 sTM30Desc[] = _(
    "投掷一团黑影进行攻击。有时会降低对手的特防。");

static const u8 sTM31Desc[] = _(
    "将手刀猛烈地挥下攻击对手。还可以破坏光墙和反射壁等。");

static const u8 sTM32Desc[] = _(
    "通过快速移动来制造分身，扰乱对手，从而提高闪避率。");

static const u8 sTM33Desc[] = _(
    "在5回合内使用神奇的墙，减弱从对手那受到的物理攻击的伤害。");

static const u8 sTM34Desc[] = _(
    "向对手快速发出电击。攻击必定会命中。");

static const u8 sTM35Desc[] = _(
    "向对手发射烈焰进行攻击。有时会让对手陷入灼伤状态。");

static const u8 sTM36Desc[] = _(
    "用污泥投掷对手进行攻击。有时会让对手陷入中毒状态。");

static const u8 sTM37Desc[] = _(
    "在5回合内扬起沙暴，除岩石、地面和钢属性以外的宝可梦，都会受到伤害。岩石属性的特防还会提高。");

static const u8 sTM38Desc[] = _(
    "用大字形状的火焰烧尽对手。有时会让对手陷入灼伤状态。");

static const u8 sTM39Desc[] = _(
    "投掷岩石进行攻击。封住对手的行动，从而降低速度。");

static const u8 sTM40Desc[] = _(
    "以敏捷的动作戏弄对手后进行切斩。攻击必定会命中。");

static const u8 sTM41Desc[] = _(
    "向对手无理取闹，令其不能连续2次使出相同招式。");

static const u8 sTM42Desc[] = _(
    "当自己处于中毒、麻痹、灼伤状态时，向对手使出此招式的话，威力会变成2倍。");

static const u8 sTM43Desc[] = _(
    "根据使用场所不同，该招式的追加效果也会有所变化。");

static const u8 sTM44Desc[] = _(
    "连续睡上2回合。回复自己的全部HP以及治愈所有异常状态。");

static const u8 sTM45Desc[] = _(
    "♂诱惑♀或♀诱惑♂，让对手着迷。对手将很难使出招式。");

static const u8 sTM46Desc[] = _(
    "攻击的同时盗取道具。当自己携带道具时，不会去盗取。");

static const u8 sTM47Desc[] = _(
    "用坚硬的翅膀敲打对手进行攻击。有时会提高自己的防御。");

static const u8 sTM48Desc[] = _(
    "利用超能力互换自己和对手的特性。");

static const u8 sTM49Desc[] = _(
    "将对手打算使用的回复招式或能力变化招式夺为己用。");

static const u8 sTM50Desc[] = _(
    "使出全部力量攻击对手。使用之后会因为反作用力，自己的特攻大幅降低。");

static const u8 sHM01Desc[] = _(
    "用镰刀或爪子等切斩对手进行攻击。");

static const u8 sHM02Desc[] = _(
    "第1回合飞上天空，第2回合攻击对手。");

static const u8 sHM03Desc[] = _(
    "利用大浪攻击自己周围所有的宝可梦。");

static const u8 sHM04Desc[] = _(
    "使出浑身力气殴打对手进行攻击。");

static const u8 sHM05Desc[] = _(
    "使出耀眼光芒，从而降低对手的命中率。");

static const u8 sHM06Desc[] = _(
    "用拳头进行攻击。有时会降低对手的防御。");

static const u8 sHM07Desc[] = _(
    "以惊人的气势扑向对手。有时会使对手畏缩。");

static const u8 sHM08Desc[] = _(
    "第1回合潜入，第2回合浮上来进行攻击。");

// FireRed/LeafGreen key items
static const u8 sOaksParcelDesc[] = _(
    "这是常青市的友好商店托付给你的包裹。需要将它交给大木博士。");

static const u8 sPokeFluteDesc[] = _(
    "能吹出让睡着的宝可梦都会情不自禁醒来的美妙音色的笛子。");

static const u8 sSecretKeyDesc[] = _(
    "能打开红莲岛上那座宝可梦道馆的钥匙。周身都以红色装饰。");

static const u8 sBikeVoucherDesc[] = _(
    "给华蓝市的奇迹自行车店就能交换得到自行车。");

static const u8 sGoldTeethDesc[] = _(
    "狩猎地带的园长遗失的金假牙。装上它后，笑起来十分耀眼。");

static const u8 sOldAmberDesc[] = _(
    "封存着古代宝可梦遗传基因的琥珀，透着点红色。");

static const u8 sCardKeyDesc[] = _(
    "用来打开位于金黄市的西尔佛公司总部大厦门锁的卡片式钥匙。");

static const u8 sLiftKeyDesc[] = _(
    "一把用来打开火箭队藏身处的电梯钥匙。");

static const u8 sArmorFossilDesc[] = _(
    "带有火箭队标志的钥匙。能启动位于火箭队基地的电梯。");

static const u8 sSkullFossilDesc[] = _(
    "很久以前生活在地上的古代宝可梦的化石。好像是头部的一部分。");

static const u8 sHelixFossilDesc[] = _(
    "很久以前栖息在海里的古代宝可梦的化石。好像是贝壳的一部分。");

static const u8 sDomeFossilDesc[] = _(
    "很久以前栖息在海里的古代宝可梦的化石。好像是甲壳的一部分。");

static const u8 sCoverFossilDesc[] = _(
    "很久以前栖息在海里的古代宝可梦的化石。好像是后背的一部分。");

static const u8 sPlumeFossilDesc[] = _(
    "据说是鸟宝可梦的祖先，古代宝可梦的化石。好像是翅膀的一部分。");

static const u8 sJawFossilDesc[] = _(
    "很久以前生活在地上的古代宝可梦的化石。好像是很大的颚的一部分。");

static const u8 sSailFossilDesc[] = _(
    "很久以前生活在地上的古代宝可梦的化石。好像是头鳍的一部分。");

static const u8 sSilphScopeDesc[] = _(
    "西尔佛公司制造的透视镜。可以看见人眼无法看见的东西。");

static const u8 sBicycleDesc[] = _(
    "能比跑步鞋跑得还快的折叠式自行车。");

static const u8 sTownMapDesc[] = _(
    "可以随时轻松查看的便利地图。也能清楚自己的位置。");

static const u8 sVSSeekerDesc[] = _(
    "会告诉你想对战的训练家在哪里的机器。走路就能给电池充电。");

static const u8 sFameCheckerDesc[] = _(
    "可以重复查看打听到的有名人物的东西。");

static const u8 sTMCaseDesc[] = _(
    "用来存放招式学习器的盒子，放在包包的重要物品口袋里。");

static const u8 sBerryPouchDesc[] = _(
    "将树果收集起来的袋子，放在包包的重要物品口袋里。");

static const u8 sTeachyTVDesc[] = _(
    "可以收看对新手训练家有帮助的节目的电视");

static const u8 sTriPassDesc[] = _(
    "能够在第1岛，第2岛和第3岛之间用渡船移动的通行证。上面印着三座岛。");

static const u8 sRainbowPassDesc[] = _(
    "能够在枯叶市和七之岛之间用渡船移动的通行证。上面印着彩虹的图片。");

static const u8 sTeaDesc[] = _(
    "老奶奶泡的散发清香的茶。十分解渴。");

static const u8 sMysticTicketDesc[] = _(
    "前往肚脐岩时必要的船票。神秘地发着光。");

static const u8 sAuroraTicketDesc[] = _(
    "前往诞生之岛时必要的船票。美丽地散发着光芒。");

static const u8 sPowderJarDesc[] = _(
    "能收纳树果碾碎器制作出的树果粉末的保存用瓶子");

static const u8 sRubyDesc[] = _(
    "散发着红色光辉的非常漂亮的宝石。热情的象征。");

static const u8 sSapphireDesc[] = _(
    "散发着蓝色光辉的非常漂亮的宝石。真诚的象征。");

// Emerald-specific key items
static const u8 sMagmaEmblemDesc[] = _(
    "与熔岩队的标志形状相同的徽章模样的东西。");

static const u8 sOldSeaMapDesc[] = _(
    "记录着前往某座岛屿的路线的一张古老的航海图。");

// New items
static const u8 sWideLensDesc[] = _(
    "能放大观看物体的镜片。携带后，招式的命中率就会少量提高。");

static const u8 sMuscleBandDesc[] = _(
    "力如泉涌的头带。携带后，物理招式的威力就会少量提高。");

static const u8 sWiseGlassesDesc[] = _(
    "装着很厚镜片的眼镜。携带后，特殊招式的威力就会少量提高。");

static const u8 sExpertBeltDesc[] = _(
    "用惯了的黑色带子。携带后，效果绝佳时的招式威力就会少量提高。");

static const u8 sLightClayDesc[] = _(
    "当携带它的宝可梦使出光墙或反射壁时，效果会比平时持续得更长。");

static const u8 sLifeOrbDesc[] = _(
    "携带后，虽然每次攻击时HP少量减少，但招式的威力会提高。");

static const u8 sPowerHerbDesc[] = _(
    "携带它的宝可梦仅有1次机会可以在第1回合使出需要蓄力的招式。");

static const u8 sToxicOrbDesc[] = _(
    "触碰后会放出毒的神奇宝珠。携带后，在战斗时会变成剧毒状态。");

static const u8 sFlameOrbDesc[] = _(
    "触碰后会放出热量的神奇宝珠。携带后，在战斗时会变成灼伤状态。");

static const u8 sQuickPowderDesc[] = _(
    "让百变怪携带后，速度就会提高的神奇粉末。非常细腻坚硬。");

static const u8 sFocusSashDesc[] = _(
    "携带后，在HP全满时，即便受到可能会导致濒死的招式，也能仅以1HP撑过去1次。");

static const u8 sZoomLensDesc[] = _(
    "当携带它的宝可梦比对手行动迟缓时，招式会变得容易命中。");

static const u8 sMetronomeDesc[] = _(
    "携带后，连续使出相同招式时，威力就会提高。不再使出相同招式时，威力就会复原。");

static const u8 sIronBallDesc[] = _(
    "携带后，速度会降低。飞行属性以及飘浮宝可梦会被地面招式击中。");

static const u8 sLaggingTailDesc[] = _(
    "非常沉重的某种尾巴。携带后，行动会比平时更加迟缓。");

static const u8 sDestinyKnotDesc[] = _(
    "长长的鲜红色细线。携带后，在自己着迷时能让对手也着迷。");

static const u8 sBlackSludgeDesc[] = _(
    "携带后，毒属性的宝可梦会缓缓回复HP。其他属性的话，HP则会减少。");

static const u8 sIcyRockDesc[] = _(
    "携带它的宝可梦使出冰雹的话，冰雹的时间就会比平时更长。");

static const u8 sSmoothRockDesc[] = _(
    "携带它的宝可梦使出沙暴的话，沙暴的时间就会比平时更长。");

static const u8 sHeatRockDesc[] = _(
    "携带它的宝可梦使出大晴天的话，晴天的时间就会比平时更长。");

static const u8 sDampRockDesc[] = _(
    "携带它的宝可梦使出求雨的话，下雨的时间就会比平时更长。");

static const u8 sGripClawDesc[] = _(
    "携带后，绑紧以及紧束等会持续造成伤害的招式的回合数会增加。");

static const u8 sChoiceScarfDesc[] = _(
    "有点讲究的围巾。虽然携带后速度会提高，但只能使出相同的招式。");

static const u8 sStickyBarbDesc[] = _(
    "携带后，每回合都会受到伤害。有时也会附着到碰到自己的对手身上。");

static const u8 sShedShellDesc[] = _(
    "结实坚硬的空壳。携带它的宝可梦必定可以和后备的宝可梦进行替换。");

static const u8 sBigRootDesc[] = _(
    "携带后，吸取HP的招式可以比平时更多地回复自己的HP。");

static const u8 sChoiceSpecsDesc[] = _(
    "有点讲究的眼镜。虽然携带后特攻会提高，但只能使出相同的招式。");

static const u8 sOddKeystoneDesc[] = _(
    "没有它，石之塔就会崩塌的重要石头。有时能从石头里听到声音。");

static const u8 sAdamantOrbDesc[] = _(
    "让帝牙卢卡携带的话，龙和钢属性的招式威力就会提高。散发着光辉的宝珠。");

static const u8 sLustrousOrbDesc[] = _(
    "让帕路奇亚携带的话，龙和水属性的招式威力就会提高。散发着美丽光辉的宝珠。");

static const u8 sGriseousOrbDesc[] = _(
    "让骑拉帝纳携带的话，龙和幽灵属性的招式威力就会提高。散发着光辉的宝珠。");

static const u8 sGracideaDesc[] = _(
    "在生日或纪念日等日子里，为了表达感激之情，有时会将其扎成花束送出。");

static const u8 sBugMemoryDesc[] = _(
    "装有虫属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sDarkMemoryDesc[] = _(
    "装有恶属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sDragonMemoryDesc[] = _(
    "装有龙属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sElectricMemoryDesc[] = _(
    "装有电属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sFairyMemoryDesc[] = _(
    "装有妖精属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sFightingMemoryDesc[] = _(
    "装有格斗属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sFireMemoryDesc[] = _(
    "装有火属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sFlyingMemoryDesc[] = _(
    "装有飞行属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sGhostMemoryDesc[] = _(
    "装有幽灵属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sGrassMemoryDesc[] = _(
    "装有草属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sGroundMemoryDesc[] = _(
    "装有地面属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sIceMemoryDesc[] = _(
    "装有冰属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sPoisonMemoryDesc[] = _(
    "装有毒属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sPsychicMemoryDesc[] = _(
    "装有超能力属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sRockMemoryDesc[] = _(
    "装有岩石属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sSteelMemoryDesc[] = _(
    "装有钢属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sWaterMemoryDesc[] = _(
    "装有水属性数据的存储碟。特定宝可梦携带后，属性就会发生变化。");

static const u8 sFlamePlateDesc[] = _(
    "火属性的石板。携带后，火属性的招式威力就会增强。");

static const u8 sSplashPlateDesc[] = _(
    "水属性的石板。携带后，水属性的招式威力就会增强。");

static const u8 sZapPlateDesc[] = _(
    "电属性的石板。携带后，电属性的招式威力就会增强。");

static const u8 sMeadowPlateDesc[] = _(
    "草属性的石板。携带后，草属性的招式威力就会增强。");

static const u8 sIciclePlateDesc[] = _(
    "冰属性的石板。携带后，冰属性的招式威力就会增强。");

static const u8 sFistPlateDesc[] = _(
    "格斗属性的石板。携带后，格斗属性的招式威力就会增强。");

static const u8 sToxicPlateDesc[] = _(
    "毒属性的石板。携带后，毒属性的招式威力就会增强。");

static const u8 sEarthPlateDesc[] = _(
    "地面属性的石板。携带后，地面属性的招式威力就会增强。");

static const u8 sSkyPlateDesc[] = _(
    "飞行属性的石板。携带后，飞行属性的招式威力就会增强。");

static const u8 sMindPlateDesc[] = _(
    "超能力属性的石板。携带后，超能力属性的招式威力就会增强。");

static const u8 sInsectPlateDesc[] = _(
    "虫属性的石板。携带后，虫属性的招式威力就会增强。");

static const u8 sStonePlateDesc[] = _(
    "岩石属性的石板。携带后，岩石属性的招式威力就会增强。");

static const u8 sSpookyPlateDesc[] = _(
    "幽灵属性的石板。携带后，幽灵属性的招式威力就会增强。");

static const u8 sDracoPlateDesc[] = _(
    "龙属性的石板。携带后，龙属性的招式威力就会增强。");

static const u8 sDreadPlateDesc[] = _(
    "恶属性的石板。携带后，恶属性的招式威力就会增强。");

static const u8 sIronPlateDesc[] = _(
    "钢属性的石板。携带后，钢属性的招式威力就会增强。");

static const u8 sEvioliteDesc[] = _(
    "进化的神奇石块。携带后，还能进化的宝可梦的防御和特防就会提高。");

static const u8 sFloatStoneDesc[] = _(
    "非常轻的石头。携带后，宝可梦的体重会变轻。");

static const u8 sRockyHelmetDesc[] = _(
    "让宝可梦携带后，在受到打击招式攻击时，能给予对手伤害。");

static const u8 sAirBalloonDesc[] = _(
    "让宝可梦携带后，宝可梦会浮在空中。受到攻击就会破裂。");

static const u8 sRedCardDesc[] = _(
    "有着神奇力量的卡片。携带后，能让使用了招式的对手退场。");

static const u8 sRingTargetDesc[] = _(
    "原本因宝可梦的属性相克关系而无效的招式现在会变得能够击中自己。");

static const u8 sBindingBandDesc[] = _(
    "能增强绑紧招式的束带。携带后，绑紧招式的威力会变强。");

static const u8 sEjectButtonDesc[] = _(
    "携带它的宝可梦如果受到招式攻击，就能逃脱战斗，并和同行的其他宝可梦进行替换。");

static const u8 sAbsorbBulbDesc[] = _(
    "一次性使用的球根。携带它的宝可梦如果受到水属性招式的攻击，特攻就会提高。");

static const u8 sCellBatteryDesc[] = _(
    "一次性使用的充电电池。携带它的宝可梦如果受到电属性招式的攻击，攻击就会提高。");

static const u8 sLuminousMossDesc[] = _(
    "一次性使用的光苔。携带它的宝可梦如果受到水属性招式攻击，特防就会提高。");

static const u8 sSnowballDesc[] = _(
    "一次性使用的雪球。携带它的宝可梦如果受到冰属性招式攻击，攻击就会提高。");

static const u8 sWeaknessPolicyDesc[] = _(
    "被针对弱点时，攻击和特攻就会大幅提高。");

static const u8 sDouseDriveDesc[] = _(
    "这是让盖诺赛克特携带的卡带。携带后，高科技光炮这招式就会变为水属性。");

static const u8 sShockDriveDesc[] = _(
    "这是让盖诺赛克特携带的卡带。携带后，高科技光炮这招式就会变为电属性。");

static const u8 sBurnDriveDesc[] = _(
    "这是让盖诺赛克特携带的卡带。携带后，高科技光炮这招式就会变为火属性。");

static const u8 sChillDriveDesc[] = _(
    "这是让盖诺赛克特携带的卡带。携带后，高科技光炮这招式就会变为冰属性。");

static const u8 sFireGemDesc[] = _(
    "火属性的宝石。携带后，火属性的招式威力仅会增强1次。");

static const u8 sWaterGemDesc[] = _(
    "水属性的宝石。携带后，水属性的招式威力仅会增强1次。");

static const u8 sElectricGemDesc[] = _(
    "电属性的宝石。携带后，电属性的招式威力仅会增强1次。");

static const u8 sGrassGemDesc[] = _(
    "草属性的宝石。携带后，草属性的招式威力仅会增强1次。");

static const u8 sIceGemDesc[] = _(
    "冰属性的宝石。携带后，冰属性的招式威力仅会增强1次。");

static const u8 sFightingGemDesc[] = _(
    "格斗属性的宝石。携带后，格斗属性的招式威力仅会增强1次。");

static const u8 sPoisonGemDesc[] = _(
    "毒属性的宝石。携带后，毒属性的招式威力仅会增强1次。");

static const u8 sGroundGemDesc[] = _(
    "地面属性的宝石。携带后，地面属性的招式威力仅会增强1次。");

static const u8 sFlyingGemDesc[] = _(
    "飞行属性的宝石。携带后，飞行属性的招式威力仅会增强1次。");

static const u8 sPsychicGemDesc[] = _(
    "超能力属性的宝石。携带后，超能力属性的招式威力仅会增强1次。");

static const u8 sBugGemDesc[] = _(
    "虫属性的宝石。携带后，虫属性的招式威力仅会增强1次。");

static const u8 sRockGemDesc[] = _(
    "岩石属性的宝石。携带后，岩石属性的招式威力仅会增强1次。");

static const u8 sGhostGemDesc[] = _(
    "幽灵属性的宝石。携带后，幽灵属性的招式威力仅会增强1次。");

static const u8 sDragonGemDesc[] = _(
    "龙属性的宝石。携带后，龙属性的招式威力仅会增强1次。");

static const u8 sDarkGemDesc[] = _(
    "恶属性的宝石。携带后，恶属性的招式威力仅会增强1次。");

static const u8 sSteelGemDesc[] = _(
    "钢属性的宝石。携带后，钢属性的招式威力仅会增强1次。");

static const u8 sNormalGemDesc[] = _(
    "一般属性的宝石。携带后，一般属性的招式威力仅会增强1次。");

static const u8 sFairyGemDesc[] = _(
    "妖精属性的宝石。携带后，妖精属性的招式威力仅会增强1次。");

static const u8 sAssaultVestDesc[] = _(
    "会变得富有攻击性的背心。虽然携带后特防会提高，但会无法使出变化招式。");

static const u8 sPixiePlateDesc[] = _(
    "妖精属性的石板。携带后，妖精属性的招式威力就会增强。");

static const u8 sSafetyGogglesDesc[] = _(
    "不单是天气造成的伤害，就连粉末类招式的效果也能防御的护目镜。");

static const u8 sGengariteDesc[] = _(
    "让耿鬼携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sGardevoiriteDesc[] = _(
    "让沙奈朵携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sAmpharositeDesc[] = _(
    "让电龙带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sVenusauriteDesc[] = _(
    "让妙蛙花携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sCharizarditeDesc[] = _(
    "让喷火龙携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sBlastoisiniteDesc[] = _(
    "让水箭龟携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sMewtwoniteDesc[] = _(
    "让超梦携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sBlazikeniteDesc[] = _(
    "让火焰鸡携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sMedichamiteDesc[] = _(
    "让恰雷姆携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sHoundoominiteDesc[] = _(
    "让黑鲁加携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sAggroniteDesc[] = _(
    "让波士可多拉携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sBanettiteDesc[] = _(
    "让诅咒娃娃携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sTyranitariteDesc[] = _(
    "让班基拉斯携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sScizoriteDesc[] = _(
    "让巨钳螳螂携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sPinsiriteDesc[] = _(
    "让凯罗斯携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sAerodactyliteDesc[] = _(
    "让化石翼龙携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sLucarioniteDesc[] = _(
    "让路卡利欧携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sAbomasiteDesc[] = _(
    "让暴雪王携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sKangaskhaniteDesc[] = _(
    "让袋兽携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sGyaradositeDesc[] = _(
    "让暴鲤龙携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sAbsoliteDesc[] = _(
    "让阿勃梭鲁携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sAlakaziteDesc[] = _(
    "让胡地携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sHeracroniteDesc[] = _(
    "让赫拉克罗斯携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sMawiliteDesc[] = _(
    "让大嘴娃携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sManectiteDesc[] = _(
    "让雷电兽携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sGarchompiteDesc[] = _(
    "让烈咬陆鲨携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sLatiasiteDesc[] = _(
    "让拉帝亚斯携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sLatiositeDesc[] = _(
    "让拉帝欧斯携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sSwampertiteDesc[] = _(
    "让巨沼怪携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sSceptiliteDesc[] = _(
    "让蜥蜴王携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sSableniteDesc[] = _(
    "让勾魂眼携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sAltarianiteDesc[] = _(
    "让七夕青鸟携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sGalladiteDesc[] = _(
    "让艾路雷朵携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sAudiniteDesc[] = _(
    "让差不多娃娃携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sMetagrossiteDesc[] = _(
    "让巨金怪携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sSharpedoniteDesc[] = _(
    "让巨牙鲨携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sSlowbroniteDesc[] = _(
    "让呆壳兽携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sSteelixiteDesc[] = _(
    "让大钢蛇携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sPidgeotiteDesc[] = _(
    "让大比鸟携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sGlalititeDesc[] = _(
    "让冰鬼护携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sDianciteDesc[] = _(
    "让蒂安希携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sCameruptiteDesc[] = _(
    "喷火驼携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sLopunniteDesc[] = _(
    "长耳兔携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sSalamenciteDesc[] = _(
    "暴飞龙携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sBeedrilliteDesc[] = _(
    "大针蜂携带后，在战斗时就能进行超级进化的一种神奇超级石。");

static const u8 sMegaBraceletDesc[] = _(
    "蕴藏着未知力量的手镯。能让携带着超级石战斗的宝可梦进行超级进化。");

static const u8 sProtectPadsDesc[] = _(
    "不会受到触碰攻击对手时本应受到的效果。");

static const u8 sTerrainExtenderDesc[] = _(
    "当携带它的宝可梦利用招式或特性展开场地时，场地的持续时间会比平时更长。");

static const u8 sElectricSeedDesc[] = _(
    "让宝可梦携带后，在电气场地上使用，防御就会提高。");

static const u8 sGrassySeedDesc[] = _(
    "让宝可梦携带后，在青草场地上使用，防御就会提高。");

static const u8 sMistySeedDesc[] = _(
    "让宝可梦携带后，在薄雾场地上使用，特防就会提高。");

static const u8 sPsychicSeedDesc[] = _(
    "让宝可梦携带后，在精神场地上使用，特防就会提高。");

static const u8 sAdrenalineOrbDesc[] = _(
    "使用后会容易呼唤伙伴，但使用后会消失。携带后，在受到威吓时速度会提高。");

static const u8 sHoneyDesc[] = _(
    "在草丛或洞窟等地方使用后，被甜甜香气吸引的野生宝可梦就会出现。");

static const u8 sHealthFeatherDesc[] = _(
    "用于宝可梦的道具。能稍微提高1只宝可梦的HP的基础点数。");

static const u8 sMuscleFeatherDesc[] = _(
    "用于宝可梦的道具。能稍微提高1只宝可梦的攻击的基础点数。");

static const u8 sResistFeatherDesc[] = _(
    "用于宝可梦的道具。能稍微提高1只宝可梦的防御的基础点数。");

static const u8 sGeniusFeatherDesc[] = _(
    "用于宝可梦的道具。能稍微提高1只宝可梦的特攻的基础点数。");

static const u8 sCleverFeatherDesc[] = _(
    "用于宝可梦的道具。能稍微提高1只宝可梦的特防的基础点数。");

static const u8 sSwiftFeatherDesc[] = _(
    "用于宝可梦的道具。能稍微提高1只宝可梦的速度的基础点数。");

static const u8 sPrettyFeatherDesc[] = _(
    "仅仅只是漂亮，没有任何效果，极其普通的羽毛。");

static const u8 sShinyCharmDesc[] = _(
    "拥有它之后，据说会更容易遇见发光宝可梦的神奇闪光护符。");

static const u8 sOvalCharmDesc[] = _(
    "拥有它之后，在寄放屋里会更容易找到蛋的神奇浑圆护符。");

static const u8 sZRingDesc[] = _(
    "通过使用训练家的气力和体力来让宝可梦释放出Z力量的神奇手环。");

static const u8 sNormaliumZDesc[] = _(
    "Z力量的结晶。会将一般属性的招式升级成Z招式。");

static const u8 sFightiniumZDesc[] = _(
    "Z力量的结晶。会将格斗属性的招式升级成Z招式。");

static const u8 sFlyiniumZDesc[] = _(
    "Z力量的结晶。会将飞行属性的招式升级成Z招式。");

static const u8 sPoisoniumZDesc[] = _(
    "Z力量的结晶。会将毒属性的招式升级成Z招式。");

static const u8 sGroundiumZDesc[] = _(
    "Z力量的结晶。会将地面属性的招式升级成Z招式。");

static const u8 sRockiumZDesc[] = _(
    "Z力量的结晶。会将岩石属性的招式升级成Z招式。");

static const u8 sBuginiumZDesc[] = _(
    "Z力量的结晶。会将虫属性的招式升级成Z招式。");

static const u8 sGhostiumZDesc[] = _(
    "Z力量的结晶。会将幽灵属性的招式升级成Z招式。");

static const u8 sSteeliumZDesc[] = _(
    "Z力量的结晶。会将钢属性的招式升级成Z招式。");

static const u8 sFiriumZDesc[] = _(
    "Z力量的结晶。会将火属性的招式升级成Z招式。");

static const u8 sWateriumZDesc[] = _(
    "Z力量的结晶。会将水属性的招式升级成Z招式。");

static const u8 sGrassiumZDesc[] = _(
    "Z力量的结晶。会将草属性的招式升级成Z招式。");

static const u8 sElectriumZDesc[] = _(
    "Z力量的结晶。会将电属性的招式升级成Z招式。");

static const u8 sPsychiumZDesc[] = _(
    "Z力量的结晶。会将超能力属性的招式升级成Z招式。");

static const u8 sIciumZDesc[] = _(
    "Z力量的结晶。会将冰属性的招式升级成Z招式。");

static const u8 sDragoniumZDesc[] = _(
    "Z力量的结晶。会将龙属性的招式升级成Z招式。");

static const u8 sDarkiniumZDesc[] = _(
    "Z力量的结晶。会将恶属性的招式升级成Z招式。");

static const u8 sFairiumZDesc[] = _(
    "Z力量的结晶。会将妖精属性的招式升级成Z招式。");

static const u8 sAloraichiumZDesc[] = _(
    "Z力量的结晶。会将阿罗拉地区雷丘的十万伏特升级成Z招式。");

static const u8 sDecidiumZDesc[] = _(
    "Z力量的结晶。会将狙射树枭的缝影升级成Z招式。");

static const u8 sEeviumZDesc[] = _(
    "Z力量的结晶。会将伊布的珍藏升级成Z招式。");

static const u8 sInciniumZDesc[] = _(
    "Z力量的结晶。会将炽焰咆哮虎的DD金勾臂升级成Z招式。");

static const u8 sKommoniumZDesc[] = _(
    "Z力量的结晶。会将杖尾鳞甲龙的鳞片噪音升级成Z招式。");

static const u8 sLunaliumZDesc[] = _(
    "Z力量的结晶。会将露奈雅拉的暗影之光升级成Z招式。");

static const u8 sLycaniumZDesc[] = _(
    "Z力量的结晶。会将鬃岩狼人的尖石攻击升级成Z招式。");

static const u8 sMarshadiumZDesc[] = _(
    "Z力量的结晶。会将玛夏多的暗影偷盗升级成Z招式。");

static const u8 sMewniumZDesc[] = _(
    "Z力量的结晶。会将梦幻的精神强念升级成Z招式。");

static const u8 sMimikiumZDesc[] = _(
    "Z力量的结晶。会将谜拟Q的嬉闹升级成Z招式。");

static const u8 sPikaniumZDesc[] = _(
    "Z力量的结晶。会将皮卡丘的伏特攻击升级成Z招式。");

static const u8 sPikashuniumZDesc[] = _(
    "Z力量的结晶。会将戴着帽子的皮卡丘的十万伏特升级成Z招式。");

static const u8 sPrimariumZDesc[] = _(
    "Z力量的结晶。会将西狮海壬的泡影的咏叹调升级成Z招式。");

static const u8 sSnorliumZDesc[] = _(
    "Z力量的结晶。会将卡比兽的终极冲击升级成Z招式。");

static const u8 sSolganiumZDesc[] = _(
    "Z力量的结晶。会将索尔迦雷欧的流星闪冲升级成Z招式。");

static const u8 sTapuniumZDesc[] = _(
    "Z力量的结晶。会将卡璞们的自然之怒升级成Z招式。");

static const u8 sUltranecroziumZDesc[] = _(
    "Z力量的结晶。会将奈克洛兹玛的光子喷涌升级成Z招式。");
#else
// Pokeballs
static const u8 sMasterBallDesc[] = _(
    "The best Ball that\n"
    "catches a Pokémon\n"
    "without fail.");

static const u8 sUltraBallDesc[] = _(
    "A better Ball with\n"
    "a higher catch rate\n"
    "than a Great Ball.");

static const u8 sGreatBallDesc[] = _(
    "A good Ball with a\n"
    "higher catch rate\n"
    "than a Poké Ball.");

static const u8 sPokeBallDesc[] = _(
    "A tool used for\n"
    "catching wild\n"
    "Pokémon.");

static const u8 sSafariBallDesc[] = _(
    "A special Ball that\n"
    "is used only in the\n"
    "Safari Zone.");

static const u8 sNetBallDesc[] = _(
    "A Ball that works\n"
    "well on Water- and\n"
    "Bug-type Pokémon.");

static const u8 sDiveBallDesc[] = _(
    "A Ball that works\n"
    "better on Pokémon\n"
    "on the ocean floor.");

static const u8 sNestBallDesc[] = _(
    "A Ball that works\n"
    "better on weaker\n"
    "Pokémon.");

static const u8 sRepeatBallDesc[] = _(
    "A Ball that works\n"
    "better on Pokémon\n"
    "caught before.");

static const u8 sTimerBallDesc[] = _(
    "A Ball that gains\n"
    "power in battles\n"
    "taking many turns.");

static const u8 sLuxuryBallDesc[] = _(
    "A cozy Ball that\n"
    "makes Pokémon\n"
    "more friendly.");

static const u8 sPremierBallDesc[] = _(
    "A rare Ball made\n"
    "in commemoration\n"
    "of some event.");

static const u8 sLevelBallDesc[] = _(
    "A Ball that works\n"
    "well on lower\n"
    "level Pokémon.");

static const u8 sLureBallDesc[] = _(
    "A Ball that works\n"
    "well on fished\n"
    "up Pokémon.");

static const u8 sMoonBallDesc[] = _(
    "A Ball that works\n"
    "well on Moon\n"
    "Stone users.");

static const u8 sFriendBallDesc[] = _(
    "A Ball that makes\n"
    "a Pokémon friendly\n"
    "when caught.");

static const u8 sLoveBallDesc[] = _(
    "Works well on\n"
    "Pokémon of the\n"
    "opposite gender.");

static const u8 sHeavyBallDesc[] = _(
    "Works well on\n"
    "very heavy\n"
    "Pokémon.");

static const u8 sFastBallDesc[] = _(
    "Works well on\n"
    "very fast\n"
    "Pokémon.");

static const u8 sHealBallDesc[] = _(
    "A remedial Ball\n"
    "that restores\n"
    "caught Pokémon.");

static const u8 sQuickBallDesc[] = _(
    "Works well if\n"
    "used on the\n"
    "first turn.");

static const u8 sDuskBallDesc[] = _(
    "Works well if\n"
    "used in a\n"
    "dark place.");

static const u8 sCherishBallDesc[] = _(
    "A rare Ball made\n"
    "in commemoration\n"
    "of some event.");

static const u8 sSportBallDesc[] = _(
    "A special Ball used\n"
    "in the Bug-Catching\n"
    "Contest.");

static const u8 sParkBallDesc[] = _(
    "A special Ball for\n"
    "the Pal Park.");

static const u8 sDreamBallDesc[] = _(
    "A Poké Ball used in\n"
    "the Entree Forest.\n"
    "It doesn't fail.");

static const u8 sBeastBallDesc[] = _(
    "A Ball designed to\n"
    "catch Ultra Beasts.");

// Medicine
static const u8 sPotionDesc[] = _(
    "Restores the HP of\n"
    "a Pokémon by\n"
    "20 points.");

static const u8 sAntidoteDesc[] = _(
    "Heals a poisoned\n"
    "Pokémon.");

static const u8 sBurnHealDesc[] = _(
    "Heals Pokémon\n"
    "of a burn.");

static const u8 sIceHealDesc[] = _(
    "Defrosts a frozen\n"
    "Pokémon.");

static const u8 sAwakeningDesc[] = _(
    "Awakens a sleeping\n"
    "Pokémon.");

static const u8 sParalyzeHealDesc[] = _(
    "Heals a paralyzed\n"
    "Pokémon.");

static const u8 sFullRestoreDesc[] = _(
    "Fully restores the\n"
    "HP and status of a\n"
    "Pokémon.");

static const u8 sMaxPotionDesc[] = _(
    "Fully restores the\n"
    "HP of a Pokémon.");

static const u8 sHyperPotionDesc[] = _(
    "Restores the HP of\n"
    "a Pokémon by\n"
    "120 points.");

static const u8 sSuperPotionDesc[] = _(
    "Restores the HP of\n"
    "a Pokémon by\n"
    "60 points.");

static const u8 sFullHealDesc[] = _(
    "Heals all the\n"
    "status problems of\n"
    "one Pokémon.");

static const u8 sReviveDesc[] = _(
    "Revives a fainted\n"
    "Pokémon with half\n"
    "its HP.");

static const u8 sMaxReviveDesc[] = _(
    "Revives a fainted\n"
    "Pokémon with all\n"
    "its HP.");

static const u8 sFreshWaterDesc[] = _(
    "A mineral water\n"
    "that restores HP\n"
    "by 30 points.");

static const u8 sSodaPopDesc[] = _(
    "A fizzy soda drink\n"
    "that restores HP\n"
    "by 50 points.");

static const u8 sLemonadeDesc[] = _(
    "A very sweet drink\n"
    "that restores HP\n"
    "by 70 points.");

static const u8 sMoomooMilkDesc[] = _(
    "A nutritious milk\n"
    "that restores HP\n"
    "by 100 points.");

static const u8 sEnergyPowderDesc[] = _(
    "A bitter powder\n"
    "that restores HP\n"
    "by 60 points.");

static const u8 sEnergyRootDesc[] = _(
    "A bitter root\n"
    "that restores HP\n"
    "by 120 points.");

static const u8 sHealPowderDesc[] = _(
    "A bitter powder\n"
    "that heals all\n"
    "status problems.");

static const u8 sRevivalHerbDesc[] = _(
    "A very bitter herb\n"
    "that revives a\n"
    "fainted Pokémon.");

static const u8 sEtherDesc[] = _(
    "Restores the PP\n"
    "of a selected move\n"
    "by 10.");

static const u8 sMaxEtherDesc[] = _(
    "Fully restores the\n"
    "PP of a selected\n"
    "move.");

static const u8 sElixirDesc[] = _(
    "Restores the PP\n"
    "of all moves by 10.");

static const u8 sMaxElixirDesc[] = _(
    "Fully restores the\n"
    "PP of a Pokémon's\n"
    "moves.");

static const u8 sLavaCookieDesc[] = _(
    "A local specialty\n"
    "that heals all\n"
    "status problems.");

static const u8 sBlueFluteDesc[] = _(
    "A glass flute that\n"
    "awakens sleeping\n"
    "Pokémon.");

static const u8 sYellowFluteDesc[] = _(
    "A glass flute that\n"
    "snaps Pokémon\n"
    "out of confusion.");

static const u8 sRedFluteDesc[] = _(
    "A glass flute that\n"
    "snaps Pokémon\n"
    "out of attraction.");

static const u8 sBlackFluteDesc[] = _(
    "A glass flute that\n"
    "keeps away wild\n"
    "Pokémon.");

static const u8 sWhiteFluteDesc[] = _(
    "A glass flute that\n"
    "lures wild Pokémon.");

static const u8 sBerryJuiceDesc[] = _(
    "A 100% pure juice\n"
    "that restores HP\n"
    "by 20 points.");

static const u8 sSweetHeartDesc[] = _(
    "A sweet chocolate\n"
    "that restores HP\n"
    "by 20 points.");

static const u8 sBigMalasadaDesc[] = _(
    "Heals all the\n"
    "status problems of\n"
    "one Pokémon.");

static const u8 sOldGateauDesc[] = _(
    "Heals all the\n"
    "status problems of\n"
    "one Pokémon.");

static const u8 sSacredAshDesc[] = _(
    "Fully revives and\n"
    "restores all\n"
    "fainted Pokémon.");

// Collectibles
static const u8 sShoalSaltDesc[] = _(
    "Salt obtained from\n"
    "deep inside the\n"
    "Shoal Cave.");

static const u8 sShoalShellDesc[] = _(
    "A seashell found\n"
    "deep inside the\n"
    "Shoal Cave.");

static const u8 sRedShardDesc[] = _(
    "A shard from an\n"
    "ancient item. Can\n"
    "be sold cheaply.");

static const u8 sBlueShardDesc[] = _(
    "A shard from an\n"
    "ancient item. Can\n"
    "be sold cheaply.");

static const u8 sYellowShardDesc[] = _(
    "A shard from an\n"
    "ancient item. Can\n"
    "be sold cheaply.");

static const u8 sGreenShardDesc[] = _(
    "A shard from an\n"
    "ancient item. Can\n"
    "be sold cheaply.");

// Vitamins
static const u8 sHPUpDesc[] = _(
    "Raises the base HP\n"
    "of one Pokémon.");

static const u8 sProteinDesc[] = _(
    "Raises the base\n"
    "Attack stat of one\n"
    "Pokémon.");

static const u8 sIronDesc[] = _(
    "Raises the base\n"
    "Defense stat of\n"
    "one Pokémon.");

static const u8 sCarbosDesc[] = _(
    "Raises the base\n"
    "Speed stat of one\n"
    "Pokémon.");

static const u8 sCalciumDesc[] = _(
    "Raises the base\n"
    "Sp. Atk stat of one\n"
    "Pokémon.");

static const u8 sRareCandyDesc[] = _(
    "Raises the level\n"
    "of a Pokémon by\n"
    "one.");

static const u8 sPPUpDesc[] = _(
    "Raises the maximum\n"
    "PP of a selected\n"
    "move.");

static const u8 sZincDesc[] = _(
    "Raises the base\n"
    "Sp. Def stat of one\n"
    "Pokémon.");

static const u8 sPPMaxDesc[] = _(
    "Raises the PP of a\n"
    "move to its maximum\n"
    "points.");

// Battle items
static const u8 sGuardSpecDesc[] = _(
    "Prevents stat\n"
    "reduction when\n"
    "used in battle.");

static const u8 sDireHitDesc[] = _(
    "Raises the\n"
    "critical-hit ratio\n"
    "during one battle.");

static const u8 sXAttackDesc[] = _(
    "Raises the stat\n"
    "Attack during one\n"
    "battle.");

static const u8 sXDefendDesc[] = _(
    "Raises the stat\n"
    "Defense during one\n"
    "battle.");

static const u8 sXSpeedDesc[] = _(
    "Raises the stat\n"
    "Speed during one\n"
    "battle.");

static const u8 sXAccuracyDesc[] = _(
    "Raises accuracy\n"
    "of attack moves\n"
    "during one battle.");

static const u8 sXSpecialAttackDesc[] = _(
    "Raises the stat\n"
    "Sp. Atk during one\n"
    "battle.");

static const u8 sXSpecialDefenseDesc[] = _(
    "Raises the stat\n"
    "Sp. Def during one\n"
    "battle.");

static const u8 sPokeDollDesc[] = _(
    "Use to flee from\n"
    "any battle with\n"
    "a wild Pokémon.");

static const u8 sFluffyTailDesc[] = _(
    "Use to flee from\n"
    "any battle with\n"
    "a wild Pokémon.");

// Field items
static const u8 sSuperRepelDesc[] = _(
    "Repels weak wild\n"
    "Pokémon for 200\n"
    "steps.");

static const u8 sMaxRepelDesc[] = _(
    "Repels weak wild\n"
    "Pokémon for 250\n"
    "steps.");

static const u8 sAbilityCapsuleDesc[] = _(
    "Switches a Poké-\n"
    "mon's ability.");

static const u8 sEscapeRopeDesc[] = _(
    "Use to escape\n"
    "instantly from a\n"
    "cave or a dungeon.");

static const u8 sRepelDesc[] = _(
    "Repels weak wild\n"
    "Pokémon for 100\n"
    "steps.");

// Evolution stones
static const u8 sSunStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

static const u8 sMoonStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

static const u8 sFireStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

static const u8 sThunderStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

static const u8 sWaterStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

static const u8 sLeafStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

static const u8 sDawnStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

static const u8 sDuskStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

static const u8 sShinyStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

static const u8 sIceStoneDesc[] = _(
    "Makes certain\n"
    "species of Pokémon\n"
    "evolve.");

// Valuable items

static const u8 sRedApricornDesc[] = _(
    "A red apricorn.\n"
    "It assails your\n"
    "nostrils.");

static const u8 sBlueApricornDesc[] = _(
    "A blue apricorn.\n"
    "It smells a bit\n"
    "like grass.");

static const u8 sYellowApricornDesc[] = _(
    "A yellow apricorn.\n"
    "It has an invigor-\n"
    "ating scent.");

static const u8 sGreenApricornDesc[] = _(
    "A green apricorn.\n"
    "It has a strange,\n"
    "aromatic scent.");

static const u8 sPinkApricornDesc[] = _(
    "A pink apricorn.\n"
    "It has a nice,\n"
    "sweet scent.");

static const u8 sWhiteApricornDesc[] = _(
    "A white apricorn.\n"
    "It doesn't smell\n"
    "like anything.");

static const u8 sBlackApricornDesc[] = _(
    "A black apricorn.\n"
    "It has an inde-\n"
    "scribable scent.");

static const u8 sTinyMushroomDesc[] = _(
    "A plain mushroom\n"
    "that would sell\n"
    "at a cheap price.");

static const u8 sBigMushroomDesc[] = _(
    "A rare mushroom\n"
    "that would sell at a\n"
    "high price.");

static const u8 sPearlDesc[] = _(
    "A pretty pearl\n"
    "that would sell at a\n"
    "cheap price.");

static const u8 sBigPearlDesc[] = _(
    "A lovely large pearl\n"
    "that would sell at a\n"
    "high price.");

static const u8 sStardustDesc[] = _(
    "Beautiful red sand.\n"
    "Can be sold at a\n"
    "high price.");

static const u8 sStarPieceDesc[] = _(
    "A red gem shard.\n"
    "It would sell for a\n"
    "very high price.");

static const u8 sNuggetDesc[] = _(
    "A nugget of pure\n"
    "gold. Can be sold at\n"
    "a high price.");

static const u8 sHeartScaleDesc[] = _(
    "A lovely scale.\n"
    "It is coveted by\n"
    "collectors.");

static const u8 sRedNectarDesc[] = _(
    "Flower nectar that\n"
    "changes the form\n"
    "of certain Pokémon.");

static const u8 sYellowNectarDesc[] = _(
    "Flower nectar that\n"
    "changes the form\n"
    "of certain Pokémon.");

static const u8 sPinkNectarDesc[] = _(
    "Flower nectar that\n"
    "changes the form\n"
    "of certain Pokémon.");

static const u8 sPurpleNectarDesc[] = _(
    "Flower nectar that\n"
    "changes the form\n"
    "of certain Pokémon.");

static const u8 sRareBoneDesc[] = _(
    "A very rare bone.\n"
    "It can be sold at\n"
    "a high price.");

// Mail
static const u8 sOrangeMailDesc[] = _(
    "A Zigzagoon-print\n"
    "Mail to be held by\n"
    "a Pokémon.");

static const u8 sHarborMailDesc[] = _(
    "A Wingull-print\n"
    "Mail to be held by\n"
    "a Pokémon.");

static const u8 sGlitterMailDesc[] = _(
    "A Pikachu-print\n"
    "Mail to be held by\n"
    "a Pokémon.");

static const u8 sMechMailDesc[] = _(
    "A Magnemite-print\n"
    "Mail to be held by\n"
    "a Pokémon.");

static const u8 sWoodMailDesc[] = _(
    "A Slakoth-print\n"
    "Mail to be held by\n"
    "a Pokémon.");

static const u8 sWaveMailDesc[] = _(
    "A Wailmer-print\n"
    "Mail to be held by\n"
    "a Pokémon.");

static const u8 sBeadMailDesc[] = _(
    "Mail featuring a\n"
    "sketch of the\n"
    "holding Pokémon.");

static const u8 sShadowMailDesc[] = _(
    "A Duskull-print\n"
    "Mail to be held by\n"
    "a Pokémon.");

static const u8 sTropicMailDesc[] = _(
    "A Bellossom-print\n"
    "Mail to be held by\n"
    "a Pokémon.");

static const u8 sDreamMailDesc[] = _(
    "Mail featuring a\n"
    "sketch of the\n"
    "holding Pokémon.");

static const u8 sFabMailDesc[] = _(
    "A gorgeous-print\n"
    "Mail to be held\n"
    "by a Pokémon.");

static const u8 sRetroMailDesc[] = _(
    "Mail featuring the\n"
    "drawings of three\n"
    "Pokémon.");

// Berries
static const u8 sCheriBerryDesc[] = _(
    "A hold item that\n"
    "heals paralysis\n"
    "in battle.");

static const u8 sChestoBerryDesc[] = _(
    "A hold item that\n"
    "awakens Pokémon\n"
    "in battle.");

static const u8 sPechaBerryDesc[] = _(
    "A hold item that\n"
    "heals poisoning\n"
    "in battle.");

static const u8 sRawstBerryDesc[] = _(
    "A hold item that\n"
    "heals a burn in\n"
    "battle.");

static const u8 sAspearBerryDesc[] = _(
    "A hold item that\n"
    "defrosts Pokémon\n"
    "in battle.");

static const u8 sLeppaBerryDesc[] = _(
    "A hold item that\n"
    "restores 10 PP in\n"
    "battle.");

static const u8 sOranBerryDesc[] = _(
    "A hold item that\n"
    "restores 10 HP in\n"
    "battle.");

static const u8 sPersimBerryDesc[] = _(
    "A hold item that\n"
    "heals confusion\n"
    "in battle.");

static const u8 sLumBerryDesc[] = _(
    "A hold item that\n"
    "heals any status\n"
    "problem in battle.");

static const u8 sSitrusBerryDesc[] = _(
    "A hold item that\n"
    "restores 30 HP in\n"
    "battle.");

static const u8 sFigyBerryDesc[] = _(
    "A hold item that\n"
    "restores HP but\n"
    "may confuse.");

static const u8 sWikiBerryDesc[] = _(
    "A hold item that\n"
    "restores HP but\n"
    "may confuse.");

static const u8 sMagoBerryDesc[] = _(
    "A hold item that\n"
    "restores HP but\n"
    "may confuse.");

static const u8 sAguavBerryDesc[] = _(
    "A hold item that\n"
    "restores HP but\n"
    "may confuse.");

static const u8 sIapapaBerryDesc[] = _(
    "A hold item that\n"
    "restores HP but\n"
    "may confuse.");

static const u8 sRazzBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Razz.");

static const u8 sBlukBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Bluk.");

static const u8 sNanabBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Nanab.");

static const u8 sWepearBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Wepear.");

static const u8 sPinapBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Pinap.");

static const u8 sPomegBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base HP.");

static const u8 sKelpsyBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Attack.");

static const u8 sQualotBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Defense.");

static const u8 sHondewBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Sp. Atk.");

static const u8 sGrepaBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Sp. Def.");

static const u8 sTamatoBerryDesc[] = _(
    "Makes a Pokémon\n"
    "friendly but lowers\n"
    "base Speed.");

static const u8 sCornnBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Cornn.");

static const u8 sMagostBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Magost.");

static const u8 sRabutaBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Rabuta.");

static const u8 sNomelBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Nomel.");

static const u8 sSpelonBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Spelon.");

static const u8 sPamtreBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Pamtre.");

static const u8 sWatmelBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Watmel.");

static const u8 sDurinBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Durin.");

static const u8 sBelueBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow Belue.");

static const u8 sLiechiBerryDesc[] = _(
    "A hold item that\n"
    "raises Attack in\n"
    "a pinch.");

static const u8 sGanlonBerryDesc[] = _(
    "A hold item that\n"
    "raises Defense in\n"
    "a pinch.");

static const u8 sSalacBerryDesc[] = _(
    "A hold item that\n"
    "raises Speed in\n"
    "a pinch.");

static const u8 sPetayaBerryDesc[] = _(
    "A hold item that\n"
    "raises Sp. Atk in\n"
    "a pinch.");

static const u8 sApicotBerryDesc[] = _(
    "A hold item that\n"
    "raises Sp. Def in\n"
    "a pinch.");

static const u8 sLansatBerryDesc[] = _(
    "A hold item that\n"
    "ups the critical-\n"
    "hit rate in a pinch.");

static const u8 sStarfBerryDesc[] = _(
    "A hold item that\n"
    "sharply boosts a\n"
    "stat in a pinch.");

static const u8 sMicleBerryDesc[] = _(
    "When held, it ups\n"
    "the Accuracy of a\n"
    "move in a pinch.");

static const u8 sEnigmaBerryDesc[] = _(
    "{POKEBLOCK} ingredient.\n"
    "Plant in loamy soil\n"
    "to grow a mystery.");

static const u8 sOccaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Fire\n"
    "move if weak to it.");

static const u8 sPasshoBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Water\n"
    "move if weak to it.");

static const u8 sWacanBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Electric\n"
    "move if weak to it.");

static const u8 sRindoBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Grass\n"
    "move if weak to it.");

static const u8 sYacheBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Ice\n"
    "move if weak to it.");

static const u8 sChopleBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Fighting\n"
    "move if weak to it.");

static const u8 sKebiaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Poison\n"
    "move if weak to it.");

static const u8 sShucaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Ground\n"
    "move if weak to it.");

static const u8 sCobaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Flying\n"
    "move if weak to it.");

static const u8 sPayapaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Psychic\n"
    "move if weak to it.");

static const u8 sTangaBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Bug\n"
    "move if weak to it.");

static const u8 sChartiBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Rock\n"
    "move if weak to it.");

static const u8 sKasibBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Ghost\n"
    "move if weak to it.");

static const u8 sHabanBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Dragon\n"
    "move if weak to it.");

static const u8 sColburBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Dark\n"
    "move if weak to it.");

static const u8 sBabiriBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Steel\n"
    "move if weak to it.");

static const u8 sChilanBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Normal\n"
    "move.");

static const u8 sRoseliBerryDesc[] = _(
    "A hold item that\n"
    "weakens a Fairy\n"
    "move if weak to it.");

static const u8 sCustapBerryDesc[] = _(
    "It allows a Pokémon\n"
    "in a pinch to move\n"
    "first just once.");

static const u8 sJabocaBerryDesc[] = _(
    "If hit by a physical\n"
    "move, it will hurt\n"
    "the attacker a bit.");

static const u8 sRowapBerryDesc[] = _(
    "If hit by a special\n"
    "move, it will hurt\n"
    "the attacker a bit.");

static const u8 sKeeBerryDesc[] = _(
    "If hit by a physical\n"
    "move, it raises the\n"
    "Defense a bit.");

static const u8 sMarangaBerryDesc[] = _(
    "If hit by a special\n"
    "move, it raises the\n"
    "Sp. Def. a bit.");

// Hold items
static const u8 sBrightPowderDesc[] = _(
    "A hold item that\n"
    "casts a glare to\n"
    "reduce accuracy.");

static const u8 sWhiteHerbDesc[] = _(
    "A hold item that\n"
    "restores any\n"
    "lowered stat.");

static const u8 sMachoBraceDesc[] = _(
    "A hold item that\n"
    "promotes growth,\n"
    "but reduces Speed.");

static const u8 sExpShareDesc[] = _(
    "A hold item that\n"
    "gets Exp. points\n"
    "from battles.");

static const u8 sQuickClawDesc[] = _(
    "A hold item that\n"
    "occasionally allows\n"
    "the first strike.");

static const u8 sSootheBellDesc[] = _(
    "A hold item that\n"
    "calms spirits and\n"
    "fosters friendship.");

static const u8 sMentalHerbDesc[] = _(
    "A hold item that\n"
    "snaps Pokémon out\n"
    "of infatuation.");

static const u8 sChoiceBandDesc[] = _(
    "Raises a move's\n"
    "power, but permits\n"
    "only that move.");

static const u8 sKingsRockDesc[] = _(
    "A hold item that\n"
    "may cause flinching\n"
    "when the foe is hit.");

static const u8 sSilverPowderDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Bug-type moves.");

static const u8 sAmuletCoinDesc[] = _(
    "Doubles money in\n"
    "battle if the\n"
    "holder takes part.");

static const u8 sCleanseTagDesc[] = _(
    "A hold item that\n"
    "helps repel wild\n"
    "Pokémon.");

static const u8 sSoulDewDesc[] = _(
    "Hold item: raises\n"
    "Sp. Atk & Sp. Def of\n"
    "Latios & Latias.");

static const u8 sDeepSeaToothDesc[] = _(
    "A hold item that\n"
    "raises the Sp. Atk\n"
    "of Clamperl.");

static const u8 sDeepSeaScaleDesc[] = _(
    "A hold item that\n"
    "raises the Sp. Def\n"
    "of Clamperl.");

static const u8 sSmokeBallDesc[] = _(
    "A hold item that\n"
    "assures fleeing\n"
    "from wild Pokémon.");

static const u8 sEverstoneDesc[] = _(
    "A wondrous hold\n"
    "item that prevents\n"
    "evolution.");

static const u8 sFocusBandDesc[] = _(
    "A hold item that\n"
    "occasionally\n"
    "prevents fainting.");

static const u8 sLuckyEggDesc[] = _(
    "A hold item that\n"
    "boosts Exp. points\n"
    "earned in battle.");

static const u8 sScopeLensDesc[] = _(
    "A hold item that\n"
    "improves the\n"
    "critical-hit rate.");

static const u8 sMetalCoatDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Steel-type moves.");

static const u8 sLeftoversDesc[] = _(
    "A hold item that\n"
    "gradually restores\n"
    "HP in battle.");

static const u8 sDragonScaleDesc[] = _(
    "A strange scale\n"
    "held by Dragon-\n"
    "type Pokémon.");

static const u8 sOvalStoneDesc[] = _(
    "Makes a certain\n"
    "Pokémon evolve. It's\n"
    "shaped like an egg.");

static const u8 sProtectorDesc[] = _(
    "Loved by a certain\n"
    "Pokémon. It's stiff\n"
    "and heavy.");

static const u8 sElectirizerDesc[] = _(
    "Loved by a certain\n"
    "Pokémon. It's full\n"
    "of electric energy.");

static const u8 sMagmarizerDesc[] = _(
    "Loved by a certain\n"
    "Pokémon. It's full\n"
    "of magma energy.");

static const u8 sDubiousDiscDesc[] = _(
    "A transparent device\n"
    "overflowing with\n"
    "dubious data.");

static const u8 sReaperClothDesc[] = _(
    "Loved by a certain\n"
    "Pokémon. Imbued with\n"
    "spiritual energy.");

static const u8 sRazorClawDesc[] = _(
    "A hooked claw that\n"
    "ups the holder's\n"
    "critical-hit ratio.");

static const u8 sRazorFangDesc[] = _(
    "A hold item that\n"
    "may cause flinching\n"
    "when the foe is hit.");

static const u8 sPrismScaleDesc[] = _(
    "A mysterious scale\n"
    "that evolves certain\n"
    "Pokémon. It shines.");

static const u8 sWhippedDreamDesc[] = _(
    "A soft and sweet\n"
    "treat loved by\n"
    "a certain Pokémon.");

static const u8 sSachetDesc[] = _(
    "A sachet filled with\n"
    "perfumes loved by\n"
    "a certain Pokémon.");

static const u8 sLightBallDesc[] = _(
    "A hold item that\n"
    "raises the Atk and\n"
    "Sp. Atk of Pikachu.");

static const u8 sSoftSandDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Ground-type moves.");

static const u8 sHardStoneDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Rock-type moves.");

static const u8 sMiracleSeedDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Grass-type moves.");

static const u8 sBlackGlassesDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Dark-type moves.");

static const u8 sBlackBeltDesc[] = _(
    "A hold item that\n"
    "boosts Fighting-\n"
    "type moves.");

static const u8 sMagnetDesc[] = _(
    "A hold item that\n"
    "boosts Electric-\n"
    "type moves.");

static const u8 sMysticWaterDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Water-type moves.");

static const u8 sSharpBeakDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Flying-type moves.");

static const u8 sPoisonBarbDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Poison-type moves.");

static const u8 sNeverMeltIceDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Ice-type moves.");

static const u8 sSpellTagDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Ghost-type moves.");

static const u8 sTwistedSpoonDesc[] = _(
    "A hold item that\n"
    "boosts Psychic-\n"
    "type moves.");

static const u8 sCharcoalDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Fire-type moves.");

static const u8 sDragonFangDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Dragon-type moves.");

static const u8 sSilkScarfDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Normal-type moves.");

static const u8 sUpGradeDesc[] = _(
    "A peculiar box made\n"
    "by Silph Co.");

static const u8 sShellBellDesc[] = _(
    "A hold item that\n"
    "restores HP upon\n"
    "striking the foe.");

static const u8 sPowerBracerDesc[] = _(
    "A hold item that\n"
    "promotes Atk gain,\n"
    "but reduces Speed.");

static const u8 sPowerBeltDesc[] = _(
    "A hold item that\n"
    "promotes Def gain,\n"
    "but reduces Speed.");

static const u8 sPowerLensDesc[] = _(
    "Hold item that pro-\n"
    "motes Sp. Atk gain,\n"
    "but reduces Speed.");

static const u8 sPowerBandDesc[] = _(
    "Hold item that pro-\n"
    "motes Sp. Def gain,\n"
    "but reduces Speed.");

static const u8 sPowerAnkletDesc[] = _(
    "A hold item that\n"
    "promotes Spd gain,\n"
    "but reduces Speed.");

static const u8 sPowerWeightDesc[] = _(
    "A hold item that\n"
    "promotes HP gain,\n"
    "but reduces Speed.");

static const u8 sSeaIncenseDesc[] = _(
    "A hold item that\n"
    "slightly boosts\n"
    "Water-type moves.");

static const u8 sLaxIncenseDesc[] = _(
    "A hold item that\n"
    "slightly lowers the\n"
    "foe's accuracy.");

static const u8 sOddIncenseDesc[] = _(
    "A hold item that\n"
    "boosts Psychic-\n"
    "type moves.");

static const u8 sRockIncenseDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Rock-type moves.");

static const u8 sFullIncenseDesc[] = _(
    "A held item that\n"
    "makes the holder\n"
    "move slower.");

static const u8 sWaveIncenseDesc[] = _(
    "A hold item that\n"
    "slightly boosts\n"
    "Water-type moves.");

static const u8 sRoseIncenseDesc[] = _(
    "A hold item that\n"
    "raises the power of\n"
    "Grass-type moves.");

static const u8 sLuckIncenseDesc[] = _(
    "Doubles money in\n"
    "battle if the\n"
    "holder takes part.");

static const u8 sPureIncenseDesc[] = _(
    "A hold item that\n"
    "helps repel wild\n"
    "Pokémon.");

static const u8 sLuckyPunchDesc[] = _(
    "A hold item that\n"
    "raises Chansey's\n"
    "critical-hit rate.");

static const u8 sMetalPowderDesc[] = _(
    "A hold item that\n"
    "raises Ditto's\n"
    "Defense.");

static const u8 sThickClubDesc[] = _(
    "A hold item that \n"
    "raises Cubone or\n"
    "Marowak's Attack.");

static const u8 sStickDesc[] = _(
    "A hold item that\n"
    "raises Farfetch'd's\n"
    "critical-hit ratio.");

static const u8 sRedScarfDesc[] = _(
    "A hold item that\n"
    "raises Cool in\n"
    "Contests.");

static const u8 sBlueScarfDesc[] = _(
    "A hold item that\n"
    "raises Beauty in\n"
    "Contests.");

static const u8 sPinkScarfDesc[] = _(
    "A hold item that\n"
    "raises Cute in\n"
    "Contests.");

static const u8 sGreenScarfDesc[] = _(
    "A hold item that\n"
    "raises Smart in\n"
    "Contests.");

static const u8 sYellowScarfDesc[] = _(
    "A hold item that\n"
    "raises Tough in\n"
    "Contests.");

// Key items
static const u8 sMachBikeDesc[] = _(
    "A folding bicycle\n"
    "that doubles your\n"
    "speed or better.");

static const u8 sCoinCaseDesc[] = _(
    "A case that holds\n"
    "up to 9,999 Coins.");

static const u8 sItemfinderDesc[] = _(
    "A device that\n"
    "signals an invisible\n"
    "item by sound.");

static const u8 sOldRodDesc[] = _(
    "Use by any body of\n"
    "water to fish for\n"
    "wild Pokémon.");

static const u8 sGoodRodDesc[] = _(
    "A decent fishing\n"
    "rod for catching\n"
    "wild Pokémon.");

static const u8 sSuperRodDesc[] = _(
    "The best fishing\n"
    "rod for catching\n"
    "wild Pokémon.");

static const u8 sSSTicketDesc[] = _(
    "The ticket required\n"
    "for sailing on a\n"
    "ferry.");

static const u8 sContestPassDesc[] = _(
    "The pass required\n"
    "for entering\n"
    "Pokémon Contests.");

static const u8 sWailmerPailDesc[] = _(
    "A tool used for\n"
    "watering Berries\n"
    "and plants.");

static const u8 sDevonGoodsDesc[] = _(
    "A package that\n"
    "contains Devon's\n"
    "machine parts.");

static const u8 sSootSackDesc[] = _(
    "A sack used to\n"
    "gather and hold\n"
    "volcanic ash.");

static const u8 sBasementKeyDesc[] = _(
    "The key for New\n"
    "Mauville beneath\n"
    "Mauville City.");

static const u8 sAcroBikeDesc[] = _(
    "A folding bicycle\n"
    "capable of jumps\n"
    "and wheelies.");

static const u8 sPokeblockCaseDesc[] = _(
    "A case for holding\n"
    "Pokéblocks made with\n"
    "a Berry Blender.");

static const u8 sLetterDesc[] = _(
    "A letter to Steven\n"
    "from the President\n"
    "of the Devon Corp.");

static const u8 sEonTicketDesc[] = _(
    "The ticket for a\n"
    "ferry to a distant\n"
    "southern island.");

static const u8 sRedOrbDesc[] = _(
    "A red, glowing orb\n"
    "said to contain an\n"
    "ancient power.");

static const u8 sBlueOrbDesc[] = _(
    "A blue, glowing orb\n"
    "said to contain an\n"
    "ancient power.");

static const u8 sScannerDesc[] = _(
    "A device found\n"
    "inside the\n"
    "Abandoned Ship.");

static const u8 sGoGogglesDesc[] = _(
    "Nifty goggles that\n"
    "protect eyes from\n"
    "desert sandstorms.");

static const u8 sMeteoriteDesc[] = _(
    "A meteorite found\n"
    "at Meteor Falls.");

static const u8 sRoom1KeyDesc[] = _(
    "A key that opens a\n"
    "door inside the\n"
    "Abandoned Ship.");

static const u8 sRoom2KeyDesc[] = _(
    "A key that opens a\n"
    "door inside the\n"
    "Abandoned Ship.");

static const u8 sRoom4KeyDesc[] = _(
    "A key that opens a\n"
    "door inside the\n"
    "Abandoned Ship.");

static const u8 sRoom6KeyDesc[] = _(
    "A key that opens a\n"
    "door inside the\n"
    "Abandoned Ship.");

static const u8 sStorageKeyDesc[] = _(
    "The key to the\n"
    "storage inside the\n"
    "Abandoned Ship.");

static const u8 sRootFossilDesc[] = _(
    "A fossil of an\n"
    "ancient, seafloor-\n"
    "dwelling Pokémon.");

static const u8 sClawFossilDesc[] = _(
    "A fossil of an\n"
    "ancient, seafloor-\n"
    "dwelling Pokémon.");

static const u8 sDevonScopeDesc[] = _(
    "A device by Devon\n"
    "that signals any\n"
    "unseeable Pokémon.");

// TMs/HMs
static const u8 sTM01Desc[] = _(
    "Powerful, but makes\n"
    "the user flinch if\n"
    "hit by the foe.");

static const u8 sTM02Desc[] = _(
    "Hooks and slashes\n"
    "the foe with long,\n"
    "sharp claws.");

static const u8 sTM03Desc[] = _(
    "Generates an\n"
    "ultrasonic wave\n"
    "that may confuse.");

static const u8 sTM04Desc[] = _(
    "Raises Sp. Atk and\n"
    "Sp. Def by focusing\n"
    "the mind.");

static const u8 sTM05Desc[] = _(
    "A savage roar that\n"
    "makes the foe flee \n"
    "to end the battle.");

static const u8 sTM06Desc[] = _(
    "Poisons the foe\n"
    "with a toxin that\n"
    "gradually worsens.");

static const u8 sTM07Desc[] = _(
    "Creates a hailstorm\n"
    "that damages all\n"
    "types except Ice.");

static const u8 sTM08Desc[] = _(
    "Bulks up the body\n"
    "to boost both\n"
    "Attack & Defense.");

static const u8 sTM09Desc[] = _(
    "Shoots 2 to 5 seeds\n"
    "in a row to strike\n"
    "the foe.");

static const u8 sTM10Desc[] = _(
    "The attack power\n"
    "varies among\n"
    "different Pokémon.");

static const u8 sTM11Desc[] = _(
    "Raises the power of\n"
    "Fire-type moves\n"
    "for 5 turns.");

static const u8 sTM12Desc[] = _(
    "Enrages the foe so\n"
    "it can only use\n"
    "attack moves.");

static const u8 sTM13Desc[] = _(
    "Fires an icy cold\n"
    "beam that may\n"
    "freeze the foe.");

static const u8 sTM14Desc[] = _(
    "A brutal snow-and-\n"
    "wind attack that\n"
    "may freeze the foe.");

static const u8 sTM15Desc[] = _(
    "Powerful, but needs\n"
    "recharging the\n"
    "next turn.");

static const u8 sTM16Desc[] = _(
    "Creates a wall of\n"
    "light that lowers\n"
    "Sp. Atk damage.");

static const u8 sTM17Desc[] = _(
    "Negates all damage,\n"
    "but may fail if used\n"
    "in succession.");

static const u8 sTM18Desc[] = _(
    "Raises the power of\n"
    "Water-type moves\n"
    "for 5 turns.");

static const u8 sTM19Desc[] = _(
    "Recovers half the\n"
    "HP of the damage \n"
    "this move inflicts.");

static const u8 sTM20Desc[] = _(
    "Prevents status\n"
    "abnormality with a\n"
    "mystical power.");

static const u8 sTM21Desc[] = _(
    "The less the user\n"
    "likes you, the more\n"
    "powerful this move.");

static const u8 sTM22Desc[] = _(
    "Absorbs sunlight in\n"
    "the 1st turn, then\n"
    "attacks next turn.");

static const u8 sTM23Desc[] = _(
    "Slams the foe with\n"
    "a hard tail. It may\n"
    "lower Defense.");

static const u8 sTM24Desc[] = _(
    "A powerful electric\n"
    "attack that may\n"
    "cause paralysis.");

static const u8 sTM25Desc[] = _(
    "Strikes the foe\n"
    "with a thunderbolt.\n"
    "It may paralyze.");

static const u8 sTM26Desc[] = _(
    "Causes a quake\n"
    "that has no effect\n"
    "on flying foes.");

static const u8 sTM27Desc[] = _(
    "The more the user\n"
    "likes you, the more\n"
    "powerful this move.");

static const u8 sTM28Desc[] = _(
    "Digs underground\n"
    "the 1st turn, then\n"
    "strikes next turn.");

static const u8 sTM29Desc[] = _(
    "A powerful psychic\n"
    "attack that may\n"
    "lower Sp. Def.");

static const u8 sTM30Desc[] = _(
    "Hurls a dark lump\n"
    "at the foe. It may\n"
    "lower Sp. Def.");

static const u8 sTM31Desc[] = _(
    "Destroys barriers\n"
    "like Light Screen\n"
    "and causes damage.");

static const u8 sTM32Desc[] = _(
    "Creates illusory\n"
    "copies to enhance\n"
    "elusiveness.");

static const u8 sTM33Desc[] = _(
    "Creates a wall of\n"
    "light that weakens\n"
    "physical attacks.");

static const u8 sTM34Desc[] = _(
    "Zaps the foe with a\n"
    "jolt of electricity\n"
    "that never misses.");

static const u8 sTM35Desc[] = _(
    "Looses a stream of\n"
    "fire that may burn\n"
    "the foe.");

static const u8 sTM36Desc[] = _(
    "Hurls sludge at the\n"
    "foe. It may poison\n"
    "the foe.");

static const u8 sTM37Desc[] = _(
    "Causes a sandstorm\n"
    "that hits the foe\n"
    "over several turns.");

static const u8 sTM38Desc[] = _(
    "A powerful fire\n"
    "attack that may\n"
    "burn the foe.");

static const u8 sTM39Desc[] = _(
    "Stops the foe from\n"
    "moving with rocks.\n"
    "May lower Speed.");

static const u8 sTM40Desc[] = _(
    "An extremely fast\n"
    "attack that can't\n"
    "be avoided.");

static const u8 sTM41Desc[] = _(
    "Prevents the foe\n"
    "from using the same\n"
    "move in a row.");

static const u8 sTM42Desc[] = _(
    "Raises Attack when\n"
    "poisoned, burned,\n"
    "or paralyzed.");

static const u8 sTM43Desc[] = _(
    "Adds an effect to\n"
    "attack depending\n"
    "on the location.");

static const u8 sTM44Desc[] = _(
    "The user sleeps for\n"
    "2 turns to restore\n"
    "health and status.");

static const u8 sTM45Desc[] = _(
    "Makes it tough to\n"
    "attack a foe of the\n"
    "opposite gender.");

static const u8 sTM46Desc[] = _(
    "While attacking,\n"
    "it may steal the\n"
    "foe's held item.");

static const u8 sTM47Desc[] = _(
    "Spreads hard-\n"
    "edged wings and\n"
    "slams into the foe.");

static const u8 sTM48Desc[] = _(
    "Switches abilities\n"
    "with the foe on the\n"
    "turn this is used.");

static const u8 sTM49Desc[] = _(
    "Steals the effects\n"
    "of the move the foe\n"
    "is trying to use.");

static const u8 sTM50Desc[] = _(
    "Enables full-power\n"
    "attack, but sharply\n"
    "lowers Sp. Atk.");


static const u8 sHM01Desc[] = _(
    "Attacks the foe\n"
    "with sharp blades\n"
    "or claws.");

static const u8 sHM02Desc[] = _(
    "Flies up on the\n"
    "first turn, then\n"
    "attacks next turn.");

static const u8 sHM03Desc[] = _(
    "Creates a huge\n"
    "wave, then crashes\n"
    "it down on the foe.");

static const u8 sHM04Desc[] = _(
    "Builds enormous\n"
    "power, then slams\n"
    "the foe.");

static const u8 sHM05Desc[] = _(
    "Looses a powerful\n"
    "blast of light that\n"
    "reduces accuracy.");

static const u8 sHM06Desc[] = _(
    "A rock-crushingly\n"
    "tough attack that\n"
    "may lower Defense.");

static const u8 sHM07Desc[] = _(
    "Attacks the foe\n"
    "with enough power\n"
    "to climb waterfalls.");

static const u8 sHM08Desc[] = _(
    "Dives underwater\n"
    "the 1st turn, then\n"
    "attacks next turn.");

// FireRed/LeafGreen key items
static const u8 sOaksParcelDesc[] = _(
    "A parcel for Prof.\n"
    "Oak from a Pokémon\n"
    "Mart's clerk.");

static const u8 sPokeFluteDesc[] = _(
    "A sweet-sounding\n"
    "flute that awakens\n"
    "Pokémon.");

static const u8 sSecretKeyDesc[] = _(
    "The key to the\n"
    "Cinnabar Island\n"
    "Gym's entrance.");

static const u8 sBikeVoucherDesc[] = _(
    "A voucher for\n"
    "obtaining a bicycle\n"
    "from the Bike Shop.");

static const u8 sGoldTeethDesc[] = _(
    "Gold dentures lost\n"
    "by the Safari\n"
    "Zone's Warden.");

static const u8 sOldAmberDesc[] = _(
    "A stone containing\n"
    "the genes of an\n"
    "ancient Pokémon.");

static const u8 sCardKeyDesc[] = _(
    "A card-type door\n"
    "key used in Silph\n"
    "Co's office.");

static const u8 sLiftKeyDesc[] = _(
    "An elevator key\n"
    "used in Team\n"
    "Rocket's Hideout.");

static const u8 sArmorFossilDesc[] = _(
    "A piece of a\n"
    "prehistoric Poké-\n"
    "mon's head.");

static const u8 sSkullFossilDesc[] = _(
    "A piece of a\n"
    "prehistoric Poké-\n"
    "mon's head.");

static const u8 sHelixFossilDesc[] = _(
    "A piece of an\n"
    "ancient marine\n"
    "Pokémon's seashell.");

static const u8 sDomeFossilDesc[] = _(
    "A piece of an\n"
    "ancient marine\n"
    "Pokémon's shell.");

static const u8 sCoverFossilDesc[] = _(
    "A piece of a\n"
    "prehistoric Poké-\n"
    "mon's back.");

static const u8 sPlumeFossilDesc[] = _(
    "A piece of a\n"
    "prehistoric Poké-\n"
    "mon's wing.");

static const u8 sJawFossilDesc[] = _(
    "A piece of a prehis-\n"
    "toric Pokémon's\n"
    "large jaw.");

static const u8 sSailFossilDesc[] = _(
    "A piece of a prehis-\n"
    "toric Pokémon's\n"
    "skin sail.");

static const u8 sSilphScopeDesc[] = _(
    "Silph Co's scope\n"
    "makes unseeable\n"
    "Pokémon visible.");

static const u8 sBicycleDesc[] = _(
    "A folding bicycle\n"
    "that is faster than\n"
    "the Running Shoes.");

static const u8 sTownMapDesc[] = _(
    "Can be viewed\n"
    "anytime. Shows your\n"
    "present location.");

static const u8 sVSSeekerDesc[] = _(
    "A rechargeable unit\n"
    "that flags battle-\n"
    "ready Trainers.");

static const u8 sFameCheckerDesc[] = _(
    "Stores information\n"
    "on famous people\n"
    "for instant recall.");

static const u8 sTMCaseDesc[] = _(
    "A convenient case \n"
    "that holds TMs and\n"
    "HMs.");

static const u8 sBerryPouchDesc[] = _(
    "A convenient\n"
    "container that\n"
    "holds Berries.");

static const u8 sTeachyTVDesc[] = _(
    "A TV set tuned to\n"
    "an advice program\n"
    "for Trainers.");

static const u8 sTriPassDesc[] = _(
    "A pass for ferries\n"
    "between One, Two,\n"
    "and Three Island.");

static const u8 sRainbowPassDesc[] = _(
    "For ferries serving\n"
    "Vermilion and the\n"
    "Sevii Islands.");

static const u8 sTeaDesc[] = _(
    "A thirst-quenching\n"
    "tea prepared by an\n"
    "old lady.");

static const u8 sMysticTicketDesc[] = _(
    "A ticket required\n"
    "to board the ship\n"
    "to Navel Rock.");

static const u8 sAuroraTicketDesc[] = _(
    "A ticket required\n"
    "to board the ship\n"
    "to Birth Island.");

static const u8 sPowderJarDesc[] = _(
    "Stores Berry\n"
    "Powder made using\n"
    "a Berry Crusher.");

static const u8 sRubyDesc[] = _(
    "An exquisite, red-\n"
    "glowing gem that\n"
    "symbolizes passion.");

static const u8 sSapphireDesc[] = _(
    "A brilliant blue gem\n"
    "that symbolizes\n"
    "honesty.");

// Emerald-specific key items
static const u8 sMagmaEmblemDesc[] = _(
    "A medal-like item in\n"
    "the same shape as\n"
    "Team Magma's mark.");

static const u8 sOldSeaMapDesc[] = _(
    "A faded sea chart\n"
    "that shows the way\n"
    "to a certain island.");

	// New items
static const u8 sWideLensDesc[] = _(
    "A magnifying lens\n"
    "that boosts the\n"
    "accuracy of moves.");

static const u8 sMuscleBandDesc[] = _(
    "A headband that\n"
    "boosts the power of\n"
    "physical moves.");

static const u8 sWiseGlassesDesc[] = _(
    "A pair of glasses\n"
    "that ups the power\n"
    "of special moves.");

static const u8 sExpertBeltDesc[] = _(
    "A belt that boosts\n"
    "the power of super\n"
    "effective moves.");

static const u8 sLightClayDesc[] = _(
    "Extends the length\n"
    "of barrier moves\n"
    "used by the holder.");

static const u8 sLifeOrbDesc[] = _(
    "Boosts the power of\n"
    "moves at the cost\n"
    "of some HP per turn.");

static const u8 sPowerHerbDesc[] = _(
    "Allows immediate\n"
    "use of a move that\n"
    "charges first.");

static const u8 sToxicOrbDesc[] = _(
    "A bizarre orb that\n"
    "badly poisons the\n"
    "holder in battle.");

static const u8 sFlameOrbDesc[] = _(
    "A bizarre orb that\n"
    "inflicts a burn on\n"
    "holder in battle.");

static const u8 sQuickPowderDesc[] = _(
    "An item to be held\n"
    "by Ditto. This odd\n"
    "powder boosts Speed.");

static const u8 sFocusSashDesc[] = _(
    "If the holder has\n"
    "full HP, it endures\n"
    "KO hits with 1 HP.");

static const u8 sZoomLensDesc[] = _(
    "If the holder moves\n"
    "after the foe, it'll\n"
    "boost accuracy.");

static const u8 sMetronomeDesc[] = _(
    "A held item that\n"
    "boosts a move used\n"
    "consecutively.");

static const u8 sIronBallDesc[] = _(
    "Cuts Speed and lets\n"
    "Flying-types be hit\n"
    "by Ground moves.");

static const u8 sLaggingTailDesc[] = _(
    "A held item that\n"
    "makes the holder\n"
    "move slower.");

static const u8 sDestinyKnotDesc[] = _(
    "If the holder falls\n"
    "in love, the foe\n"
    "does too.");

static const u8 sBlackSludgeDesc[] = _(
    "Gradually restores\n"
    "HP of Poison-types.\n"
    "Damages others.");

static const u8 sIcyRockDesc[] = _(
    "Extends the length\n"
    "of the move Hail\n"
    "used by the holder.");

static const u8 sSmoothRockDesc[] = _(
    "Extends the length\n"
    "of Sandstorm if\n"
    "used by the holder.");

static const u8 sHeatRockDesc[] = _(
    "Extends the length\n"
    "of Sunny Day if\n"
    "used by the holder.");

static const u8 sDampRockDesc[] = _(
    "Extends the length\n"
    "of Rain Dance if\n"
    "used by the holder.");

static const u8 sGripClawDesc[] = _(
    "Makes binding moves\n"
    "used by the holder\n"
    "go on for 7 turns.");

static const u8 sChoiceScarfDesc[] = _(
    "Boosts Speed, but\n"
    "allows the use of\n"
    "only one move.");

static const u8 sStickyBarbDesc[] = _(
    "Damages the holder\n"
    "each turn. May latch\n"
    "on to foes.");

static const u8 sShedShellDesc[] = _(
    "Enables the holder\n"
    "to switch out of\n"
    "battle without fail.");

static const u8 sBigRootDesc[] = _(
    "A held item that\n"
    "boosts the power of\n"
    "HP-stealing moves.");

static const u8 sChoiceSpecsDesc[] = _(
    "Boosts Sp. Atk, but\n"
    "allows the use of\n"
    "only one move.");

static const u8 sOddKeystoneDesc[] = _(
    "Voices can be heard\n"
    "from this odd stone\n"
    "occasionally.");

static const u8 sAdamantOrbDesc[] = _(
    "Boosts the power of\n"
    "Dialga's Dragon and\n"
    "Steel-type moves.");

static const u8 sLustrousOrbDesc[] = _(
    "Boosts the power of\n"
    "Palkia's Dragon and\n"
    "Water-type moves.");

static const u8 sGriseousOrbDesc[] = _(
    "Powers up Giratina's\n"
    "Dragon and Ghost-\n"
    "type moves.");

static const u8 sGracideaDesc[] = _(
    "Bouquets made with\n"
    "it are offered as a\n"
    "token of gratitude.");

static const u8 sBugMemoryDesc[] = _(
    "A disc with Bug\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sDarkMemoryDesc[] = _(
    "A disc with Dark\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sDragonMemoryDesc[] = _(
    "A disc with Dragon\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sElectricMemoryDesc[] = _(
    "A disc with Electric\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sFairyMemoryDesc[] = _(
    "A disc with Fairy\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sFightingMemoryDesc[] = _(
    "A disc with Fighting\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sFireMemoryDesc[] = _(
    "A disc with Fire\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sFlyingMemoryDesc[] = _(
    "A disc with Flying\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sGhostMemoryDesc[] = _(
    "A disc with Ghost\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sGrassMemoryDesc[] = _(
    "A disc with Grass\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sGroundMemoryDesc[] = _(
    "A disc with Ground\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sIceMemoryDesc[] = _(
    "A disc with Ice\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sPoisonMemoryDesc[] = _(
    "A disc with Poison\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sPsychicMemoryDesc[] = _(
    "A disc with Psychic\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sRockMemoryDesc[] = _(
    "A disc with Rock\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sSteelMemoryDesc[] = _(
    "A disc with Steel\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sWaterMemoryDesc[] = _(
    "A disc with Water\n"
    "type data. It swaps\n"
    "Silvally's type.");

static const u8 sFlamePlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Fire-type moves.");

static const u8 sSplashPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Water-type moves.");

static const u8 sZapPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of Elec-\n"
    "tric-type moves.");

static const u8 sMeadowPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Grass-type moves.");

static const u8 sIciclePlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Ice-type moves.");

static const u8 sFistPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of Fight-\n"
    "ing-type moves.");

static const u8 sToxicPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Poison-type moves.");

static const u8 sEarthPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Ground-type moves.");

static const u8 sSkyPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Flying-type moves.");

static const u8 sMindPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of Psy\n"
    "chic-type moves.");

static const u8 sInsectPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Bug-type moves.");

static const u8 sStonePlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Rock-type moves.");

static const u8 sSpookyPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Ghost-type moves.");

static const u8 sDracoPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Dragon-type moves.");

static const u8 sDreadPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Dark-type moves.");

static const u8 sIronPlateDesc[] = _(
    "A tablet that ups\n"
    "the power of\n"
    "Steel-type moves.");

static const u8 sEvioliteDesc[] = _(
    "Raises the Def and\n"
    "Sp. Def of Pokémon\n"
    "that can evolve.");

static const u8 sFloatStoneDesc[] = _(
    "It's so light that\n"
    "when held, it halves\n"
    "a Pokémon's weight.");

static const u8 sRockyHelmetDesc[] = _(
    "Hurts the foe if\n"
    "they touch its\n"
    "holder.");

static const u8 sAirBalloonDesc[] = _(
    "Elevates the holder\n"
    "in the air. If hit,\n"
    "this item will burst.");

static const u8 sRedCardDesc[] = _(
    "Switches out the\n"
    "foe if they hit the\n"
    "holder.");

static const u8 sRingTargetDesc[] = _(
    "Moves that wouldn't\n"
    "have effect will\n"
    "land on its holder.");

static const u8 sBindingBandDesc[] = _(
    "Increases the\n"
    "power of binding\n"
    "moves when held.");

static const u8 sEjectButtonDesc[] = _(
    "Switches out the\n"
    "user if they're hit\n"
    "by the foe.");

static const u8 sAbsorbBulbDesc[] = _(
    "Raises Sp. Atk if\n"
    "the holder is hit by\n"
    "a Water-type move.");

static const u8 sCellBatteryDesc[] = _(
    "Raises Atk if the\n"
    "holder is hit by an\n"
    "Electric-type move.");

static const u8 sLuminousMossDesc[] = _(
    "Raises Sp. Def if\n"
    "the holder is hit by\n"
    "a Water-type move.");

static const u8 sSnowballDesc[] = _(
    "Raises Atk if its\n"
    "holder is hit by an\n"
    "Ice-type move.");

static const u8 sWeaknessPolicyDesc[] = _(
    "If hit by a Super\n"
    "Effective move, ups\n"
    "Atk and Sp. Atk.");

static const u8 sDouseDriveDesc[] = _(
    "Changes Genesect's\n"
    "Techno Blast to\n"
    "Water-type.");

static const u8 sShockDriveDesc[] = _(
    "Changes Genesect's\n"
    "Techno Blast to\n"
    "Electric-type.");

static const u8 sBurnDriveDesc[] = _(
    "Changes Genesect's\n"
    "Techno Blast to\n"
    "Fire-type.");

static const u8 sChillDriveDesc[] = _(
    "Changes Genesect's\n"
    "Techno Blast to\n"
    "Ice-type.");

static const u8 sFireGemDesc[] = _(
    "Increases the\n"
    "power of Fire\n"
    "Type moves.");

static const u8 sWaterGemDesc[] = _(
    "Increases the\n"
    "power of Water\n"
    "Type moves.");

static const u8 sElectricGemDesc[] = _(
    "Increases the\n"
    "power of Electric\n"
    "Type moves.");

static const u8 sGrassGemDesc[] = _(
    "Increases the\n"
    "power of Grass\n"
    "Type moves.");

static const u8 sIceGemDesc[] = _(
    "Increases the\n"
    "power of Ice\n"
    "Type moves.");

static const u8 sFightingGemDesc[] = _(
    "Increases the\n"
    "power of Fighting\n"
    "Type moves.");

static const u8 sPoisonGemDesc[] = _(
    "Increases the\n"
    "power of Poison\n"
    "Type moves.");

static const u8 sGroundGemDesc[] = _(
    "Increases the\n"
    "power of Ground\n"
    "Type moves.");

static const u8 sFlyingGemDesc[] = _(
    "Increases the\n"
    "power of Flying\n"
    "Type moves.");

static const u8 sPsychicGemDesc[] = _(
    "Increases the\n"
    "power of Psychic\n"
    "Type moves.");

static const u8 sBugGemDesc[] = _(
    "Increases the\n"
    "power of Bug\n"
    "Type moves.");

static const u8 sRockGemDesc[] = _(
    "Increases the\n"
    "power of Rock\n"
    "Type moves.");

static const u8 sGhostGemDesc[] = _(
    "Increases the\n"
    "power of Ghost\n"
    "Type moves.");

static const u8 sDragonGemDesc[] = _(
    "Increases the\n"
    "power of Dragon\n"
    "Type moves.");

static const u8 sDarkGemDesc[] = _(
    "Increases the\n"
    "power of Dark\n"
    "Type moves.");

static const u8 sSteelGemDesc[] = _(
    "Increases the\n"
    "power of Steel\n"
    "Type moves.");

static const u8 sNormalGemDesc[] = _(
    "Increases the\n"
    "power of Normal\n"
    "Type moves.");

static const u8 sFairyGemDesc[] = _(
    "Increases the\n"
    "power of Fairy\n"
    "Type moves.");

static const u8 sAssaultVestDesc[] = _(
    "Raises Sp. Def but\n"
    "prevents the use\n"
    "of status moves.");

static const u8 sPixiePlateDesc[] = _(
    "A stone tablet that\n"
    "boosts the power of\n"
    "Fairy-type moves.");

static const u8 sSafetyGogglesDesc[] = _(
    "Protect from\n"
    "weather damage and\n"
    "powder moves.");

static const u8 sGengariteDesc[] = _(
    "This stone enables\n"
    "Gengar to Mega\n"
    "Evolve in battle.");

static const u8 sGardevoiriteDesc[] = _(
    "This stone enables\n"
    "Gardevoir to Mega\n"
    "Evolve in battle.");

static const u8 sAmpharositeDesc[] = _(
    "This stone enables\n"
    "Ampharos to Mega\n"
    "Evolve in battle.");

static const u8 sVenusauriteDesc[] = _(
    "This stone enables\n"
    "Venusaur to Mega\n"
    "Evolve in battle.");

static const u8 sCharizarditeDesc[] = _(
    "This stone enables\n"
    "Charizard to Mega\n"
    "Evolve in battle.");

static const u8 sBlastoisiniteDesc[] = _(
    "This stone enables\n"
    "Blastoise to Mega\n"
    "Evolve in battle.");

static const u8 sMewtwoniteDesc[] = _(
    "This stone enables\n"
    "Mewtwo to Mega\n"
    "Evolve in battle.");

static const u8 sBlazikeniteDesc[] = _(
    "This stone enables\n"
    "Blaziken to Mega\n"
    "Evolve in battle.");

static const u8 sMedichamiteDesc[] = _(
    "This stone enables\n"
    "Medicham to Mega\n"
    "Evolve in battle.");

static const u8 sHoundoominiteDesc[] = _(
    "This stone enables\n"
    "Houndoom to Mega\n"
    "Evolve in battle.");

static const u8 sAggroniteDesc[] = _(
    "This stone enables\n"
    "Aggron to Mega\n"
    "Evolve in battle.");

static const u8 sBanettiteDesc[] = _(
    "This stone enables\n"
    "Banette to Mega\n"
    "Evolve in battle.");

static const u8 sTyranitariteDesc[] = _(
    "This stone enables\n"
    "Tyranitar to Mega\n"
    "Evolve in battle.");

static const u8 sScizoriteDesc[] = _(
    "This stone enables\n"
    "Scizor to Mega\n"
    "Evolve in battle.");

static const u8 sPinsiriteDesc[] = _(
    "This stone enables\n"
    "Pinsir to Mega\n"
    "Evolve in battle.");

static const u8 sAerodactyliteDesc[] = _(
    "This stone enables\n"
    "Aerodactyl to Mega\n"
    "Evolve in battle.");

static const u8 sLucarioniteDesc[] = _(
    "This stone enables\n"
    "Lucario to Mega\n"
    "Evolve in battle.");

static const u8 sAbomasiteDesc[] = _(
    "This stone enables\n"
    "Abomasnow to Mega\n"
    "Evolve in battle.");

static const u8 sKangaskhaniteDesc[] = _(
    "This stone enables\n"
    "Kangaskhan to Mega\n"
    "Evolve in battle.");

static const u8 sGyaradositeDesc[] = _(
    "This stone enables\n"
    "Gyarados to Mega\n"
    "Evolve in battle.");

static const u8 sAbsoliteDesc[] = _(
    "This stone enables\n"
    "Absol to Mega\n"
    "Evolve in battle.");

static const u8 sAlakaziteDesc[] = _(
    "This stone enables\n"
    "Alakazam to Mega\n"
    "Evolve in battle.");

static const u8 sHeracroniteDesc[] = _(
    "This stone enables\n"
    "Heracross to Mega\n"
    "Evolve in battle.");

static const u8 sMawiliteDesc[] = _(
    "This stone enables\n"
    "Mawile to Mega\n"
    "Evolve in battle.");

static const u8 sManectiteDesc[] = _(
    "This stone enables\n"
    "Manectric to Mega\n"
    "Evolve in battle.");

static const u8 sGarchompiteDesc[] = _(
    "This stone enables\n"
    "Garchomp to Mega\n"
    "Evolve in battle.");

static const u8 sLatiasiteDesc[] = _(
    "This stone enables\n"
    "Latias to Mega\n"
    "Evolve in battle.");

static const u8 sLatiositeDesc[] = _(
    "This stone enables\n"
    "Latios to Mega\n"
    "Evolve in battle.");

static const u8 sSwampertiteDesc[] = _(
    "This stone enables\n"
    "Swampert to Mega\n"
    "Evolve in battle.");

static const u8 sSceptiliteDesc[] = _(
    "This stone enables\n"
    "Sceptile to Mega\n"
    "Evolve in battle.");

static const u8 sSableniteDesc[] = _(
    "This stone enables\n"
    "Sableye to Mega\n"
    "Evolve in battle.");

static const u8 sAltarianiteDesc[] = _(
    "This stone enables\n"
    "Altaria to Mega\n"
    "Evolve in battle.");

static const u8 sGalladiteDesc[] = _(
    "This stone enables\n"
    "Gallade to Mega\n"
    "Evolve in battle.");

static const u8 sAudiniteDesc[] = _(
    "This stone enables\n"
    "Audino to Mega\n"
    "Evolve in battle.");

static const u8 sMetagrossiteDesc[] = _(
    "This stone enables\n"
    "Metagross to Mega\n"
    "Evolve in battle.");

static const u8 sSharpedoniteDesc[] = _(
    "This stone enables\n"
    "Sharpedo to Mega\n"
    "Evolve in battle.");

static const u8 sSlowbroniteDesc[] = _(
    "This stone enables\n"
    "Slowbro to Mega\n"
    "Evolve in battle.");

static const u8 sSteelixiteDesc[] = _(
    "This stone enables\n"
    "Steelix to Mega\n"
    "Evolve in battle.");

static const u8 sPidgeotiteDesc[] = _(
    "This stone enables\n"
    "Pidgeot to Mega\n"
    "Evolve in battle.");

static const u8 sGlalititeDesc[] = _(
    "This stone enables\n"
    "Glalie to Mega\n"
    "Evolve in battle.");

static const u8 sDianciteDesc[] = _(
    "This stone enables\n"
    "Diancie to Mega\n"
    "Evolve in battle.");

static const u8 sCameruptiteDesc[] = _(
    "This stone enables\n"
    "Camerupt to Mega\n"
    "Evolve in battle.");

static const u8 sLopunniteDesc[] = _(
    "This stone enables\n"
    "Lopunny to Mega\n"
    "Evolve in battle.");

static const u8 sSalamenciteDesc[] = _(
    "This stone enables\n"
    "Salamence to Mega\n"
    "Evolve in battle.");

static const u8 sBeedrilliteDesc[] = _(
    "This stone enables\n"
    "Beedrill to Mega\n"
    "Evolve in battle.");

static const u8 sMegaBraceletDesc[] = _(
    "Enables {PKMN} holding\n"
    "their Mega Stone to\n"
    "Mega Evolve.");

static const u8 sProtectPadsDesc[] = _(
    "Guard the holder\n"
    "from contact move\n"
    "effects.");

static const u8 sTerrainExtenderDesc[] = _(
    "Extends the length\n"
    "of the active\n"
    "battle terrain.");

static const u8 sElectricSeedDesc[] = _(
    "Boosts Defense on\n"
    "Electric Terrain,\n"
    "but only one time.");

static const u8 sGrassySeedDesc[] = _(
    "Boosts Defense on\n"
    "Grassy Terrain,\n"
    "but only one time.");

static const u8 sMistySeedDesc[] = _(
    "Boosts Sp. Def. on\n"
    "Misty Terrain,\n"
    "but only one time.");

static const u8 sPsychicSeedDesc[] = _(
    "Boosts Sp. Def. on\n"
    "Psychic Terrain,\n"
    "but only one time.");

static const u8 sAdrenalineOrbDesc[] = _(
    "Boosts Speed if the\n"
    "user is intimidated,\n"
    "but only one time.");

static const u8 sHoneyDesc[] = _(
    "Sweet honey that\n"
    "attracts wild\n"
    "Pokémon when used.");

static const u8 sHealthFeatherDesc[] = _(
    "An item that raises\n"
    "the base HP of\n"
    "a Pokémon.");

static const u8 sMuscleFeatherDesc[] = _(
    "An item that raises\n"
    "the base Attack of\n"
    "a Pokémon.");

static const u8 sResistFeatherDesc[] = _(
    "An item that raises\n"
    "the base Defense\n"
    "of a Pokémon.");

static const u8 sGeniusFeatherDesc[] = _(
    "An item that raises\n"
    "the base Sp. Atk.\n"
    "of a Pokémon.");

static const u8 sCleverFeatherDesc[] = _(
    "An item that raises\n"
    "the base Sp. Def.\n"
    "of a Pokémon.");

static const u8 sSwiftFeatherDesc[] = _(
    "An item that raises\n"
    "the base Speed of\n"
    "a Pokémon.");

static const u8 sPrettyFeatherDesc[] = _(
    "A beautiful yet\n"
    "plain feather that\n"
    "does nothing.");

static const u8 sShinyCharmDesc[] = _(
	"A charm that will\n"
    "raise the chance\n"
    "of Shiny Pokémon.");
    
static const u8 sOvalCharmDesc[] = _(
    "Raises the chance\n"
    "of finding eggs\n"
    "at the daycare.");

static const u8 sZRingDesc[] = _(
    "A strange ring\n"
    "that enables\n"
    "Z-Move usage.");

static const u8 sNormaliumZDesc[] = _(
    "Upgrade Normal-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sFightiniumZDesc[] = _(
    "Upgrade Fighting-\n"
    "type moves into\n"
    "Z-Moves.");
    
static const u8 sFlyiniumZDesc[] = _(
    "Upgrade Flying-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sPoisoniumZDesc[] = _(
    "Upgrade Poison-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sGroundiumZDesc[] = _(
    "Upgrade Ground-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sRockiumZDesc[] = _(
    "Upgrade Rock-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sBuginiumZDesc[] = _(
    "Upgrade Bug-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sGhostiumZDesc[] = _(
    "Upgrade Ghost-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sSteeliumZDesc[] = _(
    "Upgrade Steel-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sFiriumZDesc[] = _(
    "Upgrade Fire-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sWateriumZDesc[] = _(
    "Upgrade Water-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sGrassiumZDesc[] = _(
    "Upgrade Grass-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sElectriumZDesc[] = _(
    "Upgrade Electric-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sPsychiumZDesc[] = _(
    "Upgrade Psychic-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sIciumZDesc[] = _(
    "Upgrade Ice-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sDragoniumZDesc[] = _(
    "Upgrade Dragon-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sDarkiniumZDesc[] = _(
    "Upgrade Dark-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sFairiumZDesc[] = _(
    "Upgrade Fairy-\n"
    "type moves into\n"
    "Z-Moves.");

static const u8 sAloraichiumZDesc[] = _(
    "Upgrade Alolan\n"
    "Raichu's Thunder-\n"
    "bolt into a Z-Move.");

static const u8 sDecidiumZDesc[] = _(
    "Upgrade Decidu-\n"
    "eye's Spirit Sha-\n"
    "ckle into a Z-Move.");

static const u8 sEeviumZDesc[] = _(
    "Upgrade Eevee's\n"
    "Last Resort\n"
    "into a Z-Move.");

static const u8 sInciniumZDesc[] = _(
    "Upgrade Incine-\n"
    "roar's Darkest La-\n"
    "riat into a Z-Move.");

static const u8 sKommoniumZDesc[] = _(
    "Upgrade Kommo-o's\n"
    "Clanging Scales\n"
    "into a Z-Move.");

static const u8 sLunaliumZDesc[] = _(
    "Upgrade Lunala's\n"
    "Moongeist Beam\n"
    "into a Z-Move.");

static const u8 sLycaniumZDesc[] = _(
    "Upgrade Lycanroc's\n"
    "Stone Edge\n"
    "into a Z-Move.");

static const u8 sMarshadiumZDesc[] = _(
    "Upgrade Marsha-\n"
    "dow's Spectral Thi-\n"
    "ef into a Z-Move.");

static const u8 sMewniumZDesc[] = _(
    "Upgrade Mew's\n"
    "Psychic into\n"
    "a Z-Move.");

static const u8 sMimikiumZDesc[] = _(
    "Upgrade Mimikyu's\n"
    "Play Rough\n"
    "into a Z-Move.");

static const u8 sPikaniumZDesc[] = _(
    "Upgrade Pikachu's\n"
    "Volt Tackle\n"
    "into a Z-Move.");

static const u8 sPikashuniumZDesc[] = _(
    "Upgrade Pikachu w/\n"
    "a cap's Thunderbolt\n"
    "into a Z-Move.");

static const u8 sPrimariumZDesc[] = _(
    "Upgrade Primarina's\n"
    "Sparkling Aria\n"
    "into a Z-Move.");

static const u8 sSnorliumZDesc[] = _(
    "Upgrade Snorlax's\n"
    "Giga Impact\n"
    "into a Z-Move.");

static const u8 sSolganiumZDesc[] = _(
    "Upgrade Solgaleo's\n"
    "Sunsteel Strike\n"
    "into a Z-Move.");

static const u8 sTapuniumZDesc[] = _(
    "Upgrade the tapu's\n"
    "Nature's Madness\n"
    "into a Z-Move.");

static const u8 sUltranecroziumZDesc[] = _(
    "A crystal to turn\n"
    "fused Necrozma\n"
    "into a new form.");
#endif