#pragma once

#include "Connector.hpp"
#include "GUI.hpp"

namespace cse3330 {

    class Core final {

    public:

        Core();

    private:

        Connector connector;
        GUI gui;
    };

}