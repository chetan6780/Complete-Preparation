# Reverse the stack

### Algorithm

1. Insert function.

    - if the stack is empty, push the element.
    - Get the top element.
    - Recursively call the insert function with reduced elements.
    - push the temp element.

2. reverse function.
    - Base condition. If stack has only one element then return.
    - Get the top element.
    - Recursively call the reverse function with Reduced input.
    - insert the temp element to the stack.

### Code

```cpp

void inserT(stack<int> &s, int ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }

    int temp = s.top();
    s.pop();

    inserT(s, ele);
    s.push(temp);
}

void reverse(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int temp = s.top();
    s.pop();

    reverse(s);
    inserT(s, temp);
}
```

### References

-   GFG: [Reverse a stack using recursion](https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/)
-   YouTube:
<iframe width="560" height="315" src="https://www.youtube.com/embed/8YXQ68oHjAs" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
