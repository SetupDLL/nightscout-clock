#include "BGDisplayFaceBigText.h"

#include "BGDisplayManager.h"
#include "globals.h"

void BGDisplayFaceBigText::showReadings(
    const std::list<GlucoseReading>& readings, bool dataIsOld) const {
    showReading(readings.back(), MATRIX_WIDTH, 7, TEXT_ALIGNMENT::RIGHT, FONT_TYPE::LARGE, dataIsOld);
    DisplayManager.update();
}
