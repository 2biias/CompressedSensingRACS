#include "FusionCenter.hpp"

FusionCenter::FusionCenter()
: packet_count_(0)
{}

void FusionCenter::getPacket(size_t x_coord, size_t y_coord, float value) {
    
    // Simulate collision?

    // Add measurement to random subset of M
    y.push_back(value);

}

void FusionCenter::newFrame() {
    // reset packet counts etc.
    packet_count_ = 0;
}