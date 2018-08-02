#include "core.h"

int main(void) {

    try {

        std::shared_ptr<cse3330::Connector> connector{ 
            std::make_shared<cse3330::Connector>() };

    } catch (std::exception& e) {

        std::cerr << "Exception thrown: "<< e.what() << std::endl;
        std::cerr << "Press any key to exit" << std::endl;
        std::getchar();

        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}