//
// Created by markr on 1/7/2021.
//

#include "TreeNode.h"
#include <cstddef>   // make gcc & CLion happy
#include <string>
#include <stdexcept>
#include <iostream>


//Constructor
// Takes the payoff values, player name and creates a node ready to be linked into tree
TreeNode::TreeNode(std::vector<PlayerNode> payoff, std::string name): payoffs(payoff), player(name)
, up(nullptr), down(nullptr){ }

// insert
// Inserts a node at the given depth for a player
void TreeNode::insert (const std::string& name){
    std::vector<PlayerNode> curr = payoffs;
    int selection, terminal;

    std::cout<<"Current node: "<< player << std::endl;
    std::cout<<"Enter 1 for up and 0 for down"<<std::endl;
    std::cin>>selection;
    if(up == nullptr || down == nullptr){
        std::cout<<"Enter 1 for terminal and 0 for non-terminal"<<std::endl;
        std::cin>>terminal;
    }

    if (selection == 1 && up == nullptr && terminal == 1){
         //make payoffs for new node
         for( size_t i = 0; i < curr.size(); i++){
             std::cout<<curr.at(i).name<< " gets a payoff of?";
             std::cin>>curr.at(i).reward;
         }
        up = new TreeNode(curr,name);
    } else if (selection == 0 && down == nullptr && terminal == 1){
         for( size_t i = 0; i < curr.size(); i++){
             std::cout<<curr.at(i).name<< "gets a payoff of?";
             std::cin>>curr.at(i).reward;
         }
         down = new TreeNode(curr,name);
     } else if (selection == 0 && down == nullptr){
        down = new TreeNode(curr,name);
    } else if (selection == 1 && up == nullptr) {
        up = new TreeNode(curr,name);
    } else if( selection == 1) {
        up->insert(name);
    } else if (selection == 0){
        down->insert(name);
    }
}

// solve
// pre: tree exists
// post: Solves the tree using rollback
std::vector<PlayerNode> TreeNode::solve(){
    //no options
    if(up == nullptr && down == nullptr) {
        return payoffs;
    }

    //only one option
    if(up == nullptr && down != nullptr){
        return down->solve();
    }
    if(down == nullptr && up != nullptr){
        return up->solve();
    }

    std::vector<PlayerNode> final, upMax, downMax;

    if (up != nullptr){
        upMax = up->solve();
    }
    if (down != nullptr){
       downMax = down->solve();
    }

    for(size_t i = 0; i< upMax.size(); ++i){
        if(player == upMax[i].name){
            if(upMax[i].reward > downMax[i].reward){
                final =upMax;
            } else{
                final = downMax;
            }
        }
    }

    return final;
}

// print
// pre: tree exists
// post: Print all nodes in the tree
void TreeNode::print() const{
    if(player != "root"){
        std::cout<<"Player: " + player;
        if (up != nullptr){
            std::cout<<"Up: ";
            up->print();
        }
        if(down != nullptr){
            std::cout<<"Down: ";
            down->print();
        }
        std::cout<<std::endl;
    }
}

// nodeCount
// Returns a count of all the nodes in the Tree structure
size_t TreeNode::nodeCount() const{
    size_t sum(0);

    if (up != nullptr){
        sum += up->nodeCount();
    }
    if(down != nullptr){
        sum += down->nodeCount();
    }
    if(player == "root"){
        return sum;
    } else{
        return 1+sum;
    }
}