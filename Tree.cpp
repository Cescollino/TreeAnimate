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
	outfile << "Media_SetBrushColor(SetParam(&Param, 3, 255, 255, 255, 0, 0, 0, 0, 0, NULL));" << std::endl;
	outfile << "Media_SetPenColor(SetParam(&Param, 3, 0, 0, 0, 0, 0, 0, 0, 0, NULL));" << std::endl;
	outfile << "Media_Clear(SetParam(&Param, 3, 255, 255, 255, 0, 0, 0, 0, 0, NULL));" << std::endl;
	
	outfile.close();

}

void Tree::makeTree()
{
	makeNode();	
	
}

void Tree::makeNode()
{
	if (pHead == nullptr) {// for head pointer, initializing tree
		pHead = new Node(&mParameters,1);
		pHead->setPosition(250, 175);
	}
}

int Tree::getLevel()
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
}

int Tree::wind(int frame)
{
	int offset{};
	offset = 0.5 * sin(5 / 2 * frame) + 0.5 * cos(3 / 2 * (frame - (acos(-1))));
	return 5*offset;
}


// to finish once we got a list
// to finish once we got a list
// to finish once we got a list
// to finish once we got a list
// to finish once we got a list
// to finish once we got a list
// to finish once we got a list
// to finish once we got a list
// to finish once we got a list
void Tree::itterateTree(Node start)
{
	Node cur = start;
	while (cur.getKids() != nullptr)
	{
		//std::list a= cur.getKids();
		//itterateTree(cur.getKids()->front() );
		//itterateTree(cur.getKids()->front());
	}

	std::ofstream fs;
	fs.open("Tree.sfa", std::ios::app);
	if (fs.is_open())
	{
		//draw a line between the current position and the parent's position
		fs << "dlin" << " " << cur.getPosition().x << " " << cur.getPosition().y << " " << 
			cur.getPrevious()->getPosition().x << " " << cur.getPrevious()->getPosition().y << " " << std::endl;
	}
	fs.close();

}
