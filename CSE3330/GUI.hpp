#pragma once

namespace cse3330 {

    class Connector;

    class GUI final {

    public:

        GUI(Connector* connector);

    private:

        Connector* connector;

    };

}