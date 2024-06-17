#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Queue{
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void enqueue(T value);
    bool isEmpty();
    T dequeue();
};

template <class T>
void Queue<T>::enqueue(T value){
    stack1.push(value);
}

template <class T>
bool Queue<T>::isEmpty(){
    return stack1.empty() && stack2.empty();
}

template <class T>
T Queue<T>::dequeue(){
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    int front = stack2.top();
    stack2.pop();
    return front;
}

int main() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout<<"Dequeued: "<<queue.dequeue()<<endl;
    cout<<"Dequeued: "<<queue.dequeue()<<endl;

    queue.enqueue(40);
    cout<<"Dequeued: "<<queue.dequeue()<<endl;
    cout<<"Dequeued: "<<queue.dequeue()<<endl;

    return 0;
}