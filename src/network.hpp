#pragma once

#include <stdint.h>

struct architecture {
    unsigned int inputs;    // number of input neurons
    unsigned int outputs;   // number of output neurons
    unsigned int hidden;    // number of neurons per hidden layer
    unsigned int layers;    // number of hidden layers
};

class neural_net {
public:
    neural_net(unsigned int popsz, architecture arch);
    ~neural_net();

private:
    unsigned int m_popsz;
    architecture m_arch;
};

