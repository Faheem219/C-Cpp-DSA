#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Selection(int A[],int n){
    int min_id;
    for(int i=0;i<n-1;i++){
        min_id=i;
        for(int j=i;j<n;j++){
            if(A[j]<A[min_id]) min_id=j;
        }
        if(min_id!=i) swap(&A[min_id],&A[i]);
    }
}

void SelectionDesc(int A[],int n){
    int max_id;
    for(int i=0;i<n-1;i++){
        max_id=i;
        for(int j=i;j<n;j++){
            if(A[j]>A[max_id]) max_id=j;
        }
        if(max_id!=i) swap(&A[max_id],&A[i]);
    }
}

int main(){
    int A[]={3,7,9,10,6,5,12,4,11,12}, n=10; // Bubble sort is stable
    SelectionDesc(A,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}