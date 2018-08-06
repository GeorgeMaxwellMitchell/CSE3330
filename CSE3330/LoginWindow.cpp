#include "stdafx.h"

#include "LoginWindow.hpp"

namespace cse3330 {

    // 

    // Constructor also defines window layout
    LoginWindow::LoginWindow()
    :   window{ },
        login_button{ window, "Login" },
        host_name_textbox{ window },
        user_name_textbox{ window },
        password_textbox{ window },
        database_name_textbox{ window },
        window_format{ window } {

        // Text input config
        host_name_textbox.tip_string("Hostname").multi_lines(false);
        user_name_textbox.tip_string("Username").multi_lines(false);
        password_textbox.tip_string("Password").multi_lines(false).mask('*');
        database_name_textbox.tip_string("Database").multi_lines(false);

        // Window config
        // https://github.com/qPCR4vir/nana-docs/wiki/Using-place-for-layouts#an-illustration
        window_format.div("<><weight=80% vertical "
            "<><weight=70% vertical "
            "<vertical gap=10 textboxes arrange=[25,25]> "
            "<weight=25 gap=10 buttons>"
            "><>><>");

        window.caption("CSE3330 Project 2");

        window_format.field("textboxes") 
            << host_name_textbox
            << user_name_textbox
            << password_textbox
            << database_name_textbox;

        window_format["buttons"] << login_button;

        window_format.collocate();

        // Login button behavior
        // Stores login info on selecting login button
        login_button.events().mouse_up( [&] {

            host_name_textbox.getline(0, hostname);
            user_name_textbox.getline(0, username);
            password_textbox.getline(0, password);
            database_name_textbox.getline(0, database);

            window.close();

        });
    
    } // login_window

    void LoginWindow::show_window() {
    
        window.show();

        nana::exec();
    
    } // show_window

    // Window input getters
    std::string LoginWindow::get_hostname() const { return hostname; }

    std::string LoginWindow::get_username() const { return username; }

    std::string LoginWindow::get_password() const { return password; }

    std::string LoginWindow::get_database() const { return database; }

}