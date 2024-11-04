#include <iostream>
#include <string>

#ifndef EXPRESSIONS_HPP_
#define EXPRESSIONS_HPP_

class Expression {
    public:
        virtual ~Expression() {}
        virtual int evaluate() = 0;
};

class NumberExpression : public Expression {
    public:
        NumberExpression(int value) : value(value) {}
        int evaluate() override { return value; }

    private:
        int value;
};

class AdditionExpression : public Expression {
    public:
        AdditionExpression(Expression* left, Expression* right) : left(left), right(right) {}
        int evaluate() override { return left->evaluate() + right->evaluate(); }

    private:
        Expression* left;
        Expression* right;
};

class SubtractionExpression : public Expression {
    public:
        SubtractionExpression(Expression* left, Expression* right) : left(left), right(right) {}
        int evaluate() override { return left->evaluate() - right->evaluate(); }

    private:
        Expression* left;
        Expression* right;
};

class MultiplicationExpression : public Expression {
    public:
        MultiplicationExpression(Expression* left, Expression* right) : left(left), right(right) {}
        int evaluate() override { return left->evaluate() * right->evaluate(); }

    private:
        Expression* left;
        Expression* right;
};

class DivisionExpression : public Expression {
    public:
        DivisionExpression(Expression* left, Expression* right) : left(left), right(right) {}
        int evaluate() override { return left->evaluate() / right->evaluate(); }

    private:
        Expression* left;
        Expression* right;
};

class ParenthesisExpression : public Expression {
    public:
        ParenthesisExpression(Expression* expr) : expr(expr) {}
        int evaluate() override { return expr->evaluate(); }

    private:
        Expression* expr;
};

#endif
