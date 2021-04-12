

#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream> 
#include <string>
#include "Node.h"
#include <math.h>
#include "Structures.h"



class Tree {
  
public:
    Tree(IParam parameters);
    ~Tree();
    void makeinit();
    void makeTree();
    void makeNode();
    void writeData();
    float wind(int frame);
    void iterateTree(nInst* start, int frame);
    float windAngle(nInst* kid,int frame);
private:
    position init{};
    Node* pHead = nullptr;
    IParam mParameters{};

protected:
};
#endif
