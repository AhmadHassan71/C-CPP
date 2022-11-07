#include "header.h"


int main()
{
    
    BST tree;
    tree.insert(25);
    tree.insert(15);
    tree.insert(50);
    tree.insert(10);
    tree.insert(22);
    tree.insert(35);
    tree.insert(70);
    tree.insert(4);
    tree.insert(12);
    tree.insert(18);
    tree.insert(24);
    tree.insert(31);
    tree.insert(44);
    tree.insert(66);
    tree.insert(90);

    if(tree.retrieve(25))
    {
        cout<<endl;
        cout<<"Inorder : ";
        tree.inorderTraversal();
        cout<<endl;
        cout<<"Preorder : ";
        tree.preorderTraversal();
        cout<<endl;
        cout<<"Postorder : ";
        tree.postorderTraversal();
        cout<<endl;
        cout<<"Level Order : ";
        tree.levelOrder();
        cout<<endl;
        cout<<"Minimum is : "<<tree.getMin()<<endl;

        tree.delNode(25);

        cout<<"Minimum is : "<<tree.getMin()<<endl;

        cout<<"Inorder : ";
        tree.inorderTraversal();
        cout<<endl;
        cout<<"Preorder : ";
        tree.preorderTraversal();
        cout<<endl;
        cout<<"Postorder : ";
        tree.postorderTraversal();
        cout<<endl;
        cout<<"Level Order : ";
        tree.levelOrder();
        cout<<endl;
    }


    return 0;
}