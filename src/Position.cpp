#include "../inc/shell.hpp"

Position::Position(int i, int ln, int col, std::string fileName, std::string fileText) {
    _i = i;
    _ln = ln;
    _col = col;
    _fileName = fileName;
    _fileText = fileText;
}

Position::Position() {
    _i = -1;
    _ln = 0;
    _col = -1;
}

void Position::advance(char current_char) {
    _i++;
    _col++;

    if (current_char == '\n') {
        _col = 0;
        _ln++;
    }
}

Position* Position::copy() {
    Position* pos = new Position(_i, _ln, _col, _fileName, _fileText);
    return pos;
}

void Position::write_error_here(int offset) {
    int lastLine = _i;
    char last = _fileText[lastLine];
    int nextLine = _i;
    char next = _fileText[nextLine];
    while(last != '\n' && lastLine != 0) {
        lastLine--;
        last = _fileText[lastLine];
    }
    if(lastLine == 0)
        lastLine--;
    while(next != '\n' && next != '\0') {
        nextLine++;
        next = _fileText[nextLine];
    }
    for(int i = lastLine + 1; i <nextLine; i++) {
        std::cout << _fileText[i];
    }
    std::cout << "\n";
    for(int i = lastLine + 1; i <_i + offset; i++) {
        std::cout << " ";
    }
    std::cout << "^\n";
}
