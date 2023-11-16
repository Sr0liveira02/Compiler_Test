#ifndef NUMBER_HPP
#define NUMBER_HPP

#include "Position.hpp"
#include <string>
// decide whether i want to be float int phobic or i only know floats
class Number {
    public:
    Number(float number);
    Number(float number, Position* pos);
    Number();
    float _number;
    Position* _pos;
    Number* add(Number *number);
    Number* sub(Number* number);
    Number* mul(Number* number);
    Number* div(Number* number, Position* pos);
    std::string toString();
    private:
};

#endif