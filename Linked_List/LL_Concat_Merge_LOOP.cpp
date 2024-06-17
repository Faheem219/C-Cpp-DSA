#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL,*second=NULL,*third=NULL; // This pointer points to the first node of the linked list
// It is global and therefore accessible to all functions.

void create(int A[], int n){
    struct Node *t;
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[], int n){
    struct Node *t;
    second = new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int Count(struct Node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

// Concatenation of LL:
void Concat(struct Node *p, struct Node *q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}

// Merging two LL (Concatenating sorted LL in sorted manner):
void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p) last->next=p;
    if(q) last->next=q;
}

// To check whether a LL is looped:
int isLoop(struct Node *f){
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    return p==q?1:0;
}

int main(){
    struct Node *t1,*t2;
    int A[]={3,5,7,10,15},B[]={2,4,6,8,9};
    create(A,5);
    create2(B,5);
    Display(first);
    cout<<endl<<endl;
    Display(second);
    cout<<endl<<endl;
    /*
    Concat(first,second);
    Display(third);
    cout<<endl<<endl;
    
   Merge(first,second);
   Display(third);
   cout<<endl<<endl;
   */
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    cout<<isLoop(first)<<endl<<endl;
    return 0;
}