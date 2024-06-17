#include <iostream>
using namespace std;

void ShellSort(int A[], int n){
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            temp=A[i];
            j=i-gap;
            while(j>0 && A[j]>temp){
                A[j+gap]=A[j];
                j-=gap;
            }
            A[j+gap]=temp;
        }
    }
}

int main(){
    int A[]={3,7,9,10,6,5,12,4,11,12}, n=10; // Insertion sort is stable
    ShellSort(A,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}