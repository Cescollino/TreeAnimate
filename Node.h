#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream> 
#include <string>
#include <list>
#include "LinkedList.h"
#include "Structures.h"
class Tree;// utile juste pour éviter une déclaration récursive
struct IParam;// utile juste pour éviter une déclaration récursive



class Node {

public:
    Node(IParam* parameters, int level);
    ~Node();
    Node* getPrevious();
    LinkedList* getKids(); 
    void setKids(Node* Kid, int branches);
    void setPrevious(Node* Parent);
    int getlevel();
    void setLevel(int level);
    void setPosition(int x, int y);
    position getPosition();
    int length();
    int angle();

private:

    position mPosition{};
    Node* mPrevious=nullptr; // This can only contain one pointer
    
    
    LinkedList mKids = {}; // this points to a table of Nodes 
                                // ************//to replace
    int mLevel { }; // determines the level of the node inside a tree
    IParam* TreeParameters = nullptr; // points to the parameters of the tree

protected:

};
#endif

