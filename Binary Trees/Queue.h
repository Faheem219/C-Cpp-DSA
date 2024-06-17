using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int size;
    int front;
    int rear;
    Node* *Q;
};

void Create(struct Queue *q, int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new Node*[q->size];
}

void enqueue(struct Queue *q,struct Node* x){
    if(q->rear==q->size-1) cout<<"\nQueue is full."<<endl;
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

struct Node* dequeue(struct Queue *q){
    struct Node* x=NULL;
    if(q->front==q->rear) cout<<"\nQueue is empty"<<endl;
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front==q.rear;
}