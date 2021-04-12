#include "Tree.h"

Tree::Tree(IParam parameters)
{
	mParameters.length= parameters.length; 
	mParameters.maxBranches = parameters.maxBranches; 
	mParameters.maxLvl = parameters.maxLvl;
	init.x = initX;
	init.y = initY;
	makeinit();
	makeTree();

 //13 frames***


}

Tree::~Tree()
{

}

void Tree::makeinit()
{
	std::ofstream outfile("Tree.sfa"); // generates sfa file
	outfile << "Sto and Mario's tree" << std::endl;
	outfile << "INIT" << std::endl;
	outfile << "eras 255 255 255" << std::endl;
	
	outfile.close();

}

void Tree::makeTree()
{
	makeNode();	
	
}

void Tree::makeNode()
{
	if (pHead == nullptr) {// for head pointer, initializing tree
			position headPosition;
			headPosition.x = 250;
			headPosition.y = 175;

		pHead = new Node(&mParameters,1, nullptr,headPosition);
		//pHead->setPosition(250, 175);
	}
}



		
void Tree :: writeData()
{
	
	//std::fstream fs; 
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
	for (int i{}; i < 13; i++)
	{
		float newAngle = asin((0.5*wind(i)) / (init.y-pHead->getPosition().y));
		float newX = (init.y - pHead->getPosition().y) * sin(newAngle);
		float newY = (init.y - pHead->getPosition().y) * cos(newAngle);
		pHead->setPosition(pHead->getPosition().x + newX, pHead->getPosition().y+ ((init.y - pHead->getPosition().y) - newY));
		iterateTree(&head, i);
		//stuff to be written after each frame
		std::ofstream fs;
		fs.open("Tree.sfa", std::ios::app);
		if (fs.is_open())
		{
			fs << "wait 2000" << std::endl;
			fs << "eras 255 255 255." << std::endl;
			fs << "FRAME" << std::endl;
			fs.close();
		}
	}
	

}

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


void Tree::iterateTree(nInst* start, int frame)
{
	nInst* cur = start;
	nInst* kid = nullptr;
	std::ofstream fs;
	fs.open("Tree.sfa", std::ios::app);
	if (fs.is_open())
	{
		if (cur != nullptr)
		{
			kid = cur->node->getKids()->Head();
			
			//draws the initial line, so bottom to pHead
			fs << "dlin" << " " << init.x << " " << init.y << " " << pHead->getPosition().x << " " << pHead->getPosition().y << " " << std::endl;
			while (kid != nullptr)
			{
				if (frame < 1) {
					fs << "dlin" << " " << cur->node->getPosition().x << " " << cur->node->getPosition().y << " " <<
						kid->node->getPosition().x << " " << kid->node->getPosition().y << " " << std::endl;
				}
				else {
					int realAngle = kid->node->angle();
					int realX = abs(cos(degToRad(realAngle)) * kid->node->length());// gets us the length of x value before being affected by the wind
					float topacos{};
						float botacos{};
					if (realAngle > 90) {
					topacos = (realX-wind(frame));
					botacos = kid->node->length();
					}
					else {
					topacos = (wind(frame) + realX);
					botacos = kid->node->length();
					}
					if (topacos > botacos) {// ensures that hypotenuse is always bigger than one of the cathetes
						topacos = botacos;
					};
					float newAngleRAD = acos((topacos / botacos));
					//newAngleRAD = newAngleRAD + (newAngleRAD*.1* kid->node->getlevel());
					float newAngle = radToDeg(newAngleRAD);
					float deltaAngle{};
					if (realAngle > 90) {
						newAngle =  180-newAngle;
						deltaAngle = realAngle - newAngle;
					}
					else if (realAngle > 180) {
						newAngle = 270-newAngle;
						deltaAngle = realAngle - newAngle;
					}
					else if (realAngle<0) {
						newAngle = 360 + newAngle;
						deltaAngle = realAngle - newAngle;
					}
					else{
							//newAngle = 90 + newAngle;
							deltaAngle = realAngle - newAngle;
					}
				//	float deltaAngle = realAngle - newAngle;
					
					realAngle = realAngle + deltaAngle;
										

					int kidx = kid->node->getPrevious()->getPosition().x - kid->node->length() * cos(degToRad(realAngle));
					int kidy = kid->node->getPrevious()->getPosition().y - kid->node->length() * sin(degToRad(realAngle));
					kid->node->setPosition(kidx, kidy);
					//std::cout << kid->node->getPosition().x << "\t";
					//std::cout << kid->node->getPosition().y << "\n";
					//  draw a line between the (N) kid and the parent's position

					
						fs << "dlin" << " " << cur->node->getPosition().x << " " << cur->node->getPosition().y << " " <<
						kid->node->getPosition().x << " " << kid->node->getPosition().y << " " << std::endl;

				}
			
					iterateTree(kid, frame);
					kid = kid->Next;
				}
			
		}

	}
	fs.close();

}
