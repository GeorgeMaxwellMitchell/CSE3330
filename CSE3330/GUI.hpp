#pragma once

#include "LoginWindow.hpp"

namespace cse3330 {

    class Connector;
    class LoginWindow;

    class GUI final {

    public:

        GUI(Connector* connector);

        // Displays the login window
        void show_login();

    private:

        Connector* connector;   // Pointer to Connector object

        LoginWindow login_window;

    };

}
