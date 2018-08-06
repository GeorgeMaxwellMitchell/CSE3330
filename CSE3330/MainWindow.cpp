#include "stdafx.h"

#include "MainWindow.hpp"

namespace cse3330 {

    MainWindow::MainWindow() {

    } // MainWindow

    void MainWindow::show_window() {

        nana::form window;
        nana::textbox output_textbox;

        // Text output config
        output_textbox.multi_lines(true).editable(false).line_wrapped(false);

        // Query buttons

        // Window config
        window.caption("CSE3330 Project 2");

        // Show the window
        window.show();
        nana::exec();

    } // show_window

} // cse3330