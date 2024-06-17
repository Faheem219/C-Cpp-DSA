#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Node{
public:
    Node *lchild;
    T data;
    Node *rchild;
};

template <class T>
class BST{
private:
    Node<T> *root;
public:
    BST(){root=NULL;}
    void Insert(T key); // Time Complexity: O(n*log n)
    void Inorder(Node<T> *p); // Time Complexity: O(n)
    Node<T>* getRoot(){return root;}
    Node<T>* Search(T key); // Time Complexity: O(log n)
    Node<T>* RInsert(Node<T> *p,T key); // Time Complexity: O(log n)
    Node<T>* Delete(Node<T> *p, T key); // Time Complexity: O(n*log n)
    int Height(Node<T> *p);
    Node<T>* InPre(Node<T> *p);
    Node<T>* InSucc(Node<T> *p);
    void createPre(T *pre, int n); // Time Complexity: O(n)
};

// TIME COMPLEXITY O(n*log n)
template <class T>
void BST<T>::Insert(T key){
    Node<T> *t=root;
    Node<T> *r,*p;
    if(root==NULL){
        p=new Node<T>;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t){
        r=t;
        if(key<t->data) t=t->lchild;
        else if(key>t->data) t=t->rchild;
        else return;
    }
    p=new Node<T>;
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data) r->lchild=p;
    else r->rchild=p;
}

template <class T>
void BST<T>::Inorder(Node<T> *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

// TIME COMPLEXITY: O(log n)
template <class T>
Node<T>* BST<T>::Search(T key){
    Node<T> *t=root;
    while(t){
        if(key==t->data) return t;
        else if(key<t->data) t=t->lchild;
        else t=t->rchild;
    }
    return NULL;
}

// TIME COMPLEXITY: O(log n)
template <class T>
Node<T>* BST<T>::RInsert(Node<T> *p,T key){
    Node<T> *t=NULL;
    if(p==NULL){
        t=new Node<T>;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data) p->lchild=RInsert(p->lchild,key);
    else if(key>p->data) p->rchild=RInsert(p->rchild,key);

    return p;
}

template <class T>
int BST<T>::Height(Node<T> *p){
    int x=0,y=0;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    if(x>y) return x+1;
    else return y+1;
}

template <class T>
Node<T>* BST<T>::InPre(Node<T> *p){
    while(p && p->rchild!=NULL) p=p->rchild;
    return p;
}

template <class T>
Node<T>* BST<T>::InSucc(Node<T> *p){
    while(p && p->lchild!=NULL) p=p->lchild;
    return p;
}

// TIME COMPLEXITY: O(n*log n)
template <class T>
Node<T>* BST<T>::Delete(Node<T> *p, T key){
    Node<T> *q=NULL;
    if(p==NULL) return NULL;
    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root) root=NULL;
        delete p;
        return NULL;
    }

    if(key<p->data) p->lchild=Delete(p->lchild,key);
    else if(key>p->data) p->rchild=Delete(p->rchild,key);
    else{
        if(Height(p->lchild)>Height(p->rchild)){
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else{
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

// TIME COMPLEXITY: O(n)
template <class T>
void BST<T>::createPre(T *pre, int n){
    int i=0;
    root = new Node<T>;
    root->data=pre[i++];
    root->lchild=root->rchild=nullptr;

    Node<T> *t;
    Node<T> *p=root;
    stack<Node<T>*> stk;
    while(i<n){
        if(pre[i]<p->data){
            t=new Node<T>;
            t->data=pre[i++];
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            stk.push(p);
            p=t;
        }
        else{
            if(pre[i]>p->data && pre[i]<(stk.empty()?32767:stk.top()->data)){
                t=new Node<T>;
                t->data=pre[i++];
                t->lchild=t->rchild=nullptr;
                p->rchild=t;
                p=t;
            }
            else{
                p=stk.top();
                stk.pop();
            }
        }
    }
}

int main(){
    BST<int> t,b;
    Node<int> *search;
    t.Insert(5);
    // t.Insert(20);
    // t.Insert(30);
    t.RInsert(t.getRoot(),10);
    t.RInsert(t.getRoot(),20);
    t.RInsert(t.getRoot(),30);
    t.RInsert(t.getRoot(),25);
    cout<<"\nInorder:"<<endl;
    t.Inorder(t.getRoot());
    cout<<endl;

    t.Delete(t.getRoot(),10);
    search=t.Search(25);
    cout<<"\nInorder:"<<endl;
    t.Inorder(t.getRoot());
    cout<<endl;
    search?cout<<"\nElement is found: "<<search->data<<endl:cout<<"\nElement not found."<<endl;

    // BST from Preorder traversal
    cout << "BST from Preorder: " << flush;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre)/sizeof(pre[0]);
 
    b.createPre(pre, n);
    b.Inorder(b.getRoot());
    cout << endl;
    return 0;
}