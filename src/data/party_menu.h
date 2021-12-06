static const struct BgTemplate sPartyMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};

enum
{
    PARTY_BOX_LEFT_COLUMN,
    PARTY_BOX_RIGHT_COLUMN
};

static const struct PartyMenuBoxInfoRects sPartyBoxInfoRects[] =
{
    [PARTY_BOX_LEFT_COLUMN] = 
    {
        BlitBitmapToPartyWindow_LeftColumn, 
        {
            //The below are the x, y, width, and height for each of the following info
            24, 11, 40, 13, // Nickname
            32, 20, 32,  8, // Level
            64, 20,  8,  8, // Gender
            38, 37, 24,  8, // HP
            53, 37, 24,  8, // Max HP
            24, 35, 48,  3  // HP bar
        }, 
        12, 34, 64, 16      // Description text (e.g. NO USE)
    },
    [PARTY_BOX_RIGHT_COLUMN] = 
    {
        BlitBitmapToPartyWindow_RightColumn, 
        {
             // See above comment
             22,  3, 40, 13, // Nickname
             30, 12, 32,  8, // Level
             62, 12,  8,  8, // Gender
            102, 12, 24,  8, // HP
            117, 12, 24,  8, // Max HP
             88, 10, 48,  3  // HP bar
        }, 
        77, 4, 64, 16        // Description text
    },
};


// Each layout array has an array for each of the 6 party slots
// The array for each slot has the sprite coords of its various sprites in the following order
// Pokemon icon (x, y), held item (x, y), status condition (x, y), menu pokeball (x, y)
static const u8 sPartyMenuSpriteCoords[PARTY_LAYOUT_COUNT][PARTY_SIZE][4 * 2] =
{
    [PARTY_LAYOUT_SINGLE] = 
    {
        { 16,  40,  20,  50,  50,  52,  16,  34},
        {104,  18, 108,  28, 136,  27, 102,  25},
        {104,  42, 108,  52, 136,  51, 102,  49},
        {104,  66, 108,  76, 136,  75, 102,  73},
        {104,  90, 108, 100, 136,  99, 102,  97},
        {104, 114, 108, 124, 136, 123, 102, 121},
    },
    [PARTY_LAYOUT_DOUBLE] = 
    {
        {16, 24, 20, 34, 50, 36, 16, 18},
        {16, 80, 20, 90, 50, 92, 16, 74},
        {104, 18, 108, 28, 136, 27, 102, 25},
        {104, 50, 108, 60, 136, 59, 102, 57},
        {104, 82, 108, 92, 136, 91, 102, 89},
        {104, 114, 108, 124, 136, 123, 102, 121},
    },
    [PARTY_LAYOUT_MULTI] = 
    {
        {16, 24, 20, 34, 50, 36, 16, 18},
        {16, 80, 20, 90, 50, 92, 16, 74},
        {104, 26, 106, 36, 136, 35, 102, 33},
        {104, 50, 106, 60, 136, 59, 102, 57},
        {104, 82, 106, 92, 136, 91, 102, 89},
        {104, 106, 106, 116, 136, 115, 102, 113},
    },
    [PARTY_LAYOUT_MULTI_SHOWCASE] = 
    {
        {16, 32, 20, 42, 50, 44, 16, 26},
        {104, 34, 106, 44, 136, 43, 102, 41},
        {104, 58, 106, 68, 136, 67, 102, 65},
        {16, 104, 20, 114, 50, 116, 16, 98},
        {104, 106, 106, 116, 136, 115, 102, 113},
        {104, 130, 106, 140, 136, 139, 102, 137},
    },
};

// Used only when both Cancel and Confirm are present
static const u32 sConfirmButton_Tilemap[] = INCBIN_U32("graphics/interface/party_menu_confirm_button.bin");
static const u32 sCancelButton_Tilemap[] = INCBIN_U32("graphics/interface/party_menu_cancel_button.bin");

// Text colors for BG, FG, and Shadow in that order
static const u8 sFontColorTable[][3] =
{
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_DARK_GRAY},  // Default
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_GREEN},      // Unused
    {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_2,  TEXT_DYNAMIC_COLOR_3},  // Gender symbol
    {TEXT_COLOR_WHITE,       TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY}, // Selection actions
    {TEXT_COLOR_WHITE,       TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_BLUE}, // Field moves
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},  // Unused
};

static const struct WindowTemplate sSinglePartyMenuWindowTemplate[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 3,
        .width = 10,
        .height = 7,
        .paletteNum = 3,
        .baseBlock = 0x63,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 1,
        .width = 18,
        .height = 3,
        .paletteNum = 4,
        .baseBlock = 0xA9,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 4,
        .width = 18,
        .height = 3,
        .paletteNum = 5,
        .baseBlock = 0xDF,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 7,
        .width = 18,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 0x115,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 10,
        .width = 18,
        .height = 3,
        .paletteNum = 7,
        .baseBlock = 0x14B,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 13,
        .width = 18,
        .height = 3,
        .paletteNum = 8,
        .baseBlock = 0x181,
    },
    {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x1DF,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sDoublePartyMenuWindowTemplate[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 7,
        .paletteNum = 3,
        .baseBlock = 0x63,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 8,
        .width = 10,
        .height = 7,
        .paletteNum = 4,
        .baseBlock = 0xA9,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 1,
        .width = 18,
        .height = 3,
        .paletteNum = 5,
        .baseBlock = 0xEF,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 5,
        .width = 18,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 0x125,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 9,
        .width = 18,
        .height = 3,
        .paletteNum = 7,
        .baseBlock = 0x15B,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 13,
        .width = 18,
        .height = 3,
        .paletteNum = 8,
        .baseBlock = 0x191,
    },
    {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x1DF,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sMultiPartyMenuWindowTemplate[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 7,
        .paletteNum = 3,
        .baseBlock = 0x63,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 8,
        .width = 10,
        .height = 7,
        .paletteNum = 4,
        .baseBlock = 0xA9,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 2,
        .width = 18,
        .height = 3,
        .paletteNum = 5,
        .baseBlock = 0xEF,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 5,
        .width = 18,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 0x125,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 9,
        .width = 18,
        .height = 3,
        .paletteNum = 7,
        .baseBlock = 0x15B,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 12,
        .width = 18,
        .height = 3,
        .paletteNum = 8,
        .baseBlock = 0x191,
    },
    {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x1DF,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sShowcaseMultiPartyMenuWindowTemplate[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 2,
        .width = 10,
        .height = 7,
        .paletteNum = 3,
        .baseBlock = 0x63,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 3,
        .width = 18,
        .height = 3,
        .paletteNum = 5,
        .baseBlock = 0xA9,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 6,
        .width = 18,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 0xDF,
    },
    {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 11,
        .width = 10,
        .height = 7,
        .paletteNum = 4,
        .baseBlock = 0x115,
    },
    {
        .bg = 2,
        .tilemapLeft = 12,
        .tilemapTop = 12,
        .width = 18,
        .height = 3,
        .paletteNum = 7,
        .baseBlock = 0x16B,
    },
    {
        .bg = 2,
        .tilemapLeft = 12,
        .tilemapTop = 15,
        .width = 18,
        .height = 3,
        .paletteNum = 8,
        .baseBlock = 0x1A1,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sCancelButtonWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 17,
    .width = 6,
    .height = 2,
    .paletteNum = 3,
    .baseBlock = 0x1C7,
};

static const struct WindowTemplate sMultiCancelButtonWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 18,
    .width = 6,
    .height = 2,
    .paletteNum = 3,
    .baseBlock = 0x1C7,
};

static const struct WindowTemplate sConfirmButtonWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 16,
    .width = 6,
    .height = 2,
    .paletteNum = 3,
    .baseBlock = 0x1D3,
};

static const struct WindowTemplate sDefaultPartyMsgWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 1,
    .tilemapTop = 17,
    .width = 21,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x24F,
};

