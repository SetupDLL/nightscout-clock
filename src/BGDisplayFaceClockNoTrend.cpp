#include "BGDisplayFaceClockNoTrend.h"

#include "BGDisplayManager.h"
#include "ServerManager.h"
#include "globals.h"

void BGDisplayFaceClockNoTrend::showReadings(
    const std::list<GlucoseReading>& readings, bool dataIsOld) const {
    showClock();

    showReading(readings.back(), 33, 6, TEXT_ALIGNMENT::RIGHT, FONT_TYPE::MEDIUM, dataIsOld);

    switch (SettingsManager.settings.time_format) {
        case TIME_FORMAT::HOURS_12:
            BGDisplayManager_::drawTimerBlocks(readings.back(), MATRIX_WIDTH - 17, 18, 7);
            break;
        default:
            BGDisplayManager_::drawTimerBlocks(readings.back(), MATRIX_WIDTH, 0, 7);
            break;
    }
}

void BGDisplayFaceClockNoTrend::showClock() const {
    tm timeinfo = ServerManager.getTimezonedTime();

    auto time_format = SettingsManager.settings.time_format;
    if (time_format == TIME_FORMAT::HOURS_12) {
        bool is_pm = timeinfo.tm_hour >= 12;
        if (timeinfo.tm_hour == 0) {
            timeinfo.tm_hour = 12;
        } else if (timeinfo.tm_hour > 12) {
            timeinfo.tm_hour -= 12;
        }

        for (int i = 0; i < 16; i++) {
            DisplayManager.drawPixel(i, 7, is_pm ? COLOR_BLUE : COLOR_CYAN);
        }
    }

    char timeText[6];
    snprintf(timeText, sizeof(timeText), "%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min);

    DisplayManager.setTextColor(COLOR_WHITE);
    DisplayManager.printText(0, 6, timeText, TEXT_ALIGNMENT::LEFT, 2);
}

void BGDisplayFaceClockNoTrend::showNoData() const {
    showClock();
}
