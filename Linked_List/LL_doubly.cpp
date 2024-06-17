#include <iostream>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n){
    struct Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

void insert(struct Node *p, int index, int x){
    struct Node *t;
    if(index<0||index>Length(p)) return;
    if(index==0){
        t=new Node;
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++) p=p->next;
        t=new Node;
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next) p->next->prev=t; // If next node is there, only then will it be modified
        p->next=t;
    }
}

int Delete(struct Node *p, int index){
    int x=-1;
    if(index<0||index>Length(p)) return x;
    if(index==0){
        first=first->next;
        if(first) first->prev=NULL;
        x=p->data;
        delete p;
    }
    else{
        for(int i=0;i<index;i++) p=p->next;
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
    return x;
}

void Reverse(struct Node *p){
    struct Node *t;
    while(p){
        t=p->next;
        p->next=p->prev;
        p->prev=t;
        p=p->prev;
        if(p!=NULL && p->next==NULL) first=p;
    }
}

int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    cout<<"\nLength is: "<<Length(first)<<endl;
    display(first);
    cout<<endl;
    insert(first,2,25);
    display(first);
    cout<<endl;
    Delete(first,3);
    display(first);
    cout<<endl;
    Reverse(first);
    display(first);
    cout<<endl;
    return 0;
}