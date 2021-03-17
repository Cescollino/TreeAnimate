#include "Node.h"

Node::Node(IParam parameters)
{
	
}

Node::~Node()
{
}

Node* Node::getPrevious()
{
	if (mPrevious) {
		return mPrevious;
	}
	else {
		return nullptr;
	
	}
}

Node* Node::getKids()
{
	if (mKids) {
		return mKids;
	}
	else {
		return nullptr;

	}
}
