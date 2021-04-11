#include "Node.h"


Node::Node(IParam* parameters, int level, Node* Parent, position positionKid)
{
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
	mPosition = positionKid;
	if (this->getlevel() < parameters->maxLvl) {
		for (int i = 0; i < numberofkids; i++) {
			position thisposition = PositionKids(numberofkids, i + 1);
		
			this->setKids(new Node(parameters, this->getlevel() + 1, this,thisposition),numberofkids, i+1); 
			
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

void Node::setKids(Node* Kid, int branches, int whichKid)
{
	

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

position Node::PositionKids(int branches, int whichKid)
{
	int x{};
	int y{};
	float bAngle = 180 / (branches + 1);
	mBranchAngle = bAngle;
	mListSpot = whichKid;
	position myposition;

	if (mLevel > 1 ) {
		myposition= offsetKids(bAngle, whichKid, false);
		
	}
	else {
		int lenght = TreeParameters->length*(initY - mPosition.y);
		myposition.x = lenght * cos(degToRad((bAngle * whichKid) + 180)) + initX;
		myposition.y = lenght * sin(degToRad((bAngle * whichKid) + 180)) + 175;
	}

	return myposition;
}



int Node::length()
{
	position pos1= mPrevious->getPosition();
	int length{};

	length= sqrt( (pos1.x - mPosition.x) * (pos1.x - mPosition.x) + (pos1.y - mPosition.y)* (pos1.y - mPosition.y));

	return length;
}
int Node::angle()
{
	position pos1 = mPrevious->getPosition();
	float angle{};
	
	if (pos1.x != mPosition.x) {
		angle = radToDeg(atan2((pos1.y-mPosition.y), (  pos1.x- mPosition.x)));
		int bla{};
		
	}
	else {
		angle = 90;
	}
	return angle;
}



position Node::offsetKids( int bAngle, int whichKid, float angleOffset)
{
	position newPos{};
	int lenght = TreeParameters->length * length();
	int parentAngle = angle();
	
	newPos.x = lenght * cos(degToRad(90 + parentAngle + radToDeg(angleOffset) +(bAngle * whichKid))) + mPosition.x;//must change offset to fit tree shape
	newPos.y = lenght * sin(degToRad(90 + parentAngle + radToDeg(angleOffset) +(bAngle * whichKid))) + mPosition.y;
	return newPos;
}

int Node::getSpot()
{
	return mListSpot;
}

float Node::getBranchA()
{
	return mBranchAngle;
}

