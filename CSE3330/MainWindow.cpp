#include "stdafx.h"

#include "MainWindow.hpp"

namespace cse3330 {

    MainWindow::MainWindow() {

    } // MainWindow

    // Note: all window logic placed here to prevent nana from crashing
    // For some reason having both MainWindow and LoginWindow contain
    // window objects causes the program to freeze

    // Handling Connector output:
    // https://github.com/cnjinhao/nana/wiki/Using-STL-Sequence-Container
    void MainWindow::show_window() {

        nana::form window{};
        nana::textbox output_textbox{ window };
        nana::place window_format{ window };

        // Text output config
        output_textbox.multi_lines(true).editable(false).line_wrapped(false);

        // Query buttons
        // TODO: Get requirements from Elmasri on what queries are needed
        nana::button
            test_button_1{ window, "Test Button 1" },
            test_button_2{ window, "Test Button 2" },
            test_button_3{ window, "Test Button 3" };

        // Window format
        window_format.div("<vert weight=100 <vert buttons > <> ><output>");

        window_format["buttons"] 
            << test_button_1
            << test_button_2
            << test_button_3;

        window_format["output"] << output_textbox;

        window_format.collocate();

        window.caption("CSE3330 Project 2");

        // Show the window
        window.show();
        nana::exec();

    } // show_window

} // cse3330