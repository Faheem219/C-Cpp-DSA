#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int A[],int l,int h){
    int pivot=A[l];
    int i=l,j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j) swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;
}

void QuickSort(int A[],int l,int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main(){
    int A[]={3,7,9,10,6,5,12,4,11,12,INT32_MAX}, n=10; // Bubble sort is stable
    QuickSort(A,0,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}