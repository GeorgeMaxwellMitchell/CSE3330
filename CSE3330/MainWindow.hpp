#pragma once

namespace cse3330 {

    class MainWindow final {

    public:

        MainWindow();

        void show_window();

    private:

        nana::form window;

        nana::textbox output_textbox;

    };

}