#include <iostream>
#include "Linkedlist.h"
using namespace std;

class Binarytree
{
private:
    class Node
    {
    public:
        int data;
        Node *right;
        Node *left;
        Node(int data)
        {
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }
    };
    Node *root;
    void helperinsert(Node *root, int data)
    {
        if(data <= root->data)
        {
            if(root->left==NULL)
            {
                Node *newel =new Node(data);
                root->left=newel;
            }
            else
            {
                helperinsert(root->left,data);
            }
        }
        else if (data > root->data)
        {
             if(root->right==NULL)
            {
                Node *newel =new Node(data);
                root->right=newel;
            }
            else
            {
                helperinsert(root->right,data);
            }
        }  
    }
    void helperconvert(Linkedlist &list,Node *root)
    {
        if (root->left != NULL)
        {
            helperconvert(list,root->left);
        }
        list.push(root->data);
        if (root->right != NULL)
        {
            helperconvert(list,root->right);
        }
    }
public:
    Binarytree()
    {
        this->root = NULL;
    }
    void insert(int data)
    {
        if (this->root==NULL)   //if first element;
        {
           Node *newel =new Node(data);
           this->root=newel;
           return;
        }
        helperinsert(this->root,data);
    }
    void converttolinklist(Linkedlist &list)
    {
        helperconvert(list,this->root);
    }
};