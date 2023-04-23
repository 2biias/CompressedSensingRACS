#pragma once
#ifndef FIELD_HPP
#define FIELD_HPP

#include "Sensor.hpp"
#include "FusionCenter.hpp"

#include <vector>
#include <cstdlib>

template<typename T>
using Dataset = std::vector<std::vector<T>>;

class Field
{
public:
    Field(const std::string& file_path);
    float get_U_at(size_t x, size_t y);
    float get_V_at(size_t x, size_t y);
    FusionCenter& get_fusion_center();
private:
    std::vector<std::vector<Sensor>> fieldmap_;
    FusionCenter fc_;
    Dataset<float> U_data;
};

#endif