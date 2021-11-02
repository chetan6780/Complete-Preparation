# Next Greater Element

### Statement

Find next greater element from the **left**.

### Approach

- **Brute force**: Itterate over each element and for each element Itterate from i to j i.e. left subarray and find greater element.
- **Efficient Approach(using Stack)**: Approch is same as [next greater element (right)](1_next_greater_element.md) we just need to do some changes.

### Changes

1. Traverse from left to right.
2. Don't reverse the vector.

### Pseudo code

1. Create a vector to return and stack to find greater element efficiently.
2. Itterate from first element to last in the vector.
   - if stack is empty greater element is -1.
   - else if stack is not empty and top is greater than arr[i], we **found** the greater element.
   - else if stack is not empty and top is less than arr[i], we didn't find the greater element.
     - pop untill we get greater element than arr[i] or stack is empty.
     - if stack is empty there is no greater element.
     - else top is greater element, push it in the vector.
3. Push element in the stack.
4. Return the ans vector.

### Code

```cpp

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> v;
    stack<long long> s;

    for (auto i = 0; i < n; i++)
    {
        // if stack is empty
        if (s.empty())
        {
            v.push_back(-1);
        }

        // else if stack not empty and top is greater than arr[i]
        else if (!s.empty() && s.top() > arr[i])
        {
            v.push_back(s.top());
        }

        // else if stack is not empty and top is less than arr[i]
        else if (!s.empty() && s.top() <= arr[i])
        {
            // pop untill we get greater element or stack is empty
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
            // if stack is empty else push top()
            if (s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        // push in stack
        s.push(arr[i]);
    }

    return v;
}
```

### References

- Youtube: [link](https://www.youtube.com/watch?v=T5s96ynzArg&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=3)
