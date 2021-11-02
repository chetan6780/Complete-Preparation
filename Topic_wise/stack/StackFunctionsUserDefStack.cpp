// Evaluate value of a postfix expression
#include <bits/stdc++.h>

using namespace std;

// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// Stack Operations
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    if (!stack->array)
        return NULL;

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

int evaluatePostfix(char *exp)
{
    struct Stack *stack = createStack(strlen(exp));
    int i;

    if (!stack)
        return -1;

    for (i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');

        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}

// Implimentation of stack using Queue ----------------------------------------------------------------
// Method 1 (By making push operation costly)

// class Stack
// {
//     queue<int> q1, q2;
//     int curr_size;

// public:
//     Stack()
//     {
//         curr_size = 0;
//     }

//     void push(int x)
//     {
//         curr_size++;

//         q2.push(x);

//         while (!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         // swap the names of two queues
//         queue<int> q = q1;
//         q1 = q2;
//         q2 = q;
//     }

//     void pop()
//     {

//         if (q1.empty())
//             return;
//         q1.pop();
//         curr_size--;
//     }

//     int top()
//     {
//         if (q1.empty())
//             return -1;
//         return q1.front();
//     }

//     int size()
//     {
//         return curr_size;
//     }
// };

// Method 2 (By making pop operation costly)

// class Stack
// {
//     queue<int> q1, q2;
//     int curr_size;

// public:
//     Stack()
//     {
//         curr_size = 0;
//     }

//     void pop()
//     {
//         if (q1.empty())
//             return;

//         while (q1.size() != 1)
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         q1.pop();
//         curr_size--;

//         // swap the names of two queues
//         queue<int> q = q1;
//         q1 = q2;
//         q2 = q;
//     }

//     void push(int x)
//     {
//         q1.push(x);
//         curr_size++;
//     }

//     int top()
//     {
//         if (q1.empty())
//             return -1;

//         while (q1.size() != 1)
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         int temp = q1.front();

//         q1.pop();

//         q2.push(temp);

//         // swap the two queues names
//         queue<int> q = q1;
//         q1 = q2;
//         q2 = q;
//         return temp;
//     }

//     int size()
//     {
//         return curr_size;
//     }
// };