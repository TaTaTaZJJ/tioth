#include "global.h"
#include "config.h"
#include "strings.h"
#include "battle_pyramid_bag.h"
#include "item_menu.h"

ALIGNED(4)
const u8 gText_ExpandedPlaceholder_Empty[] = _("");
const u8 gText_ExpandedPlaceholder_Kun[] = _("");
const u8 gText_ExpandedPlaceholder_Chan[] = _("");

const u8 gText_ExpandedPlaceholder_Sapphire[] =
#ifdef CHINESE
    _("蓝宝石");
#else
    _("SAPPHIRE");
#endif

const u8 gText_ExpandedPlaceholder_Ruby[] =
#ifdef CHINESE
    _("红宝石");
#else
    _("RUBY");
#endif

const u8 gText_ExpandedPlaceholder_Emerald[] =
#ifdef CHINESE
    _("绿宝石");
#else
    _("EMERALD");
#endif

const u8 gText_ExpandedPlaceholder_Aqua[] =
#ifdef CHINESE
    _("水舰队");
#else
    _("AQUA");
#endif

const u8 gText_ExpandedPlaceholder_Magma[] =
#ifdef CHINESE
    _("火岩队");
#else
    _("MAGMA");
#endif

const u8 gText_ExpandedPlaceholder_Archie[] =
#ifdef CHINESE
    _("水梧桐");
#else
    _("ARCHIE");
#endif

const u8 gText_ExpandedPlaceholder_Maxie[] =
#ifdef CHINESE
    _("赤焰松");
#else
    _("MAXIE");
#endif

const u8 gText_ExpandedPlaceholder_Kyogre[] =
#ifdef CHINESE
    _("盖欧卡");
#else
    _("KYOGRE");
#endif

const u8 gText_ExpandedPlaceholder_Groudon[] =
#ifdef CHINESE
    _("固拉多");
#else
    _("GROUDON");
#endif

const u8 gText_ExpandedPlaceholder_Brendan[] =
#ifdef CHINESE
    _("佑树");
#else
    _("BRENDAN");
#endif

const u8 gText_ExpandedPlaceholder_May[] =
#ifdef CHINESE
    _("小遥");
#else
    _("MAY");
#endif

const u8 gText_EggNickname[] =
#ifdef CHINESE
    _("蛋");
#else
    _("EGG");
#endif

const u8 gText_Pokemon[] =
#ifdef CHINESE
    _("宝可梦");
#else
    _("POKéMON");
#endif

const u8 gText_ProfBirchMatchCallName[] =
#ifdef CHINESE
    _("小田卷博士");
#else
    _("PROF. BIRCH");
#endif

const u8 gText_MainMenuNewGame[] =
#ifdef CHINESE
    _("新游戏");
#else
    _("NEW GAME");
#endif

const u8 gText_MainMenuContinue[] =
#ifdef CHINESE
    _("继续游戏");
#else
    _("CONTINUE");
#endif

const u8 gText_MainMenuOption[] =
#ifdef CHINESE
    _("设置");
#else
    _("OPTION");
#endif

const u8 gText_MainMenuMysteryGift[] =
#ifdef CHINESE
    _("神秘礼物");
#else
    _("MYSTERY GIFT");
#endif

const u8 gText_MainMenuMysteryGift2[] =
#ifdef CHINESE
    _("神秘礼物");
#else
    _("MYSTERY GIFT");
#endif

const u8 gText_MainMenuMysteryEvents[] =
#ifdef CHINESE
    _("神秘事件");
#else
    _("MYSTERY EVENTS");
#endif

const u8 gText_WirelessNotConnected[] =
#ifdef CHINESE
    _("无线适配器未连接。");
#else
    _("The Wireless Adapter is not\nconnected.");
#endif

const u8 gText_MysteryGiftCantUse[] =
#ifdef CHINESE
    _("无线适配器正连接，\n无法使用神秘礼物。");
#else
    _("MYSTERY GIFT can't be used while\nthe Wireless Adapter is attached.");
#endif

const u8 gText_MysteryEventsCantUse[] =
#ifdef CHINESE
    _("无线适配器正连接，\n无法进行神秘事件。");
#else
    _("MYSTERY EVENTS can't be used while\nthe Wireless Adapter is attached.");
#endif

const u8 gText_UpdatingSaveExternalData[] =
#ifdef CHINESE
    _("存档文件外接更新中，\n 请稍等。"); // Unused
#else
    _("Updating save file using external\ndata. Please wait."); // Unused
#endif

const u8 gText_SaveFileUpdated[] =
#ifdef CHINESE
    _("存档文件已经更新。"); // Unused
#else
    _("The save file has been updated.");                       // Unused
#endif

const u8 gText_SaveFileCorrupted[] =
#ifdef CHINESE
    _("存档已损坏，\n将读取最近一次的存档。");
#else
    _("The save file is corrupted. The\nprevious save file will be loaded.");
#endif

const u8 gText_SaveFileErased[] =
#ifdef CHINESE
    _("由于存档受损或毁坏\n，已经将其擦除。");
#else
    _("The save file has been erased\ndue to corruption or damage.");
#endif

const u8 gJPText_No1MSubCircuit[] = _("1Mサブきばんが ささっていません！");

const u8 gText_BatteryRunDry[] =
#ifdef CHINESE
    _("内部电池已经耗尽。\n游戏仍然可以游玩。\p但基于时钟变化的事件不会再发生。");
#else
    _("The internal battery has run dry.\nThe game can be played.\pHowever, clock-based events will\nno longer occur.");
#endif

const u8 gText_Player[] =
#ifdef CHINESE
    _("玩家");
#else
    _("PLAYER");  // Unused
#endif

const u8 gText_Pokedex[] =
#ifdef CHINESE
    _("图鉴");
#else
    _("POKéDEX"); // Unused
#endif

const u8 gText_Time[] =
#ifdef CHINESE
    _("时间");
#else
    _("TIME");
#endif

const u8 gText_Badges[] =
#ifdef CHINESE
    _("徽章");
#else
    _("BADGES");                         // Unused
#endif

const u8 gText_AButton[] =
#ifdef CHINESE
    _("A键"); // Unused
#else
    _("A Button");                       // Unused
#endif

const u8 gText_BButton[] =
#ifdef CHINESE
    _("B键"); // Unused
#else
    _("B Button");                       // Unused
#endif

const u8 gText_RButton[] =
#ifdef CHINESE
    _("R键"); // Unused
#else
    _("R Button");                       // Unused
#endif

const u8 gText_LButton[] =
#ifdef CHINESE
    _("L键"); // Unused
#else
    _("L Button");                       // Unused
#endif

const u8 gText_Start[] =
#ifdef CHINESE
    _("开始"); // Unused
#else
    _("START");                          // Unused
#endif

const u8 gText_Select[] =
#ifdef CHINESE
    _("选择"); // Unused
#else
    _("SELECT");                         // Unused
#endif

const u8 gText_ControlPad[] =
#ifdef CHINESE
    _("方向控制键"); // Unused
#else
    _("+ Control Pad");                  // Unused
#endif

const u8 gText_LButtonRButton[] =
#ifdef CHINESE
    _("L键R键"); // Unused
#else
    _("L Button  R Button");             // Unused
#endif

const u8 gText_Controls[] =
#ifdef CHINESE
    _("控制"); // Unused
#else
    _("CONTROLS");                       // Unused
#endif

ALIGNED(4)
const u8 gText_PickOk[] =
#ifdef CHINESE
    _("{DPAD_UPDOWN}选取{A_BUTTON}确认"); // Unused
#else
    _("{DPAD_UPDOWN}PICK {A_BUTTON}OK"); // Unused
#endif

ALIGNED(4)
const u8 gText_Next[] =
#ifdef CHINESE
    _("{A_BUTTON}下一个"); // Unused
#else
    _("{A_BUTTON}NEXT");                 // Unused
#endif

ALIGNED(4)
const u8 gText_NextBack[] =
#ifdef CHINESE
    _("{A_BUTTON}下一个{B_BUTTON}返回"); // Unused
#else
    _("{A_BUTTON}NEXT {B_BUTTON}BACK");  // Unused
#endif

ALIGNED(4)
const u8 gText_PickNextCancel[] =
#ifdef CHINESE
    _("{DPAD_UPDOWN}选取{A_BUTTON}下一个{B_BUTTON}取消"); //TODO
#else
    _("{DPAD_UPDOWN}PICK {A_BUTTON}NEXT {B_BUTTON}CANCEL");
#endif

ALIGNED(4)
const u8 gText_PickCancel[] =
#ifdef CHINESE
    _("{DPAD_UPDOWN}选取{A_BUTTON}{B_BUTTON}取消"); //TODO
#else
    _("{DPAD_UPDOWN}PICK {A_BUTTON}{B_BUTTON}CANCEL");
#endif

ALIGNED(4)
const u8 gText_AButtonExit[] =
#ifdef CHINESE
    _("{A_BUTTON}退出");
#else
    _("{A_BUTTON}EXIT");
#endif

const u8 gText_BirchBoy[] =
#ifdef CHINESE
    _("男孩");
#else
    _("BOY");
#endif

const u8 gText_BirchGirl[] =
#ifdef CHINESE
    _("女孩");
#else
    _("GIRL");
#endif

const u8 gText_DefaultNameStu[] =
#ifdef CHINESE
    _("安房");
#else
    _("STU");
#endif

const u8 gText_DefaultNameMilton[] =
#ifdef CHINESE
    _("上野");
#else
    _("MILTON");
#endif

const u8 gText_DefaultNameTom[] =
#ifdef CHINESE
    _("常陆");
#else
    _("TOM");
#endif

const u8 gText_DefaultNameKenny[] =
#ifdef CHINESE
    _("羽前");
#else
    _("KENNY");
#endif

const u8 gText_DefaultNameReid[] =
#ifdef CHINESE
    _("岩代");
#else
    _("REID");
#endif

const u8 gText_DefaultNameJude[] =
#ifdef CHINESE
    _("伊豆");
#else
    _("JUDE");
#endif

const u8 gText_DefaultNameJaxson[] =
#ifdef CHINESE
    _("尾张");
#else
    _("JAXSON");
#endif

const u8 gText_DefaultNameEaston[] =
#ifdef CHINESE
    _("美浓");
#else
    _("EASTON");
#endif

const u8 gText_DefaultNameWalker[] =
#ifdef CHINESE
    _("日向");
#else
    _("WALKER");
#endif

const u8 gText_DefaultNameTeru[] =
#ifdef CHINESE
    _("越后");
#else
    _("TERU");
#endif

const u8 gText_DefaultNameJohnny[] =
#ifdef CHINESE
    _("加贺");
#else
    _("JOHNNY");
#endif

const u8 gText_DefaultNameBrett[] =
#ifdef CHINESE
    _("若狭");
#else
    _("BRETT");
#endif

const u8 gText_DefaultNameSeth[] =
#ifdef CHINESE
    _("近江");
#else
    _("SETH");
#endif

const u8 gText_DefaultNameTerry[] =
#ifdef CHINESE
    _("周防");
#else
    _("TERRY");
#endif

const u8 gText_DefaultNameCasey[] =
#ifdef CHINESE
    _("花筏");
#else
    _("CASEY");
#endif

const u8 gText_DefaultNameDarren[] =
#ifdef CHINESE
    _("时雨");
#else
    _("DARREN");
#endif

const u8 gText_DefaultNameLandon[] =
#ifdef CHINESE
    _("樱舍");
#else
    _("LANDON");
#endif

const u8 gText_DefaultNameCollin[] =
#ifdef CHINESE
    _("夕立");
#else
    _("COLLIN");
#endif

const u8 gText_DefaultNameStanley[] =
#ifdef CHINESE
    _("冬萌");
#else
    _("STANLEY");
#endif

const u8 gText_DefaultNameQuincy[] =
#ifdef CHINESE
    _("花信");
#else
    _("QUINCY");
#endif

const u8 gText_DefaultNameKimmy[] =
#ifdef CHINESE
    _("雪洞");
#else
    _("KIMMY");
#endif

const u8 gText_DefaultNameTiara[] =
#ifdef CHINESE
    _("潮遗");
#else
    _("TIARA");
#endif

const u8 gText_DefaultNameBella[] =
#ifdef CHINESE
    _("萤钓");
#else
    _("BELLA");
#endif

const u8 gText_DefaultNameJayla[] =
#ifdef CHINESE
    _("樱明");
#else
    _("JAYLA");
#endif

const u8 gText_DefaultNameAllie[] =
#ifdef CHINESE
    _("音砂");
#else
    _("ALLIE");
#endif

const u8 gText_DefaultNameLianna[] =
#ifdef CHINESE
    _("?藤");
#else
    _("LIANNA");
#endif

const u8 gText_DefaultNameSara[] =
#ifdef CHINESE
    _("挽雨");
#else
    _("SARA");
#endif

const u8 gText_DefaultNameMonica[] =
#ifdef CHINESE
    _("茜空");
#else
    _("MONICA");
#endif

const u8 gText_DefaultNameCamila[] =
#ifdef CHINESE
    _("木漏");
#else
    _("CAMILA");
#endif

const u8 gText_DefaultNameAubree[] =
#ifdef CHINESE
    _("春告");
#else
    _("AUBREE");
#endif

const u8 gText_DefaultNameRuthie[] =
#ifdef CHINESE
    _("风薰");
#else
    _("RUTHIE");
#endif

const u8 gText_DefaultNameHazel[] =
#ifdef CHINESE
    _("遥焰");
#else
    _("HAZEL");
#endif

const u8 gText_DefaultNameNadine[] =
#ifdef CHINESE
    _("阳炎");
#else
    _("NADINE");
#endif

const u8 gText_DefaultNameTanja[] =
#ifdef CHINESE
    _("雪风");
#else
    _("TANJA");
#endif

const u8 gText_DefaultNameYasmin[] =
#ifdef CHINESE
    _("泪云");
#else
    _("YASMIN");
#endif

const u8 gText_DefaultNameNicola[] =
#ifdef CHINESE
    _("枫握");
#else
    _("NICOLA");
#endif

const u8 gText_DefaultNameLillie[] =
#ifdef CHINESE
    _("花立");
#else
    _("LILLIE");
#endif

const u8 gText_DefaultNameTerra[] =
#ifdef CHINESE
    _("蝉铃");
#else
    _("TERRA");
#endif

const u8 gText_DefaultNameLucy[] =
#ifdef CHINESE
    _("泡沫");
#else
    _("LUCY");
#endif

const u8 gText_DefaultNameHalie[] =
#ifdef CHINESE
    _("泪云");
#else
    _("HALIE");
#endif

const u8 gText_ThisIsAPokemon[] =
#ifdef CHINESE
    _("这就是我们叫做宝可梦的生物。”{PAUSE 96}\p");
#else
    _("This is what we call a “POKéMON.”{PAUSE 96}\p");
#endif

const u8 gText_5MarksPokemon[] =
#ifdef CHINESE
    _("?????宝可梦");
#else
    _("????? POKéMON");
#endif

const u8 gText_UnkHeight[] =
#ifdef CHINESE
    _("{CLEAR_TO 0x0C}??'??”");
#else
    _("{CLEAR_TO 0x0C}??'??”");
#endif

const u8 gText_UnkWeight[] =
#ifdef CHINESE
    _("????.?公斤");
#else
    _("????.? lbs.");
#endif

const u8 gText_EmptyPkmnCategory[] =
#ifdef CHINESE
    _("                      宝可梦"); // Unused
#else
    _("                      POKéMON"); // Unused
#endif

const u8 gText_EmptyHeight[] =
#ifdef CHINESE
    _("{CLEAR_TO 0x0C}    '    ”"); // Unused
#else
    _("{CLEAR_TO 0x0C}    '    ”");     // Unused
#endif

const u8 gText_EmptyWeight[] =
#ifdef CHINESE
    _("        .  公斤"); // Unused
#else
    _("       .   lbs.");               // Unused
#endif

const u8 gText_EmptyPokedexInfo1[] = _("");

const u8 gText_CryOf[] =
#ifdef CHINESE
    _("的叫声");
#else
    _("CRY OF");
#endif

const u8 gText_EmptyPokedexInfo2[] = _("");

const u8 gText_SizeComparedTo[] =
#ifdef CHINESE
    _("体型相较于");
#else
    _("SIZE COMPARED TO ");
#endif

const u8 gText_PokedexRegistration[] =
#ifdef CHINESE
    _("宝可梦登录完毕。");
#else
    _("POKéDEX registration completed.");
#endif

const u8 gText_HTHeight[] =
#ifdef CHINESE
    _("高");
#else
    _("HT");
#endif

const u8 gText_WTWeight[] =
#ifdef CHINESE
    _("重");
#else
    _("WT");
#endif

const u8 gText_SearchingPleaseWait[] =
#ifdef CHINESE
    _("查找中…\n请稍后。");
#else
    _("Searching…\nPlease wait.");
#endif

const u8 gText_SearchCompleted[] =
#ifdef CHINESE
    _("查找完毕。");
#else
    _("Search completed.");
#endif

const u8 gText_NoMatchingPkmnWereFound[] =
#ifdef CHINESE
    _("没有发现匹配的宝可梦。");
#else
    _("No matching POKéMON were found.");
#endif

const u8 gText_SearchForPkmnBasedOnParameters[] =
#ifdef CHINESE
    _("按特征查找宝可梦。");
#else
    _("Search for POKéMON based on\nselected parameters.");
#endif

const u8 gText_SwitchPokedexListings[] =
#ifdef CHINESE
    _("切换宝可梦列表。");
#else
    _("Switch POKéDEX listings.");
#endif

const u8 gText_ReturnToPokedex[] =
#ifdef CHINESE
    _("返回宝可梦图鉴。");
#else
    _("Return to the POKéDEX.");
#endif

const u8 gText_SelectPokedexMode[] =
#ifdef CHINESE
    _("选择宝可梦图鉴模式。");
#else
    _("Select the POKéDEX mode.");
#endif

const u8 gText_SelectPokedexListingMode[] =
#ifdef CHINESE
    _("选择宝可梦图鉴列表模式。");
#else
    _("Select the POKéDEX listing mode.");
#endif

const u8 gText_ListByFirstLetter[] =
#ifdef CHINESE
    _("按首字母排列。\n仅见过的宝可梦。");
#else
    _("List by the first letter in the name.\nSpotted POKéMON only.");
#endif

const u8 gText_ListByBodyColor[] =
#ifdef CHINESE
    _("按身体颜色排列。\n仅见过的宝可梦。");
#else
    _("List by body color.\nSpotted POKéMON only.");
#endif

const u8 gText_ListByType[] =
#ifdef CHINESE
    _("按类型排列。\n仅已拥有的宝可梦。");
#else
    _("List by type.\nOwned POKéMON only.");
#endif

const u8 gText_ExecuteSearchSwitch[] =
#ifdef CHINESE
    _("执行搜索/切换。");
#else
    _("Execute search/switch.");
#endif

const u8 gText_DexHoennTitle[] =
#ifdef CHINESE
    _("丰缘图鉴");
#else
    _("HOENN DEX");
#endif

const u8 gText_DexNatTitle[] =
#ifdef CHINESE
    _("全国图鉴");
#else
    _("NATIONAL DEX");
#endif

const u8 gText_DexSortNumericalTitle[] =
#ifdef CHINESE
    _("序号模式");
#else
    _("NUMERICAL MODE");
#endif

const u8 gText_DexSortAtoZTitle[] =
#ifdef CHINESE
    _("首字母顺序模式");
#else
    _("A TO Z MODE");
#endif

const u8 gText_DexSortHeaviestTitle[] =
#ifdef CHINESE
    _("优先最重");
#else
    _("HEAVIEST MODE");
#endif

const u8 gText_DexSortLightestTitle[] =
#ifdef CHINESE
    _("优先最轻");
#else
    _("LIGHTEST MODE");
#endif

const u8 gText_DexSortTallestTitle[] =
#ifdef CHINESE
    _("优先最高");
#else
    _("TALLEST MODE");
#endif

const u8 gText_DexSortSmallestTitle[] =
#ifdef CHINESE
    _("优先最小");
#else
    _("SMALLEST MODE");
#endif

const u8 gText_DexSearchAlphaABC[] = _("ABC");
const u8 gText_DexSearchAlphaDEF[] = _("DEF");
const u8 gText_DexSearchAlphaGHI[] = _("GHI");
const u8 gText_DexSearchAlphaJKL[] = _("JKL");
const u8 gText_DexSearchAlphaMNO[] = _("MNO");
const u8 gText_DexSearchAlphaPQR[] = _("PQR");
const u8 gText_DexSearchAlphaSTU[] = _("STU");
const u8 gText_DexSearchAlphaVWX[] = _("VWX");
const u8 gText_DexSearchAlphaYZ[] = _("YZ");

const u8 gText_DexSearchColorRed[] =
#ifdef CHINESE
    _("红色");
#else
    _("RED");
#endif

const u8 gText_DexSearchColorBlue[] =
#ifdef CHINESE
    _("蓝色");
#else
    _("BLUE");
#endif

const u8 gText_DexSearchColorYellow[] =
#ifdef CHINESE
    _("黄色");
#else
    _("YELLOW");
#endif

const u8 gText_DexSearchColorGreen[] =
#ifdef CHINESE
    _("绿色");
#else
    _("GREEN");
#endif

const u8 gText_DexSearchColorBlack[] =
#ifdef CHINESE
    _("黑色");
#else
    _("BLACK");
#endif

const u8 gText_DexSearchColorBrown[] =
#ifdef CHINESE
    _("棕色");
#else
    _("BROWN");
#endif

const u8 gText_DexSearchColorPurple[] =
#ifdef CHINESE
    _("紫色");
#else
    _("PURPLE");
#endif

const u8 gText_DexSearchColorGray[] =
#ifdef CHINESE
    _("灰色");
#else
    _("GRAY");
#endif

const u8 gText_DexSearchColorWhite[] =
#ifdef CHINESE
    _("白色");
#else
    _("WHITE");
#endif

const u8 gText_DexSearchColorPink[] =
#ifdef CHINESE
    _("粉色");
#else
    _("PINK");
#endif

const u8 gText_DexHoennDescription[] =
#ifdef CHINESE
    _("丰缘地区图鉴");
#else
    _("HOENN region's POKéDEX");
#endif

const u8 gText_DexNatDescription[] =
#ifdef CHINESE
    _("全国高级图鉴");
#else
    _("National edition POKéDEX");
#endif

const u8 gText_DexSortNumericalDescription[] =
#ifdef CHINESE
    _("宝可梦依其序号排列。");
#else
    _("POKéMON are listed according to their\nnumber.");
#endif

const u8 gText_DexSortAtoZDescription[] =
#ifdef CHINESE
    _("宝可梦依其首字母排列。");
#else
    _("Spotted and owned POKéMON are listed\nalphabetically.");
#endif

const u8 gText_DexSortHeaviestDescription[] =
#ifdef CHINESE
    _("已拥有的宝可梦由重到轻排列。");
#else
    _("Owned POKéMON are listed from the\nheaviest to the lightest.");
#endif

const u8 gText_DexSortLightestDescription[] =
#ifdef CHINESE
    _("已拥有的宝可梦由轻到重排列。");
#else
    _("Owned POKéMON are listed from the\nlightest to the heaviest.");
#endif

const u8 gText_DexSortTallestDescription[] =
#ifdef CHINESE
    _("已拥有的宝可梦由高到矮排列。");
#else
    _("Owned POKéMON are listed from the\ntallest to the smallest.");
#endif

const u8 gText_DexSortSmallestDescription[] =
#ifdef CHINESE
    _("已拥有的宝可梦由矮到高排列。");
#else
    _("Owned POKéMON are listed from the\nsmallest to the tallest.");
#endif

const u8 gText_DexEmptyString[] = _("");

const u8 gText_DexSearchDontSpecify[] =
#ifdef CHINESE
    _("不指定。");
#else
    _("DON'T SPECIFY.");
#endif

const u8 gText_DexSearchTypeNone[] =
#ifdef CHINESE
    _("无");
#else
    _("NONE");
#endif

const u8 gText_SelectorArrow[] = _("▶");
const u8 gText_EmptySpace[] = _("");

const u8 gText_WelcomeToHOF[] =
#ifdef CHINESE
    _("欢迎登录荣誉殿堂！");
#else
    _("Welcome to the HALL OF FAME!");
#endif

const u8 gText_HOFDexRating[] =
#ifdef CHINESE
    _("目击宝可梦: {STR_VAR_1}只!\n已拥有宝可梦: {STR_VAR_2}只!\p小田卷博士的图鉴评价!\p 小田卷博士: 让我看看……\p");
#else
    _("Spotted POKéMON: {STR_VAR_1}!\nOwned POKéMON: {STR_VAR_2}!\pPROF. BIRCH's POKéDEX rating!\pPROF. BIRCH: Let's see…\p");
#endif

const u8 gText_HOFDexSaving[] =
#ifdef CHINESE
    _("保存中……\n请勿关闭电源。");
#else
    _("SAVING…\nDON'T TURN OFF THE POWER.");
#endif

const u8 gText_HOFCorrupted[] =
#ifdef CHINESE
    _("荣誉殿堂的数据损坏了。");
#else
    _("The HALL OF FAME data is corrupted.");
#endif

const u8 gText_HOFNumber[] =
#ifdef CHINESE
    _("名人堂 No. {STR_VAR_1}");
#else
    _("HALL OF FAME No. {STR_VAR_1}");
#endif

const u8 gText_LeagueChamp[] =
#ifdef CHINESE
    _("联盟冠军！\n恭喜！");
#else
    _("LEAGUE CHAMPION!\nCONGRATULATIONS!");
#endif

const u8 gText_Number[] =
#ifdef CHINESE
    _("No. ");
#else
    _("No. ");
#endif

const u8 gText_Level[] =
#ifdef CHINESE
    _("Lv. ");
#else
    _("Lv. ");
#endif

const u8 gText_IdNumberSlash[] =
#ifdef CHINESE
    _("IDNo. /");
#else
    _("IDNo. /"); // Unused
#endif

const u8 gText_Name[] =
#ifdef CHINESE
    _("名字");
#else
    _("NAME");
#endif

const u8 gText_IDNumber[] =
#ifdef CHINESE
    _("IDNo.");
#else
    _("IDNo.");
#endif

const u8 gText_BirchInTrouble[] =
#ifdef CHINESE
    _("小田卷博士麻烦了！\n快选一只宝可梦来救救他！");
#else
    _("PROF. BIRCH is in trouble!\nRelease a POKéMON and rescue him!");
#endif

const u8 gText_ConfirmStarterChoice[] =
#ifdef CHINESE
    _("就选这只宝可梦了？");
#else
    _("Do you choose this POKéMON?");
#endif

const u8 gText_Pokemon4[] =
#ifdef CHINESE
    _("宝可梦");
#else
    _("POKéMON"); // Unused
#endif

const u8 gText_FlyToWhere[] =
#ifdef CHINESE
    _("飞往哪里？");
#else
    _("FLY to where?");
#endif

const u8 gMenuText_Use[] =
#ifdef CHINESE
    _("使用");
#else
    _("USE");
#endif

const u8 gMenuText_Toss[] =
#ifdef CHINESE
    _("扔");
#else
    _("TOSS");
#endif

const u8 gMenuText_Register[] =
#ifdef CHINESE
    _("注册");
#else
    _("REGISTER");
#endif

const u8 gMenuText_Give[] =
#ifdef CHINESE
    _("交予");
#else
    _("GIVE");
#endif

const u8 gMenuText_CheckTag[] =
#ifdef CHINESE
    _("检查标签");
#else
    _("CHECK TAG");
#endif

const u8 gMenuText_Confirm[] =
#ifdef CHINESE
    _("确认");
#else
    _("CONFIRM");
#endif

const u8 gMenuText_Walk[] =
#ifdef CHINESE
    _("行走");
#else
    _("WALK");
#endif

const u8 gText_Cancel[] =
#ifdef CHINESE
    _("取消");
#else
    _("CANCEL");
#endif

const u8 gText_Cancel2[] =
#ifdef CHINESE
    _("取消");
#else
    _("CANCEL");
#endif

const u8 gMenuText_Show[] =
#ifdef CHINESE
    _("展示");
#else
    _("SHOW");
#endif

const u8 gText_EmptyString2[] = _("");

const u8 gText_Cancel7[] =
#ifdef CHINESE
    _("取消"); // Unused
#else
    _("CANCEL"); // Unused
#endif

const u8 gText_Item[] =
#ifdef CHINESE
    _("道具");
#else
    _("ITEM");
#endif

const u8 gText_Mail[] =
#ifdef CHINESE
    _("邮件");
#else
    _("MAIL");
#endif

const u8 gText_Take[] =
#ifdef CHINESE
    _("取出");
#else
    _("TAKE");
#endif

const u8 gText_Store[] =
#ifdef CHINESE
    _("存放");
#else
    _("STORE");
#endif

const u8 gMenuText_Check[] =
#ifdef CHINESE
    _("检查");
#else
    _("CHECK");
#endif

const u8 gText_None[] =
#ifdef CHINESE
    _("什么也没有");
#else
    _("NONE");
#endif

const u8 gMenuText_Deselect[] =
#ifdef CHINESE
    _("取消选中");
#else
    _("DESELECT");
#endif

const u8 gText_ThreeMarks[] =
#ifdef CHINESE
    _("???");
#else
    _("???");
#endif

const u8 gText_FiveMarks[] =
#ifdef CHINESE
    _("?????");
#else
    _("?????");
#endif

const u8 gText_Slash[] =
#ifdef CHINESE
    _("/");
#else
    _("/");
#endif

const u8 gText_OneDash[] =
#ifdef CHINESE
    _("-");
#else
    _("-");
#endif

const u8 gText_TwoDashes[] =
#ifdef CHINESE
    _("--");
#else
    _("--");
#endif

const u8 gText_ThreeDashes[] =
#ifdef CHINESE
    _("---");
#else
    _("---");
#endif

const u8 gText_MaleSymbol[] =
#ifdef CHINESE
    _("♂");
#else
    _("♂");
#endif

const u8 gText_FemaleSymbol[] =
#ifdef CHINESE
    _("♀");
#else
    _("♀");
#endif

const u8 gText_LevelSymbol[] =
#ifdef CHINESE
    _("{LV}");
#else
    _("{LV}");
#endif

const u8 gText_NumberClear01[] =
#ifdef CHINESE
    _("{NO}{CLEAR 0x01}");
#else
    _("{NO}{CLEAR 0x01}");
#endif

const u8 gText_PlusSymbol[] =
#ifdef CHINESE
    _("+"); // Unused
#else
    _("+");             // Unused
#endif

const u8 gText_RightArrow[] =
#ifdef CHINESE
    _("{RIGHT_ARROW}"); // Unused
#else
    _("{RIGHT_ARROW}"); // Unused
#endif

const u8 gText_IDNumber2[] =
#ifdef CHINESE
    _("{ID}{NO}");
#else
    _("{ID}{NO}");
#endif

const u8 gText_Space[] =
#ifdef CHINESE
    _(" ");
#else
    _("");
#endif

const u8 gText_SelectorArrow2[] =
#ifdef CHINESE
    _("▶");
#else
    _("▶");
#endif

const u8 gText_GoBackPrevMenu[] =
#ifdef CHINESE
    _("返回上级菜单。");
#else
    _("Go back to the\nprevious menu.");
#endif

const u8 gText_WhatWouldYouLike[] =
#ifdef CHINESE
    _("你想干啥？");
#else
    _("What would you like to do?");
#endif

const u8 gMenuText_Give2[] =
#ifdef CHINESE
    _("交予");
#else
    _("GIVE");
#endif

const u8 gText_xVar1[] =
#ifdef CHINESE
    _("×{STR_VAR_1}");
#else
    _("×{STR_VAR_1}");
#endif

const u8 gText_Berry2[] =
#ifdef CHINESE
    _(" 树果"); // Unused
#else
    _("BERRY"); // Unused
#endif

const u8 gText_Coins[] =
#ifdef CHINESE
    _("{STR_VAR_1}枚硬币");
#else
    _("{STR_VAR_1} COINS");
#endif

const u8 gText_CloseBag[] =
#ifdef CHINESE
    _("合上背包");
#else
    _("CLOSE BAG");
#endif

const u8 gText_Var1IsSelected[] =
#ifdef CHINESE
    _("{STR_VAR_1}已被选中。");
#else
    _("{STR_VAR_1} is\nselected.");
#endif

const u8 gText_CantWriteMail[] =
#ifdef CHINESE
    _("无法在此写邮件。");
#else
    _("You can't write\nMAIL here.");
#endif

const u8 gText_NoPokemon[] =
#ifdef CHINESE
    _("没有宝可梦。");
#else
    _("There is no\nPOKéMON.");
#endif

const u8 gText_MoveVar1Where[] =
#ifdef CHINESE
    _("把{STR_VAR_1}挪到哪儿?");
#else
    _("Move the\n{STR_VAR_1}\nwhere?");
#endif

const u8 gText_Var1CantBeHeld[] =
#ifdef CHINESE
    _("无法持有{STR_VAR_1}。");
#else
    _("The {STR_VAR_1} can't be held.");
#endif

const u8 gText_Var1CantBeHeldHere[] =
#ifdef CHINESE
    _("无法在此持有{STR_VAR_1}。");
#else
    _("The {STR_VAR_1} can't be held\nhere.");
#endif

const u8 gText_DepositHowManyVar1[] =
#ifdef CHINESE
    _("存入多少个{STR_VAR_1}？");
#else
    _("Deposit how many\n{STR_VAR_1}(s)?");
#endif

const u8 gText_DepositedVar2Var1s[] =
#ifdef CHINESE
    _("存入了{STR_VAR_2}\n{STR_VAR_1}(s)。");
#else
    _("Deposited {STR_VAR_2}\n{STR_VAR_1}(s).");
#endif

const u8 gText_NoRoomForItems[] =
#ifdef CHINESE
    _("存放道具了的空间不足。");
#else
    _("There's no room to\nstore items.");
#endif

const u8 gText_CantStoreImportantItems[] =
#ifdef CHINESE
    _("重要道具无法存进电脑！");
#else
    _("Important items\ncan't be stored in\nthe PC!");
#endif

const u8 gText_TooImportantToToss[] =
#ifdef CHINESE
    _("它很重要，无法丢弃。");
#else
    _("That's much too\nimportant to toss\nout!");
#endif

const u8 gText_TossHowManyVar1s[] =
#ifdef CHINESE
    _("丢弃多少个\n{STR_VAR_1}？");
#else
    _("Toss out how many\n{STR_VAR_1}(s)?");
#endif

const u8 gText_ThrewAwayVar2Var1s[] =
#ifdef CHINESE
    _("丢弃{STR_VAR_2}个\n{STR_VAR_1}。");
#else
    _("Threw away {STR_VAR_2}\n{STR_VAR_1}(s).");
#endif

const u8 gText_ConfirmTossItems[] =
#ifdef CHINESE
    _("是否丢弃{STR_VAR_2}个\n{STR_VAR_1}？");
#else
    _("Is it okay to\nthrow away {STR_VAR_2}\n{STR_VAR_1}(s)?");
#endif

const u8 gText_DadsAdvice[] =
#ifdef CHINESE
    _("父亲常说……\n每个东西在合适的地点和时候都有用！{PAUSE_UNTIL_PRESS}")
#else
    _("DAD's advice…\n{PLAYER}, there's a time and place for\leverything!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_CantDismountBike[] =
#ifdef CHINESE
    _("无法在此下车。{PAUSE_UNTIL_PRESS}");
#else
    _("You can't dismount your BIKE here.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_ItemFinderNearby[] =
#ifdef CHINESE
    _("哈？\n道具搜寻器有反应了！\p有什么道具就埋在这附近！{PAUSE_UNTIL_PRESS}");
#else
    _("Huh?\nThe ITEMFINDER's responding!\pThere's an item buried around here!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_ItemFinderOnTop[] =
#ifdef CHINESE
    _("啊!\n道具搜寻器在剧烈震动！{PAUSE_UNTIL_PRESS}");
#else
    _("Oh!\nThe ITEMFINDER's shaking wildly!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_ItemFinderNothing[] =
#ifdef CHINESE
    _("… … … …害!\n没有任何反应。{PAUSE_UNTIL_PRESS}");
#else
    _("… … … …Nope!\nThere's no response.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_CoinCase[] =
#ifdef CHINESE
    _("你的硬币数：\n{STR_VAR_1}{PAUSE_UNTIL_PRESS}");
#else
    _("Your COINS:\n{STR_VAR_1}{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_BootedUpTM[] =
#ifdef CHINESE
    _("驱动了招式学习器。"); //TODO 汉化
#else
    _("Booted up a TM.");
#endif

const u8 gText_BootedUpHM[] =
#ifdef CHINESE
    _("驱动了秘传学习器。"); //TODO 汉化
#else
    _("Booted up an HM.");
#endif

const u8 gText_TMHMContainedVar1[] =
#ifdef CHINESE
    _("内含{STR_VAR_1}。\p把{STR_VAR_1}教给某只宝可梦吗？");
#else
    _("It contained\n{STR_VAR_1}.\pTeach {STR_VAR_1}\nto a POKéMON?");
#endif

const u8 gText_PlayerUsedVar2[] =
#ifdef CHINESE
    _("{PLAYER}使用了\n{STR_VAR_2}。{PAUSE_UNTIL_PRESS}");
#else
    _("{PLAYER} used the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_RepelEffectsLingered[] =
#ifdef CHINESE
    _("先前的喷雾效果还在。{PAUSE_UNTIL_PRESS}");
#else
    _("But the effects of a REPEL\nlingered from earlier.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_UsedVar2WildLured[] =
#ifdef CHINESE
    _("{PLAYER}使用了\n{STR_VAR_2}。\p野生的宝可梦会被驱赶走。{PAUSE_UNTIL_PRESS}");
#else
    _("{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be lured.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_UsedVar2WildRepelled[] =
#ifdef CHINESE
    _("{PLAYER}使用了\n{STR_VAR_2}。\p野生的宝可梦会被驱赶走。{PAUSE_UNTIL_PRESS}");
#else
    _("{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be repelled.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_BoxFull[] =
#ifdef CHINESE
    _("这个盒子满了。.{PAUSE_UNTIL_PRESS}");
#else
    _("The BOX is full.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PowderQty[] =
#ifdef CHINESE
    _("药粉量: {STR_VAR_1}{PAUSE_UNTIL_PRESS}");
#else
    _("POWDER QTY: {STR_VAR_1}{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_TheField[] =
#ifdef CHINESE
    _("原野");
#else
    _("the field");
#endif

const u8 gText_TheBattle[] =
#ifdef CHINESE
    _("战斗");
#else
    _("the battle");
#endif

const u8 gText_ThePokemonList[] =
#ifdef CHINESE
    _("精灵列表");
#else
    _("the POKéMON LIST");
#endif

const u8 gText_TheShop[] =
#ifdef CHINESE
    _("商店");
#else
    _("the shop");
#endif

const u8 gText_ThePC[] =
#ifdef CHINESE
    _("精灵中心");
#else
    _("the PC");
#endif

const u8 *const gBagMenu_ReturnToStrings[] =
    {
        [ITEMMENULOCATION_FIELD] = gText_TheField,
        [ITEMMENULOCATION_BATTLE] = gText_TheBattle,
        [ITEMMENULOCATION_PARTY] = gText_ThePokemonList,
        [ITEMMENULOCATION_SHOP] = gText_TheShop,
        [ITEMMENULOCATION_BERRY_TREE] = gText_TheField,
        [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] = gText_TheField,
        [ITEMMENULOCATION_ITEMPC] = gText_ThePC,
        [ITEMMENULOCATION_FAVOR_LADY] = gText_TheField,
        [ITEMMENULOCATION_QUIZ_LADY] = gText_TheField,
        [ITEMMENULOCATION_APPRENTICE] = gText_TheField,
        [ITEMMENULOCATION_WALLY] = gText_TheBattle,
        [ITEMMENULOCATION_PCBOX] = gText_ThePC};

const u8 *const gPyramidBagMenu_ReturnToStrings[] =
    {
        [PYRAMIDBAG_LOC_FIELD] = gText_TheField,
        [PYRAMIDBAG_LOC_BATTLE] = gText_TheBattle,
        [PYRAMIDBAG_LOC_PARTY] = gText_ThePokemonList,
        [PYRAMIDBAG_LOC_CHOOSE_TOSS] = gText_TheField};

const u8 gText_ReturnToVar1[] =
#ifdef CHINESE
    _("返回至\n{STR_VAR_1}.");
#else
    _("Return to\n{STR_VAR_1}.");
#endif

const u8 gText_ItemsPocket[] =
#ifdef CHINESE
    _("道具");
#else
    _("ITEMS");
#endif

const u8 gText_PokeBallsPocket[] =
#ifdef CHINESE
    _("精灵球");
#else
    _("POKé BALLS");
#endif

const u8 gText_TMHMPocket[] =
#ifdef CHINESE
    _("招式机器");
#else
    _("TMs & HMs");
#endif

const u8 gText_BerriesPocket[] =
#ifdef CHINESE
    _("树果");
#else
    _("BERRIES");
#endif

const u8 gText_KeyItemsPocket[] =
#ifdef CHINESE
    _("重要道具");
#else
    _("KEY ITEMS");
#endif

const u8 *const gPocketNamesStringsTable[] =
    {
        [ITEMS_POCKET] = gText_ItemsPocket,
        [BALLS_POCKET] = gText_PokeBallsPocket,
        [TMHM_POCKET] = gText_TMHMPocket,
        [BERRIES_POCKET] = gText_BerriesPocket,
        [KEYITEMS_POCKET] = gText_KeyItemsPocket};

const u8 gText_NumberItem_TMBerry[] =
#ifdef CHINESE
    _("{NO}{STR_VAR_1}{CLEAR 0x07}{STR_VAR_2}");
#else
    _("{NO}{STR_VAR_1}{CLEAR 0x07}{STR_VAR_2}");
#endif

const u8 gText_NumberItem_HM[] =
#ifdef CHINESE
    _("{CLEAR_TO 0x11}{STR_VAR_1}{CLEAR 0x05}{STR_VAR_2}");
#else
    _("{CLEAR_TO 0x11}{STR_VAR_1}{CLEAR 0x05}{STR_VAR_2}");
#endif

const u8 gText_SizeSlash[] =
#ifdef CHINESE
    _("尺寸/");
#else
    _("SIZE /");
#endif

const u8 gText_FirmSlash[] =
#ifdef CHINESE
    _("硬度/");
#else
    _("FIRM /");
#endif

const u8 gText_Var1DotVar2[] =
#ifdef CHINESE
    _("{STR_VAR_1}.{STR_VAR_2}”");
#else
    _("{STR_VAR_1}.{STR_VAR_2}”");
#endif

// Berry firmness strings
const u8 gBerryFirmnessString_VerySoft[] =
#ifdef CHINESE
    _("软塌塌");
#else
    _("Very soft");
#endif

const u8 gBerryFirmnessString_Soft[] =
#ifdef CHINESE
    _("软");
#else
    _("Soft");
#endif

const u8 gBerryFirmnessString_Hard[] =
#ifdef CHINESE
    _("硬");
#else
    _("Hard");
#endif

const u8 gBerryFirmnessString_VeryHard[] =
#ifdef CHINESE
    _("硬邦邦");
#else
    _("Very hard");
#endif

const u8 gBerryFirmnessString_SuperHard[] =
#ifdef CHINESE
    _("刚硬");
#else
    _("Super hard");
#endif

const u8 gText_NumberVar1Var2[] =
#ifdef CHINESE
    _("{NO}{STR_VAR_1} {STR_VAR_2}");
#else
    _("{NO}{STR_VAR_1} {STR_VAR_2}");
#endif

const u8 gText_BerryTag[] =
#ifdef CHINESE
    _("树果标签");
#else
    _("BERRY TAG");
#endif

const u8 gText_RedPokeblock[] =
#ifdef CHINESE
    _("红色的{POKEBLOCK}");
#else
    _("RED {POKEBLOCK}");
#endif

const u8 gText_BluePokeblock[] =
#ifdef CHINESE
    _("蓝色的{POKEBLOCK}");
#else
    _("BLUE {POKEBLOCK}");
#endif

const u8 gText_PinkPokeblock[] =
#ifdef CHINESE
    _("粉色的{POKEBLOCK}");
#else
    _("PINK {POKEBLOCK}");
#endif

const u8 gText_GreenPokeblock[] =
#ifdef CHINESE
    _("绿色的{POKEBLOCK}");
#else
    _("GREEN {POKEBLOCK}");
#endif

const u8 gText_YellowPokeblock[] =
#ifdef CHINESE
    _("黄色的{POKEBLOCK}");
#else
    _("YELLOW {POKEBLOCK}");
#endif

const u8 gText_PurplePokeblock[] =
#ifdef CHINESE
    _("紫色的{POKEBLOCK}");
#else
    _("PURPLE {POKEBLOCK}");
#endif

const u8 gText_IndigoPokeblock[] =
#ifdef CHINESE
    _("靛色的{POKEBLOCK}");
#else
    _("INDIGO {POKEBLOCK}");
#endif

const u8 gText_BrownPokeblock[] =
#ifdef CHINESE
    _("棕色的{POKEBLOCK}");
#else
    _("BROWN {POKEBLOCK}");
#endif

const u8 gText_LiteBluePokeblock[] =
#ifdef CHINESE
    _("浅蓝色的{POKEBLOCK}");
#else
    _("LITEBLUE {POKEBLOCK}");
#endif

const u8 gText_OlivePokeblock[] =
#ifdef CHINESE
    _("橄榄色的{POKEBLOCK}");
#else
    _("OLIVE {POKEBLOCK}");
#endif

const u8 gText_GrayPokeblock[] =
#ifdef CHINESE
    _("灰色的{POKEBLOCK}");
#else
    _("GRAY {POKEBLOCK}");
#endif

const u8 gText_BlackPokeblock[] =
#ifdef CHINESE
    _("黑色的{POKEBLOCK}");
#else
    _("BLACK {POKEBLOCK}");
#endif

const u8 gText_WhitePokeblock[] =
#ifdef CHINESE
    _("白色的{POKEBLOCK}");
#else
    _("WHITE {POKEBLOCK}");
#endif

const u8 gText_GoldPokeblock[] =
#ifdef CHINESE
    _("金色的{POKEBLOCK}");
#else
    _("GOLD {POKEBLOCK}");
#endif

const u8 gText_Spicy[] =
#ifdef CHINESE
    _("辣");
#else
    _("SPICY");
#endif

const u8 gText_Dry[] =
#ifdef CHINESE
    _("涩");
#else
    _("DRY");
#endif

const u8 gText_Sweet[] =
#ifdef CHINESE
    _("甜");
#else
    _("SWEET");
#endif

const u8 gText_Bitter[] =
#ifdef CHINESE
    _("苦");
#else
    _("BITTER");
#endif

const u8 gText_Sour[] =
#ifdef CHINESE
    _("酸");
#else
    _("SOUR");
#endif

const u8 gText_Tasty[] =
#ifdef CHINESE
    _("口味"); // Unused
#else
    _("TASTY"); // Unused
#endif

const u8 gText_Feel[] =
#ifdef CHINESE
    _("感觉"); // Unused
#else
    _("FEEL");  // Unused
#endif

const u8 gText_StowCase[] =
#ifdef CHINESE
    _("Stow CASE."); //TODO 汉化
#else
    _("Stow CASE.");
#endif

const u8 gText_LvVar1[] =
#ifdef CHINESE
    _("{LV}{STR_VAR_1}");
#else
    _("{LV}{STR_VAR_1}");
#endif

const u8 gText_ThrowAwayVar1[] =
#ifdef CHINESE
    _("丢弃这个\n{STR_VAR_1}吗？");
#else
    _("Throw away this\n{STR_VAR_1}?");
#endif

const u8 gText_Var1ThrownAway[] =
#ifdef CHINESE
    _("那个{STR_VAR_1}\n已经丢弃了 。")
#else
    _("The {STR_VAR_1}\nwas thrown away.");
#endif

const u8 gText_Var1AteTheVar2[] =
#ifdef CHINESE
    _("{STR_VAR_1}吃掉了\n{STR_VAR_2}。{PAUSE_UNTIL_PRESS}");
#else
    _("{STR_VAR_1} ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_Var1HappilyAteVar2[] =
#ifdef CHINESE
    _("{STR_VAR_1}快乐地吃掉了\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#else
    _("{STR_VAR_1} happily ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_Var1DisdainfullyAteVar2[] =
#ifdef CHINESE
    _("{STR_VAR_1}嫌弃地吃掉了\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#else
    _("{STR_VAR_1} disdainfully ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_ShopBuy[] =
#ifdef CHINESE
    _("购买");
#else
    _("BUY");
#endif

const u8 gText_ShopSell[] =
#ifdef CHINESE
    _("出售");
#else
    _("SELL");
#endif

const u8 gText_ShopQuit[] =
#ifdef CHINESE
    _("退出");
#else
    _("QUIT");
#endif

const u8 gText_InBagVar1[] =
#ifdef CHINESE
    _("背包内：{STR_VAR_1}个");
#else
    _("IN BAG: {STR_VAR_1}");
#endif

const u8 gText_QuitShopping[] =
#ifdef CHINESE
    _("退出购物。");
#else
    _("Quit shopping.");
#endif

const u8 gText_Var1CertainlyHowMany[] =
#ifdef CHINESE
    _("{STR_VAR_1}？当然可以。\n您想要多少个？");
#else
    _("{STR_VAR_1}? Certainly.\nHow many would you like?");
#endif

const u8 gText_Var1CertainlyHowMany2[] =
#ifdef CHINESE
    _("{STR_VAR_1}？当然可以。\n您想要多少个？");
#else
    _("{STR_VAR_1}? Certainly.\nHow many would you like?");
#endif

const u8 gText_Var1AndYouWantedVar2[] =
#ifdef CHINESE
    _("{STR_VAR_1}？还有{STR_VAR_2}？\n那总计{STR_VAR_3}元。");
#else
    _("{STR_VAR_1}? And you wanted {STR_VAR_2}?\nThat will be ¥{STR_VAR_3}.");
#endif

const u8 gText_Var1IsItThatllBeVar2[] =
#ifdef CHINESE
    _("{STR_VAR_1}，是这个吗？\n一共{STR_VAR_2}元。请问要购买吗？");
#else
    _("{STR_VAR_1}, is it?\nThat'll be ¥{STR_VAR_2}. Do you want it?");
#endif

const u8 gText_YouWantedVar1ThatllBeVar2[] =
#ifdef CHINESE
    _("您想要{STR_VAR_1}？\n一共{STR_VAR_2}元。请问要购买吗？");
#else
    _("You wanted {STR_VAR_1}?\nThat'll be ¥{STR_VAR_2}. Will that be okay?");
#endif

const u8 gText_HereYouGoThankYou[] =
#ifdef CHINESE
    _("这是您的货物！\n感谢惠顾。");
#else
    _("Here you go!\nThank you very much.");
#endif

const u8 gText_ThankYouIllSendItHome[] =
#ifdef CHINESE
    _("感谢惠顾！\n我会把您的货物发送至您的个人电脑的。");
#else
    _("Thank you!\nI'll send it to your home PC.");
#endif

const u8 gText_ThanksIllSendItHome[] =
#ifdef CHINESE
    _("购物愉快！\n我会把您的货物发送至您的个人电脑的。");
#else
    _("Thanks!\nI'll send it to your PC at home.");
#endif

const u8 gText_YouDontHaveMoney[] =
#ifdef CHINESE
    _("您的余额不足。{PAUSE_UNTIL_PRESS}");
#else
    _("You don't have enough money.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_NoMoreRoomForThis[] =
#ifdef CHINESE
    _("你没有库存放这个了。{PAUSE_UNTIL_PRESS}");
#else
    _("You have no more room for this\nitem.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_SpaceForVar1Full[] =
#ifdef CHINESE
    _("{STR_VAR_1}已经满仓了！ {PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("The space for {STR_VAR_1} is full.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_AnythingElseICanHelp[] =
#ifdef CHINESE
    _("还有什么可以帮助你的吗？"); //TODO 汉化
#else
    _("Is there anything else I can help\nyou with?");
#endif

const u8 gText_CanIHelpWithAnythingElse[] =
#ifdef CHINESE
    _("我还能再帮你些什么吗？"); //TODO 汉化
#else
    _("Can I help you with anything else?");
#endif

const u8 gText_ThrowInPremierBall[] =
#ifdef CHINESE
    _("赠品！一个纪念球！{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("I'll throw in a PREMIER BALL, too.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_CantBuyKeyItem[] =
#ifdef CHINESE
    _("{STR_VAR_2}? 你自己觉得这玩意能卖？{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_2}? Oh, no.\nI can't buy that.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_HowManyToSell[] =
#ifdef CHINESE
    _("{STR_VAR_2}?\n你卖多少个？"); //TODO 汉化
#else
    _("{STR_VAR_2}?\nHow many would you like to sell?");
#endif

const u8 gText_ICanPayVar1[] =
#ifdef CHINESE
    _("我开价{STR_VAR_1}元。\n成交吗？"); //TODO 汉化
#else
    _("I can pay ¥{STR_VAR_1}.\nWould that be okay?");
#endif

const u8 gText_TurnedOverVar1ForVar2[] =
#ifdef CHINESE
    _("Turned over the {STR_VAR_2}\nand received ¥{STR_VAR_1}."); //TODO 汉化不懂
#else
    _("Turned over the {STR_VAR_2}\nand received ¥{STR_VAR_1}.");
#endif

const u8 gText_PokedollarVar1[] =
#ifdef CHINESE
    _("{STR_VAR_1}元"); //TODO 汉化
#else
    _("¥{STR_VAR_1}");
#endif

const u8 gText_Shift[] =
#ifdef CHINESE
    _("SHIFT"); //TODO 汉化
#else
    _("SHIFT");
#endif

const u8 gText_SendOut[] =
#ifdef CHINESE
    _("发送"); //TODO 汉化
#else
    _("SEND OUT");
#endif

const u8 gText_Switch2[] =
#ifdef CHINESE
    _("切换"); //TODO 汉化
#else
    _("SWITCH");
#endif

const u8 gText_Summary5[] =
#ifdef CHINESE
    _("SUMMARY"); //TODO 汉化不懂
#else
    _("SUMMARY");
#endif

const u8 gText_Moves[] =
#ifdef CHINESE
    _("动作"); // Unused //TODO 汉化
#else
    _("MOVES"); // Unused
#endif

const u8 gText_Enter[] =
#ifdef CHINESE
    _("ENTER"); //TODO 汉化不懂
#else
    _("ENTER");
#endif

const u8 gText_NoEntry[] =
#ifdef CHINESE
    _("NO ENTRY"); //TODO 汉化不懂
#else
    _("NO ENTRY");
#endif

const u8 gText_Take2[] =
#ifdef CHINESE
    _("TAKE"); //TODO 汉化不懂
#else
    _("TAKE");
#endif

const u8 gText_Read2[] =
#ifdef CHINESE
    _("阅读"); //TODO 汉化
#else
    _("READ");
#endif

const u8 gText_Trade4[] =
#ifdef CHINESE
    _("TRADE"); //TODO 汉化不懂
#else
    _("TRADE");
#endif

const u8 gText_HP3[] =
#ifdef CHINESE
    _("体力"); //TODO 汉化
#else
    _("HP");
#endif

const u8 gText_SpAtk3[] =
#ifdef CHINESE
    _("特攻"); //TODO 汉化
#else
    _("SP. ATK");
#endif

const u8 gText_SpDef3[] =
#ifdef CHINESE
    _("特防"); //TODO 汉化
#else
    _("SP. DEF");
#endif

const u8 gText_WontHaveEffect[] =
#ifdef CHINESE
    _("它不会有任何效果。{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("It won't have any effect.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_CantBeUsedOnPkmn[] =
#ifdef CHINESE
    _("这不能用于那只宝可梦。{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("This can't be used on\nthat POKéMON.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnCantSwitchOut[] =
#ifdef CHINESE
    _("{STR_VAR_1} 不能关闭!{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} can't be switched\nout!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnAlreadyInBattle[] =
#ifdef CHINESE
    _("{STR_VAR_1} 已经在战斗中了!{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} is already\nin battle!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnAlreadySelected[] =
#ifdef CHINESE
    _("{STR_VAR_1} 已经被选中了。{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} has already been\nselected.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnHasNoEnergy[] =
#ifdef CHINESE
    _("{STR_VAR_1} 没有剩余的体力战斗了！{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} has no energy\nleft to battle!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_CantSwitchWithAlly[] =
#ifdef CHINESE
    _("你不能拿你的宝可梦去换{STR_VAR_1}的！{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("You can't switch {STR_VAR_1}'s\nPOKéMON with one of yours!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_EggCantBattle[] =
#ifdef CHINESE
    _("蛋不能战斗！{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("An EGG can't battle!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_CantUseUntilNewBadge[] =
#ifdef CHINESE
    _("这个直到你获得新的徽章才能使用！{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("This can't be used until a new\nBADGE is obtained.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_NoMoreThanVar1Pkmn[] =
#ifdef CHINESE
    _("至多只能进入 {STR_VAR_1} 只宝可梦。{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("No more than {STR_VAR_1} POKéMON\nmay enter.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_SendMailToPC[] =
#ifdef CHINESE
    _("Send the removed MAIL to\nyour PC?"); //TODO 汉化
#else
    _("Send the removed MAIL to\nyour PC?");
#endif

const u8 gText_MailSentToPC[] =
#ifdef CHINESE
    _("The MAIL was sent to your PC.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("The MAIL was sent to your PC.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PCMailboxFull[] =
#ifdef CHINESE
    _("Your PC's MAILBOX is full.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("Your PC's MAILBOX is full.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_MailMessageWillBeLost[] =
#ifdef CHINESE
    _("If the MAIL is removed, the\nmessage will be lost. Okay?"); //TODO 汉化
#else
    _("If the MAIL is removed, the\nmessage will be lost. Okay?");
#endif

const u8 gText_RemoveMailBeforeItem[] =
#ifdef CHINESE
    _("MAIL must be removed before\nholding an item.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("MAIL must be removed before\nholding an item.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnWasGivenItem[] =
#ifdef CHINESE
    _("{STR_VAR_1} was given the\n{STR_VAR_2} to hold.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} was given the\n{STR_VAR_2} to hold.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnAlreadyHoldingItemSwitch[] =
#ifdef CHINESE
    _("{STR_VAR_1} is already holding\none {STR_VAR_2}.\pWould you like to switch the\ntwo items?"); //TODO 汉化
#else
    _("{STR_VAR_1} is already holding\none {STR_VAR_2}.\pWould you like to switch the\ntwo items?");
#endif

const u8 gText_PkmnNotHolding[] =
#ifdef CHINESE
    _("{STR_VAR_1} isn't holding\nanything.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} isn't holding\nanything.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_ReceivedItemFromPkmn[] =
#ifdef CHINESE
    _("Received the {STR_VAR_2}\nfrom {STR_VAR_1}.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("Received the {STR_VAR_2}\nfrom {STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_MailTakenFromPkmn[] =
#ifdef CHINESE
    _("MAIL was taken from the\nPOKéMON.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("MAIL was taken from the\nPOKéMON.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_SwitchedPkmnItem[] =
#ifdef CHINESE
    _("The {STR_VAR_2} was taken and\nreplaced with the {STR_VAR_1}.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("The {STR_VAR_2} was taken and\nreplaced with the {STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnHoldingItemCantHoldMail[] =
#ifdef CHINESE
    _("This POKéMON is holding an\nitem. It cannot hold MAIL.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("This POKéMON is holding an\nitem. It cannot hold MAIL.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_MailTransferredFromMailbox[] =
#ifdef CHINESE
    _("MAIL was transferred from\nthe MAILBOX.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("MAIL was transferred from\nthe MAILBOX.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_BagFullCouldNotRemoveItem[] =
#ifdef CHINESE
    _("The BAG is full. The POKéMON's\nitem could not be removed.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("The BAG is full. The POKéMON's\nitem could not be removed.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnLearnedMove3[] =
#ifdef CHINESE
    _("{STR_VAR_1} learned\n{STR_VAR_2}!"); //TODO 汉化
#else
    _("{STR_VAR_1} learned\n{STR_VAR_2}!");
#endif

const u8 gText_PkmnCantLearnMove[] =
#ifdef CHINESE
    _("{STR_VAR_1} and {STR_VAR_2}\nare not compatible.\p{STR_VAR_2} can't be\nlearned.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} and {STR_VAR_2}\nare not compatible.\p{STR_VAR_2} can't be\nlearned.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnNeedsToReplaceMove[] =
#ifdef CHINESE
    _("{STR_VAR_1} wants to learn the\nmove {STR_VAR_2}.\pHowever, {STR_VAR_1} already\nknows four moves.\pShould a move be deleted and\nreplaced with {STR_VAR_2}?"); //TODO 汉化
#else
    _("{STR_VAR_1} wants to learn the\nmove {STR_VAR_2}.\pHowever, {STR_VAR_1} already\nknows four moves.\pShould a move be deleted and\nreplaced with {STR_VAR_2}?");
#endif

const u8 gText_StopLearningMove2[] =
#ifdef CHINESE
    _("Stop trying to teach\n{STR_VAR_2}?"); //TODO 汉化
#else
    _("Stop trying to teach\n{STR_VAR_2}?");
#endif

const u8 gText_MoveNotLearned[] =
#ifdef CHINESE
    _("{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_WhichMoveToForget[] =
#ifdef CHINESE
    _("Which move should be forgotten?{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("Which move should be forgotten?{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_12PoofForgotMove[] =
#ifdef CHINESE
    _("1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p{STR_VAR_1} forgot how to\nuse {STR_VAR_2}.\pAnd…{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p{STR_VAR_1} forgot how to\nuse {STR_VAR_2}.\pAnd…{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnAlreadyKnows[] =
#ifdef CHINESE
    _("{STR_VAR_1} already knows\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} already knows\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnHPRestoredByVar2[] =
#ifdef CHINESE
    _("{STR_VAR_1}'s HP was restored\nby {STR_VAR_2} point(s).{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1}'s HP was restored\nby {STR_VAR_2} point(s).{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnCuredOfPoison[] =
#ifdef CHINESE
    _("{STR_VAR_1} was cured of its\npoisoning.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} was cured of its\npoisoning.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnCuredOfParalysis[] =
#ifdef CHINESE
    _("{STR_VAR_1} was cured of\nparalysis.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} was cured of\nparalysis.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnWokeUp2[] =
#ifdef CHINESE
    _("{STR_VAR_1} woke up.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} woke up.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnBurnHealed[] =
#ifdef CHINESE
    _("{STR_VAR_1}'s burn was healed.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1}'s burn was healed.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnThawedOut[] =
#ifdef CHINESE
    _("{STR_VAR_1} was thawed out.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} was thawed out.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PPWasRestored[] =
#ifdef CHINESE
    _("PP was restored.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("PP was restored.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnRegainhedHealth[] =
#ifdef CHINESE
    _("{STR_VAR_1} regained health.{PAUSE_UNTIL_PRESS}"); // Unused //TODO 汉化
#else
    _("{STR_VAR_1} regained health.{PAUSE_UNTIL_PRESS}"); // Unused
#endif

const u8 gText_PkmnBecameHealthy[] =
#ifdef CHINESE
    _("{STR_VAR_1} became healthy.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} became healthy.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_MovesPPIncreased[] =
#ifdef CHINESE
    _("{STR_VAR_1}'s PP increased.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1}'s PP increased.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnElevatedToLvVar2[] =
#ifdef CHINESE
    _("{STR_VAR_1} was elevated to\nLv. {STR_VAR_2}."); //TODO 汉化
#else
    _("{STR_VAR_1} was elevated to\nLv. {STR_VAR_2}.");
#endif

const u8 gText_PkmnBaseVar2StatIncreased[] =
#ifdef CHINESE
    _("{STR_VAR_1}'s base {STR_VAR_2}\nstat was raised.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1}'s base {STR_VAR_2}\nstat was raised.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnFriendlyBaseVar2Fell[] =
#ifdef CHINESE
    _("{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnAdoresBaseVar2Fell[] =
#ifdef CHINESE
    _("{STR_VAR_1} adores you!\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} adores you!\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnFriendlyBaseVar2CantFall[] =
#ifdef CHINESE
    _("{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} can't fall!{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} can't fall!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnSnappedOutOfConfusion[] =
#ifdef CHINESE
    _("{STR_VAR_1} snapped out of its\nconfusion.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} snapped out of its\nconfusion.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_PkmnGotOverInfatuation[] =
#ifdef CHINESE
    _("{STR_VAR_1} got over its\ninfatuation.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{STR_VAR_1} got over its\ninfatuation.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_ThrowAwayItem[] =
#ifdef CHINESE
    _("Throw away this\n{STR_VAR_1}?"); //TODO 汉化
#else
    _("Throw away this\n{STR_VAR_1}?");
#endif

const u8 gText_ItemThrownAway[] =
#ifdef CHINESE
    _("The {STR_VAR_1}\nwas thrown away.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("The {STR_VAR_1}\nwas thrown away.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_TeachWhichPokemon2[] =
#ifdef CHINESE
    _("Teach which POKéMON?"); // Unused //TODO 汉化
#else
    _("Teach which POKéMON?"); // Unused
#endif

const u8 gText_ChoosePokemon[] =
#ifdef CHINESE
    _("Choose a POKéMON."); //TODO 汉化
#else
    _("Choose a POKéMON.");
#endif

const u8 gText_MoveToWhere[] =
#ifdef CHINESE
    _("Move to where?"); //TODO 汉化
#else
    _("Move to where?");
#endif

const u8 gText_TeachWhichPokemon[] =
#ifdef CHINESE
    _("Teach which POKéMON?"); //TODO 汉化
#else
    _("Teach which POKéMON?");
#endif

const u8 gText_UseOnWhichPokemon[] =
#ifdef CHINESE
    _("Use on which POKéMON?"); //TODO 汉化
#else
    _("Use on which POKéMON?");
#endif

const u8 gText_GiveToWhichPokemon[] =
#ifdef CHINESE
    _("Give to which POKéMON?"); //TODO 汉化
#else
    _("Give to which POKéMON?");
#endif

const u8 gText_DoWhatWithPokemon[] =
#ifdef CHINESE
    _("Do what with this {PKMN}?"); //TODO 汉化
#else
    _("Do what with this {PKMN}?");
#endif

const u8 gText_NothingToCut[] =
#ifdef CHINESE
    _("There's nothing to CUT."); //TODO 汉化
#else
    _("There's nothing to CUT.");
#endif

const u8 gText_CantSurfHere[] =
#ifdef CHINESE
    _("You can't SURF here."); //TODO 汉化
#else
    _("You can't SURF here.");
#endif

const u8 gText_AlreadySurfing[] =
#ifdef CHINESE
    _("You're already SURFING."); //TODO 汉化
#else
    _("You're already SURFING.");
#endif

const u8 gText_CantUseHere[] =
#ifdef CHINESE
    _("Can't use that here."); //TODO 汉化
#else
    _("Can't use that here.");
#endif

const u8 gText_RestoreWhichMove[] =
#ifdef CHINESE
    _("Restore which move?"); //TODO 汉化
#else
    _("Restore which move?");
#endif

const u8 gText_BoostPp[] =
#ifdef CHINESE
    _("Boost PP of which move?"); //TODO 汉化
#else
    _("Boost PP of which move?");
#endif

const u8 gText_DoWhatWithItem[] =
#ifdef CHINESE
    _("Do what with an item?"); //TODO 汉化
#else
    _("Do what with an item?");
#endif

const u8 gText_NoPokemonForBattle[] =
#ifdef CHINESE
    _("No POKéMON for battle!"); //TODO 汉化
#else
    _("No POKéMON for battle!");
#endif

const u8 gText_ChoosePokemon2[] =
#ifdef CHINESE
    _("Choose a POKéMON."); //TODO 汉化
#else
    _("Choose a POKéMON.");
#endif

const u8 gText_NotEnoughHp[] =
#ifdef CHINESE
    _("Not enough HP…"); //TODO 汉化
#else
    _("Not enough HP…");
#endif

const u8 gText_PokemonAreNeeded[] =
#ifdef CHINESE
    _("{STR_VAR_1} POKéMON are needed."); //TODO 汉化
#else
    _("{STR_VAR_1} POKéMON are needed.");
#endif

const u8 gText_PokemonCantBeSame[] =
#ifdef CHINESE
    _("POKéMON can't be the same."); //TODO 汉化
#else
    _("POKéMON can't be the same.");
#endif

const u8 gText_NoIdenticalHoldItems[] =
#ifdef CHINESE
    _("No identical hold items."); //TODO 汉化
#else
    _("No identical hold items.");
#endif

const u8 gText_CurrentIsTooFast[] =
#ifdef CHINESE
    _("The current is much too fast!"); //TODO 汉化
#else
    _("The current is much too fast!");
#endif

const u8 gText_DoWhatWithMail[] =
#ifdef CHINESE
    _("Do what with the MAIL?"); //TODO 汉化
#else
    _("Do what with the MAIL?");
#endif

const u8 gText_ChoosePokemonCancel[] =
#ifdef CHINESE
    _("Choose POKéMON or CANCEL."); //TODO 汉化
#else
    _("Choose POKéMON or CANCEL.");
#endif

const u8 gText_ChoosePokemonConfirm[] =
#ifdef CHINESE
    _("Choose POKéMON and confirm."); //TODO 汉化
#else
    _("Choose POKéMON and confirm.");
#endif

const u8 gText_EnjoyCycling[] =
#ifdef CHINESE
    _("Let's enjoy cycling!"); //TODO 汉化
#else
    _("Let's enjoy cycling!");
#endif

const u8 gText_InUseAlready_PM[] =
#ifdef CHINESE
    _("This is in use already."); //TODO 汉化
#else
    _("This is in use already.");
#endif

const u8 gText_AlreadyHoldingOne[] =
#ifdef CHINESE
    _("{STR_VAR_1} is already holding\none {STR_VAR_2}."); //TODO 汉化
#else
    _("{STR_VAR_1} is already holding\none {STR_VAR_2}.");
#endif

const u8 gText_NoUse[] =
#ifdef CHINESE
    _("No use."); //TODO 汉化
#else
    _("No use.");
#endif

const u8 gText_Able[] =
#ifdef CHINESE
    _("ABLE"); //TODO 汉化
#else
    _("ABLE");
#endif

const u8 gText_First_PM[] =
#ifdef CHINESE
    _("FIRST"); //TODO 汉化
#else
    _("FIRST");
#endif

const u8 gText_Second_PM[] =
#ifdef CHINESE
    _("SECOND"); //TODO 汉化
#else
    _("SECOND");
#endif

const u8 gText_Third_PM[] =
#ifdef CHINESE
    _("THIRD"); //TODO 汉化
#else
    _("THIRD");
#endif

const u8 gText_Able2[] =
#ifdef CHINESE
    _("ABLE"); //TODO 汉化
#else
    _("ABLE");
#endif

const u8 gText_NotAble[] =
#ifdef CHINESE
    _("NOT ABLE"); //TODO 汉化
#else
    _("NOT ABLE");
#endif

const u8 gText_Able3[] =
#ifdef CHINESE
    _("ABLE!"); //TODO 汉化
#else
    _("ABLE!");
#endif

const u8 gText_NotAble2[] =
#ifdef CHINESE
    _("NOT ABLE!"); //TODO 汉化
#else
    _("NOT ABLE!");
#endif

const u8 gText_Learned[] =
#ifdef CHINESE
    _("LEARNED"); //TODO 汉化
#else
    _("LEARNED");
#endif

const u8 gText_Have[] =
#ifdef CHINESE
    _("HAVE"); //TODO 汉化
#else
    _("HAVE");
#endif

const u8 gText_DontHave[] =
#ifdef CHINESE
    _("DON'T HAVE"); //TODO 汉化
#else
    _("DON'T HAVE");
#endif

const u8 gText_Fourth[] =
#ifdef CHINESE
    _("FOURTH"); //TODO 汉化
#else
    _("FOURTH");
#endif

const u8 gText_PkmnCantParticipate[] =
#ifdef CHINESE
    _("That POKéMON can't participate.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("That POKéMON can't participate.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_CancelParticipation[] =
#ifdef CHINESE
    _("Cancel participation?"); //TODO 汉化
#else
    _("Cancel participation?");
#endif

const u8 gText_CancelBattle[] =
#ifdef CHINESE
    _("Cancel the battle?"); //TODO 汉化
#else
    _("Cancel the battle?");
#endif

const u8 gText_ReturnToWaitingRoom[] =
#ifdef CHINESE
    _("Return to the WAITING ROOM?"); //TODO 汉化
#else
    _("Return to the WAITING ROOM?");
#endif

const u8 gText_CancelChallenge[] =
#ifdef CHINESE
    _("Cancel the challenge?"); //TODO 汉化
#else
    _("Cancel the challenge?");
#endif

const u8 gText_EscapeFromHere[] =
#ifdef CHINESE
    _("Want to escape from here and return\nto {STR_VAR_1}?"); //TODO 汉化
#else
    _("Want to escape from here and return\nto {STR_VAR_1}?");
#endif

const u8 gText_ReturnToHealingSpot[] =
#ifdef CHINESE
    _("Want to return to the healing spot\nused last in {STR_VAR_1}?"); //TODO 汉化
#else
    _("Want to return to the healing spot\nused last in {STR_VAR_1}?");
#endif

const u8 gText_PauseUntilPress[] =
#ifdef CHINESE
    _("{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("{PAUSE_UNTIL_PRESS}");
#endif

const u8 gJPText_AreYouSureYouWantToSpinTradeMon[] =
#ifdef CHINESE
    _("{STR_VAR_1}を ぐるぐるこうかんに\nだして よろしいですか？"); //TODO 汉化
#else
    _("{STR_VAR_1}を ぐるぐるこうかんに\nだして よろしいですか？");
#endif

ALIGNED(4)
const u8 gText_OnlyPkmnForBattle[] =
#ifdef CHINESE
    _("That's your only\nPOKéMON for battle."); //TODO 汉化
#else
    _("That's your only\nPOKéMON for battle.");
#endif

ALIGNED(4)
const u8 gText_PkmnCantBeTradedNow[] =
#ifdef CHINESE
    _("That POKéMON can't be traded\nnow."); //TODO 汉化
#else
    _("That POKéMON can't be traded\nnow.");
#endif

ALIGNED(4)
const u8 gText_EggCantBeTradedNow[] =
#ifdef CHINESE
    _("An EGG can't be traded now."); //TODO 汉化
#else
    _("An EGG can't be traded now.");
#endif

ALIGNED(4)
const u8 gText_OtherTrainersPkmnCantBeTraded[] =
#ifdef CHINESE
    _("The other TRAINER's POKéMON\ncan't be traded now."); //TODO 汉化
#else
    _("The other TRAINER's POKéMON\ncan't be traded now.");
#endif

ALIGNED(4)
const u8 gText_OtherTrainerCantAcceptPkmn[] =
#ifdef CHINESE
    _("The other TRAINER can't accept\nthat POKéMON now."); //TODO 汉化
#else
    _("The other TRAINER can't accept\nthat POKéMON now.");
#endif

ALIGNED(4)
const u8 gText_CantTradeWithTrainer[] =
#ifdef CHINESE
    _("You can't trade with that\nTRAINER now."); //TODO 汉化
#else
    _("You can't trade with that\nTRAINER now.");
#endif

ALIGNED(4)
const u8 gText_NotPkmnOtherTrainerWants[] =
#ifdef CHINESE
    _("That isn't the type of POKéMON\nthat the other TRAINER wants."); //TODO 汉化
#else
    _("That isn't the type of POKéMON\nthat the other TRAINER wants.");
#endif

ALIGNED(4)
const u8 gText_ThatIsntAnEgg[] =
#ifdef CHINESE
    _("That isn't an EGG."); //TODO 汉化
#else
    _("That isn't an EGG.");
#endif

const u8 gText_Register[] =
#ifdef CHINESE
    _("REGISTER"); //TODO 汉化
#else
    _("REGISTER");
#endif

const u8 gText_Attack3[] =
#ifdef CHINESE
    _("ATTACK"); //TODO 汉化
#else
    _("ATTACK");
#endif

const u8 gText_Defense3[] =
#ifdef CHINESE
    _("DEFENSE"); //TODO 汉化
#else
    _("DEFENSE");
#endif

const u8 gText_SpAtk4[] =
#ifdef CHINESE
    _("SP. ATK"); //TODO 汉化
#else
    _("SP. ATK");
#endif

const u8 gText_SpDef4[] =
#ifdef CHINESE
    _("SP. DEF"); //TODO 汉化
#else
    _("SP. DEF");
#endif

const u8 gText_Speed2[] =
#ifdef CHINESE
    _("SPEED"); //TODO 汉化
#else
    _("SPEED");
#endif

const u8 gText_HP4[] =
#ifdef CHINESE
    _("HP"); //TODO 汉化
#else
    _("HP");
#endif

const u8 gText_EmptyString8[] = _("");

const u8 gText_OTSlash[] =
#ifdef CHINESE
    _("OT/"); //TODO 汉化
#else
    _("OT/");
#endif

const u8 gText_RentalPkmn[] =
#ifdef CHINESE
    _("RENTAL POKéMON"); //TODO 汉化
#else
    _("RENTAL POKéMON");
#endif

const u8 gText_TypeSlash[] =
#ifdef CHINESE
    _("TYPE/"); //TODO 汉化
#else
    _("TYPE/");
#endif

const u8 gText_Power[] =
#ifdef CHINESE
    _("POWER"); //TODO 汉化
#else
    _("POWER");
#endif

const u8 gText_Accuracy2[] =
#ifdef CHINESE
    _("ACCURACY"); //TODO 汉化
#else
    _("ACCURACY");
#endif

const u8 gText_Appeal[] =
#ifdef CHINESE
    _("APPEAL"); //TODO 汉化
#else
    _("APPEAL");
#endif

const u8 gText_Jam[] =
#ifdef CHINESE
    _("JAM"); //TODO 汉化
#else
    _("JAM");
#endif

const u8 gText_Status[] =
#ifdef CHINESE
    _("STATUS"); //TODO 汉化
#else
    _("STATUS");
#endif

const u8 gText_ExpPoints[] =
#ifdef CHINESE
    _("EXP. POINTS"); //TODO 汉化
#else
    _("EXP. POINTS");
#endif

const u8 gText_NextLv[] =
#ifdef CHINESE
    _("NEXT LV."); //TODO 汉化
#else
    _("NEXT LV.");
#endif

const u8 gText_RibbonsVar1[] =
#ifdef CHINESE
    _("RIBBONS: {STR_VAR_1}"); //TODO 汉化
#else
    _("RIBBONS: {STR_VAR_1}");
#endif

const u8 gText_EmptyString5[] = _("");

const u8 gText_Events[] =
#ifdef CHINESE
    _("EVENTS"); // Unused //TODO 汉化
#else
    _("EVENTS"); // Unused
#endif

const u8 gText_Switch[] =
#ifdef CHINESE
    _("SWITCH"); //TODO 汉化
#else
    _("SWITCH");
#endif

const u8 gText_PkmnInfo[] =
#ifdef CHINESE
    _("POKéMON INFO"); //TODO 汉化
#else
    _("POKéMON INFO");
#endif

const u8 gText_PkmnSkills[] =
#ifdef CHINESE
    _("POKéMON SKILLS"); //TODO 汉化
#else
    _("POKéMON SKILLS");
#endif

const u8 gText_BattleMoves[] =
#ifdef CHINESE
    _("BATTLE MOVES"); //TODO 汉化
#else
    _("BATTLE MOVES");
#endif

const u8 gText_ContestMoves[] =
#ifdef CHINESE
    _("C0NTEST MOVES"); //TODO 汉化
#else
    _("C0NTEST MOVES");
#endif

const u8 gText_Info[] =
#ifdef CHINESE
    _("INFO"); //TODO 汉化
#else
    _("INFO");
#endif

const u8 gText_EggWillTakeALongTime[] =
#ifdef CHINESE
    _("It looks like this EGG will\ntake a long time to hatch."); //TODO 汉化
#else
    _("It looks like this EGG will\ntake a long time to hatch.");
#endif

const u8 gText_EggWillTakeSomeTime[] =
#ifdef CHINESE
    _("What will hatch from this?\nIt will take some time."); //TODO 汉化
#else
    _("What will hatch from this?\nIt will take some time.");
#endif

const u8 gText_EggWillHatchSoon[] =
#ifdef CHINESE
    _("It moves occasionally.\nIt should hatch soon."); //TODO 汉化
#else
    _("It moves occasionally.\nIt should hatch soon.");
#endif

const u8 gText_EggAboutToHatch[] =
#ifdef CHINESE
    _("It's making sounds.\nIt's about to hatch!"); //TODO 汉化
#else
    _("It's making sounds.\nIt's about to hatch!");
#endif

const u8 gText_HMMovesCantBeForgotten2[] =
#ifdef CHINESE
    _("HM moves can't be\nforgotten now."); //TODO 汉化
#else
    _("HM moves can't be\nforgotten now.");
#endif

const u8 gText_XNatureMetAtYZ[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nmet at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}."); //TODO 汉化
#else
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nmet at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
#endif

const u8 gText_XNatureHatchedAtYZ[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nhatched at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}."); //TODO 汉化
#else
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nhatched at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
#endif

const u8 gText_XNatureObtainedInTrade[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nobtained in a trade."); //TODO 汉化
#else
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nobtained in a trade.");
#endif

const u8 gText_XNatureFatefulEncounter[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nobtained in a fateful\nencounter at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}."); //TODO 汉化
#else
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nobtained in a fateful\nencounter at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
#endif

const u8 gText_XNatureProbablyMetAt[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nprobably met at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}."); //TODO 汉化
#else
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nprobably met at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
#endif

const u8 gText_XNature[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature"); //TODO 汉化
#else
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature");
#endif

const u8 gText_XNatureMetSomewhereAt[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nmet somewhere at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}."); //TODO 汉化
#else
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nmet somewhere at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
#endif

const u8 gText_XNatureHatchedSomewhereAt[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nhatched somewhere at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}."); //TODO 汉化
#else
    _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5} nature,\nhatched somewhere at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
#endif

const u8 gText_OddEggFoundByCouple[] =
#ifdef CHINESE
    _("An odd POKéMON EGG found\nby the DAY CARE couple."); //TODO 汉化
#else
    _("An odd POKéMON EGG found\nby the DAY CARE couple.");
#endif

const u8 gText_PeculiarEggNicePlace[] =
#ifdef CHINESE
    _("A peculiar POKéMON EGG\nobtained at the nice place."); //TODO 汉化
#else
    _("A peculiar POKéMON EGG\nobtained at the nice place.");
#endif

const u8 gText_PeculiarEggTrade[] =
#ifdef CHINESE
    _("A peculiar POKéMON EGG\nobtained in a trade."); //TODO 汉化
#else
    _("A peculiar POKéMON EGG\nobtained in a trade.");
#endif

const u8 gText_EggFromHotSprings[] =
#ifdef CHINESE
    _("A POKéMON EGG obtained\nat the hot springs."); //TODO 汉化
#else
    _("A POKéMON EGG obtained\nat the hot springs.");
#endif

const u8 gText_EggFromTraveler[] =
#ifdef CHINESE
    _("An odd POKéMON EGG\nobtained from a traveler."); //TODO 汉化
#else
    _("An odd POKéMON EGG\nobtained from a traveler.");
#endif

const u8 gText_ApostropheSBase[] =
#ifdef CHINESE
    _("'    s BASE"); //TODO 汉化
#else
    _("'s BASE");
#endif

const u8 gText_OkayToDeleteFromRegistry[] =
#ifdef CHINESE
    _("Is it okay to delete {STR_VAR_1}\nfrom the REGISTRY?"); //TODO 汉化
#else
    _("Is it okay to delete {STR_VAR_1}\nfrom the REGISTRY?");
#endif

const u8 gText_RegisteredDataDeleted[] =
#ifdef CHINESE
    _("The registered data was deleted.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("The registered data was deleted.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_NoRegistry[] =
#ifdef CHINESE
    _("There is no REGISTRY.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("There is no REGISTRY.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_DelRegist[] =
#ifdef CHINESE
    _("DEL REGIST."); //TODO 汉化
#else
    _("DEL REGIST.");
#endif

const u8 gText_Var3Var1SlashVar2[] =
#ifdef CHINESE
    _("{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}"); // Unused //TODO 汉化
#else
    _("{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}"); // Unused
#endif

const u8 gText_Decorate[] =
#ifdef CHINESE
    _("DECORATE"); //TODO 汉化
#else
    _("DECORATE");
#endif

const u8 gText_PutAway[] =
#ifdef CHINESE
    _("PUT AWAY"); //TODO 汉化
#else
    _("PUT AWAY");
#endif

const u8 gText_Toss2[] =
#ifdef CHINESE
    _("TOSS"); //TODO 汉化
#else
    _("TOSS");
#endif

const u8 gText_Color161Shadow161[] =
#ifdef CHINESE
    _("{COLOR 161}{SHADOW 161}"); //TODO 汉化
#else
    _("{COLOR 161}{SHADOW 161}");
#endif

const u8 gText_PutOutSelectedDecorItem[] =
#ifdef CHINESE
    _("Put out the selected decoration item."); //TODO 汉化
#else
    _("Put out the selected decoration item.");
#endif

const u8 gText_StoreChosenDecorInPC[] =
#ifdef CHINESE
    _("Store the chosen decoration in the PC."); //TODO 汉化
#else
    _("Store the chosen decoration in the PC.");
#endif

const u8 gText_ThrowAwayUnwantedDecors[] =
#ifdef CHINESE
    _("Throw away unwanted decorations."); //TODO 汉化
#else
    _("Throw away unwanted decorations.");
#endif

const u8 gText_NoDecorations[] =
#ifdef CHINESE
    _("There are no decorations.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("There are no decorations.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_Desk[] =
#ifdef CHINESE
    _("DESK"); //TODO 汉化
#else
    _("DESK");
#endif

const u8 gText_Chair[] =
#ifdef CHINESE
    _("CHAIR"); //TODO 汉化
#else
    _("CHAIR");
#endif

const u8 gText_Plant[] =
#ifdef CHINESE
    _("PLANT"); //TODO 汉化
#else
    _("PLANT");
#endif

const u8 gText_Ornament[] =
#ifdef CHINESE
    _("ORNAMENT"); //TODO 汉化
#else
    _("ORNAMENT");
#endif

const u8 gText_Mat[] =
#ifdef CHINESE
    _("MAT"); //TODO 汉化
#else
    _("MAT");
#endif

const u8 gText_Poster[] =
#ifdef CHINESE
    _("POSTER"); //TODO 汉化
#else
    _("POSTER");
#endif

const u8 gText_Doll[] =
#ifdef CHINESE
    _("DOLL"); //TODO 汉化
#else
    _("DOLL");
#endif

const u8 gText_Cushion[] =
#ifdef CHINESE
    _("CUSHION"); //TODO 汉化
#else
    _("CUSHION");
#endif

const u8 gText_Gold[] =
#ifdef CHINESE
    _("GOLD"); //TODO 汉化
#else
    _("GOLD");
#endif

const u8 gText_Silver[] =
#ifdef CHINESE
    _("SILVER"); //TODO 汉化
#else
    _("SILVER");
#endif

const u8 gText_PlaceItHere[] =
#ifdef CHINESE
    _("Place it here?"); //TODO 汉化
#else
    _("Place it here?");
#endif

const u8 gText_CantBePlacedHere[] =
#ifdef CHINESE
    _("It can't be placed here."); //TODO 汉化
#else
    _("It can't be placed here.");
#endif

const u8 gText_CancelDecorating[] =
#ifdef CHINESE
    _("Cancel decorating?"); //TODO 汉化
#else
    _("Cancel decorating?");
#endif

const u8 gText_InUseAlready[] =
#ifdef CHINESE
    _("This is in use already."); //TODO 汉化
#else
    _("This is in use already.");
#endif

const u8 gText_NoMoreDecorations[] =
#ifdef CHINESE
    _("No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}."); //TODO 汉化
#else
    _("No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}.");
#endif

const u8 gText_NoMoreDecorations2[] =
#ifdef CHINESE
    _("No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}."); //TODO 汉化
#else
    _("No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}.");
#endif

const u8 gText_MustBePlacedOnDesk[] =
#ifdef CHINESE
    _("This can't be placed here.\nIt must be on a DESK, etc."); // Unused //TODO 汉化
#else
    _("This can't be placed here.\nIt must be on a DESK, etc."); // Unused
#endif

const u8 gText_CantPlaceInRoom[] =
#ifdef CHINESE
    _("This decoration can't be placed in\nyour own room."); //TODO 汉化
#else
    _("This decoration can't be placed in\nyour own room.");
#endif

const u8 gText_CantThrowAwayInUse[] =
#ifdef CHINESE
    _("This decoration is in use.\nIt can't be thrown away."); //TODO 汉化
#else
    _("This decoration is in use.\nIt can't be thrown away.");
#endif

const u8 gText_DecorationWillBeDiscarded[] =
#ifdef CHINESE
    _("This {STR_VAR_1} will be discarded.\nIs that okay?"); //TODO 汉化
#else
    _("This {STR_VAR_1} will be discarded.\nIs that okay?");
#endif

const u8 gText_DecorationThrownAway[] =
#ifdef CHINESE
    _("The decoration item was thrown away."); //TODO 汉化
#else
    _("The decoration item was thrown away.");
#endif

const u8 gText_StopPuttingAwayDecorations[] =
#ifdef CHINESE
    _("Stop putting away decorations?"); //TODO 汉化
#else
    _("Stop putting away decorations?");
#endif

const u8 gText_NoDecorationHere[] =
#ifdef CHINESE
    _("There is no decoration item here."); //TODO 汉化
#else
    _("There is no decoration item here.");
#endif

const u8 gText_ReturnDecorationToPC[] =
#ifdef CHINESE
    _("Return this decoration to the PC?"); //TODO 汉化
#else
    _("Return this decoration to the PC?");
#endif

const u8 gText_DecorationReturnedToPC[] =
#ifdef CHINESE
    _("The decoration was returned to the PC."); //TODO 汉化
#else
    _("The decoration was returned to the PC.");
#endif

const u8 gText_NoDecorationsInUse[] =
#ifdef CHINESE
    _("There are no decorations in use.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("There are no decorations in use.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_Tristan[] =
#ifdef CHINESE
    _("TRISTAN"); //TODO 汉化
#else
    _("TRISTAN");
#endif

const u8 gText_Philip[] =
#ifdef CHINESE
    _("PHILIP"); //TODO 汉化
#else
    _("PHILIP");
#endif

const u8 gText_Dennis[] =
#ifdef CHINESE
    _("DENNIS"); //TODO 汉化
#else
    _("DENNIS");
#endif

const u8 gText_Roberto[] =
#ifdef CHINESE
    _("ROBERTO"); //TODO 汉化
#else
    _("ROBERTO");
#endif

const u8 gText_TurnOff[] =
#ifdef CHINESE
    _("TURN OFF"); //TODO 汉化
#else
    _("TURN OFF");
#endif

const u8 gText_Decoration[] =
#ifdef CHINESE
    _("DECORATION"); //TODO 汉化
#else
    _("DECORATION");
#endif

const u8 gText_ItemStorage[] =
#ifdef CHINESE
    _("ITEM STORAGE"); //TODO 汉化
#else
    _("ITEM STORAGE");
#endif

const u8 gText_Mailbox[] =
#ifdef CHINESE
    _("MAILBOX"); //TODO 汉化
#else
    _("MAILBOX");
#endif

const u8 gText_DepositItem[] =
#ifdef CHINESE
    _("DEPOSIT ITEM"); //TODO 汉化
#else
    _("DEPOSIT ITEM");
#endif

const u8 gText_WithdrawItem[] =
#ifdef CHINESE
    _("WITHDRAW ITEM"); //TODO 汉化
#else
    _("WITHDRAW ITEM");
#endif

const u8 gText_TossItem[] =
#ifdef CHINESE
    _("TOSS ITEM"); //TODO 汉化
#else
    _("TOSS ITEM");
#endif

const u8 gText_StoreItemsInPC[] =
#ifdef CHINESE
    _("Store items in the PC."); //TODO 汉化
#else
    _("Store items in the PC.");
#endif

const u8 gText_TakeOutItemsFromPC[] =
#ifdef CHINESE
    _("Take out items from the PC."); //TODO 汉化
#else
    _("Take out items from the PC.");
#endif

const u8 gText_ThrowAwayItemsInPC[] =
#ifdef CHINESE
    _("Throw away items stored in the PC."); //TODO 汉化
#else
    _("Throw away items stored in the PC.");
#endif

const u8 gText_NoItems[] =
#ifdef CHINESE
    _("There are no items.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("There are no items.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_NoRoomInBag[] =
#ifdef CHINESE
    _("There is no more\nroom in the BAG."); //TODO 汉化
#else
    _("There is no more\nroom in the BAG.");
#endif

const u8 gText_WithdrawHowManyItems[] =
#ifdef CHINESE
    _("Withdraw how many\n{STR_VAR_1}(s)?"); //TODO 汉化
#else
    _("Withdraw how many\n{STR_VAR_1}(s)?");
#endif

const u8 gText_WithdrawXItems[] =
#ifdef CHINESE
    _("Withdrew {STR_VAR_2}\n{STR_VAR_1}(s)."); //TODO 汉化
#else
    _("Withdrew {STR_VAR_2}\n{STR_VAR_1}(s).");
#endif

const u8 gText_Read[] =
#ifdef CHINESE
    _("READ"); //TODO 汉化
#else
    _("READ");
#endif

const u8 gText_MoveToBag[] =
#ifdef CHINESE
    _("MOVE TO BAG"); //TODO 汉化
#else
    _("MOVE TO BAG");
#endif

const u8 gText_Give2[] =
#ifdef CHINESE
    _("GIVE"); //TODO 汉化
#else
    _("GIVE");
#endif

const u8 gText_NoMailHere[] =
#ifdef CHINESE
    _("There's no MAIL here.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("There's no MAIL here.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_WhatToDoWithVar1sMail[] =
#ifdef CHINESE
    _("What would you like to do with\n{STR_VAR_1}'s MAIL?"); //TODO 汉化
#else
    _("What would you like to do with\n{STR_VAR_1}'s MAIL?");
#endif

const u8 gText_MessageWillBeLost[] =
#ifdef CHINESE
    _("The message will be lost.\nIs that okay?"); //TODO 汉化
#else
    _("The message will be lost.\nIs that okay?");
#endif

const u8 gText_BagIsFull[] =
#ifdef CHINESE
    _("The BAG is full.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("The BAG is full.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_MailToBagMessageErased[] =
#ifdef CHINESE
    _("The MAIL was returned to the BAG\nwith its message erased.{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("The MAIL was returned to the BAG\nwith its message erased.{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_Dad[] =
#ifdef CHINESE
    _("DAD"); //TODO 汉化
#else
    _("DAD");
#endif

const u8 gText_Mom[] =
#ifdef CHINESE
    _("MOM"); //TODO 汉化
#else
    _("MOM");
#endif

const u8 gText_Wallace[] =
#ifdef CHINESE
    _("WALLACE"); //TODO 汉化
#else
    _("WALLACE");
#endif

const u8 gText_Steven[] =
#ifdef CHINESE
    _("STEVEN"); //TODO 汉化
#else
    _("STEVEN");
#endif

const u8 gText_Brawly[] =
#ifdef CHINESE
    _("BRAWLY"); //TODO 汉化
#else
    _("BRAWLY");
#endif

const u8 gText_Winona[] =
#ifdef CHINESE
    _("WINONA"); //TODO 汉化
#else
    _("WINONA");
#endif

const u8 gText_Phoebe[] =
#ifdef CHINESE
    _("PHOEBE"); //TODO 汉化
#else
    _("PHOEBE");
#endif

const u8 gText_Glacia[] =
#ifdef CHINESE
    _("GLACIA"); //TODO 汉化
#else
    _("GLACIA");
#endif

const u8 gText_Petalburg[] =
#ifdef CHINESE
    _("PETALBURG"); //TODO 汉化
#else
    _("PETALBURG");
#endif

const u8 gText_Slateport[] =
#ifdef CHINESE
    _("SLATEPORT"); //TODO 汉化
#else
    _("SLATEPORT");
#endif

const u8 gText_Littleroot[] =
#ifdef CHINESE
    _("LITTLEROOT"); // Unused. Given the context, Briney may at one point have been able to sail the player here //TODO 汉化
#else
    _("LITTLEROOT"); // Unused. Given the context, Briney may at one point have been able to sail the player here
#endif

const u8 gText_Lilycove[] =
#ifdef CHINESE
    _("LILYCOVE"); // Unused. Given the context, Briney may at one point have been able to sail the player here //TODO 汉化
#else
    _("LILYCOVE");   // Unused. Given the context, Briney may at one point have been able to sail the player here
#endif

const u8 gText_Dewford[] =
#ifdef CHINESE
    _("DEWFORD"); //TODO 汉化
#else
    _("DEWFORD");
#endif

const u8 gText_Enter2[] =
#ifdef CHINESE
    _("ENTER"); //TODO 汉化
#else
    _("ENTER");
#endif

const u8 gText_Info2[] =
#ifdef CHINESE
    _("INFO"); //TODO 汉化
#else
    _("INFO");
#endif

const u8 gText_WhatsAContest[] =
#ifdef CHINESE
    _("What's a CONTEST?"); //TODO 汉化
#else
    _("What's a CONTEST?");
#endif

const u8 gText_TypesOfContests[] =
#ifdef CHINESE
    _("Types of CONTESTS"); //TODO 汉化
#else
    _("Types of CONTESTS");
#endif

const u8 gText_Ranks[] =
#ifdef CHINESE
    _("Ranks"); //TODO 汉化
#else
    _("Ranks");
#endif

const u8 gText_Judging[] =
#ifdef CHINESE
    _("Judging"); //unused //TODO 汉化
#else
    _("Judging"); //unused
#endif

const u8 gText_CoolnessContest[] =
#ifdef CHINESE
    _("COOLNESS CONTEST"); //TODO 汉化
#else
    _("COOLNESS CONTEST");
#endif

const u8 gText_BeautyContest[] =
#ifdef CHINESE
    _("BEAUTY CONTEST"); //TODO 汉化
#else
    _("BEAUTY CONTEST");
#endif

const u8 gText_CutenessContest[] =
#ifdef CHINESE
    _("CUTENESS CONTEST"); //TODO 汉化
#else
    _("CUTENESS CONTEST");
#endif

const u8 gText_SmartnessContest[] =
#ifdef CHINESE
    _("SMARTNESS CONTEST"); //TODO 汉化
#else
    _("SMARTNESS CONTEST");
#endif

const u8 gText_ToughnessContest[] =
#ifdef CHINESE
    _("TOUGHNESS CONTEST"); //TODO 汉化
#else
    _("TOUGHNESS CONTEST");
#endif

const u8 gText_Decoration2[] =
#ifdef CHINESE
    _("DECORATION"); //TODO 汉化
#else
    _("DECORATION");
#endif

const u8 gText_PackUp[] =
#ifdef CHINESE
    _("PACK UP"); //TODO 汉化
#else
    _("PACK UP");
#endif

const u8 gText_Count[] =
#ifdef CHINESE
    _("COUNT"); //unused //TODO 汉化
#else
    _("COUNT"); //unused
#endif

const u8 gText_Registry[] =
#ifdef CHINESE
    _("REGISTRY"); //TODO 汉化
#else
    _("REGISTRY");
#endif

const u8 gText_Information[] =
#ifdef CHINESE
    _("INFORMATION"); //TODO 汉化
#else
    _("INFORMATION");
#endif

const u8 gText_Mach[] =
#ifdef CHINESE
    _("MACH"); //TODO 汉化
#else
    _("MACH");
#endif

const u8 gText_Acro[] =
#ifdef CHINESE
    _("ACRO"); //TODO 汉化
#else
    _("ACRO");
#endif

const u8 gText_Psn[] =
#ifdef CHINESE
    _("PSN"); //TODO 汉化
#else
    _("PSN");
#endif

const u8 gText_Par[] =
#ifdef CHINESE
    _("PAR"); //TODO 汉化
#else
    _("PAR");
#endif

const u8 gText_Slp[] =
#ifdef CHINESE
    _("SLP"); //TODO 汉化
#else
    _("SLP");
#endif

const u8 gText_Brn[] =
#ifdef CHINESE
    _("BRN"); //TODO 汉化
#else
    _("BRN");
#endif

const u8 gText_Frz[] =
#ifdef CHINESE
    _("FRZ"); //TODO 汉化
#else
    _("FRZ");
#endif

const u8 gText_Toxic[] =
#ifdef CHINESE
    _("TOXIC"); // Unused //TODO 汉化
#else
    _("TOXIC"); // Unused
#endif

const u8 gText_Ok3[] =
#ifdef CHINESE
    _("OK"); // Unused //TODO 汉化
#else
    _("OK");    // Unused
#endif

const u8 gText_Quit[] =
#ifdef CHINESE
    _("QUIT"); // Unused //TODO 汉化
#else
    _("QUIT");  // Unused
#endif

const u8 gText_SawIt[] =
#ifdef CHINESE
    _("Saw it"); //TODO 汉化
#else
    _("Saw it");
#endif

const u8 gText_NotYet[] =
#ifdef CHINESE
    _("Not yet"); //TODO 汉化
#else
    _("Not yet");
#endif

const u8 gText_Yes[] =
#ifdef CHINESE
    _("YES"); //TODO 汉化
#else
    _("YES");
#endif

const u8 gText_No[] =
#ifdef CHINESE
    _("NO"); //TODO 汉化
#else
    _("NO");
#endif

const u8 gText_Info4[] =
#ifdef CHINESE
    _("INFO"); // Unused //TODO 汉化
#else
    _("INFO"); // Unused
#endif

const u8 gText_SingleBattle[] =
#ifdef CHINESE
    _("SINGLE BATTLE"); //TODO 汉化
#else
    _("SINGLE BATTLE");
#endif

const u8 gText_DoubleBattle[] =
#ifdef CHINESE
    _("DOUBLE BATTLE"); //TODO 汉化
#else
    _("DOUBLE BATTLE");
#endif

const u8 gText_MultiBattle[] =
#ifdef CHINESE
    _("MULTI BATTLE"); //TODO 汉化
#else
    _("MULTI BATTLE");
#endif

const u8 gText_MrBriney[] =
#ifdef CHINESE
    _("MR. BRINEY"); // Unused //TODO 汉化
#else
    _("MR. BRINEY"); // Unused
#endif

const u8 gText_Challenge[] =
#ifdef CHINESE
    _("CHALLENGE"); //TODO 汉化
#else
    _("CHALLENGE");
#endif

const u8 gText_Info3[] =
#ifdef CHINESE
    _("INFO"); //TODO 汉化
#else
    _("INFO");
#endif

const u8 gText_Lv50[] =
#ifdef CHINESE
    _("LV. 50"); //TODO 汉化
#else
    _("LV. 50");
#endif

const u8 gText_OpenLevel[] =
#ifdef CHINESE
    _("OPEN LEVEL"); //TODO 汉化
#else
    _("OPEN LEVEL");
#endif

const u8 gText_FreshWaterAndPrice[] =
#ifdef CHINESE
    _("FRESH WATER{CLEAR_TO 0x48}¥200"); //TODO 汉化
#else
    _("FRESH WATER{CLEAR_TO 0x48}¥200");
#endif

const u8 gText_SodaPopAndPrice[] =
#ifdef CHINESE
    _("SODA POP{CLEAR_TO 0x48}¥300"); //TODO 汉化
#else
    _("SODA POP{CLEAR_TO 0x48}¥300");
#endif

const u8 gText_LemonadeAndPrice[] =
#ifdef CHINESE
    _("LEMONADE{CLEAR_TO 0x48}¥350"); //TODO 汉化
#else
    _("LEMONADE{CLEAR_TO 0x48}¥350");
#endif

const u8 gText_HowToRide[] =
#ifdef CHINESE
    _("HOW TO RIDE"); //TODO 汉化
#else
    _("HOW TO RIDE");
#endif

const u8 gText_HowToTurn[] =
#ifdef CHINESE
    _("HOW TO TURN"); //TODO 汉化
#else
    _("HOW TO TURN");
#endif

const u8 gText_SandySlopes[] =
#ifdef CHINESE
    _("SANDY SLOPES"); //TODO 汉化
#else
    _("SANDY SLOPES");
#endif

const u8 gText_Wheelies[] =
#ifdef CHINESE
    _("WHEELIES"); //TODO 汉化
#else
    _("WHEELIES");
#endif

const u8 gText_BunnyHops[] =
#ifdef CHINESE
    _("BUNNY-HOPS"); //TODO 汉化
#else
    _("BUNNY-HOPS");
#endif

const u8 gText_Jump[] =
#ifdef CHINESE
    _("JUMP"); //TODO 汉化
#else
    _("JUMP");
#endif

const u8 gText_Satisfied[] =
#ifdef CHINESE
    _("Satisfied"); //TODO 汉化
#else
    _("Satisfied");
#endif

const u8 gText_Dissatisfied[] =
#ifdef CHINESE
    _("Dissatisfied"); //TODO 汉化
#else
    _("Dissatisfied");
#endif

const u8 gText_DeepSeaTooth[] =
#ifdef CHINESE
    _("DEEPSEATOOTH"); //TODO 汉化
#else
    _("DEEPSEATOOTH");
#endif

const u8 gText_DeepSeaScale[] =
#ifdef CHINESE
    _("DEEPSEASCALE"); //TODO 汉化
#else
    _("DEEPSEASCALE");
#endif

const u8 gText_BlueFlute2[] =
#ifdef CHINESE
    _("BLUE FLUTE"); //TODO 汉化
#else
    _("BLUE FLUTE");
#endif

const u8 gText_YellowFlute2[] =
#ifdef CHINESE
    _("YELLOW FLUTE"); //TODO 汉化
#else
    _("YELLOW FLUTE");
#endif

const u8 gText_RedFlute2[] =
#ifdef CHINESE
    _("RED FLUTE"); //TODO 汉化
#else
    _("RED FLUTE");
#endif

const u8 gText_WhiteFlute2[] =
#ifdef CHINESE
    _("WHITE FLUTE"); //TODO 汉化
#else
    _("WHITE FLUTE");
#endif

const u8 gText_BlackFlute2[] =
#ifdef CHINESE
    _("BLACK FLUTE"); //TODO 汉化
#else
    _("BLACK FLUTE");
#endif

const u8 gText_GlassChair[] =
#ifdef CHINESE
    _("GLASS CHAIR"); //TODO 汉化
#else
    _("GLASS CHAIR");
#endif

const u8 gText_GlassDesk[] =
#ifdef CHINESE
    _("GLASS DESK"); //TODO 汉化
#else
    _("GLASS DESK");
#endif

const u8 gText_TreeckoDollAndPrice[] =
#ifdef CHINESE
    _("TREECKO DOLL 1,000 枚硬币"); //TODO 汉化
#else
    _("TREECKO DOLL 1,000 COINS");
#endif

const u8 gText_TorchicDollAndPrice[] =
#ifdef CHINESE
    _("TORCHIC DOLL 1,000 枚硬币"); //TODO 汉化
#else
    _("TORCHIC DOLL 1,000 COINS");
#endif

const u8 gText_MudkipDollAndPrice[] =
#ifdef CHINESE
    _("MUDKIP DOLL   1,000 枚硬币"); //TODO 汉化
#else
    _("MUDKIP DOLL   1,000 COINS");
#endif

const u8 gText_50CoinsAndPrice[] =
#ifdef CHINESE
    _("  50 枚硬币    ¥1,000"); //TODO 汉化
#else
    _(" 50 COINS    ¥1,000");
#endif

const u8 gText_500CoinsAndPrice[] =
#ifdef CHINESE
    _("500 枚硬币  ¥10,000"); //TODO 汉化
#else
    _("500 COINS  ¥10,000");
#endif

const u8 gText_Excellent2[] =
#ifdef CHINESE
    _("Excellent"); //TODO 汉化
#else
    _("Excellent");
#endif

const u8 gText_NotSoGood[] =
#ifdef CHINESE
    _("Not so good"); //TODO 汉化
#else
    _("Not so good");
#endif

const u8 gText_RedShard[] =
#ifdef CHINESE
    _("RED SHARD"); //TODO 汉化
#else
    _("RED SHARD");
#endif

const u8 gText_YellowShard[] =
#ifdef CHINESE
    _("YELLOW SHARD"); //TODO 汉化
#else
    _("YELLOW SHARD");
#endif

const u8 gText_BlueShard[] =
#ifdef CHINESE
    _("BLUE SHARD"); //TODO 汉化
#else
    _("BLUE SHARD");
#endif

const u8 gText_GreenShard[] =
#ifdef CHINESE
    _("GREEN SHARD"); //TODO 汉化
#else
    _("GREEN SHARD");
#endif

const u8 gText_BattleFrontier[] =
#ifdef CHINESE
    _("BATTLE FRONTIER"); //TODO 汉化
#else
    _("BATTLE FRONTIER");
#endif

const u8 gText_Right[] =
#ifdef CHINESE
    _("Right"); //TODO 汉化
#else
    _("Right");
#endif

const u8 gText_Left[] =
#ifdef CHINESE
    _("Left"); //TODO 汉化
#else
    _("Left");
#endif

const u8 gText_TM32AndPrice[] =
#ifdef CHINESE
    _("TM32{CLEAR_TO 0x48}1,500 枚硬币"); //TODO 汉化
#else
    _("TM32{CLEAR_TO 0x48}1,500 COINS");
#endif

const u8 gText_TM29AndPrice[] =
#ifdef CHINESE
    _("TM29{CLEAR_TO 0x48}3,500 枚硬币"); //TODO 汉化
#else
    _("TM29{CLEAR_TO 0x48}3,500 COINS");
#endif

const u8 gText_TM35AndPrice[] =
#ifdef CHINESE
    _("TM35{CLEAR_TO 0x48}4,000 枚硬币"); //TODO 汉化
#else
    _("TM35{CLEAR_TO 0x48}4,000 COINS");
#endif

const u8 gText_TM24AndPrice[] =
#ifdef CHINESE
    _("TM24{CLEAR_TO 0x48}4,000 枚硬币"); //TODO 汉化
#else
    _("TM24{CLEAR_TO 0x48}4,000 COINS");
#endif

const u8 gText_TM13AndPrice[] =
#ifdef CHINESE
    _("TM13{CLEAR_TO 0x48}4,000 枚硬币"); //TODO 汉化
#else
    _("TM13{CLEAR_TO 0x48}4,000 COINS");
#endif

const u8 gText_Cool[] =
#ifdef CHINESE
    _("COOL"); //TODO 汉化
#else
    _("COOL");
#endif

const u8 gText_Beauty[] =
#ifdef CHINESE
    _("BEAUTY"); //TODO 汉化
#else
    _("BEAUTY");
#endif

const u8 gText_Cute[] =
#ifdef CHINESE
    _("CUTE"); //TODO 汉化
#else
    _("CUTE");
#endif

const u8 gText_Smart[] =
#ifdef CHINESE
    _("SMART"); //TODO 汉化
#else
    _("SMART");
#endif

const u8 gText_Tough[] =
#ifdef CHINESE
    _("TOUGH"); //TODO 汉化
#else
    _("TOUGH");
#endif

const u8 gText_Normal[] =
#ifdef CHINESE
    _("NORMAL"); //TODO 汉化
#else
    _("NORMAL");
#endif

const u8 gText_Super[] =
#ifdef CHINESE
    _("SUPER"); //TODO 汉化
#else
    _("SUPER");
#endif

const u8 gText_Hyper[] =
#ifdef CHINESE
    _("HYPER"); //TODO 汉化
#else
    _("HYPER");
#endif

const u8 gText_Master[] =
#ifdef CHINESE
    _("MASTER"); //TODO 汉化
#else
    _("MASTER");
#endif

const u8 gText_Cool2[] =
#ifdef CHINESE
    _("COOL"); //TODO 汉化
#else
    _("COOL");
#endif

const u8 gText_Beauty2[] =
#ifdef CHINESE
    _("BEAUTY"); //TODO 汉化
#else
    _("BEAUTY");
#endif

const u8 gText_Cute2[] =
#ifdef CHINESE
    _("CUTE"); //TODO 汉化
#else
    _("CUTE");
#endif

const u8 gText_Smart2[] =
#ifdef CHINESE
    _("SMART"); //TODO 汉化
#else
    _("SMART");
#endif

const u8 gText_Tough2[] =
#ifdef CHINESE
    _("TOUGH"); //TODO 汉化
#else
    _("TOUGH");
#endif

const u8 gText_Items[] =
#ifdef CHINESE
    _("ITEMS"); //TODO 汉化
#else
    _("ITEMS");
#endif

const u8 gText_Key_Items[] =
#ifdef CHINESE
    _("KEY ITEMS"); //TODO 汉化
#else
    _("KEY ITEMS");
#endif

const u8 gText_Poke_Balls[] =
#ifdef CHINESE
    _("POKé BALLS"); //TODO 汉化
#else
    _("POKé BALLS");
#endif

const u8 gText_TMs_Hms[] =
#ifdef CHINESE
    _("TMs & HMs"); //TODO 汉化
#else
    _("TMs & HMs");
#endif

const u8 gText_Berries2[] =
#ifdef CHINESE
    _("BERRIES"); //TODO 汉化
#else
    _("BERRIES");
#endif

const u8 gText_SomeonesPC[] =
#ifdef CHINESE
    _("SOMEONE'S PC"); //TODO 汉化
#else
    _("SOMEONE'S PC");
#endif

const u8 gText_LanettesPC[] =
#ifdef CHINESE
    _("LANETTE'S PC"); //TODO 汉化
#else
    _("LANETTE'S PC");
#endif

const u8 gText_PlayersPC[] =
#ifdef CHINESE
    _("{PLAYER}'s PC"); //TODO 汉化
#else
    _("{PLAYER}'s PC");
#endif

const u8 gText_HallOfFame[] =
#ifdef CHINESE
    _("HALL OF FAME"); //TODO 汉化
#else
    _("HALL OF FAME");
#endif

const u8 gText_LogOff[] =
#ifdef CHINESE
    _("LOG OFF"); //TODO 汉化
#else
    _("LOG OFF");
#endif

const u8 gText_Opponent[] =
#ifdef CHINESE
    _("OPPONENT"); //TODO 汉化
#else
    _("OPPONENT");
#endif

const u8 gText_Tourney_Tree[] =
#ifdef CHINESE
    _("TOURNEY TREE"); //TODO 汉化
#else
    _("TOURNEY TREE");
#endif

const u8 gText_ReadyToStart[] =
#ifdef CHINESE
    _("READY TO START"); //TODO 汉化
#else
    _("READY TO START");
#endif

const u8 gText_NormalRank[] =
#ifdef CHINESE
    _("NORMAL RANK"); //TODO 汉化
#else
    _("NORMAL RANK");
#endif

const u8 gText_SuperRank[] =
#ifdef CHINESE
    _("SUPER RANK"); //TODO 汉化
#else
    _("SUPER RANK");
#endif

const u8 gText_HyperRank[] =
#ifdef CHINESE
    _("HYPER RANK"); //TODO 汉化
#else
    _("HYPER RANK");
#endif

const u8 gText_MasterRank[] =
#ifdef CHINESE
    _("MASTER RANK"); //TODO 汉化
#else
    _("MASTER RANK");
#endif

const u8 gText_Single2[] =
#ifdef CHINESE
    _("SINGLE"); //TODO 汉化
#else
    _("SINGLE");
#endif

const u8 gText_Double2[] =
#ifdef CHINESE
    _("DOUBLE"); //TODO 汉化
#else
    _("DOUBLE");
#endif

const u8 gText_Multi[] =
#ifdef CHINESE
    _("MULTI"); //TODO 汉化
#else
    _("MULTI");
#endif

const u8 gText_MultiLink[] =
#ifdef CHINESE
    _("MULTI-LINK"); //TODO 汉化
#else
    _("MULTI-LINK");
#endif

const u8 gText_BattleBag[] =
#ifdef CHINESE
    _("BATTLE BAG"); //TODO 汉化
#else
    _("BATTLE BAG");
#endif

const u8 gText_HeldItem[] =
#ifdef CHINESE
    _("HELD ITEM"); //TODO 汉化
#else
    _("HELD ITEM");
#endif

const u8 gText_LinkContest[] =
#ifdef CHINESE
    _("LINK CONTEST"); //TODO 汉化
#else
    _("LINK CONTEST");
#endif

const u8 gText_AboutE_Mode[] =
#ifdef CHINESE
    _("ABOUT E-MODE"); //TODO 汉化
#else
    _("ABOUT E-MODE");
#endif

const u8 gText_AboutG_Mode[] =
#ifdef CHINESE
    _("ABOUT G-MODE"); //TODO 汉化
#else
    _("ABOUT G-MODE");
#endif

const u8 gText_E_Mode[] =
#ifdef CHINESE
    _("E-MODE"); //TODO 汉化
#else
    _("E-MODE");
#endif

const u8 gText_G_Mode[] =
#ifdef CHINESE
    _("G-MODE"); //TODO 汉化
#else
    _("G-MODE");
#endif

const u8 gText_MenuOptionPokedex[] =
#ifdef CHINESE
    _("POKéDEX"); //TODO 汉化
#else
    _("POKéDEX");
#endif

const u8 gText_MenuOptionPokemon[] =
#ifdef CHINESE
    _("POKéMON"); //TODO 汉化
#else
    _("POKéMON");
#endif

const u8 gText_MenuOptionBag[] =
#ifdef CHINESE
    _("BAG"); //TODO 汉化
#else
    _("BAG");
#endif

const u8 gText_MenuOptionPokenav[] =
#ifdef CHINESE
    _("POKéNAV"); //TODO 汉化
#else
    _("POKéNAV");
#endif

const u8 gText_Blank[] = _("");

const u8 gText_MenuOptionSave[] =
#ifdef CHINESE
    _("SAVE"); //TODO 汉化
#else
    _("SAVE");
#endif

const u8 gText_MenuOptionOption[] =
#ifdef CHINESE
    _("OPTION"); //TODO 汉化
#else
    _("OPTION");
#endif

const u8 gText_MenuOptionExit[] =
#ifdef CHINESE
    _("EXIT"); //TODO 汉化
#else
    _("EXIT");
#endif

const u8 gText_5BP[] =
#ifdef CHINESE
    _("  5BP"); //TODO 汉化
#else
    _(" 5BP");
#endif

const u8 gText_10BP[] =
#ifdef CHINESE
    _("10BP"); //TODO 汉化
#else
    _("10BP");
#endif

const u8 gText_15BP[] =
#ifdef CHINESE
    _("15BP"); //TODO 汉化
#else
    _("15BP");
#endif

const u8 gText_RedTent[] =
#ifdef CHINESE
    _("RED TENT"); //TODO 汉化
#else
    _("RED TENT");
#endif

const u8 gText_BlueTent[] =
#ifdef CHINESE
    _("BLUE TENT"); //TODO 汉化
#else
    _("BLUE TENT");
#endif

const u8 gText_SouthernIsland[] =
#ifdef CHINESE
    _("SOUTHERN ISLAND"); //TODO 汉化
#else
    _("SOUTHERN ISLAND");
#endif

const u8 gText_BirthIsland[] =
#ifdef CHINESE
    _("BIRTH ISLAND"); //TODO 汉化
#else
    _("BIRTH ISLAND");
#endif

const u8 gText_FarawayIsland[] =
#ifdef CHINESE
    _("FARAWAY ISLAND"); //TODO 汉化
#else
    _("FARAWAY ISLAND");
#endif

const u8 gText_NavelRock[] =
#ifdef CHINESE
    _("NAVEL ROCK"); //TODO 汉化
#else
    _("NAVEL ROCK");
#endif

const u8 gText_ClawFossil[] =
#ifdef CHINESE
    _("CLAW FOSSIL"); //TODO 汉化
#else
    _("CLAW FOSSIL");
#endif

const u8 gText_RootFossil[] =
#ifdef CHINESE
    _("ROOT FOSSIL"); //TODO 汉化
#else
    _("ROOT FOSSIL");
#endif

const u8 gText_No4[] =
#ifdef CHINESE
    _("NO"); //TODO 汉化
#else
    _("NO");
#endif

const u8 gText_IllBattleNow[] =
#ifdef CHINESE
    _("I'll battle now!"); //TODO 汉化
#else
    _("I'll battle now!");
#endif

const u8 gText_IWon[] =
#ifdef CHINESE
    _("I won!"); //TODO 汉化
#else
    _("I won!");
#endif

const u8 gText_ILost[] =
#ifdef CHINESE
    _("I lost!"); //TODO 汉化
#else
    _("I lost!");
#endif

const u8 gText_IWontTell[] =
#ifdef CHINESE
    _("I won't tell."); //TODO 汉化
#else
    _("I won't tell.");
#endif

const u8 gText_NormalTagMatch[] =
#ifdef CHINESE
    _("NORMAL TAG MATCH"); //TODO 汉化
#else
    _("NORMAL TAG MATCH");
#endif

const u8 gText_VarietyTagMatch[] =
#ifdef CHINESE
    _("VARIETY TAG MATCH"); //TODO 汉化
#else
    _("VARIETY TAG MATCH");
#endif

const u8 gText_UniqueTagMatch[] =
#ifdef CHINESE
    _("UNIQUE TAG MATCH"); //TODO 汉化
#else
    _("UNIQUE TAG MATCH");
#endif

const u8 gText_ExpertTagMatch[] =
#ifdef CHINESE
    _("EXPERT TAG MATCH"); //TODO 汉化
#else
    _("EXPERT TAG MATCH");
#endif

const u8 gText_TradeCenter[] =
#ifdef CHINESE
    _("TRADE CENTER"); //TODO 汉化
#else
    _("TRADE CENTER");
#endif

const u8 gText_Colosseum[] =
#ifdef CHINESE
    _("COLOSSEUM"); //TODO 汉化
#else
    _("COLOSSEUM");
#endif

const u8 gText_RecordCorner[] =
#ifdef CHINESE
    _("RECORD CORNER"); //TODO 汉化
#else
    _("RECORD CORNER");
#endif

const u8 gText_BerryCrush3[] =
#ifdef CHINESE
    _("BERRY CRUSH"); //TODO 汉化
#else
    _("BERRY CRUSH");
#endif

const u8 gText_EmptyLinkService[] = _("");

const u8 gText_PokemonJump[] =
#ifdef CHINESE
    _("POKéMON JUMP"); //TODO 汉化
#else
    _("POKéMON JUMP");
#endif

const u8 gText_DodrioBerryPicking[] =
#ifdef CHINESE
    _("DODRIO BERRY-PICKING"); //TODO 汉化
#else
    _("DODRIO BERRY-PICKING");
#endif

const u8 gText_BecomeLeader[] =
#ifdef CHINESE
    _("BECOME LEADER"); //TODO 汉化
#else
    _("BECOME LEADER");
#endif

const u8 gText_JoinGroup[] =
#ifdef CHINESE
    _("JOIN GROUP"); //TODO 汉化
#else
    _("JOIN GROUP");
#endif

const u8 gText_TwoStyles[] =
#ifdef CHINESE
    _("TWO STYLES"); //TODO 汉化
#else
    _("TWO STYLES");
#endif

const u8 gText_Lv50_3[] =
#ifdef CHINESE
    _("LV. 50"); //TODO 汉化
#else
    _("LV. 50");
#endif

const u8 gText_OpenLevel2[] =
#ifdef CHINESE
    _("OPEN LEVEL"); //TODO 汉化
#else
    _("OPEN LEVEL");
#endif

const u8 gText_MonTypeAndNo[] =
#ifdef CHINESE
    _("{PKMN} TYPE & NO."); //TODO 汉化
#else
    _("{PKMN} TYPE & NO.");
#endif

const u8 gText_HoldItems[] =
#ifdef CHINESE
    _("HOLD ITEMS"); //TODO 汉化
#else
    _("HOLD ITEMS");
#endif

const u8 gText_Symbols2[] =
#ifdef CHINESE
    _("SYMBOLS"); //TODO 汉化
#else
    _("SYMBOLS");
#endif

const u8 gText_Record3[] =
#ifdef CHINESE
    _("RECORD"); //TODO 汉化
#else
    _("RECORD");
#endif

const u8 gText_BattlePts[] =
#ifdef CHINESE
    _("BATTLE PTS"); //TODO 汉化
#else
    _("BATTLE PTS");
#endif

const u8 gText_TowerInfo[] =
#ifdef CHINESE
    _("TOWER INFO"); //TODO 汉化
#else
    _("TOWER INFO");
#endif

const u8 gText_BattleMon[] =
#ifdef CHINESE
    _("BATTLE {PKMN}"); //TODO 汉化
#else
    _("BATTLE {PKMN}");
#endif

const u8 gText_BattleSalon[] =
#ifdef CHINESE
    _("BATTLE SALON"); //TODO 汉化
#else
    _("BATTLE SALON");
#endif

const u8 gText_MultiLink2[] =
#ifdef CHINESE
    _("MULTI-LINK"); //TODO 汉化
#else
    _("MULTI-LINK");
#endif

const u8 gText_BattleRules[] =
#ifdef CHINESE
    _("BATTLE RULES"); //TODO 汉化
#else
    _("BATTLE RULES");
#endif

const u8 gText_JudgeMind[] =
#ifdef CHINESE
    _("JUDGE: MIND"); //TODO 汉化
#else
    _("JUDGE: MIND");
#endif

const u8 gText_JudgeSkill[] =
#ifdef CHINESE
    _("JUDGE: SKILL"); //TODO 汉化
#else
    _("JUDGE: SKILL");
#endif

const u8 gText_JudgeBody[] =
#ifdef CHINESE
    _("JUDGE: BODY"); //TODO 汉化
#else
    _("JUDGE: BODY");
#endif

const u8 gText_Matchup[] =
#ifdef CHINESE
    _("MATCHUP"); //TODO 汉化
#else
    _("MATCHUP");
#endif

const u8 gText_TourneyTree[] =
#ifdef CHINESE
    _("TOURNEY TREE"); //TODO 汉化
#else
    _("TOURNEY TREE");
#endif

const u8 gText_DoubleKO[] =
#ifdef CHINESE
    _("DOUBLE KO"); //TODO 汉化
#else
    _("DOUBLE KO");
#endif

const u8 gText_BasicRules[] =
#ifdef CHINESE
    _("BASIC RULES"); //TODO 汉化
#else
    _("BASIC RULES");
#endif

const u8 gText_SwapPartners[] =
#ifdef CHINESE
    _("SWAP: PARTNER"); //TODO 汉化
#else
    _("SWAP: PARTNER");
#endif

const u8 gText_SwapNumber[] =
#ifdef CHINESE
    _("SWAP: NUMBER"); //TODO 汉化
#else
    _("SWAP: NUMBER");
#endif

const u8 gText_SwapNotes[] =
#ifdef CHINESE
    _("SWAP: NOTES"); //TODO 汉化
#else
    _("SWAP: NOTES");
#endif

const u8 gText_OpenLevel3[] =
#ifdef CHINESE
    _("OPEN LEVEL"); //TODO 汉化
#else
    _("OPEN LEVEL");
#endif

const u8 gText_BattleBasics[] =
#ifdef CHINESE
    _("BATTLE BASICS"); //TODO 汉化
#else
    _("BATTLE BASICS");
#endif

const u8 gText_PokemonNature[] =
#ifdef CHINESE
    _("POKéMON NATURE"); //TODO 汉化
#else
    _("POKéMON NATURE");
#endif

const u8 gText_PokemonMoves[] =
#ifdef CHINESE
    _("POKéMON MOVES"); //TODO 汉化
#else
    _("POKéMON MOVES");
#endif

const u8 gText_Underpowered[] =
#ifdef CHINESE
    _("UNDERPOWERED"); //TODO 汉化
#else
    _("UNDERPOWERED");
#endif

const u8 gText_WhenInDanger[] =
#ifdef CHINESE
    _("WHEN IN DANGER"); //TODO 汉化
#else
    _("WHEN IN DANGER");
#endif

const u8 gText_PyramidPokemon[] =
#ifdef CHINESE
    _("PYRAMID: POKéMON"); //TODO 汉化
#else
    _("PYRAMID: POKéMON");
#endif

const u8 gText_PyramidTrainers[] =
#ifdef CHINESE
    _("PYRAMID: TRAINERS"); //TODO 汉化
#else
    _("PYRAMID: TRAINERS");
#endif

const u8 gText_PyramidMaze[] =
#ifdef CHINESE
    _("PYRAMID: MAZE"); //TODO 汉化
#else
    _("PYRAMID: MAZE");
#endif

const u8 gText_BattleBag2[] =
#ifdef CHINESE
    _("BATTLE BAG"); //TODO 汉化
#else
    _("BATTLE BAG");
#endif

const u8 gText_PokenavAndBag[] =
#ifdef CHINESE
    _("POKéNAV AND BAG"); //TODO 汉化
#else
    _("POKéNAV AND BAG");
#endif

const u8 gText_HeldItems[] =
#ifdef CHINESE
    _("HELD ITEMS"); //TODO 汉化
#else
    _("HELD ITEMS");
#endif

const u8 gText_PokemonOrder[] =
#ifdef CHINESE
    _("POKéMON ORDER"); //TODO 汉化
#else
    _("POKéMON ORDER");
#endif

const u8 gText_BattlePokemon[] =
#ifdef CHINESE
    _("BATTLE POKéMON"); //TODO 汉化
#else
    _("BATTLE POKéMON");
#endif

const u8 gText_BattleTrainers[] =
#ifdef CHINESE
    _("BATTLE TRAINERS"); //TODO 汉化
#else
    _("BATTLE TRAINERS");
#endif

const u8 gText_GoOn[] =
#ifdef CHINESE
    _("GO ON"); //TODO 汉化
#else
    _("GO ON");
#endif

const u8 gText_Record2[] =
#ifdef CHINESE
    _("RECORD"); //TODO 汉化
#else
    _("RECORD");
#endif

const u8 gText_Rest[] =
#ifdef CHINESE
    _("REST"); //TODO 汉化
#else
    _("REST");
#endif

const u8 gText_Retire[] =
#ifdef CHINESE
    _("RETIRE"); //TODO 汉化
#else
    _("RETIRE");
#endif

const u8 gText_99TimesPlus[] =
#ifdef CHINESE
    _("99 times +"); //TODO 汉化
#else
    _("99 times +");
#endif

const u8 gText_1MinutePlus[] =
#ifdef CHINESE
    _("1 minute +"); //TODO 汉化
#else
    _("1 minute +");
#endif

const u8 gText_SpaceSeconds[] =
#ifdef CHINESE
    _(" seconds"); //TODO 汉化
#else
    _("seconds");
#endif

const u8 gText_SpaceTimes[] =
#ifdef CHINESE
    _(" time(s)"); //TODO 汉化
#else
    _("time(s)");
#endif

const u8 gText_Dot[] =
#ifdef CHINESE
    _("."); // Unused //TODO 汉化
#else
    _("."); // Unused
#endif

const u8 gText_BigGuy[] =
#ifdef CHINESE
    _("Big guy"); //TODO 汉化
#else
    _("Big guy");
#endif

const u8 gText_BigGirl[] =
#ifdef CHINESE
    _("Big girl"); //TODO 汉化
#else
    _("Big girl");
#endif

const u8 gText_Son[] =
#ifdef CHINESE
    _("son"); //TODO 汉化
#else
    _("son");
#endif

const u8 gText_Daughter[] =
#ifdef CHINESE
    _("daughter"); //TODO 汉化
#else
    _("daughter");
#endif

const u8 gText_BlueFlute[] =
#ifdef CHINESE
    _("BLUE FLUTE"); //TODO 汉化
#else
    _("BLUE FLUTE");
#endif

const u8 gText_YellowFlute[] =
#ifdef CHINESE
    _("YELLOW FLUTE"); //TODO 汉化
#else
    _("YELLOW FLUTE");
#endif

const u8 gText_RedFlute[] =
#ifdef CHINESE
    _("RED FLUTE"); //TODO 汉化
#else
    _("RED FLUTE");
#endif

const u8 gText_WhiteFlute[] =
#ifdef CHINESE
    _("WHITE FLUTE"); //TODO 汉化
#else
    _("WHITE FLUTE");
#endif

const u8 gText_BlackFlute[] =
#ifdef CHINESE
    _("BLACK FLUTE"); //TODO 汉化
#else
    _("BLACK FLUTE");
#endif

const u8 gText_PrettyChair[] =
#ifdef CHINESE
    _("PRETTY CHAIR"); //TODO 汉化
#else
    _("PRETTY CHAIR");
#endif

const u8 gText_PrettyDesk[] =
#ifdef CHINESE
    _("PRETTY DESK"); //TODO 汉化
#else
    _("PRETTY DESK");
#endif

const u8 gText_1F[] =
#ifdef CHINESE
    _("1F"); //TODO 汉化
#else
    _("1F");
#endif

const u8 gText_2F[] =
#ifdef CHINESE
    _("2F"); //TODO 汉化
#else
    _("2F");
#endif

const u8 gText_3F[] =
#ifdef CHINESE
    _("3F"); //TODO 汉化
#else
    _("3F");
#endif

const u8 gText_4F[] =
#ifdef CHINESE
    _("4F"); //TODO 汉化
#else
    _("4F");
#endif

const u8 gText_5F[] =
#ifdef CHINESE
    _("5F"); //TODO 汉化
#else
    _("5F");
#endif

const u8 gText_6F[] =
#ifdef CHINESE
    _("6F"); //TODO 汉化
#else
    _("6F");
#endif

const u8 gText_7F[] =
#ifdef CHINESE
    _("7F"); //TODO 汉化
#else
    _("7F");
#endif

const u8 gText_8F[] =
#ifdef CHINESE
    _("8F"); //TODO 汉化
#else
    _("8F");
#endif

const u8 gText_9F[] =
#ifdef CHINESE
    _("9F"); //TODO 汉化
#else
    _("9F");
#endif

const u8 gText_10F[] =
#ifdef CHINESE
    _("10F"); //TODO 汉化
#else
    _("10F");
#endif

const u8 gText_11F[] =
#ifdef CHINESE
    _("11F"); //TODO 汉化
#else
    _("11F");
#endif

const u8 gText_B1F[] =
#ifdef CHINESE
    _("B1F"); //TODO 汉化
#else
    _("B1F");
#endif

const u8 gText_B2F[] =
#ifdef CHINESE
    _("B2F"); //TODO 汉化
#else
    _("B2F");
#endif

const u8 gText_B3F[] =
#ifdef CHINESE
    _("B3F"); //TODO 汉化
#else
    _("B3F");
#endif

const u8 gText_B4F[] =
#ifdef CHINESE
    _("B4F"); //TODO 汉化
#else
    _("B4F");
#endif

const u8 gText_Rooftop[] =
#ifdef CHINESE
    _("ROOFTOP"); //TODO 汉化
#else
    _("ROOFTOP");
#endif

const u8 gText_ElevatorNowOn[] =
#ifdef CHINESE
    _("Now on:"); //TODO 汉化
#else
    _("Now on:");
#endif

const u8 gText_BP[] =
#ifdef CHINESE
    _("BP"); //TODO 汉化
#else
    _("BP");
#endif

const u8 gText_EnergyPowder50[] =
#ifdef CHINESE
    _("ENERGYPOWDER{CLEAR_TO 0x72}{SIZE 0}50"); //TODO 汉化
#else
    _("ENERGYPOWDER{CLEAR_TO 0x72}{SIZE 0}50");
#endif

const u8 gText_EnergyRoot80[] =
#ifdef CHINESE
    _("ENERGY ROOT{CLEAR_TO 0x72}{SIZE 0}80"); //TODO 汉化
#else
    _("ENERGY ROOT{CLEAR_TO 0x72}{SIZE 0}80");
#endif

const u8 gText_HealPowder50[] =
#ifdef CHINESE
    _("HEAL POWDER{CLEAR_TO 0x72}{SIZE 0}50"); //TODO 汉化
#else
    _("HEAL POWDER{CLEAR_TO 0x72}{SIZE 0}50");
#endif

const u8 gText_RevivalHerb300[] =
#ifdef CHINESE
    _("REVIVAL HERB{CLEAR_TO 0x6C}{SIZE 0}300"); //TODO 汉化
#else
    _("REVIVAL HERB{CLEAR_TO 0x6C}{SIZE 0}300");
#endif

const u8 gText_Protein1000[] =
#ifdef CHINESE
    _("PROTEIN{CLEAR_TO 0x63}{SIZE 0}1,000"); //TODO 汉化
#else
    _("PROTEIN{CLEAR_TO 0x63}{SIZE 0}1,000");
#endif

const u8 gText_Iron1000[] =
#ifdef CHINESE
    _("IRON{CLEAR_TO 0x63}{SIZE 0}1,000"); //TODO 汉化
#else
    _("IRON{CLEAR_TO 0x63}{SIZE 0}1,000");
#endif

const u8 gText_Carbos1000[] =
#ifdef CHINESE
    _("CARBOS{CLEAR_TO 0x63}{SIZE 0}1,000"); //TODO 汉化
#else
    _("CARBOS{CLEAR_TO 0x63}{SIZE 0}1,000");
#endif

const u8 gText_Calcium1000[] =
#ifdef CHINESE
    _("CALCIUM{CLEAR_TO 0x63}{SIZE 0}1,000"); //TODO 汉化
#else
    _("CALCIUM{CLEAR_TO 0x63}{SIZE 0}1,000");
#endif

const u8 gText_Zinc1000[] =
#ifdef CHINESE
    _("ZINC{CLEAR_TO 0x63}{SIZE 0}1,000"); //TODO 汉化
#else
    _("ZINC{CLEAR_TO 0x63}{SIZE 0}1,000");
#endif

const u8 gText_HPUp1000[] =
#ifdef CHINESE
    _("HP UP{CLEAR_TO 0x63}{SIZE 0}1,000"); //TODO 汉化
#else
    _("HP UP{CLEAR_TO 0x63}{SIZE 0}1,000");
#endif

const u8 gText_PPUp3000[] =
#ifdef CHINESE
    _("PP UP{CLEAR_TO 0x63}{SIZE 0}3,000"); //TODO 汉化
#else
    _("PP UP{CLEAR_TO 0x63}{SIZE 0}3,000");
#endif

const u8 gText_RankingHall[] =
#ifdef CHINESE
    _("RANKING HALL"); //TODO 汉化
#else
    _("RANKING HALL");
#endif

const u8 gText_ExchangeService[] =
#ifdef CHINESE
    _("EXCHANGE SERVICE"); //TODO 汉化
#else
    _("EXCHANGE SERVICE");
#endif

const u8 gText_LilycoveCity[] =
#ifdef CHINESE
    _("LILYCOVE CITY"); //TODO 汉化
#else
    _("LILYCOVE CITY");
#endif

const u8 gText_SlateportCity[] =
#ifdef CHINESE
    _("SLATEPORT CITY"); //TODO 汉化
#else
    _("SLATEPORT CITY");
#endif

const u8 gText_CaveOfOrigin[] =
#ifdef CHINESE
    _("CAVE OF ORIGIN"); //TODO 汉化
#else
    _("CAVE OF ORIGIN");
#endif

const u8 gText_MtPyre[] =
#ifdef CHINESE
    _("MT. PYRE"); //TODO 汉化
#else
    _("MT. PYRE");
#endif

const u8 gText_SkyPillar[] =
#ifdef CHINESE
    _("SKY PILLAR"); //TODO 汉化
#else
    _("SKY PILLAR");
#endif

const u8 gText_DontRemember[] =
#ifdef CHINESE
    _("Don't remember"); //TODO 汉化
#else
    _("Don't remember");
#endif

const u8 gText_Exit[] =
#ifdef CHINESE
    _("EXIT"); //TODO 汉化
#else
    _("EXIT");
#endif

const u8 gText_ExitFromBox[] =
#ifdef CHINESE
    _("Exit from the BOX?"); //TODO 汉化
#else
    _("Exit from the BOX?");
#endif

const u8 gText_WhatDoYouWantToDo[] =
#ifdef CHINESE
    _("What do you want to do?"); //TODO 汉化
#else
    _("What do you want to do?");
#endif

const u8 gText_PleasePickATheme[] =
#ifdef CHINESE
    _("Please pick a theme."); //TODO 汉化
#else
    _("Please pick a theme.");
#endif

const u8 gText_PickTheWallpaper[] =
#ifdef CHINESE
    _("Pick the wallpaper."); //TODO 汉化
#else
    _("Pick the wallpaper.");
#endif

const u8 gText_PkmnIsSelected[] =
#ifdef CHINESE
    _("{DYNAMIC 0} is selected."); //TODO 汉化
#else
    _("{DYNAMIC 0} is selected.");
#endif

const u8 gText_JumpToWhichBox[] =
#ifdef CHINESE
    _("Jump to which BOX?"); //TODO 汉化
#else
    _("Jump to which BOX?");
#endif

const u8 gText_DepositInWhichBox[] =
#ifdef CHINESE
    _("Deposit in which BOX?"); //TODO 汉化
#else
    _("Deposit in which BOX?");
#endif

const u8 gText_PkmnWasDeposited[] =
#ifdef CHINESE
    _("{DYNAMIC 0} was deposited."); //TODO 汉化
#else
    _("{DYNAMIC 0} was deposited.");
#endif

const u8 gText_BoxIsFull2[] =
#ifdef CHINESE
    _("The BOX is full."); //TODO 汉化
#else
    _("The BOX is full.");
#endif

const u8 gText_ReleaseThisPokemon[] =
#ifdef CHINESE
    _("Release this POKéMON?"); //TODO 汉化
#else
    _("Release this POKéMON?");
#endif

const u8 gText_PkmnWasReleased[] =
#ifdef CHINESE
    _("{DYNAMIC 0} was released."); //TODO 汉化
#else
    _("{DYNAMIC 0} was released.");
#endif

const u8 gText_ByeByePkmn[] =
#ifdef CHINESE
    _("Bye-bye, {DYNAMIC 0}!"); //TODO 汉化
#else
    _("Bye-bye, {DYNAMIC 0}!");
#endif

const u8 gText_MarkYourPkmn[] =
#ifdef CHINESE
    _("Mark your POKéMON."); //TODO 汉化
#else
    _("Mark your POKéMON.");
#endif

const u8 gText_ThatsYourLastPkmn[] =
#ifdef CHINESE
    _("That's your last POKéMON!"); //TODO 汉化
#else
    _("That's your last POKéMON!");
#endif

const u8 gText_YourPartysFull[] =
#ifdef CHINESE
    _("Your party's full!"); //TODO 汉化
#else
    _("Your party's full!");
#endif

const u8 gText_YoureHoldingAPkmn[] =
#ifdef CHINESE
    _("You're holding a POKéMON!"); //TODO 汉化
#else
    _("You're holding a POKéMON!");
#endif

const u8 gText_WhichOneWillYouTake[] =
#ifdef CHINESE
    _("Which one will you take?"); //TODO 汉化
#else
    _("Which one will you take?");
#endif

const u8 gText_YouCantReleaseAnEgg[] =
#ifdef CHINESE
    _("You can't release an EGG."); //TODO 汉化
#else
    _("You can't release an EGG.");
#endif

const u8 gText_ContinueBoxOperations[] =
#ifdef CHINESE
    _("Continue BOX operations?"); //TODO 汉化
#else
    _("Continue BOX operations?");
#endif

const u8 gText_PkmnCameBack[] =
#ifdef CHINESE
    _("{DYNAMIC 0} came back!"); //TODO 汉化
#else
    _("{DYNAMIC 0} came back!");
#endif

const u8 gText_WasItWorriedAboutYou[] =
#ifdef CHINESE
    _("Was it worried about you?"); //TODO 汉化
#else
    _("Was it worried about you?");
#endif

const u8 gText_FourEllipsesExclamation[] =
#ifdef CHINESE
    _("… … … … !"); //TODO 汉化
#else
    _("… … … … !");
#endif

const u8 gText_PleaseRemoveTheMail[] =
#ifdef CHINESE
    _("Please remove the MAIL."); //TODO 汉化
#else
    _("Please remove the MAIL.");
#endif

const u8 gText_GiveToAPkmn[] =
#ifdef CHINESE
    _("GIVE to a POKéMON?"); //TODO 汉化
#else
    _("GIVE to a POKéMON?");
#endif

const u8 gText_PlacedItemInBag[] =
#ifdef CHINESE
    _("Placed item in the BAG."); //TODO 汉化
#else
    _("Placed item in the BAG.");
#endif

const u8 gText_BagIsFull2[] =
#ifdef CHINESE
    _("The BAG is full."); //TODO 汉化
#else
    _("The BAG is full.");
#endif

const u8 gText_PutItemInBag[] =
#ifdef CHINESE
    _("Put this item in the BAG?"); //TODO 汉化
#else
    _("Put this item in the BAG?");
#endif

const u8 gText_ItemIsNowHeld[] =
#ifdef CHINESE
    _("{DYNAMIC 0} is now held."); //TODO 汉化
#else
    _("{DYNAMIC 0} is now held.");
#endif

const u8 gText_ChangedToNewItem[] =
#ifdef CHINESE
    _("Changed to {DYNAMIC 0}."); //TODO 汉化
#else
    _("Changed to {DYNAMIC 0}.");
#endif

const u8 gText_MailCantBeStored[] =
#ifdef CHINESE
    _("MAIL can't be stored!"); //TODO 汉化
#else
    _("MAIL can't be stored!");
#endif

const u8 gPCText_Cancel[] =
#ifdef CHINESE
    _("CANCEL"); //TODO 汉化
#else
    _("CANCEL");
#endif

const u8 gPCText_Store[] =
#ifdef CHINESE
    _("STORE"); //TODO 汉化
#else
    _("STORE");
#endif

const u8 gPCText_Withdraw[] =
#ifdef CHINESE
    _("WITHDRAW"); //TODO 汉化
#else
    _("WITHDRAW");
#endif

const u8 gPCText_Shift[] =
#ifdef CHINESE
    _("SHIFT"); //TODO 汉化
#else
    _("SHIFT");
#endif

const u8 gPCText_Move[] =
#ifdef CHINESE
    _("MOVE"); //TODO 汉化
#else
    _("MOVE");
#endif

const u8 gPCText_Place[] =
#ifdef CHINESE
    _("PLACE"); //TODO 汉化
#else
    _("PLACE");
#endif

const u8 gPCText_Summary[] =
#ifdef CHINESE
    _("SUMMARY"); //TODO 汉化
#else
    _("SUMMARY");
#endif

const u8 gPCText_Release[] =
#ifdef CHINESE
    _("RELEASE"); //TODO 汉化
#else
    _("RELEASE");
#endif

const u8 gPCText_Mark[] =
#ifdef CHINESE
    _("MARK"); //TODO 汉化
#else
    _("MARK");
#endif

const u8 gPCText_Name[] =
#ifdef CHINESE
    _("NAME"); //TODO 汉化
#else
    _("NAME");
#endif

const u8 gPCText_Jump[] =
#ifdef CHINESE
    _("JUMP"); //TODO 汉化
#else
    _("JUMP");
#endif

const u8 gPCText_Wallpaper[] =
#ifdef CHINESE
    _("WALLPAPER"); //TODO 汉化
#else
    _("WALLPAPER");
#endif

const u8 gPCText_Take[] =
#ifdef CHINESE
    _("TAKE"); //TODO 汉化
#else
    _("TAKE");
#endif

const u8 gPCText_Give[] =
#ifdef CHINESE
    _("GIVE"); //TODO 汉化
#else
    _("GIVE");
#endif

const u8 gPCText_Switch[] =
#ifdef CHINESE
    _("SWITCH"); //TODO 汉化
#else
    _("SWITCH");
#endif

const u8 gPCText_Bag[] =
#ifdef CHINESE
    _("BAG"); //TODO 汉化
#else
    _("BAG");
#endif

const u8 gPCText_Info[] =
#ifdef CHINESE
    _("INFO"); //TODO 汉化
#else
    _("INFO");
#endif

const u8 gPCText_Scenery1[] =
#ifdef CHINESE
    _("SCENERY 1"); //TODO 汉化
#else
    _("SCENERY 1");
#endif

const u8 gPCText_Scenery2[] =
#ifdef CHINESE
    _("SCENERY 2"); //TODO 汉化
#else
    _("SCENERY 2");
#endif

const u8 gPCText_Scenery3[] =
#ifdef CHINESE
    _("SCENERY 3"); //TODO 汉化
#else
    _("SCENERY 3");
#endif

const u8 gPCText_Etcetera[] =
#ifdef CHINESE
    _("ETCETERA"); //TODO 汉化
#else
    _("ETCETERA");
#endif

const u8 gPCText_Friends[] =
#ifdef CHINESE
    _("FRIENDS"); //TODO 汉化
#else
    _("FRIENDS");
#endif

const u8 gPCText_Forest[] =
#ifdef CHINESE
    _("FOREST"); //TODO 汉化
#else
    _("FOREST");
#endif

const u8 gPCText_City[] =
#ifdef CHINESE
    _("CITY"); //TODO 汉化
#else
    _("CITY");
#endif

const u8 gPCText_Desert[] =
#ifdef CHINESE
    _("DESERT"); //TODO 汉化
#else
    _("DESERT");
#endif

const u8 gPCText_Savanna[] =
#ifdef CHINESE
    _("SAVANNA"); //TODO 汉化
#else
    _("SAVANNA");
#endif

const u8 gPCText_Crag[] =
#ifdef CHINESE
    _("CRAG"); //TODO 汉化
#else
    _("CRAG");
#endif

const u8 gPCText_Volcano[] =
#ifdef CHINESE
    _("VOLCANO"); //TODO 汉化
#else
    _("VOLCANO");
#endif

const u8 gPCText_Snow[] =
#ifdef CHINESE
    _("SNOW"); //TODO 汉化
#else
    _("SNOW");
#endif

const u8 gPCText_Cave[] =
#ifdef CHINESE
    _("CAVE"); //TODO 汉化
#else
    _("CAVE");
#endif

const u8 gPCText_Beach[] =
#ifdef CHINESE
    _("BEACH"); //TODO 汉化
#else
    _("BEACH");
#endif

const u8 gPCText_Seafloor[] =
#ifdef CHINESE
    _("SEAFLOOR"); //TODO 汉化
#else
    _("SEAFLOOR");
#endif

const u8 gPCText_River[] =
#ifdef CHINESE
    _("RIVER"); //TODO 汉化
#else
    _("RIVER");
#endif

const u8 gPCText_Sky[] =
#ifdef CHINESE
    _("SKY"); //TODO 汉化
#else
    _("SKY");
#endif

const u8 gPCText_PolkaDot[] =
#ifdef CHINESE
    _("POLKA-DOT"); //TODO 汉化
#else
    _("POLKA-DOT");
#endif

const u8 gPCText_Pokecenter[] =
#ifdef CHINESE
    _("POKéCENTER"); //TODO 汉化
#else
    _("POKéCENTER");
#endif

const u8 gPCText_Machine[] =
#ifdef CHINESE
    _("MACHINE"); //TODO 汉化
#else
    _("MACHINE");
#endif

const u8 gPCText_Simple[] =
#ifdef CHINESE
    _("SIMPLE"); //TODO 汉化
#else
    _("SIMPLE");
#endif

const u8 gText_WhatWouldYouLikeToDo[] =
#ifdef CHINESE
    _("What would you like to do?"); // Unused //TODO 汉化
#else
    _("What would you like to do?"); // Unused
#endif

const u8 gText_WithdrawPokemon[] =
#ifdef CHINESE
    _("WITHDRAW POKéMON"); //TODO 汉化
#else
    _("WITHDRAW POKéMON");
#endif

const u8 gText_DepositPokemon[] =
#ifdef CHINESE
    _("DEPOSIT POKéMON"); //TODO 汉化
#else
    _("DEPOSIT POKéMON");
#endif

const u8 gText_MovePokemon[] =
#ifdef CHINESE
    _("MOVE POKéMON"); //TODO 汉化
#else
    _("MOVE POKéMON");
#endif

const u8 gText_MoveItems[] =
#ifdef CHINESE
    _("MOVE ITEMS"); //TODO 汉化
#else
    _("MOVE ITEMS");
#endif

const u8 gText_SeeYa[] =
#ifdef CHINESE
    _("SEE YA!"); //TODO 汉化
#else
    _("SEE YA!");
#endif

const u8 gText_WithdrawMonDescription[] =
#ifdef CHINESE
    _("Move POKéMON stored in BOXES to\nyour party."); //TODO 汉化
#else
    _("Move POKéMON stored in BOXES to\nyour party.");
#endif

const u8 gText_DepositMonDescription[] =
#ifdef CHINESE
    _("Store POKéMON in your party in BOXES."); //TODO 汉化
#else
    _("Store POKéMON in your party in BOXES.");
#endif

const u8 gText_MoveMonDescription[] =
#ifdef CHINESE
    _("Organize the POKéMON in BOXES and\nin your party."); //TODO 汉化
#else
    _("Organize the POKéMON in BOXES and\nin your party.");
#endif

const u8 gText_MoveItemsDescription[] =
#ifdef CHINESE
    _("Move items held by any POKéMON\nin a BOX or your party."); //TODO 汉化
#else
    _("Move items held by any POKéMON\nin a BOX or your party.");
#endif

const u8 gText_SeeYaDescription[] =
#ifdef CHINESE
    _("Return to the previous menu."); //TODO 汉化
#else
    _("Return to the previous menu.");
#endif

const u8 gText_JustOnePkmn[] =
#ifdef CHINESE
    _("There is just one POKéMON with you."); //TODO 汉化
#else
    _("There is just one POKéMON with you.");
#endif

const u8 gText_PartyFull[] =
#ifdef CHINESE
    _("Your party is full!"); //TODO 汉化
#else
    _("Your party is full!");
#endif

const u8 gText_Box[] =
#ifdef CHINESE
    _("BOX"); //TODO 汉化
#else
    _("BOX");
#endif

const u8 gText_CheckMapOfHoenn[] =
#ifdef CHINESE
    _("Check the map of the HOENN region."); //TODO 汉化
#else
    _("Check the map of the HOENN region.");
#endif

const u8 gText_CheckPokemonInDetail[] =
#ifdef CHINESE
    _("Check POKéMON in detail."); //TODO 汉化
#else
    _("Check POKéMON in detail.");
#endif

const u8 gText_CallRegisteredTrainer[] =
#ifdef CHINESE
    _("Call a registered TRAINER."); //TODO 汉化
#else
    _("Call a registered TRAINER.");
#endif

const u8 gText_CheckObtainedRibbons[] =
#ifdef CHINESE
    _("Check obtained RIBBONS."); //TODO 汉化
#else
    _("Check obtained RIBBONS.");
#endif

const u8 gText_PutAwayPokenav[] =
#ifdef CHINESE
    _("Put away the POKéNAV."); //TODO 汉化
#else
    _("Put away the POKéNAV.");
#endif

const u8 gText_NoRibbonWinners[] =
#ifdef CHINESE
    _("There are no RIBBON winners."); //TODO 汉化
#else
    _("There are no RIBBON winners.");
#endif

const u8 gText_NoTrainersRegistered[] =
#ifdef CHINESE
    _("No TRAINERS are registered."); // Unused //TODO 汉化
#else
    _("No TRAINERS are registered."); // Unused
#endif

const u8 gText_CheckPartyPokemonInDetail[] =
#ifdef CHINESE
    _("Check party POKéMON in detail."); //TODO 汉化
#else
    _("Check party POKéMON in detail.");
#endif

const u8 gText_CheckAllPokemonInDetail[] =
#ifdef CHINESE
    _("Check all POKéMON in detail."); //TODO 汉化
#else
    _("Check all POKéMON in detail.");
#endif

const u8 gText_ReturnToPokenavMenu[] =
#ifdef CHINESE
    _("Return to the POKéNAV menu."); //TODO 汉化
#else
    _("Return to the POKéNAV menu.");
#endif

const u8 gText_FindCoolPokemon[] =
#ifdef CHINESE
    _("Find cool POKéMON."); //TODO 汉化
#else
    _("Find cool POKéMON.");
#endif

const u8 gText_FindBeautifulPokemon[] =
#ifdef CHINESE
    _("Find beautiful POKéMON."); //TODO 汉化
#else
    _("Find beautiful POKéMON.");
#endif

const u8 gText_FindCutePokemon[] =
#ifdef CHINESE
    _("Find cute POKéMON."); //TODO 汉化
#else
    _("Find cute POKéMON.");
#endif

const u8 gText_FindSmartPokemon[] =
#ifdef CHINESE
    _("Find smart POKéMON."); //TODO 汉化
#else
    _("Find smart POKéMON.");
#endif

const u8 gText_FindToughPokemon[] =
#ifdef CHINESE
    _("Find tough POKéMON."); //TODO 汉化
#else
    _("Find tough POKéMON.");
#endif

const u8 gText_ReturnToConditionMenu[] =
#ifdef CHINESE
    _("Return to the CONDITION menu."); //TODO 汉化
#else
    _("Return to the CONDITION menu.");
#endif

const u8 gText_NumberRegistered[] =
#ifdef CHINESE
    _("No. registered"); //TODO 汉化
#else
    _("No. registered");
#endif

const u8 gText_NumberOfBattles[] =
#ifdef CHINESE
    _("No. of battles"); //TODO 汉化
#else
    _("No. of battles");
#endif

const u8 gText_Detail[] =
#ifdef CHINESE
    _("DETAIL"); // Unused //TODO 汉化
#else
    _("DETAIL");                    // Unused
#endif

const u8 gText_Call2[] =
#ifdef CHINESE
    _("CALL"); // Unused //TODO 汉化
#else
    _("CALL");                      // Unused
#endif

const u8 gText_UnusedExit[] =
#ifdef CHINESE
    _("EXIT"); // Unused //TODO 汉化
#else
    _("EXIT");                      // Unused
#endif

const u8 gText_CantCallOpponentHere[] =
#ifdef CHINESE
    _("Can't call opponent here."); // Unused //TODO 汉化
#else
    _("Can't call opponent here."); // Unused
#endif

const u8 gText_PokenavMatchCall_Strategy[] =
#ifdef CHINESE
    _("STRATEGY"); //TODO 汉化
#else
    _("STRATEGY");
#endif

const u8 gText_PokenavMatchCall_TrainerPokemon[] =
#ifdef CHINESE
    _("TRAINER'S POKéMON"); //TODO 汉化
#else
    _("TRAINER'S POKéMON");
#endif

const u8 gText_PokenavMatchCall_SelfIntroduction[] =
#ifdef CHINESE
    _("SELF-INTRODUCTION"); //TODO 汉化
#else
    _("SELF-INTRODUCTION");
#endif

const u8 gText_Pokenav_ClearButtonList[] =
#ifdef CHINESE
    _("{CLEAR 0x80}"); //TODO 汉化
#else
    _("{CLEAR 0x80}");
#endif

const u8 gText_PokenavMap_ZoomedOutButtons[] =
#ifdef CHINESE
    _("{A_BUTTON}ZOOM {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{A_BUTTON}ZOOM {B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavMap_ZoomedInButtons[] =
#ifdef CHINESE
    _("{A_BUTTON}FULL {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{A_BUTTON}FULL {B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavCondition_MonListButtons[] =
#ifdef CHINESE
    _("{A_BUTTON}CONDITION {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{A_BUTTON}CONDITION {B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavCondition_MonStatusButtons[] =
#ifdef CHINESE
    _("{A_BUTTON}MARKINGS {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{A_BUTTON}MARKINGS {B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavCondition_MarkingButtons[] =
#ifdef CHINESE
    _("{A_BUTTON}SELECT MARK {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{A_BUTTON}SELECT MARK {B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavMatchCall_TrainerListButtons[] =
#ifdef CHINESE
    _("{A_BUTTON}MENU {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{A_BUTTON}MENU {B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavMatchCall_CallMenuButtons[] =
#ifdef CHINESE
    _("{A_BUTTON}OK {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{A_BUTTON}OK {B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavMatchCall_CheckTrainerButtons[] =
#ifdef CHINESE
    _("{B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavRibbons_MonListButtons[] =
#ifdef CHINESE
    _("{A_BUTTON}RIBBONS {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{A_BUTTON}RIBBONS {B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavRibbons_RibbonListButtons[] =
#ifdef CHINESE
    _("{A_BUTTON}CHECK {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{A_BUTTON}CHECK {B_BUTTON}CANCEL");
#endif

const u8 gText_PokenavRibbons_RibbonCheckButtons[] =
#ifdef CHINESE
    _("{B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{B_BUTTON}CANCEL");
#endif

const u8 gText_NatureSlash[] =
#ifdef CHINESE
    _("NATURE/"); //TODO 汉化
#else
    _("NATURE/");
#endif

const u8 gText_TrainerCloseBy[] =
#ifdef CHINESE
    _("That TRAINER is close by.\nTalk to the TRAINER in person!"); //TODO 汉化
#else
    _("That TRAINER is close by.\nTalk to the TRAINER in person!");
#endif

const u8 gText_InParty[] =
#ifdef CHINESE
    _("IN PARTY"); //TODO 汉化
#else
    _("IN PARTY");
#endif

const u8 gText_Number2[] =
#ifdef CHINESE
    _("No. "); //TODO 汉化
#else
    _("No. ");
#endif

const u8 gText_Ribbons[] =
#ifdef CHINESE
    _("RIBBONS"); // Unused //TODO 汉化
#else
    _("RIBBONS");                                                                                                                        // Unused
#endif

const u8 gText_PokemonMaleLv[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}"); // Unused //TODO 汉化
#else
    _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}");  // Unused
#endif

const u8 gText_PokemonFemaleLv[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}"); // Unused //TODO 汉化
#else
    _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}"); // Unused
#endif

const u8 gText_PokemonNoGenderLv[] =
#ifdef CHINESE
    _("{DYNAMIC 0}/{LV}{DYNAMIC 1}"); // Unused //TODO 汉化
#else
    _("{DYNAMIC 0}/{LV}{DYNAMIC 1}");                                                                                                    // Unused
#endif

const u8 gText_Unknown[] =
#ifdef CHINESE
    _("UNKNOWN"); //TODO 汉化
#else
    _("UNKNOWN");
#endif

const u8 gText_Call[] =
#ifdef CHINESE
    _("CALL"); //TODO 汉化
#else
    _("CALL");
#endif

const u8 gText_Check[] =
#ifdef CHINESE
    _("CHECK"); //TODO 汉化
#else
    _("CHECK");
#endif

const u8 gText_Cancel6[] =
#ifdef CHINESE
    _("CANCEL"); //TODO 汉化
#else
    _("CANCEL");
#endif

const u8 gText_NumberF700[] =
#ifdef CHINESE
    _("No. {DYNAMIC 0}"); //TODO 汉化
#else
    _("No. {DYNAMIC 0}");
#endif

const u8 gText_RibbonsF700[] =
#ifdef CHINESE
    _("RIBBONS {DYNAMIC 0}"); //TODO 汉化
#else
    _("RIBBONS {DYNAMIC 0}");
#endif

const u8 gText_PokemonMaleLv2[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused //TODO 汉化
#else
    _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}");  // Unused
#endif

const u8 gText_PokemonFemaleLv2[] =
#ifdef CHINESE
    _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused //TODO 汉化
#else
    _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
#endif

const u8 gText_PokemonNoGenderLv2[] =
#ifdef CHINESE
    _("{DYNAMIC 0}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused //TODO 汉化
#else
    _("{DYNAMIC 0}/{LV}{DYNAMIC 1}{DYNAMIC 2}");                                                                                                    // Unused
#endif

const u8 gText_CombineFourWordsOrPhrases[] =
#ifdef CHINESE
    _("Combine four words or phrases"); //TODO 汉化
#else
    _("Combine four words or phrases");
#endif

const u8 gText_AndMakeYourProfile[] =
#ifdef CHINESE
    _("and make your profile."); //TODO 汉化
#else
    _("and make your profile.");
#endif

const u8 gText_CombineSixWordsOrPhrases[] =
#ifdef CHINESE
    _("Combine six words or phrases"); //TODO 汉化
#else
    _("Combine six words or phrases");
#endif

const u8 gText_AndMakeAMessage[] =
#ifdef CHINESE
    _("and make a message."); //TODO 汉化
#else
    _("and make a message.");
#endif

const u8 gText_FindWordsThatDescribeYour[] =
#ifdef CHINESE
    _("Find words that describe your"); //TODO 汉化
#else
    _("Find words that describe your");
#endif

const u8 gText_FeelingsRightNow[] =
#ifdef CHINESE
    _("feelings right now."); //TODO 汉化
#else
    _("feelings right now.");
#endif

const u8 gText_WithFourPhrases[] =
#ifdef CHINESE
    _("With four phrases,"); // Unused //TODO 汉化
#else
    _("With four phrases,"); // Unused
#endif

const u8 gText_CombineNineWordsOrPhrases[] =
#ifdef CHINESE
    _("Combine nine words or phrases"); //TODO 汉化
#else
    _("Combine nine words or phrases");
#endif

const u8 gText_AndMakeAMessage2[] =
#ifdef CHINESE
    _("and make a message."); //TODO 汉化
#else
    _("and make a message.");
#endif

const u8 gText_ChangeJustOneWordOrPhrase[] =
#ifdef CHINESE
    _("Change just one word or phrase"); //TODO 汉化
#else
    _("Change just one word or phrase");
#endif

const u8 gText_AndImproveTheBardsSong[] =
#ifdef CHINESE
    _("and improve the BARD's song."); //TODO 汉化
#else
    _("and improve the BARD's song.");
#endif

const u8 gText_YourProfile[] =
#ifdef CHINESE
    _("Your profile"); //TODO 汉化
#else
    _("Your profile");
#endif

const u8 gText_YourFeelingAtTheBattlesStart[] =
#ifdef CHINESE
    _("Your feeling at the battle's start"); //TODO 汉化
#else
    _("Your feeling at the battle's start");
#endif

const u8 gText_WhatYouSayIfYouWin[] =
#ifdef CHINESE
    _("What you say if you win a battle"); //TODO 汉化
#else
    _("What you say if you win a battle");
#endif

const u8 gText_WhatYouSayIfYouLose[] =
#ifdef CHINESE
    _("What you say if you lose a battle"); //TODO 汉化
#else
    _("What you say if you lose a battle");
#endif

const u8 gText_TheAnswer[] =
#ifdef CHINESE
    _("The answer"); //TODO 汉化
#else
    _("The answer");
#endif

const u8 gText_TheMailMessage[] =
#ifdef CHINESE
    _("The MAIL message"); //TODO 汉化
#else
    _("The MAIL message");
#endif

const u8 gText_TheMailSalutation[] =
#ifdef CHINESE
    _("The MAIL salutation"); // Unused //TODO 汉化
#else
    _("The MAIL salutation"); // Unused
#endif

const u8 gText_TheBardsSong2[] =
#ifdef CHINESE
    _("The new song"); //TODO 汉化
#else
    _("The new song");
#endif

const u8 gText_CombineTwoWordsOrPhrases[] =
#ifdef CHINESE
    _("Combine two words or phrases"); //TODO 汉化
#else
    _("Combine two words or phrases");
#endif

const u8 gText_AndMakeATrendySaying[] =
#ifdef CHINESE
    _("and make a trendy saying."); //TODO 汉化
#else
    _("and make a trendy saying.");
#endif

const u8 gText_TheTrendySaying[] =
#ifdef CHINESE
    _("The trendy saying"); //TODO 汉化
#else
    _("The trendy saying");
#endif

const u8 gText_IsAsShownOkay[] =
#ifdef CHINESE
    _("is as shown. Okay?"); //TODO 汉化
#else
    _("is as shown. Okay?");
#endif

const u8 gText_CombineTwoWordsOrPhrases2[] =
#ifdef CHINESE
    _("Combine two words or phrases"); //TODO 汉化
#else
    _("Combine two words or phrases");
#endif

const u8 gText_ToTeachHerAGoodSaying[] =
#ifdef CHINESE
    _("to teach her a good saying."); //TODO 汉化
#else
    _("to teach her a good saying.");
#endif

const u8 gText_FindWordsWhichFit[] =
#ifdef CHINESE
    _("Find words which fit"); //TODO 汉化
#else
    _("Find words which fit");
#endif

const u8 gText_TheTrainersImage[] =
#ifdef CHINESE
    _("the TRAINER's image."); //TODO 汉化
#else
    _("the TRAINER's image.");
#endif

const u8 gText_TheImage[] =
#ifdef CHINESE
    _("The image:"); //TODO 汉化
#else
    _("The image:");
#endif

const u8 gText_OutOfTheListedChoices[] =
#ifdef CHINESE
    _("Out of the listed choices,"); //TODO 汉化
#else
    _("Out of the listed choices,");
#endif

const u8 gText_SelectTheAnswerToTheQuiz[] =
#ifdef CHINESE
    _("select the answer to the quiz!"); //TODO 汉化
#else
    _("select the answer to the quiz!");
#endif

const u8 gText_AndCreateAQuiz[] =
#ifdef CHINESE
    _("and create a quiz!"); //TODO 汉化
#else
    _("and create a quiz!");
#endif

const u8 gText_PickAWordOrPhraseAnd[] =
#ifdef CHINESE
    _("Pick a word or phrase and"); //TODO 汉化
#else
    _("Pick a word or phrase and");
#endif

const u8 gText_SetTheQuizAnswer[] =
#ifdef CHINESE
    _("set the quiz answer."); //TODO 汉化
#else
    _("set the quiz answer.");
#endif

const u8 gText_TheAnswerColon[] =
#ifdef CHINESE
    _("The answer:"); //TODO 汉化
#else
    _("The answer:");
#endif

const u8 gText_TheQuizColon[] =
#ifdef CHINESE
    _("The quiz:"); // Unused //TODO 汉化
#else
    _("The quiz:"); // Unused
#endif

const u8 gText_ApprenticePhrase[] =
#ifdef CHINESE
    _("Apprentice's phrase:"); //TODO 汉化
#else
    _("Apprentice's phrase:");
#endif

const u8 gText_QuitEditing[] =
#ifdef CHINESE
    _("Quit editing?"); //TODO 汉化
#else
    _("Quit editing?");
#endif

const u8 gText_StopGivingPkmnMail[] =
#ifdef CHINESE
    _("Stop giving the POKéMON MAIL?"); //TODO 汉化
#else
    _("Stop giving the POKéMON MAIL?");
#endif

const u8 gText_AndFillOutTheQuestionnaire[] =
#ifdef CHINESE
    _("and fill out the questionnaire."); //TODO 汉化
#else
    _("and fill out the questionnaire.");
#endif

const u8 gText_LetsReplyToTheInterview[] =
#ifdef CHINESE
    _("Let's reply to the interview!"); //TODO 汉化
#else
    _("Let's reply to the interview!");
#endif

const u8 gText_AllTextBeingEditedWill[] =
#ifdef CHINESE
    _("All the text being edited will"); //TODO 汉化
#else
    _("All the text being edited will");
#endif

const u8 gText_BeDeletedThatOkay[] =
#ifdef CHINESE
    _("be deleted. Is that okay?"); //TODO 汉化
#else
    _("be deleted. Is that okay?");
#endif

const u8 gText_QuitEditing2[] =
#ifdef CHINESE
    _("Quit editing?"); // Unused //TODO 汉化
#else
    _("Quit editing?");                      // Unused
#endif

const u8 gText_EditedTextWillNotBeSaved[] =
#ifdef CHINESE
    _("The edited text will not be saved."); // Unused //TODO 汉化
#else
    _("The edited text will not be saved."); // Unused
#endif

const u8 gText_IsThatOkay[] =
#ifdef CHINESE
    _("Is that okay?"); // Unused //TODO 汉化
#else
    _("Is that okay?");                      // Unused
#endif

const u8 gText_PleaseEnterPhraseOrWord[] =
#ifdef CHINESE
    _("Please enter a phrase or word."); // Unused //TODO 汉化
#else
    _("Please enter a phrase or word.");     // Unused
#endif

const u8 gText_EntireTextCantBeDeleted[] =
#ifdef CHINESE
    _("The entire text can't be deleted."); //TODO 汉化
#else
    _("The entire text can't be deleted.");
#endif

const u8 gText_OnlyOnePhrase[] =
#ifdef CHINESE
    _("Only one phrase may be changed."); //TODO 汉化
#else
    _("Only one phrase may be changed.");
#endif

const u8 gText_OriginalSongWillBeUsed[] =
#ifdef CHINESE
    _("The original song will be used."); //TODO 汉化
#else
    _("The original song will be used.");
#endif

const u8 gText_ThatsTrendyAlready[] =
#ifdef CHINESE
    _("That's trendy already!"); // Unused //TODO 汉化
#else
    _("That's trendy already!"); // Unused
#endif

const u8 gText_CombineTwoWordsOrPhrases3[] =
#ifdef CHINESE
    _("Combine two words or phrases."); //TODO 汉化
#else
    _("Combine two words or phrases.");
#endif

const u8 gText_QuitGivingInfo[] =
#ifdef CHINESE
    _("Quit giving information?"); // Unused //TODO 汉化
#else
    _("Quit giving information?");      // Unused
#endif

const u8 gText_StopGivingPkmnMail2[] =
#ifdef CHINESE
    _("Stop giving the POKéMON MAIL?"); // Unused //TODO 汉化
#else
    _("Stop giving the POKéMON MAIL?"); // Unused
#endif

const u8 gText_CreateAQuiz2[] =
#ifdef CHINESE
    _("Create a quiz!"); // Unused //TODO 汉化
#else
    _("Create a quiz!");                // Unused
#endif

const u8 gText_SetTheAnswer[] =
#ifdef CHINESE
    _("Set the answer!"); // Unused //TODO 汉化
#else
    _("Set the answer!");               // Unused
#endif

const u8 gText_CancelSelection[] =
#ifdef CHINESE
    _("Cancel the selection?"); // Unused //TODO 汉化
#else
    _("Cancel the selection?");         // Unused
#endif

const u8 gText_Profile[] =
#ifdef CHINESE
    _("PROFILE"); //TODO 汉化
#else
    _("PROFILE");
#endif

const u8 gText_AtTheBattlesStart[] =
#ifdef CHINESE
    _("At the battle's start:"); //TODO 汉化
#else
    _("At the battle's start:");
#endif

const u8 gText_UponWinningABattle[] =
#ifdef CHINESE
    _("Upon winning a battle:"); //TODO 汉化
#else
    _("Upon winning a battle:");
#endif

const u8 gText_UponLosingABattle[] =
#ifdef CHINESE
    _("Upon losing a battle:"); //TODO 汉化
#else
    _("Upon losing a battle:");
#endif

const u8 gText_TheBardsSong[] =
#ifdef CHINESE
    _("The BARD's Song"); //TODO 汉化
#else
    _("The BARD's Song");
#endif

const u8 gText_WhatsHipAndHappening[] =
#ifdef CHINESE
    _("What's hip and happening?"); //TODO 汉化
#else
    _("What's hip and happening?");
#endif

const u8 gText_Interview[] =
#ifdef CHINESE
    _("Interview"); //TODO 汉化
#else
    _("Interview");
#endif

const u8 gText_GoodSaying[] =
#ifdef CHINESE
    _("Good saying"); //TODO 汉化
#else
    _("Good saying");
#endif

const u8 gText_FansQuestion[] =
#ifdef CHINESE
    _("Fan's question"); //TODO 汉化
#else
    _("Fan's question");
#endif

const u8 gJPText_WhatIsTheQuizAnswer[] =
#ifdef CHINESE
    _("クイズの こたえは？"); // Unused //TODO 汉化
#else
    _("クイズの こたえは？"); // Unused
#endif

const u8 gText_ApprenticesPhrase[] =
#ifdef CHINESE
    _("Apprentice's phrase"); //TODO 汉化
#else
    _("Apprentice's phrase");
#endif

const u8 gText_Questionnaire[] =
#ifdef CHINESE
    _("QUESTIONNAIRE"); //TODO 汉化
#else
    _("QUESTIONNAIRE");
#endif

const u8 gText_YouCannotQuitHere[] =
#ifdef CHINESE
    _("You cannot quit here."); //TODO 汉化
#else
    _("You cannot quit here.");
#endif

const u8 gText_SectionMustBeCompleted[] =
#ifdef CHINESE
    _("This section must be completed."); //TODO 汉化
#else
    _("This section must be completed.");
#endif

const u8 gText_F700sQuiz[] =
#ifdef CHINESE
    _("{DYNAMIC 0}'s quiz"); //TODO 汉化
#else
    _("{DYNAMIC 0}'s quiz");
#endif

const u8 gText_Lady[] =
#ifdef CHINESE
    _("Lady"); //TODO 汉化
#else
    _("Lady");
#endif

const u8 gText_AfterYouHaveReadTheQuiz[] =
#ifdef CHINESE
    _("After you have read the quiz"); //TODO 汉化
#else
    _("After you have read the quiz");
#endif

const u8 gText_QuestionPressTheAButton[] =
#ifdef CHINESE
    _("question, press the A Button."); //TODO 汉化
#else
    _("question, press the A Button.");
#endif

const u8 gText_TheQuizAnswerIs[] =
#ifdef CHINESE
    _("The quiz answer is?"); //TODO 汉化
#else
    _("The quiz answer is?");
#endif

const u8 gText_LikeToQuitQuiz[] =
#ifdef CHINESE
    _("Would you like to quit this quiz"); //TODO 汉化
#else
    _("Would you like to quit this quiz");
#endif

const u8 gText_ChallengeQuestionMark[] =
#ifdef CHINESE
    _("challenge?"); //TODO 汉化
#else
    _("challenge?");
#endif

const u8 gText_IsThisQuizOK[] =
#ifdef CHINESE
    _("Is this quiz OK?"); //TODO 汉化
#else
    _("Is this quiz OK?");
#endif

const u8 gText_CreateAQuiz[] =
#ifdef CHINESE
    _("Create a quiz!"); //TODO 汉化
#else
    _("Create a quiz!");
#endif

const u8 gText_SelectTheAnswer[] =
#ifdef CHINESE
    _("Select the answer!"); //TODO 汉化
#else
    _("Select the answer!");
#endif

const u8 gText_LyricsCantBeDeleted[] =
#ifdef CHINESE
    _("The lyrics can't be deleted."); //TODO 汉化
#else
    _("The lyrics can't be deleted.");
#endif

const u8 gText_PokemonLeague[] =
#ifdef CHINESE
    _("POKéMON LEAGUE"); //TODO 汉化
#else
    _("POKéMON LEAGUE");
#endif

const u8 gText_PokemonCenter[] =
#ifdef CHINESE
    _("POKéMON CENTER"); //TODO 汉化
#else
    _("POKéMON CENTER");
#endif

const u8 gText_GetsAPokeBlockQuestion[] =
#ifdef CHINESE
    _(" gets a {POKEBLOCK}?"); //TODO 汉化
#else
    _("gets a {POKEBLOCK}?");
#endif

const u8 gText_Coolness[] =
#ifdef CHINESE
    _("Coolness "); //TODO 汉化
#else
    _("Coolness ");
#endif

const u8 gText_Beauty3[] =
#ifdef CHINESE
    _("Beauty "); //TODO 汉化
#else
    _("Beauty ");
#endif

const u8 gText_Cuteness[] =
#ifdef CHINESE
    _("Cuteness "); //TODO 汉化
#else
    _("Cuteness ");
#endif

const u8 gText_Smartness[] =
#ifdef CHINESE
    _("Smartness "); //TODO 汉化
#else
    _("Smartness ");
#endif

const u8 gText_Toughness[] =
#ifdef CHINESE
    _("Toughness "); //TODO 汉化
#else
    _("Toughness ");
#endif

const u8 gText_WasEnhanced[] =
#ifdef CHINESE
    _("was enhanced!"); //TODO 汉化
#else
    _("was enhanced!");
#endif

const u8 gText_NothingChanged[] =
#ifdef CHINESE
    _("Nothing changed!"); //TODO 汉化
#else
    _("Nothing changed!");
#endif

const u8 gText_WontEatAnymore[] =
#ifdef CHINESE
    _("It won't eat anymore…"); //TODO 汉化
#else
    _("It won't eat anymore…");
#endif

const u8 gText_SaveFailedCheckingBackup[] =
#ifdef CHINESE
    _("Save failed. Checking the backup\nmemory… Please wait.\n{COLOR RED}“Time required: about 1 minute”"); //TODO 汉化
#else
    _("Save failed. Checking the backup\nmemory… Please wait.\n{COLOR RED}“Time required: about 1 minute”");
#endif

const u8 gText_BackupMemoryDamaged[] =
#ifdef CHINESE
    _("The backup memory is damaged, or\nthe internal battery has run dry.\nYou can still play, but not save."); //TODO 汉化
#else
    _("The backup memory is damaged, or\nthe internal battery has run dry.\nYou can still play, but not save.");
#endif

const u8 gText_GamePlayCannotBeContinued[] =
#ifdef CHINESE
    _("{COLOR RED}“Game play cannot be continued.\nReturning to the title screen…”"); //TODO 汉化
#else
    _("{COLOR RED}“Game play cannot be continued.\nReturning to the title screen…”");
#endif

const u8 gText_CheckCompleted[] =
#ifdef CHINESE
    _("Check completed.\nAttempting to save again.\nPlease wait."); //TODO 汉化
#else
    _("Check completed.\nAttempting to save again.\nPlease wait.");
#endif

const u8 gText_SaveCompleteGameCannotContinue[] =
#ifdef CHINESE
    _("Save completed.\n{COLOR RED}“Game play cannot be continued.\nReturning to the title screen.”"); //TODO 汉化
#else
    _("Save completed.\n{COLOR RED}“Game play cannot be continued.\nReturning to the title screen.”");
#endif

const u8 gText_SaveCompletePressA[] =
#ifdef CHINESE
    _("Save completed.\n{COLOR RED}“Please press the A Button.”"); //TODO 汉化
#else
    _("Save completed.\n{COLOR RED}“Please press the A Button.”");
#endif

const u8 gText_Ferry[] =
#ifdef CHINESE
    _("FERRY"); //TODO 汉化
#else
    _("FERRY");
#endif

const u8 gText_SecretBase[] =
#ifdef CHINESE
    _("SECRET BASE"); //TODO 汉化
#else
    _("SECRET BASE");
#endif

const u8 gText_Hideout[] =
#ifdef CHINESE
    _("HIDEOUT"); //TODO 汉化
#else
    _("HIDEOUT");
#endif

const u8 gText_ResetRTCConfirmCancel[] =
#ifdef CHINESE
    _("Reset RTC?\nA: Confirm, B: Cancel"); //TODO 汉化
#else
    _("Reset RTC?\nA: Confirm, B: Cancel");
#endif

const u8 gText_PresentTime[] =
#ifdef CHINESE
    _("Present time in game"); //TODO 汉化
#else
    _("Present time in game");
#endif

const u8 gText_PreviousTime[] =
#ifdef CHINESE
    _("Previous time in game"); //TODO 汉化
#else
    _("Previous time in game");
#endif

const u8 gText_PleaseResetTime[] =
#ifdef CHINESE
    _("Please reset the time."); //TODO 汉化
#else
    _("Please reset the time.");
#endif

const u8 gText_ClockHasBeenReset[] =
#ifdef CHINESE
    _("The clock has been reset.\nData will be saved. Please wait."); //TODO 汉化
#else
    _("The clock has been reset.\nData will be saved. Please wait.");
#endif

const u8 gText_SaveCompleted[] =
#ifdef CHINESE
    _("Save completed."); //TODO 汉化
#else
    _("Save completed.");
#endif

const u8 gText_SaveFailed[] =
#ifdef CHINESE
    _("Save failed…"); //TODO 汉化
#else
    _("Save failed…");
#endif

const u8 gText_NoSaveFileCantSetTime[] =
#ifdef CHINESE
    _("There is no save file, so the time\ncan't be set."); //TODO 汉化
#else
    _("There is no save file, so the time\ncan't be set.");
#endif

const u8 gText_InGameClockUsable[] =
#ifdef CHINESE
    _("The in-game clock adjustment system\nis now useable."); //TODO 汉化
#else
    _("The in-game clock adjustment system\nis now useable.");
#endif

const u8 gText_Slots[] =
#ifdef CHINESE
    _("SLOTS"); //TODO 汉化
#else
    _("SLOTS");
#endif

const u8 gText_Roulette[] =
#ifdef CHINESE
    _("ROULETTE"); //TODO 汉化
#else
    _("ROULETTE");
#endif

const u8 gText_Good[] =
#ifdef CHINESE
    _("Good"); //TODO 汉化
#else
    _("Good");
#endif

const u8 gText_VeryGood[] =
#ifdef CHINESE
    _("Very good"); //TODO 汉化
#else
    _("Very good");
#endif

const u8 gText_Excellent[] =
#ifdef CHINESE
    _("Excellent"); //TODO 汉化
#else
    _("Excellent");
#endif

const u8 gText_SoSo[] =
#ifdef CHINESE
    _("So-so"); //TODO 汉化
#else
    _("So-so");
#endif

const u8 gText_Bad[] =
#ifdef CHINESE
    _("Bad"); //TODO 汉化
#else
    _("Bad");
#endif

const u8 gText_TheWorst[] =
#ifdef CHINESE
    _("The worst"); //TODO 汉化
#else
    _("The worst");
#endif

const u8 gText_Spicy2[] =
#ifdef CHINESE
    _("spicy"); //TODO 汉化
#else
    _("spicy");
#endif

const u8 gText_Dry2[] =
#ifdef CHINESE
    _("dry"); //TODO 汉化
#else
    _("dry");
#endif

const u8 gText_Sweet2[] =
#ifdef CHINESE
    _("sweet"); //TODO 汉化
#else
    _("sweet");
#endif

const u8 gText_Bitter2[] =
#ifdef CHINESE
    _("bitter"); //TODO 汉化
#else
    _("bitter");
#endif

const u8 gText_Sour2[] =
#ifdef CHINESE
    _("sour"); //TODO 汉化
#else
    _("sour");
#endif

const u8 gText_Single[] =
#ifdef CHINESE
    _("SINGLE"); //TODO 汉化
#else
    _("SINGLE");
#endif

const u8 gText_Double[] =
#ifdef CHINESE
    _("DOUBLE"); //TODO 汉化
#else
    _("DOUBLE");
#endif

const u8 gText_Jackpot[] =
#ifdef CHINESE
    _("jackpot"); //TODO 汉化
#else
    _("jackpot");
#endif

const u8 gText_First[] =
#ifdef CHINESE
    _("first"); //TODO 汉化
#else
    _("first");
#endif

const u8 gText_Second[] =
#ifdef CHINESE
    _("second"); //TODO 汉化
#else
    _("second");
#endif

const u8 gText_Third[] =
#ifdef CHINESE
    _("third"); //TODO 汉化
#else
    _("third");
#endif

const u8 gText_0Pts[] =
#ifdef CHINESE
    _("0 pts"); //TODO 汉化
#else
    _("0 pts");
#endif

const u8 gText_10Pts[] =
#ifdef CHINESE
    _("10 pts"); //TODO 汉化
#else
    _("10 pts");
#endif

const u8 gText_20Pts[] =
#ifdef CHINESE
    _("20 pts"); //TODO 汉化
#else
    _("20 pts");
#endif

const u8 gText_30Pts[] =
#ifdef CHINESE
    _("30 pts"); //TODO 汉化
#else
    _("30 pts");
#endif

const u8 gText_40Pts[] =
#ifdef CHINESE
    _("40 pts"); //TODO 汉化
#else
    _("40 pts");
#endif

const u8 gText_50Pts[] =
#ifdef CHINESE
    _("50 pts"); //TODO 汉化
#else
    _("50 pts");
#endif

const u8 gText_60Pts[] =
#ifdef CHINESE
    _("60 pts"); //TODO 汉化
#else
    _("60 pts");
#endif

const u8 gText_70Pts[] =
#ifdef CHINESE
    _("70 pts"); //TODO 汉化
#else
    _("70 pts");
#endif

const u8 gText_80Pts[] =
#ifdef CHINESE
    _("80 pts"); //TODO 汉化
#else
    _("80 pts");
#endif

const u8 gText_90Pts[] =
#ifdef CHINESE
    _("90 pts"); //TODO 汉化
#else
    _("90 pts");
#endif

const u8 gText_100Pts[] =
#ifdef CHINESE
    _("100 pts"); //TODO 汉化
#else
    _("100 pts");
#endif

const u8 gText_QuestionMark[] =
#ifdef CHINESE
    _("?"); //TODO 汉化
#else
    _("?");
#endif

const u8 gText_KissPoster16BP[] =
#ifdef CHINESE
    _("KISS POSTER{CLEAR_TO 0x5E}16BP"); //TODO 汉化
#else
    _("KISS POSTER{CLEAR_TO 0x5E}16BP");
#endif

const u8 gText_KissCushion32BP[] =
#ifdef CHINESE
    _("KISS CUSHION{CLEAR_TO 0x5E}32BP"); //TODO 汉化
#else
    _("KISS CUSHION{CLEAR_TO 0x5E}32BP");
#endif

const u8 gText_SmoochumDoll32BP[] =
#ifdef CHINESE
    _("SMOOCHUM DOLL{CLEAR_TO 0x5E}32BP"); //TODO 汉化
#else
    _("SMOOCHUM DOLL{CLEAR_TO 0x5E}32BP");
#endif

const u8 gText_TogepiDoll48BP[] =
#ifdef CHINESE
    _("TOGEPI DOLL{CLEAR_TO 0x5E}48BP"); //TODO 汉化
#else
    _("TOGEPI DOLL{CLEAR_TO 0x5E}48BP");
#endif

const u8 gText_MeowthDoll48BP[] =
#ifdef CHINESE
    _("MEOWTH DOLL{CLEAR_TO 0x5E}48BP"); //TODO 汉化
#else
    _("MEOWTH DOLL{CLEAR_TO 0x5E}48BP");
#endif

const u8 gText_ClefairyDoll48BP[] =
#ifdef CHINESE
    _("CLEFAIRY DOLL{CLEAR_TO 0x5E}48BP"); //TODO 汉化
#else
    _("CLEFAIRY DOLL{CLEAR_TO 0x5E}48BP");
#endif

const u8 gText_DittoDoll48BP[] =
#ifdef CHINESE
    _("DITTO DOLL{CLEAR_TO 0x5E}48BP"); //TODO 汉化
#else
    _("DITTO DOLL{CLEAR_TO 0x5E}48BP");
#endif

const u8 gText_CyndaquilDoll80BP[] =
#ifdef CHINESE
    _("CYNDAQUIL DOLL{CLEAR_TO 0x5E}80BP"); //TODO 汉化
#else
    _("CYNDAQUIL DOLL{CLEAR_TO 0x5E}80BP");
#endif

const u8 gText_ChikoritaDoll80BP[] =
#ifdef CHINESE
    _("CHIKORITA DOLL{CLEAR_TO 0x5E}80BP"); //TODO 汉化
#else
    _("CHIKORITA DOLL{CLEAR_TO 0x5E}80BP");
#endif

const u8 gText_TotodileDoll80BP[] =
#ifdef CHINESE
    _("TOTODILE DOLL{CLEAR_TO 0x5E}80BP"); //TODO 汉化
#else
    _("TOTODILE DOLL{CLEAR_TO 0x5E}80BP");
#endif

const u8 gText_LaprasDoll128BP[] =
#ifdef CHINESE
    _("LAPRAS DOLL{CLEAR_TO 0x58}128BP"); //TODO 汉化
#else
    _("LAPRAS DOLL{CLEAR_TO 0x58}128BP");
#endif

const u8 gText_SnorlaxDoll128BP[] =
#ifdef CHINESE
    _("SNORLAX DOLL{CLEAR_TO 0x58}128BP"); //TODO 汉化
#else
    _("SNORLAX DOLL{CLEAR_TO 0x58}128BP");
#endif

const u8 gText_VenusaurDoll256BP[] =
#ifdef CHINESE
    _("VENUSAUR DOLL{CLEAR_TO 0x58}256BP"); //TODO 汉化
#else
    _("VENUSAUR DOLL{CLEAR_TO 0x58}256BP");
#endif

const u8 gText_CharizardDoll256BP[] =
#ifdef CHINESE
    _("CHARIZARD DOLL{CLEAR_TO 0x58}256BP"); //TODO 汉化
#else
    _("CHARIZARD DOLL{CLEAR_TO 0x58}256BP");
#endif

const u8 gText_BlastoiseDoll256BP[] =
#ifdef CHINESE
    _("BLASTOISE DOLL{CLEAR_TO 0x58}256BP"); //TODO 汉化
#else
    _("BLASTOISE DOLL{CLEAR_TO 0x58}256BP");
#endif

const u8 gText_Protein1BP[] =
#ifdef CHINESE
    _("PROTEIN{CLEAR_TO 0x64}1BP"); //TODO 汉化
#else
    _("PROTEIN{CLEAR_TO 0x64}1BP");
#endif

const u8 gText_Calcium1BP[] =
#ifdef CHINESE
    _("CALCIUM{CLEAR_TO 0x64}1BP"); //TODO 汉化
#else
    _("CALCIUM{CLEAR_TO 0x64}1BP");
#endif

const u8 gText_Iron1BP[] =
#ifdef CHINESE
    _("IRON{CLEAR_TO 0x64}1BP"); //TODO 汉化
#else
    _("IRON{CLEAR_TO 0x64}1BP");
#endif

const u8 gText_Zinc1BP[] =
#ifdef CHINESE
    _("ZINC{CLEAR_TO 0x64}1BP"); //TODO 汉化
#else
    _("ZINC{CLEAR_TO 0x64}1BP");
#endif

const u8 gText_Carbos1BP[] =
#ifdef CHINESE
    _("CARBOS{CLEAR_TO 0x64}1BP"); //TODO 汉化
#else
    _("CARBOS{CLEAR_TO 0x64}1BP");
#endif

const u8 gText_HpUp1BP[] =
#ifdef CHINESE
    _("HP UP{CLEAR_TO 0x64}1BP"); //TODO 汉化
#else
    _("HP UP{CLEAR_TO 0x64}1BP");
#endif

const u8 gText_Leftovers48BP[] =
#ifdef CHINESE
    _("LEFTOVERS{CLEAR_TO 0x5E}48BP"); //TODO 汉化
#else
    _("LEFTOVERS{CLEAR_TO 0x5E}48BP");
#endif

const u8 gText_WhiteHerb48BP[] =
#ifdef CHINESE
    _("WHITE HERB{CLEAR_TO 0x5E}48BP"); //TODO 汉化
#else
    _("WHITE HERB{CLEAR_TO 0x5E}48BP");
#endif

const u8 gText_QuickClaw48BP[] =
#ifdef CHINESE
    _("QUICK CLAW{CLEAR_TO 0x5E}48BP"); //TODO 汉化
#else
    _("QUICK CLAW{CLEAR_TO 0x5E}48BP");
#endif

const u8 gText_MentalHerb48BP[] =
#ifdef CHINESE
    _("MENTAL HERB{CLEAR_TO 0x5E}48BP"); //TODO 汉化
#else
    _("MENTAL HERB{CLEAR_TO 0x5E}48BP");
#endif

const u8 gText_BrightPowder64BP[] =
#ifdef CHINESE
    _("BRIGHTPOWDER{CLEAR_TO 0x5E}64BP"); //TODO 汉化
#else
    _("BRIGHTPOWDER{CLEAR_TO 0x5E}64BP");
#endif

const u8 gText_ChoiceBand64BP[] =
#ifdef CHINESE
    _("CHOICE BAND{CLEAR_TO 0x5E}64BP"); //TODO 汉化
#else
    _("CHOICE BAND{CLEAR_TO 0x5E}64BP");
#endif

const u8 gText_KingsRock64BP[] =
#ifdef CHINESE
    _("KING'S ROCK{CLEAR_TO 0x5E}64BP"); //TODO 汉化
#else
    _("KING'S ROCK{CLEAR_TO 0x5E}64BP");
#endif

const u8 gText_FocusBand64BP[] =
#ifdef CHINESE
    _("FOCUS BAND{CLEAR_TO 0x5E}64BP"); //TODO 汉化
#else
    _("FOCUS BAND{CLEAR_TO 0x5E}64BP");
#endif

const u8 gText_ScopeLens64BP[] =
#ifdef CHINESE
    _("SCOPE LENS{CLEAR_TO 0x5E}64BP"); //TODO 汉化
#else
    _("SCOPE LENS{CLEAR_TO 0x5E}64BP");
#endif

const u8 gText_Softboiled16BP[] =
#ifdef CHINESE
    _("SOFTBOILED{CLEAR_TO 0x4E}16BP"); //TODO 汉化
#else
    _("SOFTBOILED{CLEAR_TO 0x4E}16BP");
#endif

const u8 gText_SeismicToss24BP[] =
#ifdef CHINESE
    _("SEISMIC TOSS{CLEAR_TO 0x4E}24BP"); //TODO 汉化
#else
    _("SEISMIC TOSS{CLEAR_TO 0x4E}24BP");
#endif

const u8 gText_DreamEater24BP[] =
#ifdef CHINESE
    _("DREAM EATER{CLEAR_TO 0x4E}24BP"); //TODO 汉化
#else
    _("DREAM EATER{CLEAR_TO 0x4E}24BP");
#endif

const u8 gText_MegaPunch24BP[] =
#ifdef CHINESE
    _("MEGA PUNCH{CLEAR_TO 0x4E}24BP"); //TODO 汉化
#else
    _("MEGA PUNCH{CLEAR_TO 0x4E}24BP");
#endif

const u8 gText_MegaKick48BP[] =
#ifdef CHINESE
    _("MEGA KICK{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("MEGA KICK{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_BodySlam48BP[] =
#ifdef CHINESE
    _("BODY SLAM{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("BODY SLAM{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_RockSlide48BP[] =
#ifdef CHINESE
    _("ROCK SLIDE{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("ROCK SLIDE{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_Counter48BP[] =
#ifdef CHINESE
    _("COUNTER{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("COUNTER{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_ThunderWave48BP[] =
#ifdef CHINESE
    _("THUNDER WAVE{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("THUNDER WAVE{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_SwordsDance48BP[] =
#ifdef CHINESE
    _("SWORDS DANCE{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("SWORDS DANCE{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_DefenseCurl16BP[] =
#ifdef CHINESE
    _("DEFENSE CURL{CLEAR_TO 0x4E}16BP"); //TODO 汉化
#else
    _("DEFENSE CURL{CLEAR_TO 0x4E}16BP");
#endif

const u8 gText_Snore24BP[] =
#ifdef CHINESE
    _("SNORE{CLEAR_TO 0x4E}24BP"); //TODO 汉化
#else
    _("SNORE{CLEAR_TO 0x4E}24BP");
#endif

const u8 gText_MudSlap24BP[] =
#ifdef CHINESE
    _("MUD-SLAP{CLEAR_TO 0x4E}24BP"); //TODO 汉化
#else
    _("MUD-SLAP{CLEAR_TO 0x4E}24BP");
#endif

const u8 gText_Swift24BP[] =
#ifdef CHINESE
    _("SWIFT{CLEAR_TO 0x4E}24BP"); //TODO 汉化
#else
    _("SWIFT{CLEAR_TO 0x4E}24BP");
#endif

const u8 gText_IcyWind24BP[] =
#ifdef CHINESE
    _("ICY WIND{CLEAR_TO 0x4E}24BP"); //TODO 汉化
#else
    _("ICY WIND{CLEAR_TO 0x4E}24BP");
#endif

const u8 gText_Endure48BP[] =
#ifdef CHINESE
    _("ENDURE{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("ENDURE{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_PsychUp48BP[] =
#ifdef CHINESE
    _("PSYCH UP{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("PSYCH UP{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_IcePunch48BP[] =
#ifdef CHINESE
    _("ICE PUNCH{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("ICE PUNCH{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_ThunderPunch48BP[] =
#ifdef CHINESE
    _("THUNDERPUNCH{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("THUNDERPUNCH{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_FirePunch48BP[] =
#ifdef CHINESE
    _("FIRE PUNCH{CLEAR_TO 0x4E}48BP"); //TODO 汉化
#else
    _("FIRE PUNCH{CLEAR_TO 0x4E}48BP");
#endif

const u8 gText_PkmnFainted3[] =
#ifdef CHINESE
    _("{STR_VAR_1} fainted…\p\n"); //TODO 汉化
#else
    _("{STR_VAR_1} fainted…\p\n");
#endif

const u8 gText_Marco[] =
#ifdef CHINESE
    _("MARCO"); //TODO 汉化
#else
    _("MARCO");
#endif

const u8 gText_TrainerCardName[] =
#ifdef CHINESE
    _("NAME: "); //TODO 汉化
#else
    _("NAME: ");
#endif

const u8 gText_TrainerCardIDNo[] =
#ifdef CHINESE
    _("IDNo."); //TODO 汉化
#else
    _("IDNo.");
#endif

const u8 gText_TrainerCardMoney[] =
#ifdef CHINESE
    _("MONEY"); //TODO 汉化
#else
    _("MONEY");
#endif

const u8 gText_PokeDollar[] =
#ifdef CHINESE
    _("¥"); // Unused //TODO 汉化
#else
    _("¥"); // Unused
#endif

const u8 gText_TrainerCardPokedex[] =
#ifdef CHINESE
    _("POKéDEX"); //TODO 汉化
#else
    _("POKéDEX");
#endif

const u8 gText_EmptyString6[] = _("");

const u8 gText_Colon2[] =
#ifdef CHINESE
    _(":"); //TODO 汉化
#else
    _(":");
#endif

const u8 gText_Points[] =
#ifdef CHINESE
    _(" points"); // Unused //TODO 汉化
#else
    _("points"); // Unused
#endif

const u8 gText_TrainerCardTime[] =
#ifdef CHINESE
    _("TIME"); //TODO 汉化
#else
    _("TIME");
#endif

const u8 gJPText_BattlePoints[] =
#ifdef CHINESE
    _("ゲ-ムポイント"); // Unused. Name presumed, translation is Game Points //TODO 汉化
#else
    _("ゲ-ムポイント"); // Unused. Name presumed, translation is Game Points
#endif

const u8 gText_Var1sTrainerCard[] =
#ifdef CHINESE
    _("{STR_VAR_1}'s TRAINER CARD"); //TODO 汉化
#else
    _("{STR_VAR_1}'s TRAINER CARD");
#endif

const u8 gText_HallOfFameDebut[] =
#ifdef CHINESE
    _("HALL OF FAME DEBUT  "); //TODO 汉化
#else
    _("HALL OF FAME DEBUT  ");
#endif

const u8 gText_LinkBattles[] =
#ifdef CHINESE
    _("LINK BATTLES"); //TODO 汉化
#else
    _("LINK BATTLES");
#endif

const u8 gText_LinkCableBattles[] =
#ifdef CHINESE
    _("LINK CABLE BATTLES"); //TODO 汉化
#else
    _("LINK CABLE BATTLES");
#endif

const u8 gText_WinsLosses[] =
#ifdef CHINESE
    _("W:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  L:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}"); //TODO 汉化
#else
    _("W:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  L:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
#endif

const u8 gText_PokemonTrades[] =
#ifdef CHINESE
    _("POKéMON TRADES"); //TODO 汉化
#else
    _("POKéMON TRADES");
#endif

const u8 gText_UnionTradesAndBattles[] =
#ifdef CHINESE
    _("UNION TRADES & BATTLES"); //TODO 汉化
#else
    _("UNION TRADES & BATTLES");
#endif

const u8 gText_BerryCrush[] =
#ifdef CHINESE
    _("BERRY CRUSH"); //TODO 汉化
#else
    _("BERRY CRUSH");
#endif

const u8 gText_WaitingTrainerFinishReading[] =
#ifdef CHINESE
    _("Waiting for the other TRAINER to\nfinish reading your TRAINER CARD."); //TODO 汉化
#else
    _("Waiting for the other TRAINER to\nfinish reading your TRAINER CARD.");
#endif

const u8 gText_PokeblocksWithFriends[] =
#ifdef CHINESE
    _("{POKEBLOCK}S W/FRIENDS"); //TODO 汉化
#else
    _("{POKEBLOCK}S W/FRIENDS");
#endif

const u8 gText_NumPokeblocks[] =
#ifdef CHINESE
    _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}"); //TODO 汉化
#else
    _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
#endif

const u8 gText_WonContestsWFriends[] =
#ifdef CHINESE
    _("WON CONTESTS W/FRIENDS"); //TODO 汉化
#else
    _("WON CONTESTS W/FRIENDS");
#endif

const u8 gText_BattlePtsWon[] =
#ifdef CHINESE
    _("BATTLE POINTS WON"); //TODO 汉化
#else
    _("BATTLE POINTS WON");
#endif

const u8 gText_NumBP[] =
#ifdef CHINESE
    _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}BP"); //TODO 汉化
#else
    _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}BP");
#endif

const u8 gText_BattleTower[] =
#ifdef CHINESE
    _("BATTLE TOWER"); //TODO 汉化
#else
    _("BATTLE TOWER");
#endif

const u8 gText_WinsStraight[] =
#ifdef CHINESE
    _("W/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  STRAIGHT/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}"); //TODO 汉化
#else
    _("W/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  STRAIGHT/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}");
#endif

const u8 gText_BattleTower2[] =
#ifdef CHINESE
    _("BATTLE TOWER"); //TODO 汉化
#else
    _("BATTLE TOWER");
#endif

const u8 gText_BattleDome[] =
#ifdef CHINESE
    _("BATTLE DOME"); //TODO 汉化
#else
    _("BATTLE DOME");
#endif

const u8 gText_BattlePalace[] =
#ifdef CHINESE
    _("BATTLE PALACE"); //TODO 汉化
#else
    _("BATTLE PALACE");
#endif

const u8 gText_BattleFactory[] =
#ifdef CHINESE
    _("BATTLE FACTORY"); //TODO 汉化
#else
    _("BATTLE FACTORY");
#endif

const u8 gText_BattleArena[] =
#ifdef CHINESE
    _("BATTLE ARENA"); //TODO 汉化
#else
    _("BATTLE ARENA");
#endif

const u8 gText_BattlePike[] =
#ifdef CHINESE
    _("BATTLE PIKE"); //TODO 汉化
#else
    _("BATTLE PIKE");
#endif

const u8 gText_BattlePyramid[] =
#ifdef CHINESE
    _("BATTLE PYRAMID"); //TODO 汉化
#else
    _("BATTLE PYRAMID");
#endif

ALIGNED(4)
const u8 gText_FacilitySingle[] =
#ifdef CHINESE
    _("{STR_VAR_1} SINGLE"); //TODO 汉化
#else
    _("{STR_VAR_1} SINGLE");
#endif

ALIGNED(4)
const u8 gText_FacilityDouble[] =
#ifdef CHINESE
    _("{STR_VAR_1} DOUBLE"); //TODO 汉化
#else
    _("{STR_VAR_1} DOUBLE");
#endif

ALIGNED(4)
const u8 gText_FacilityMulti[] =
#ifdef CHINESE
    _("{STR_VAR_1} MULTI"); //TODO 汉化
#else
    _("{STR_VAR_1} MULTI");
#endif

ALIGNED(4)
const u8 gText_FacilityLink[] =
#ifdef CHINESE
    _("{STR_VAR_1} LINK"); //TODO 汉化
#else
    _("{STR_VAR_1} LINK");
#endif

ALIGNED(4)
const u8 gText_Facility[] =
#ifdef CHINESE
    _("{STR_VAR_1}"); //TODO 汉化
#else
    _("{STR_VAR_1}");
#endif

const u8 gText_Give[] =
#ifdef CHINESE
    _("Give"); //TODO 汉化
#else
    _("Give");
#endif

const u8 gText_NoNeed[] =
#ifdef CHINESE
    _("No need"); //TODO 汉化
#else
    _("No need");
#endif

const u8 gText_ColorLightShadowDarkGray[] =
#ifdef CHINESE
    _("{COLOR LIGHT_GRAY}{SHADOW DARK_GRAY}"); //TODO 汉化
#else
    _("{COLOR LIGHT_GRAY}{SHADOW DARK_GRAY}");
#endif

const u8 gText_ColorBlue[] =
#ifdef CHINESE
    _("{COLOR BLUE}"); //TODO 汉化
#else
    _("{COLOR BLUE}");
#endif

const u8 gText_ColorTransparent[] =
#ifdef CHINESE
    _("{HIGHLIGHT TRANSPARENT}{COLOR TRANSPARENT}"); //TODO 汉化
#else
    _("{HIGHLIGHT TRANSPARENT}{COLOR TRANSPARENT}");
#endif

const u8 gText_CDot[] =
#ifdef CHINESE
    _("C."); //TODO 汉化
#else
    _("C.");
#endif

const u8 gText_BDot[] =
#ifdef CHINESE
    _("B."); //TODO 汉化
#else
    _("B.");
#endif

const u8 gText_AnnouncingResults[] =
#ifdef CHINESE
    _("Announcing the results!"); //TODO 汉化
#else
    _("Announcing the results!");
#endif

const u8 gText_PreliminaryResults[] =
#ifdef CHINESE
    _("The preliminary results!"); //TODO 汉化
#else
    _("The preliminary results!");
#endif

const u8 gText_Round2Results[] =
#ifdef CHINESE
    _("Round 2 results!"); //TODO 汉化
#else
    _("Round 2 results!");
#endif

const u8 gText_ContestantsMonWon[] =
#ifdef CHINESE
    _("{STR_VAR_1}'s {STR_VAR_2} won!"); //TODO 汉化
#else
    _("{STR_VAR_1}'s {STR_VAR_2} won!");
#endif

const u8 gText_CommunicationStandby[] =
#ifdef CHINESE
    _("Communication standby…"); //TODO 汉化
#else
    _("Communication standby…");
#endif

const u8 gText_ColorDarkGray[] =
#ifdef CHINESE
    _("{COLOR DARK_GRAY}"); //TODO 汉化
#else
    _("{COLOR DARK_GRAY}");
#endif

const u8 gText_ColorDynamic6WhiteDynamic5[] =
#ifdef CHINESE
    _("{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR6 WHITE DYNAMIC_COLOR5}"); // Unused //TODO 汉化
#else
    _("{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR6 WHITE DYNAMIC_COLOR5}"); // Unused
#endif

const u8 gText_HighlightDarkGray[] =
#ifdef CHINESE
    _("{HIGHLIGHT DARK_GRAY}"); //TODO 汉化
#else
    _("{HIGHLIGHT DARK_GRAY}");
#endif

const u8 gText_EmptySpace2[] =
#ifdef CHINESE
    _(" "); // Unused //TODO 汉化
#else
    _(""); // Unused
#endif

const u8 gText_DynColor2Male[] =
#ifdef CHINESE
    _("{COLOR DYNAMIC_COLOR2}♂"); //TODO 汉化
#else
    _("{COLOR DYNAMIC_COLOR2}♂");
#endif

const u8 gText_DynColor1Female[] =
#ifdef CHINESE
    _("{COLOR DYNAMIC_COLOR1}♀"); //TODO 汉化
#else
    _("{COLOR DYNAMIC_COLOR1}♀");
#endif

const u8 gText_DynColor2[] =
#ifdef CHINESE
    _("{COLOR DYNAMIC_COLOR2}"); //TODO 汉化
#else
    _("{COLOR DYNAMIC_COLOR2}");
#endif

const u8 gText_Upper[] =
#ifdef CHINESE
    _("UPPER"); //TODO 汉化
#else
    _("UPPER");
#endif

const u8 gText_Lower[] =
#ifdef CHINESE
    _("lower"); //TODO 汉化
#else
    _("lower");
#endif

const u8 gText_Others[] =
#ifdef CHINESE
    _("OTHERS"); //TODO 汉化
#else
    _("OTHERS");
#endif

const u8 gText_Symbols[] =
#ifdef CHINESE
    _("SYMBOLS"); //TODO 汉化
#else
    _("SYMBOLS");
#endif

const u8 gText_Register2[] =
#ifdef CHINESE
    _("REGISTER"); //TODO 汉化
#else
    _("REGISTER");
#endif

const u8 gText_Exit2[] =
#ifdef CHINESE
    _("EXIT"); //TODO 汉化
#else
    _("EXIT");
#endif

const u8 gText_QuitChatting[] =
#ifdef CHINESE
    _("Quit chatting?"); //TODO 汉化
#else
    _("Quit chatting?");
#endif

const u8 gText_RegisterTextWhere[] =
#ifdef CHINESE
    _("Register text where?"); //TODO 汉化
#else
    _("Register text where?");
#endif

const u8 gText_RegisterTextHere[] =
#ifdef CHINESE
    _("Register text here?"); //TODO 汉化
#else
    _("Register text here?");
#endif

const u8 gText_InputText[] =
#ifdef CHINESE
    _("Input text."); //TODO 汉化
#else
    _("Input text.");
#endif

const u8 gText_F700JoinedChat[] =
#ifdef CHINESE
    _("{DYNAMIC 0} joined the chat!"); //TODO 汉化
#else
    _("{DYNAMIC 0} joined the chat!");
#endif

const u8 gText_F700LeftChat[] =
#ifdef CHINESE
    _("{DYNAMIC 0} left the chat."); //TODO 汉化
#else
    _("{DYNAMIC 0} left the chat.");
#endif

const u8 gJPText_PlayersXPokemon[] =
#ifdef CHINESE
    _("{DYNAMIC 0}の{DYNAMIC 1}ひきめ:"); // Unused //TODO 汉化
#else
    _("{DYNAMIC 0}の{DYNAMIC 1}ひきめ:");           // Unused
#endif

const u8 gJPText_PlayersXPokmonDoesNotExist[] =
#ifdef CHINESE
    _("{DYNAMIC 0}の{DYNAMIC 1}ひきめは いません"); // Unused //TODO 汉化
#else
    _("{DYNAMIC 0}の{DYNAMIC 1}ひきめは いません"); // Unused
#endif

const u8 gText_ExitingChat[] =
#ifdef CHINESE
    _("Exiting the chat…"); //TODO 汉化
#else
    _("Exiting the chat…");
#endif

const u8 gText_LeaderLeftEndingChat[] =
#ifdef CHINESE
    _("The LEADER, {DYNAMIC 0}, has\nleft, ending the chat."); //TODO 汉化
#else
    _("The LEADER, {DYNAMIC 0}, has\nleft, ending the chat.");
#endif

const u8 gText_RegisteredTextChangedOKToSave[] =
#ifdef CHINESE
    _("The registered text has been changed.\nIs it okay to save the game?"); //TODO 汉化
#else
    _("The registered text has been changed.\nIs it okay to save the game?");
#endif

const u8 gText_AlreadySavedFile_Chat[] =
#ifdef CHINESE
    _("There is already a saved file.\nIs it okay to overwrite it?"); //TODO 汉化
#else
    _("There is already a saved file.\nIs it okay to overwrite it?");
#endif

const u8 gText_SavingDontTurnOff_Chat[] =
#ifdef CHINESE
    _("SAVING…\nDON'T TURN OFF THE POWER."); //TODO 汉化
#else
    _("SAVING…\nDON'T TURN OFF THE POWER.");
#endif

const u8 gText_PlayerSavedGame_Chat[] =
#ifdef CHINESE
    _("{DYNAMIC 0} saved the game."); //TODO 汉化
#else
    _("{DYNAMIC 0} saved the game.");
#endif

const u8 gText_IfLeaderLeavesChatEnds[] =
#ifdef CHINESE
    _("If the LEADER leaves, the chat\nwill end. Is that okay?"); //TODO 汉化
#else
    _("If the LEADER leaves, the chat\nwill end. Is that okay?");
#endif

const u8 gText_Hello[] =
#ifdef CHINESE
    _("HELLO"); //TODO 汉化
#else
    _("HELLO");
#endif

const u8 gText_Pokemon2[] =
#ifdef CHINESE
    _("POKéMON"); //TODO 汉化
#else
    _("POKéMON");
#endif

const u8 gText_Trade[] =
#ifdef CHINESE
    _("TRADE"); //TODO 汉化
#else
    _("TRADE");
#endif

const u8 gText_Battle[] =
#ifdef CHINESE
    _("BATTLE"); //TODO 汉化
#else
    _("BATTLE");
#endif

const u8 gText_Lets[] =
#ifdef CHINESE
    _("LET'S"); //TODO 汉化
#else
    _("LET'S");
#endif

const u8 gText_Ok[] =
#ifdef CHINESE
    _("OK!"); //TODO 汉化
#else
    _("OK!");
#endif

const u8 gText_Sorry[] =
#ifdef CHINESE
    _("SORRY"); //TODO 汉化
#else
    _("SORRY");
#endif

const u8 gText_YaySmileEmoji[] =
#ifdef CHINESE
    _("YAY{EMOJI_BIGSMILE}"); //TODO 汉化
#else
    _("YAY{EMOJI_BIGSMILE}");
#endif

const u8 gText_ThankYou[] =
#ifdef CHINESE
    _("THANK YOU"); //TODO 汉化
#else
    _("THANK YOU");
#endif

const u8 gText_ByeBye[] =
#ifdef CHINESE
    _("BYE-BYE!"); //TODO 汉化
#else
    _("BYE-BYE!");
#endif

const u8 gText_MatchCallSteven_Strategy[] =
#ifdef CHINESE
    _("Attack the weak points!"); //TODO 汉化
#else
    _("Attack the weak points!");
#endif

const u8 gText_MatchCallSteven_Pokemon[] =
#ifdef CHINESE
    _("Ultimate STEEL POKéMON."); //TODO 汉化
#else
    _("Ultimate STEEL POKéMON.");
#endif

const u8 gText_MatchCallSteven_Intro1_BeforeMeteorFallsBattle[] =
#ifdef CHINESE
    _("I'd climb even waterfalls"); //TODO 汉化
#else
    _("I'd climb even waterfalls");
#endif

const u8 gText_MatchCallSteven_Intro2_BeforeMeteorFallsBattle[] =
#ifdef CHINESE
    _("to find a rare stone!"); //TODO 汉化
#else
    _("to find a rare stone!");
#endif

const u8 gText_MatchCallSteven_Intro1_AfterMeteorFallsBattle[] =
#ifdef CHINESE
    _("I'm the strongest and most"); //TODO 汉化
#else
    _("I'm the strongest and most");
#endif

const u8 gText_MatchCallSteven_Intro2_AfterMeteorFallsBattle[] =
#ifdef CHINESE
    _("energetic after all!"); //TODO 汉化
#else
    _("energetic after all!");
#endif

const u8 gText_MatchCallBrendan_Strategy[] =
#ifdef CHINESE
    _("Battle with knowledge!"); //TODO 汉化
#else
    _("Battle with knowledge!");
#endif

const u8 gText_MatchCallBrendan_Pokemon[] =
#ifdef CHINESE
    _("I will use various POKéMON."); //TODO 汉化
#else
    _("I will use various POKéMON.");
#endif

const u8 gText_MatchCallBrendan_Intro1[] =
#ifdef CHINESE
    _("I'll be a better POKéMON"); //TODO 汉化
#else
    _("I'll be a better POKéMON");
#endif

const u8 gText_MatchCallBrendan_Intro2[] =
#ifdef CHINESE
    _("prof than my father is!"); //TODO 汉化
#else
    _("prof than my father is!");
#endif

const u8 gText_MatchCallMay_Strategy[] =
#ifdef CHINESE
    _("I'm not so good at battles."); //TODO 汉化
#else
    _("I'm not so good at battles.");
#endif

const u8 gText_MatchCallMay_Pokemon[] =
#ifdef CHINESE
    _("I'll use any POKéMON!"); //TODO 汉化
#else
    _("I'll use any POKéMON!");
#endif

const u8 gText_MatchCallMay_Intro1[] =
#ifdef CHINESE
    _("My POKéMON and I help"); //TODO 汉化
#else
    _("My POKéMON and I help");
#endif

const u8 gText_MatchCallMay_Intro2[] =
#ifdef CHINESE
    _("my father's research."); //TODO 汉化
#else
    _("my father's research.");
#endif

const u8 gText_HatchedFromEgg[] =
#ifdef CHINESE
    _("{STR_VAR_1} hatched from the EGG!"); //TODO 汉化
#else
    _("{STR_VAR_1} hatched from the EGG!");
#endif

const u8 gText_NicknameHatchPrompt[] =
#ifdef CHINESE
    _("Would you like to nickname the newly\nhatched {STR_VAR_1}?"); //TODO 汉化
#else
    _("Would you like to nickname the newly\nhatched {STR_VAR_1}?");
#endif

ALIGNED(4)
const u8 gText_ReadyPickBerry[] =
#ifdef CHINESE
    _("Are you ready to BERRY-CRUSH?\nPlease pick a BERRY for use.\p"); //TODO 汉化
#else
    _("Are you ready to BERRY-CRUSH?\nPlease pick a BERRY for use.\p");
#endif

ALIGNED(4)
const u8 gText_WaitForAllChooseBerry[] =
#ifdef CHINESE
    _("Please wait while each member\nchooses a BERRY."); //TODO 汉化
#else
    _("Please wait while each member\nchooses a BERRY.");
#endif

ALIGNED(4)
const u8 gText_EndedWithXUnitsPowder[] =
#ifdef CHINESE
    _("{PAUSE_MUSIC}{PLAY_BGM MUS_LEVEL_UP}You ended up with {STR_VAR_1} units of\nsilky-smooth BERRY POWDER.{RESUME_MUSIC}\pYour total amount of BERRY POWDER\nis {STR_VAR_2}.\p"); //TODO 汉化
#else
    _("{PAUSE_MUSIC}{PLAY_BGM MUS_LEVEL_UP}You ended up with {STR_VAR_1} units of\nsilky-smooth BERRY POWDER.{RESUME_MUSIC}\pYour total amount of BERRY POWDER\nis {STR_VAR_2}.\p");
#endif

ALIGNED(4)
const u8 gText_RecordingGameResults[] =
#ifdef CHINESE
    _("Recording your game results in the\nsave file.\lPlease wait."); //TODO 汉化
#else
    _("Recording your game results in the\nsave file.\lPlease wait.");
#endif

ALIGNED(4)
const u8 gText_PlayBerryCrushAgain[] =
#ifdef CHINESE
    _("Want to play BERRY CRUSH again?"); //TODO 汉化
#else
    _("Want to play BERRY CRUSH again?");
#endif

ALIGNED(4)
const u8 gText_YouHaveNoBerries[] =
#ifdef CHINESE
    _("You have no BERRIES.\nThe game will be canceled."); //TODO 汉化
#else
    _("You have no BERRIES.\nThe game will be canceled.");
#endif

ALIGNED(4)
const u8 gText_MemberDroppedOut[] =
#ifdef CHINESE
    _("A member dropped out.\nThe game will be canceled."); //TODO 汉化
#else
    _("A member dropped out.\nThe game will be canceled.");
#endif

ALIGNED(4)
const u8 gText_TimesUpNoGoodPowder[] =
#ifdef CHINESE
    _("Time's up.\pGood BERRY POWDER could not be\nmade…\p"); //TODO 汉化
#else
    _("Time's up.\pGood BERRY POWDER could not be\nmade…\p");
#endif

ALIGNED(4)
const u8 gText_CommunicationStandby2[] =
#ifdef CHINESE
    _("Communication standby…"); //TODO 汉化
#else
    _("Communication standby…");
#endif

ALIGNED(4)
const u8 gText_1DotBlueF700[] =
#ifdef CHINESE
    _("1. {COLOR BLUE}{SHADOW LIGHT_BLUE}{DYNAMIC 0}"); //TODO 汉化
#else
    _("1. {COLOR BLUE}{SHADOW LIGHT_BLUE}{DYNAMIC 0}");
#endif

ALIGNED(4)
const u8 gText_1DotF700[] =
#ifdef CHINESE
    _("1. {DYNAMIC 0}"); //TODO 汉化
#else
    _("1. {DYNAMIC 0}");
#endif

ALIGNED(4)
const u8 gText_SpaceTimes2[] =
#ifdef CHINESE
    _(" time(s)"); //TODO 汉化
#else
    _("time(s)");
#endif

ALIGNED(4)
const u8 gText_XDotY[] =
#ifdef CHINESE
    _("{STR_VAR_1}.{STR_VAR_2}"); //TODO 汉化
#else
    _("{STR_VAR_1}.{STR_VAR_2}");
#endif

ALIGNED(4)
const u8 gText_Var1Berry[] =
#ifdef CHINESE
    _("{STR_VAR_1} BERRY"); //TODO 汉化
#else
    _("{STR_VAR_1} BERRY");
#endif

ALIGNED(4)
const u8 gText_TimeColon[] =
#ifdef CHINESE
    _("Time:"); //TODO 汉化
#else
    _("Time:");
#endif

ALIGNED(4)
const u8 gText_PressingSpeed[] =
#ifdef CHINESE
    _("Pressing Speed:"); //TODO 汉化
#else
    _("Pressing Speed:");
#endif

ALIGNED(4)
const u8 gText_Silkiness[] =
#ifdef CHINESE
    _("Silkiness:"); //TODO 汉化
#else
    _("Silkiness:");
#endif

ALIGNED(4)
const u8 gText_StrVar1[] =
#ifdef CHINESE
    _("{STR_VAR_1}"); //TODO 汉化
#else
    _("{STR_VAR_1}");
#endif

ALIGNED(4)
const u8 gText_SpaceMin[] =
#ifdef CHINESE
    _(" min. "); //TODO 汉化
#else
    _("min. ");
#endif

ALIGNED(4)
const u8 gText_XDotY2[] =
#ifdef CHINESE
    _("{STR_VAR_1}.{STR_VAR_2}"); //TODO 汉化
#else
    _("{STR_VAR_1}.{STR_VAR_2}");
#endif

ALIGNED(4)
const u8 gText_SpaceSec[] =
#ifdef CHINESE
    _(" sec."); //TODO 汉化
#else
    _("sec.");
#endif

ALIGNED(4)
const u8 gText_XDotY3[] =
#ifdef CHINESE
    _("{STR_VAR_1}.{STR_VAR_2}"); //TODO 汉化
#else
    _("{STR_VAR_1}.{STR_VAR_2}");
#endif

ALIGNED(4)
const u8 gText_TimesPerSec[] =
#ifdef CHINESE
    _(" Times/sec."); //TODO 汉化
#else
    _("Times/sec.");
#endif

ALIGNED(4)
const u8 gText_Var1Percent[] =
#ifdef CHINESE
    _("{STR_VAR_1}%"); //TODO 汉化
#else
    _("{STR_VAR_1}%");
#endif

ALIGNED(4)
const u8 gText_PressesRankings[] =
#ifdef CHINESE
    _("No. of Presses Rankings"); //TODO 汉化
#else
    _("No. of Presses Rankings");
#endif

ALIGNED(4)
const u8 gText_CrushingResults[] =
#ifdef CHINESE
    _("Crushing Results"); //TODO 汉化
#else
    _("Crushing Results");
#endif

ALIGNED(4)
const u8 gText_NeatnessRankings[] =
#ifdef CHINESE
    _("Neatness Rankings"); //TODO 汉化
#else
    _("Neatness Rankings");
#endif

ALIGNED(4)
const u8 gText_CoopRankings[] =
#ifdef CHINESE
    _("Cooperative Rankings"); //TODO 汉化
#else
    _("Cooperative Rankings");
#endif

ALIGNED(4)
const u8 gText_PressingPowerRankings[] =
#ifdef CHINESE
    _("Pressing-Power Rankings"); //TODO 汉化
#else
    _("Pressing-Power Rankings");
#endif

const u8 gText_BerryCrush2[] =
#ifdef CHINESE
    _("BERRY CRUSH"); //TODO 汉化
#else
    _("BERRY CRUSH");
#endif

const u8 gText_PressingSpeedRankings[] =
#ifdef CHINESE
    _("Pressing-Speed Rankings"); //TODO 汉化
#else
    _("Pressing-Speed Rankings");
#endif

const u8 gText_Var1Players[] =
#ifdef CHINESE
    _("{STR_VAR_1} PLAYERS"); //TODO 汉化
#else
    _("{STR_VAR_1} PLAYERS");
#endif

const u8 gText_SymbolsEarned[] =
#ifdef CHINESE
    _("Symbols Earned"); //TODO 汉化
#else
    _("Symbols Earned");
#endif

const u8 gText_BattleRecord[] =
#ifdef CHINESE
    _("Battle Record"); //TODO 汉化
#else
    _("Battle Record");
#endif

const u8 gText_BattlePoints[] =
#ifdef CHINESE
    _("Battle Points"); //TODO 汉化
#else
    _("Battle Points");
#endif

const u8 gText_UnusedCancel[] =
#ifdef CHINESE
    _("CANCEL"); // Unused //TODO 汉化
#else
    _("CANCEL"); // Unused
#endif

const u8 gText_EmptyString7[] = _("");

const u8 gText_CheckFrontierMap[] =
#ifdef CHINESE
    _("Check BATTLE FRONTIER MAP."); //TODO 汉化
#else
    _("Check BATTLE FRONTIER MAP.");
#endif

const u8 gText_CheckTrainerCard[] =
#ifdef CHINESE
    _("Check TRAINER CARD."); //TODO 汉化
#else
    _("Check TRAINER CARD.");
#endif

const u8 gText_ViewRecordedBattle[] =
#ifdef CHINESE
    _("View recorded battle."); //TODO 汉化
#else
    _("View recorded battle.");
#endif

const u8 gText_PutAwayFrontierPass[] =
#ifdef CHINESE
    _("Put away the FRONTIER PASS."); //TODO 汉化
#else
    _("Put away the FRONTIER PASS.");
#endif

const u8 gText_CurrentBattlePoints[] =
#ifdef CHINESE
    _("Your current Battle Points."); //TODO 汉化
#else
    _("Your current Battle Points.");
#endif

const u8 gText_CollectedSymbols[] =
#ifdef CHINESE
    _("Your collected Symbols."); //TODO 汉化
#else
    _("Your collected Symbols.");
#endif

const u8 gText_BattleTowerAbilitySymbol[] =
#ifdef CHINESE
    _("Battle Tower - Ability Symbol"); //TODO 汉化
#else
    _("Battle Tower - Ability Symbol");
#endif

const u8 gText_BattleDomeTacticsSymbol[] =
#ifdef CHINESE
    _("Battle Dome - Tactics Symbol"); //TODO 汉化
#else
    _("Battle Dome - Tactics Symbol");
#endif

const u8 gText_BattlePalaceSpiritsSymbol[] =
#ifdef CHINESE
    _("Battle Palace - Spirits Symbol"); //TODO 汉化
#else
    _("Battle Palace - Spirits Symbol");
#endif

const u8 gText_BattleArenaGutsSymbol[] =
#ifdef CHINESE
    _("Battle Arena - Guts Symbol"); //TODO 汉化
#else
    _("Battle Arena - Guts Symbol");
#endif

const u8 gText_BattleFactoryKnowledgeSymbol[] =
#ifdef CHINESE
    _("Battle Factory - Knowledge Symbol"); //TODO 汉化
#else
    _("Battle Factory - Knowledge Symbol");
#endif

const u8 gText_BattlePikeLuckSymbol[] =
#ifdef CHINESE
    _("Battle Pike - Luck Symbol"); //TODO 汉化
#else
    _("Battle Pike - Luck Symbol");
#endif

const u8 gText_BattlePyramidBraveSymbol[] =
#ifdef CHINESE
    _("Battle Pyramid - Brave Symbol"); //TODO 汉化
#else
    _("Battle Pyramid - Brave Symbol");
#endif

const u8 gText_ThereIsNoBattleRecord[] =
#ifdef CHINESE
    _("There is no Battle Record."); //TODO 汉化
#else
    _("There is no Battle Record.");
#endif

const u8 gText_BattleTower3[] =
#ifdef CHINESE
    _("BATTLE TOWER"); //TODO 汉化
#else
    _("BATTLE TOWER");
#endif

const u8 gText_BattleDome2[] =
#ifdef CHINESE
    _("BATTLE DOME"); //TODO 汉化
#else
    _("BATTLE DOME");
#endif

const u8 gText_BattlePalace2[] =
#ifdef CHINESE
    _("BATTLE PALACE"); //TODO 汉化
#else
    _("BATTLE PALACE");
#endif

const u8 gText_BattleArena2[] =
#ifdef CHINESE
    _("BATTLE ARENA"); //TODO 汉化
#else
    _("BATTLE ARENA");
#endif

const u8 gText_BattleFactory2[] =
#ifdef CHINESE
    _("BATTLE FACTORY"); //TODO 汉化
#else
    _("BATTLE FACTORY");
#endif

const u8 gText_BattlePike2[] =
#ifdef CHINESE
    _("BATTLE PIKE"); //TODO 汉化
#else
    _("BATTLE PIKE");
#endif

const u8 gText_BattlePyramid2[] =
#ifdef CHINESE
    _("BATTLE PYRAMID"); //TODO 汉化
#else
    _("BATTLE PYRAMID");
#endif

const u8 gText_BattleTowerDesc[] =
#ifdef CHINESE
    _("KO opponents and aim for the top!\nYour ability will be tested."); //TODO 汉化
#else
    _("KO opponents and aim for the top!\nYour ability will be tested.");
#endif

const u8 gText_BattleDomeDesc[] =
#ifdef CHINESE
    _("Keep winning at the tournament!\nYour tactics will be tested."); //TODO 汉化
#else
    _("Keep winning at the tournament!\nYour tactics will be tested.");
#endif

const u8 gText_BattlePalaceDesc[] =
#ifdef CHINESE
    _("Watch your POKéMON battle!\nYour spirit will be tested."); //TODO 汉化
#else
    _("Watch your POKéMON battle!\nYour spirit will be tested.");
#endif

const u8 gText_BattleArenaDesc[] =
#ifdef CHINESE
    _("Win battles with teamed-up POKéMON!\nYour guts will be tested."); //TODO 汉化
#else
    _("Win battles with teamed-up POKéMON!\nYour guts will be tested.");
#endif

const u8 gText_BattleFactoryDesc[] =
#ifdef CHINESE
    _("Aim for victory using rental POKéMON!\nYour knowledge will be tested."); //TODO 汉化
#else
    _("Aim for victory using rental POKéMON!\nYour knowledge will be tested.");
#endif

const u8 gText_BattlePikeDesc[] =
#ifdef CHINESE
    _("Select one of three paths to battle!\nYour luck will be tested."); //TODO 汉化
#else
    _("Select one of three paths to battle!\nYour luck will be tested.");
#endif

const u8 gText_BattlePyramidDesc[] =
#ifdef CHINESE
    _("Aim for the top with exploration!\nYour bravery will be tested."); //TODO 汉化
#else
    _("Aim for the top with exploration!\nYour bravery will be tested.");
#endif

const u8 gText_ContinueMenuPlayer[] =
#ifdef CHINESE
    _("PLAYER"); //TODO 汉化
#else
    _("PLAYER");
#endif

const u8 gText_ContinueMenuTime[] =
#ifdef CHINESE
    _("TIME"); //TODO 汉化
#else
    _("TIME");
#endif

const u8 gText_ContinueMenuPokedex[] =
#ifdef CHINESE
    _("POKéDEX"); //TODO 汉化
#else
    _("POKéDEX");
#endif

const u8 gText_ContinueMenuBadges[] =
#ifdef CHINESE
    _("BADGES"); //TODO 汉化
#else
    _("BADGES");
#endif

const u8 gText_Powder[] =
#ifdef CHINESE
    _("POWDER"); //TODO 汉化
#else
    _("POWDER");
#endif

const u8 gText_BerryPickingRecords[] =
#ifdef CHINESE
    _("DODRIO BERRY-PICKING RECORDS"); //TODO 汉化
#else
    _("DODRIO BERRY-PICKING RECORDS");
#endif

const u8 gText_BerriesPicked[] =
#ifdef CHINESE
    _("BERRIES picked:"); //TODO 汉化
#else
    _("BERRIES picked:");
#endif

const u8 gText_BestScore[] =
#ifdef CHINESE
    _("Best score:"); //TODO 汉化
#else
    _("Best score:");
#endif

const u8 gText_BerriesInRowFivePlayers[] =
#ifdef CHINESE
    _("BERRIES picked in a row with\nfive players:"); //TODO 汉化
#else
    _("BERRIES picked in a row with\nfive players:");
#endif

const u8 gText_BerryPickingResults[] =
#ifdef CHINESE
    _("Announcing BERRY-PICKING results!"); //TODO 汉化
#else
    _("Announcing BERRY-PICKING results!");
#endif

const u8 gText_10P30P50P50P[] =
#ifdef CHINESE
    _("{CLEAR_TO 0x03}10P{CLEAR_TO 0x2B}30P{CLEAR_TO 0x53}50P{CLEAR_TO 0x77}{EMOJI_MINUS}50P"); //TODO 汉化
#else
    _("{CLEAR_TO 0x03}10P{CLEAR_TO 0x2B}30P{CLEAR_TO 0x53}50P{CLEAR_TO 0x77}{EMOJI_MINUS}50P");
#endif

const u8 gText_AnnouncingRankings[] =
#ifdef CHINESE
    _("Announcing rankings!"); //TODO 汉化
#else
    _("Announcing rankings!");
#endif

const u8 gText_AnnouncingPrizes[] =
#ifdef CHINESE
    _("Announcing prizes!"); //TODO 汉化
#else
    _("Announcing prizes!");
#endif

const u8 gText_1Colon[] =
#ifdef CHINESE
    _("1:"); //TODO 汉化
#else
    _("1:");
#endif

const u8 gText_2Colon[] =
#ifdef CHINESE
    _("2:"); //TODO 汉化
#else
    _("2:");
#endif

const u8 gText_3Colon[] =
#ifdef CHINESE
    _("3:"); //TODO 汉化
#else
    _("3:");
#endif

const u8 gText_4Colon[] =
#ifdef CHINESE
    _("4:"); //TODO 汉化
#else
    _("4:");
#endif

const u8 gText_5Colon[] =
#ifdef CHINESE
    _("5:"); //TODO 汉化
#else
    _("5:");
#endif

const u8 gText_FirstPlacePrize[] =
#ifdef CHINESE
    _("The first-place winner gets\nthis {DYNAMIC 0}!"); //TODO 汉化
#else
    _("The first-place winner gets\nthis {DYNAMIC 0}!");
#endif

const u8 gText_CantHoldAnyMore[] =
#ifdef CHINESE
    _("You can't hold any more!"); //TODO 汉化
#else
    _("You can't hold any more!");
#endif

const u8 gText_FilledStorageSpace[] =
#ifdef CHINESE
    _("It filled its storage space."); //TODO 汉化
#else
    _("It filled its storage space.");
#endif

const u8 gText_WantToPlayAgain[] =
#ifdef CHINESE
    _("Want to play again?"); //TODO 汉化
#else
    _("Want to play again?");
#endif

const u8 gText_SomeoneDroppedOut[] =
#ifdef CHINESE
    _("Somebody dropped out.\nThe link will be canceled."); //TODO 汉化
#else
    _("Somebody dropped out.\nThe link will be canceled.");
#endif

const u8 gText_SpacePoints[] =
#ifdef CHINESE
    _(" points"); //TODO 汉化
#else
    _("points");
#endif

const u8 gText_CommunicationStandby3[] =
#ifdef CHINESE
    _("Communication standby…"); //TODO 汉化
#else
    _("Communication standby…");
#endif

const u8 gText_SpacePoints2[] =
#ifdef CHINESE
    _(" points"); //TODO 汉化
#else
    _("points");
#endif

const u8 gText_SpaceTimes3[] =
#ifdef CHINESE
    _(" time(s)"); //TODO 汉化
#else
    _("time(s)");
#endif

const u8 gText_PkmnJumpRecords[] =
#ifdef CHINESE
    _("POKéMON JUMP RECORDS"); //TODO 汉化
#else
    _("POKéMON JUMP RECORDS");
#endif

const u8 gText_JumpsInARow[] =
#ifdef CHINESE
    _("Jumps in a row:"); //TODO 汉化
#else
    _("Jumps in a row:");
#endif

const u8 gText_BestScore2[] =
#ifdef CHINESE
    _("Best score:"); //TODO 汉化
#else
    _("Best score:");
#endif

const u8 gText_ExcellentsInARow[] =
#ifdef CHINESE
    _("EXCELLENTS in a row:"); //TODO 汉化
#else
    _("EXCELLENTS in a row:");
#endif

const u8 gText_AwesomeWonF701F700[] =
#ifdef CHINESE
    _("Awesome score! You've\nwon {DYNAMIC 1} {DYNAMIC 0}!"); //TODO 汉化
#else
    _("Awesome score! You've\nwon {DYNAMIC 1} {DYNAMIC 0}!");
#endif

const u8 gText_FilledStorageSpace2[] =
#ifdef CHINESE
    _("It filled its storage space."); //TODO 汉化
#else
    _("It filled its storage space.");
#endif

const u8 gText_CantHoldMore[] =
#ifdef CHINESE
    _("You can't hold any more!"); //TODO 汉化
#else
    _("You can't hold any more!");
#endif

const u8 gText_WantToPlayAgain2[] =
#ifdef CHINESE
    _("Want to play again?"); //TODO 汉化
#else
    _("Want to play again?");
#endif

const u8 gText_SomeoneDroppedOut2[] =
#ifdef CHINESE
    _("Somebody dropped out.\nThe link will be canceled."); //TODO 汉化
#else
    _("Somebody dropped out.\nThe link will be canceled.");
#endif

const u8 gText_CommunicationStandby4[] =
#ifdef CHINESE
    _("Communication standby…"); //TODO 汉化
#else
    _("Communication standby…");
#endif

const u8 gText_LinkContestResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Link Contest Results"); //TODO 汉化
#else
    _("{PLAYER}'s Link Contest Results");
#endif

const u8 gText_1st[] =
#ifdef CHINESE
    _("1st"); //TODO 汉化
#else
    _("1st");
#endif

const u8 gText_2nd[] =
#ifdef CHINESE
    _("2nd"); //TODO 汉化
#else
    _("2nd");
#endif

const u8 gText_3rd[] =
#ifdef CHINESE
    _("3rd"); //TODO 汉化
#else
    _("3rd");
#endif

const u8 gText_4th[] =
#ifdef CHINESE
    _("4th"); //TODO 汉化
#else
    _("4th");
#endif

const u8 gText_Friend[] =
#ifdef CHINESE
    _("Friend"); //TODO 汉化
#else
    _("Friend");
#endif

const u8 gText_Pokemon3[] =
#ifdef CHINESE
    _("POKeMON"); // Unused //TODO 汉化
#else
    _("POKeMON"); // Unused
#endif

const u8 gJPText_MysteryGift[] =
#ifdef CHINESE
    _("ふしぎなもらいもの"); //TODO 汉化
#else
    _("ふしぎなもらいもの");
#endif

const u8 gJPText_DecideStop[] =
#ifdef CHINESE
    _("{A_BUTTON}けってい {B_BUTTON}やめる"); //TODO 汉化
#else
    _("{A_BUTTON}けってい {B_BUTTON}やめる");
#endif

const u8 gJPText_ReceiveMysteryGiftWithEReader[] =
#ifdef CHINESE
    _("カードeリーダー{PLUS}　で\nふしぎなもらいものを　よみこみます"); //TODO 汉化
#else
    _("カードeリーダー{PLUS}　で\nふしぎなもらいものを　よみこみます");
#endif

const u8 gJPText_SelectConnectFromEReaderMenu[] =
#ifdef CHINESE
    _("カードeリーダー{PLUS}の　メニューから\n‘つうしん'を　えらび"); //TODO 汉化
#else
    _("カードeリーダー{PLUS}の　メニューから\n‘つうしん'を　えらび");
#endif

const u8 gJPText_SelectConnectWithGBA[] =
#ifdef CHINESE
    _("‘ゲームボーイアドバンスとつうしん'\nを　せんたく　してください"); //TODO 汉化
#else
    _("‘ゲームボーイアドバンスとつうしん'\nを　せんたく　してください");
#endif

const u8 gJPText_SelectConnectAndPressA[] =
#ifdef CHINESE
    _("カードeリーダー{PLUS}の　‘つうしん'を\nえらんで　Aボタンを　おしてください"); // Unused //TODO 汉化
#else
    _("カードeリーダー{PLUS}の　‘つうしん'を\nえらんで　Aボタンを　おしてください"); // Unused
#endif

const u8 gJPText_LinkIsIncorrect[] =
#ifdef CHINESE
    _("せつぞくが　まちがっています"); //TODO 汉化
#else
    _("せつぞくが　まちがっています");
#endif

const u8 gJPText_CardReadingHasBeenHalted[] =
#ifdef CHINESE
    _("カードの　よみこみを\nちゅうし　しました"); //TODO 汉化
#else
    _("カードの　よみこみを\nちゅうし　しました");
#endif

const u8 gJPText_UnableConnectWithEReader[] =
#ifdef CHINESE
    _("カードeリーダー{PLUS}と\nつうしん　できません"); // Unused //TODO 汉化
#else
    _("カードeリーダー{PLUS}と\nつうしん　できません"); // Unused
#endif

const u8 gJPText_Connecting[] =
#ifdef CHINESE
    _("つうしん　ちゅう　です"); //TODO 汉化
#else
    _("つうしん　ちゅう　です");
#endif

const u8 gJPText_ConnectionErrorCheckLink[] =
#ifdef CHINESE
    _("つうしん　エラーです\nせつぞくを　たしかめて　ください"); //TODO 汉化
#else
    _("つうしん　エラーです\nせつぞくを　たしかめて　ください");
#endif

const u8 gJPText_ConnectionErrorTryAgain[] =
#ifdef CHINESE
    _("つうしん　エラーです\nはじめから　やりなおして　ください"); // Link error //TODO 汉化
#else
    _("つうしん　エラーです\nはじめから　やりなおして　ください"); // Link error
#endif

const u8 gJPText_AllowEReaderToLoadCard[] =
#ifdef CHINESE
    _("カードeリーダー{PLUS}　に\nカードを　よみこませて　ください"); //TODO 汉化
#else
    _("カードeリーダー{PLUS}　に\nカードを　よみこませて　ください");
#endif

const u8 gJPText_ConnectionComplete[] =
#ifdef CHINESE
    _("つうしん　しゅうりょう！"); //TODO 汉化
#else
    _("つうしん　しゅうりょう！");
#endif

const u8 gJPText_NewTrainerHasComeToHoenn[] =
#ifdef CHINESE
    _("あらたな　トレーナーが\nホウエンに　やってきた！"); //TODO 汉化
#else
    _("あらたな　トレーナーが\nホウエンに　やってきた！");
#endif

const u8 gJPText_PleaseWaitAMoment[] =
#ifdef CHINESE
    _("しばらく　おまちください"); //TODO 汉化
#else
    _("しばらく　おまちください");
#endif

const u8 gJPText_WriteErrorUnableToSaveData[] =
#ifdef CHINESE
    _("かきこみ　エラー　です\nデータが　ほぞん　できませんでした"); //TODO 汉化
#else
    _("かきこみ　エラー　です\nデータが　ほぞん　できませんでした");
#endif

const u8 gText_Red[] =
#ifdef CHINESE
    _("RED"); //TODO 汉化
#else
    _("RED");
#endif

const u8 gText_Blue[] =
#ifdef CHINESE
    _("BLUE"); //TODO 汉化
#else
    _("BLUE");
#endif

const u8 gText_3Dashes[] =
#ifdef CHINESE
    _("---"); // Unused //TODO 汉化
#else
    _("---"); // Unused
#endif

const u8 gText_SingleBattleRoomResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Single Battle Room Results"); //TODO 汉化
#else
    _("{PLAYER}'s Single Battle Room Results");
#endif

const u8 gText_DoubleBattleRoomResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Double Battle Room Results"); //TODO 汉化
#else
    _("{PLAYER}'s Double Battle Room Results");
#endif

const u8 gText_MultiBattleRoomResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Multi Battle Room Results"); //TODO 汉化
#else
    _("{PLAYER}'s Multi Battle Room Results");
#endif

const u8 gText_LinkMultiBattleRoomResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Link Multi Battle Room Results"); //TODO 汉化
#else
    _("{PLAYER}'s Link Multi Battle Room Results");
#endif

const u8 gText_SingleBattleTourneyResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Single Battle Tourney Results"); //TODO 汉化
#else
    _("{PLAYER}'s Single Battle Tourney Results");
#endif

const u8 gText_DoubleBattleTourneyResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Double Battle Tourney Results"); //TODO 汉化
#else
    _("{PLAYER}'s Double Battle Tourney Results");
#endif

const u8 gText_SingleBattleHallResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Single Battle Hall Results"); //TODO 汉化
#else
    _("{PLAYER}'s Single Battle Hall Results");
#endif

const u8 gText_DoubleBattleHallResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Double Battle Hall Results"); //TODO 汉化
#else
    _("{PLAYER}'s Double Battle Hall Results");
#endif

const u8 gText_BattleChoiceResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Battle Choice Results"); //TODO 汉化
#else
    _("{PLAYER}'s Battle Choice Results");
#endif

const u8 gText_SetKOTourneyResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Set KO Tourney Results"); //TODO 汉化
#else
    _("{PLAYER}'s Set KO Tourney Results");
#endif

const u8 gText_BattleSwapSingleResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Battle Swap Single Results"); //TODO 汉化
#else
    _("{PLAYER}'s Battle Swap Single Results");
#endif

const u8 gText_BattleSwapDoubleResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Battle Swap Double Results"); //TODO 汉化
#else
    _("{PLAYER}'s Battle Swap Double Results");
#endif

const u8 gText_BattleQuestResults[] =
#ifdef CHINESE
    _("{PLAYER}'s Battle Quest Results"); //TODO 汉化
#else
    _("{PLAYER}'s Battle Quest Results");
#endif

const u8 gText_Lv502[] =
#ifdef CHINESE
    _("LV. 50"); //TODO 汉化
#else
    _("LV. 50");
#endif

const u8 gText_OpenLv[] =
#ifdef CHINESE
    _("OPEN LV."); //TODO 汉化
#else
    _("OPEN LV.");
#endif

const u8 gText_WinStreak[] =
#ifdef CHINESE
    _("Win streak: {STR_VAR_1}"); //TODO 汉化
#else
    _("Win streak: {STR_VAR_1}");
#endif

const u8 gText_Current[] =
#ifdef CHINESE
    _("CURRENT"); //TODO 汉化
#else
    _("CURRENT");
#endif

const u8 gText_Record[] =
#ifdef CHINESE
    _("RECORD"); //TODO 汉化
#else
    _("RECORD");
#endif

const u8 gText_Prev[] =
#ifdef CHINESE
    _("PREV."); //TODO 汉化
#else
    _("PREV.");
#endif

const u8 gText_RentalSwap[] =
#ifdef CHINESE
    _("Rental/Swap"); //TODO 汉化
#else
    _("Rental/Swap");
#endif

const u8 gText_Total[] =
#ifdef CHINESE
    _("Total"); //TODO 汉化
#else
    _("Total");
#endif

const u8 gText_ClearStreak[] =
#ifdef CHINESE
    _("Clear streak: {STR_VAR_1}"); //TODO 汉化
#else
    _("Clear streak: {STR_VAR_1}");
#endif

const u8 gText_Championships[] =
#ifdef CHINESE
    _("Championships: {STR_VAR_1}"); //TODO 汉化
#else
    _("Championships: {STR_VAR_1}");
#endif

const u8 gText_RoomsCleared[] =
#ifdef CHINESE
    _("Rooms cleared: {STR_VAR_1}"); //TODO 汉化
#else
    _("Rooms cleared: {STR_VAR_1}");
#endif

const u8 gText_TimesCleared[] =
#ifdef CHINESE
    _("Times cleared:{CLEAR 0x05}{STR_VAR_1}"); //TODO 汉化
#else
    _("Times cleared:{CLEAR 0x05}{STR_VAR_1}");
#endif

const u8 gText_KOsInARow[] =
#ifdef CHINESE
    _("KOs in a row: {STR_VAR_1}"); //TODO 汉化
#else
    _("KOs in a row: {STR_VAR_1}");
#endif

const u8 gText_TimesVar1[] =
#ifdef CHINESE
    _("Times: {STR_VAR_1}"); //TODO 汉化
#else
    _("Times: {STR_VAR_1}");
#endif

const u8 gText_FloorsCleared[] =
#ifdef CHINESE
    _("Floors cleared: {STR_VAR_1}"); //TODO 汉化
#else
    _("Floors cleared: {STR_VAR_1}");
#endif

ALIGNED(4)
const u8 gText_RecordsLv50[] =
#ifdef CHINESE
    _("LV. 50"); //TODO 汉化
#else
    _("LV. 50");
#endif

ALIGNED(4)
const u8 gText_RecordsOpenLevel[] =
#ifdef CHINESE
    _("OPEN LEVEL"); //TODO 汉化
#else
    _("OPEN LEVEL");
#endif

ALIGNED(4)
const u8 gText_FrontierFacilityWinStreak[] =
#ifdef CHINESE
    _("Win streak: {STR_VAR_2}"); //TODO 汉化
#else
    _("Win streak: {STR_VAR_2}");
#endif

ALIGNED(4)
const u8 gText_FrontierFacilityClearStreak[] =
#ifdef CHINESE
    _("Clear streak: {STR_VAR_2}"); //TODO 汉化
#else
    _("Clear streak: {STR_VAR_2}");
#endif

ALIGNED(4)
const u8 gText_FrontierFacilityRoomsCleared[] =
#ifdef CHINESE
    _("Rooms cleared: {STR_VAR_2}"); //TODO 汉化
#else
    _("Rooms cleared: {STR_VAR_2}");
#endif

ALIGNED(4)
const u8 gText_FrontierFacilityKOsStreak[] =
#ifdef CHINESE
    _("KOs in a row: {STR_VAR_2}"); //TODO 汉化
#else
    _("KOs in a row: {STR_VAR_2}");
#endif

ALIGNED(4)
const u8 gText_FrontierFacilityFloorsCleared[] =
#ifdef CHINESE
    _("Floors cleared: {STR_VAR_2}"); //TODO 汉化
#else
    _("Floors cleared: {STR_VAR_2}");
#endif

ALIGNED(4)
const u8 gText_123Dot[][3] = {_("1."), _("2."), _("3.")};

const u8 gText_SavingDontTurnOff2[] =
#ifdef CHINESE
    _("SAVING…\nDON'T TURN OFF THE POWER."); //TODO 汉化
#else
    _("SAVING…\nDON'T TURN OFF THE POWER.");
#endif

const u8 gText_BlenderMaxSpeedRecord[] =
#ifdef CHINESE
    _("BERRY BLENDER\nMAXIMUM SPEED RECORD!"); //TODO 汉化
#else
    _("BERRY BLENDER\nMAXIMUM SPEED RECORD!");
#endif

const u8 gText_234Players[] =
#ifdef CHINESE
    _("2 PLAYERS\n3 PLAYERS\n4 PLAYERS"); //TODO 汉化
#else
    _("2 PLAYERS\n3 PLAYERS\n4 PLAYERS");
#endif

const u8 gText_YesNo[] =
#ifdef CHINESE
    _("YES\nNO"); //TODO 汉化
#else
    _("YES\nNO");
#endif

const u8 gText_SelectorArrow3[] =
#ifdef CHINESE
    _("▶"); //TODO 汉化
#else
    _("▶");
#endif

const u8 gText_Peekaboo[] =
#ifdef CHINESE
    _("PEEKABOO!"); //TODO 汉化
#else
    _("PEEKABOO!");
#endif

const u8 gText_CommErrorCheckConnections[] =
#ifdef CHINESE
    _("Communication error…\nPlease check all connections,\nthen turn the power OFF and ON."); //TODO 汉化
#else
    _("Communication error…\nPlease check all connections,\nthen turn the power OFF and ON.");
#endif

const u8 gText_CommErrorEllipsis[] =
#ifdef CHINESE
    _("Communication error…"); //TODO 汉化
#else
    _("Communication error…");
#endif

const u8 gText_MoveCloserToLinkPartner[] =
#ifdef CHINESE
    _("Move closer to your link partner(s).\nAvoid obstacles between partners."); //TODO 汉化
#else
    _("Move closer to your link partner(s).\nAvoid obstacles between partners.");
#endif

const u8 gText_ABtnRegistrationCounter[] =
#ifdef CHINESE
    _("A Button: Registration Counter"); //TODO 汉化
#else
    _("A Button: Registration Counter");
#endif

const u8 gText_ABtnTitleScreen[] =
#ifdef CHINESE
    _("A Button: Title Screen"); //TODO 汉化
#else
    _("A Button: Title Screen");
#endif

const u8 gText_Option[] =
#ifdef CHINESE
    _("OPTION"); //TODO 汉化
#else
    _("OPTION");
#endif

const u8 gText_TextSpeed[] =
#ifdef CHINESE
    _("TEXT SPEED"); //TODO 汉化
#else
    _("TEXT SPEED");
#endif

const u8 gText_BattleScene[] =
#ifdef CHINESE
    _("BATTLE SCENE"); //TODO 汉化
#else
    _("BATTLE SCENE");
#endif

const u8 gText_BattleStyle[] =
#ifdef CHINESE
    _("BATTLE STYLE"); //TODO 汉化
#else
    _("BATTLE STYLE");
#endif

const u8 gText_Sound[] =
#ifdef CHINESE
    _("SOUND"); //TODO 汉化
#else
    _("SOUND");
#endif

const u8 gText_Frame[] =
#ifdef CHINESE
    _("FRAME"); //TODO 汉化
#else
    _("FRAME");
#endif

const u8 gText_OptionMenuCancel[] =
#ifdef CHINESE
    _("CANCEL"); //TODO 汉化
#else
    _("CANCEL");
#endif

const u8 gText_ButtonMode[] =
#ifdef CHINESE
    _("BUTTON MODE"); //TODO 汉化
#else
    _("BUTTON MODE");
#endif

const u8 gText_TextSpeedSlow[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SLOW"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SLOW");
#endif

const u8 gText_TextSpeedMid[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}MID"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}MID");
#endif

const u8 gText_TextSpeedFast[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}FAST"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}FAST");
#endif

const u8 gText_BattleSceneOn[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
#endif

const u8 gText_BattleSceneOff[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
#endif

const u8 gText_BattleStyleShift[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SHIFT"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SHIFT");
#endif

const u8 gText_BattleStyleSet[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SET"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SET");
#endif

const u8 gText_SoundMono[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}MONO"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}MONO");
#endif

const u8 gText_SoundStereo[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}STEREO"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}STEREO");
#endif

const u8 gText_FrameType[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}TYPE"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}TYPE");
#endif

const u8 gText_FrameTypeNumber[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}");
#endif

const u8 gText_ButtonTypeNormal[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL");
#endif

const u8 gText_ButtonTypeLR[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LR"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LR");
#endif

const u8 gText_ButtonTypeLEqualsA[] =
#ifdef CHINESE
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A"); //TODO 汉化
#else
    _("{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A");
#endif

const u8 gText_NumPlayerLink[] =
#ifdef CHINESE
    _("{STR_VAR_1}P LINK"); //TODO 汉化
#else
    _("{STR_VAR_1}P LINK");
#endif

const u8 gText_BronzeCard[] =
#ifdef CHINESE
    _("BRONZE"); //TODO 汉化
#else
    _("BRONZE");
#endif

const u8 gText_CopperCard[] =
#ifdef CHINESE
    _("COPPER"); //TODO 汉化
#else
    _("COPPER");
#endif

const u8 gText_SilverCard[] =
#ifdef CHINESE
    _("SILVER"); //TODO 汉化
#else
    _("SILVER");
#endif

const u8 gText_GoldCard[] =
#ifdef CHINESE
    _("GOLD"); //TODO 汉化
#else
    _("GOLD");
#endif

const u8 gText_Day[] =
#ifdef CHINESE
    _("DAY"); //TODO 汉化
#else
    _("DAY");
#endif

const u8 gText_Colon3[] =
#ifdef CHINESE
    _(":"); //TODO 汉化
#else
    _(":");
#endif

const u8 gText_Confirm2[] =
#ifdef CHINESE
    _("CONFIRM"); //TODO 汉化
#else
    _("CONFIRM");
#endif

const u8 gText_Days[] =
#ifdef CHINESE
    _("Days"); // Unused //TODO 汉化
#else
    _("Days");         // Unused
#endif

const u8 gText_TimeColon2[] =
#ifdef CHINESE
    _("Time:"); // Unused //TODO 汉化
#else
    _("Time:");        // Unused
#endif

const u8 gText_GameTime[] =
#ifdef CHINESE
    _("Game time"); // Unused //TODO 汉化
#else
    _("Game time");    // Unused
#endif

const u8 gText_RTCTime[] =
#ifdef CHINESE
    _("RTC time"); // Unused //TODO 汉化
#else
    _("RTC time");     // Unused
#endif

const u8 gText_UpdatedTime[] =
#ifdef CHINESE
    _("Updated time"); // Unused //TODO 汉化
#else
    _("Updated time"); // Unused
#endif

const u8 gText_MenuPokedex[] =
#ifdef CHINESE
    _("POKéDEX"); //TODO 汉化
#else
    _("POKéDEX");
#endif

const u8 gText_MenuPokemon[] =
#ifdef CHINESE
    _("POKéMON"); //TODO 汉化
#else
    _("POKéMON");
#endif

const u8 gText_MenuBag[] =
#ifdef CHINESE
    _("BAG"); //TODO 汉化
#else
    _("BAG");
#endif

const u8 gText_MenuPokenav[] =
#ifdef CHINESE
    _("POKéNAV"); //TODO 汉化
#else
    _("POKéNAV");
#endif

const u8 gText_MenuPlayer[] =
#ifdef CHINESE
    _("{PLAYER}"); //TODO 汉化
#else
    _("{PLAYER}");
#endif

const u8 gText_MenuSave[] =
#ifdef CHINESE
    _("SAVE"); //TODO 汉化
#else
    _("SAVE");
#endif

const u8 gText_MenuOption[] =
#ifdef CHINESE
    _("OPTION"); //TODO 汉化
#else
    _("OPTION");
#endif

const u8 gText_MenuExit[] =
#ifdef CHINESE
    _("EXIT"); //TODO 汉化
#else
    _("EXIT");
#endif

const u8 gText_MenuRetire[] =
#ifdef CHINESE
    _("RETIRE"); //TODO 汉化
#else
    _("RETIRE");
#endif

const u8 gText_MenuRest[] =
#ifdef CHINESE
    _("REST"); //TODO 汉化
#else
    _("REST");
#endif

const u8 gText_SafariBallStock[] =
#ifdef CHINESE
    _("SAFARI BALLS\nStock: {STR_VAR_1}"); //TODO 汉化
#else
    _("SAFARI BALLS\nStock: {STR_VAR_1}");
#endif

const u8 gText_BattlePyramidFloor[] =
#ifdef CHINESE
    _("Battle Pyramid\n{STR_VAR_1}"); //TODO 汉化
#else
    _("Battle Pyramid\n{STR_VAR_1}");
#endif

const u8 gText_Floor1[] =
#ifdef CHINESE
    _("Floor 1"); //TODO 汉化
#else
    _("Floor 1");
#endif

const u8 gText_Floor2[] =
#ifdef CHINESE
    _("Floor 2"); //TODO 汉化
#else
    _("Floor 2");
#endif

const u8 gText_Floor3[] =
#ifdef CHINESE
    _("Floor 3"); //TODO 汉化
#else
    _("Floor 3");
#endif

const u8 gText_Floor4[] =
#ifdef CHINESE
    _("Floor 4"); //TODO 汉化
#else
    _("Floor 4");
#endif

const u8 gText_Floor5[] =
#ifdef CHINESE
    _("Floor 5"); //TODO 汉化
#else
    _("Floor 5");
#endif

const u8 gText_Floor6[] =
#ifdef CHINESE
    _("Floor 6"); //TODO 汉化
#else
    _("Floor 6");
#endif

const u8 gText_Floor7[] =
#ifdef CHINESE
    _("Floor 7"); //TODO 汉化
#else
    _("Floor 7");
#endif

const u8 gText_Peak[] =
#ifdef CHINESE
    _("Peak"); //TODO 汉化
#else
    _("Peak");
#endif

const u8 gText_LinkStandby2[] =
#ifdef CHINESE
    _("Link standby…\n… … B Button: Cancel"); //TODO 汉化
#else
    _("Link standby…\n… … B Button: Cancel");
#endif

const u8 gText_PressAToLoadEvent[] =
#ifdef CHINESE
    _("Press the A Button to load event.\n… … B Button: Cancel"); //TODO 汉化
#else
    _("Press the A Button to load event.\n… … B Button: Cancel");
#endif

const u8 gText_LoadingEvent[] =
#ifdef CHINESE
    _("Loading event…"); //TODO 汉化
#else
    _("Loading event…");
#endif

const u8 gText_DontRemoveCableTurnOff[] =
#ifdef CHINESE
    _("Don't remove the Game Link cable.\nDon't turn off the power."); //TODO 汉化
#else
    _("Don't remove the Game Link cable.\nDon't turn off the power.");
#endif

const u8 gText_EventSafelyLoaded[] =
#ifdef CHINESE
    _("The event was safely loaded."); //TODO 汉化
#else
    _("The event was safely loaded.");
#endif

const u8 gText_LoadErrorEndingSession[] =
#ifdef CHINESE
    _("Loading error.\nEnding session."); //TODO 汉化
#else
    _("Loading error.\nEnding session.");
#endif

const u8 gJPText_Player[] =
#ifdef CHINESE
    _("プレイヤー"); // Unused //TODO 汉化
#else
    _("プレイヤー"); // Unused
#endif

const u8 gJPText_Sama[] =
#ifdef CHINESE
    _("さま"); // Unused //TODO 汉化
#else
    _("さま");       // Unused
#endif

const u8 gText_DexHoenn[] =
#ifdef CHINESE
    _("HOENN"); //TODO 汉化
#else
    _("HOENN");
#endif

const u8 gText_DexNational[] =
#ifdef CHINESE
    _("NATIONAL"); //TODO 汉化
#else
    _("NATIONAL");
#endif

const u8 gText_PokedexDiploma[] =
#ifdef CHINESE
    _("PLAYER: {CLEAR 0x10}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n\nThis document certifies\nthat you have successfully\ncompleted your\n{STR_VAR_1} POKéDEX.\n\n{CLEAR_TO 0x42}{COLOR RED}{SHADOW LIGHT_RED}GAME FREAK"); //TODO 汉化
#else
    _("PLAYER: {CLEAR 0x10}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n\nThis document certifies\nthat you have successfully\ncompleted your\n{STR_VAR_1} POKéDEX.\n\n{CLEAR_TO 0x42}{COLOR RED}{SHADOW LIGHT_RED}GAME FREAK");
#endif

const u8 gJPText_GameFreak[] =
#ifdef CHINESE
    _("{COLOR RED}{SHADOW LIGHT_RED}ゲ-ムフリ-ク"); // Unused //TODO 汉化
#else
    _("{COLOR RED}{SHADOW LIGHT_RED}ゲ-ムフリ-ク"); // Unused
#endif

const u8 gText_DiplomaEmpty[] =
#ifdef CHINESE
    _("{COLOR RED}{SHADOW LIGHT_RED}"); // Unused //TODO 汉化
#else
    _("{COLOR RED}{SHADOW LIGHT_RED}");             // Unused
#endif

const u8 gText_Hoenn[] =
#ifdef CHINESE
    _("HOENN"); //TODO 汉化
#else
    _("HOENN");
#endif

const u8 gText_OhABite[] =
#ifdef CHINESE
    _("Oh! A bite!"); //TODO 汉化
#else
    _("Oh! A bite!");
#endif

const u8 gText_PokemonOnHook[] =
#ifdef CHINESE
    _("A POKéMON's on the hook!{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("A POKéMON's on the hook!{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_NotEvenANibble[] =
#ifdef CHINESE
    _("Not even a nibble…{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("Not even a nibble…{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_ItGotAway[] =
#ifdef CHINESE
    _("It got away…{PAUSE_UNTIL_PRESS}"); //TODO 汉化
#else
    _("It got away…{PAUSE_UNTIL_PRESS}");
#endif

const u8 gText_XWillBeSentToY[] =
#ifdef CHINESE
    _("{STR_VAR_2} will be\nsent to {STR_VAR_1}."); //TODO 汉化
#else
    _("{STR_VAR_2} will be\nsent to {STR_VAR_1}.");
#endif

const u8 gText_ByeByeVar1[] =
#ifdef CHINESE
    _("Bye-bye, {STR_VAR_2}!"); //TODO 汉化
#else
    _("Bye-bye, {STR_VAR_2}!");
#endif

const u8 gText_XSentOverY[] =
#ifdef CHINESE
    _("{STR_VAR_1} sent over {STR_VAR_3}."); //TODO 汉化
#else
    _("{STR_VAR_1} sent over {STR_VAR_3}.");
#endif

const u8 gText_TakeGoodCareOfX[] =
#ifdef CHINESE
    _("Take good care of {STR_VAR_3}!"); //TODO 汉化
#else
    _("Take good care of {STR_VAR_3}!");
#endif

// Easy chat group names
const u8 gEasyChatGroupName_Pokemon[] =
#ifdef CHINESE
    _("POKéMON"); //TODO 汉化
#else
    _("POKéMON");
#endif

const u8 gEasyChatGroupName_Trainer[] =
#ifdef CHINESE
    _("TRAINER"); //TODO 汉化
#else
    _("TRAINER");
#endif

const u8 gEasyChatGroupName_Status[] =
#ifdef CHINESE
    _("STATUS"); //TODO 汉化
#else
    _("STATUS");
#endif

const u8 gEasyChatGroupName_Battle[] =
#ifdef CHINESE
    _("BATTLE"); //TODO 汉化
#else
    _("BATTLE");
#endif

const u8 gEasyChatGroupName_Greetings[] =
#ifdef CHINESE
    _("GREETINGS"); //TODO 汉化
#else
    _("GREETINGS");
#endif

const u8 gEasyChatGroupName_People[] =
#ifdef CHINESE
    _("PEOPLE"); //TODO 汉化
#else
    _("PEOPLE");
#endif

const u8 gEasyChatGroupName_Voices[] =
#ifdef CHINESE
    _("VOICES"); //TODO 汉化
#else
    _("VOICES");
#endif

const u8 gEasyChatGroupName_Speech[] =
#ifdef CHINESE
    _("SPEECH"); //TODO 汉化
#else
    _("SPEECH");
#endif

const u8 gEasyChatGroupName_Endings[] =
#ifdef CHINESE
    _("ENDINGS"); //TODO 汉化
#else
    _("ENDINGS");
#endif

const u8 gEasyChatGroupName_Feelings[] =
#ifdef CHINESE
    _("FEELINGS"); //TODO 汉化
#else
    _("FEELINGS");
#endif

const u8 gEasyChatGroupName_Conditions[] =
#ifdef CHINESE
    _("CONDITIONS"); //TODO 汉化
#else
    _("CONDITIONS");
#endif

const u8 gEasyChatGroupName_Actions[] =
#ifdef CHINESE
    _("ACTIONS"); //TODO 汉化
#else
    _("ACTIONS");
#endif

const u8 gEasyChatGroupName_Lifestyle[] =
#ifdef CHINESE
    _("LIFESTYLE"); //TODO 汉化
#else
    _("LIFESTYLE");
#endif

const u8 gEasyChatGroupName_Hobbies[] =
#ifdef CHINESE
    _("HOBBIES"); //TODO 汉化
#else
    _("HOBBIES");
#endif

const u8 gEasyChatGroupName_Time[] =
#ifdef CHINESE
    _("TIME"); //TODO 汉化
#else
    _("TIME");
#endif

const u8 gEasyChatGroupName_Misc[] =
#ifdef CHINESE
    _("MISC."); //TODO 汉化
#else
    _("MISC.");
#endif

const u8 gEasyChatGroupName_Adjectives[] =
#ifdef CHINESE
    _("ADJECTIVES"); //TODO 汉化
#else
    _("ADJECTIVES");
#endif

const u8 gEasyChatGroupName_Events[] =
#ifdef CHINESE
    _("EVENTS"); //TODO 汉化
#else
    _("EVENTS");
#endif

const u8 gEasyChatGroupName_Move1[] =
#ifdef CHINESE
    _("MOVE 1"); //TODO 汉化
#else
    _("MOVE 1");
#endif

const u8 gEasyChatGroupName_Move2[] =
#ifdef CHINESE
    _("MOVE 2"); //TODO 汉化
#else
    _("MOVE 2");
#endif

const u8 gEasyChatGroupName_TrendySaying[] =
#ifdef CHINESE
    _("TRENDY SAYING"); //TODO 汉化
#else
    _("TRENDY SAYING");
#endif

const u8 gEasyChatGroupName_Pokemon2[] =
#ifdef CHINESE
    _("POKéMON2"); //TODO 汉化
#else
    _("POKéMON2");
#endif

const u8 gText_ThreeQuestionMarks[] =
#ifdef CHINESE
    _("???"); //TODO 汉化
#else
    _("???");
#endif

const u8 gText_MaxHP[] =
#ifdef CHINESE
    _("MAX. HP"); //TODO 汉化
#else
    _("MAX. HP");
#endif

const u8 gText_Attack[] =
#ifdef CHINESE
    _("ATTACK"); //TODO 汉化
#else
    _("ATTACK");
#endif

const u8 gText_Defense[] =
#ifdef CHINESE
    _("DEFENSE"); //TODO 汉化
#else
    _("DEFENSE");
#endif

const u8 gText_Speed[] =
#ifdef CHINESE
    _("SPEED"); //TODO 汉化
#else
    _("SPEED");
#endif

const u8 gText_SpAtk[] =
#ifdef CHINESE
    _("SP. ATK"); //TODO 汉化
#else
    _("SP. ATK");
#endif

const u8 gText_SpDef[] =
#ifdef CHINESE
    _("SP. DEF"); //TODO 汉化
#else
    _("SP. DEF");
#endif

const u8 gText_Plus[] =
#ifdef CHINESE
    _("{PLUS}"); //TODO 汉化
#else
    _("{PLUS}");
#endif

const u8 gText_Dash[] =
#ifdef CHINESE
    _("-"); //TODO 汉化
#else
    _("-");
#endif

const u8 gText_FromSpace[] =
#ifdef CHINESE
    _("From "); //TODO 汉化
#else
    _("From ");
#endif

const u8 gText_MixingRecords[] =
#ifdef CHINESE
    _("Mixing records…"); //TODO 汉化
#else
    _("Mixing records…");
#endif

const u8 gText_RecordMixingComplete[] =
#ifdef CHINESE
    _("Record mixing completed.\nThank you for waiting."); //TODO 汉化
#else
    _("Record mixing completed.\nThank you for waiting.");
#endif

const u8 gText_YourName[] =
#ifdef CHINESE
    _("YOUR NAME?"); //TODO 汉化
#else
    _("YOUR NAME?");
#endif

const u8 gText_BoxName[] =
#ifdef CHINESE
    _("BOX NAME?"); //TODO 汉化
#else
    _("BOX NAME?");
#endif

const u8 gText_PkmnsNickname[] =
#ifdef CHINESE
    _("{STR_VAR_1}'s nickname?"); //TODO 汉化
#else
    _("{STR_VAR_1}'s nickname?");
#endif

const u8 gText_TellHimTheWords[] =
#ifdef CHINESE
    _("Tell him the words."); //TODO 汉化
#else
    _("Tell him the words.");
#endif

const u8 gText_MoveOkBack[] =
#ifdef CHINESE
    _("{DPAD_NONE}MOVE  {A_BUTTON}OK  {B_BUTTON}BACK"); //TODO 汉化
#else
    _("{DPAD_NONE}MOVE  {A_BUTTON}OK  {B_BUTTON}BACK");
#endif

const u8 gText_CallCantBeMadeHere[] =
#ifdef CHINESE
    _("A call can't be made from here."); //TODO 汉化
#else
    _("A call can't be made from here.");
#endif

const u8 gText_ContestLady_Handsome[] =
#ifdef CHINESE
    _("HANDSOME"); //TODO 汉化
#else
    _("HANDSOME");
#endif

const u8 gText_ContestLady_Vinny[] =
#ifdef CHINESE
    _("VINNY"); //TODO 汉化
#else
    _("VINNY");
#endif

const u8 gText_ContestLady_Moreme[] =
#ifdef CHINESE
    _("MOREME"); //TODO 汉化
#else
    _("MOREME");
#endif

const u8 gText_ContestLady_Ironhard[] =
#ifdef CHINESE
    _("IRONHARD"); //TODO 汉化
#else
    _("IRONHARD");
#endif

const u8 gText_ContestLady_Muscle[] =
#ifdef CHINESE
    _("MUSCLE"); //TODO 汉化
#else
    _("MUSCLE");
#endif

const u8 gText_ContestLady_Coolness[] =
#ifdef CHINESE
    _("coolness"); //TODO 汉化
#else
    _("coolness");
#endif

const u8 gText_ContestLady_Beauty[] =
#ifdef CHINESE
    _("beauty"); //TODO 汉化
#else
    _("beauty");
#endif

const u8 gText_ContestLady_Cuteness[] =
#ifdef CHINESE
    _("cuteness"); //TODO 汉化
#else
    _("cuteness");
#endif

const u8 gText_ContestLady_Smartness[] =
#ifdef CHINESE
    _("smartness"); //TODO 汉化
#else
    _("smartness");
#endif

const u8 gText_ContestLady_Toughness[] =
#ifdef CHINESE
    _("toughness"); //TODO 汉化
#else
    _("toughness");
#endif

const u8 gText_QuizLady_Lady[] =
#ifdef CHINESE
    _("Lady"); //TODO 汉化
#else
    _("Lady");
#endif

const u8 gText_FavorLady_Slippery[] =
#ifdef CHINESE
    _("slippery"); //TODO 汉化
#else
    _("slippery");
#endif

const u8 gText_FavorLady_Roundish[] =
#ifdef CHINESE
    _("roundish"); //TODO 汉化
#else
    _("roundish");
#endif

const u8 gText_FavorLady_Whamish[] =
#ifdef CHINESE
    _("wham-ish"); //TODO 汉化
#else
    _("wham-ish");
#endif

const u8 gText_FavorLady_Shiny[] =
#ifdef CHINESE
    _("shiny"); //TODO 汉化
#else
    _("shiny");
#endif

const u8 gText_FavorLady_Sticky[] =
#ifdef CHINESE
    _("sticky"); //TODO 汉化
#else
    _("sticky");
#endif

const u8 gText_FavorLady_Pointy[] =
#ifdef CHINESE
    _("pointy"); //TODO 汉化
#else
    _("pointy");
#endif

const u8 gText_RentalPkmn2[] =
#ifdef CHINESE
    _("RENTAL POKéMON"); //TODO 汉化
#else
    _("RENTAL POKéMON");
#endif

const u8 gText_SelectFirstPkmn[] =
#ifdef CHINESE
    _("Select the first POKéMON."); //TODO 汉化
#else
    _("Select the first POKéMON.");
#endif

const u8 gText_SelectSecondPkmn[] =
#ifdef CHINESE
    _("Select the second POKéMON."); //TODO 汉化
#else
    _("Select the second POKéMON.");
#endif

const u8 gText_SelectThirdPkmn[] =
#ifdef CHINESE
    _("Select the third POKéMON."); //TODO 汉化
#else
    _("Select the third POKéMON.");
#endif

const u8 gText_Rent[] =
#ifdef CHINESE
    _("RENT"); //TODO 汉化
#else
    _("RENT");
#endif

const u8 gText_Summary[] =
#ifdef CHINESE
    _("SUMMARY"); //TODO 汉化
#else
    _("SUMMARY");
#endif

const u8 gText_Others2[] =
#ifdef CHINESE
    _("OTHERS"); //TODO 汉化
#else
    _("OTHERS");
#endif

const u8 gText_Deselect[] =
#ifdef CHINESE
    _("DESELECT"); //TODO 汉化
#else
    _("DESELECT");
#endif

const u8 gText_TheseThreePkmnOkay[] =
#ifdef CHINESE
    _("Are these three POKéMON OK?"); //TODO 汉化
#else
    _("Are these three POKéMON OK?");
#endif

const u8 gText_Yes2[] =
#ifdef CHINESE
    _("YES"); //TODO 汉化
#else
    _("YES");
#endif

const u8 gText_No2[] =
#ifdef CHINESE
    _("NO"); //TODO 汉化
#else
    _("NO");
#endif

const u8 gText_CantSelectSamePkmn[] =
#ifdef CHINESE
    _("Can't select same {PKMN}."); //TODO 汉化
#else
    _("Can't select same {PKMN}.");
#endif

const u8 gText_PkmnSwap[] =
#ifdef CHINESE
    _("POKéMON SWAP"); //TODO 汉化
#else
    _("POKéMON SWAP");
#endif

const u8 gText_SelectPkmnToSwap[] =
#ifdef CHINESE
    _("Select POKéMON to swap."); //TODO 汉化
#else
    _("Select POKéMON to swap.");
#endif

const u8 gText_SelectPkmnToAccept[] =
#ifdef CHINESE
    _("Select POKéMON to accept."); //TODO 汉化
#else
    _("Select POKéMON to accept.");
#endif

const u8 gText_Swap[] =
#ifdef CHINESE
    _("SWAP"); //TODO 汉化
#else
    _("SWAP");
#endif

const u8 gText_Summary2[] =
#ifdef CHINESE
    _("SUMMARY"); //TODO 汉化
#else
    _("SUMMARY");
#endif

const u8 gText_Rechoose[] =
#ifdef CHINESE
    _("RECHOOSE"); //TODO 汉化
#else
    _("RECHOOSE");
#endif

const u8 gText_QuitSwapping[] =
#ifdef CHINESE
    _("Quit swapping?"); //TODO 汉化
#else
    _("Quit swapping?");
#endif

const u8 gText_Yes3[] =
#ifdef CHINESE
    _("YES"); //TODO 汉化
#else
    _("YES");
#endif

const u8 gText_No3[] =
#ifdef CHINESE
    _("NO"); //TODO 汉化
#else
    _("NO");
#endif

const u8 gText_PkmnForSwap[] =
#ifdef CHINESE
    _("{PKMN} FOR SWAP"); //TODO 汉化
#else
    _("{PKMN} FOR SWAP");
#endif

const u8 gText_Cancel3[] =
#ifdef CHINESE
    _("CANCEL"); //TODO 汉化
#else
    _("CANCEL");
#endif

const u8 gText_Swap2[] =
#ifdef CHINESE
    _("SWAP"); // Unused //TODO 汉化
#else
    _("SWAP");   // Unused
#endif

const u8 gText_Accept[] =
#ifdef CHINESE
    _("ACCEPT"); // Unused //TODO 汉化
#else
    _("ACCEPT"); // Unused
#endif

const u8 gText_AcceptThisPkmn[] =
#ifdef CHINESE
    _("Accept this POKéMON?"); //TODO 汉化
#else
    _("Accept this POKéMON?");
#endif

const u8 gText_4Spaces[] =
#ifdef CHINESE
    _("    "); // Unused //TODO 汉化
#else
    _("   "); // Unused
#endif

const u8 gText_SamePkmnInPartyAlready[] =
#ifdef CHINESE
    _("Same {PKMN} in party already."); //TODO 汉化
#else
    _("Same {PKMN} in party already.");
#endif

const u8 gText_DecimalPoint[] =
#ifdef CHINESE
    _("."); //TODO 汉化
#else
    _(".");
#endif

const u8 gText_SavingPlayer[] =
#ifdef CHINESE
    _("PLAYER"); //TODO 汉化
#else
    _("PLAYER");
#endif

const u8 gText_SavingBadges[] =
#ifdef CHINESE
    _("BADGES"); //TODO 汉化
#else
    _("BADGES");
#endif

const u8 gText_SavingPokedex[] =
#ifdef CHINESE
    _("POKéDEX"); //TODO 汉化
#else
    _("POKéDEX");
#endif

const u8 gText_SavingTime[] =
#ifdef CHINESE
    _("TIME"); //TODO 汉化
#else
    _("TIME");
#endif

const u8 gText_WirelessCommStatus[] =
#ifdef CHINESE
    _("Wireless Communication Status"); //TODO 汉化
#else
    _("Wireless Communication Status");
#endif

const u8 gText_PeopleTrading[] =
#ifdef CHINESE
    _("People trading:"); //TODO 汉化
#else
    _("People trading:");
#endif

const u8 gText_PeopleBattling[] =
#ifdef CHINESE
    _("People battling:"); //TODO 汉化
#else
    _("People battling:");
#endif

const u8 gText_PeopleInUnionRoom[] =
#ifdef CHINESE
    _("People in the UNION ROOM:"); //TODO 汉化
#else
    _("People in the UNION ROOM:");
#endif

const u8 gText_PeopleCommunicating[] =
#ifdef CHINESE
    _("People communicating:"); //TODO 汉化
#else
    _("People communicating:");
#endif

const u8 gText_F700Players[] =
#ifdef CHINESE
    _("{DYNAMIC 0} players"); //TODO 汉化
#else
    _("{DYNAMIC 0} players");
#endif

const u8 gText_F701Players[] =
#ifdef CHINESE
    _("{DYNAMIC 1} players"); //TODO 汉化
#else
    _("{DYNAMIC 1} players");
#endif

const u8 gText_F702Players[] =
#ifdef CHINESE
    _("{DYNAMIC 2} players"); //TODO 汉化
#else
    _("{DYNAMIC 2} players");
#endif

const u8 gText_F703Players[] =
#ifdef CHINESE
    _("{DYNAMIC 3} players"); //TODO 汉化
#else
    _("{DYNAMIC 3} players");
#endif

const u8 *const gTextTable_Players[] = {
    gText_F700Players,
    gText_F701Players,
    gText_F702Players,
    gText_F703Players};

ALIGNED(4)
const u8 gText_WonderCards[] =
#ifdef CHINESE
    _("WONDER CARDS"); //TODO 汉化
#else
    _("WONDER CARDS");
#endif

ALIGNED(4)
const u8 gText_WonderNews[] =
#ifdef CHINESE
    _("WONDER NEWS"); //TODO 汉化
#else
    _("WONDER NEWS");
#endif

ALIGNED(4)
const u8 gText_WirelessCommunication[] =
#ifdef CHINESE
    _("WIRELESS COMMUNICATION"); //TODO 汉化
#else
    _("WIRELESS COMMUNICATION");
#endif

ALIGNED(4)
const u8 gText_Friend2[] =
#ifdef CHINESE
    _("FRIEND"); //TODO 汉化
#else
    _("FRIEND");
#endif

ALIGNED(4)
const u8 gText_Exit3[] =
#ifdef CHINESE
    _("EXIT"); //TODO 汉化
#else
    _("EXIT");
#endif

ALIGNED(4)
const u8 gText_Receive[] =
#ifdef CHINESE
    _("RECEIVE"); //TODO 汉化
#else
    _("RECEIVE");
#endif

ALIGNED(4)
const u8 gText_Send[] =
#ifdef CHINESE
    _("SEND"); //TODO 汉化
#else
    _("SEND");
#endif

ALIGNED(4)
const u8 gText_Toss[] =
#ifdef CHINESE
    _("TOSS"); //TODO 汉化
#else
    _("TOSS");
#endif

ALIGNED(4)
const u8 gText_VarietyOfEventsImportedWireless[] =
#ifdef CHINESE
    _("A variety of events will be imported\nover Wireless Communication."); //TODO 汉化
#else
    _("A variety of events will be imported\nover Wireless Communication.");
#endif

ALIGNED(4)
const u8 gText_WonderCardsInPossession[] =
#ifdef CHINESE
    _("Read the WONDER CARDS in your\npossession."); //TODO 汉化
#else
    _("Read the WONDER CARDS in your\npossession.");
#endif

ALIGNED(4)
const u8 gText_ReadNewsThatArrived[] =
#ifdef CHINESE
    _("Read the NEWS that arrived."); //TODO 汉化
#else
    _("Read the NEWS that arrived.");
#endif

ALIGNED(4)
const u8 gText_ReturnToTitle[] =
#ifdef CHINESE
    _("Return to the title screen."); //TODO 汉化
#else
    _("Return to the title screen.");
#endif

ALIGNED(4)
const u8 gText_DontHaveCardNewOneInput[] =
#ifdef CHINESE
    _("You don't have a WONDER CARD,\nso a new CARD will be input."); //TODO 汉化
#else
    _("You don't have a WONDER CARD,\nso a new CARD will be input.");
#endif

ALIGNED(4)
const u8 gText_DontHaveNewsNewOneInput[] =
#ifdef CHINESE
    _("You don't have any WONDER NEWS,\nso new NEWS will be input."); //TODO 汉化
#else
    _("You don't have any WONDER NEWS,\nso new NEWS will be input.");
#endif

ALIGNED(4)
const u8 gText_WhereShouldCardBeAccessed[] =
#ifdef CHINESE
    _("Where should the WONDER CARD\nbe accessed?"); //TODO 汉化
#else
    _("Where should the WONDER CARD\nbe accessed?");
#endif

ALIGNED(4)
const u8 gText_WhereShouldNewsBeAccessed[] =
#ifdef CHINESE
    _("Where should the WONDER NEWS\nbe accessed?"); //TODO 汉化
#else
    _("Where should the WONDER NEWS\nbe accessed?");
#endif

ALIGNED(4)
const u8 gText_CommunicationStandbyBButtonCancel[] =
#ifdef CHINESE
    _("Communication standby…\nB Button: Cancel"); // Unused //TODO 汉化
#else
    _("Communication standby…\nB Button: Cancel"); // Unused
#endif

ALIGNED(4)
const u8 gText_Communicating[] =
#ifdef CHINESE
    _("Communicating…"); //TODO 汉化
#else
    _("Communicating…");
#endif

ALIGNED(4)
const u8 gText_CommunicationCompleted[] =
#ifdef CHINESE
    _("Communication completed."); //TODO 汉化
#else
    _("Communication completed.");
#endif

ALIGNED(4)
const u8 gText_CommunicationError[] =
#ifdef CHINESE
    _("Communication error."); //TODO 汉化
#else
    _("Communication error.");
#endif

ALIGNED(4)
const u8 gText_CommunicationCanceled[] =
#ifdef CHINESE
    _("Communication has been canceled."); //TODO 汉化
#else
    _("Communication has been canceled.");
#endif

ALIGNED(4)
const u8 gText_ThrowAwayWonderCard[] =
#ifdef CHINESE
    _("Throw away the WONDER CARD\nand input a new CARD?"); //TODO 汉化
#else
    _("Throw away the WONDER CARD\nand input a new CARD?");
#endif

ALIGNED(4)
const u8 gText_HaventReceivedCardsGift[] =
#ifdef CHINESE
    _("You haven't received the CARD's gift\nyet. Input a new CARD anyway?"); //TODO 汉化
#else
    _("You haven't received the CARD's gift\nyet. Input a new CARD anyway?");
#endif

ALIGNED(4)
const u8 gText_WonderCardReceivedFrom[] =
#ifdef CHINESE
    _("A WONDER CARD has been received\nfrom {STR_VAR_1}."); //TODO 汉化
#else
    _("A WONDER CARD has been received\nfrom {STR_VAR_1}.");
#endif

ALIGNED(4)
const u8 gText_WonderNewsReceivedFrom[] =
#ifdef CHINESE
    _("A WONDER NEWS item has been\nreceived from {STR_VAR_1}."); //TODO 汉化
#else
    _("A WONDER NEWS item has been\nreceived from {STR_VAR_1}.");
#endif

ALIGNED(4)
const u8 gText_WonderCardReceived[] =
#ifdef CHINESE
    _("A new WONDER CARD has been\nreceived."); //TODO 汉化
#else
    _("A new WONDER CARD has been\nreceived.");
#endif

ALIGNED(4)
const u8 gText_WonderNewsReceived[] =
#ifdef CHINESE
    _("A new WONDER NEWS item has been\nreceived."); //TODO 汉化
#else
    _("A new WONDER NEWS item has been\nreceived.");
#endif

ALIGNED(4)
const u8 gText_NewStampReceived[] =
#ifdef CHINESE
    _("A new STAMP has been received."); //TODO 汉化
#else
    _("A new STAMP has been received.");
#endif

ALIGNED(4)
const u8 gText_NewTrainerReceived[] =
#ifdef CHINESE
    _("A new TRAINER has arrived."); //TODO 汉化
#else
    _("A new TRAINER has arrived.");
#endif

ALIGNED(4)
const u8 gText_AlreadyHadCard[] =
#ifdef CHINESE
    _("You already had that\nWONDER CARD."); //TODO 汉化
#else
    _("You already had that\nWONDER CARD.");
#endif

ALIGNED(4)
const u8 gText_AlreadyHadNews[] =
#ifdef CHINESE
    _("You already had that\nWONDER NEWS item."); //TODO 汉化
#else
    _("You already had that\nWONDER NEWS item.");
#endif

ALIGNED(4)
const u8 gText_AlreadyHadStamp[] =
#ifdef CHINESE
    _("You already had that\nSTAMP."); //TODO 汉化
#else
    _("You already had that\nSTAMP.");
#endif

ALIGNED(4)
const u8 gText_NoMoreRoomForStamps[] =
#ifdef CHINESE
    _("There's no more room for adding\nSTAMPS."); //TODO 汉化
#else
    _("There's no more room for adding\nSTAMPS.");
#endif

ALIGNED(4)
const u8 gText_RecordUploadedViaWireless[] =
#ifdef CHINESE
    _("Your record has been uploaded via\nWIRELESS COMMUNICATION."); //TODO 汉化
#else
    _("Your record has been uploaded via\nWIRELESS COMMUNICATION.");
#endif

ALIGNED(4)
const u8 gText_CantAcceptCardFromTrainer[] =
#ifdef CHINESE
    _("You can't accept a WONDER CARD\nfrom this TRAINER."); //TODO 汉化
#else
    _("You can't accept a WONDER CARD\nfrom this TRAINER.");
#endif

ALIGNED(4)
const u8 gText_CantAcceptNewsFromTrainer[] =
#ifdef CHINESE
    _("You can't accept WONDER NEWS\nfrom this TRAINER."); //TODO 汉化
#else
    _("You can't accept WONDER NEWS\nfrom this TRAINER.");
#endif

ALIGNED(4)
const u8 gText_NothingSentOver[] =
#ifdef CHINESE
    _("Nothing was sent over…"); //TODO 汉化
#else
    _("Nothing was sent over…");
#endif

ALIGNED(4)
const u8 gText_WhatToDoWithCards[] =
#ifdef CHINESE
    _("What would you like to do\nwith the WONDER CARDS?"); //TODO 汉化
#else
    _("What would you like to do\nwith the WONDER CARDS?");
#endif

ALIGNED(4)
const u8 gText_WhatToDoWithNews[] =
#ifdef CHINESE
    _("What would you like to do\nwith the WONDER NEWS?"); //TODO 汉化
#else
    _("What would you like to do\nwith the WONDER NEWS?");
#endif

ALIGNED(4)
const u8 gText_SendingWonderCard[] =
#ifdef CHINESE
    _("Sending your WONDER CARD…"); //TODO 汉化
#else
    _("Sending your WONDER CARD…");
#endif

ALIGNED(4)
const u8 gText_SendingWonderNews[] =
#ifdef CHINESE
    _("Sending your WONDER NEWS item…"); //TODO 汉化
#else
    _("Sending your WONDER NEWS item…");
#endif

ALIGNED(4)
const u8 gText_WonderCardSentTo[] =
#ifdef CHINESE
    _("Your WONDER CARD has been sent\nto {STR_VAR_1}."); //TODO 汉化
#else
    _("Your WONDER CARD has been sent\nto {STR_VAR_1}.");
#endif

ALIGNED(4)
const u8 gText_WonderNewsSentTo[] =
#ifdef CHINESE
    _("Your WONDER NEWS item has been\nsent to {STR_VAR_1}."); //TODO 汉化
#else
    _("Your WONDER NEWS item has been\nsent to {STR_VAR_1}.");
#endif

ALIGNED(4)
const u8 gText_StampSentTo[] =
#ifdef CHINESE
    _("A STAMP has been sent to {STR_VAR_1}."); //TODO 汉化
#else
    _("A STAMP has been sent to {STR_VAR_1}.");
#endif

ALIGNED(4)
const u8 gText_GiftSentTo[] =
#ifdef CHINESE
    _("A GIFT has been sent to {STR_VAR_1}."); //TODO 汉化
#else
    _("A GIFT has been sent to {STR_VAR_1}.");
#endif

ALIGNED(4)
const u8 gText_OtherTrainerHasCard[] =
#ifdef CHINESE
    _("The other TRAINER has the same\nWONDER CARD already."); //TODO 汉化
#else
    _("The other TRAINER has the same\nWONDER CARD already.");
#endif

ALIGNED(4)
const u8 gText_OtherTrainerHasNews[] =
#ifdef CHINESE
    _("The other TRAINER has the same\nWONDER NEWS already."); //TODO 汉化
#else
    _("The other TRAINER has the same\nWONDER NEWS already.");
#endif

ALIGNED(4)
const u8 gText_OtherTrainerHasStamp[] =
#ifdef CHINESE
    _("The other TRAINER has the same\nSTAMP already."); //TODO 汉化
#else
    _("The other TRAINER has the same\nSTAMP already.");
#endif

ALIGNED(4)
const u8 gText_OtherTrainerCanceled[] =
#ifdef CHINESE
    _("The other TRAINER canceled\ncommunication."); //TODO 汉化
#else
    _("The other TRAINER canceled\ncommunication.");
#endif

ALIGNED(4)
const u8 gText_CantSendGiftToTrainer[] =
#ifdef CHINESE
    _("You can't send a MYSTERY GIFT to\nthis TRAINER."); //TODO 汉化
#else
    _("You can't send a MYSTERY GIFT to\nthis TRAINER.");
#endif

ALIGNED(4)
const u8 gText_IfThrowAwayCardEventWontHappen[] =
#ifdef CHINESE
    _("If you throw away the CARD,\nits event won't happen. Okay?"); //TODO 汉化
#else
    _("If you throw away the CARD,\nits event won't happen. Okay?");
#endif

ALIGNED(4)
const u8 gText_OkayToDiscardNews[] =
#ifdef CHINESE
    _("Is it okay to discard this\nNEWS item?"); //TODO 汉化
#else
    _("Is it okay to discard this\nNEWS item?");
#endif

ALIGNED(4)
const u8 gText_HaventReceivedGiftOkayToDiscard[] =
#ifdef CHINESE
    _("You haven't received the\nGIFT. Is it okay to discard?"); //TODO 汉化
#else
    _("You haven't received the\nGIFT. Is it okay to discard?");
#endif

ALIGNED(4)
const u8 gText_DataWillBeSaved[] =
#ifdef CHINESE
    _("Data will be saved.\nPlease wait."); //TODO 汉化
#else
    _("Data will be saved.\nPlease wait.");
#endif

ALIGNED(4)
const u8 gText_SaveCompletedPressA[] =
#ifdef CHINESE
    _("Save completed.\nPlease press the A Button."); //TODO 汉化
#else
    _("Save completed.\nPlease press the A Button.");
#endif

ALIGNED(4)
const u8 gText_WonderCardThrownAway[] =
#ifdef CHINESE
    _("The WONDER CARD was thrown away."); //TODO 汉化
#else
    _("The WONDER CARD was thrown away.");
#endif

ALIGNED(4)
const u8 gText_WonderNewsThrownAway[] =
#ifdef CHINESE
    _("The WONDER NEWS was thrown away."); //TODO 汉化
#else
    _("The WONDER NEWS was thrown away.");
#endif

ALIGNED(4)
const u8 gText_MysteryGift[] =
#ifdef CHINESE
    _("MYSTERY GIFT"); //TODO 汉化
#else
    _("MYSTERY GIFT");
#endif

ALIGNED(4)
const u8 gText_PickOKExit[] =
#ifdef CHINESE
    _("{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}EXIT"); //TODO 汉化
#else
    _("{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}EXIT");
#endif

ALIGNED(4)
const u8 gText_PickOKCancel[] =
#ifdef CHINESE
    _("{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}CANCEL"); //TODO 汉化
#else
    _("{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}CANCEL");
#endif

const u8 gText_PlayersBattleResults[] =
#ifdef CHINESE
    _("{PLAYER}'s BATTLE RESULTS"); //TODO 汉化
#else
    _("{PLAYER}'s BATTLE RESULTS");
#endif

const u8 gText_TotalRecordWLD[] =
#ifdef CHINESE
    _("TOTAL RECORD W:{STR_VAR_1} L:{STR_VAR_2} D:{STR_VAR_3}"); //TODO 汉化
#else
    _("TOTAL RECORD W:{STR_VAR_1} L:{STR_VAR_2} D:{STR_VAR_3}");
#endif

const u8 gText_WinLoseDraw[] =
#ifdef CHINESE
    _("{CLEAR_TO 0x53}WIN{CLEAR_TO 0x80}LOSE{CLEAR_TO 0xB0}DRAW"); //TODO 汉化
#else
    _("{CLEAR_TO 0x53}WIN{CLEAR_TO 0x80}LOSE{CLEAR_TO 0xB0}DRAW");
#endif

const u8 gText_CommunicationStandby5[] =
#ifdef CHINESE
    _("Communication standby…"); //TODO 汉化
#else
    _("Communication standby…");
#endif

const u8 gText_QuitTheGame[] =
#ifdef CHINESE
    _("不玩了?"); //TODO 汉化
#else
    _("Quit the game?");
#endif

const u8 gText_YouveGot9999Coins[] =
#ifdef CHINESE
    _("你得到了9,999 枚硬币。"); //TODO 汉化
#else
    _("You've got 9,999 COINS.");
#endif

const u8 gText_YouveRunOutOfCoins[] =
#ifdef CHINESE
    _("你把硬币花的一干二净，\n游戏结束!"); //TODO 汉化
#else
    _("You've run out of COINS.\nGame over!");
#endif

const u8 gText_YouDontHaveThreeCoins[] =
#ifdef CHINESE
    _("你没有3枚硬币"); //TODO 汉化
#else
    _("You don't have three COINS.");
#endif

const u8 gText_ReelTimeHelp[] =
#ifdef CHINESE
    _("REEL TIME\nHere's your chance to take\naim and nail marks!\nReel Time continues for the\nawarded number of spins.\nIt all ends on a Big Bonus."); //TODO 汉化
#else
    _("REEL TIME\nHere's your chance to take\naim and nail marks!\nReel Time continues for the\nawarded number of spins.\nIt all ends on a Big Bonus.");
#endif

const u8 gDaycareText_GetAlongVeryWell[] =
#ifdef CHINESE
    _("The two seem to get along\nvery well."); //TODO 汉化
#else
    _("The two seem to get along\nvery well.");
#endif

const u8 gDaycareText_GetAlong[] =
#ifdef CHINESE
    _("The two seem to get along."); //TODO 汉化
#else
    _("The two seem to get along.");
#endif

const u8 gDaycareText_DontLikeOther[] =
#ifdef CHINESE
    _("The two don't seem to like\neach other much."); //TODO 汉化
#else
    _("The two don't seem to like\neach other much.");
#endif

const u8 gDaycareText_PlayOther[] =
#ifdef CHINESE
    _("The two prefer to play with other\nPOKéMON than each other."); //TODO 汉化
#else
    _("The two prefer to play with other\nPOKéMON than each other.");
#endif

const u8 gText_NewLine2[] = _("\n");

const u8 gText_Exit4[] =
#ifdef CHINESE
    _("EXIT"); //TODO 汉化
#else
    _("EXIT");
#endif

const u8 gText_Lv[] = _("{LV}");

const u8 gText_TimeBoard[] =
#ifdef CHINESE
    _("TIME BOARD"); //TODO 汉化
#else
    _("TIME BOARD");
#endif

const u8 gText_TimeCleared[] =
#ifdef CHINESE
    _("TIME CLEARED "); //TODO 汉化
#else
    _("TIME CLEARED ");
#endif

const u8 gText_XMinYDotZSec[] =
#ifdef CHINESE
    _("{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec."); //TODO 汉化
#else
    _("{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.");
#endif

const u8 gText_TrainerHill1F[] =
#ifdef CHINESE
    _("1F"); //TODO 汉化
#else
    _("1F");
#endif

const u8 gText_TrainerHill2F[] =
#ifdef CHINESE
    _("2F"); //TODO 汉化
#else
    _("2F");
#endif

const u8 gText_TrainerHill3F[] =
#ifdef CHINESE
    _("3F"); //TODO 汉化
#else
    _("3F");
#endif

const u8 gText_TrainerHill4F[] =
#ifdef CHINESE
    _("4F"); //TODO 汉化
#else
    _("4F");
#endif

const u8 gText_TeachWhichMoveToPkmn[] =
#ifdef CHINESE
    _("Teach which move to {STR_VAR_1}?"); //TODO 汉化
#else
    _("Teach which move to {STR_VAR_1}?");
#endif

const u8 gText_MoveRelearnerTeachMoveConfirm[] =
#ifdef CHINESE
    _("Teach {STR_VAR_2}?"); //TODO 汉化
#else
    _("Teach {STR_VAR_2}?");
#endif

const u8 gText_MoveRelearnerPkmnLearnedMove[] =
#ifdef CHINESE
    _("{STR_VAR_1} learned\n{STR_VAR_2}!"); //TODO 汉化
#else
    _("{STR_VAR_1} learned\n{STR_VAR_2}!");
#endif

const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] =
#ifdef CHINESE
    _("{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\pBut {STR_VAR_1} can't learn more\nthan four moves.\pDelete an older move to make\nroom for {STR_VAR_2}?"); //TODO 汉化
#else
    _("{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\pBut {STR_VAR_1} can't learn more\nthan four moves.\pDelete an older move to make\nroom for {STR_VAR_2}?");
#endif

const u8 gText_MoveRelearnerStopTryingToTeachMove[] =
#ifdef CHINESE
    _("Stop trying to teach\n{STR_VAR_2}?"); //TODO 汉化
#else
    _("Stop trying to teach\n{STR_VAR_2}?");
#endif

const u8 gText_MoveRelearnerAndPoof[] =
#ifdef CHINESE
    _("{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p"); //TODO 汉化
#else
    _("{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p");
#endif

const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] =
#ifdef CHINESE
    _("{STR_VAR_1} forgot {STR_VAR_3}.\pAnd…\p{STR_VAR_1} learned {STR_VAR_2}."); //TODO 汉化
#else
    _("{STR_VAR_1} forgot {STR_VAR_3}.\pAnd…\p{STR_VAR_1} learned {STR_VAR_2}.");
#endif

const u8 gText_MoveRelearnedPkmnDidNotLearnMove[] =
#ifdef CHINESE
    _("{STR_VAR_1} did not learn the\nmove {STR_VAR_2}."); // Unused //TODO 汉化
#else
    _("{STR_VAR_1} did not learn the\nmove {STR_VAR_2}."); // Unused
#endif

const u8 gText_MoveRelearnerGiveUp[] =
#ifdef CHINESE
    _("Give up trying to teach a new\nmove to {STR_VAR_1}?"); //TODO 汉化
#else
    _("Give up trying to teach a new\nmove to {STR_VAR_1}?");
#endif

const u8 gText_MoveRelearnerWhichMoveToForget[] =
#ifdef CHINESE
    _("Which move should be\nforgotten?\p"); //TODO 汉化
#else
    _("Which move should be\nforgotten?\p");
#endif

const u8 gText_MoveRelearnerBattleMoves[] =
#ifdef CHINESE
    _("BATTLE MOVES"); //TODO 汉化
#else
    _("BATTLE MOVES");
#endif

const u8 gText_MoveRelearnerContestMovesTitle[] =
#ifdef CHINESE
    _("CONTEST MOVES"); //TODO 汉化
#else
    _("CONTEST MOVES");
#endif

const u8 gText_MoveRelearnerType[] =
#ifdef CHINESE
    _("TYPE/"); // Unused //TODO 汉化
#else
    _("TYPE/"); // Unused
#endif

const u8 gText_MoveRelearnerPP[] =
#ifdef CHINESE
    _("PP/"); //TODO 汉化
#else
    _("PP/");
#endif

const u8 gText_MoveRelearnerPower[] =
#ifdef CHINESE
    _("POWER/"); //TODO 汉化
#else
    _("POWER/");
#endif

const u8 gText_MoveRelearnerAccuracy[] =
#ifdef CHINESE
    _("ACCURACY/"); //TODO 汉化
#else
    _("ACCURACY/");
#endif

const u8 gText_MoveRelearnerAppeal[] =
#ifdef CHINESE
    _("APPEAL"); //TODO 汉化
#else
    _("APPEAL");
#endif

const u8 gText_MoveRelearnerJam[] =
#ifdef CHINESE
    _("JAM"); //TODO 汉化
#else
    _("JAM");
#endif

const u8 gText_Kira[] =
#ifdef CHINESE
    _("KIRA"); //TODO 汉化
#else
    _("KIRA");
#endif

const u8 gText_Amy[] =
#ifdef CHINESE
    _("AMY"); //TODO 汉化
#else
    _("AMY");
#endif

const u8 gText_John[] =
#ifdef CHINESE
    _("JOHN"); //TODO 汉化
#else
    _("JOHN");
#endif

const u8 gText_Roy[] =
#ifdef CHINESE
    _("ROY"); //TODO 汉化
#else
    _("ROY");
#endif

const u8 gText_Gabby[] =
#ifdef CHINESE
    _("GABBY"); //TODO 汉化
#else
    _("GABBY");
#endif

const u8 gText_Anna[] =
#ifdef CHINESE
    _("ANNA"); //TODO 汉化
#else
    _("ANNA");
#endif

const u8 gText_ClearAllSaveData[] =
#ifdef CHINESE
    _("Clear all save data areas?"); //TODO 汉化
#else
    _("Clear all save data areas?");
#endif

const u8 gText_ClearingData[] =
#ifdef CHINESE
    _("Clearing data…\nPlease wait."); //TODO 汉化
#else
    _("Clearing data…\nPlease wait.");
#endif

const u8 gText_IsThisTheCorrectTime[] =
#ifdef CHINESE
    _("Is this the correct time?"); //TODO 汉化
#else
    _("Is this the correct time?");
#endif

const u8 gText_Confirm3[] =
#ifdef CHINESE
    _("CONFIRM"); //TODO 汉化
#else
    _("CONFIRM");
#endif

const u8 gText_Cancel4[] =
#ifdef CHINESE
    _("CANCEL"); //TODO 汉化
#else
    _("CANCEL");
#endif

const u8 gText_MrStoneMatchCallDesc[] =
#ifdef CHINESE
    _("DEVON PRES"); //TODO 汉化
#else
    _("DEVON PRES");
#endif

const u8 gText_MrStoneMatchCallName[] =
#ifdef CHINESE
    _("MR. STONE"); //TODO 汉化
#else
    _("MR. STONE");
#endif

const u8 gText_StevenMatchCallDesc[] =
#ifdef CHINESE
    _("HARD AS ROCK"); //TODO 汉化
#else
    _("HARD AS ROCK");
#endif

const u8 gText_StevenMatchCallName[] =
#ifdef CHINESE
    _("STEVEN"); //TODO 汉化
#else
    _("STEVEN");
#endif

const u8 gText_MayBrendanMatchCallDesc[] =
#ifdef CHINESE
    _("RAD NEIGHBOR"); //TODO 汉化
#else
    _("RAD NEIGHBOR");
#endif

const u8 gText_NormanMatchCallDesc[] =
#ifdef CHINESE
    _("RELIABLE ONE"); //TODO 汉化
#else
    _("RELIABLE ONE");
#endif

const u8 gText_MomMatchCallDesc[] =
#ifdef CHINESE
    _("CALM & KIND"); //TODO 汉化
#else
    _("CALM & KIND");
#endif

const u8 gText_WallyMatchCallDesc[] =
#ifdef CHINESE
    _("{PKMN} LOVER"); //TODO 汉化
#else
    _("{PKMN} LOVER");
#endif

const u8 gText_NormanMatchCallName[] =
#ifdef CHINESE
    _("DAD"); //TODO 汉化
#else
    _("DAD");
#endif

const u8 gText_MomMatchCallName[] =
#ifdef CHINESE
    _("MOM"); //TODO 汉化
#else
    _("MOM");
#endif

const u8 gText_ScottMatchCallDesc[] =
#ifdef CHINESE
    _("ELUSIVE EYES"); //TODO 汉化
#else
    _("ELUSIVE EYES");
#endif

const u8 gText_ScottMatchCallName[] =
#ifdef CHINESE
    _("SCOTT"); //TODO 汉化
#else
    _("SCOTT");
#endif

const u8 gText_RoxanneMatchCallDesc[] =
#ifdef CHINESE
    _("ROCKIN' WHIZ"); //TODO 汉化
#else
    _("ROCKIN' WHIZ");
#endif

const u8 gText_BrawlyMatchCallDesc[] =
#ifdef CHINESE
    _("THE BIG HIT"); //TODO 汉化
#else
    _("THE BIG HIT");
#endif

const u8 gText_WattsonMatchCallDesc[] =
#ifdef CHINESE
    _("SWELL SHOCK"); //TODO 汉化
#else
    _("SWELL SHOCK");
#endif

const u8 gText_FlanneryMatchCallDesc[] =
#ifdef CHINESE
    _("PASSION BURN"); //TODO 汉化
#else
    _("PASSION BURN");
#endif

const u8 gText_WinonaMatchCallDesc[] =
#ifdef CHINESE
    _("SKY TAMER"); //TODO 汉化
#else
    _("SKY TAMER");
#endif

const u8 gText_TateLizaMatchCallDesc[] =
#ifdef CHINESE
    _("MYSTIC DUO"); //TODO 汉化
#else
    _("MYSTIC DUO");
#endif

const u8 gText_JuanMatchCallDesc[] =
#ifdef CHINESE
    _("DANDY CHARM"); //TODO 汉化
#else
    _("DANDY CHARM");
#endif

const u8 gText_EliteFourMatchCallDesc[] =
#ifdef CHINESE
    _("ELITE FOUR"); //TODO 汉化
#else
    _("ELITE FOUR");
#endif

const u8 gText_ChampionMatchCallDesc[] =
#ifdef CHINESE
    _("CHAMPION"); //TODO 汉化
#else
    _("CHAMPION");
#endif

const u8 gText_ProfBirchMatchCallDesc[] =
#ifdef CHINESE
    _("{PKMN} PROF."); //TODO 汉化
#else
    _("{PKMN} PROF.");
#endif

const u8 gText_CommStandbyAwaitingOtherPlayer[] =
#ifdef CHINESE
    _("Communication standby…\nAwaiting another player to choose."); //TODO 汉化
#else
    _("Communication standby…\nAwaiting another player to choose.");
#endif

const u8 gText_BattleWasRefused[] =
#ifdef CHINESE
    _("The battle was refused.{PAUSE 60}"); //TODO 汉化
#else
    _("The battle was refused.{PAUSE 60}");
#endif

const u8 gText_RefusedBattle[] =
#ifdef CHINESE
    _("Refused the battle.{PAUSE 60}"); //TODO 汉化
#else
    _("Refused the battle.{PAUSE 60}");
#endif

const u8 gText_NoWeather[] =
#ifdef CHINESE
    _("NO WEATHER"); // Below are unused debug names for weather types //TODO 汉化
#else
    _("NO WEATHER");  // Below are unused debug names for weather types
#endif

const u8 gText_Sunny[] =
#ifdef CHINESE
    _("SUNNY"); // Unused //TODO 汉化
#else
    _("SUNNY");       // Unused
#endif

const u8 gText_Sunny2[] =
#ifdef CHINESE
    _("SUNNY2"); // Unused //TODO 汉化
#else
    _("SUNNY2");      // Unused
#endif

const u8 gText_Rain[] =
#ifdef CHINESE
    _("RAIN"); // Unused //TODO 汉化
#else
    _("RAIN");        // Unused
#endif

const u8 gText_Snow[] =
#ifdef CHINESE
    _("SNOW"); // Unused //TODO 汉化
#else
    _("SNOW");        // Unused
#endif

const u8 gText_Lightning[] =
#ifdef CHINESE
    _("LIGHTNING"); // Unused //TODO 汉化
#else
    _("LIGHTNING");   // Unused
#endif

const u8 gText_Fog[] =
#ifdef CHINESE
    _("FOG"); // Unused //TODO 汉化
#else
    _("FOG");         // Unused
#endif

const u8 gText_VolcanoAsh[] =
#ifdef CHINESE
    _("VOLCANO ASH"); // Unused //TODO 汉化
#else
    _("VOLCANO ASH"); // Unused
#endif

const u8 gText_Sandstorm[] =
#ifdef CHINESE
    _("SANDSTORM"); // Unused //TODO 汉化
#else
    _("SANDSTORM");   // Unused
#endif

const u8 gText_Fog2[] =
#ifdef CHINESE
    _("FOG2"); // Unused //TODO 汉化
#else
    _("FOG2");        // Unused
#endif

const u8 gText_Seafloor[] =
#ifdef CHINESE
    _("SEAFLOOR"); // Unused //TODO 汉化
#else
    _("SEAFLOOR");    // Unused
#endif

const u8 gText_Cloudy[] =
#ifdef CHINESE
    _("CLOUDY"); // Unused //TODO 汉化
#else
    _("CLOUDY");      // Unused
#endif

const u8 gText_Sunny3[] =
#ifdef CHINESE
    _("SUNNY3"); // Unused //TODO 汉化
#else
    _("SUNNY3");      // Unused
#endif

const u8 gText_HeavyRain[] =
#ifdef CHINESE
    _("HEAVY RAIN"); // Unused //TODO 汉化
#else
    _("HEAVY RAIN");  // Unused
#endif

const u8 gText_Seafloor2[] =
#ifdef CHINESE
    _("SEAFLOOR2"); // Unused //TODO 汉化
#else
    _("SEAFLOOR2");   // Unused
#endif

const u8 gText_DelAll[] =
#ifdef CHINESE
    _("DEL. ALL"); //TODO 汉化
#else
    _("DEL. ALL");
#endif

const u8 gText_Cancel5[] =
#ifdef CHINESE
    _("CANCEL"); //TODO 汉化
#else
    _("CANCEL");
#endif

const u8 gText_Ok2[] =
#ifdef CHINESE
    _("OK"); //TODO 汉化
#else
    _("OK");
#endif

const u8 gText_Quiz[] =
#ifdef CHINESE
    _("QUIZ"); //TODO 汉化
#else
    _("QUIZ");
#endif

const u8 gText_Answer[] =
#ifdef CHINESE
    _("ANSWER"); //TODO 汉化
#else
    _("ANSWER");
#endif

const u8 gText_PokeBalls[] =
#ifdef CHINESE
    _("POKé BALLS"); //TODO 汉化
#else
    _("POKé BALLS");
#endif

const u8 gText_Berry[] =
#ifdef CHINESE
    _("BERRY"); //TODO 汉化
#else
    _("BERRY");
#endif

const u8 gText_Berries[] =
#ifdef CHINESE
    _("BERRIES"); //TODO 汉化
#else
    _("BERRIES");
#endif
