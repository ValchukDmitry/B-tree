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

private:
    bool isLeaf;
    int n;
    std::vector<T> key;
    std::vector<TreeElem *> childs;
};


#endif //B_TREE_TREEELEM_H
