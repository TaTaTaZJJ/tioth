#include "global.h"
#include "battle_setup.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "pokemon.h"
#include "script.h"
#include "script_movement.h"
#include "sprite.h"
#include "task.h"
#include "trainer_see.h"
#include "trainer_hill.h"
#include "util.h"
#include "battle_pyramid.h"
#include "constants/battle_setup.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/trainer_types.h"

// this file's functions
static u8 CheckTrainer(u8 objectEventId);
static u8 GetTrainerApproachDistance(struct ObjectEvent *trainerObj);
static u8 CheckPathBetweenTrainerAndPlayer(struct ObjectEvent *trainerObj, u8 approachDistance, u8 direction);
static void InitTrainerApproachTask(struct ObjectEvent *trainerObj, u8 range);
static void Task_RunTrainerSeeFuncList(u8 taskId);
static void Task_EndTrainerApproach(u8 taskId);
static void SetIconSpriteData(struct Sprite *sprite, u16 fldEffId, u8 spriteAnimNum);

static u8 GetTrainerApproachDistanceSouth(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y);
static u8 GetTrainerApproachDistanceNorth(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y);
static u8 GetTrainerApproachDistanceWest(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y);
static u8 GetTrainerApproachDistanceEast(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y);

static bool8 TrainerSeeIdle(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 TrainerExclamationMark(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 WaitTrainerExclamationMark(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 TrainerMoveToPlayer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 PlayerFaceApproachingTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 WaitPlayerFaceApproachingTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 RevealDisguisedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 WaitRevealDisguisedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 RevealBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 PopOutOfAshBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 JumpInPlaceBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 WaitRevealBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);

static void SpriteCB_TrainerIcons(struct Sprite *sprite);

// IWRAM common
u16 gWhichTrainerToFaceAfterBattle;
u8 gPostBattleMovementScript[4];
struct ApproachingTrainer gApproachingTrainers[2];
u8 gNoOfApproachingTrainers;
bool8 gTrainerApproachedPlayer;

// EWRAM
EWRAM_DATA u8 gApproachingTrainerId = 0;

// const rom data
static const u8 sEmotion_ExclamationMarkGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_exclamation_mark.4bpp");
static const u8 sEmotion_QuestionMarkGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_question_mark.4bpp");
static const u8 sEmotion_HeartGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_heart.4bpp");

//新表情
static const u8 sEmotion_DotDotDotGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_dot_dot_dot.4bpp");
static const u8 sEmotion_AngryGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_angry.4bpp");
static const u8 sEmotion_SweatGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_sweat.4bpp");
static const u8 sEmotion_ExclamationMark2Gfx[] = INCBIN_U8("graphics/misc/emotion/emotion_exclamation_mark_2.4bpp");
static const u8 sEmotion_BulbGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_bulb.4bpp");
static const u8 sEmotion_SpeechlessGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_speechless.4bpp");
static const u8 sEmotion_MusicGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_music.4bpp");
static const u8 sEmotion_CircleGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_circle.4bpp");
static const u8 sEmotion_SleepyGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_sleepy.4bpp");
static const u8 sEmotion_CrossGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_cross.4bpp");
static const u8 sEmotion_StarGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_star.4bpp");
static const u8 sEmotion_FunnnyGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_funny.4bpp");
static const u8 sEmotion_VommitGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_vommit.4bpp");
static const u8 sEmotion_SmileGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_smile.4bpp");
static const u8 sEmotion_FacePalmGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_face_palm.4bpp");
static const u8 sEmotion_BombedGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_bombed.4bpp");
static const u8 sEmotion_DogeGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_doge.4bpp");
static const u8 sEmotion_EvilGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_evil.4bpp");
static const u8 sEmotion_Sweat2Gfx[] = INCBIN_U8("graphics/misc/emotion/emotion_sweat_2.4bpp");
static const u8 sEmotion_SkullGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_skull.4bpp");

static const u8 sEmotion_SwordGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_sword.4bpp");
static const u8 sEmotion_CreeperGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_creeper.4bpp");
static const u8 sEmotion_SpitBloodGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_spit_blood.4bpp");
static const u8 sEmotion_InterestingGfx[] = INCBIN_U8("graphics/misc/emotion/emotion_interesting.4bpp");

static u8 (*const sDirectionalApproachDistanceFuncs[])(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y) =
{
    GetTrainerApproachDistanceSouth,
    GetTrainerApproachDistanceNorth,
    GetTrainerApproachDistanceWest,
    GetTrainerApproachDistanceEast,
};

enum {
    TRSEE_NONE,
    TRSEE_EXCLAMATION,
    TRSEE_EXCLAMATION_WAIT,
    TRSEE_MOVE_TO_PLAYER,
    TRSEE_PLAYER_FACE,
    TRSEE_PLAYER_FACE_WAIT,
    TRSEE_REVEAL_DISGUISE,
    TRSEE_REVEAL_DISGUISE_WAIT,
    TRSEE_REVEAL_BURIED,
    TRSEE_BURIED_POP_OUT,
    TRSEE_BURIED_JUMP,
    TRSEE_REVEAL_BURIED_WAIT,
};

static bool8 (*const sTrainerSeeFuncList[])(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj) =
{
    [TRSEE_NONE]                 = TrainerSeeIdle,
    [TRSEE_EXCLAMATION]          = TrainerExclamationMark,
    [TRSEE_EXCLAMATION_WAIT]     = WaitTrainerExclamationMark,
    [TRSEE_MOVE_TO_PLAYER]       = TrainerMoveToPlayer,
    [TRSEE_PLAYER_FACE]          = PlayerFaceApproachingTrainer,
    [TRSEE_PLAYER_FACE_WAIT]     = WaitPlayerFaceApproachingTrainer,
    [TRSEE_REVEAL_DISGUISE]      = RevealDisguisedTrainer,
    [TRSEE_REVEAL_DISGUISE_WAIT] = WaitRevealDisguisedTrainer,
    [TRSEE_REVEAL_BURIED]        = RevealBuriedTrainer,
    [TRSEE_BURIED_POP_OUT]       = PopOutOfAshBuriedTrainer,
    [TRSEE_BURIED_JUMP]          = JumpInPlaceBuriedTrainer,
    [TRSEE_REVEAL_BURIED_WAIT]   = WaitRevealBuriedTrainer,
};

static bool8 (*const sTrainerSeeFuncList2[])(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj) =
{
    RevealBuriedTrainer,
    PopOutOfAshBuriedTrainer,
    JumpInPlaceBuriedTrainer,
    WaitRevealBuriedTrainer,
};

static const struct OamData sOamData_Icons =
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
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteFrameImage sSpriteImageTable_ExclamationMark[] =
{
    {
        .data = sEmotion_ExclamationMarkGfx,
        .size = 0x80
    },
};

static const struct SpriteFrameImage sSpriteImageTable_QuestionMark[] =
{
    {
        .data = sEmotion_QuestionMarkGfx,
        .size = 0x80
    }
};

static const struct SpriteFrameImage sSpriteImageTable_HeartIcon[] =
{
    {
        .data = sEmotion_HeartGfx,
        .size = 0x80
    }
};

static const struct SpriteFrameImage sSpriteImageTable_DotDotDotIcon[] = { { .data = sEmotion_DotDotDotGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_AngryIcon[] = { { .data = sEmotion_AngryGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_SweatIcon[] = { { .data = sEmotion_SweatGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_ExclamationMark2Icon[] = { { .data = sEmotion_ExclamationMark2Gfx, .size = 0x80}}; 
static const struct SpriteFrameImage sSpriteImageTable_BulbIcon[] = { { .data = sEmotion_BulbGfx, .size = 0x80}}; 
static const struct SpriteFrameImage sSpriteImageTable_SpeechlessIcon[] = { { .data = sEmotion_SpeechlessGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_MusicIcon[] = { { .data = sEmotion_MusicGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_CircleIcon[] = { { .data = sEmotion_CircleGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_SleepyIcon[] = { { .data = sEmotion_SleepyGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_CrossIcon[] = { { .data = sEmotion_CrossGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_StarIcon[] = { { .data = sEmotion_StarGfx, .size = 0x80}};  
static const struct SpriteFrameImage sSpriteImageTable_FunnnyIcon[] = { { .data = sEmotion_FunnnyGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_VommitIcon[] = { { .data = sEmotion_VommitGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_SmileIcon[] = { { .data = sEmotion_SmileGfx, .size = 0x80}}; 
static const struct SpriteFrameImage sSpriteImageTable_FacePalmIcon[] = { { .data = sEmotion_FacePalmGfx, .size = 0x80}};  
static const struct SpriteFrameImage sSpriteImageTable_BombedIcon[] = { { .data = sEmotion_BombedGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_DogeIcon[] = { { .data = sEmotion_DogeGfx, .size = 0x80}};  
static const struct SpriteFrameImage sSpriteImageTable_EvilIcon[] = { { .data = sEmotion_EvilGfx, .size = 0x80}};  
static const struct SpriteFrameImage sSpriteImageTable_Sweat2Icon[] = { { .data = sEmotion_Sweat2Gfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_SkullIcon[] = { { .data = sEmotion_SkullGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_SwordIcon[] = { { .data = sEmotion_SwordGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_CreeperIcon[] = { { .data = sEmotion_CreeperGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_SpitBloodIcon[] = { { .data = sEmotion_SpitBloodGfx, .size = 0x80}};
static const struct SpriteFrameImage sSpriteImageTable_InterestingIcon[] = { { .data = sEmotion_InterestingGfx, .size = 0x80}};

static const union AnimCmd sSpriteAnim_Icons1[] =
{
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Icons2[] =
{
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Icons[] =
{
    sSpriteAnim_Icons1,
    sSpriteAnim_Icons2
};

static const struct SpriteTemplate sSpriteTemplate_ExclamationMark =
{
    .tileTag = 0xffff,
    .paletteTag = FLDEFF_PAL_TAG_EMOTION,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Icons,
    .images = sSpriteImageTable_ExclamationMark,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TrainerIcons
};

static const struct SpriteTemplate sSpriteTemplate_QuestionMark =
{
    .tileTag = 0xffff,
    .paletteTag = FLDEFF_PAL_TAG_EMOTION,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Icons,
    .images = sSpriteImageTable_QuestionMark,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TrainerIcons
};

static const struct SpriteTemplate sSpriteTemplate_HeartIcon =
{
    .tileTag = 0xffff,
    .paletteTag = FLDEFF_PAL_TAG_EMOTION,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Icons,
    .images = sSpriteImageTable_HeartIcon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TrainerIcons
};

static const struct SpriteTemplate sSpriteTemplate_DotDotDotIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_DotDotDotIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_AngryIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_AngryIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_SweatIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_SweatIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_ExclamationMark2Icon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_ExclamationMark2Icon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_BulbIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_BulbIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_SpeechlessIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_SpeechlessIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_MusicIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_MusicIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_CircleIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_CircleIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_SleepyIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_SleepyIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_CrossIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_CrossIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_StarIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_StarIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_FunnnyIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_FunnnyIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_VommitIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_VommitIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_SmileIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_SmileIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_FacePalmIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_FacePalmIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_BombedIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_BombedIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_DogeIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_DogeIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_EvilIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_EvilIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_Sweat2Icon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_Sweat2Icon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_SkullIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_SkullIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_SwordIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_SwordIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_SpitBloodIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_SpitBloodIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_CreeperIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_CreeperIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

static const struct SpriteTemplate sSpriteTemplate_InterestingIcon =
    {
        .tileTag = 0xffff,
        .paletteTag = FLDEFF_PAL_TAG_EMOTION,
        .oam = &sOamData_Icons,
        .anims = sSpriteAnimTable_Icons,
        .images = sSpriteImageTable_InterestingIcon,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_TrainerIcons};

// code
bool8 CheckForTrainersWantingBattle(void)
{
    u8 i;

    gNoOfApproachingTrainers = 0;
    gApproachingTrainerId = 0;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        u8 numTrainers;

        if (!gObjectEvents[i].active)
            continue;
        if (gObjectEvents[i].trainerType != TRAINER_TYPE_NORMAL && gObjectEvents[i].trainerType != TRAINER_TYPE_BURIED)
            continue;

        numTrainers = CheckTrainer(i);
        if (numTrainers == 2)
            break;

        if (numTrainers == 0)
            continue;

        if (gNoOfApproachingTrainers > 1)
            break;
        if (GetMonsStateToDoubles_2() != 0) // one trainer found and cant have a double battle
            break;
    }

    if (gNoOfApproachingTrainers == 1)
    {
        ResetTrainerOpponentIds();
        ConfigureAndSetUpOneTrainerBattle(gApproachingTrainers[gNoOfApproachingTrainers - 1].objectEventId,
                                          gApproachingTrainers[gNoOfApproachingTrainers - 1].trainerScriptPtr);
        gTrainerApproachedPlayer = TRUE;
        return TRUE;
    }
    else if (gNoOfApproachingTrainers == 2)
    {
        ResetTrainerOpponentIds();
        for (i = 0; i < gNoOfApproachingTrainers; i++, gApproachingTrainerId++)
        {
            ConfigureTwoTrainersBattle(gApproachingTrainers[i].objectEventId,
                                       gApproachingTrainers[i].trainerScriptPtr);
        }
        SetUpTwoTrainersBattle();
        gApproachingTrainerId = 0;
        gTrainerApproachedPlayer = TRUE;
        return TRUE;
    }
    else
    {
        gTrainerApproachedPlayer = FALSE;
        return FALSE;
    }
}

static u8 CheckTrainer(u8 objectEventId)
{
    const u8 *scriptPtr;
    u8 numTrainers = 1;
    u8 approachDistance;

    if (InTrainerHill() == TRUE)
        scriptPtr = GetTrainerHillTrainerScript();
    else
        scriptPtr = GetObjectEventScriptPointerByObjectEventId(objectEventId);

    if (InBattlePyramid())
    {
        if (GetBattlePyramidTrainerFlag(objectEventId))
            return 0;
    }
    else if (InTrainerHill() == TRUE)
    {
        if (GetHillTrainerFlag(objectEventId))
            return 0;
    }
    else
    {
        if (GetTrainerFlagFromScriptPointer(scriptPtr))
            return 0;
    }

    approachDistance = GetTrainerApproachDistance(&gObjectEvents[objectEventId]);

    if (approachDistance != 0)
    {
        if (scriptPtr[1] == TRAINER_BATTLE_DOUBLE
            || scriptPtr[1] == TRAINER_BATTLE_REMATCH_DOUBLE
            || scriptPtr[1] == TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE)
        {
            if (GetMonsStateToDoubles_2() != 0)
                return 0;

            numTrainers = 2;
        }

        gApproachingTrainers[gNoOfApproachingTrainers].objectEventId = objectEventId;
        gApproachingTrainers[gNoOfApproachingTrainers].trainerScriptPtr = scriptPtr;
        gApproachingTrainers[gNoOfApproachingTrainers].radius = approachDistance;
        InitTrainerApproachTask(&gObjectEvents[objectEventId], approachDistance - 1);
        gNoOfApproachingTrainers++;

        return numTrainers;
    }

    return 0;
}

static u8 GetTrainerApproachDistance(struct ObjectEvent *trainerObj)
{
    s16 x, y;
    u8 i;
    u8 approachDistance;

    PlayerGetDestCoords(&x, &y);
    if (trainerObj->trainerType == TRAINER_TYPE_NORMAL)  // can only see in one direction
    {
        approachDistance = sDirectionalApproachDistanceFuncs[trainerObj->facingDirection - 1](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
        return CheckPathBetweenTrainerAndPlayer(trainerObj, approachDistance, trainerObj->facingDirection);
    }
    else // TRAINER_TYPE_SEE_ALL_DIRECTIONS, TRAINER_TYPE_BURIED
    {
        for (i = 0; i < ARRAY_COUNT(sDirectionalApproachDistanceFuncs); i++)
        {
            approachDistance = sDirectionalApproachDistanceFuncs[i](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
            if (CheckPathBetweenTrainerAndPlayer(trainerObj, approachDistance, i + 1)) // directions are 1-4 instead of 0-3. south north west east
                return approachDistance;
        }
    }

    return 0;
}

// Returns how far south the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceSouth(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->currentCoords.x == x
     && y > trainerObj->currentCoords.y
     && y <= trainerObj->currentCoords.y + range)
        return (y - trainerObj->currentCoords.y);
    else
        return 0;
}

// Returns how far north the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceNorth(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->currentCoords.x == x
     && y < trainerObj->currentCoords.y
     && y >= trainerObj->currentCoords.y - range)
        return (trainerObj->currentCoords.y - y);
    else
        return 0;
}

// Returns how far west the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceWest(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->currentCoords.y == y
     && x < trainerObj->currentCoords.x
     && x >= trainerObj->currentCoords.x - range)
        return (trainerObj->currentCoords.x - x);
    else
        return 0;
}

// Returns how far east the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceEast(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->currentCoords.y == y
     && x > trainerObj->currentCoords.x
     && x <= trainerObj->currentCoords.x + range)
        return (x - trainerObj->currentCoords.x);
    else
        return 0;
}

#define COLLISION_MASK (~1)

static u8 CheckPathBetweenTrainerAndPlayer(struct ObjectEvent *trainerObj, u8 approachDistance, u8 direction)
{
    s16 x, y;
    u8 rangeX, rangeY;
    u8 i;
    u8 collision;

    if (approachDistance == 0)
        return 0;

    x = trainerObj->currentCoords.x;
    y = trainerObj->currentCoords.y;

    MoveCoords(direction, &x, &y);
    for (i = 0; i < approachDistance - 1; i++, MoveCoords(direction, &x, &y))
    {
        collision = GetCollisionFlagsAtCoords(trainerObj, x, y, direction);
        if (collision != 0 && (collision & COLLISION_MASK))
            return 0;
    }

    rangeX = trainerObj->rangeX;
    rangeY = trainerObj->rangeY;
    trainerObj->rangeX = 0;
    trainerObj->rangeY = 0;

    collision = GetCollisionAtCoords(trainerObj, x, y, direction);

    trainerObj->rangeX = rangeX;
    trainerObj->rangeY = rangeY;
    if (collision == COLLISION_OBJECT_EVENT)
        return approachDistance;

    return 0;
}

#define tFuncId             data[0]
#define tTrainerRange       data[3]
#define tOutOfAshSpriteId   data[4]
#define tTrainerObjectEventId data[7]

static void InitTrainerApproachTask(struct ObjectEvent *trainerObj, u8 range)
{
    struct Task *task;

    gApproachingTrainers[gNoOfApproachingTrainers].taskId = CreateTask(Task_RunTrainerSeeFuncList, 0x50);
    task = &gTasks[gApproachingTrainers[gNoOfApproachingTrainers].taskId];
    task->tTrainerRange = range;
    task->tTrainerObjectEventId = gApproachingTrainers[gNoOfApproachingTrainers].objectEventId;
}

static void StartTrainerApproach(TaskFunc followupFunc)
{
    u8 taskId;
    TaskFunc taskFunc;

    if (gApproachingTrainerId == 0)
        taskId = gApproachingTrainers[0].taskId;
    else
        taskId = gApproachingTrainers[1].taskId;

    taskFunc = Task_RunTrainerSeeFuncList;
    SetTaskFuncWithFollowupFunc(taskId, taskFunc, followupFunc);
    gTasks[taskId].tFuncId = TRSEE_EXCLAMATION;
    taskFunc(taskId);
}

static void Task_RunTrainerSeeFuncList(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct ObjectEvent *trainerObj = &gObjectEvents[task->tTrainerObjectEventId];

    if (!trainerObj->active)
    {
        SwitchTaskToFollowupFunc(taskId);
    }
    else
    {
        while (sTrainerSeeFuncList[task->tFuncId](taskId, task, trainerObj));
    }
}

static bool8 TrainerSeeIdle(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    return FALSE;
}

// TRSEE_EXCLAMATION
static bool8 TrainerExclamationMark(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    u8 direction;

    ObjectEventGetLocalIdAndMap(trainerObj, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON);
    direction = GetFaceDirectionMovementAction(trainerObj->facingDirection);
    ObjectEventSetHeldMovement(trainerObj, direction);
    task->tFuncId++; // TRSEE_EXCLAMATION_WAIT
    return TRUE;
}

// TRSEE_EXCLAMATION_WAIT
static bool8 WaitTrainerExclamationMark(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (FieldEffectActiveListContains(FLDEFF_EXCLAMATION_MARK_ICON))
    {
        return FALSE;
    }
    else
    {
        task->tFuncId++; // TRSEE_MOVE_TO_PLAYER
        if (trainerObj->movementType == MOVEMENT_TYPE_TREE_DISGUISE || trainerObj->movementType == MOVEMENT_TYPE_MOUNTAIN_DISGUISE)
            task->tFuncId = TRSEE_REVEAL_DISGUISE;
        if (trainerObj->movementType == MOVEMENT_TYPE_BURIED)
            task->tFuncId = TRSEE_REVEAL_BURIED;
        return TRUE;
    }
}

// TRSEE_MOVE_TO_PLAYER
static bool8 TrainerMoveToPlayer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (!ObjectEventIsMovementOverridden(trainerObj) || ObjectEventClearHeldMovementIfFinished(trainerObj))
    {
        if (task->tTrainerRange)
        {
            ObjectEventSetHeldMovement(trainerObj, GetWalkNormalMovementAction(trainerObj->facingDirection));
            task->tTrainerRange--;
        }
        else
        {
            ObjectEventSetHeldMovement(trainerObj, MOVEMENT_ACTION_FACE_PLAYER);
            task->tFuncId++; // TRSEE_PLAYER_FACE
        }
    }
    return FALSE;
}

// TRSEE_PLAYER_FACE
static bool8 PlayerFaceApproachingTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    struct ObjectEvent *playerObj;

    if (ObjectEventIsMovementOverridden(trainerObj) && !ObjectEventClearHeldMovementIfFinished(trainerObj))
        return FALSE;

    // Set trainer's movement type so they stop and remain facing that direction
    SetTrainerMovementType(trainerObj, GetTrainerFacingDirectionMovementType(trainerObj->facingDirection));
    TryOverrideTemplateCoordsForObjectEvent(trainerObj, GetTrainerFacingDirectionMovementType(trainerObj->facingDirection));
    OverrideTemplateCoordsForObjectEvent(trainerObj);

    playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (ObjectEventIsMovementOverridden(playerObj) && !ObjectEventClearHeldMovementIfFinished(playerObj))
        return FALSE;

    sub_808BCE8();
    ObjectEventSetHeldMovement(&gObjectEvents[gPlayerAvatar.objectEventId], GetFaceDirectionMovementAction(GetOppositeDirection(trainerObj->facingDirection)));
    task->tFuncId++; // TRSEE_PLAYER_FACE_WAIT
    return FALSE;
}

// TRSEE_PLAYER_FACE_WAIT
static bool8 WaitPlayerFaceApproachingTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!ObjectEventIsMovementOverridden(playerObj)
     || ObjectEventClearHeldMovementIfFinished(playerObj))
        SwitchTaskToFollowupFunc(taskId);
    return FALSE;
}

// TRSEE_REVEAL_DISGUISE
static bool8 RevealDisguisedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (!ObjectEventIsMovementOverridden(trainerObj)
     || ObjectEventClearHeldMovementIfFinished(trainerObj))
    {
        ObjectEventSetHeldMovement(trainerObj, MOVEMENT_ACTION_REVEAL_TRAINER);
        task->tFuncId++; // TRSEE_REVEAL_DISGUISE_WAIT
    }
    return FALSE;
}

// TRSEE_REVEAL_DISGUISE_WAIT
static bool8 WaitRevealDisguisedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (ObjectEventClearHeldMovementIfFinished(trainerObj))
        task->tFuncId = TRSEE_MOVE_TO_PLAYER;

    return FALSE;
}

// TRSEE_REVEAL_BURIED
static bool8 RevealBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (!ObjectEventIsMovementOverridden(trainerObj)
     || ObjectEventClearHeldMovementIfFinished(trainerObj))
    {
        ObjectEventSetHeldMovement(trainerObj, MOVEMENT_ACTION_FACE_PLAYER);
        task->tFuncId++;
    }
    return FALSE;
}

// TRSEE_BURIED_POP_OUT
static bool8 PopOutOfAshBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (ObjectEventCheckHeldMovementStatus(trainerObj))
    {
        gFieldEffectArguments[0] = trainerObj->currentCoords.x;
        gFieldEffectArguments[1] = trainerObj->currentCoords.y;
        gFieldEffectArguments[2] = gSprites[trainerObj->spriteId].subpriority - 1;
        gFieldEffectArguments[3] = 2;
        task->tOutOfAshSpriteId = FieldEffectStart(FLDEFF_ASH_PUFF);
        task->tFuncId++;
    }
    return FALSE;
}

// TRSEE_BURIED_JUMP
static bool8 JumpInPlaceBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    struct Sprite *sprite;

    if (gSprites[task->tOutOfAshSpriteId].animCmdIndex == 2)
    {
        trainerObj->fixedPriority = 0;
        trainerObj->triggerGroundEffectsOnMove = 1;

        sprite = &gSprites[trainerObj->spriteId];
        sprite->oam.priority = 2;
        ObjectEventClearHeldMovementIfFinished(trainerObj);
        ObjectEventSetHeldMovement(trainerObj, GetJumpInPlaceMovementAction(trainerObj->facingDirection));
        task->tFuncId++;
    }

    return FALSE;
}

// TRSEE_REVEAL_BURIED_WAIT
static bool8 WaitRevealBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (!FieldEffectActiveListContains(FLDEFF_ASH_PUFF))
        task->tFuncId = TRSEE_MOVE_TO_PLAYER;

    return FALSE;
}

#undef tTrainerRange
#undef tOutOfAshSpriteId
#undef tTrainerObjectEventId

#define tObjEvent data[1]

static void Task_SetBuriedTrainerMovement(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct ObjectEvent *objEvent;

    LoadWordFromTwoHalfwords(&task->tObjEvent, (u32 *)&objEvent);
    if (!task->data[7])
    {
        ObjectEventClearHeldMovement(objEvent);
        task->data[7]++;
    }
    sTrainerSeeFuncList2[task->tFuncId](taskId, task, objEvent);
    if (task->tFuncId == ((int)ARRAY_COUNT(sTrainerSeeFuncList2) - 1) && !FieldEffectActiveListContains(FLDEFF_ASH_PUFF))
    {
        SetTrainerMovementType(objEvent, GetTrainerFacingDirectionMovementType(objEvent->facingDirection));
        TryOverrideTemplateCoordsForObjectEvent(objEvent, GetTrainerFacingDirectionMovementType(objEvent->facingDirection));
        DestroyTask(taskId);
    }
    else
    {
        objEvent->heldMovementFinished = 0;
    }
}

// Called when a buried Trainer has the reveal_trainer movement applied, from direct interaction
void SetBuriedTrainerMovement(struct ObjectEvent *objEvent)
{
    StoreWordInTwoHalfwords(&gTasks[CreateTask(Task_SetBuriedTrainerMovement, 0)].tObjEvent, (u32)objEvent);
}

void DoTrainerApproach(void)
{
    StartTrainerApproach(Task_EndTrainerApproach);
}

static void Task_EndTrainerApproach(u8 taskId)
{
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

void TryPrepareSecondApproachingTrainer(void)
{
    if (gNoOfApproachingTrainers == 2)
    {
        if (gApproachingTrainerId == 0)
        {
            gApproachingTrainerId++;
            gSpecialVar_Result = TRUE;
            UnfreezeObjectEvents();
            FreezeObjectEventsExceptOne(gApproachingTrainers[1].objectEventId);
        }
        else
        {
            gApproachingTrainerId = 0;
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

#define sLocalId    data[0]
#define sMapNum     data[1]
#define sMapGroup   data[2]
#define sData3      data[3]
#define sData4      data[4]
#define sFldEffId   data[7]

u8 FldEff_ExclamationMarkIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_ExclamationMark, 0, 0, 0x52);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_EXCLAMATION_MARK_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }
    return 0;
}

u8 FldEff_QuestionMarkIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_QuestionMark, 0, 0, 0x52);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_QUESTION_MARK_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }
    return 0;
}

u8 FldEff_HeartIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_HeartIcon, 0, 0, 0x52);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_HEART_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}


u8 FldEff_DotDotDotIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_DotDotDotIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_DOTDOTDOT_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_AngryIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_AngryIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_ANGRY_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_SweatIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_SweatIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_SWEAT_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_ExclamationMark2Icon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_ExclamationMark2Icon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_EXCLAMATION_MARK_2_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_BulbIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_BulbIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_BULB_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_SpeechlessIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_SpeechlessIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_SPEECHLESS_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_MusicIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_MusicIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_MUSIC_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_CircleIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_CircleIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_CIRCLE_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_SleepyIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_SleepyIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_SLEEPY_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_CrossIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_CrossIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_CROSS_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_StarIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_StarIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_STAR_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_FunnnyIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_FunnnyIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_FUNNY_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_VommitIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_VommitIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_VOMMIT_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_SmileIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_SmileIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_SMILE_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_FacePalmIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_FacePalmIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_FACE_PALM_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_BombedIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_BombedIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_BOMBED_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_DogeIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_DogeIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_DOGE_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_EvilIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_EvilIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_EVIL_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_Sweat2Icon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_Sweat2Icon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_SWEAT_2_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_SkullIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_SkullIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_SKULL_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_SwordIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_SwordIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_SWORD_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_SpitBloodIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_SpitBloodIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_SPIT_BLOOD_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_CreeperIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_CreeperIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_CREEPER_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

u8 FldEff_InterestingIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_InterestingIcon,0,0,0x52);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_INTERESTING_ICON, 0);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(sprite->template->paletteTag);
    }

    return 0;
}

static void SetIconSpriteData(struct Sprite *sprite, u16 fldEffId, u8 spriteAnimNum)
{
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = 1;

    sprite->sLocalId = gFieldEffectArguments[0];
    sprite->sMapNum = gFieldEffectArguments[1];
    sprite->sMapGroup = gFieldEffectArguments[2];
    sprite->sData3 = -5;
    sprite->sFldEffId = fldEffId;

    StartSpriteAnim(sprite, spriteAnimNum);
}

static void SpriteCB_TrainerIcons(struct Sprite *sprite)
{
    u8 objEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objEventId)
     || sprite->animEnded)
    {
        FieldEffectStop(sprite, sprite->sFldEffId);
    }
    else
    {
        struct Sprite *objEventSprite = &gSprites[gObjectEvents[objEventId].spriteId];
        sprite->sData4 += sprite->sData3;
        sprite->x = objEventSprite->x;
        sprite->y = objEventSprite->y - 16;
        sprite->x2 = objEventSprite->x2;
        sprite->y2 = objEventSprite->y2 + sprite->sData4;
        if (sprite->sData4)
            sprite->sData3++;
        else
            sprite->sData3 = 0;
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sData3
#undef sData4
#undef sFldEffId

u8 GetCurrentApproachingTrainerObjectEventId(void)
{
    if (gApproachingTrainerId == 0)
        return gApproachingTrainers[0].objectEventId;
    else
        return gApproachingTrainers[1].objectEventId;
}

u8 GetChosenApproachingTrainerObjectEventId(u8 arrayId)
{
    if (arrayId >= ARRAY_COUNT(gApproachingTrainers))
        return 0;
    else if (arrayId == 0)
        return gApproachingTrainers[0].objectEventId;
    else
        return gApproachingTrainers[1].objectEventId;
}

void PlayerFaceTrainerAfterBattle(void)
{
    struct ObjectEvent *objEvent;

    if (gTrainerApproachedPlayer == TRUE)
    {
        objEvent = &gObjectEvents[gApproachingTrainers[gWhichTrainerToFaceAfterBattle].objectEventId];
        gPostBattleMovementScript[0] = GetFaceDirectionMovementAction(GetOppositeDirection(objEvent->facingDirection));
        gPostBattleMovementScript[1] = MOVEMENT_ACTION_STEP_END;
        ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_PLAYER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gPostBattleMovementScript);
    }
    else
    {
        objEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
        gPostBattleMovementScript[0] = GetFaceDirectionMovementAction(objEvent->facingDirection);
        gPostBattleMovementScript[1] = MOVEMENT_ACTION_STEP_END;
        ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_PLAYER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gPostBattleMovementScript);
    }

    SetMovingNpcId(OBJ_EVENT_ID_PLAYER);
}
