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
        TreeElem<T> *bufElem = root;
        while (!bufElem->isLeaf()) {
            int i = 0;
            for (; (i < bufElem->getN()) && bufElem->getKey(i) < value; i++);
            if (i > 0) {
                bufElem = bufElem->getChild(i);
            }
        }
        if (bufElem->getN() == 2 * t - 1) {

        }
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

    void splitVertex(TreeElem *elem) {
        T value = elem->getKey(((2 * t - 1) / 2) + 1);
        if (elem->getParent()->getN() == 2 * t - 1) {
            if (elem->getParent() == 0) {
                splitRoot(elem->getParent());
            }
            splitVertex(elem->getParent());
        }
        TreeElem<T> *newVertex = new TreeElem<T>();
        elem->getParent()->addKey(value, newVertex);
        newVertex->removeKey(value);
        int g = 0;
        for (int i = g = ((2 * t) - 1) / 2; i < 2 * t - 1; i++) {
            newVertex->addKey(elem->getKey(g), elem->getChild(g));
            newVertex->removeKey(elem->getKey(g));
            newVertex->removeChild(elem->getChild(g));
        }
        newVertex->addChild(elem->getChild(g));
    }

    void splitRoot(TreeElem *elem) {
        T value = elem->getKey((2 * t - 1) / 2 + 1);
        TreeElem<T> *newRoot = new TreeElem<T>;
        newRoot->addKey(value, root);
        root->removeKey(value);

        TreeElem<T> *newVertex = new TreeElem<T>();
        int g = 0;
        for (int i = g = ((2 * t) - 1) / 2; i < 2 * t - 1; i++) {
            newVertex->addKey(elem->getKey(g), elem->getChild(g));
            newVertex->removeKey(elem->getKey(g));
            newVertex->removeChild(elem->getChild(g));
        }
        newVertex->addChild(elem->getChild(g));
    }
};


#endif //B_TREE_BTREE_H