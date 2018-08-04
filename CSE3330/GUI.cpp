#include "stdafx.h"

#include "GUI.hpp"

#include "Connector.hpp"

namespace cse3330 {

    GUI::GUI(Connector* connector)
    :   connector{ connector } { }

    void GUI::show_login() {

        l_win.show_window();

        std::string hostname = l_win.get_hostname();
        std::string username = l_win.get_username();
        std::string password = l_win.get_password();
        std::string database = l_win.get_database();

        connector->connect_to_server(hostname, username, password, database);

    }

}
