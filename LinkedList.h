#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
#include "Structures.h"
class Node; //prevents circular referencing 
//provides the two main variables of the list, next points to the next kid while node contains all its information
typedef struct _nInst {

	Node* node;
	_nInst* Next;	/* Un pointeur vers le prochain noeud */
} nInst;

// class which creates a very basic linked list that is used for all the kids of each node
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

};

#endif
