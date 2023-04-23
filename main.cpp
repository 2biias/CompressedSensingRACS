#include <iostream>
#include "Field.hpp"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cout << "Not enough parameters. Usage: CSapp <datapath>" << std::endl;
        exit(1);
    }

    std::string data_path = std::string(argv[1]);
    Field field(data_path);

    //printf("data at: 0,16: %.2f\n", field.get_measurement_at(0,16));

    // Main loop
    size_t iterations = 10;
    while(iterations--) {
        // Let all sensors do a measurement at random
        // Send data to FC if measurement taken
        // Let FC do a reconstruction
        // Update the field
    }
}