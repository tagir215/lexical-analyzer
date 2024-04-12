#pragma once
#include "TokenType.h"
#include <string>
struct Token{
	Token(TokenType tokenType, std::string token) : tokenType(tokenType), token(token) {}
	Token() {}
	TokenType tokenType;
	std::string token;
};
