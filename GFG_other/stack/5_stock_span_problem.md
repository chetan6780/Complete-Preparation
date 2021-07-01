# Stock Span Problem

### Statement

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days. 
(Find consecutive smaller or equal to element from left i.e. next greater to left)

### Approach

- **Brute force**: Itterate over each element and for each element Itterate from i to j i.e. left subarray and find greater element then the ans will be (index of greater element - i).
- **Efficient Approach(using Stack)**: Approch is same as [next greater element (left)](2_next_greater_element.md), we just need to do some changes.

### Changes

1. Create a stack of pair.
2. Compare with the first element of pair(grater element)
3. Push s.top().second in answer vector
4. Push pair in stack
5. Update vector with actual answer i.e. i - v[i](index of greater element)

### Pseudo code

1. Create a vector to return and stack of pair to find greater element and its index.
2. Itterate from first element to last in the vector.
   - if stack is empty greater element is -1.
   - else if stack is not empty and top.first is greater than arr[i], we **found** the greater element.push its index(second of pair) in vector.
   - else if stack is not empty and top.first is less than arr[i], we didn't find the greater element.
     - pop untill we get greater element than arr[i] or stack is empty.
     - if stack is empty there is no greater element.
     - else top.fisrt is greater element, push it's index(top.second) in the vector.
3. Push pair in the stack.
4. Update vector with correct values i.e. i-v[i]
4. Return the ans vector.

### Code

```cpp

vector<long long> stockSpan(vector<long long> arr, int n)
{
    vector<long long> v;
    stack<pair<long long, long long>> s;

    for (auto i = 0; i < n; i++)
    {
        // if stack is empty
        if (s.empty())
        {
            v.push_back(-1);
        }

        // else if stack not empty and top is greater than arr[i]
        else if (!s.empty() && s.top().first > arr[i])
        {
            v.push_back(s.top().second);
        }

        // else if stack is not empty and top is less than arr[i]
        else if (!s.empty() && s.top().first <= arr[i])
        {
            // pop untill we get greater element or stack is empty
            while (!s.empty() && s.top().first <= arr[i])
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
                v.push_back(s.top().second);
            }
        }
        // push pair in stack
        s.push(make_pair(arr[i], i));
    }

    // vector contains index of greater element to right.
    // update vector with correct values i.e. i - v[i]
    for (auto i = 0; i < n; i++)
    {
        v[i] = i - v[i];
    }

    return v;
}
```

### References

- Youtube: [link](https://www.youtube.com/watch?v=p9T-fE1g1pU&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=6)
- GFG: [link](https://www.geeksforgeeks.org/the-stock-span-problem/)
