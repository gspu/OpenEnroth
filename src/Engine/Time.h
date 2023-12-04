#pragma once

#include <cstdint>
#include <compare>

const int game_starting_year = 1168;

struct GameTime {
    static constexpr int64_t TICKS_PER_REALTIME_SECOND = 128;
    static constexpr int64_t GAME_SECONDS_IN_REALTIME_SECOND = 30; // Game time runs 30x faster than real time.

    GameTime() = default;
    GameTime(int seconds, int minutes, int hours = 0, int days = 0, int weeks = 0, int months = 0, int years = 0) {
        value = seconds + 60ll * minutes + 3600ll * hours + 86400ll * days + 604800ll * weeks + 2419200ll * months + 29030400ll * years;
        value = value * TICKS_PER_REALTIME_SECOND / GAME_SECONDS_IN_REALTIME_SECOND;
    }

    int64_t GetSeconds() const {
        return value * GAME_SECONDS_IN_REALTIME_SECOND / TICKS_PER_REALTIME_SECOND;
    }
    int64_t GetMinutes() const { return GetSeconds() / 60; }
    int64_t GetHours() const { return GetMinutes() / 60; }
    int GetDays() const { return GetHours() / 24; }
    int GetWeeks() const { return GetDays() / 7; }
    int GetMonths() const { return GetWeeks() / 4; }
    int GetYears() const { return GetMonths() / 12; }

    int GetSecondsFraction() const { return GetSeconds() % 60; }
    int GetMinutesFraction() const { return GetMinutes() % 60; }
    int GetHoursOfDay() const { return GetHours() % 24; }
    int GetDaysOfWeek() const { return GetDays() % 7; }
    int GetDaysOfMonth() const { return GetDays() % 28; }
    int GetWeeksOfMonth() const { return GetWeeks() % 4; }
    int GetMonthsOfYear() const { return GetMonths() % 12; }

    [[nodiscard]] GameTime AddSeconds(int seconds) const {
        return *this + GameTime::FromSeconds(seconds);
    }
    [[nodiscard]] GameTime AddMinutes(int minutes) const {
        return *this + GameTime::FromMinutes(minutes);
    }
    [[nodiscard]] GameTime SubtractMinutes(int minutes) const {
        return *this - GameTime::FromMinutes(minutes);
    }
    [[nodiscard]] GameTime AddHours(int hours) const {
        return *this + GameTime::FromHours(hours);
    }
    [[nodiscard]] GameTime SubtractHours(int hours) const {
        return *this - GameTime::FromHours(hours);
    }
    [[nodiscard]] GameTime AddDays(int days) const {
        return *this + GameTime::FromDays(days);
    }
    [[nodiscard]] GameTime SubtractDays(int days) const {
        return *this - GameTime::FromDays(days);
    }
    [[nodiscard]] GameTime AddYears(int years) const {
        return *this + GameTime::FromYears(years);
    }

    void SetExpired() { value = -1;  }
    bool Expired() const { return value < 0; }
    void Reset() { value = 0; }
    bool Valid() const { return value > 0; }

    friend GameTime operator+(const GameTime &l, const GameTime &r) {
        return GameTime::FromTicks(l.value + r.value);
    }

    friend GameTime operator-(const GameTime &l, const GameTime &r) {
        return GameTime::FromTicks(l.value - r.value);
    }

    GameTime &operator+=(const GameTime &rhs) {
        value += rhs.value;
        return *this;
    }

    GameTime &operator-=(const GameTime &rhs) {
        value -= rhs.value;
        return *this;
    }

    friend bool operator==(const GameTime &l, const GameTime &r) = default;
    friend auto operator<=>(const GameTime &l, const GameTime &r) = default;

    explicit operator bool() const {
        return Valid();
    }

    static GameTime FromTicks(int64_t ticks) {
        GameTime result;
        result.value = ticks;
        return result;
    }
    static GameTime FromSeconds(int seconds) {
        return GameTime(seconds, 0, 0, 0, 0, 0, 0);
    }
    static GameTime FromMinutes(int minutes) {
        return GameTime(0, minutes, 0, 0, 0, 0, 0);
    }
    static GameTime FromHours(int hours) {
        return GameTime(0, 0, hours, 0, 0, 0, 0);
    }
    static GameTime FromDays(int days) {
        return GameTime(0, 0, 0, days, 0, 0, 0);
    }
    static GameTime FromMonths(int months) {
        return GameTime(0, 0, 0, 0, 0, months, 0);
    }
    static GameTime FromYears(int years) {
        return GameTime(0, 0, 0, 0, 0, 0, years);
    }

    int64_t value = 0;
};

struct Timer {
    Timer() = default;

    /**
     * @return                          Current real time (not game time!) in timer ticks. One tick is 1/128th of a
     *                                  real time second.
     */
    uint64_t Time();

    void Update();
    void Pause();
    void Resume();
    void TrackGameTime();
    void StopGameTime();

    unsigned int bPaused = false;
    int bTackGameTime = 0;
    unsigned int uStartTime = 0; // Last frame time, in real time ticks (128 ticks is 1 real time second).
    unsigned int uStopTime = 0;
    int uGameTimeStart = 0;
    int uTimeElapsed = 0; // dt since last frame in real time ticks (128 ticks is 1 real time second).
    int dt_fixpoint = 0; // dt since last frame in real time seconds in fixpoint format.
    unsigned int uTotalTimeElapsed = 0; // Total time elapsed since the last Initialize() call, in real time ticks (128 ticks is 1 real time second).

    // Real time intervals in timer ticks.
    static const unsigned int Second = 128;
    static const unsigned int Minute = 60 * Second;
    static const unsigned int Hour = 60 * Minute;
    static const unsigned int Day = 24 * Hour;
    static const unsigned int Week = 7 * Day;
    static const unsigned int Month = 4 * Week;
    static const unsigned int Year = 12 * Month;
};

extern Timer *pMiscTimer;
extern Timer *pEventTimer;
