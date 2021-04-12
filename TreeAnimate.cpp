// TreeAnimate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Tree.h"

int main()
{
    IParam Parameters{};

    //cherche le maximum de branche de l'usager
    std::string Mbranches{};
    std::cout << "Quel est le nombre maximal de branches que vous désirez?\n";
    std::getline(std::cin, Mbranches);
    while (std::stoi(Mbranches) < 2 || std::stoi(Mbranches) > 10) {
        std::cout << "Faites attention, votre chiffre est hors de la plage acceptable. (2 - 10)" << std::endl;
        std::cout << "Quel est le nombre maximal de branches que vous désirez?\n";
        std::getline(std::cin, Mbranches);
    };
    Parameters.maxBranches = std::stoi(Mbranches);
    //cherche le multiple qui sera utilise pour trouver la longueur d'un branche 
    std::string Longueur{};
    std::cout << "Quel est le multiple de longueur de branche que vous désirez?\n";
    std::getline(std::cin, Longueur);

    while (std::stof(Longueur) < 0.6 || std::stof(Longueur) > 1) {
        std::cout << "Faites attention, votre chiffre est hors de la plage acceptable. (0.6 - 1)" << std::endl;
        std::cout << "Quel est le nombre maximal de branches que vous désirez?\n";
        std::getline(std::cin, Longueur);
    };
    Parameters.length =std::stof(Longueur);

    std::string NMax{};
    std::cout << "Quel est le niveau maximal de noeuds que vous désirez?\n";
    std::getline(std::cin, NMax);

    while (std::stoi(NMax) < 2 || std::stoi(NMax) > 7) {
        std::cout << "Faites attention, votre chiffre est hors de la plage acceptable.(2-7)" << std::endl;
        std::cout << "Quel est le nombre maximal de branches que vous désirez?\n";
        std::getline(std::cin, NMax);
    };

    Parameters.maxLvl =std::stoi(NMax);

    Tree mytree(Parameters);
    mytree.writeData();
    std::ofstream fs;
    fs.open("Tree.sfa", std::ios::app);
    if (fs.is_open())
    {
        
        fs << "END";
      
    }
    fs.close();
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
