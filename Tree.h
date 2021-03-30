

#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream> 
#include <string>
#include "Node.h"
#include <math.h>
#include "Structures.h"

//class Node; // utile juste pour éviter une déclaration récursive


class Tree {
  
public:
    Tree(IParam parameters);
    ~Tree();
    void makeinit();
    void makeTree();
    void makeNode();
    int getLevel();
    
private:
    position init{};
    Node* pHead = nullptr;
    IParam mParameters{};

protected:
};
#endif
