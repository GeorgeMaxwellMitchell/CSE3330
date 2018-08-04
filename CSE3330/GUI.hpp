#pragma once

#include "LoginWindow.hpp"

namespace cse3330 {

    class Connector;
    class login_window;

    class GUI final {

    public:

        GUI(Connector* connector);

        // Displays the login window
        void show_login();

    private:

        Connector* connector;   // Pointer to Connector object

        login_window l_win;

    };

}
