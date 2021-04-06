#include "LinkedList.h"

LinkedList::LinkedList()
{
	pHead = nullptr;
}

LinkedList::~LinkedList()
{
	this->deleteAll();
}

void LinkedList::deleteAll()
{
		nInst* tempnode;

		while (pHead != nullptr) {
			tempnode = pHead;
			pHead = (pHead)->Next;
			if (tempnode != nullptr) { delete(tempnode); }	
		}
		
		if (pHead != nullptr) { pHead = nullptr; }
}

bool LinkedList::Insert(nInst node)
{
	nInst * Cur;
	nInst* NewNode = new (std::nothrow) nInst;
	
	*NewNode = node;

	if (NewNode == nullptr) { // case where you attempt to insert nullptr
		return 1;
	}

	if (pHead == nullptr) {	// case where there are no nodes in the list	
		pHead = NewNode;
		Cur = pHead;
		Cur->Next = nullptr;
		return 0;
		} 
	else
	{
		Cur = pHead;      // case where there is already a node in the list 
		while (Cur->Next != nullptr) {
		Cur = Cur->Next;
		}

		Cur->Next = NewNode;
		Cur->Next->Next = nullptr;
	}
	return 0;
}


