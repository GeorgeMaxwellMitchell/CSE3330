#pragma once

#include "LoginWindow.hpp"
#include "MainWindow.hpp"

namespace cse3330 {

    class Connector;
    class LoginWindow;

    class GUI final {

    public:

        GUI(Connector* connector);

        // Displays the login window
        void show_login();

        // Displays the main window
        //void show_main();

    private:

        Connector* connector;   // Pointer to Connector object

        LoginWindow login_window;
        //MainWindow main_window;

    };

}
