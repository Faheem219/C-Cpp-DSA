#include<iostream>
#include "Queue.h"
using namespace std;

struct Node *root=NULL;

void Tcreate(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    Create(&q,100);
    cout<<"\nEnter root value: ";
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    
    while(!isEmpty(q)){
        p=dequeue(&q);
        cout<<"\nEnter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        cout<<"\nEnter right child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void Preorder(struct Node *p){
    if(p){
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

int main(){
    Tcreate();
    Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    return 0;
}