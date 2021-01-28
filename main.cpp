#include <iostream>
#include "Tree.h"


int main() {
    std::cout << "Welcome to the Rollback Equilibrium simulator!" << std::endl;
    std::cout << "Let's get started with a simple example" << std::endl;
    Tree myTree;
    std::cout<<myTree.nodeCount()<<std::endl;
    myTree.print();

    size_t count, i(0);
    std::cout << "How many inserts would you like to complete?" << std::endl;
    std::cin>>count;
    while(i<count){
        myTree.insert();
        ++i;
    }

    myTree.print();
    myTree.solve();


    return 0;
}
