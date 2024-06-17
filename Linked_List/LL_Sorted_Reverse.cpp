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

int isSorted(struct Node *p){
    int x=-65536;
    while(p!=NULL){
        if(p->data<x) return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

// Removing duplicates from a sorted linked list:
void RemoveDuplicate(struct Node *p){
    struct Node *q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

// Reversing a Linked List by reversing links using Sliding Pointers:
void Reverse(struct Node *p){
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

// Reversing using recursion by changing links:
void Reverse_Rec(struct Node *q,struct Node *p){
    if(p){
        Reverse_Rec(p,p->next);
        p->next=q;
    }
    else first=q;
}

// Reversing a linked list by modifying values using array:
void Reverse_Arr(struct Node *p){
    int *A,i=0;
    struct Node *q;
    q=p;
    A=new int[Count(p)];
    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;
    }
}

int main(){
    struct Node *temp;
    int A[]={3,5,7,10,15,15,15};
    int c;
    create(A,7);
    Display(first);
    cout<<endl<<endl;
    cout<<" "<<isSorted(first)<<endl;
    cout<<endl<<endl;
    RemoveDuplicate(first);
    Display(first);
    cout<<endl<<endl;
    Reverse_Arr(first);
    Display(first);
    cout<<endl<<endl;
    Reverse(first);
    Display(first);
    cout<<endl<<endl;
    Reverse_Rec(NULL,first);
    Display(first);
    cout<<endl<<endl;
    return 0;
}