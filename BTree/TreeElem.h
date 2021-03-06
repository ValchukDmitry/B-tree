//
// Created by awemath on 21.06.16.
//

#include "vector"
#include <iostream>

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

    TreeElem *getChild(int i) {
        return childs[i];
    }

    const T getKey(int i) const {
        return keys[i];
    }

    void addKey(T key, TreeElem *treeElem) {
        n++;
        bool isLast = true;
        for (int i = 0; i < n; i++) {
            if (keys[i] < key) {
                keys.push_back(keys[n - 1]);
                childs.push_back(childs[childs.size() - 1]);
                for (int g = i; g < keys.size(); g++) {
                    keys[g + 1] = keys[g];
                }
                for (int g = i + 1; g < childs.size(); g++) {
                    childs[g + 1] = childs[g];
                }
                keys[i + 1] = key;
                childs[i] = treeElem;
                isLast = false;
                break;
            }
        }
        if (isLast) {
            keys.push_back(key);
            childs.push_back(treeElem);
        }
    }

    void removeKey(T key) {
        int i = 0;
        for (i = 0; i < n; i++) {
            if (keys[i] == key) {
                break;
            }
        }
        for (; i < n; i++) {
            keys[i] = keys[i + 1];
        }
        keys.pop_back();
        n--;
    }

    void addChild(TreeElem *treeElem) {
        childs.push_back(treeElem);
    }

    void addKey(T key) {
        int i = 0;
        bool isLast = true;
        for (i = 0; i < n; i++) {
            if (keys[i] < key) {
                keys.push_back(keys[n - 1]);
                for (int g = i; g < keys.size(); g++) {
                    keys[g + 1] = keys[g];
                }
                isLast = false;
                break;
            }
        }
        if (isLast) {
            keys.push_back(key);
        }
        n++;
    }

    void removeChild(TreeElem *treeElem) {
        int i = 0;
        for (i = 0; i < childs.size(); i++) {
            if (childs[i] == treeElem) {
                break;
            }
        }
        for (; i < childs.size(); i++) {
            childs[i] = childs[i + 1];
        }
        childs.pop_back();
    }

    TreeElem *getParent() const {
        return parent;
    }

    void setParent(TreeElem *parent) {
        TreeElem::parent = parent;
    }

    friend std::ostream &operator<<(std::ostream &out, TreeElem &treeElem) {

            if (treeElem.isLeaf()) {
                for (int i = treeElem.getN(); i > 0; i--) {

                }
            }
    }

private:
    bool leaf;
    int n; // количество детей, на 1 меньше, чем ключей
    std::vector<T> keys;
    std::vector<TreeElem *> childs;
    TreeElem *parent;
};


#endif //B_TREE_TREEELEM_H
