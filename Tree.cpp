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
		pHead->setPosition(pHead->getPosition().x + wind(i) / 2, pHead->getPosition().y);
		iterateTree(&head, i);
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

int Tree::wind(int frame)
{
	if (frame!=0)
	{
		float offset{};
		offset = 0.5 * sin(5 / 2 * frame) + 0.5 * cos(3 / 2 * (frame - (acos(-1))));
		return 5 * offset;
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
				
				////////////cur->node->setPosition(cur->node->getPosition().x + cur->node->getlevel() * wind(frame),	cur->node->getPosition().y);
				
				kid->node->setPosition(kid->node->getPosition().x + kid->node->getlevel() * wind(frame),	kid->node->getPosition().y );
								
					//draw a line between the (N) kid and the parent's position
					fs << "dlin" << " " << cur->node->getPosition().x << " " << cur->node->getPosition().y << " " <<
						kid->node->getPosition().x << " " << kid->node->getPosition().y << " " << std::endl;
					

				iterateTree(kid, frame);
				kid = kid->Next;
				
			}
			
		}

	}
	fs.close();

}
