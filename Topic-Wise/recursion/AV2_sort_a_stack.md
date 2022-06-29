# Sort a stack using recursion

### Algorithm

1. Insert function.

    - If stack is empty _OR_ temp is the largest element, then we can directly insert it at last position.
    - else we need to insert temp at it's correct position.
    - Get the top element of the stack and reduce its size by 1.
    - Insert temp recursively.
    - finally insert value which is poped.

2. Sort function.
    - If stack contains only one element then it is sorted iteself.Return.
    - Get the last element of the stack.
    - Reduce the size of input for recursion.
    - Recursively sort remaining the stack which has one element less.
    - Insert the element in sorted stack at its right position.

### Code

```cpp

void inserT(stack<int> &s, int temp)
{
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();

    inserT(s, temp);
    s.push(val);
}

void sortStack(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int temp = s.top();
    s.pop();

    sortStack(s);
    inserT(s, temp);
}
```

### References

-   GFG: [Sort a stack using recursion](https://www.geeksforgeeks.org/sort-a-stack-using-recursion/)
-   YouTube:
<iframe width="560" height="315" src="https://www.youtube.com/embed/oCcUNRMl7dA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
