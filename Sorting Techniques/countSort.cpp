#include <iostream>
using namespace std;

int findMax(int A[], int n){
    int max=INT32_MIN;
    for(int i=0;i<n;i++){
        if(A[i]>max) max=A[i];
    }
    return max;
}

void CountSort(int A[],int n){
    int i,j,*C,max;
    max=findMax(A,n);
    C=new int[max+1];
    for(i=0;i<max+1;i++){
        C[i]=0;
    }
    for(i=0;i<n;i++){
        C[A[i]]++;
    }
    i=0;j=0;
    while(j<max+1){
        if(C[j]>0){
            A[i++]=j;
            C[j]--;
        }
        else j++;
    }
}

int main(){
    int A[]={3,7,9,10,6,5,12,4,11,12}, n=10;
    CountSort(A,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}