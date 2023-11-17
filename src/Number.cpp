#include "../inc/shell.hpp"

Number::Number(float number) {
    _number = number;
    _pos = NULL;
}

Number::Number(float number, Position* pos) {
    _number = number;
    _pos = pos;
}

Number::Number() {
    _number = 0;
    _pos = NULL;
}
// comecou a complicar como fazer pensando que vou receber string e os crlhs aqui;_;
Number* Number::add(Number* number) {
    return new Number(_number + number->_number);
}

Number* Number::sub(Number* number) {
    return new Number(_number - number->_number);
}

Number* Number::mul(Number* number) {
    return new Number(_number * number->_number);
}

Number* Number::div(Number* number, Position* pos) {
    if (number->_number == 0) {
        if (number->_pos == NULL) {
            std::cerr << "Runtime error: Cannot divide by 0\n";
            std::cerr << "In File: '" << pos->_fileName << "', line " << (pos->_ln + 1) << "\n";
            pos->write_error_here(0);
            exit(1);
        }
        else {
            std::cerr << "Runtime error: Cannot divide by 0\n";
            std::cerr << "In File: '" << number->_pos->_fileName << "', line " << (number->_pos->_ln + 1) << "\n";
            number->_pos->write_error_here(-1);
            exit(1);
        }
    }
    return new Number(_number / number->_number);
}

std::string Number::toString() {
    std::string alpha;
    alpha = _number;
    std::cout << "testing: " << alpha << " | " << _number << "\n";
    return "[" + alpha + "]";
}