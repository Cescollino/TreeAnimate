// TreeAnimate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Tree.h"

int main()
{
    std::cout << "Hello World!\n";
    IParam Parameters{};

    std::string Mbranches{};
    std::cout << "Quel est le nombre maximal de branches que vous désirez?\n";
    std::getline(std::cin, Mbranches);
    Parameters.maxBranches = std::stoi(Mbranches);

    std::string Longueur{};
    std::cout << "Quel est le multiple de longueur de branche que vous désirez?\n";
    std::getline(std::cin, Longueur);
    Parameters.length = std::stof(Longueur);

    std::string NMax{};
    std::cout << "Quel est le niveau maximal de noeuds que vous désirez?\n";
    std::getline(std::cin, NMax);
    Parameters.maxLvl = std::stoi(NMax);

    Tree mytree(Parameters);

    int a{};

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
