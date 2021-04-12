#include "LinkedList.h"

LinkedList::LinkedList()
{
	pHead = nullptr;
}

LinkedList::~LinkedList()
{
	this->deleteAll();
}

//goes to the head and itterates through all the nodes to delete them, once all the kids are done, so it the parent
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

//creates a new node and inserts it into the linked list of kids
bool LinkedList::Insert(nInst node)
{
	nInst * Cur;
	nInst* NewNode = new (std::nothrow) nInst;
	
	*NewNode = node;

	if (NewNode == nullptr) { // case where you attempt to insert nullptr
		return 1;	//1 is bad, indicates error which could be treated different ways
	}

	if (pHead == nullptr) {	// case where there are no nodes in the list	
		pHead = NewNode;
		Cur = pHead;
		Cur->Next = nullptr;
		return 0;			//happy to be a zero
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

nInst* LinkedList::Head()
{
	return pHead;
}


