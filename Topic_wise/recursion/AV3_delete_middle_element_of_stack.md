# Delete middle element of a stack

### Algorithm

1. Delete function.

    - if k is 1 then delete top element.
    - else store the top element in a temp variable.
    - Reduce size of input for recursion.
    - Call the function again with reduced input.
    - Put the temp variable back on the stack.

2. midDelete function.(main)
    - Base condition - If stack is empty, return.
    - Get the middle element
    - Delete the middle element.

### Code

```cpp
void del(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();

    del(s, k - 1);
    s.push(temp);
}

void midDelete(stack<int> s, int n)
{
    if (s.empty())
        return;

    int k = (n / 2) + 1;
    del(s, k);
}
```

### References

-   GFG: [Delete middle element of a stack](https://www.geeksforgeeks.org/delete-middle-element-stack/)
-   YouTube:
<iframe width="560" height="315" src="https://www.youtube.com/embed/oCcUNRMl7dA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
