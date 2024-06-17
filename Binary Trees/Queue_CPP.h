using namespace std;

template <class T>
class Node{
public:
    Node *lchild;
    T data;
    Node *rchild;
};

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
    bool isEmpty(){return front==rear;}
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
    T x=NULL;
    if(front==rear) cout<<"\nQueue is empty."<<endl;
    else{
        x=Q[front+1];
        front++;
    }
    return x;
}