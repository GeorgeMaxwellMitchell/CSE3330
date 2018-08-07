#include "stdafx.h"

#include "GUI.hpp"

#include "Connector.hpp"

namespace cse3330 {

    GUI::GUI(Connector* connector)
    :   connector{ connector },
        login_window{ }
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

    } // show_login

    // Note: all window logic placed here to prevent nana from crashing
    // For some reason having both MainWindow and LoginWindow contain
    // window objects causes the program to freeze
    void GUI::show_main() {

        // Window configuration -----------------------------------------
        nana::form window{ };
        window.caption("CSE3330 Project 2");

        // Output textbox configuration ---------------------------------
        nana::textbox output_textbox{ window };
        output_textbox.multi_lines(true).editable(false).line_wrapped(false);


        
        // Team Query textbox config ------------------------------------
        nana::textbox team_query{ window };
        team_query.tip_string("Enter Team Name");
        team_query.multi_lines(false);

        team_query.events().key_release(
            [&](nana::arg_keyboard const& key_arg) {
                
                std::string team_name;
                team_query.getline(0, team_name);
                if (!team_name.empty())
                    return;

                if (key_arg.key == nana::keyboard::enter) {
                    
                    std::string query = "";

                    auto result = connector->send_query(query, 0);

                    // display_results(result);

                }

            }
        );

        // Query buttons
        // TODO: Get requirements from Elmasri on what queries are needed
        nana::button
            test_button_1{ window, "Test Button 1" },
            test_button_2{ window, "Test Button 2" },
            test_button_3{ window, "Test Button 3" };

        // Window format ------------------------------------------------
        nana::place window_format{ window };
        window_format.div("<vert weight=100 <vert buttons > <> ><output>");

        window_format["buttons"]
            << test_button_1
            << test_button_2
            << test_button_3;

        window_format["output"] << output_textbox;

        window_format.collocate();

        // Show the window ----------------------------------------------
        window.show();
        nana::exec();

    } // show_main

} // cse3330
