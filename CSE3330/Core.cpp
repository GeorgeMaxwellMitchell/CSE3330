#include "stdafx.h"

#include "Core.hpp"

namespace cse3330 {

    Core::Core()
    :   connector{&gui},
        gui{&connector} {
        
        
    }

    void Core::run() {

        gui.show_login();

    }

}

int main(void) {

    try {

        cse3330::Core core{};

        core.run();

    } catch (std::exception& e) {

        std::cerr << "Exception thrown: "<< e.what() << std::endl;
        std::cerr << "Press any key to exit" << std::endl;
        std::getchar();

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}