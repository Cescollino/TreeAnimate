#include "Node.h"

Node::Node(IParam* parameters)
{
	int numberofkids = rand() % (parameters->maxBranches - parameters->minBranches) + parameters->minBranches; // generates random number for branches

	if (this->getlevel() < parameters->maxLvl) {
	for (int i = 0; i < numberofkids; i++) {
		this->setKids(new Node(TreeParameters));
		}

	}
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
	Kid->setLevel(this->getlevel() + 1);
//	mKids.back()->setLevel(Kid->getPrevious()->getlevel() + 1);
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
