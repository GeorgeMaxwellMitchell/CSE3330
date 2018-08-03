#pragma once

namespace cse3330 {

    class Connector;

    class GUI final {

    public:

        GUI(Connector* connector);

        // Displays the login window
        void show_login();

    private:

        Connector* connector;   // Pointer to Connector object

    };

}