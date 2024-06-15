#include "FiniteAutomata.h"
#include <iostream>
#include "Token.h"
#include "FileManager.h"
#include "LexicalAnalyzer.h"

std::string tokenTypeToString(TokenType type) {
	if (type == TokenType::KEYWORD) return "KEYWORD";
	if (type == TokenType::IDENTIFIER) return "IDENTIFIER";
	if (type == TokenType::LITERAL) return "LITERAL";
	if (type == TokenType::OPERATOR) return "OPERATOR";
	if (type == TokenType::PUNCTUATION) return "PUNCTUATION";
	return "";
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
	std::string code = 
	R"(const char* s = "hello world";
    int a = 5;
    a++;
    double exampleCodeIdentifier = 50;
    float a5 = 45.0f;
    bool boolean = false;
    
    for(int i=0; i<20; ++i){
        while(a!=900000){
            a-=40;				
        }
    }
    
    return 0;
    )";
	LexicalAnalyzer lexicalAnalyzer;

	std::vector<Token>tokens = lexicalAnalyzer.analyze(code);

	FileManager filemanager;
	filemanager.saveTokensBinary(tokens);
	std::vector<Token>tokens2;
	filemanager.loadTokensBinary(tokens2);
	printTokens(tokens2);
	return 0;
}