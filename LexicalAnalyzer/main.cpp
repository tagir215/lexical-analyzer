#include "InputHandler.h"
#include "FiniteAutomata.h"
#include <iostream>

int main() {

	InputHandler input_handler;
	FiniteAutomata automata;
	std::vector<std::string> keywords = input_handler.getKeyWords();
	std::vector<std::string> punctuators = input_handler.getPunctuators();
	std::vector<std::string> operators = input_handler.getOperators();

	for (std::string keyword : keywords) {
		automata.insert(keyword, "KEYWORD");
	}
	for (std::string punctuation : punctuators) {
		automata.insert(punctuation, "PUNCTUATION");
	}
	for (std::string opr : operators) {
		automata.insert(opr, "OPERATOR");
	}
	std::string code = input_handler.getCode() + "\n";

	std::string currentWord = "";

	--automata;
	bool halt = false;
	for (int i = 0; i < code.length(); i++) {
		char c = code[i];
		bool stateChanged = automata << c;

		if (!stateChanged || c == '\n') {
			if (& automata) {
				std::cout << automata.state.currentState->type << ":";
				for (int i = automata.state.currentState->type.length(); i < 20; i++) {
					std::cout << " ";
				}
				std::cout << currentWord << std::endl;
			}

			--automata;
			currentWord = "";

			halt = !halt;
		}
		else {
			currentWord += c;
			halt = false;
		}

		if (halt) {
			i--;
		}
	}

	return 0;
}