static const struct WindowTemplate sDoWhatWithMonMsgWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 1,
    .tilemapTop = 17,
    .width = 16,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x279,
};

static const struct WindowTemplate sDoWhatWithItemMsgWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 1,
    .tilemapTop = 17,
    .width = 20,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x299,
};

static const struct WindowTemplate sDoWhatWithMailMsgWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 1,
    .tilemapTop = 17,
    .width = 18,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x299,
};

static const struct WindowTemplate sWhichMoveMsgWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 1,
    .tilemapTop = 17,
    .width = 16,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x299,
};

static const struct WindowTemplate sAlreadyHoldingOneMsgWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 20,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x299,
};

static const struct WindowTemplate sItemGiveTakeWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 23,
    .tilemapTop = 13,
    .width = 6,
    .height = 6,
    .paletteNum = 14,
    .baseBlock = 0x39D,
};

static const struct WindowTemplate sMailReadTakeWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 21,
    .tilemapTop = 13,
    .width = 8,
    .height = 6,
    .paletteNum = 14,
    .baseBlock = 0x39D,
};

static const struct WindowTemplate sMoveSelectWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 19,
    .tilemapTop = 11,
    .width = 10,
    .height = 8,
    .paletteNum = 14,
    .baseBlock = 0x2E9,
};

static const struct WindowTemplate sPartyMenuYesNoWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 0x2E9,
};

static const struct WindowTemplate sLevelUpStatsWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 19,
    .tilemapTop = 1,
    .width = 10,
    .height = 11,
    .paletteNum = 14,
    .baseBlock = 0x2E9,
};

static const struct WindowTemplate sUnusedWindowTemplate1 =
{
    .bg = 2,
    .tilemapLeft = 2,
    .tilemapTop = 15,
    .width = 27,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 0x1DF,
};

static const struct WindowTemplate sUnusedWindowTemplate2 =
{
    .bg = 2,
    .tilemapLeft = 0,
    .tilemapTop = 13,
    .width = 18,
    .height = 3,
    .paletteNum = 12,
    .baseBlock = 0x39D,
};

// Tile nums
static const u8 sMainSlotTileNums[] = {24, 25, 25, 25, 25, 25, 25, 25, 25, 26,
                                       32, 33, 33, 33, 33, 33, 33, 33, 33, 34,
                                       32, 33, 33, 33, 33, 33, 33, 33, 33, 34,
                                       32, 33, 33, 33, 33, 33, 33, 33, 33, 34,
                                       40, 59, 60, 58, 58, 58, 58, 58, 58, 61,
                                       15, 16, 16, 16, 16, 16, 16, 16, 16, 17,
                                       46, 47, 47, 47, 47, 47, 47, 47, 47, 48};

static const u8 sMainSlotTileNums_Egg[] = {24, 25, 25, 25, 25, 25, 25, 25, 25, 26,
                                           32, 33, 33, 33, 33, 33, 33, 33, 33, 34,
                                           32, 33, 33, 33, 33, 33, 33, 33, 33, 34,
                                           32, 33, 33, 33, 33, 33, 33, 33, 33, 34,
                                           40, 41, 41, 41, 41, 41, 41, 41, 41, 42,
                                           15, 16, 16, 16, 16, 16, 16, 16, 16, 17,
                                           46, 47, 47, 47, 47, 47, 47, 47, 47, 48};

static const u8 sOtherSlotsTileNums[] = {43, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45,
                                         49, 33, 33, 33, 33, 33, 33, 33, 33, 52, 53, 51, 51, 51, 51, 51, 51, 54,
                                         55, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57};

static const u8 sOtherSlotsTileNums_Egg[] = {43, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45,
                                             49, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 50,
                                             55, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57};

static const u8 sEmptySlotTileNums[] = {21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23,
                                        30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31,
                                        37, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 39};

// Palette offsets
static const u8 sGenderPalOffsets[] = {11, 12};
static const u8 sHPBarPalOffsets[] = {9, 10};
static const u8 sPartyBoxPalOffsets1[] = {4, 5, 6};
static const u8 sPartyBoxPalOffsets2[] = {1, 7, 8};
static const u8 sPartyBoxNoMonPalOffsets[] = {1, 11, 12};

// Palette ids
static const u8 sGenderMalePalIds[] = {59, 60};
static const u8 sGenderFemalePalIds[] = {75, 76};
static const u8 sHPBarGreenPalIds[] = {57, 58};
static const u8 sHPBarYellowPalIds[] = {73, 74};
static const u8 sHPBarRedPalIds[] = {89, 90};
static const u8 sPartyBoxEmptySlotPalIds1[] = {52, 53, 54};
static const u8 sPartyBoxMultiPalIds1[] = {68, 69, 70};
static const u8 sPartyBoxFaintedPalIds1[] = {84, 85, 86};
static const u8 sPartyBoxCurrSelectionPalIds1[] = {116, 117, 118};
static const u8 sPartyBoxCurrSelectionMultiPalIds[] = {132, 133, 134};
static const u8 sPartyBoxCurrSelectionFaintedPalIds[] = {148, 149, 150};
static const u8 sPartyBoxSelectedForActionPalIds1[] = {100, 101, 102};
static const u8 sPartyBoxEmptySlotPalIds2[] = {49, 55, 56};
static const u8 sPartyBoxMultiPalIds2[] = {65, 71, 72};
static const u8 sPartyBoxFaintedPalIds2[] = {81, 87, 88};
static const u8 sPartyBoxCurrSelectionPalIds2[] = {97, 103, 104};
static const u8 sPartyBoxSelectedForActionPalIds2[] = {161, 167, 168};
static const u8 sPartyBoxNoMonPalIds[] = {17, 27, 28};

static const u8 *const sActionStringTable[] =
{
    [PARTY_MSG_CHOOSE_MON]             = gText_ChoosePokemon,
    [PARTY_MSG_CHOOSE_MON_OR_CANCEL]   = gText_ChoosePokemonCancel,
    [PARTY_MSG_CHOOSE_MON_AND_CONFIRM] = gText_ChoosePokemonConfirm,
    [PARTY_MSG_MOVE_TO_WHERE]          = gText_MoveToWhere,
    [PARTY_MSG_TEACH_WHICH_MON]        = gText_TeachWhichPokemon,
    [PARTY_MSG_USE_ON_WHICH_MON]       = gText_UseOnWhichPokemon,
    [PARTY_MSG_GIVE_TO_WHICH_MON]      = gText_GiveToWhichPokemon,
    [PARTY_MSG_NOTHING_TO_CUT]         = gText_NothingToCut,
    [PARTY_MSG_CANT_SURF_HERE]         = gText_CantSurfHere,
    [PARTY_MSG_ALREADY_SURFING]        = gText_AlreadySurfing,
    [PARTY_MSG_CURRENT_TOO_FAST]       = gText_CurrentIsTooFast,
    [PARTY_MSG_ENJOY_CYCLING]          = gText_EnjoyCycling,
    [PARTY_MSG_ALREADY_IN_USE]         = gText_InUseAlready_PM,
    [PARTY_MSG_CANT_USE_HERE]          = gText_CantUseHere,
    [PARTY_MSG_NO_MON_FOR_BATTLE]      = gText_NoPokemonForBattle,
    [PARTY_MSG_CHOOSE_MON_2]           = gText_ChoosePokemon2,
    [PARTY_MSG_NOT_ENOUGH_HP]          = gText_NotEnoughHp,
    [PARTY_MSG_X_MONS_ARE_NEEDED]      = gText_PokemonAreNeeded,
    [PARTY_MSG_MONS_CANT_BE_SAME]      = gText_PokemonCantBeSame,
    [PARTY_MSG_NO_SAME_HOLD_ITEMS]     = gText_NoIdenticalHoldItems,
    [PARTY_MSG_UNUSED]                 = gText_EmptyString2,
    [PARTY_MSG_DO_WHAT_WITH_MON]       = gText_DoWhatWithPokemon,
    [PARTY_MSG_RESTORE_WHICH_MOVE]     = gText_RestoreWhichMove,
    [PARTY_MSG_BOOST_PP_WHICH_MOVE]    = gText_BoostPp,
    [PARTY_MSG_DO_WHAT_WITH_ITEM]      = gText_DoWhatWithItem,
    [PARTY_MSG_DO_WHAT_WITH_MAIL]      = gText_DoWhatWithMail,
    [PARTY_MSG_ALREADY_HOLDING_ONE]    = gText_AlreadyHoldingOne,
};

