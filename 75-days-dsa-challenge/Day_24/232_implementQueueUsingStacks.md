# [232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) 🌟


### O(1) AMORTIZED Time solution

- **AMORTIZED**: Most of the times operations are O(1) time.sometimes it will be O(n) time.But total time for all the operations will be O(1).
- Using 2 stacks; one is used for read and another for write.

### Code

```cpp
class MyQueue{
    stack<int> input, output;
public:
    // Initialize tha data structure
    MyQueue(){}

    // Push element x to the back of the queue
    void push(int x){
        input.push(x);
    }

    // Removes the element from the front of the queue and returns it.
    int pop(){
        int temp = peek();
        output.pop();
        return temp;
    }

    // Get the front element.
    int peek(){
        if (output.empty())
        {
            while (input.empty() == false)
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    // Return whether the queue is empty.
    bool empty(){
        return (input.empty() && output.empty());
    }
};
```

---

### Do you know when we should use two stacks to implement a queue?

I was asked in the internship interview of a company two years ago.

The application for this implementation is to separate read & write of a queue in multi-processing. One of the stack is for read, and another is for write. They only interfere each other when the former one is full or latter is empty.

When there's only one thread doing the read/write operation to the stack, there will always one stack empty. However, in a multi-thread application, if we have only one queue, for thread-safety, either read or write will lock the whole queue. In the two stack implementation, as long as the second stack is not empty, push operation will not lock the stack for pop.
