//#pragma once
#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <stdlib.h>

class Field;

class Sensor
{
public:
    Sensor(size_t x, size_t y, Field& field);
    void make_measurement();
private:
    size_t x_coord_;
    size_t y_coord_;
    Field& field_;
};

#endif