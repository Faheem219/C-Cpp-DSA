#include <iostream>
using namespace std;

template <class T>
class Node{
public:
    Node *lchild;
    T data;
    int height;
    Node *rchild;
};

template <class T>
class AVL{
private:
    Node<T> *root;
public:
    AVL(){root=nullptr;}
    Node<T>* getRoot(){return root;}
    Node<T>* RInsert(Node<T> *p,T key);
    int NodeHeight(Node<T> *p);
    int balanceFactor(Node<T> *p);
    Node<T>* LLRotation(Node<T> *p);
    Node<T>* LRRotation(Node<T> *p);
    Node<T>* RRRotation(Node<T> *p);
    Node<T>* RLRotation(Node<T> *p);
    void Inorder(Node<T> *p);
    void Inorder(){Inorder(root);}
    Node<T>* Delete(Node<T> *p,T key);
    Node<T>* InPre(Node<T> *p);
    Node<T>* InSucc(Node<T> *p);
};

template <class T>
int AVL<T>::NodeHeight(Node<T> *p){
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}

template <class T>
int AVL<T>::balanceFactor(Node<T> *p){
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl-hr;
}

template <class T>
Node<T>* AVL<T>::LLRotation(Node<T> *p){
    Node<T> *pl=p->lchild;
    Node<T> *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p) root=pl;

    return pl;
}

template <class T>
Node<T>* AVL<T>::LRRotation(Node<T> *p){
    Node<T> *pl=p->lchild;
    Node<T> *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;

    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
    
    if(root==p) root=plr;
    return plr;
}

template <class T>
Node<T>* AVL<T>::RRRotation(Node<T> *p){
    Node<T> *pr=p->rchild;
    Node<T> *prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if(root==p) root=pr;
    
    return p;
}

template <class T>
Node<T>* AVL<T>::RLRotation(Node<T> *p){
    Node<T> *pr=p->rchild;
    Node<T> *prl=pr->lchild;

    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    prl->rchild=pr;
    prl->lchild=p;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);
    
    if(p==root) root=prl;
    return p;
}

// TIME COMPLEXITY: O(log n)
// AVL Tree is balanced as soon as a node is getting imbalanced, if not done then |bf| will exceed 3 
template <class T>
Node<T>* AVL<T>::RInsert(Node<T> *p,T key){
    Node<T> *t=NULL;
    if(p==NULL){
        t=new Node<T>;
        t->data=key;
        t->height=1; // Starting height from 1 onwards
        t->lchild=t->rchild=NULL;
        if(root==NULL) root=t;
        return t;
    }
    if(key<p->data) p->lchild=RInsert(p->lchild,key);
    else if(key>p->data) p->rchild=RInsert(p->rchild,key);

    p->height=NodeHeight(p);

    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1) return LLRotation(p);
    else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1) return LRRotation(p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1) return RRRotation(p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1) return RLRotation(p);

    return p;
}

template <class T>
void AVL<T>::Inorder(Node<T> *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

template <class T>
Node<T>* AVL<T>::InPre(Node<T> *p){
    while(p && p->rchild!=NULL) p=p->rchild;
    return p;
}

template <class T>
Node<T>* AVL<T>::InSucc(Node<T> *p){
    while(p && p->lchild!=NULL) p=p->lchild;
    return p;
}

template <class T>
Node<T>* AVL<T>::Delete(Node<T> *p,T key){
    if(p==nullptr) return nullptr;
    if(p->lchild==nullptr && p->rchild==nullptr){
        if(p==root) root=nullptr;
        delete p;
        return nullptr;
    }

    if(key<p->data) p->lchild=Delete(p->lchild,key);
    else if(key>p->data) p->rchild=Delete(p->rchild,key);
    else{
        Node<T> *q;
        if(NodeHeight(p->lchild)>NodeHeight(p->rchild)){
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

    // Update Height and perform rotations based on balance factor:
    p->height=NodeHeight(p);
    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1) return LLRotation(p); // L1 Rotation
    else if (balanceFactor(p)==2 && balanceFactor(p->lchild)==-1) return LRRotation(p); // L-1 Rotation
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1) return RRRotation(p); // R-1 Rotation
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1) return RLRotation(p); // R1 Rotation
    else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==0) return LLRotation(p); // L0 Rotation
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==0) return RRRotation(p); // R0 Rotation

    return p;
}

int main(){
    AVL<int> tree;
 
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.RInsert(tree.getRoot(), A[i]);
    }
 
    tree.Inorder();
    cout << endl;
 
    tree.Delete(tree.getRoot(), 25);
   
    tree.Inorder();
    cout << endl;
 
    return 0;
}