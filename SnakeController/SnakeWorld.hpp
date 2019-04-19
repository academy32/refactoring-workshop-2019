#pragma once

#include <functional>

#include "SnakePosition.hpp"
#include "SnakeDimension.hpp"
#include "SnakeSegments.hpp"

class IPort;

namespace Snake
{
    class Segments;


    class IWorld{

    public:
        virtual bool contains(Position position) const=0;
        virtual bool eatFood(Position position) const=0;

        virtual void updateFoodPosition(Position position, Segments const& segments)=0;
        virtual void placeFood(Position position, Segments const& segments)=0;
    };


class World :public IWorld
{
public:
    World(IPort& displayPort, IPort& foodPort, Dimension dimension, Position food);


    bool contains(Position position) const;
    bool eatFood(Position position) const;

     void updateFoodPosition(Position position, Segments const& segments);
     void placeFood(Position position, Segments const& segments);

private:
    IPort& m_displayPort;
    IPort& m_foodPort;

    Position m_foodPosition;
    Dimension m_dimension;

    void sendPlaceNewFood(Position position);
    void sendClearOldFood();
    void updateFoodPositionWithCleanPolicy(Position position, Segments const& segments, std::function<void()> clearPolicy);
};

} // namespace Snake
