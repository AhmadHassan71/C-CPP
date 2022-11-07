#include<iostream>
#include<queue>
using namespace std;


struct Node
{
    int data;
    Node* left, * right;
};



class BST
{
public:
    Node* root;



    BST()
    {
        root = NULL;
    }

    void insert(int val)        // returns true if insertion is successful
    {
        Node* nodeval=new Node;
        nodeval->left = NULL;
        nodeval->right = NULL;
        nodeval->data = val;
        if (root == NULL)
        {
            root = nodeval;
            return;
        }
        Node* nodeptr = root;
        
        while (nodeptr != NULL)
        {
            if (nodeptr->data > val)
            {
                if (nodeptr->left)
                    nodeptr = nodeptr->left;
                else
                {
                    nodeptr->left = nodeval;
                    return;
                }
            }

            else if (nodeptr->data < val)
            {
                if (nodeptr->right)
                    nodeptr = nodeptr->right;
                else
                {
                    nodeptr->right = nodeval;
                    return;
                }
            }
            else
            {
                cout << "\n Duplicate Value found\n";
            }
        }
        return;
    }

    void display()
    {
        inorderTraversal(root);
    }

    bool retrieve(int val)
    {
        Node* nodeptr = root;

        while (nodeptr)
        {
            if (nodeptr->data == val)
                return true;
            else if (nodeptr->data > val)
            {
                nodeptr = nodeptr->left;
            }
            else if (nodeptr->data < val)
            {
                nodeptr = nodeptr->right;
            }
        }
        return false;
    }


        // Preorder traversal
        void preorderTraversal(Node* node) 
        {
            if (node == NULL)
            return;

            cout << node->data << "->";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }

        void preorderTraversal() 
        {
            preorderTraversal(root);
        }   

        // Postorder traversal
        void postorderTraversal(Node* node) 
        {
            if (node == NULL)
                return;

            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << "->";
        }

        void postorderTraversal() 
        {
            postorderTraversal(root);
        }

        // Inorder traversal
        void inorderTraversal(Node* node) 
        {
            if (node == NULL)
                return;

            inorderTraversal(node->left);
            cout << node->data << "->";
            inorderTraversal(node->right);
        }
        void inorderTraversal() 
        {
            inorderTraversal(root);
        }

        void levelOrder(Node* node)
        {
            if(node==NULL)
                return;
            
            queue<Node*> q;
            q.push(node);

            while(q.empty()==false)
            {
                Node* temp=q.front();
                cout<<temp->data<<"->";
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        void levelOrder()
        {
            levelOrder(root);
        }


        int getMin()
        {
            
            if(!root)
                return 0;

            if(!root->left)
                return root->data;
  
            Node* temp=root->left;
            
            while (temp->left!= NULL)
            {
                temp=temp->left;
            }
           return temp->data;
        }

        Node* getMin(Node* root)
        {
            Node* temp=root->left;
            
            while (temp && temp->left)
            {
                temp=temp->left;
            }
           return temp;
        }

        Node* delNode(Node* node, int val)
        {
            if(val < node->data)
            {
                node->left=delNode(node->left,val);
            }
            else if(val > node->data)
            {
                node->right=delNode(node->right,val);
            }
            else
            {
                if(!node->left && !node->right)
                {
                    return NULL;
                }
                else if(!node->left)
                {
                    Node* temp=node->right;
                    free(node);
                    return temp;
                }
                else if(!node->right)
                {
                    Node* temp=node->left;
                    free(node);
                    return temp;
                }
                Node* temp= getMin(node->right);

                node->data = temp->data;
                node->right = delNode(node->right,temp->data);
            }
            return node;    
            
        }

        void delNode(int val)
        {
            if(root==NULL)
                return;
            else
            {
                delNode(root,val);
                cout<<"deleted node : "<<val<<endl;
            }
        }

};