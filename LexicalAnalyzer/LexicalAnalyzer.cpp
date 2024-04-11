#pragma once
#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer() {
	for (std::string keyword : keywords) {
		automata.insert(keyword, TokenType::KEYWORD);
	}
	for (std::string punctuation : punctuators) {
		automata.insert(punctuation, TokenType::PUNCTUATION);
	}
	for (std::string opr : operators) {
		automata.insert(opr, TokenType::OPERATOR);
	}
}

std::vector<Token>LexicalAnalyzer::analyze(std::string code) {
	code += "\n";
	std::string currentWord = "";

	std::vector<Token>tokens;

	--automata;
	bool halt = false;
	for (int i = 0; i < code.length(); i++) {
		char c = code[i];
		bool stateChanged = automata << c;

		if (!stateChanged || c == '\n') {
			if (&automata) {
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
	return tokens;
}