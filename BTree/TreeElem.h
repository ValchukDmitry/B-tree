//
// Created by awemath on 21.06.16.
//

#include "vector"

#ifndef B_TREE_TREEELEM_H
#define B_TREE_TREEELEM_H

template<class T>
class TreeElem {
public:
    TreeElem<T>() {
        n = 0;
    }


    bool isLeaf() const {
        return leaf;
    }

    void setLeaf(bool leaf) {
        TreeElem::leaf = leaf;
    }

    int getN() const {
        return n;
    }

    const std::vector<T> &getKeys() const {
        return keys;
    }

    const std::vector<TreeElem *> &getChilds() const {
        return childs;
    }

private:
    bool leaf;
    int n;
    std::vector<T> keys;
    std::vector<TreeElem *> childs;
};


#endif //B_TREE_TREEELEM_H
