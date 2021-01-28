//
// Created by markr on 1/7/2021.
//

#ifndef ROLLBACK_TREE_H
#define ROLLBACK_TREE_H

#include "TreeNode.h"
#include <cstddef>   // make gcc & CLion happy
#include <string>
#include <stdexcept>



class Tree {
    typedef TreeNode* NodePtr;


private:
    NodePtr root;
    size_t numPlayers;
    std::vector<PlayerNode> blank;


public:
    //default constructor
    Tree();

    // insert
    // Inserts a node at the given depth for a player
    void insert ();

    // solve
    // prints the final solution to the game
    void solve();

    // print
    // pre: tree exists
    // post: Print all nodes in the tree
    void print() const;

    // nodeCount
    // Returns a count of all the nodes in the Tree structure
    size_t nodeCount() const;
};


#endif //ROLLBACK_TREE_H
