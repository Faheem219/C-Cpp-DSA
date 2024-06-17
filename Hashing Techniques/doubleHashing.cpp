#include <iostream>
#define SIZE 10
#define PRIME 7
using namespace std;

int Hash(int key){
    return key%SIZE;
}

int primeHash(int key){
    return PRIME-(key%PRIME);
}

int doubleHash(int H[],int key){
    int i=0;
    while(H[(Hash(key)+i*primeHash(key))%SIZE]!=0) i++;
    return (Hash(key)+i*primeHash(key))%SIZE;
}

void Insert(int H[],int key){
    int index=Hash(key);

    if(H[index]!=0) index=doubleHash(H,key);
    H[index]=key;
}

int Search(int H[],int key){
    int index=Hash(key);
    int i=0;
    while(H[(Hash(key)+i*primeHash(key))%SIZE]!=key){ // Hash function for linear probing
        i++;
        if(H[(Hash(key)+i*primeHash(key))%SIZE]==0) return -1;
    }
    return (Hash(key)+i*primeHash(key))%SIZE;
}

int main(){
    int HT[10]={0};

    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,45);

    cout<<"\nSearch result: "<<Search(HT,35)<<endl;

    return 0;
}