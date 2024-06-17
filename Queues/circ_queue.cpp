#include <iostream>
using namespace std;

template <class T>
class CircQueue{
private:
    int front;
    int rear;
    int size;
    T *Q;
public:
    CircQueue(){front=rear=0;size=10;Q=new T[size];}
    CircQueue(int size){front=rear=0;this->size=size;Q=new T[this->size];}
    void enqueue(T x);
    T dequeue();
    void Display();
};

template <class T>
void CircQueue<T>::enqueue(T x){
    if(((rear+1)%size)==front) cout<<"\nQueue Full."<<endl;
    else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

template <class T>
T CircQueue<T>::dequeue(){
    T x=-1;
    if(front==rear) cout<<"\nQueue is empty."<<endl;
    else{
       front=(front+1)%size;
        x=Q[front];
    }
    return x;
}

template <class T>
void CircQueue<T>::Display(){
    int i=front+1;
    do{
        cout<<Q[i]<<" ";
        i=(i+1)%size;
    }while(i!=(rear+1)%size);
    cout<<endl;
}

int main(){
    CircQueue<float> q(5);
    q.enqueue(10.5);
    q.enqueue(20.5);
    q.enqueue(30.5);
    q.enqueue(40.5);
    q.enqueue(50.5);
    q.enqueue(60.5);
    q.Display();
    return 0;
}