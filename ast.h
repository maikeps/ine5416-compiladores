#pragma once

#include <iostream>

#include <vector>

namespace AST {

//Binary operations
enum Operation { plus, mult };

class Node;

typedef std::vector<Node*> NodeList; //List of ASTs

class Node {
    public:
        virtual ~Node() {}
        virtual void printTree(){}
        virtual int computeTree(){return 0;}
};

class Integer : public Node {
    public:
        int value;
        Integer(int value) : value(value) {  }
        void printTree();
        int computeTree();
};

class Variable : public Node {
	public:
		char* name;
		Node* next;
		Variable(char* name, Node* next) : name(name), next(next) {  }
		void printTree();
		int computeTree();
};

class BinOp : public Node {
    public:
        Operation op;
        Node *left;
        Node *right;
        BinOp(Node *left, Operation op, Node *right) :
            left(left), right(right), op(op) { }
        void printTree();
        int computeTree();
};

class Block : public Node {
    public:
        NodeList lines;
        Block() { }
        void printTree();
        int computeTree();
};

}

