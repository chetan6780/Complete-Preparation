# Maximum of minimum for every window size

### Statement
Given an integer array of size n, find the maximum of the minimum’s of every window size in the array. Note that window size varies from 1 to n.

### Prerequisite
1. Next Greater Element (right)[2_next_greater_element.md]

### Code

```cpp

vector<int> maxOfMin(int arr[], int n)
{
    stack<int> s;
    vector<int> v;

    int left[n + 1];
    int right[n + 1];

    for (int i = 0; i < n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            left[i] = s.top();

        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            right[i] = s.top();

        s.push(i);
    }

    int ans[n + 1];
    for (int i = 0; i <= n; i++)
        ans[i] = 0;

    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 1;

        ans[len] = max(ans[len], arr[i]);
    }

    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);

    for (int i = 1; i <= n; i++)
        v.push_back(ans[i]);

    return v;
}

```

### References
- GFG: [link](https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/)