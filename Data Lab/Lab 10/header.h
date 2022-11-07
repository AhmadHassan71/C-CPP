#include <iostream>
using namespace std;

struct TreeNode
{

    int value;

    TreeNode *left;

    TreeNode *right;

}root;

class intBinaryTree
{
    private:
        TreeNode *root;
    
    public:
        intBinaryTree()
        {
            root= NULL;
        }
        

        bool find(int num)
        {
            TreeNode *nodePtr=root;

            while(nodePtr)
            {
                if(nodePtr->value==num)
                    return true;
                else if(nodePtr->value>num)
                {
                    nodePtr=nodePtr->left;
                }
                else
                {
                    nodePtr=nodePtr->right;
                }
            }
            return false;
        }


        // void postorder(TreeNode *p)
        // {

        //     if (p != NULL)

        //     {

        //         postorder(p->left);

        //         postorder(p->right);

        //         cout << p->value << " ";

        //     }

        // }



        ~intBinaryTree()
        {

        }
};