#ifndef POSITION_HPP
#define POSITION_HPP

#include <string>

class Position {
    public:
    Position(int i, int ln, int col, std::string fileName, std::string fileText);
    Position();
    int _i;
    int _ln;
    int _col;
    std::string _fileName;
    std::string _fileText;
    void advance(char currentChar);
    Position* copy();
    void write_error_here();
    private:
};

#endif