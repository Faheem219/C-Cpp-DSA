#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL; // This pointer points to the first node of the linked list
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

void Insert(struct Node *p,int pos, int x){
    struct Node *t;
    if(pos<0 || pos>Count(p)) return; // Checking also that p is not null (pos is outside linked list)
    t=new Node;
    t->data=x;
    if(pos==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0; i<pos-1; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

// Inserting at last element, faster as no need to traverse the linked list:
void InsertLast(struct Node *p,int x){
    struct Node *t;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(first == NULL) first = last = t;
    else{
        last->next=t;
        last=t;
    }
}

// Inserting in a sorted list:
void SortedInsert(struct Node *p, int x){
    struct Node *t,*q=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(first==NULL) first =t;
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

// Deleting a node:
int Delete(struct Node *p, int index){
    struct Node *q;
    int x=-1;
    if(index<1 || index>Count(p)) return x;
    if(index == 1){
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}

int main(){
    struct Node *temp;
    int A[]={3,5,7,10,15};
    int c;
    create(A,5);
    Display(first);
    cout<<endl<<endl;
    Insert(first,3,9);
    Display(first);
    cout<<endl<<endl;
    InsertLast(first,17);
    Display(first);
    cout<<endl<<endl;
    SortedInsert(first,4);
    Display(first);
    cout<<endl<<endl;
    cout<<"Deleted Element: "<<Delete(first,3)<<endl;
    Display(first);
    cout<<endl<<endl;
    return 0;
}