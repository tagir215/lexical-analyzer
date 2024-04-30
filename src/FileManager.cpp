#pragma once
#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::saveTokensBinary(std::vector<Token>& tokens) {
    std::ofstream outputFile("data.dat", std::ios::binary | std::ios::out);
    if (outputFile.is_open()) {
        size_t numTokens = tokens.size();
        outputFile.write(reinterpret_cast<char*>(&numTokens), sizeof(numTokens));

        for (const Token& token : tokens) {
            outputFile.write(reinterpret_cast<const char*>(&token), sizeof(Token));
        }
        outputFile.close();
    }
    else {
        std::cerr << "Error: ei toiminu.\n";
    }
}

void FileManager::loadTokensBinary(std::vector<Token>& tokens) {
    std::ifstream inputFile("data.dat", std::ios::binary);
    if (inputFile.is_open()) {
        size_t numTokens;
        inputFile.read(reinterpret_cast<char*>(&numTokens), sizeof(numTokens));

        tokens.resize(numTokens);

        for (size_t i = 0; i < numTokens; ++i) {
            inputFile.read(reinterpret_cast<char*>(&tokens[i]), sizeof(Token));
        }
        inputFile.close();
    }
    else {
        std::cerr << "Error: Ei onninstunu lukea.\n";
    }
}