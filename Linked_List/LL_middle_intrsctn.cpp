#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL, *second = NULL;

void create(int A[], int n)
{
    struct Node *t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    struct Node *t;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int Count(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

// Finding middle element by scanning two times, first for length, then accessing:
int middle1(struct Node *p)
{
    int x = 0, len = 0;
    len = Count(p);
    for (int i = 0; i < (len / 2); i++) p = p->next;
    x = p->data;
    return x;
}

// Finding middle element by scanning one time by using tailing pointer:
int middle2(struct Node *p)
{
    int x = 0;
    struct Node *q = p;
    while (q)
    {
        q = q->next;
        if (q) q = q->next;
        if (q) p = p->next;
    }
    x = p->data;
    return x;
}

// Finding middle element by making use of stack and storing addresses of all nodes:
#include <stack> // Include the <stack> header file
int middle3(struct Node *p)
{
    stack<struct Node *> s; // Use the 'std::' namespace prefix
    while (p)
    {
        s.push(p);
        p = p->next;
    }
    int len = s.size();
    for (int i = 0; i < len / 2; i++)
    {
        s.pop();
    }
    return s.top()->data;
}

// Finding the intersection point of two linked lists using stacks:
struct Node *findIntersection(struct Node *head1, struct Node *head2)
{
    stack<struct Node *> stack1, stack2;

    // Push all nodes of the first linked list into stack1
    while (head1)
    {
        stack1.push(head1);
        head1 = head1->next;
    }

    // Push all nodes of the second linked list into stack2
    while (head2)
    {
        stack2.push(head2);
        head2 = head2->next;
    }

    struct Node *intersection = NULL;

    // Pop nodes from the stacks until the top nodes are different
    while (!stack1.empty() && !stack2.empty() && stack1.top() == stack2.top())
    {
        intersection = stack1.top();
        stack1.pop();
        stack2.pop();
    }

    return intersection;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15}, B[] = {2, 4, 6, 8, 10};
    create(A, 5);
    create2(B, 5);
    cout << endl;
    Display(first);
    cout << endl << middle1(first) << endl;
    cout << endl << middle2(first) << endl;
    cout << endl << middle3(first) << endl;
    // Call the findIntersection function in the main function
    struct Node *intersection = findIntersection(first, second);
    if (intersection)
    {
        cout << "Intersection point: " << intersection->data << endl;
    }
    else
    {
        cout << "No intersection point found." << endl;
    }
    return 0;
}
