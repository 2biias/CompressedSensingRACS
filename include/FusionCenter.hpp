#ifndef FUSIONCENTER_HPP
#define FUSIONCENTER_HPP

#include <stdlib.h>
#include <vector>
#include <memory>
//#include "ortools/linear_solver/linear_solver.h"


class FusionCenter
{
public:
    FusionCenter();
    void newFrame();
    void getPacket(size_t x, size_t y, float value);
private:
    size_t packet_count_;

    // Reconstruction
    //std::unique_ptr<MPSolver> solver;
    std::vector<std::vector<bool>> R; // Random selection matrix
    std::vector<float> y;
};

#endif