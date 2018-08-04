#include "stdafx.h"

#include "GUI.hpp"

#include "Connector.hpp"

namespace cse3330 {

    GUI::GUI(Connector* connector)
    :   connector{ connector } { }

    void GUI::show_login() {

        l_win.show_window();

    }

}
