#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
#include "Structures.h"
class Node;
typedef struct _nInst {

	Node* node;
	_nInst* Next;	/* Un pointeur vers le prochain noeud */
} nInst;

class LinkedList
{

public:
	LinkedList();
	~LinkedList();
	void deleteAll();
	bool Insert(nInst node);// appends a node to the end of the list
	nInst* Head();

private:
	nInst* pHead;
protected:
};

#endif
