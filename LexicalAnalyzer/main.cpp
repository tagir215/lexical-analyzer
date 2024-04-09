#include "InputHandler.h"
#include "FiniteAutomata.h"
#include <iostream>
#include "Token.h"
#include "FileManager.h"

std::string tokenTypeToString(TokenType type) {
	if (type == TokenType::KEYWORD) return "KEYWORD";
	if (type == TokenType::IDENTIFIER) return "IDENTIFIER";
	if (type == TokenType::LITERAL) return "LITERAL";
	if (type == TokenType::OPERATOR) return "OPERATOR";
	if (type == TokenType::PUNCTUATION) return "PUNCTUATION";
	return nullptr;
}

void printTokens(std::vector<Token>& tokens) {
	for (Token token : tokens) {
		std::string line = tokenTypeToString(token.tokenType);
		for (int i = line.length(); i < 20; i++) {
			line += " ";
		}
		line += token.token;
		std::cout << line << std::endl;
	}
}

int main() {

	InputHandler input_handler;
	FiniteAutomata automata;
	std::vector<std::string> keywords = input_handler.getKeyWords();
	std::vector<std::string> punctuators = input_handler.getPunctuators();
	std::vector<std::string> operators = input_handler.getOperators();

	for (std::string keyword : keywords) {
		automata.insert(keyword, TokenType::KEYWORD);
	}
	for (std::string punctuation : punctuators) {
		automata.insert(punctuation, TokenType::PUNCTUATION);
	}
	for (std::string opr : operators) {
		automata.insert(opr, TokenType::OPERATOR);
	}

	std::string code = input_handler.getCode() + "\n";
	std::string currentWord = "";

	std::vector<Token>tokens;

	--automata;
	bool halt = false;
	for (int i = 0; i < code.length(); i++) {
		char c = code[i];
		bool stateChanged = automata << c;

		if (!stateChanged || c == '\n') {
			if (& automata) {
				TokenType type = automata.state.currentState->tokenType;
				tokens.push_back(Token(type, currentWord));
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

	FileManager filemanager;
	filemanager.saveTokensBinary(tokens);
	std::vector<Token>tokens2;
	filemanager.loadTokensBinary(tokens2);
	printTokens(tokens2);
	return 0;
}