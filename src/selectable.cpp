#include "selectable.hpp"

Selectable::Selectable(){}

Selectable::~Selectable(){}

bool Selectable::contain(sf::Vector2f mousePos)
{
    /**
     * @return selectable default bahvior
     */

    return false;
}

bool Selectable::isToMove()
{
    /**
     * @return selectable default bahvior
     */

    return false;
}

bool Selectable::isReturn()
{
    /**
     * @return selectable default bahvior
     */

    return false;
}

void Selectable::setToDelete() {}

bool Selectable::isToDelete()
{
    /**
     * @return selectable default bahvior
     */

    return false;
}

void Selectable::hover() {}

void Selectable::unHover() {}
