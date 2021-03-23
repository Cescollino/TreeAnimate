#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream> 
#include <string>
#include <list>
#include "Tree.h"
class Tree;// utile juste pour éviter une déclaration récursive
struct IParam;// utile juste pour éviter une déclaration récursive

struct position {
    int x{};
    int y{};
};

class Node {

public:
    Node(IParam* parameters);
    ~Node();
    Node* getPrevious();
    std::list<Node*>* getKids(); 
    void setKids(Node* Kid);
    void setPrevious(Node* Parent);
    int getlevel();
    void setLevel(int level);

private:

    position mPosition{};
    Node* mPrevious=nullptr; // This can only contain one pointer
    std::list<Node*> mKids = {}; // this points to a table of Nodes
    int mLevel{}; // determines the level of the node inside a tree
    IParam* TreeParameters = nullptr; // points to the parameters of the tree

protected:

};
#endif