static const u8 *const sDescriptionStringTable[] =
{
    [PARTYBOX_DESC_NO_USE]     = gText_NoUse,
    [PARTYBOX_DESC_ABLE_3]     = gText_Able,
    [PARTYBOX_DESC_FIRST]      = gText_First_PM,
    [PARTYBOX_DESC_SECOND]     = gText_Second_PM,
    [PARTYBOX_DESC_THIRD]      = gText_Third_PM,
    [PARTYBOX_DESC_FOURTH]     = gText_Fourth,
    [PARTYBOX_DESC_ABLE]       = gText_Able2,
    [PARTYBOX_DESC_NOT_ABLE]   = gText_NotAble,
    [PARTYBOX_DESC_ABLE_2]     = gText_Able3,
    [PARTYBOX_DESC_NOT_ABLE_2] = gText_NotAble2,
    [PARTYBOX_DESC_LEARNED]    = gText_Learned,
    [PARTYBOX_DESC_HAVE]       = gText_Have,
    [PARTYBOX_DESC_DONT_HAVE]  = gText_DontHave,
};

static const u16 sUnusedData[] =
{
    0x0108, 0x0151, 0x0160, 0x015b, 0x002e, 0x005c, 0x0102, 0x0153, 0x014b, 0x00ed, 0x00f1, 0x010d, 0x003a, 0x003b, 0x003f, 0x0071,
    0x00b6, 0x00f0, 0x00ca, 0x00db, 0x00da, 0x004c, 0x00e7, 0x0055, 0x0057, 0x0059, 0x00d8, 0x005b, 0x005e, 0x00f7, 0x0118, 0x0068,
    0x0073, 0x015f, 0x0035, 0x00bc, 0x00c9, 0x007e, 0x013d, 0x014c, 0x0103, 0x0107, 0x0122, 0x009c, 0x00d5, 0x00a8, 0x00d3, 0x011d,
    0x0121, 0x013b, 0x000f, 0x0013, 0x0039, 0x0046, 0x0094, 0x00f9, 0x007f, 0x0123,
};

enum
{
    MENU_SUMMARY,
    MENU_SWITCH,
    MENU_CANCEL1,
    MENU_ITEM,
    MENU_GIVE,
    MENU_TAKE_ITEM,
    MENU_MAIL,
    MENU_TAKE_MAIL,
    MENU_READ,
    MENU_CANCEL2,
    MENU_SHIFT,
    MENU_SEND_OUT,
    MENU_ENTER,
    MENU_NO_ENTRY,
    MENU_STORE,
    MENU_REGISTER,
    MENU_TRADE1,
    MENU_TRADE2,
    MENU_TOSS,
    MENU_FIELD_MOVES,
};

enum
{
    FIELD_MOVE_CUT,
    FIELD_MOVE_FLASH,
    FIELD_MOVE_ROCK_SMASH,
    FIELD_MOVE_STRENGTH,
    FIELD_MOVE_SURF,
    FIELD_MOVE_FLY,
    FIELD_MOVE_DIVE,
    FIELD_MOVE_WATERFALL,
    FIELD_MOVE_TELEPORT,
    FIELD_MOVE_DIG,
    FIELD_MOVE_SECRET_POWER,
    FIELD_MOVE_MILK_DRINK,
    FIELD_MOVE_SOFT_BOILED,
    FIELD_MOVE_SWEET_SCENT,
};

// What a weird choice of table termination;
#define FIELD_MOVE_TERMINATOR MOVE_SWORDS_DANCE

struct
{
    const u8 *text;
    TaskFunc func;
} static const sCursorOptions[] =
{
    [MENU_SUMMARY] = {gText_Summary5, CursorCb_Summary},
    [MENU_SWITCH] = {gText_Switch2, CursorCb_Switch},
    [MENU_CANCEL1] = {gText_Cancel2, CursorCb_Cancel1},
    [MENU_ITEM] = {gText_Item, CursorCb_Item},
    [MENU_GIVE] = {gMenuText_Give, CursorCb_Give},
    [MENU_TAKE_ITEM] = {gText_Take, CursorCb_TakeItem},
    [MENU_MAIL] = {gText_Mail, CursorCb_Mail},
    [MENU_TAKE_MAIL] = {gText_Take2, CursorCb_TakeMail},
    [MENU_READ] = {gText_Read2, CursorCb_Read},
    [MENU_CANCEL2] = {gText_Cancel2, CursorCb_Cancel2},
    [MENU_SHIFT] = {gText_Shift, CursorCb_SendMon},
    [MENU_SEND_OUT] = {gText_SendOut, CursorCb_SendMon},
    [MENU_ENTER] = {gText_Enter, CursorCb_Enter},
    [MENU_NO_ENTRY] = {gText_NoEntry, CursorCb_NoEntry},
    [MENU_STORE] = {gText_Store, CursorCb_Store},
    [MENU_REGISTER] = {gText_Register, CursorCb_Register},
    [MENU_TRADE1] = {gText_Trade4, CursorCb_Trade1},
    [MENU_TRADE2] = {gText_Trade4, CursorCb_Trade2},
    [MENU_TOSS] = {gMenuText_Toss, CursorCb_Toss},
    [MENU_FIELD_MOVES + FIELD_MOVE_CUT] = {gMoveNames[MOVE_CUT], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_FLASH] = {gMoveNames[MOVE_FLASH], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_ROCK_SMASH] = {gMoveNames[MOVE_ROCK_SMASH], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_STRENGTH] = {gMoveNames[MOVE_STRENGTH], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_SURF] = {gMoveNames[MOVE_SURF], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_FLY] = {gMoveNames[MOVE_FLY], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_DIVE] = {gMoveNames[MOVE_DIVE], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_WATERFALL] = {gMoveNames[MOVE_WATERFALL], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_TELEPORT] = {gMoveNames[MOVE_TELEPORT], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_DIG] = {gMoveNames[MOVE_DIG], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_SECRET_POWER] = {gMoveNames[MOVE_SECRET_POWER], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_MILK_DRINK] = {gMoveNames[MOVE_MILK_DRINK], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_SOFT_BOILED] = {gMoveNames[MOVE_SOFT_BOILED], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_SWEET_SCENT] = {gMoveNames[MOVE_SWEET_SCENT], CursorCb_FieldMove},
};

