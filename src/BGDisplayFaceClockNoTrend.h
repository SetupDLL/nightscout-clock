#ifndef BGDISPLAYFACECLOCKNOTREND_H
#define BGDISPLAYFACECLOCKNOTREND_H

#include "BGDisplayFaceTextBase.h"
#include "BGSource.h"

class BGDisplayFaceClockNoTrend : public BGDisplayFaceTextBase {
public:
    void showReadings(const std::list<GlucoseReading>& readings, bool dataIsOld = false) const override;
    void showNoData() const override;

private:
    void showClock() const;
};

#endif
