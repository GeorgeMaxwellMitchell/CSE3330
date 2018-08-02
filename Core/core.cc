#include "core.h"

#include "connector.h"

#include <iostream>
#include <exception>

#include <cstdlib>

int main(void) {

    try {

        cse3330::Connector connector{};

    } catch (std::exception& e) {

        std::cerr << "Exception thrown: "<< e.what() << std::endl;
        std::cerr << "Press any key to exit" << std::endl;
        std::getchar();

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}