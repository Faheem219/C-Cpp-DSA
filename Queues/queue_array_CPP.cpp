#include <iostream>
using namespace std;

template <class T>
class Queue{
private:
    int front;
    int rear;
    int size;
    T *Q;
public:
    Queue(){front=rear=-1;size=10;Q=new T[size];}
    Queue(int size){front=rear=-1;this->size=size;Q=new T[this->size];}
    void enqueue(T x);
    T dequeue();
    void Display();
};

template <class T>
void Queue<T>::enqueue(T x){
    if(rear==size-1) cout<<"\nQueue Full."<<endl;
    else{
        rear++;
        Q[rear]=x;
    }
}

template <class T>
T Queue<T>::dequeue(){
    T x=-1;
    if(front==rear) cout<<"\nQueue is empty."<<endl;
    else{
        x=Q[front+1];
        front++;
    }
    return x;
}

template <class T>
void Queue<T>::Display(){
    for(int i=front+1;i<=rear;i++) cout<<Q[i]<<" ";
    cout<<endl;
}

int main(){
    Queue<float> q(5);
    q.enqueue(10.5);
    q.enqueue(20.5);
    q.enqueue(30.5);
    q.Display();
    return 0;
}