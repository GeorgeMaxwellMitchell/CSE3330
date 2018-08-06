#include "stdafx.h"

#include "GUI.hpp"

#include "Connector.hpp"

namespace cse3330 {

    GUI::GUI(Connector* connector)
    :   connector{ connector },
        login_window{ }//,
        //main_window{ } 
    { }

    void GUI::show_login() {

        login_window.show_window();

        std::string hostname{ login_window.get_hostname() };
        std::string username{ login_window.get_username() };
        std::string password{ login_window.get_password() };
        std::string database{ login_window.get_database() };

        if (hostname.empty()) {

            hostname = "localhost";

        }

        connector->connect_to_server(hostname, username, password, database);

    }

    /*void GUI::show_main() {

        main_window.show_window();

    }*/

}
