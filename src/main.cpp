#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <boost/program_options.hpp>

#include "network.hpp"

namespace po = boost::program_options;

int main(int argc, char **argv) {
    // parse CLI options
    po::options_description desc("CoSyNE");
    desc.add_options()
        ("help,h", "Print a description of available options")
        ("population,p", po::value<unsigned int>()->default_value(100),
         "Population size")
        ("iters,i", po::value<unsigned int>()->default_value(10),
         "Number of iterations before stopping")
        ("mut-prob,m", po::value<float>()->default_value(0.5),
         "Mutation chance")
        ;
    
    po::variables_map vars;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vars);

        if(vars.count("help") != 0) {
            std::cout << "CoSyNE\n" << desc << std::endl;
            return 0;
        }

        po::notify(vars);
    } catch(po::error& e) {
        std::cerr << "error: " << e.what() << "\n\n";
        std::cerr << desc << std::endl;
        return -1;
    }

    // create the neural net
    architecture arch = {
        2,  // inputs
        1,  // outputs
        10, // hidden
        1,  // # of hidden layers
    };
    neural_net net(vars["population"].as<unsigned int>(), arch);
    return 0;
}
