#include "Node.h"


Node::Node(IParam* parameters, int level)
{
	int numberofkids = rand() % (parameters->maxBranches - parameters->minBranches) + parameters->minBranches; // generates random number for branches
	this->mLevel = level;
	if (this->getlevel() < parameters->maxLvl) {
		for (int i = 0; i < numberofkids; i++) {
			this->setKids(new Node(parameters, this->getlevel() + 1),numberofkids);
			
		}

	}
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

LinkedList* Node::getKids()
{
	return &mKids;
}

void Node::setKids(Node* Kid, int branches)
{
	int x{};
	int y{}; 
	int angle = 90 / (branches + 1);
	if (this->mPrevious != nullptr) {
		int lenght = TreeParameters->length * this->length();
		int parentAngle = this->angle();
		 x = lenght * sin(angle + parentAngle);
		 y = lenght * cos(angle + parentAngle);
	}
	else {
		int lenght = initY - mPosition.y;
		 x = lenght * sin(angle);
		 y = lenght * cos(angle);
	}
	Kid->setPosition(x,y);
	Kid->setPrevious(this);
	nInst AKid;
	AKid.node = Kid;
	mKids.Insert(AKid);
	Kid->setLevel(this->getlevel() + 1);

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

void Node::setPosition(int x, int y)
{
  mPosition.x=x;
  mPosition.y=y;
}

position Node::getPosition()
{
	return mPosition;
}



int Node::length()
{
	position pos1= mPrevious->getPosition();
	int length{};
	length=sqrt( (pos1.x - mPosition.x)^2 + (pos1.y-mPosition.y)^2);

	return length;
}
int Node::angle()
{
	position pos1 = mPrevious->getPosition();
	int angle{};
	angle = atan((pos1.x - mPosition.x) / (pos1.y - mPosition.y));

	return angle;
}
