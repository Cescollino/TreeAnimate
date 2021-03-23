

#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream> 
#include <string>
#include "Node.h"


class Node; // utile juste pour éviter une déclaration récursive
struct IParam {
    int maxLvl{};
    int maxBranches{};
    const int minBranches{2};
    float lenght{}; 
};

class Tree {
  
public:
    Tree(IParam parameters);
    ~Tree();
    void makeinit();
    void makeTree(IParam parameters);
    void makeNode(Node* currentNode);
    int getLevel();
private:
    Node* pHead = nullptr;
    IParam mParameters{};
protected:
};
#endif
