#pragma once

#include "SnakePosition.hpp"
#include "SnakeDimension.hpp"
#include "SnakeWorld.hpp"

namespace Snake {
    class Torus : public World {
    private:
        IPort &m_displayPort;
        IPort &m_foodPort;
        Dimension m_dimension;
        Position m_foodPosition;

    public:
        Torus(IPort &displayPort, IPort &foodPort, Dimension dimension, Position food);

        bool contains(Position position) const;
    };
}


