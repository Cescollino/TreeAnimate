#include "Node.h"

//recursive function which creates all the kids of the kids of the kids once started
//it randomizez the number of branches depensing on the user input
Node::Node(IParam* parameters, int level, Node* Parent, position positionKid)
{
	int numberofkids{};


	if (parameters->maxBranches == parameters->minBranches) {
	numberofkids = parameters->minBranches;
	}
	else {
	numberofkids = rand() % (parameters->maxBranches - parameters->minBranches) + parameters->minBranches; // generates random number for branches
	}
	this->mLevel = level;			//makes sure to save its level
	this->setPrevious(Parent);		//and its parent so it can go back later

	TreeParameters = parameters;	//and a pointer to the parameters given by the users to the kids can make kids
	mPosition = positionKid;		//sets its position to what it has recieved from the parent
	if (mPrevious != nullptr) {
		angle();					//calculates the angle of the branch and saves it in mAngle, every other time that "angle()" is called, that value will be returned instead of recalculating
		length();					//calculates the length of the branch and saves it in mAngle, every other time that "length()" is called, that value will be returned
	}
	if (this->getlevel() < parameters->maxLvl ) {	//max level set by user and bigger or equal than 3
		for (int i = 0; i < numberofkids; i++) {				//goes through all the kids
			position thisposition = PositionKids(numberofkids, i + 1); //will calculate the position of the kid with the offset depending on the ammount
			this->setKids(new Node(parameters, this->getlevel() + 1, this,thisposition),numberofkids, i+1);
		}
	}
}

Node::~Node() //doesn't need much since the linked list will empty itself and its kids
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

void Node::setKids(Node* Kid, int branches, int whichKid)		// creates the kid and inserts it in the linked list of kids
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

//takes care of all the calculations required to position kids in function of the parent's position and the ammount of kids
position Node::PositionKids(int branches, int whichKid)
{
	int x{};
	int y{};
	int bAngle = 180 / (branches + 1); 

	if (mLevel > 1 ) {
		int lenght = TreeParameters->length * length();		//recieves mLength, doesn't recalculate
		int parentAngle = angle();							//recieves mAngle, doesn't recalculate

		x = lenght * cos(degToRad(90 + parentAngle+ (bAngle * whichKid))) + mPosition.x; //must change positioning to fit tree shape
		y = lenght * sin(degToRad(90 + parentAngle+ (bAngle * whichKid))) + mPosition.y;
		int a{};
	}
	else {
		int lenght = TreeParameters->length*(initY - mPosition.y);	 //only used for the head since it's straight	
		x = lenght * cos(degToRad((bAngle * whichKid) + 180)) + 250; //offset thanks to pHead
		y = lenght * sin(degToRad((bAngle * whichKid) + 180)) + 175; //offset thanks to pHead
	}

	position myposition; //excellent for troubleshooting
	myposition.x = x;
	myposition.y = y;
	return myposition;
}


//compares the curent node position to its parent to find its length
//first time it's run, it calculates it, then it simply returns the same value since it shouldn't vary regardless of wind
int Node::length()
{
	if (mLength == 0) {

		position pos1 = mPrevious->getPosition();
		int length{};

		length = sqrt((pos1.x - mPosition.x) * (pos1.x - mPosition.x) + (pos1.y - mPosition.y) * (pos1.y - mPosition.y));
		mLength = length;
	
		return length;

	}
	else
	{
		return mLength;
	}


}

//compares the curent node position to its parent to find its angle
//first time it's run, it calculates it, then it simply returns the same value 
int Node::angle()
{
	float angle{};
	if (mAngle == 0) {
	position pos1 = mPrevious->getPosition();

	if (pos1.x != mPosition.x) {
		angle = radToDeg(atan2((pos1.y - mPosition.y), (pos1.x - mPosition.x)));

	}
	else {
		if (pos1.y > mPosition.y) {
			angle = 90;
		}
		else {
			angle = 270;
		}
	}
	mAngle = angle;
	
	}
	return mAngle;

}
