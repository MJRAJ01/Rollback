//
// Created by markr on 1/7/2021.
//

#ifndef ROLLBACK_TREENODE_H
#define ROLLBACK_TREENODE_H

#include <cstddef>   // make gcc & CLion happy
#include <string>
#include <stdexcept>
#include <vector>
struct PlayerNode{
    std::string name;
    size_t reward;
};
class TreeNode {
    typedef TreeNode* NodePtr;

private:
    std::vector<PlayerNode> payoffs;
    std::string player;
    NodePtr up;
    NodePtr down;

public:
    //Constructor
    // Takes the payoff values, player name and creates a node ready to be linked into tree
    TreeNode(std::vector<PlayerNode> payoff, std::string player);

    // insert
    // Inserts a node at the given depth for a player
    void insert (const std::string& name);

    // solve
    // pre: tree exists
    // post: Solves the tree using rollback
    std::vector<PlayerNode> solve();

    // print
    // pre: tree exists
    // post: Print all nodes in the tree
    void print() const;

    // nodeCount
    // Returns a count of all the nodes in the Tree structure
    size_t nodeCount() const;
};


#endif //ROLLBACK_TREENODE_H
