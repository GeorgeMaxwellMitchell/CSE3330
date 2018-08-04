#pragma once

namespace cse3330 {

    class login_window final {

    public:

        login_window();

        void show_window();

        std::string get_hostname() const;

        std::string get_username() const;

        std::string get_password() const;

        std::string get_database() const;

    private:

        nana::form window;

        nana::button login_button;

        nana::textbox
            host_name_textbox,
            user_name_textbox,
            password_textbox,
            database_name_textbox;

        // Used to describe window format
        nana::place window_format;

        // Stored values taken from window
        std::string
            hostname,
            username,
            password,
            database;

    }; // login_window

} // cse3330