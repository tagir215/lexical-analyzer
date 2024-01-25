#pragma once
#include <vector>
#include <string>

class InputHandler{
public:
	std::vector<std::string> getKeyWords() {
		return getFileAsStrings(KEYWORDS_PATH);
	}
	std::vector<std::string> getPunctuators() {
		return getFileAsStrings(PUNCTUATORS_PATH);
	}
	std::vector<std::string> getOperators() {
		return getFileAsStrings(OPERATORS_PATH);
	}
	std::string getCode() {
		return getFileAsString(EXAMPLECODE_PATH);
	}
private:
	std::string KEYWORDS_PATH = "keywords.txt";
	std::string PUNCTUATORS_PATH = "keywords.txt";
	std::string OPERATORS_PATH = "keywords.txt";
	std::string EXAMPLECODE_PATH = "exmlcode.txt";
	std::vector<std::string> getFileAsStrings(std::string path);
	std::string getFileAsString(std::string path);
};


