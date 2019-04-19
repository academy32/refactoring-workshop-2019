//
// Created by a26stude on 19.04.19.
//

#include <IPort.hpp>
#include "Torus.h"
#include "SnakeWorld.hpp"

#include "IPort.hpp"
#include "EventT.hpp"

#include "SnakeInterface.hpp"
#include "SnakeSegments.hpp"
namespace Snake {
    Torus::Torus(IPort &displayPort, IPort &foodPort, Snake::Dimension dimension, Snake::Position food)
            : m_displayPort(displayPort),
              m_foodPort(foodPort),
              m_foodPosition(food),
              m_dimension(dimension),
              World(displayPort,foodPort,dimension,food)
              {}

    bool Torus::contains(Snake::Position position) const {
        return true;
    }
}