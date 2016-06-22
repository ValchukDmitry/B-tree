#ifndef B_TREE_BTREE_H
#define B_TREE_BTREE_H

#include <iostream>
#include "TreeElem.h"

template<class T>
class BTree {
public:
    BTree() {
        size = 0;
        root = nullptr;
    }

    ~BTree();

    BTree(const BTree &operandTree);

    BTree &operator=(const BTree &operandTree);

    bool searchElement(const T value) {
        for (int i = 0; i < root->getN(); i++) {
            if (value == root->getKey(i)) {
                return true;
            }
            if (value < root->getKey(i)) {
                root = root->getChild(i);
                searchElement(value);
            }
            return false;
        }
    }

    void insertElement(T value) {

    }

    void deleteElement(T &value);

    friend std::ostream &operator<<(std::ostream &out, BTree &tree) { //print tree in ascending order of elements
        return out;
    }

    friend std::istream &operator>>(std::istream &in, BTree &tree);

    bool isTreeEmpty(const BTree &operandTree) {
        return !(bool)(size);
    }

    void cleanTree(BTree &operandTree); // tree cleaning

    int getOrder() const {
        return t;
    }

    int getSize() const {
        return size;
    }

private:
    int t; //b-tree order
    int size; //tree size
    TreeElem *root; //root of tree
};


#endif //B_TREE_BTREE_H
