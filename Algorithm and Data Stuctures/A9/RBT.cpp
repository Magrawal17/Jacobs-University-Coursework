#include "RedBlackTree.h"
#include <iostream>
using namespace std;

   int main(){

    RedBlackTree tree;
    tree.insert(13);
    tree.insert(44);
    tree.insert(37);
    tree.insert(7);
    tree.insert(22);
    tree.insert(16);
    cout<<endl;
    cout<<"Tree after succesfull Insertion (Preorder Traversal)"<<endl;
    tree.print();
    cout<<endl;
    cout<<"Now Deleting the node 16"<<endl;
    Node *node = tree.search(16);
    tree.Delete(node);
    tree.print();
}