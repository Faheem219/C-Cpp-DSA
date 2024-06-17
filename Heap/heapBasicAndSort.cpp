#include <iostream>
using namespace std;

void Insert(int H[], int n){
    int i=n, temp;
    temp=H[i];
    while(i>1 && temp>H[i/2]){
        H[i]=H[i/2];
        i=i/2;
    }
    H[i]=temp;
}

void swap(int *A, int *B){
    int temp=*A;
    *A=*B;
    *B=temp;
}

int Delete(int A[],int n){
    int i,j,x,temp,val;
    val=A[1];
    A[1]=A[n];
    A[n]=val;
    i=1; j=i*2;

    while(j<n-1){
        if(A[j+1]>A[j]) j=j+1;
        if(A[i]<A[j]){
            swap(&A[i],&A[j]);
            i=j;
            j=2*j;
        }
        else break;
    }
    return val;
}

void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(&A[i],&A[j]);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}

void Print(int vec[], int n){
    cout<<": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int main(){
    int H[]={0,10,20,30,25,5,40,35};
    int HH[]={10,20,30,25,5,40,35};

    for(int i=2;i<=7;i++) Insert(H,i);

    cout<<endl;
    for(int i=1;i<=7;i++) cout<<H[i]<<" ";
    cout<<endl;

    for(int i=7;i>1;i--) cout<<"\nDeleted value is: "<<Delete(H,i)<<endl;

    cout<<endl;
    for(int i=1;i<=7;i++) cout<<H[i]<<" ";
    cout<<endl;

    Heapify(HH,7);
    Print(HH,7);

    return 0;
}