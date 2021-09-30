#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

struct ApproachingTrainer
{
    u8 objectEventId;
    u8 radius; // plus 1
    const u8 *trainerScriptPtr;
    u8 taskId;
};

extern u16 gWhichTrainerToFaceAfterBattle;
extern u8 gPostBattleMovementScript[4];
extern struct ApproachingTrainer gApproachingTrainers[2];
extern u8 gNoOfApproachingTrainers;
extern bool8 gTrainerApproachedPlayer;
extern u8 gApproachingTrainerId;

bool8 CheckForTrainersWantingBattle(void);
void SetBuriedTrainerMovement(struct ObjectEvent *var);
void DoTrainerApproach(void);
void TryPrepareSecondApproachingTrainer(void);
u8 FldEff_ExclamationMarkIcon(void);
u8 FldEff_QuestionMarkIcon(void);
u8 FldEff_HeartIcon(void);
u8 GetCurrentApproachingTrainerObjectEventId(void);
u8 GetChosenApproachingTrainerObjectEventId(u8 arrayId);
void PlayerFaceTrainerAfterBattle(void);

//新表情
u8 FldEff_DotDotDotIcon(void);
u8 FldEff_AngryIcon(void);
u8 FldEff_SweatIcon(void);
u8 FldEff_ExclamationMark2Icon(void);
u8 FldEff_BulbIcon(void);
u8 FldEff_SpeechlessIcon(void);
u8 FldEff_MusicIcon(void);
u8 FldEff_CircleIcon(void);
u8 FldEff_SleepyIcon(void);
u8 FldEff_CrossIcon(void);
u8 FldEff_StarIcon(void);
u8 FldEff_FunnnyIcon(void);
u8 FldEff_VommitIcon(void);
u8 FldEff_SmileIcon(void);
u8 FldEff_FacePalmIcon(void);
u8 FldEff_BombedIcon(void);
u8 FldEff_DogeIcon(void);
u8 FldEff_EvilIcon(void);
u8 FldEff_Sweat2Icon(void);
u8 FldEff_SkullIcon(void);
u8 FldEff_SwordIcon(void);
u8 FldEff_CreeperIcon(void);
u8 FldEff_SpitBloodIcon(void);
u8 FldEff_InterestingIcon(void);

#endif // GUARD_TRAINER_SEE_H
