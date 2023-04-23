#include "Field.hpp"
#include "Sensor.hpp"
#include "CSVReader.hpp"

#include <iostream>

Field::Field(const std::string& file_path)
{
    using namespace Utilities;
    CSVReader U_reader(file_path + std::string("/data/U.csv"));
    Row row;
    U_reader.getNextRow(row);
    size_t row_len = row.getDimensions();
    U_reader.reset();
    while(U_reader.getNextRow(row)) {
        U_data.push_back(std::vector<float>());
        for(size_t col = 0; col < row_len; ++col) {
            U_data.back().push_back(std::stof(std::string(row[col])));
        }
    }

    for(size_t i = 0; i < row_len; ++i) {
        fieldmap_.push_back(std::vector<Sensor>());
        for(size_t j = 0; j < row_len; ++j) {
            fieldmap_.back().push_back(Sensor(i, j, *this));
        }
    }
}

float Field::get_U_at(size_t x, size_t y) {
    // Read data
    return U_data[x][y];
}

FusionCenter& Field::get_fusion_center() {
    return fc_;
}