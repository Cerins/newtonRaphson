#ifndef AST_H
#define AST_H


#include "Token.h"
#include <string>
#include <memory>
#include <iostream>


class AbstractVisitor;
class Context;


class Node{
    public:
        virtual void accept(AbstractVisitor& v, Context* context) = 0;
        virtual ~Node(){};
};

class BinOp;
class UnaryOp;
class Num;
class VarAsign;
class VarAccess;

class AbstractVisitor{
    public:
        virtual void visit(BinOp& node, Context* context) = 0;
        virtual void visit(Num& node, Context* context) = 0;
        virtual void visit(UnaryOp& node, Context* context) = 0;

        virtual void visit(VarAsign& node, Context* context) = 0;
        virtual void visit(VarAccess& node, Context* context) = 0;

};

class BinOp: public Node{
    public:
        Token* token = nullptr;
        Node* right = nullptr;
        Node* left = nullptr;
        void accept(AbstractVisitor& v, Context* context) override {
            v.visit(*this, context);
        }
        BinOp(Node* left, Token* tok, Node* right){
            this->left = left;
            this->token = tok;
            this->right = right;
        }
        virtual ~BinOp() override{
            delete right;
            delete left;
            //delete token;
        }


};

class Num: public Node{
    public:
        Token* token = nullptr;
        void accept(AbstractVisitor& v, Context* context) override{
            v.visit(*this, context);
        }
        Num(Token* tok){
            this->token = tok;
        }
        virtual ~Num() override{
            //delete token;
        }


};

class UnaryOp: public Node{
    public:
        Token* token = nullptr;
        Node* child = nullptr;
        void accept(AbstractVisitor& v, Context* context) override {
            v.visit(*this, context);
        }

        UnaryOp(Node* child, Token* op){
            this->child = child;
            this->token = op;
        }
        virtual ~UnaryOp() override{
            delete child;
            //delete token;

        }
};


class VarAsign: public Node{
    public:
        Token* token;
        Node* value;
        void accept(AbstractVisitor& v, Context* context) override {
            v.visit(*this, context);
        }

        VarAsign(Token* token, Node* value){
            this->token = token;
            this->value = value;
        }
        virtual ~VarAsign() override{
            delete value;
        }
};

class VarAccess: public Node{
    public:
        Token* token;
        void accept(AbstractVisitor& v, Context* context) override {
            v.visit(*this, context);
        }

        VarAccess(Token* token){
            this->token = token;
        }
        virtual ~VarAccess() override{
            delete token;
        }
};


#endif // AST_H
