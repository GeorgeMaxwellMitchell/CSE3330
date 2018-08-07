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
        nana::textbox team_query_textbox{ window };
        team_query_textbox.tip_string("Enter team name to show players");
        team_query_textbox.multi_lines(false);
        team_query_textbox.events().key_char(
            [&](nana::arg_keyboard const& key_arg) {

                std::string team_name;
                team_query_textbox.getline(0, team_name);
                if (team_name.empty()) { return; }

                if (key_arg.key == nana::keyboard::enter) {

                    std::string query = 
                        "SELECT PName, PNo, Position FROM PLAYER WHERE Team =" 
                        + team_name + ";";

                    auto results = connector->send_query(query, 0);
                    if (!results.empty()) { 
                        display_results(results, output_textbox);
                    }

                }

        }); // team_query_textbox behavior

        // Window format ------------------------------------------------
        nana::place window_format{ window };
        window_format.div("<vert weight=30% <vert height=25 input > <> ><output>");
        window_format["input"] << team_query_textbox;
        window_format["output"] << output_textbox;
        window_format.collocate();

        // Show the window ----------------------------------------------
        window.show();
        nana::exec();

    } // show_main

    void GUI::display_results(
        std::vector<std::vector<std::string>>& results,
        nana::textbox& output_textbox) {

        output_textbox.reset();

        std::for_each(results.begin(), results.end(), [&](auto& row) {
        
            std::for_each(row.begin(), row.end(), [&](auto& col_val) {
            
                // Testing on the command line
                // TODO: move to output textbox

                std::cout << std::setw(10) << col_val << "\t";
            
            });

            std::cout << std::endl;
        
        });

    }

} // cse3330