static const u8 sPartyMenuAction_SummarySwitchCancel[] = {MENU_SUMMARY, MENU_SWITCH, MENU_CANCEL1};
static const u8 sPartyMenuAction_ShiftSummaryCancel[] = {MENU_SHIFT, MENU_SUMMARY, MENU_CANCEL1};
static const u8 sPartyMenuAction_SendOutSummaryCancel[] = {MENU_SEND_OUT, MENU_SUMMARY, MENU_CANCEL1};
static const u8 sPartyMenuAction_SummaryCancel[] = {MENU_SUMMARY, MENU_CANCEL1};
static const u8 sPartyMenuAction_EnterSummaryCancel[] = {MENU_ENTER, MENU_SUMMARY, MENU_CANCEL1};
static const u8 sPartyMenuAction_NoEntrySummaryCancel[] = {MENU_NO_ENTRY, MENU_SUMMARY, MENU_CANCEL1};
static const u8 sPartyMenuAction_StoreSummaryCancel[] = {MENU_STORE, MENU_SUMMARY, MENU_CANCEL1};
static const u8 sPartyMenuAction_GiveTakeItemCancel[] = {MENU_GIVE, MENU_TAKE_ITEM, MENU_CANCEL2};
static const u8 sPartyMenuAction_ReadTakeMailCancel[] = {MENU_READ, MENU_TAKE_MAIL, MENU_CANCEL2};
static const u8 sPartyMenuAction_RegisterSummaryCancel[] = {MENU_REGISTER, MENU_SUMMARY, MENU_CANCEL1};
static const u8 sPartyMenuAction_TradeSummaryCancel1[] = {MENU_TRADE1, MENU_SUMMARY, MENU_CANCEL1};
static const u8 sPartyMenuAction_TradeSummaryCancel2[] = {MENU_TRADE2, MENU_SUMMARY, MENU_CANCEL1};
static const u8 sPartyMenuAction_TakeItemTossCancel[] = {MENU_TAKE_ITEM, MENU_TOSS, MENU_CANCEL1};

// IDs for the action lists that appear when a party mon is selected
enum
{
    ACTIONS_NONE,
    ACTIONS_SWITCH,
    ACTIONS_SHIFT,
    ACTIONS_SEND_OUT,
    ACTIONS_ENTER,
    ACTIONS_NO_ENTRY,
    ACTIONS_STORE,
    ACTIONS_SUMMARY_ONLY,
    ACTIONS_ITEM,
    ACTIONS_MAIL,
    ACTIONS_REGISTER,
    ACTIONS_TRADE,
    ACTIONS_SPIN_TRADE,
    ACTIONS_TAKEITEM_TOSS
};

static const u8 *const sPartyMenuActions[] =
{
    [ACTIONS_NONE]          = NULL,
    [ACTIONS_SWITCH]        = sPartyMenuAction_SummarySwitchCancel,
    [ACTIONS_SHIFT]         = sPartyMenuAction_ShiftSummaryCancel,
    [ACTIONS_SEND_OUT]      = sPartyMenuAction_SendOutSummaryCancel,
    [ACTIONS_ENTER]         = sPartyMenuAction_EnterSummaryCancel,
    [ACTIONS_NO_ENTRY]      = sPartyMenuAction_NoEntrySummaryCancel,
    [ACTIONS_STORE]         = sPartyMenuAction_StoreSummaryCancel,
    [ACTIONS_SUMMARY_ONLY]  = sPartyMenuAction_SummaryCancel,
    [ACTIONS_ITEM]          = sPartyMenuAction_GiveTakeItemCancel,
    [ACTIONS_MAIL]          = sPartyMenuAction_ReadTakeMailCancel,
    [ACTIONS_REGISTER]      = sPartyMenuAction_RegisterSummaryCancel,
    [ACTIONS_TRADE]         = sPartyMenuAction_TradeSummaryCancel1,
    [ACTIONS_SPIN_TRADE]    = sPartyMenuAction_TradeSummaryCancel2,
    [ACTIONS_TAKEITEM_TOSS] = sPartyMenuAction_TakeItemTossCancel,
};

static const u8 sPartyMenuActionCounts[] =
{
    [ACTIONS_NONE]          = 0,
    [ACTIONS_SWITCH]        = ARRAY_COUNT(sPartyMenuAction_SummarySwitchCancel),
    [ACTIONS_SHIFT]         = ARRAY_COUNT(sPartyMenuAction_ShiftSummaryCancel),
    [ACTIONS_SEND_OUT]      = ARRAY_COUNT(sPartyMenuAction_SendOutSummaryCancel),
    [ACTIONS_ENTER]         = ARRAY_COUNT(sPartyMenuAction_EnterSummaryCancel),
    [ACTIONS_NO_ENTRY]      = ARRAY_COUNT(sPartyMenuAction_NoEntrySummaryCancel),
    [ACTIONS_STORE]         = ARRAY_COUNT(sPartyMenuAction_StoreSummaryCancel),
    [ACTIONS_SUMMARY_ONLY]  = ARRAY_COUNT(sPartyMenuAction_SummaryCancel),
    [ACTIONS_ITEM]          = ARRAY_COUNT(sPartyMenuAction_GiveTakeItemCancel),
    [ACTIONS_MAIL]          = ARRAY_COUNT(sPartyMenuAction_ReadTakeMailCancel),
    [ACTIONS_REGISTER]      = ARRAY_COUNT(sPartyMenuAction_RegisterSummaryCancel),
    [ACTIONS_TRADE]         = ARRAY_COUNT(sPartyMenuAction_TradeSummaryCancel1),
    [ACTIONS_SPIN_TRADE]    = ARRAY_COUNT(sPartyMenuAction_TradeSummaryCancel2),
    [ACTIONS_TAKEITEM_TOSS] = ARRAY_COUNT(sPartyMenuAction_TakeItemTossCancel)
};

static const u16 sFieldMoves[] =
{
    MOVE_CUT, MOVE_FLASH, MOVE_ROCK_SMASH, MOVE_STRENGTH, MOVE_SURF, MOVE_FLY, MOVE_DIVE, MOVE_WATERFALL, MOVE_TELEPORT,
    MOVE_DIG, MOVE_SECRET_POWER, MOVE_MILK_DRINK, MOVE_SOFT_BOILED, MOVE_SWEET_SCENT, FIELD_MOVE_TERMINATOR
};

struct
{
    bool8 (*fieldMoveFunc)(void);
    u8 msgId;
} static const sFieldMoveCursorCallbacks[] =
{
    [FIELD_MOVE_CUT]          = {SetUpFieldMove_Cut,         PARTY_MSG_NOTHING_TO_CUT},
    [FIELD_MOVE_FLASH]        = {SetUpFieldMove_Flash,       PARTY_MSG_CANT_USE_HERE},
    [FIELD_MOVE_ROCK_SMASH]   = {SetUpFieldMove_RockSmash,   PARTY_MSG_CANT_USE_HERE},
    [FIELD_MOVE_STRENGTH]     = {SetUpFieldMove_Strength,    PARTY_MSG_CANT_USE_HERE},
    [FIELD_MOVE_SURF]         = {SetUpFieldMove_Surf,        PARTY_MSG_CANT_SURF_HERE},
    [FIELD_MOVE_FLY]          = {SetUpFieldMove_Fly,         PARTY_MSG_CANT_USE_HERE},
    [FIELD_MOVE_DIVE]         = {SetUpFieldMove_Dive,        PARTY_MSG_CANT_USE_HERE},
    [FIELD_MOVE_WATERFALL]    = {SetUpFieldMove_Waterfall,   PARTY_MSG_CANT_USE_HERE},
    [FIELD_MOVE_TELEPORT]     = {SetUpFieldMove_Teleport,    PARTY_MSG_CANT_USE_HERE},
    [FIELD_MOVE_DIG]          = {SetUpFieldMove_Dig,         PARTY_MSG_CANT_USE_HERE},
    [FIELD_MOVE_SECRET_POWER] = {SetUpFieldMove_SecretPower, PARTY_MSG_CANT_USE_HERE},
    [FIELD_MOVE_MILK_DRINK]   = {SetUpFieldMove_SoftBoiled,  PARTY_MSG_NOT_ENOUGH_HP},
    [FIELD_MOVE_SOFT_BOILED]  = {SetUpFieldMove_SoftBoiled,  PARTY_MSG_NOT_ENOUGH_HP},
    [FIELD_MOVE_SWEET_SCENT]  = {SetUpFieldMove_SweetScent,  PARTY_MSG_CANT_USE_HERE},
};

