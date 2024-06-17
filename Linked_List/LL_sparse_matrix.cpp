#include <iostream>
using namespace std;

struct Node {
    int col;
    int val;
    struct Node* next;
}*A;

void Create(struct Node* p) { // Pass the pointer by reference
    int n;
    cout << "Enter rows: ";
    cin >> n;
    A = new Node[n];
    p=A;
    cout << "Enter non-zero elements (col, val):\n" << endl;
    for (int i = 0; i < n; i++) {
        cin >> p[i].col >> p[i].val;
        if (i < n - 1) {
            p[i].next = &p[i + 1];
        } else {
            p[i].next = nullptr;
        }
    }
}

void Display(struct Node* p) {
    int n,m;
    cout<<"\nEnter rows and columns: ";
    cin>>n>>m;
    cout<<"\nElements are:\n"<<endl;
    for(int i=0;i<n;i++){
        p=&A[i];
        for(int j=0;j<m;j++){
            if(j==p->col){
                cout<<p->val<<" ";
                p=p->next;
            }
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

struct Node* AddSparseMatrices(struct Node* p1, struct Node* p2) {
    struct Node* p3 = nullptr;
    struct Node* last = nullptr;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->col < p2->col) {
            if (p3 == nullptr) {
                p3 = last = new Node;
            } else {
                last->next = new Node;
                last = last->next;
            }
            last->col = p1->col;
            last->val = p1->val;
            last->next = nullptr;
            p1 = p1->next;
        } else if (p1->col > p2->col) {
            if (p3 == nullptr) {
                p3 = last = new Node;
            } else {
                last->next = new Node;
                last = last->next;
            }
            last->col = p2->col;
            last->val = p2->val;
            last->next = nullptr;
            p2 = p2->next;
        } else {
            if (p3 == nullptr) {
                p3 = last = new Node;
            } else {
                last->next = new Node;
                last = last->next;
            }
            last->col = p1->col;
            last->val = p1->val + p2->val;
            last->next = nullptr;
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != nullptr) {
        last->next = new Node;
        last = last->next;
        last->col = p1->col;
        last->val = p1->val;
        last->next = nullptr;
        p1 = p1->next;
    }

    while (p2 != nullptr) {
        last->next = new Node;
        last = last->next;
        last->col = p2->col;
        last->val = p2->val;
        last->next = nullptr;
        p2 = p2->next;
    }

    return p3;
}

int main() {
    struct Node* p1 = nullptr;
    struct Node* p2 = nullptr;
    struct Node* p3 = nullptr;

    cout << "Creating Sparse Matrix 1:" << endl;
    Create(p1);

    cout << "Creating Sparse Matrix 2:" << endl;
    Create(p2);

    cout << "Displaying Sparse Matrix 1:" << endl;
    Display(p1);

    cout << "Displaying Sparse Matrix 2:" << endl;
    Display(p2);

    p3 = AddSparseMatrices(p1, p2);

    cout << "Displaying Sum of Sparse Matrices:" << endl;
    Display(p3);

    return 0;
}