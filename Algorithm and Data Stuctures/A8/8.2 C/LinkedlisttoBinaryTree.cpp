#include <iostream>
#include "BinaryTreeandLinkedlist.h"
using namespace std;

int main(){

    Binarytree bst;
    Linkedlist list;
    for(int i = 0; i < 10; i++)
    {
        list.push(i);
    }
    list.reverse();     //due to not having pushfront function i just reversed it
    cout<<"Linked list print"<<endl;
    list.print();
    
    list.converttobinarytree(bst);
    cout<<"Binary tree print"<<endl;
    bst.print();
    return 0;
}