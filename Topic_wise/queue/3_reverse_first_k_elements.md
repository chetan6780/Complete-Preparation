# Reverse First K elements of Queue

### Statement

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

### Algorithm

1. Check for invalid k or queue 
2. Push the first K elements into a Stack.
3. Enqueue the contents of stack at the back of the queue.
4. Remove the remaining elements and enqueue them at the end of the Queue.
5. Return the queue.

### Code

```cpp

queue<int> modifyQueue(queue<int> q, int k)
{
    // invalid k or empty queue
    if (q.empty() == true || k > q.size() || k <= 0)
        return q;

    stack<int> st;

    // Push the first K elements into a Stack
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // Enqueue the contents of stack at the back of the queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // Remove the remaining elements and enqueue them at the end of the Queue
    for (int i = 0; i < q.size() - k; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // return queue
    return q;
}

```

### Complexity: O(n+k)

### References

- GFG Problem: [link](https://www.geeksforgeeks.org/reversing-first-k-elements-queue/)
