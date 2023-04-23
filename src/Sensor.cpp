#include "Sensor.hpp"
#include "Field.hpp"

Sensor::Sensor(size_t x, size_t y, Field& field)
:   x_coord_(x), y_coord_(y), field_(field)
{}

void Sensor::make_measurement() {
    // Throw the coin, i.e. with some proabability participate in measuring
    int p_pct = 50;
    bool truefalse = (rand() % 100) < p_pct;
    // Either read or generate value
    if(truefalse) {
        float value = field_.get_U_at(x_coord_, y_coord_);
        // Add random noise z?
        FusionCenter& fc = field_.get_fusion_center();
        fc.getPacket(x_coord_, y_coord_, value);
    }
}