#include "BGDisplayFaceBigText.h"

#include "BGDisplayManager.h"
#include "globals.h"

void BGDisplayFaceBigText::showReadings(
    const std::list<GlucoseReading>& readings, bool dataIsOld) const {
    auto lastReading = readings.back();
    constexpr int READING_LEFT_PADDING = 0;
    constexpr int TREND_ARROW_X = MATRIX_WIDTH - 5;

    showReading(lastReading, READING_LEFT_PADDING, 7, TEXT_ALIGNMENT::LEFT, FONT_TYPE::LARGE, dataIsOld);
    showTrendArrow(lastReading, TREND_ARROW_X, 1, dataIsOld);

    DisplayManager.update();
}
