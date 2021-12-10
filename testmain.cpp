//
// Created by njudd on 11/18/2021.
//

#include <iostream>
#include <sstream>
#include <queue>
#include "AVL.h"

string AVLtoString(AVL* bst);

int main() {
    AVL* testTree = new AVL();
    testTree->add(1);
    testTree->add(2);
    testTree->add(3);
    testTree->add(4);
    testTree->add(5);
    testTree->add(6);
    testTree->add(7);
    testTree->add(8);
    testTree->add(9);
    testTree->add(10);
    testTree->add(11);
    testTree->add(12);
    testTree->add(13);
    testTree->add(14);
    testTree->add(15);
    testTree->add(16);
    testTree->add(17);
    testTree->add(18);
    testTree->add(19);
    testTree->add(20);
    testTree->remove(8);
    testTree->remove(7);
    cout << AVLtoString(testTree) << endl;
    testTree->remove(6);
    cout << AVLtoString(testTree) << endl;
}

string AVLtoString(AVL* bst) {
    queue<NodeInterface*> readQ; // used to read in the levels of the tree, contains NodeTree*
    stringstream nodeReader_ss; // used to store the values of the nodes and the level-order sequence
    int depth = 0; // the depth of a node on the tree

    if (bst->getRootNode() == nullptr) {
        return "AVL is empty";
    }

    readQ.push(bst->getRootNode()); // push the root node of the tree into the queue

    while (!readQ.empty()) { // as long as the queue has a remaining node:
        int i = readQ.size(); // store the number of nodes on this level of the tree
        nodeReader_ss << depth << ":  ";
        for (; i > 0; i--) { // for each node on this level,
            NodeInterface* nextNode = readQ.front(); // store the next node in the queue
            nodeReader_ss << nextNode->getData() << " "; // store the data from the node into the ss
            if (nextNode->getLeftChild() != nullptr) { // if there is a left child, push the left child into the queue
                readQ.push(nextNode->getLeftChild());
            }
            if (nextNode->getRightChild() != nullptr) { // if there is a right child, push the left child into the queue
                readQ.push(nextNode->getRightChild());
            }
            readQ.pop(); // pop the node off of the queue, leaving its children in the queue
        }
        nodeReader_ss << "\n"; // push an endl into the ss to distinguish levels
        depth++;
    }

    return nodeReader_ss.str();
}