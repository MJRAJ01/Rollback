//
// Created by markr on 1/7/2021.
//

#include "Tree.h"
#include <iostream>
#include <cstddef>   // make gcc & CLion happy
#include <string>
#include <stdexcept>



//default constructor
Tree::Tree() {
    std::string first;
    std::cout<<"How many players?"<<std::endl;
    std::cin>>numPlayers;
    std::vector<PlayerNode> rootPayoffs;
    rootPayoffs.resize(numPlayers);
    for(size_t i = 0; i < rootPayoffs.size(); ++i){
        std::cout<< "Player "<< i + 1<< "'s name?";
        std::cin>>rootPayoffs[i].name;
    }
    std::cout<<"Who is the first player?"<<std::endl;
    std::cin>>first;
    root = new TreeNode(rootPayoffs, first);
}

// insert
// Inserts a node at the given depth for a player
void Tree::insert (){
    std::cout<<"--FIND PATH TO INSERTION SPOT--"<<std::endl;

    std::cout<<"Who is the controlling player at this new node?"<<std::endl;
    std::string name;
    std::cin>>name;
    root->insert(name);
}

// solve
// prints the final solution to the game
void Tree::solve(){
    std::vector<PlayerNode> solution = root->solve();

    std::cout<<"Final payoff:"<<std::endl;
    for(size_t i = 0; i<solution.size(); ++i){
        std::cout<<solution[i].name<<" gets "<< solution[i].reward<<std::endl;
    }
}

// print
// pre: tree exists
// post: Print all nodes in the tree
void Tree::print() const{
    root->print();
}

// nodeCount
// Returns a count of all the nodes in the Tree structure
size_t Tree::nodeCount() const{
    return root->nodeCount();
}