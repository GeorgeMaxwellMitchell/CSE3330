#pragma once

#include "Controller.hpp"

#include "Connector.hpp"


namespace cse3330 {

    class Core final {

    public:

        Core();

    private:

        Connector connector;

    };

}