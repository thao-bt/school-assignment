#include <iostream>

using namespace std;

//declare a node
struct Node{
    int data;
    Node *pRight;
    Node *pLeft;
};
typedef struct Node *tree;

//declare a tree
void createTree(tree &t) {//tree &t is a reference to a pointer to Node
    t = NULL; // cay rong
}

tree newNode(int x){
    tree p = new Node();
    p->data=x;
    p->pRight = NULL;
    p->pLeft = NULL;
    return p;
}

// add x to the binary tree
void addNode(tree &t, int x) { // t is an alias for the existing tree
    tree b = newNode(x);
    if (t==NULL){ // if tree is empty
        t =b;
    }else{// if tree is not empty
        if (x<t->data){ //t->pLeft is the value of the next left node
            addNode(t->pLeft,x);
        }else if(x>t->data){
            addNode(t->pRight,x);
        }
    }
}

// print out binary tree in NLR
void traverseTree(tree t){
    if (t!=NULL){
        cout<< t->data;
        traverseTree(t->pRight);
        traverseTree(t->pLeft);// traverse to the left
    }
}


int main() {

}
