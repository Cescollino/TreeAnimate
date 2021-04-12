#include "Tree.h"

//saves the parameters inputed by the user and then writes the initialisation parameters to file
Tree::Tree(IParam parameters)
{
	mParameters.length= parameters.length; 
	mParameters.maxBranches = parameters.maxBranches; 
	mParameters.maxLvl = parameters.maxLvl;
	init.x = initX;
	init.y = initY;
	makeinit();
	makeTree();   //then creates it all

 


}

Tree::~Tree()//linked list deletes the kids and the parent, so it'll take care of it
{

}

//writes the initialisation parameters to file
void Tree::makeinit()
{
	std::ofstream outfile("Tree.sfa"); // generates sfa file
	outfile << "Sto and Mario's tree" << std::endl;
	outfile << "INIT" << std::endl;
	outfile << "eras 255 255 255" << std::endl;
	
	outfile.close();

}

void Tree::makeTree()//could have had more, but we kept it simple
{
	makeNode();	
	
}

void Tree::makeNode()
{
	if (pHead == nullptr) { // for head pointer, initializing tree
			position headPosition;
			headPosition.x = 250;		//
			headPosition.y = 175;

		pHead = new Node(&mParameters,1, nullptr,headPosition);  //will call itself recursively to create all the nodes
		
	}
}



// itterates through the tree and writes the lines to file 		
void Tree :: writeData()
{
	//draws the trunk
	std::ofstream fs;  
	fs.open("Tree.sfa", std::ios::app);
	if (fs.is_open())
	{
		fs << "FRAME" << std::endl;
		fs << "dlin" << " " <<init.x <<" " << init.y << " " <<pHead->getPosition().x << " " << pHead->getPosition().y << " " << std::endl;
	}
	fs.close();
	nInst head;
	head.node = pHead;
	head.Next = nullptr;

	for (int i{}; i < 14; i++)//goes one extra frame to go back to the original position
	{	//sets up the tree trunk and the branches will be taken care of in the iterateTree
		float newAngle = asin((0.5*wind(i)) / (init.y-pHead->getPosition().y));
		float newX = (init.y - pHead->getPosition().y) * sin(newAngle);
		float newY = (init.y - pHead->getPosition().y) * cos(newAngle);
		pHead->setPosition(pHead->getPosition().x + newX, pHead->getPosition().y+ ((init.y - pHead->getPosition().y) - newY));
		iterateTree(&head, i);  //recursive function which will go through all the three
		//stuff to be written after each frame
		std::ofstream fs;
		fs.open("Tree.sfa", std::ios::app);
		if (fs.is_open())
		{
			fs << "wait 500" << std::endl;
			fs << "eras 255 255 255." << std::endl;
			fs << "FRAME" << std::endl;
			fs.close();
		}
	}
	

}

//13 frames to complete the whole wind function
float Tree::wind(int frame)
{
	if (frame!=0)
	{
		float offset{};
		offset = 0.5 * sin(5 / 2 * frame) + 0.5 * cos(3 / 2 * (frame - (acos(-1))));
		return 15 * offset;
	}
	else { return 0; }
	
}

//recursive function which will write the branches into the file, then redo it every frame depending on wind strangth
void Tree::iterateTree(nInst* start, int frame)
{
	nInst* cur = start;
	nInst* kid = nullptr;

	std::ofstream fs;
	fs.open("Tree.sfa", std::ios::app);
	if (fs.is_open()) //makes sure file is open
	{
		if (cur != nullptr) //goes through all the nodes
		{
			kid = cur->node->getKids()->Head(); 
			
			//draws the initial line, so bottom to pHead
			fs << "dlin" << " " << init.x << " " << init.y << " " << pHead->getPosition().x << " " << pHead->getPosition().y << " " << std::endl;
			fs << "cpen"<< "150 220 92" << std::endl;
			//draws the progress bar
			fs << "drec" << " " << 100 <<" " << 260 << " " << 400 << " " << 270 << std::endl; 
			fs << "cpen" << "0 0 0" << std::endl;

			//goes through all the kids
			while (kid != nullptr)
			{
				if (frame < 1) { //draws the rectangle and the trunk
					fs << "dlin" << " " << cur->node->getPosition().x << " " << cur->node->getPosition().y << " " <<
						kid->node->getPosition().x << " " << kid->node->getPosition().y << " " << std::endl;
					fs << "drec" << " " << 100 << " " << 255 << " " << 105 << " " << 260 << std::endl;
				}
				else {// sets new positions and then draws them after the wind
					float realAngle = kid->node->angle();
					float realX = abs(cos(degToRad(realAngle)) * kid->node->length());// gets us the length of x value before being affected by the wind
						
					realAngle = realAngle + windAngle(kid,frame);// deltaAngle;
										
					//calculates and sets the new position
					int kidx = kid->node->getPrevious()->getPosition().x - kid->node->length() * cos(degToRad(realAngle));
					int kidy = kid->node->getPrevious()->getPosition().y - kid->node->length() * sin(degToRad(realAngle));
					kid->node->setPosition(kidx, kidy);

					//draws the new branches  in the text file			
						fs << "dlin" << " " << cur->node->getPosition().x << " " << cur->node->getPosition().y << " " <<
						kid->node->getPosition().x << " " << kid->node->getPosition().y << " " << std::endl;
						fs << "drec" << " " << 100+22*frame << " " << 250 - wind(frame) << " " << 105+ 22*frame << " " << 265 << std::endl;
				}
					iterateTree(kid, frame); //goes through all the kids of the kids of the kids of the kids of the kids of the kids
					kid = kid->Next;
			}
			
		}

	}
	fs.close();

}

//wind angle will generate the offset caused by the wind depending on the quadrant in which the branch is situated
float Tree::windAngle(nInst* kid,int frame)
{
	float realAngle = kid->node->angle();	//gets the original angle of the branch before wind
	if (realAngle < 0) { realAngle = 360 + realAngle; }	//fixes the negatives
	float realX = abs(cos(degToRad(realAngle)) * kid->node->length());// gets us the length of x value before being affected by the wind
	float topacos{};
	float botacos{};
	
	//inverts the wind depending on the quadrant
	if (realAngle > 90 && realAngle <= 180 || realAngle > 270 && realAngle < 360) { 
		topacos = (realX - wind(frame));
	}
	else
	{topacos = wind(frame) + realX;
	}
	botacos = kid->node->length(); //hypotenuse 

	if (topacos > botacos) {// ensures that hypotenuse is always bigger than one of the cathetes
		topacos = botacos;
	};
	

	float newAngleRAD = acos((topacos / botacos)); //new angle after the offset caused by the wind
	newAngleRAD = newAngleRAD + (newAngleRAD*.001* kid->node->getlevel()); //wind is stronger depending on level, altough scaled to non-tornado levels
	float newAngle = radToDeg(newAngleRAD);
	float deltaAngle{};

	//angles resolved depending on the quadrant to make them all start from the same 0
	if (realAngle > 90 && realAngle < 180) {
		newAngle = 180 - newAngle;
		deltaAngle = realAngle - newAngle;
	}else if (realAngle > 180 && realAngle < 270) {
		newAngle = 270 - newAngle;
		deltaAngle = realAngle - newAngle;
	}else if (realAngle > 270 && realAngle < 360) {
		newAngle = 360 - newAngle;
		deltaAngle = realAngle - newAngle;
	}else {
		deltaAngle = realAngle - newAngle;
	}
	return deltaAngle;
}
