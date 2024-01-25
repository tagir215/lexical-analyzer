#include "InputHandler.h"
#include "FiniteAutomata.h"
#include <iostream>

int main() {

	InputHandler input_handler;
	FiniteAutomata automata;
	std::vector<std::string> keywords = input_handler.getKeyWords();
	for (std::string keyword : keywords) {
		automata.insert(keyword);
	}
	std::string code = input_handler.getCode();

	std::string currentWord = "";

	--automata;
	for (char c : code) {

		bool stateChanged = automata << c;

		if (!stateChanged || c == ' ' || c == '\n') {
			if (& automata) {
				std::cout << automata.state.currentState->type << ":" ;
				for (int i = automata.state.currentState->type.length(); i < 20; i++) {
					std::cout << " ";
				}
				std::cout << currentWord << std::endl;
			}

			--automata;
			currentWord = "";

		}
		else {
			currentWord += c;
		}

	}

	return 0;
}