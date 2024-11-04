#include <iostream>
#include <vector>
#include <string>

#include "tokenizer.hpp"

using namespace std;

// // ... (TokenType and Token struct as defined above)
// enum TokenType {
//     IDENTIFIER,
//     KEYWORD,
//     NUMBER,
//     OPERATOR,
//     PUNCTUATION,
//     UNKNOWN
// };
// 
// struct Token {
//     TokenType type;
//     string value;
// };

// struct node {
//     Token token;
//     struct node *left;
//     struct node *right;
// };
// 
// struct node *newNode(Token token) {
//     struct node *node = (struct node *)malloc(sizeof(struct node));
//     node->token = token;
//     node->left = NULL;
//     node->right = NULL;
//     return node;
// }

vector<Token> tokenize(const string& input) {
    vector<Token> tokens;
    string currentToken;

    for (char c : input) {
        if (isspace(c)) {
            // Skip whitespace
        } else if (isalnum(c)) {
            currentToken += c;
        } else {
            if (!currentToken.empty()) {
                if (currentToken[0] >= 48 && currentToken[0] <= 57) {
                    tokens.push_back({NUMBER, currentToken});
                } else {
                    tokens.push_back({IDENTIFIER, currentToken});
                }
                currentToken.clear();
            }
            tokens.push_back({OPERATOR, string(1, c)});
        }
    }

    if (!currentToken.empty()) {
        if (currentToken[0] >= 48 && currentToken[0] <= 57) {
            tokens.push_back({NUMBER, currentToken});
        } else {
            tokens.push_back({IDENTIFIER, currentToken});
        }
        currentToken.clear();
    } else {
        tokens.push_back({OPERATOR, string(1, input[input.length()-1])});
    }

    return tokens;
}

// struct node *parseTokens(vector<Token> tokens) {
//     node* root = NULL;
//     node* curr = NULL;
//     for (Token token : tokens) {
//         if (root == NULL) {
//             root = newNode(token);
//             curr = root;
//         } else {
//             node* temp = newNode(token);
//             curr->right = temp;
//             if (temp.type == OPERATOR ) {
//                 // rotate tree left
//             }
//             curr = curr->right;
//         }
//     }
//     return root;
// }

int beginTokenization() {
    // string input = "x = 10 + 20;";
    string input = "";
    cout << "Enter the math equation to parse" << endl;
    getline(cin, input);
    vector<Token> tokens = tokenize(input);

    for (const Token& token : tokens) {
        cout << "Type: " << token.type << ", Value: " << token.value << endl;
    }

    // node* root = NULL;
    // root = parseTokens(tokens);
    // if (root != NULL) {
    //     cout << "type: " << root->token.type << " val: " << root->token.value << endl;
    // } else {
    //     cout << "ROOT NULL" << endl;
    // }

    return 0;
}

// int main()
// {
//     return beginTokenization();
// }
