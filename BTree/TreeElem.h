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

    TreeElem * getChild(int i) {
        return childs[i];
    }

    const T getKey(int i) const {
        return keys[i];
    }

    void addKey(T key) {
        n++;
        keys.push_back(key);
    }


    TreeElem *getParent() const {
        return parent;
    }

    void setParent(TreeElem *parent) {
        TreeElem::parent = parent;
    }

private:
    bool leaf;
    int n;
    std::vector<T> keys;
    std::vector<TreeElem *> childs;
    TreeElem *parent;
};


#endif //B_TREE_TREEELEM_H
