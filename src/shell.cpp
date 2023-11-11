#include "shell.hpp"

int main() {

    while(true){
        std::string input;
        std::cout << "> ";
        std::getline(std::cin, input);
	    if (input[0] == 'q' && input[1] == '\0')
		    break;
        Lexer lexer = Lexer(input);
        lexer.make_tokens();
        std::cout << "Cheguei aqui\n";
        lexer.print_tokens();
    }
    return 0;
}
