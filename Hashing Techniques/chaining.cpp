#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

int Hash(int key) {
    return (key/10)%10; // we can change the hash function based on our needs
}

void SortedInsert(struct Node **H, int x){
    int hID=Hash(x);
    struct Node *t,*q=nullptr;
    t=new Node;
    t->data=x;
    t->next=nullptr;
    if(H[hID]==nullptr) H[hID]=t;
    else{
        struct Node *p=H[hID],*q=H[hID];
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        // If insert position is the first only
        if(p==H[hID]){
            t->next=H[hID];
            H[hID]=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

int Search(struct Node **H,int key){
    int hID=Hash(key);
    struct Node *p=H[hID];
    while(p){
        if(key==p->data) return p->data;
        p=p->next;
    }
    return -1;
}

int main(){
    struct Node *HT[10];
    for(int i=0;i<10;i++){
        HT[i]=nullptr;
    }
    SortedInsert(HT,2);
    SortedInsert(HT,12);
    SortedInsert(HT,22);
    SortedInsert(HT,42);
    cout<<"\nSearch result: "<<Search(HT,2)<<endl;
    return 0;
}