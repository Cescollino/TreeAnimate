

#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream> 
#include <string>
#include "Node.h"
#include <math.h>
#include "Structures.h"

//class which contains the whole three with its kids and all the pointers to the lower leve

class Tree {
  
public:
    Tree(IParam parameters);
    ~Tree();
    void makeinit();    //creates the original setup
    void makeTree();    //builds the whole three
    void makeNode();
    void writeData();
    float wind(int frame);//uses the provided function to calculate the x offset caused by the wind
    void iterateTree(nInst* start, int frame);// goes through the whole tree to draw and move according to the wind
    float windAngle(nInst* kid,int frame);    
private:
    position init{}; //initial position
    Node* pHead = nullptr;  //start of the three, contains the node which points to all its kids
    IParam mParameters{};   //baic parameters set by the user


};
#endif
