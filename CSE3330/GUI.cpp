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
        nana::form form_test{ };

        // Define a label to display some text
        nana::label label_test{ form_test, "Window test successful" };
        label_test.format(true);

        // Define a quit button
        nana::button button_quit_test{ form_test, "Quit" };
        button_quit_test.events().click(
            [&form_test] { form_test.close(); }
        );

        // Layout management for the test window
        form_test.div(
            "vert"
            "<> < <> <weight=80% text> <> > <>"
            " <weight=24% <> <button> <> > <>" );
        form_test["text"] << label_test;
        form_test["button"] << button_quit_test;
        form_test.collocate();

        // Display the window
        form_test.show();

        // Initiate event loop process
        // Blocks until the window is closed
        nana::exec();

    }

}