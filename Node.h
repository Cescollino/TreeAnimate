#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream> 
#include <string>
#include "Tree.h"

struct position {
    int x{};
    int y{};
};

class Node {

public:
    Node(IParam parameters);
    ~Node();
    Node* getPrevious();
    Node* getKids();
    
private:
    position mPosition{};
    Node* mPrevious=nullptr;
    Node* mKids=nullptr;
    int mLevel{};

protected:

};
#endif

