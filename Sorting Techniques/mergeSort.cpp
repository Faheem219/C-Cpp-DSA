#include <iostream>
using namespace std;

// Merging two lists from a single array:
void Merge(int A[], int l, int mid, int h){
    int i=l,j=mid+1,k=l;
    int B[100];

    while(i<=mid && j<=h){
        if(A[i]<A[j]) B[k++]=A[i++];
        else B[k++]=A[j++];
    }
    for(;i<=mid;i++) B[k++]=A[i];
    for(;j<=h;j++) B[k++]=A[j];

    for(int i=l;i<=h;i++) A[i]=B[i];
}

// 2-way merge sort (Time complexity: O(n*log n)):
void iMergeSort(int A[], int n){
    int p,l,h,mid,i;
    for(p=2;p<=n;p*=2){
        for(i=0;i+p-1<n;i+=p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n) Merge(A,0,p/2-1,n-1);
}

// Recursive merge sort will first break the array down into halfs until they're sorted (basically till 
// we reach a 1 element list which is guaranteed to be sorted) and then merge the whole list
// The tracing tree of this merge represents a stict binary tree of height log n.
// The merging is done in postorder, ie, at the returning time of recursive calls
void rMergeSort(int A[], int l, int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        rMergeSort(A,l,mid);
        rMergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

int main(){
    int A[]={3,7,9,10,6,5,12,4,11,12}, n=10; 
    // iMergeSort(A,n);
    rMergeSort(A,0,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}