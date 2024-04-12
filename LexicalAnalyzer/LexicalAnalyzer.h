#pragma once
#include "FiniteAutomata.h"
#include <iostream>
#include "Token.h"

/*
* Tekee leksikaalisen analyysin C++ koodeille
*/
class LexicalAnalyzer {
public:
	LexicalAnalyzer();
	/*
	* Ottaa sis��n koodin string muodossa, ja palauttaa vektorilistan Tokeneita
	*/
	std::vector<Token>analyze(std::string code);

private:
	FiniteAutomata automata;
    std::vector<std::string> keywords = {
        "alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit",
        "atomic_noexcept", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
        "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const",
        "consteval", "constexpr", "constinit", "const_cast", "continue", "co_await",
        "co_return", "co_yield", "decltype", "default", "delete", "do", "double",
        "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float",
        "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace",
        "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private",
        "protected", "public", "reflexpr", "register", "reinterpret_cast", "requires",
        "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast",
        "struct", "switch", "synchronized", "template", "this", "thread_local", "throw",
        "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
        "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    };
    std::vector<std::string> punctuators = { "{", "}", "[", "]", "#", "##", "(", ")", ";", "...", "|" };
    std::vector<std::string> operators = { 
        "+", "-", "*", "/", "%", "=", "++", "--", "+=", "-=", "*=", "/=", "%=", "==", "!=", 
        ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", ":", "?", ".", "->" 
    };

};
