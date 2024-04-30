Lexical Analyzer 

Small Only C++ Lexical Analyzer Library

LexicalAnalyzer was made for learning purposes of ongonig Compiler Project

It can reliably parse C++ language, and generate usable Tokens

You can check the examples/ for more elaborate usage.

How to Use
Just place the lexpp.h file in your project include directory.
Just include the LexicalAnalyzer.h file in your project and Start using the wonderful thing. 

Basic Examples

std::string data = "some text to parse! ";
std::vector<Token> tokens = LexicalAnalayzer.analyze(data);

for(std::string& t : tokens){
    std::cout << t.token << std::endl;
}

Tokens contain information about the token word, and the token type.


Support
I am just a Highschool student so I may not have the best quality of code but still i am trying my best to write good code!

Any support would be highly appretiated!

For example you could add a feature and contribute via pull requests or you could even report any issues with the program!

And the best thing you could do to support this project is spread word about this so that more people who might be interested in this may use this!

Please considering tweeting about this!
