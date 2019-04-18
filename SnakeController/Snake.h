//
// Created by a26stude on 18.04.19.
//

#pragma once


#include <IPort.hpp>

class SnakeClass {
    IPort& m_displayPort;
    IPort& m_foodPort;
    IPort& m_scorePort;
public:
    SnakeClass():
    m_displayPort(p_displayPort),
            m_foodPort(p_foodPort),
            m_scorePort(p_scorePort);

    struct Segment
    {
        int x;
        int y;
    };
    std::list<Segment> m_segments;
    bool isSegmentAtPosition(int x, int y) const;
    Segment calculateNewHead() const;
    void updateSegmentsIfSuccessfullMove(Segment const& newHead);
    void addHeadSegment(Segment const& newHead);
    void removeTailSegmentIfNotScored(Segment const& newHead);
    void removeTailSegment();
};



