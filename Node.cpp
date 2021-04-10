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
		
			this->setKids(new Node(parameters, this->getlevel() + 1, this,thisposition),numberofkids, i+1);// CHECK PARENT NODE POINTER EMPTY 
			
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
	int bAngle = 180 / (branches + 1);

	if (mLevel > 1 ) {
		int lenght = TreeParameters->length * length();
		int parentAngle = angle();

		x = lenght * cos(degToRad(90 + parentAngle+ (bAngle * whichKid))) + mPosition.x;//must change positioning to fit tree shape
		y = lenght * sin(degToRad(90 + parentAngle+ (bAngle * whichKid))) + mPosition.y;
		int a{};
	}
	else {
		int lenght = TreeParameters->length*(initY - mPosition.y);
		x = lenght * cos(degToRad((bAngle * whichKid) + 180)) + 250;
		y = lenght * sin(degToRad((bAngle * whichKid) + 180)) + 175;
	}

	position myposition;
	myposition.x = x;
	myposition.y = y;
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
		angle = radToDeg(atan2((pos1.y - mPosition.y), (pos1.x - mPosition.x)));
		int bla{};
		
	}
	else {
		angle = 90;
	}
	return angle;
}
