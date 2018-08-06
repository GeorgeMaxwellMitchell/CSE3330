#include "stdafx.h"

#include "Core.hpp"

namespace cse3330 {

    Core::Core()
    :   connector{ },
        gui{&connector} { }

    void Core::run() {

        std::cerr << "CSE3330 Project 2 by George Mitchell & Peter Severynen" << std::endl;
        std::cerr << "Logging info will appear here" << std::endl;

        gui.show_login();

        gui.show_main();

    }

} // namespace cse3330

int main(void) {

    try {

        cse3330::Core core{ };

        core.run();

    } catch (sql::SQLException& e) {

        std::cerr << "SQL Exception thrown: " << e.what() << std::endl
            << "SQL Error Code: " << e.getErrorCode() << std::endl
            << "SQL State: " << e.getSQLState() << std::endl
            <<  "Press any key to exit" << std::endl;

        std::getchar();

        return EXIT_FAILURE;

    } catch (std::exception& e) {

        std::cerr << "Exception thrown: "<< e.what() << std::endl
            << "Press any key to exit" << std::endl;

        std::getchar();

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

} // main