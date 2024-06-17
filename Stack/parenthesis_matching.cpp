#include <iostream>
using namespace std;

struct Node{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x){
    struct Node *t;
    t=new Node;
    if(t==NULL) cout<<"\nStack is Full."<<endl;
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

char pop(){
    struct Node *t;
    char x;
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

bool isBalanced(char *exp){
    for(int i=0;exp[i]!=0;i++){
        if(exp[i]=='(') push(exp[i]);
        else if(exp[i]==')'){
            if(top==NULL) return 0;
            pop();
        }
    }
    if(top==NULL) return 1;
    return 0;
}

bool isBalanced2(char *exp){
    char x;
    for(int i=0;exp[i]!=0;i++){
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{') push(exp[i]);
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}'){
            if(top==NULL) return 0;
            x=pop();
            if(x<50){
                if(exp[i]!=x+1) return 0;
            }
            else{
                if(exp[i]!=x+2) return 0;
            }
        }
    }
    if(top==NULL) return 1;
    return 0;
}

int main(){
    //char *exp="((a+b)*(c-d))";
    char *exp2="{([a+b]*[c-d)]/e}";
    //cout<<"\n"<<isBalanced(exp)<<endl;
    cout<<"\n"<<isBalanced2(exp2)<<endl;
    return 0;
}