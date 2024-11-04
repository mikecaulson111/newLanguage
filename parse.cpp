#include <iostream>
#include <string>
#include <vector>

#include "tokenizer.hpp"
#include "expression.hpp"

using namespace std;


int main() {
    
    vector<Token> tokens;
    tokens.push_back({NUMBER, "1"});
    tokens.push_back({OPERATOR, "+"});
    tokens.push_back({NUMBER, "17"});


    return 0;
}
