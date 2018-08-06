#include "stdafx.h"

#include "MainWindow.hpp"

namespace cse3330 {

    MainWindow::MainWindow()
    :   window{ },
        output_textbox{ window } {

        // Text output config
        output_textbox.multi_lines(true).editable(false).line_wrapped(false);

        // Query buttons

        // Window config
        window.caption("CSE3330 Project 2");

    } // MainWindow

    void MainWindow::show_window() {

        window.show();

        nana::exec();

    } // show_window

} // cse3330