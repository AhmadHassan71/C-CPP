#include "header.h"


int main()
{
    cout << " HELLO  ";

    AVL<int> tree;
    tree.root = tree.insertNode(50);

    tree.root = tree.insertNode(10);
    tree.root = tree.insertNode(60);
    tree.root = tree.insertNode(8);
    tree.root = tree.insertNode(20);

    tree.root = tree.insertNode(15);
    //cout << tree.root->data;
    tree.levelOrder();

    tree.delNode(50);

    tree.levelOrder();
    return 0;
}