static const u8 *const sUnionRoomTradeMessages[] =
{
    [UR_TRADE_MSG_NOT_MON_PARTNER_WANTS - 1]       = gText_NotPkmnOtherTrainerWants,
    [UR_TRADE_MSG_NOT_EGG - 1]                     = gText_ThatIsntAnEgg,
    [UR_TRADE_MSG_MON_CANT_BE_TRADED_1 - 1]        = gText_PkmnCantBeTradedNow,
    [UR_TRADE_MSG_MON_CANT_BE_TRADED_2 - 1]        = gText_PkmnCantBeTradedNow,
    [UR_TRADE_MSG_PARTNERS_MON_CANT_BE_TRADED - 1] = gText_OtherTrainersPkmnCantBeTraded,
    [UR_TRADE_MSG_EGG_CANT_BE_TRADED -1]           = gText_EggCantBeTradedNow,
    [UR_TRADE_MSG_PARTNER_CANT_ACCEPT_MON - 1]     = gText_OtherTrainerCantAcceptPkmn,
    [UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_1 - 1]   = gText_CantTradeWithTrainer,
    [UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_2 - 1]   = gText_CantTradeWithTrainer,
};

static const u32 sHeldItemGfx[] = INCBIN_U32("graphics/interface/hold_icons.4bpp");
static const u16 sHeldItemPalette[] = INCBIN_U16("graphics/interface/hold_icons.gbapal");

