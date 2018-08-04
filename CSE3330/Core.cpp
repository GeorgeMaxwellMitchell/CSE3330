#include "stdafx.h"

#include "Core.hpp"

namespace cse3330 {

    Core::Core()
    :   connector{ },
        gui{&connector} {
        
        
    }

    void Core::run() {

        gui.show_login();

    }

} // namespace cse3330

int main(void) {

    try {

        cse3330::Core core{};

        core.run();

    } catch (sql::SQLException& e) {

        std::cerr << "SQL Exception thrown: " << e.what() << std::endl
            << "SQL Error Code: " << e.getErrorCode() << std::endl
            << "SQL State: " << e.getSQLState() << std::endl;

        return EXIT_FAILURE;

    } catch (std::exception& e) {

        std::cerr << "Exception thrown: "<< e.what() << std::endl
            << "Press any key to exit" << std::endl;
        std::getchar();

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

} // main