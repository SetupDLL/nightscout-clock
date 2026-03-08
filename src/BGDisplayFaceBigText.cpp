#include "BGDisplayFaceBigText.h"

#include "BGDisplayManager.h"
#include "globals.h"

void BGDisplayFaceBigText::showReadings(
    const std::list<GlucoseReading>& readings, bool dataIsOld) const {
    auto lastReading = readings.back();
    constexpr int TREND_ARROW_WIDTH = 5;
    constexpr int READING_RIGHT_PADDING = TREND_ARROW_WIDTH + 1;

    showReading(
        lastReading, MATRIX_WIDTH - READING_RIGHT_PADDING, 7, TEXT_ALIGNMENT::RIGHT, FONT_TYPE::LARGE,
        dataIsOld);
    showTrendArrow(lastReading, MATRIX_WIDTH - 5, 1, dataIsOld);

    DisplayManager.update();
}
