#include "Creature.h"
#include "Point2D.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature(name, {6, 10});

    while (true) {
        std::cout << creature << '\n';
        std::cout << "Enter a new X location for the creature (-1 to quit): ";
        int x{0};
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter a new Y location for the creature (-1 to quit): ";
        int y{0};
        std::cin >> y;
        if (y == -1)
            break;

        creature.moveTo(x, y);
    };

    return 0;
};
