#pragma once

#include "selectable.hpp"

class Clickable : public Selectable
{
    //This is virtual class - DON'T USE IT!
    //Inheritance only!

public:

    Clickable();
    virtual ~Clickable();

    virtual void signalConnect(void* data) = 0;
    virtual void clicked() = 0;
    virtual void released() = 0;
};