#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream> 
#include <string>
#include "LinkedList.h"
#include "Structures.h"
class Tree;// utile juste pour �viter une d�claration r�cursive
struct IParam;// utile juste pour �viter une d�claration r�cursive



class Node {

public:
    Node(IParam* parameters, int level, Node* Parent, position positionKid);
    ~Node();
    Node* getPrevious();
    LinkedList* getKids(); 
    void setKids(Node* Kid, int branches, int whichKid);
    void setPrevious(Node* Parent);
    int getlevel();
    void setLevel(int level);
    void setPosition(int x, int y);
    position getPosition();
    position PositionKids(int branches,int whichKid);
    int length();
    int angle();

private:

    position mPosition{};
    Node* mPrevious=nullptr; // This can only contain one pointer
    int mLength{};
    LinkedList mKids = {}; // this points to a table of Nodes 
    float mAngle{};
    int mLevel {}; // determines the level of the node inside a tree
    IParam* TreeParameters = nullptr; // points to the parameters of the tree

protected:

};
#endif

