#include <bits/stdc++.h>
using namespace std;

// Array Implementation of Queue ----------------------------------------------------------------

// class Queue
// {
// public:
//     int front, rear, size;
//     unsigned capacity;
//     int *array;
// };

// Queue *createQueue(unsigned capacity)
// {
//     Queue *queue = new Queue();
//     queue->capacity = capacity;
//     queue->front = queue->size = 0;
//     queue->rear = capacity - 1; // This is important, see the enqueue
//     queue->array = new int[(queue->capacity * sizeof(int))];
//     return queue;
// }

// int isFull(Queue *queue)
// {
//     return (queue->size == queue->capacity);
// }

// int isEmpty(Queue *queue)
// {
//     return (queue->size == 0);
// }

// void enqueue(Queue *queue, int item)
// {
//     if (isFull(queue))
//         return;
//     queue->rear = (queue->rear + 1) % queue->capacity;
//     queue->array[queue->rear] = item;
//     queue->size++;

//     cout << item << " enqueued to queue\n";
// }

// int dequeue(Queue *queue)
// {
//     if (isEmpty(queue))
//         return INT_MIN;
//     int item = queue->array[queue->front];
//     queue->front = (queue->front + 1) % queue->capacity;
//     queue->size--;
//     return item;
// }

// int front(Queue *queue)
// {
//     if (isEmpty(queue))
//         return INT_MIN;
//     return queue->array[queue->front];
// }

// int rear(Queue *queue)
// {
//     if (isEmpty(queue))
//         return INT_MIN;
//     return queue->array[queue->rear];
// }

// Queue Implementation using stack ----------------------------------------------------------------
// Method 1 (By making enQueue operation costly)
struct Queue
{
    stack<int> s1, s2;

    void enQueue(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue()
    {
        if (s1.empty())
        {
            cout << "Q is Empty";
            exit(0);
        }

        int x = s1.top();
        s1.pop();
        return x;
    }
};

// Method 2 (By making deQueue operation costly)

struct Queue
{
    stack<int> s1, s2;

    void enQueue(int x)
    {
        s1.push(x);
    }

    int deQueue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Q is empty";
            exit(0);
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }
};
