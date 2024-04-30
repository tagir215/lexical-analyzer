#pragma once
#include <string>
#include "Token.h"
#include <vector>

/*
* tallentaa ja lataa bin‰‰ri tiedostoja
*/
class FileManager {
public:
	void saveTokensBinary(std::vector<Token>& tokens);
	void loadTokensBinary(std::vector<Token>& tokens);
};
