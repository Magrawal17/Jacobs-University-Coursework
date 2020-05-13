#include <iostream>
using namespace std;

class Binarytree;
class Linkedlist
{
private:
    struct list
    {
        int data;
        list *ptr;
    };
    list *head;
public:
    Linkedlist()
    {
        this->head = NULL;
    }
    void push(int data)
    {
        struct list *newel = new list;
        newel->data = data;
        newel->ptr = head;
        head = newel;
    }
    void reverse()
    {
        struct list *prev = NULL;
        struct list *cursor = head;
        struct list *ahead = NULL;
        while (cursor != NULL)
        {
            ahead = cursor->ptr;
            cursor->ptr = prev;
            prev = cursor;
            cursor = ahead;
        }
        head = prev;
    }
    void print()
    {
        struct list *temp;
        for (temp = this->head; temp != NULL; temp = temp->ptr)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    } 
    void helperbtree(Binarytree &tree, int start, int end);
    void converttobinarytree(Binarytree &tree)
    {
        struct list *temp = this->head;
        int count = 0;
        while (temp->ptr != NULL)
        {
            temp = temp->ptr;
            count++;
        }
        helperbtree(tree, 0, count);
    }
};

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
        if (data <= root->data)
        {
            if (root->left == NULL)
            {
                Node *newel = new Node(data);
                root->left = newel;
            }
            else
            {
                helperinsert(root->left, data);
            }
        }
        else if (data > root->data)
        {
            if (root->right == NULL)
            {
                Node *newel = new Node(data);
                root->right = newel;
            }
            else
            {
                helperinsert(root->right, data);
            }
        }
    }
    void helperconvert(Linkedlist &list, Node *root)
    {
        if (root->left != NULL)
        {
            helperconvert(list, root->left);
        }
        list.push(root->data);
        if (root->right != NULL)
        {
            helperconvert(list, root->right);
        }
    }
    void helperprint(Node *root)
    {
        if (root->left != NULL)
        {
            helperprint(root->left);
        }
        cout << root->data << " ";
        if (root->right != NULL)
        {
            helperprint(root->right);
        }
    }

public:
    Binarytree()
    {
        this->root = NULL;
    }
    void insert(int data)
    {
        if (this->root == NULL) //if first element;
        {
            Node *newel = new Node(data);
            this->root = newel;
            return;
        }
        helperinsert(this->root, data);
    }
    void converttolinklist(Linkedlist &list)
    {
        helperconvert(list, this->root);
    }
    void print()
    {
        helperprint(this->root);
        cout<<endl;
    }
};

void Linkedlist::helperbtree(Binarytree &tree, int start, int end)
{
    if (start > end)
    {
        return;
    }
    int mid = (start + end) / 2;
    struct list *temp = head;
    int i = 0;
    while (i < mid && temp->ptr != NULL)
    {
        temp = temp->ptr;
        i++;
    }
    tree.insert(temp->data);
    helperbtree(tree, start, mid - 1);
    helperbtree(tree, mid + 1, end);
}

