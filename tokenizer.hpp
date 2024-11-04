#include <iostream>
#include <string>
#include <vector>

#ifndef TOKENIZER_HPP_
#define TOKENIZER_HPP_

using namespace std;

// ... (TokenType and Token struct as defined above)
enum TokenType {
    IDENTIFIER,
    KEYWORD,
    NUMBER,
    OPERATOR,
    PUNCTUATION,
    UNKNOWN
};

struct Token {
    TokenType type;
    string value;
};

vector<Token> tokenize(const string& input);
int beginTokenization();

#endif
