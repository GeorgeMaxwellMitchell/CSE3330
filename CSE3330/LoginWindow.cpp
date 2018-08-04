#include "stdafx.h"

#include "LoginWindow.hpp"

namespace cse3330 {

    // 

    // Constructor also defines window layout
    login_window::login_window()
    :   window{ },
        login_button{ window, "Login" },
        host_name_textbox{ window },
        user_name_textbox{ window },
        password_textbox{ window },
        database_name_textbox{ window },
        window_format{ window } {
    
        host_name_textbox.tip_string("Hostname").multi_lines(false);
        user_name_textbox.tip_string("Username").multi_lines(false);
        password_textbox.tip_string("Password").multi_lines(false).mask('*');
        database_name_textbox.tip_string("Database").multi_lines(false);

        // https://github.com/qPCR4vir/nana-docs/wiki/Using-place-for-layouts#an-illustration
        window_format.div("<><weight=80% vertical "
            "<><weight=70% vertical "
            "<vertical gap=10 textboxes arrange=[25,25]> "
            "<weight=25 gap=10 buttons>"
            "><>><>");

        window_format.field("textboxes") << host_name_textbox
            << user_name_textbox
            << password_textbox
            << database_name_textbox;

        window_format["buttons"] << login_button;

        window_format.collocate();

        // Lambda describing window behavior for clicking on login_button
        // Stores all values into respective members and throws runtime error
        //   when one is blank
        login_button.events().mouse_up( [&] {

            host_name_textbox.getline(0, hostname);
            user_name_textbox.getline(0, username);
            password_textbox.getline(0, password);
            database_name_textbox.getline(0, database);

            window.close();

        });
    
    } // login_window

    void login_window::show_window() {
    
        window.show();

        nana::exec();

        
       
    
    } // show_window

    // Window input getters
    std::string login_window::get_hostname() const { return hostname; }

    std::string login_window::get_username() const { return username; }

    std::string login_window::get_password() const { return password; }

    std::string login_window::get_database() const { return database; }

}