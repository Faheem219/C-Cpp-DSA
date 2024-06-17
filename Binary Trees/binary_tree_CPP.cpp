#include <iostream>
#include "Queue_CPP.h"
#include <stack>
using namespace std;

template <class T>
class Tree{
public:
    Node<T> *root;
    Tree(){root=NULL;}
    void CreateTree();
    // void Preorder(){Preorder(root)} If root was a private member, this is how you would modify the program
    void Preorder(Node<T> *p); // The above is known as function overloading, same should be done to rest
    void Postorder(Node<T> *p);
    void Inorder(Node<T> *p);
    void Levelorder(Node<T> *p);
    int Height(Node<T> *p);
    void IPreorder(Node<T> *p);
    void IInorder(Node<T> *p);
    int Count(Node<T> *p);
    int Countdeg2(Node<T> *p);
    int Countdeg1(Node<T> *p);
    int CountLeaf(Node<T> *p);
    int Sum(Node<T> *p);
};

template<class T>
void Tree<T>::CreateTree(){
    Node<T> *p,*t;
    T x;
    Queue<Node<T>*> q(100);
    cout<<"\nEnter root value: ";
    cin>>x;
    root=new Node<T>;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    
    while(!q.isEmpty()){
        p=q.dequeue();
        cout<<"\nEnter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node<T>;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"\nEnter right child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node<T>;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

template <class T>
void Tree<T>::Preorder(Node<T> *p){
    if(p){
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

template <class T>
void Tree<T>::Inorder(Node<T> *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

template <class T>
void Tree<T>::Postorder(Node<T> *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

template <class T>
void Tree<T>::Levelorder(Node<T> *p){
    Queue<Node<T>*> q(100);
    cout<<p->data<<" ";
    q.enqueue(p);
    while(!q.isEmpty()){
        p=q.dequeue();
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.enqueue(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.enqueue(p->rchild);
        }
    }
}

template <class T>
int Tree<T>::Height(Node<T> *p){
    int x=0,y=0;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    if(x>y) return x+1;
    else return y+1;
}

// ALL COUNT CODES CAN BE WRITTEN LIKE THE BELOW (w/o x & y) AS WELL
template <class T>
int Tree<T>::Count(Node<T> *p){
    if(p!=NULL)
        return Count(p->lchild)+Count(p->rchild)+1; // To find SUM just return x+y+p->data;
    return 0;
}

// The below function counts the nodes of degree 2 only by a simple modification in the above code:
template <class T>
int Tree<T>::Countdeg2(Node<T> *p){
    int x=0,y=0;
    if(p!=NULL){
        x=Countdeg2(p->lchild);
        y=Countdeg2(p->rchild);
        if(p->lchild && p->rchild) return x+y+1; // Only count the node if both children are present
    //  if(p->lchild || p->rchild) return x+y+1; // For both deg 1 and 2 nodes ie internal nodes
        else return x+y;
    }
    return 0;
}

template <class T>
int Tree<T>::Countdeg1(Node<T> *p){
    int x=0,y=0;
    if(p){
        x=Countdeg1(p->lchild);
        y=Countdeg1(p->rchild);
    //    if((p->lchild && !p->rchild) || (!p->lchild && p->rchild)) return x+y+1;
        if(p->lchild!=NULL ^ p->rchild!=NULL) return x+y+1; // ^ is symbol for exclusive or in C/C++.
        else return x+y;
    }
    return 0;
}

// The below function counts the nodes of degree 0 only by a simple modification in the above code:
template <class T>
int Tree<T>::CountLeaf(Node<T> *p){
    int x=0,y=0;
    if(p!=NULL){
        x=CountLeaf(p->lchild);
        y=CountLeaf(p->rchild);
        if(!p->lchild && !p->rchild) return x+y+1; // Only count the node if both children are absent
        else return x+y;
    }
    return 0;
}

// The below function calculates sum of binary tree only by a simple modification in the above code:
template <class T>
int Tree<T>::Sum(Node<T> *p){
    int x=0,y=0;
    if(p!=NULL){
        x=Sum(p->lchild);
        y=Sum(p->rchild);
        return x+y+p->data; // Just add the data of node instead of incrementing the counter
    }
    return 0;
}

// ITERATIVE PROCEDURES FOR PREORDER / INORDER / POSTORDER USING STACK:

template <class T>
void Tree<T>::IPreorder(Node<T> *p){
    stack<Node<T>*> s;
    while(p||!s.empty()){
        if(p){
            cout<<p->data<<" ";
            s.push(p);
            p=p->lchild;
        }
        else{
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}

template <class T>
void Tree<T>::IInorder(Node<T> *p){
    stack<Node<T>*> s;
    while(p||!s.empty()){
        if(p){
            s.push(p);
            p=p->lchild;
        }
        else{
            p=s.top();
            s.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

int main(){
    Tree<float> t;
    t.CreateTree();
    cout<<"\n\nPreorder:"<<endl;
    t.Preorder(t.root);
    cout<<"\n\nPostorder:"<<endl;
    t.Postorder(t.root);
    cout<<"\n\nInorder:"<<endl;
    t.Inorder(t.root);
    cout<<"\n\nLevel order:"<<endl;
    t.Levelorder(t.root);
    cout<<endl;
    cout<<"\nIterative Preorder:"<<endl;
    t.IPreorder(t.root);
    cout<<endl;
    cout<<"\nIterative Inorder:"<<endl;
    t.IInorder(t.root);
    cout<<endl;
    cout<<"\nCount: "<<t.Count(t.root)<<endl;
    cout<<"\nCount (deg 2): "<<t.Countdeg2(t.root)<<endl;
    cout<<"\nCount (deg 1): "<<t.Countdeg1(t.root)<<endl;
    cout<<"\nCount (leaf): "<<t.CountLeaf(t.root)<<endl;
    cout<<"\nHeight: "<<t.Height(t.root)<<endl;
    cout<<"\nSum: "<<t.Sum(t.root)<<endl;
    return 0;
}