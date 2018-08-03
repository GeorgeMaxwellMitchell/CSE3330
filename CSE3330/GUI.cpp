#include "stdafx.h"

#include "GUI.hpp"

#include "Connector.hpp"

namespace cse3330 {

    GUI::GUI(Connector* connector)
    :   connector{ connector } {



    }

    void GUI::show_login() {

        // For testing purposes only
        // This will all likely be placed within its own LoginWindow class

        // Define a test form
        nana::form form_login{ };

        // Layout management for the test window
        // For nana::place documentation go to
        // https://github.com/qPCR4vir/nana-docs/wiki/Using-place-for-layouts#an-illustration
        nana::place place_login{ form_login };

        // TODO: Add formatting here

        // Display the window
        form_login.show();

        // Initiate event loop process
        // Blocks until the window is closed
        nana::exec();

    }

}