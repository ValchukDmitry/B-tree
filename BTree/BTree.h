#ifndef B_TREE_BTREE_H
#define B_TREE_BTREE_H

#include <iostream>
#include "TreeElem.h"

template<class T>
class BTree {
public:
    BTree();

    ~BTree();

    BTree(const BTree &operandTree);

    BTree &operator=(const BTree &operandTree);

    bool searchElement(const T value);

    void insertElement(T value) {

    }

    void deleteElement(T &value);

    friend std::istream &operator<<(std::istream &in, BTree &tree);//print tree in ascending order of elements

    friend std::istream &operator>>(std::istream &in, BTree &tree);

    bool isTreeEmpty(const BTree &operandTree);

    void cleanTree(BTree &operandTree); // tree cleaning

    int getOrder(const BTree &operandTree);

    int getSize(const BTree &operandTree);

private:
    int t; //b-tree order
    int size; //tree size
    TreeElem *root; //root of tree
};


#endif //B_TREE_BTREE_H
