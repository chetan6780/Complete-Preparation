// Implimentation of stack using array -------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX];

    Stack()
    {
        top = -1;
    }

    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

// Implimentation of stack using Linked List ------------------------------------------------

struct StackNode
{
    int data;
    struct StackNode *next;
};

struct StackNode *newNode(int data)
{
    struct StackNode *stackNode = new StackNode;
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode *root)
{
    return !root;
}

void push(struct StackNode **root, int data)
{
    struct StackNode *stackNode = newNode(data);

    stackNode->next = *root;
    *root = stackNode;

    cout << data << " pushed to stack\n";
}

int pop(struct StackNode **root)
{
    if (isEmpty(*root))
        return INT_MIN;

    struct StackNode *temp = *root;
    *root = (*root)->next;

    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(struct StackNode *root)
{
    if (isEmpty(root))
        return INT_MIN;

    return root->data;
}
