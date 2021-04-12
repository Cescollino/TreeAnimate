// TreeAnimate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Tree.h"

//creates the three using the parameters given by the user, then writes it to the text file
//since we weren't really given limits, we set them to something that makes sense to not go crazy
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
    //cherche le multiple qui sera utilise pour trouver la longueur d'un branche en fonction de la longueur de ses parante 
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
    if (fs.is_open())   {    fs << "END";  }
    fs.close();
    int a{};

}
