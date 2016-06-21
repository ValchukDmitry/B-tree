#ifndef B_TREE_BTREE_H
#define B_TREE_BTREE_H

class BTree {
public:
    BTree();

    ~BTree();

    BTree(const BTree &operandTree);

    BTree &operator=(const BTree &operandTree);

    bool searchElement(const BTree &operandTree);

    void insertElement(BTree &operandTree);

    void deleteElement(BTree &operandTree);

    void printTree (const BTree &operandTree);//print tree in ascending order of elements

    void inputElemntFromStream (BTree &operandTree);//input from the stream

    bool isTreeEmpty (const BTree &operandTree);

    void cleanTree (BTree &operandTree); // tree cleaning

    int getOrder (const BTree &operandTree);

    int getSize (const BTree &operandTree);

private:
    int t; //b-tree order
    int size;
    //tree height
    TreeElem *root; //root of tree
};


#endif //B_TREE_BTREE_H
