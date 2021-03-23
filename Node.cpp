#include "Node.h"

Node::Node(IParam* parameters)
{
	TreeParameters = parameters;
}

Node::~Node()
{
	for (auto x : mKids){
		delete x;
	}
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

std::list<Node*>* Node::getKids()
{
	return &mKids;
}

void Node::setKids(Node* Kid)
{
	mKids.insert(mKids.end(), Kid);
	mKids.back()->setLevel(Kid->getPrevious()->getlevel() + 1);
}

void Node::setPrevious(Node* Parent)
{
	mPrevious = Parent;
}

int Node::getlevel()
{
	return mLevel;
}

void Node::setLevel(int level)
{
	mLevel = level;
}
