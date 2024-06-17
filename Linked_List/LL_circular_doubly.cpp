#include <iostream>
using namespace std;

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
}* Head = NULL;

void Display(struct Node* p) {
    if (p == NULL) return;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != Head);
}

int Length(struct Node* p) {
    if (p == NULL) return 0;
    int len = 0;
    do {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

void Insert(struct Node* p, int index, int x) {
    struct Node* t;
    if (index < 0 || index > Length(p)) return;
    if (index == 0) {
        t = new Node;
        t->data = x;
        if (Head == NULL) { // If there is linked list was empty
            Head = t;
            Head->prev = Head;
            Head->next = Head;
        }
        else {
            t->prev = Head->prev;
            t->next = Head;
            Head->prev->next = t;
            Head->prev = t;
            Head = t;
        }
    }
    else {
        for (int i = 0; i < index - 1; i++) p = p->next;
        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
    }
}

void Create(int arr[], int n) {
    if (n <= 0) return;
    Head = new Node;
    Head->data = arr[0];
    Head->prev = Head;
    Head->next = Head;
    struct Node* last = Head;
    for (int i = 1; i < n; i++) {
        struct Node* t = new Node;
        t->data = arr[i];
        t->prev = last;
        t->next = last->next;
        last->next->prev = t;
        last->next = t;
        last = t;
    }
}

int Delete(struct Node *p,int index){
    struct Node *t;
    int x=-1;
    if(index<0 || index>Length(p)) return x;
    if(index==0){
        if(Head->next==Head){
            x=Head->data;
            delete Head;
            Head=NULL;
        }
        else{
            while(p->next!=Head) p=p->next;
            x=Head->data;
            p->next=Head->next;
            Head->next->prev=p;
            delete Head;
            Head=p->next;
        }
    }
    else{
        for(int i=0;i<index-1;i++) p=p->next;
        t=p->next;
        x=t->data;
        p->next=t->next;
        t->next->prev=p;
        delete t;
    }
    return x;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    Create(arr, 5);
    cout<<endl;
    Display(Head);
    cout<<endl;
    Insert(Head, 0, 0);
    Display(Head);
    cout<<endl;
    Delete(Head, 2);
    Display(Head);
    cout<<endl;
    return 0;
}