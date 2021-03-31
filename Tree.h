

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
    int getLevel();
    void writeData();
    int wind(int frame);
    void itterateTree(Node start);
private:
    position init{};
    Node* pHead = nullptr;
    IParam mParameters{};

protected:
};
#endif
