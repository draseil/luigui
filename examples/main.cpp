#include <iostream>
#include "entity.hpp"

int main() {
    Entity e({1, 2}, {3, 4});

    std::cout << e.getPosition().x << ", " << e.getPosition().y << std::endl
              << e.getSize().x     << ", " << e.getSize().y     << std::endl;
}