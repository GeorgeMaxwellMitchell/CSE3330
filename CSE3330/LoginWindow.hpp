#pragma once

namespace cse3330 {

    class login_window final {

    public:

        login_window();
        ~login_window();

        void show_window();

    private:

        nana::form window;

        nana::button login_button;

        nana::textbox
            host_name_textbox,
            user_name_textbox,
            password_textbox,
            database_name_textbox;

        nana::place window_format;

    };

} // cse3330