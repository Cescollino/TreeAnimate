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
		pHead = new Node(&mParameters,1, nullptr);
		//pHead->setPosition(250, 175);
	}
}

/*int Tree::getLevel()
{
	int level{};
	Node* cur;
	cur = pHead;
	while (cur) {
		while (cur->getKids()) {
			level++;
			cur = cur->getKids()->back();
	}
	}
	return level;	
}*/


		
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
	iterateTree(&head);

}

int Tree::wind(int frame)
{
	int offset{};
	offset = 0.5 * sin(5 / 2 * frame) + 0.5 * cos(3 / 2 * (frame - (acos(-1))));
	return 5*offset;
}


void Tree::iterateTree(nInst* start)
{
	nInst* cur = start;
	nInst* kid = nullptr;
	std::ofstream fs;
	fs.open("Tree.sfa", std::ios::app);
	if (fs.is_open())
	{
		while (cur != nullptr)// here's the problem
		{
			kid = cur->node->getKids()->Head();

			while (kid != nullptr)
			{	
				//draw a line between the (N) kid and the parent's position
				fs << "dlin" << " " << cur->node->getPosition().x << " " << cur->node->getPosition().y << " " <<
				kid->node->getPosition().x << " " <<kid->node->getPosition().y << " " << std::endl;

				iterateTree(kid);
				kid = kid->Next;

			}
			cur = cur->Next;
			
		}

		
	}

	fs.close();

}
