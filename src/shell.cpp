#include "../inc/shell.hpp"

int main() {

    while(true){
        std::string input;
        std::cout << "> ";
        std::getline(std::cin, input);
	    if (input[0] == 'q' && input[1] == '\0')
		    break;

        // generate Tokens
        Lexer lexer = Lexer("<stdin>", input);
        lexer.make_tokens();
        //lexer.print_tokens();
        //printf("\n");

        // Generate Parsing Tree
        Parser parser = Parser(&lexer._tokens);
        Node *node = parser.parse();
        //std::cout << node->toString() << "\n";

        // Interpreting 
        Interpreter inti = Interpreter();
        Number* res = inti.visit(node);
        std::cout << "= " << res->_number << "\n";

    }
    return 0;
}