static const struct OamData sOamData_HeldItem =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_HeldItem[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HeldMail[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_HeldItem[] =
{
    sSpriteAnim_HeldItem,
    sSpriteAnim_HeldMail,
};

static const struct SpriteSheet sSpriteSheet_HeldItem =
{
    sHeldItemGfx, sizeof(sHeldItemGfx), 0xd750
};

static const struct SpritePalette sSpritePalette_HeldItem =
{
    sHeldItemPalette, 0xd750
};

static const struct SpriteTemplate sSpriteTemplate_HeldItem =
{
    0xd750,
    0xd750,
    &sOamData_HeldItem,
    sSpriteAnimTable_HeldItem,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static const struct OamData sOamData_MenuPokeball =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sPokeballAnim_Closed[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sPokeballAnim_Open[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_MenuPokeball[] =
{
    sPokeballAnim_Closed,
    sPokeballAnim_Open
};

static const struct CompressedSpriteSheet sSpriteSheet_MenuPokeball =
{
    gPartyMenuPokeball_Gfx, 0x400, 0x04b0
};

static const struct CompressedSpritePalette sSpritePalette_MenuPokeball =
{
    gPartyMenuPokeball_Pal, 0x04b0
};

// Used for the pokeball sprite on each party slot / Cancel button
static const struct SpriteTemplate sSpriteTemplate_MenuPokeball =
{
    .tileTag = 0x04b0,
    .paletteTag = 0x04b0,
    .oam = &sOamData_MenuPokeball,
    .anims = sSpriteAnimTable_MenuPokeball,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_MenuPokeballSmall =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSmallPokeballAnim_Closed[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSmallPokeballAnim_Open[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSmallPokeballAnim_Blank1[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSmallPokeballAnim_Blank2[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd sSmallPokeballAnim_Blank3[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sSmallPokeballAnim_Blank4[] =
{
    ANIMCMD_FRAME(20, 0),
    ANIMCMD_END
};

// The blanks below are never used. See SpriteCB_BounceConfirmCancelButton, where they were intended to be used
static const union AnimCmd *const sSpriteAnimTable_MenuPokeballSmall[] =
{
    sSmallPokeballAnim_Closed,
    sSmallPokeballAnim_Open,
    sSmallPokeballAnim_Blank1,
    sSmallPokeballAnim_Blank2,
    sSmallPokeballAnim_Blank3,
    sSmallPokeballAnim_Blank4
};

static const struct CompressedSpriteSheet sSpriteSheet_MenuPokeballSmall =
{
    gPartyMenuPokeballSmall_Gfx, 0x0300, 0x04b1
};

// Used for the pokeball sprite next to Cancel and Confirm when both are present, otherwise sSpriteTemplate_MenuPokeball is used
static const struct SpriteTemplate sSpriteTemplate_MenuPokeballSmall =
{
    .tileTag = 1201,
    .paletteTag = 1200,
    .oam = &sOamData_MenuPokeballSmall,
    .anims = sSpriteAnimTable_MenuPokeballSmall,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_StatusCondition =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_StatusPoison[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusParalyzed[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusSleep[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusFrozen[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusBurn[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusPokerus[] =
{
    ANIMCMD_FRAME(20, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusFaint[] =
{
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Blank[] =
{
    ANIMCMD_FRAME(28, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteTemplate_StatusCondition[] =
{
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
    sSpriteAnim_StatusFragile,
    sSpriteAnim_Blank
};

static const struct CompressedSpriteSheet sSpriteSheet_StatusIcons =
{
    gStatusGfx_Icons, 0x400, 1202
};

static const struct CompressedSpritePalette sSpritePalette_StatusIcons =
{
    gStatusPal_Icons, 1202
};

static const struct SpriteTemplate sSpriteTemplate_StatusIcons =
{
    .tileTag = 1202,
    .paletteTag = 1202,
    .oam = &sOamData_StatusCondition,
    .anims = sSpriteTemplate_StatusCondition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u8 *const sUnused_StatStrings[] =
{
    gText_HP4,
    gText_Attack3,
    gText_Defense3,
    gText_SpAtk4,
    gText_SpDef4,
    gText_Speed2
};

const u16 gTMHMMoves[] =
{
    [ITEM_TM001 - ITEM_TM001] = MOVE_MEGA_PUNCH,
    [ITEM_TM002 - ITEM_TM001] = MOVE_RAZOR_WIND,
    [ITEM_TM003 - ITEM_TM001] = MOVE_SWORDS_DANCE,
    [ITEM_TM004 - ITEM_TM001] = MOVE_WHIRLWIND,
    [ITEM_TM005 - ITEM_TM001] = MOVE_MEGA_KICK,
    [ITEM_TM006 - ITEM_TM001] = MOVE_TOXIC,
    [ITEM_TM007 - ITEM_TM001] = MOVE_HORN_DRILL,
    [ITEM_TM008 - ITEM_TM001] = MOVE_BODY_SLAM,
    [ITEM_TM009 - ITEM_TM001] = MOVE_TAKE_DOWN,
    [ITEM_TM010 - ITEM_TM001] = MOVE_DOUBLE_EDGE,
    [ITEM_TM011 - ITEM_TM001] = MOVE_BUBBLE_BEAM,
    [ITEM_TM012 - ITEM_TM001] = MOVE_WATER_GUN,
    [ITEM_TM013 - ITEM_TM001] = MOVE_ICE_BEAM,
    [ITEM_TM014 - ITEM_TM001] = MOVE_BLIZZARD,
    [ITEM_TM015 - ITEM_TM001] = MOVE_HYPER_BEAM,
    [ITEM_TM016 - ITEM_TM001] = MOVE_PAY_DAY,
    [ITEM_TM017 - ITEM_TM001] = MOVE_SUBMISSION,
    [ITEM_TM018 - ITEM_TM001] = MOVE_COUNTER,
    [ITEM_TM019 - ITEM_TM001] = MOVE_SEISMIC_TOSS,
    [ITEM_TM020 - ITEM_TM001] = MOVE_RAGE,
    [ITEM_TM021 - ITEM_TM001] = MOVE_MEGA_DRAIN,
    [ITEM_TM022 - ITEM_TM001] = MOVE_SOLAR_BEAM,
    [ITEM_TM023 - ITEM_TM001] = MOVE_DRAGON_RAGE,
    [ITEM_TM024 - ITEM_TM001] = MOVE_THUNDERBOLT,
    [ITEM_TM025 - ITEM_TM001] = MOVE_THUNDER,
    [ITEM_TM026 - ITEM_TM001] = MOVE_EARTHQUAKE,
    [ITEM_TM027 - ITEM_TM001] = MOVE_FISSURE,
    [ITEM_TM028 - ITEM_TM001] = MOVE_DIG,
    [ITEM_TM029 - ITEM_TM001] = MOVE_PSYCHIC,
    [ITEM_TM030 - ITEM_TM001] = MOVE_TELEPORT,
    [ITEM_TM031 - ITEM_TM001] = MOVE_MIMIC,
    [ITEM_TM032 - ITEM_TM001] = MOVE_DOUBLE_TEAM,
    [ITEM_TM033 - ITEM_TM001] = MOVE_REFLECT,
    [ITEM_TM034 - ITEM_TM001] = MOVE_BIDE,
    [ITEM_TM035 - ITEM_TM001] = MOVE_METRONOME,
    [ITEM_TM036 - ITEM_TM001] = MOVE_SELF_DESTRUCT,
    [ITEM_TM037 - ITEM_TM001] = MOVE_EGG_BOMB,
    [ITEM_TM038 - ITEM_TM001] = MOVE_FIRE_BLAST,
    [ITEM_TM039 - ITEM_TM001] = MOVE_SWIFT,
    [ITEM_TM040 - ITEM_TM001] = MOVE_SKULL_BASH,
    [ITEM_TM041 - ITEM_TM001] = MOVE_SOFT_BOILED,
    [ITEM_TM042 - ITEM_TM001] = MOVE_DREAM_EATER,
    [ITEM_TM043 - ITEM_TM001] = MOVE_SKY_ATTACK,
    [ITEM_TM044 - ITEM_TM001] = MOVE_REST,
    [ITEM_TM045 - ITEM_TM001] = MOVE_THUNDER_WAVE,
    [ITEM_TM046 - ITEM_TM001] = MOVE_PSYWAVE,
    [ITEM_TM047 - ITEM_TM001] = MOVE_EXPLOSION,
    [ITEM_TM048 - ITEM_TM001] = MOVE_ROCK_SLIDE,
    [ITEM_TM049 - ITEM_TM001] = MOVE_TRI_ATTACK,
    [ITEM_TM050 - ITEM_TM001] = MOVE_SUBSTITUTE,
    [ITEM_TM051 - ITEM_TM001] = MOVE_DYNAMIC_PUNCH,
    [ITEM_TM052 - ITEM_TM001] = MOVE_HEADBUTT,
    [ITEM_TM053 - ITEM_TM001] = MOVE_CURSE,
    [ITEM_TM054 - ITEM_TM001] = MOVE_ROLLOUT,
    [ITEM_TM055 - ITEM_TM001] = MOVE_ROAR,
    [ITEM_TM056 - ITEM_TM001] = MOVE_ZAP_CANNON,
    [ITEM_TM057 - ITEM_TM001] = MOVE_ROCK_SMASH,
    [ITEM_TM058 - ITEM_TM001] = MOVE_PSYCH_UP,
    [ITEM_TM059 - ITEM_TM001] = MOVE_HIDDEN_POWER,
    [ITEM_TM060 - ITEM_TM001] = MOVE_SUNNY_DAY,
    [ITEM_TM061 - ITEM_TM001] = MOVE_SWEET_SCENT,
    [ITEM_TM062 - ITEM_TM001] = MOVE_SNORE,
    [ITEM_TM063 - ITEM_TM001] = MOVE_ICY_WIND,
    [ITEM_TM064 - ITEM_TM001] = MOVE_PROTECT,
    [ITEM_TM065 - ITEM_TM001] = MOVE_RAIN_DANCE,
    [ITEM_TM066 - ITEM_TM001] = MOVE_GIGA_DRAIN,
    [ITEM_TM067 - ITEM_TM001] = MOVE_ENDURE,
    [ITEM_TM068 - ITEM_TM001] = MOVE_FRUSTRATION,
    [ITEM_TM069 - ITEM_TM001] = MOVE_IRON_TAIL,
    [ITEM_TM070 - ITEM_TM001] = MOVE_DRAGON_BREATH,
    [ITEM_TM071 - ITEM_TM001] = MOVE_RETURN,
    [ITEM_TM072 - ITEM_TM001] = MOVE_SHADOW_BALL,
    [ITEM_TM073 - ITEM_TM001] = MOVE_MUD_SLAP,
    [ITEM_TM074 - ITEM_TM001] = MOVE_ICE_PUNCH,
    [ITEM_TM075 - ITEM_TM001] = MOVE_SWAGGER,
    [ITEM_TM076 - ITEM_TM001] = MOVE_SLEEP_TALK,
    [ITEM_TM077 - ITEM_TM001] = MOVE_SLUDGE_BOMB,
    [ITEM_TM078 - ITEM_TM001] = MOVE_SANDSTORM,
    [ITEM_TM079 - ITEM_TM001] = MOVE_DEFENSE_CURL,
    [ITEM_TM080 - ITEM_TM001] = MOVE_THUNDER_PUNCH,
    [ITEM_TM081 - ITEM_TM001] = MOVE_DETECT,
    [ITEM_TM082 - ITEM_TM001] = MOVE_ATTRACT,
    [ITEM_TM083 - ITEM_TM001] = MOVE_THIEF,
    [ITEM_TM084 - ITEM_TM001] = MOVE_STEEL_WING,
    [ITEM_TM085 - ITEM_TM001] = MOVE_FIRE_PUNCH,
    [ITEM_TM086 - ITEM_TM001] = MOVE_FURY_CUTTER,
    [ITEM_TM087 - ITEM_TM001] = MOVE_NIGHTMARE,
    [ITEM_TM088 - ITEM_TM001] = MOVE_FOCUS_PUNCH,
    [ITEM_TM089 - ITEM_TM001] = MOVE_DRAGON_CLAW,
    [ITEM_TM090 - ITEM_TM001] = MOVE_WATER_PULSE,
    [ITEM_TM091 - ITEM_TM001] = MOVE_CALM_MIND,
    [ITEM_TM092 - ITEM_TM001] = MOVE_HAIL,
    [ITEM_TM093 - ITEM_TM001] = MOVE_BULK_UP,
    [ITEM_TM094 - ITEM_TM001] = MOVE_BULLET_SEED,
    [ITEM_TM095 - ITEM_TM001] = MOVE_TAUNT,
    [ITEM_TM096 - ITEM_TM001] = MOVE_LIGHT_SCREEN,
    [ITEM_TM097 - ITEM_TM001] = MOVE_SAFEGUARD,
    [ITEM_TM098 - ITEM_TM001] = MOVE_BRICK_BREAK,
    [ITEM_TM099 - ITEM_TM001] = MOVE_SHOCK_WAVE,
    [ITEM_TM100 - ITEM_TM001] = MOVE_FLAMETHROWER,
    [ITEM_TM101 - ITEM_TM001] = MOVE_ROCK_TOMB,
    [ITEM_TM102 - ITEM_TM001] = MOVE_AERIAL_ACE,
    [ITEM_TM103 - ITEM_TM001] = MOVE_TORMENT,
    [ITEM_TM104 - ITEM_TM001] = MOVE_FACADE,
    [ITEM_TM105 - ITEM_TM001] = MOVE_SECRET_POWER,
    [ITEM_TM106 - ITEM_TM001] = MOVE_SKILL_SWAP,
    [ITEM_TM107 - ITEM_TM001] = MOVE_SNATCH,
    [ITEM_TM108 - ITEM_TM001] = MOVE_OVERHEAT,
    [ITEM_TM109 - ITEM_TM001] = MOVE_ROOST,
    [ITEM_TM110 - ITEM_TM001] = MOVE_FOCUS_BLAST,
    [ITEM_TM111 - ITEM_TM001] = MOVE_ENERGY_BALL,
    [ITEM_TM112 - ITEM_TM001] = MOVE_FALSE_SWIPE,
    [ITEM_TM113 - ITEM_TM001] = MOVE_BRINE,
    [ITEM_TM114 - ITEM_TM001] = MOVE_FLING,
    [ITEM_TM115 - ITEM_TM001] = MOVE_CHARGE_BEAM,
    [ITEM_TM116 - ITEM_TM001] = MOVE_DRAGON_PULSE,
    [ITEM_TM117 - ITEM_TM001] = MOVE_DRAIN_PUNCH,
    [ITEM_TM118 - ITEM_TM001] = MOVE_WILL_O_WISP,
    [ITEM_TM119 - ITEM_TM001] = MOVE_SILVER_WIND,
    [ITEM_TM120 - ITEM_TM001] = MOVE_EMBARGO,
    [ITEM_TM121 - ITEM_TM001] = MOVE_SHADOW_CLAW,
    [ITEM_TM122 - ITEM_TM001] = MOVE_PAYBACK,
    [ITEM_TM123 - ITEM_TM001] = MOVE_RECYCLE,
    [ITEM_TM124 - ITEM_TM001] = MOVE_GIGA_IMPACT,
    [ITEM_TM125 - ITEM_TM001] = MOVE_ROCK_POLISH,
    [ITEM_TM126 - ITEM_TM001] = MOVE_FLASH,
    [ITEM_TM127 - ITEM_TM001] = MOVE_STONE_EDGE,
    [ITEM_TM128 - ITEM_TM001] = MOVE_AVALANCHE,
    [ITEM_TM129 - ITEM_TM001] = MOVE_GYRO_BALL,
    [ITEM_TM130 - ITEM_TM001] = MOVE_STEALTH_ROCK,
    [ITEM_TM131 - ITEM_TM001] = MOVE_CAPTIVATE,
    [ITEM_TM132 - ITEM_TM001] = MOVE_DARK_PULSE,
    [ITEM_TM133 - ITEM_TM001] = MOVE_X_SCISSOR,
    [ITEM_TM134 - ITEM_TM001] = MOVE_NATURAL_GIFT,
    [ITEM_TM135 - ITEM_TM001] = MOVE_POISON_JAB,
    [ITEM_TM136 - ITEM_TM001] = MOVE_GRASS_KNOT,
    [ITEM_TM137 - ITEM_TM001] = MOVE_PLUCK,
    [ITEM_TM138 - ITEM_TM001] = MOVE_U_TURN,
    [ITEM_TM139 - ITEM_TM001] = MOVE_FLASH_CANNON,
    [ITEM_TM140 - ITEM_TM001] = MOVE_TRICK_ROOM,
    [ITEM_TM141 - ITEM_TM001] = MOVE_HONE_CLAWS,
    [ITEM_TM142 - ITEM_TM001] = MOVE_PSYSHOCK,
    [ITEM_TM143 - ITEM_TM001] = MOVE_VENOSHOCK,
    [ITEM_TM144 - ITEM_TM001] = MOVE_TELEKINESIS,
    [ITEM_TM145 - ITEM_TM001] = MOVE_SMACK_DOWN,
    [ITEM_TM146 - ITEM_TM001] = MOVE_SLUDGE_WAVE,
    [ITEM_TM147 - ITEM_TM001] = MOVE_FLAME_CHARGE,
    [ITEM_TM148 - ITEM_TM001] = MOVE_LOW_SWEEP,
    [ITEM_TM149 - ITEM_TM001] = MOVE_ROUND,
    [ITEM_TM150 - ITEM_TM001] = MOVE_ECHOED_VOICE,
    [ITEM_TM151 - ITEM_TM001] = MOVE_ALLY_SWITCH,
    [ITEM_TM152 - ITEM_TM001] = MOVE_SCALD,
    [ITEM_TM153 - ITEM_TM001] = MOVE_SKY_DROP,
    [ITEM_TM154 - ITEM_TM001] = MOVE_INCINERATE,
    [ITEM_TM155 - ITEM_TM001] = MOVE_QUASH,
    [ITEM_TM156 - ITEM_TM001] = MOVE_ACROBATICS,
    [ITEM_TM157 - ITEM_TM001] = MOVE_RETALIATE,
    [ITEM_TM158 - ITEM_TM001] = MOVE_VOLT_SWITCH,
    [ITEM_TM159 - ITEM_TM001] = MOVE_STRUGGLE_BUG,
    [ITEM_TM160 - ITEM_TM001] = MOVE_BULLDOZE,
    [ITEM_TM161 - ITEM_TM001] = MOVE_FROST_BREATH,
    [ITEM_TM162 - ITEM_TM001] = MOVE_DRAGON_TAIL,
    [ITEM_TM163 - ITEM_TM001] = MOVE_WORK_UP,
    [ITEM_TM164 - ITEM_TM001] = MOVE_WILD_CHARGE,
    [ITEM_TM165 - ITEM_TM001] = MOVE_SNARL,
    [ITEM_TM166 - ITEM_TM001] = MOVE_INFESTATION,
    [ITEM_TM167 - ITEM_TM001] = MOVE_NATURE_POWER,
    [ITEM_TM168 - ITEM_TM001] = MOVE_POWER_UP_PUNCH,
    [ITEM_TM169 - ITEM_TM001] = MOVE_DAZZLING_GLEAM,
    [ITEM_TM170 - ITEM_TM001] = MOVE_CONFIDE,
    [ITEM_TM171 - ITEM_TM001] = MOVE_LEECH_LIFE,
    [ITEM_TM172 - ITEM_TM001] = MOVE_BRUTAL_SWING,
    [ITEM_TM173 - ITEM_TM001] = MOVE_SMART_STRIKE,
    [ITEM_TM174 - ITEM_TM001] = MOVE_AURORA_VEIL,
    [ITEM_TM175 - ITEM_TM001] = MOVE_FLY,
    [ITEM_TM176 - ITEM_TM001] = MOVE_SURF,
    [ITEM_TM177 - ITEM_TM001] = MOVE_WATERFALL,
    [ITEM_TM178 - ITEM_TM001] = MOVE_HELPING_HAND,
    [ITEM_TM179 - ITEM_TM001] = MOVE_FOUL_PLAY,
    [ITEM_TM180 - ITEM_TM001] = MOVE_OUTRAGE,
    [ITEM_TM181 - ITEM_TM001] = MOVE_SELF_DESTRUCT,
    [ITEM_TM182 - ITEM_TM001] = MOVE_PLAY_ROUGH,
    [ITEM_TM183 - ITEM_TM001] = MOVE_SUPERPOWER,
    [ITEM_TM184 - ITEM_TM001] = MOVE_DRILL_RUN,
    [ITEM_TM185 - ITEM_TM001] = MOVE_MEGAHORN,
    [ITEM_TM186 - ITEM_TM001] = MOVE_PIN_MISSILE,
    [ITEM_TM187 - ITEM_TM001] = MOVE_MAGICAL_LEAF,
    [ITEM_TM188 - ITEM_TM001] = MOVE_SOLAR_BLADE,
    [ITEM_TM189 - ITEM_TM001] = MOVE_FIRE_SPIN,
    [ITEM_TM190 - ITEM_TM001] = MOVE_SCREECH,
    [ITEM_TM191 - ITEM_TM001] = MOVE_SCARY_FACE,
    [ITEM_TM192 - ITEM_TM001] = MOVE_CHARM,
    [ITEM_TM193 - ITEM_TM001] = MOVE_WHIRLPOOL,
    [ITEM_TM194 - ITEM_TM001] = MOVE_BEAT_UP,
    [ITEM_TM195 - ITEM_TM001] = MOVE_REVENGE,
    [ITEM_TM196 - ITEM_TM001] = MOVE_IMPRISON,
    [ITEM_TM197 - ITEM_TM001] = MOVE_DIVE,
    [ITEM_TM198 - ITEM_TM001] = MOVE_WEATHER_BALL,
    [ITEM_TM199 - ITEM_TM001] = MOVE_FAKE_TEARS,
    [ITEM_TM200 - ITEM_TM001] = MOVE_SAND_TOMB,
    [ITEM_TM201 - ITEM_TM001] = MOVE_ICICLE_SPEAR,
    [ITEM_TM202 - ITEM_TM001] = MOVE_BOUNCE,
    [ITEM_TM203 - ITEM_TM001] = MOVE_MUD_SHOT,
    [ITEM_TM204 - ITEM_TM001] = MOVE_ROCK_BLAST,
    [ITEM_TM205 - ITEM_TM001] = MOVE_ASSURANCE,
    [ITEM_TM206 - ITEM_TM001] = MOVE_POWER_SWAP,
    [ITEM_TM207 - ITEM_TM001] = MOVE_GUARD_SWAP,
    [ITEM_TM208 - ITEM_TM001] = MOVE_SPEED_SWAP,
    [ITEM_TM209 - ITEM_TM001] = MOVE_THUNDER_FANG,
    [ITEM_TM210 - ITEM_TM001] = MOVE_ICE_FANG,
    [ITEM_TM211 - ITEM_TM001] = MOVE_FIRE_FANG,
    [ITEM_TM212 - ITEM_TM001] = MOVE_PSYCHO_CUT,
    [ITEM_TM213 - ITEM_TM001] = MOVE_WONDER_ROOM,
    [ITEM_TM214 - ITEM_TM001] = MOVE_MAGIC_ROOM,
    [ITEM_TM215 - ITEM_TM001] = MOVE_CROSS_POISON,
    [ITEM_TM216 - ITEM_TM001] = MOVE_HEX,
    [ITEM_TM217 - ITEM_TM001] = MOVE_ELECTROWEB,
    [ITEM_TM218 - ITEM_TM001] = MOVE_RAZOR_SHELL,
    [ITEM_TM219 - ITEM_TM001] = MOVE_TAIL_SLAP,
    [ITEM_TM220 - ITEM_TM001] = MOVE_PHANTOM_FORCE,
    [ITEM_TM221 - ITEM_TM001] = MOVE_DRAINING_KISS,
    [ITEM_TM222 - ITEM_TM001] = MOVE_GRASSY_TERRAIN,
    [ITEM_TM223 - ITEM_TM001] = MOVE_MISTY_TERRAIN,
    [ITEM_TM224 - ITEM_TM001] = MOVE_ELECTRIC_TERRAIN,
    [ITEM_TM225 - ITEM_TM001] = MOVE_PSYCHIC_TERRAIN,
    [ITEM_TM226 - ITEM_TM001] = MOVE_MYSTICAL_FIRE,
    [ITEM_TM227 - ITEM_TM001] = MOVE_EERIE_IMPULSE,
    [ITEM_TM228 - ITEM_TM001] = MOVE_AIR_SLASH,
    [ITEM_TM229 - ITEM_TM001] = MOVE_STOMPING_TANTRUM,
    [ITEM_TM230 - ITEM_TM001] = MOVE_BREAKING_SWIPE,
    [ITEM_TM231 - ITEM_TM001] = MOVE_HYDRO_PUMP,
    [ITEM_TM232 - ITEM_TM001] = MOVE_LOW_KICK,
    [ITEM_TM233 - ITEM_TM001] = MOVE_AGILITY,
    [ITEM_TM234 - ITEM_TM001] = MOVE_FOCUS_ENERGY,
    [ITEM_TM235 - ITEM_TM001] = MOVE_AMNESIA,
    [ITEM_TM236 - ITEM_TM001] = MOVE_REVERSAL,
    [ITEM_TM237 - ITEM_TM001] = MOVE_SPIKES,
    [ITEM_TM238 - ITEM_TM001] = MOVE_BATON_PASS,
    [ITEM_TM239 - ITEM_TM001] = MOVE_ENCORE,
    [ITEM_TM240 - ITEM_TM001] = MOVE_CRUNCH,
    [ITEM_TM241 - ITEM_TM001] = MOVE_FUTURE_SIGHT,
    [ITEM_TM242 - ITEM_TM001] = MOVE_UPROAR,
    [ITEM_TM243 - ITEM_TM001] = MOVE_HEAT_WAVE,
    [ITEM_TM244 - ITEM_TM001] = MOVE_TRICK,
    [ITEM_TM245 - ITEM_TM001] = MOVE_BLAZE_KICK,
    [ITEM_TM246 - ITEM_TM001] = MOVE_HYPER_VOICE,
    [ITEM_TM247 - ITEM_TM001] = MOVE_COSMIC_POWER,
    [ITEM_TM248 - ITEM_TM001] = MOVE_MUDDY_WATER,
    [ITEM_TM249 - ITEM_TM001] = MOVE_IRON_DEFENSE,
    [ITEM_TM250 - ITEM_TM001] = MOVE_LEAF_BLADE,
    [ITEM_TM251 - ITEM_TM001] = MOVE_DRAGON_DANCE,
    [ITEM_TM252 - ITEM_TM001] = MOVE_CLOSE_COMBAT,
    [ITEM_TM253 - ITEM_TM001] = MOVE_TOXIC_SPIKES,
    [ITEM_TM254 - ITEM_TM001] = MOVE_FLARE_BLITZ,
    [ITEM_TM255 - ITEM_TM001] = MOVE_AURA_SPHERE,
    [ITEM_TM256 - ITEM_TM001] = MOVE_SEED_BOMB,
    [ITEM_TM257 - ITEM_TM001] = MOVE_BUG_BUZZ,
    [ITEM_TM258 - ITEM_TM001] = MOVE_POWER_GEM,
    [ITEM_TM259 - ITEM_TM001] = MOVE_BRAVE_BIRD,
    [ITEM_TM260 - ITEM_TM001] = MOVE_EARTH_POWER,
    [ITEM_TM261 - ITEM_TM001] = MOVE_NASTY_PLOT,
    [ITEM_TM262 - ITEM_TM001] = MOVE_ZEN_HEADBUTT,
    [ITEM_TM263 - ITEM_TM001] = MOVE_LEAF_STORM,
    [ITEM_TM264 - ITEM_TM001] = MOVE_POWER_WHIP,
    [ITEM_TM265 - ITEM_TM001] = MOVE_GUNK_SHOT,
    [ITEM_TM266 - ITEM_TM001] = MOVE_IRON_HEAD,
    [ITEM_TM267 - ITEM_TM001] = MOVE_HEAVY_SLAM,
    [ITEM_TM268 - ITEM_TM001] = MOVE_ELECTRO_BALL,
    [ITEM_TM269 - ITEM_TM001] = MOVE_STORED_POWER,
    [ITEM_TM270 - ITEM_TM001] = MOVE_HEAT_CRASH,
    [ITEM_TM271 - ITEM_TM001] = MOVE_HURRICANE,
    [ITEM_TM272 - ITEM_TM001] = MOVE_VENOM_DRENCH,
    [ITEM_TM273 - ITEM_TM001] = MOVE_DARKEST_LARIAT,
    [ITEM_TM274 - ITEM_TM001] = MOVE_HIGH_HORSEPOWER,
    [ITEM_TM275 - ITEM_TM001] = MOVE_THROAT_CHOP,
    [ITEM_TM276 - ITEM_TM001] = MOVE_POLLEN_PUFF,
    [ITEM_TM277 - ITEM_TM001] = MOVE_PSYCHIC_FANGS,
    [ITEM_TM278 - ITEM_TM001] = MOVE_LIQUIDATION,
    [ITEM_TM279 - ITEM_TM001] = MOVE_BODY_PRESS,
    [ITEM_TM280 - ITEM_TM001] = MOVE_CUT,
    [ITEM_TM281 - ITEM_TM001] = MOVE_STRENGTH,
    [ITEM_TM282 - ITEM_TM001] = MOVE_DEFOG,
    [ITEM_TM283 - ITEM_TM001] = MOVE_ROCK_CLIMB,
};
