#ifndef CREATURE_H
#define CREATURE_H

#include "Point2D.h"
#include <iostream>
#include <string>
#include <string_view>

class Creature {
  private:
    std::string m_name;
    Point2D m_location;

  public:
    Creature(std::string_view name, const Point2D &location)
        : m_name{name}, m_location(location){};

    friend std::ostream &operator<<(std::ostream &out,
                                    const Creature &creature) {
        out << "Creature " << creature.m_name << " is at "
            << creature.m_location;
        return out;
    };

    void moveTo(int x, int y) { m_location.setPoint(x, y); };
};

#endif
