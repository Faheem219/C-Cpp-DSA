#include <iostream>
#define SIZE 10
using namespace std;

int Hash(int key){
    return key%SIZE;
}

int quadraticProbe(int H[], int key){
    int index=Hash(key);
    int i=0;
    while(H[(index+i*i)%SIZE]!=0) i++; // TO CONVERT INTO QUADRATIC PROBING JUST DO index+i*i EVERYWHERE
    return (index+i*i)%SIZE;
}

void Insert(int H[],int key){
    int index=Hash(key);

    if(H[index]!=0) index=quadraticProbe(H,key);
    H[index]=key;
}

int Search(int H[],int key){
    int index=Hash(key);
    int i=0;
    while(H[(index+i*i)%SIZE]!=key){ // Hash function for linear probing
        i++;
        if(H[(index+i*i)%SIZE]==0) return -1;
    }
    return (index+i*i)%SIZE;
}

int main(){
    int HT[10]={0};

    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,45);

    cout<<"\nSearch result: "<<Search(HT,5)<<endl;

    return 0;
}