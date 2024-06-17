#include <iostream>
using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL,*poly2=NULL;

void Create1(){
    struct Node *t,*last;
    int num;
    cout<<"\nEnter number of terms: ";
    cin>>num;
    cout<<"\nEnter each term (coeff,exp):\n"<<endl;
    for(int i=0;i<num;i++){
        t=new Node;
        cin>>t->coeff>>t->exp;
        t->next=NULL;
        if(poly==NULL){
            poly=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
}

void Create2(){
    struct Node *t,*last;
    int num;
    cout<<"\nEnter number of terms: ";
    cin>>num;
    cout<<"\nEnter each term (coeff,exp):\n"<<endl;
    for(int i=0;i<num;i++){
        t=new Node;
        cin>>t->coeff>>t->exp;
        t->next=NULL;
        if(poly2==NULL){
            poly2=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
}

void Display(struct Node *p){
    cout<<"\n";
    while(p){
        cout<<p->coeff<<"x"<<p->exp<<" + ";
        p=p->next;
    }
    cout<<"\n";
}

long eval(struct Node *p, int x){
    long val=0;
    while(p){
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
} 

struct Node* AddPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* last = NULL;
    while (poly1 && poly2) {
        struct Node* temp = new Node;
        temp->next = NULL;

        if (poly1->exp > poly2->exp) {
            temp->coeff = poly1->coeff;
            temp->exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            temp->coeff = poly2->coeff;
            temp->exp = poly2->exp;
            poly2 = poly2->next;
        } else {
            temp->coeff = poly1->coeff + poly2->coeff;
            temp->exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (result == NULL) {
            result = last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    while (poly1) {
        struct Node* temp = new Node;
        temp->coeff = poly1->coeff;
        temp->exp = poly1->exp;
        temp->next = NULL;

        if (result == NULL) {
            result = last = temp;
        } else {
            last->next = temp;
            last = temp;
        }

        poly1 = poly1->next;
    }
    while (poly2) {
        struct Node* temp = new Node;
        temp->coeff = poly2->coeff;
        temp->exp = poly2->exp;
        temp->next = NULL;

        if (result == NULL) {
            result = last = temp;
        } else {
            last->next = temp;
            last = temp;
        }

        poly2 = poly2->next;
    }
    return result;
}

int main(){
    struct Node *Add;
    Create1();
    Display(poly);
    cout<<"\n"<<eval(poly,2)<<"\n"<<endl;
    Create2();
    Add=AddPolynomials(poly,poly2);
    Display(Add);
    cout<<"\n"<<eval(Add,2)<<"\n"<<endl;
    return 0;
}