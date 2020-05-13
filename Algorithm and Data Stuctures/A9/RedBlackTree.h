#include <iostream>
#include <list>
using namespace std;

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;
};

class RedBlackTree
{
private:
    Node *root;

protected:
    void rotateLeft(Node *&elem)
    {
        Node *y = elem->right;
        elem->right = y->left;
        if (y->right != NULL)
        {
            y->right->parent = elem;
        }
        y->parent = elem->parent;
        if (elem->parent == NULL)
        {
            root = y;
        }
        else if (elem == elem->parent->left)
        {
            elem->parent->left = y;
        }
        else
        {
            elem->parent->right = y;
        }
        y->left = elem;
        elem->parent = y;
    }

    void rotateRight(Node *&elem)
    {
        Node *y = elem->left;
        elem->left = y->right;
        if (y->left != NULL)
        {
            y->left->parent = elem;
        }
        y->parent = elem->parent;
        if (elem->parent == NULL)
        {
            root = y;
        }
        else if (elem == elem->parent->left)
        {
            elem->parent->left = y;
        }
        else
        {
            elem->parent->right = y;
        }
        y->right = elem;
        elem->parent = y;
    }
    Node *binarytreeinsert(Node *&root, Node *&elem)
    {
        if (root == NULL)
        {
            return elem;
        }
        if (elem->data < root->data)
        {
            root->left = binarytreeinsert(root->left, elem);
            root->left->parent = root;
        }
        else if (elem->data > root->data)
        {
            root->right = binarytreeinsert(root->right, elem);
            root->right->parent = root;
        }
        return root;
    }
    bool isRed(Node *elem)
    {
        if (elem != NULL && elem->color == RED)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void RBInsertFix(Node *&elem)
    {
        while (isRed(elem->parent)) //need to create new function as initally when adding causes problem
        {
            if (elem->parent == elem->parent->parent->left)
            {
                Node *uncle = elem->parent->parent->right;
                Node *grandparent = elem->parent->parent;
                if (isRed(uncle))
                {
                    elem->parent->color = BLACK;
                    uncle->color = BLACK;
                    elem->parent->parent->color = RED;
                    elem = elem->parent->parent;
                }
                else
                {
                    if (elem == elem->parent->right)
                    {
                        elem = elem->parent;
                        rotateLeft(elem);
                    }
                    elem->parent->color = BLACK;
                    elem->parent->parent->color = RED;
                    rotateRight(grandparent);
                }
            }
            else
            {
                Node *grandparent = elem->parent->parent;
                Node *uncle = elem->parent->parent->left;
                if (isRed(uncle))
                {
                    elem->parent->color = BLACK;
                    uncle->color = BLACK;
                    elem->parent->parent->color = RED;
                    elem = elem->parent->parent;
                }
                else
                {
                    if (elem == elem->parent->left)
                    {
                        elem = elem->parent;
                        rotateRight(elem);
                    }
                    elem->parent->color = BLACK;
                    elem->parent->parent->color = RED;
                    rotateLeft(grandparent); //error occurs when i dont do this
                }
            }
        }
        root->color = BLACK;
    }

    Node *helpermin(Node *elem)
    {
        while (elem->left != NULL)
        {
            elem = elem->left;
        }
        return elem;
    }

    Node *helpermax(Node *elem)
    {
        while (elem->right != NULL)
        {
            elem = elem->right;
        }
        return elem;
    }

    Node *helpersearch(Node *elem, int data)
    {
        while (elem != NULL && data != elem->data)
        {
            if (data < elem->data)
            {
                elem = elem->left;
            }
            else
            {
                elem = elem->right;
            }
        }
        return elem;
    }

    void transplant(Node *u, Node *v)
    {
        if (u->parent == NULL)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        if (v != NULL)
        {
            v->parent = u->parent;
        }
    }

    void Deletefix(Node *&elem)
    {
        Node *w;
        while (elem != root && elem->color == BLACK)
        {
            if (elem == elem->left)
            {
                w = elem->parent->right;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    elem->parent->color = RED;
                    rotateLeft(elem->parent);
                    w = elem->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    elem = elem->parent;
                }
                else
                {
                    if (w->right->color == BLACK)
                    {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        w = elem->parent->right;
                    }

                    w->color = elem->parent->color;
                    elem->parent->color = BLACK;
                    w->right->color = BLACK;
                    rotateLeft(elem->parent);
                    elem = root;
                }
            }
            else
            {
                w = elem->parent->left;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    elem->parent->color = RED;
                    rotateRight(elem->parent);
                    w = elem->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK)
                {
                    w->color = RED;
                    elem = elem->parent;
                }
                else
                {
                    if (w->left->color == BLACK)
                    {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(w);
                        w = elem->parent->left;
                    }
                    w->color = elem->parent->color;
                    elem->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(elem->parent);
                    elem = root;
                }
            }
        }
        elem->color = BLACK;
    }

    void helpercolor(Node *elem)
    {
        if (elem->color == RED)
        {
            cout << "Red";
        }
        else
        {
            cout << "Black";
        }
    }

    void helperprint(Node *&elem)
    {
        cout << elem->data;
        helpercolor(elem);
        cout<<"  ";
        //cout << endl;
        if (elem->left != NULL)
        {
            helperprint(elem->left);
        }
        if (elem->right != NULL)
        {
            helperprint(elem->right);
        }
    }
    
public:

    RedBlackTree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        Node *elem = new Node;
        elem->data = val;
        elem->color = RED;
        elem->left = elem->right = elem->parent = NULL;
        if (root == NULL)
        {
            root = elem;
        }
        else
        {
            binarytreeinsert(root, elem);
        }
        RBInsertFix(elem);
    }

    Node *predecessor(Node *&elem)
    {
        if (elem->left != NULL)
        {
            return helpermax(elem->left);
        }
        Node *y = elem->parent;
        while (y != NULL && elem == y->left)
        {
            elem = y;
            y = y->parent;
        }
        return y;
    }

    Node *successor(Node *&elem)
    {
        if (elem->right != NULL)
        {
            return helpermin(elem->right);
        }
        Node *y = elem->parent;
        while (y != NULL && elem == y->right)
        {
            elem = y;
            y = y->parent;
        }
        return y;
    }

    Node *getMinimum()
    {
        // Node*temp=helpermin(root);
        // cout<<temp->data<<endl;
        return helpermin(root);
    }

    Node *getMaximum()
    {
        //Node *temp = helpermax(root);
        //cout << temp->data << endl;
        return helpermax(root);
    }

    Node *search(int data)
    {
        if (helpersearch(root, data) == NULL)
        {
            //cout << "Data Not found" << endl;
            return NULL;
        }
        else
        {
            //cout << "Data found" << endl;
            return helpersearch(root, data);
        }
    }
    
    void Delete(Node *&elem)
    {
        Node *y = elem;
        Color Ycolor = y->color;
        Node *x;

        if (elem->left == NULL)
        {

            x = elem->right;
            transplant(elem, elem->right);
        }
        else if (elem->right == NULL)
        {
            x = elem->left;
            transplant(elem, elem->left);
        }
        else
        {
            y = helpermin(elem->right);
            Ycolor = y->color;
            x = y->right;
            if (y->parent == elem)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->right);
                y->right = elem->right;
                y->right->parent = y;
            }
            transplant(elem, y);
            y->left = elem->left;
            y->left->parent = y;
            y->color = elem->color;
        }
        if (Ycolor == BLACK)
        {
            Deletefix(x);
        }
    }

    void print()
    {
        helperprint(root);
        cout<<endl;
    }

};


