#include "Tree.h"

Tree::Tree(IParam parameters)
{
	mParameters.length= parameters.length; 
	mParameters.maxBranches = parameters.maxBranches; 
	mParameters.maxLvl = parameters.maxLvl;
	init.x = 250;
	init.y = 250;
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


		fs << "my text here!" << std::endl;
		
	}
	fs.close();
}
