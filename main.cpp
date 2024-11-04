#include <iostream>
#include <string>
#include <vector>

#include "tokenizer.hpp"
#include "expressions.hpp"

using namespace std;


int main() {
    cout << "Hello welcome to the language" << endl;

    Expression* expr = new AdditionExpression(
        new NumberExpression(10),
        new ParenthesisExpression(
            new MultiplicationExpression(
                new NumberExpression(9),
                new NumberExpression(8)
            )
        )
    );

    int result = expr->evaluate();
    cout << "Result: 10+(9*8) = " << result << endl;

    free(expr);
    expr = NULL;

    return beginTokenization();
}
