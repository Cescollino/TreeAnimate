#include "Tree.h"

Tree::Tree(IParam parameters)
{
	mParameters.lenght= parameters.lenght; 
	mParameters.maxBranches = parameters.maxBranches; 
	mParameters.maxLvl = parameters.maxLvl;



	makeinit();
	
	makeTree(parameters);
	
 //13 frames***


}

Tree::~Tree()
{

}

void Tree::makeinit()
{
	std::ofstream outfile("Tree.sfa"); // generates sfa file
	outfile << "MagicTree!" << std::endl;
	outfile.close();

}

void Tree::makeTree(IParam parameters)
{
	makeNode(pHead);
	std::fstream fs;

	fs.open("Tree.sfa", std::fstream::in);
	fs << "my text here!" << std::endl;
	fs.close();
}

void Tree::makeNode(Node* currentNode)
{
	if (currentNode == nullptr) {// for head pointer, initializing tree
	
		currentNode = new Node(&mParameters);

	}else{
		if (currentNode->getlevel() < mParameters.maxLvl) {
			currentNode->setKids(new Node(&mParameters));
		}
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
		
