#include <iostream>
using namespace std;

void DFS(int G[][7],int start, int n){
    static int visited[7]={0};
    if(visited[start]==0){
        cout<<start<<" ";
        visited[start]=1;
        for(int j=1;j<n;j++){
            if(G[start][j]==1 && visited[j]==0) DFS(G,j,n);
        }
    }
}

int main(){
    // Representation using adjacency matrix:
    int G[7][7]={
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    cout<<endl;
    DFS(G,4,7);
    cout<<endl;

    return 0;
}