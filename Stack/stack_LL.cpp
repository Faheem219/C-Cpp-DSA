#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
    struct Node *t;
    t=new Node;
    if(t==NULL) cout<<"\nStack is Full."<<endl;
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    struct Node *t;
    int x;
    if(top==NULL) cout<<"\nStack is Empty."<<endl;
    else{
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}

void Display(){
    struct Node *p;
    p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    Display();
    cout<<"\nDeleted: "<<pop()<<endl;
    return 0;
}