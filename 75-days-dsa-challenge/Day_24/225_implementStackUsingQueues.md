# [225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)

### 2 Stack - push O(N) pop O(1)

### Code

```cpp
class MyStack {
    queue<int> q1, q2;

public:
    MyStack() { }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1 = q2;
        q2 = {};
    }

    int pop()
    {
        int res = q1.front();
        q1.pop();
        return res;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};
```

### 1 stack

```cpp

class MyStack {
    queue<int> q1;

public:
    MyStack() { }

    void push(int x)
    {
        q1.push(x);
        for (int i = 0; i < q1.size() - 1; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        int res = q1.front();
        q1.pop();
        return res;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};
```
