#pragma once
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct node
{
    T data;
    int height;
    node <T>* left;
    node <T>* right;
    node()
    {
        right = NULL;
        left = NULL;
        height = -1;
    }
};

template <typename T>
class AVL
{
public:
    node<T>* root;


    AVL()
    {
        cout << "\n created \n";
        root = NULL;
     
    }

    AVL(T val)
    {
        root = new node<T>;
        root->data = val;
    }

    T max(T num1, T num2)
    {
        if (num1 > num2)
            return num1;
        return num2;
    }

    int getHeight()
    {
        if (!root)
            return 0;

        int var1 = getHeight(root->left);
        int var2 = getHeight(root->right);

        return (1 + max(var1, var2));
    }
    int getHeight(node<T>* root)
    {
        if (!root)
            return 0;

        int var1 = getHeight(root->left);
        int var2 = getHeight(root->right);

        return (1 + max(var1, var2));
    }

    T getMin()
    {
        node<T>* curr = root;
        while (!curr->left)
        {
            curr = curr->left;
        }
        return curr->data;
    }

    node<T>* getMin(node<T>* root)
    {

        if (!root)
            return 0;

        if (!root->left)
            return root;

        node<T>* temp = root->left;

        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    node<T>* rotateRight(node<T>* root)
    {
        node<T>* temp = root->left;
        node<T>* temp2 = temp->right;
        temp->right = root;
        root->left = temp2;
        root->height = getHeight(root);
        temp->height = getHeight(temp);

        return temp;
    }

    node<T>* rotateLeft(node<T>* root)
    {
        node<T>* temp = root->right;
        node<T>* temp2 = temp->left;
        temp->left = root;
        root->right = temp2;
        root->height = getHeight(root);
        temp->height = getHeight(temp);

        return temp;
    }


    void levelOrder(node<T>* Node)
    {
        if (Node == NULL)
            return;

        queue<node<T>*> q;
        q.push(Node);

        while (q.empty() == false)
        {
            node<T>* temp = q.front();
            cout << temp->data << "->";
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            
        }
    }
    // Inorder traversal
    void inorderTraversal(node<T>* Node)
    {
        if (Node == NULL)
            return;

        inorderTraversal(Node->left);
        cout << Node->data << "->";
        inorderTraversal(Node->right);
    }
    void inorderTraversal()
    {
        inorderTraversal(root);
    }
    void levelOrder()
    {
        levelOrder(root);
    }


    int getBalanceFactor(node<T>* Node)
    {
        if (!Node)
            return 0;
        else
        {
            return getHeight(Node->left) - getHeight(Node->right);
        }
    }

    node<T>* insertNode(T val)
    {
        return insertNode(root, val);
        //return root;
    }

    node<T>* insertNode(node<T>* root, T val)
    {
        node<T>* temp = new node<T>;
        temp->data = val;
        temp->right = temp->left = NULL;
        if (!root)
        {
            root = temp;
            return root;
        }


        if (val < root->data)
        {
            root->left = insertNode(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = insertNode(root->right, val);
        }
        else
            return root;

        root->height = getHeight(root);
        int bf = getBalanceFactor(root);
        if (bf > 1)
        {
            if (val < root->left->data)
            {
                return rotateRight(root);
            }
            else if (val > root->left->data)
            {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }
        if (bf < -1)
        {
            if (val > root->left->data)
            {
                return rotateLeft(root);
            }
            else if (val < root->left->data)
            {
                root->left = rotateRight(root->left);
                return rotateLeft(root);
            }
        }
        return root;
    }

    T delNode(T val)
    {
        delNode(root,val);
        cout<<"\nDeleted the node containing : "<<val<<endl;
    }
    node<T>* delNode(node<T>* Node, T val)
        {
            if(val < Node->data)
            {
                Node->left=delNode(Node->left,val);
            }
            else if(val > Node->data)
            {
                Node->right=delNode(Node->right,val);
            }
            else
            {
                if(!Node->left && !Node->right)
                {
                    return NULL;
                }
                else if(!Node->left)
                {
                    node<T>* temp=Node->right;
                    free(Node);
                    return temp;
                }
                else if(!Node->right)
                {
                    node<T>* temp=Node->left;
                    free(Node);
                    return temp;
                }
                node<T>* temp= getMin(Node->right);

                Node->data = temp->data;
                Node->right = delNode(Node->right,temp->data);
            }


            if(!Node)
                return Node;    
            
            Node->height=getHeight(Node);
            int bf =getBalanceFactor(Node);
            if(bf>1)
            {
                if(getBalanceFactor(Node->left)>=0)
                    return rotateRight(Node);
                else
                {
                    Node->left=rotateLeft(root->left);
                    return rotateRight(Node);
                }

            }
            if (bf<-1)
            {
                if(getBalanceFactor(Node->right)>=0)
                {
                    return rotateLeft(Node);
                }
                else
                {
                    Node->right=rotateRight(root->right);
                    return rotateLeft(Node);
                }
            }
            return Node;
        }



};