#pragma once

//#include "controller.h"

#include "Connector.hpp"

#include <iostream>
#include <exception>
#include <memory>

#include <cstdlib>

namespace cse3330 {

    class Core final {

    public:

        Core();

    private:

        Connector connector;

    };

}