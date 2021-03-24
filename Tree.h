

#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream> 
#include <string>
#include "Node.h"
#include <math.h>


class Node; // utile juste pour éviter une déclaration récursive
struct IParam {
    int maxLvl{};
    int maxBranches{};
    const int minBranches{2};
    float length{}; 
};

class Tree {
  
public:
    Tree(IParam parameters);
    ~Tree();
    void makeinit();
    void makeTree();
    void makeNode();
    int getLevel();
private:
    Node* pHead = nullptr;
    IParam mParameters{};
protected:
};
#endif
