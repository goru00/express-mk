#pragma once 
#include <Arduino.h>

class Express
{
public:
    Express();
    void use();
    void use(String);
    void listen();
    void listen(uint32_t);
};