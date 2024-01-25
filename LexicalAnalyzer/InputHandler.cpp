#include "InputHandler.h"
#include "fstream"


std::vector<std::string> InputHandler::getFileAsStrings(std::string path){
	std::vector<std::string>strings;
	std::ifstream stream;
	stream.open(path);
	std::string string;
	while (std::getline(stream, string)) {
		strings.push_back(string);
	}
	stream.close();
	return strings;
}

std::string InputHandler::getFileAsString(std::string path) {
	std::ifstream stream(path);
	return std::string((std::istreambuf_iterator<char>(stream)), (std::istreambuf_iterator<char>()));
}
