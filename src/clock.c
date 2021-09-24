#include "global.h"
#include "event_data.h"
#include "rtc.h"
#include "time_events.h"
#include "field_specials.h"
#include "lottery_corner.h"
#include "dewford_trend.h"
#include "script.h"
#include "tv.h"
#include "field_weather.h"
#include "berry.h"
#include "main.h"
#include "overworld.h"
#include "wallclock.h"

static void UpdatePerDay(struct Time *localTime);
static void UpdatePerMinute(struct Time *localTime);
static void DoLimitedTimeEvents(void);

static void InitTimeBasedEvents(void)
{
    FlagSet(FLAG_SYS_CLOCK_SET);
    RtcCalcLocalTime();
    gSaveBlock2Ptr->lastBerryTreeUpdate = gLocalTime;
    VarSet(VAR_DAYS, gLocalTime.days);
    VarSet(VAR_CYCLES, gLocalTime.cycles);
}

void DoTimeBasedEvents(void)
{   
    if (FlagGet(FLAG_SYS_CLOCK_SET))
    {
        if (!InPokemonCenter())
        {
            RtcCalcLocalTime();
            UpdatePerDay(&gLocalTime);
            UpdatePerMinute(&gLocalTime);
        }
        DoLimitedTimeEvents();
    }
}

static void UpdatePerDay(struct Time *localTime)
{
    u16 *days = GetVarPointer(VAR_DAYS);
    u16 *cycles = GetVarPointer(VAR_CYCLES);
    u16 daysSince;

    //计算周期天数
    int actualPreviousDays = *days + *cycles * DAYS_PER_CYCLE;
    int actualLocalDays = localTime->days + localTime->cycles * DAYS_PER_CYCLE;

    if (actualPreviousDays != actualLocalDays && actualPreviousDays <= actualLocalDays)
    {
        daysSince = actualLocalDays - actualPreviousDays;
        ClearDailyFlags();
        UpdateDewfordTrendPerDay(daysSince);
        UpdateTVShowsPerDay(daysSince);
        UpdateWeatherPerDay(daysSince);
        UpdatePartyPokerusTime(daysSince);
        UpdateMirageRnd(daysSince);
        UpdateBirchState(daysSince);
        UpdateFrontierManiac(daysSince);
        UpdateFrontierGambler(daysSince);
        SetShoalItemFlag(daysSince);
        SetRandomLotteryNumber(daysSince);
        *days = localTime->days;
    }
}

static void UpdatePerMinute(struct Time *localTime)
{
    struct Time difference;
    int minutes;

    CalcTimeDifference(&difference, &gSaveBlock2Ptr->lastBerryTreeUpdate, localTime);
    minutes = DAYS_PER_CYCLE * difference.cycles * 24 * 60 * difference.days + 60 * difference.hours + difference.minutes;
    if (minutes != 0)
    {
        if (minutes >= 0)
        {
            BerryTreeTimeUpdate(minutes);
            gSaveBlock2Ptr->lastBerryTreeUpdate = *localTime;
        }
    }
}

static void ReturnFromStartWallClock(void)
{
    InitTimeBasedEvents();
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void StartWallClock(void)
{
    SetMainCallback2(CB2_StartWallClock);
    gMain.savedCallback = ReturnFromStartWallClock;
}

// 进行限时事件
// 同一时间有复数事件触发时，根据限时事件编号顺序处理
// 只在时钟设置后触发
static void DoLimitedTimeEvents(void)
{   
    u8 i;
    if (FlagGet(FLAG_SYS_CLOCK_SET))
    {
        for (i = 0; i < LIMITED_TIME_EVENT_COUNT; i++)
        {
            const u8 *script = gSaveBlock1Ptr->limitedTimeEvent[i].script;
            if (script)
            {
                int timeEventVblanks;
                int saveVblanks;

                saveVblanks = gSaveBlock2Ptr->playTimeHours * 60 + gSaveBlock2Ptr->playTimeMinutes * 60 + gSaveBlock2Ptr->playTimeSeconds * 60 + gSaveBlock2Ptr->playTimeVBlanks;
                timeEventVblanks = gSaveBlock1Ptr->limitedTimeEvent[i].playTimeHours * 60 + gSaveBlock1Ptr->limitedTimeEvent[i].playTimeMinutes * 60 + gSaveBlock1Ptr->limitedTimeEvent[i].playTimeSeconds * 60 + gSaveBlock1Ptr->limitedTimeEvent[i].playTimeVBlanks;

                if (saveVblanks >= timeEventVblanks)
                {
                    ScriptContext1_SetupScript(script);
                    return;
                }
            }
        }
    }
}
