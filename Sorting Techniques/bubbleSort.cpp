#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Bubble(int A[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]) swap(&A[j],&A[j+1]);
        }
    }
}

void BubbleDesc(int A[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]<A[j+1]) swap(&A[j],&A[j+1]);
        }
    }
}

void BubbleAdaptive(int A[], int n){
    int flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}

int main(){
    int A[]={3,7,9,10,6,5,12,4,11,12}, n=10; // Bubble sort is stable
    BubbleDesc(A,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}