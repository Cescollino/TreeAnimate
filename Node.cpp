#include "Node.h"


Node::Node(IParam* parameters, int level, Node* Parent)
{
	if (Parent == nullptr) {
		this->setPosition(250, 175);
	}
	
	int numberofkids{};
	if (parameters->maxBranches == parameters->minBranches) {
	numberofkids = parameters->minBranches;
	}
	else {
	numberofkids = rand() % (parameters->maxBranches - parameters->minBranches) + parameters->minBranches; // generates random number for branches
	}
	this->mLevel = level;
	this->setPrevious(Parent);
	TreeParameters = parameters;
	if (this->getlevel() < parameters->maxLvl) {
		for (int i = 0; i < numberofkids; i++) {
			this->setKids(new Node(parameters, this->getlevel() + 1, this),numberofkids, i+1);// CHECK PARENT NODE POINTER EMPTY 
			
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

void Node::setKids(Node* Kid, int branches, int whichKid)// problem here, always mPrevious==nullptr...
{
	int x{};
	int y{};
	int angle = 180 / (branches+1);

	Kid->setPrevious(this);
	
	if (this->mPrevious != nullptr) {
		int lenght = TreeParameters->length * this->length();
		int parentAngle = this->angle();
		 x = lenght * cos(degToRad((angle*whichKid + parentAngle) + 180)) + mPrevious->mPosition.x;
		 y = lenght * sin(degToRad((angle*whichKid + parentAngle) + 180)) + mPrevious->mPosition.y;
		 int a{};
	}
	else {
		int lenght = initY - mPosition.y;
		 x = lenght * cos(degToRad((angle*whichKid)+180))+250;
		 y = lenght * sin(degToRad((angle*whichKid)+180))+175;

	}

	Kid->setPosition(x,y);	
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
	angle = radToDeg(atan((pos1.y - mPosition.y)/ (pos1.x - mPosition.x)));

	return angle;
}
