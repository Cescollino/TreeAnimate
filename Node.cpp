#include "Node.h"

Node::Node(IParam* parameters)
{
	TreeParameters = parameters;
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

void Node::setKids(Node* Kid, int level)
{
	
	mKids = new Node[5];

}

void Node::setPrevious(Node* Parent)
{
	mPrevious = Parent;
}
