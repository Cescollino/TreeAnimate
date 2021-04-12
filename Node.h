#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream> 
#include <string>
#include "LinkedList.h"
#include "Structures.h"
class Tree;// utile juste pour éviter une déclaration récursive
struct IParam;// utile juste pour éviter une déclaration récursive


//class which contains all the information related to each node
//each node has its own parameters, then it gets a linked list of nodes called kids

class Node {

public:
    Node(IParam* parameters, int level, Node* Parent, position positionKid);
    ~Node();
    Node* getPrevious();  //finds the parent of the current node
    LinkedList* getKids(); //finds the kids of the current node and returns it as a linked list
    void setKids(Node* Kid, int branches, int whichKid);    //very important, used to set all the poisition information of all the kids, used when the tree is first created
    void setPrevious(Node* Parent); //since we need to tell each kid what its parent is
    int getlevel(); //basic getter
    void setLevel(int level);
    void setPosition(int x, int y);
    position getPosition();
    position PositionKids(int branches,int whichKid);
    int length();
    int angle();

private:

    position mPosition{};
    Node* mPrevious=nullptr; // This can only contain one pointer to its parent
    int mLength{};          //very useful later, set once and then reused every movement
    LinkedList mKids = {};  // this points to a table of Nodes 
    float mAngle{};         //very useful later, set once and then reused every movement
    int mLevel {};          // determines the level of the node inside a tree
    IParam* TreeParameters = nullptr; // points to the parameters of the tree (all the same that were originally set by the user)


};
#endif

