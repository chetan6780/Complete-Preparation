# Maximum Area Histogram

### Statement

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.

### Prerequisite

1. You should know nearest smaller element to left and right ([NSL](3_nearest_smaller_element.md) & [NSR](3_nearest_smaller_element.md)).
2. This problem is based on Stock Span Problem which you can refer [here](5_stock_span_problem.md). The NSL and NSR are modified to get INDEX of smaller element.

### Pseudo code

1. Get the index of nearest smallest element from righ. Modified NSR.
2. Get the index of nearest smallest element from left. Modified NSL.
3. width = right[i] - left[i] - 1
4. Area = width \* arr[i]
5. return maximum area.

### Code

```cpp

// get the nearest smallest element INDEX from left
vector<long long> NSL(long long arr[], int n)
{
    vector<long long> ans;
    stack<pair<long long, int>> st;

    for (int i = 0; i < n; i++)
    {
        long long val = arr[i];

        while (!st.empty() && st.top().first >= val)
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top().second);

        st.push({val, i});
    }
    return ans;
}

// get the nearest smallest element INDEX from right
vector<long long> NSR(long long arr[], int n)
{
    vector<long long> ans;
    stack<pair<long long, int>> st;

    for (int i = n - 1; i >= 0; i--)
    {
        long long val = arr[i];

        while (!st.empty() && st.top().first >= val)
            st.pop();
        if (st.empty())
            ans.push_back(n);
        else
            ans.push_back(st.top().second);

        st.push({val, i});
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// get the maximum area histogram
long long MAH(long long arr[], int n)
{
    vector<long long> left = NSL(arr, n), right = NSR(arr, n);
    vector<long long> wArr;

    long long maxA = INT_MIN;

    for (int i = 0; i < n; i++)
        wArr.push_back(right[i] - left[i] - 1);

    for (int i = 0; i < n; i++)
        maxA = max(maxA, wArr[i] * arr[i]);

    return maxA;
}

```

### References

- Youtube: [link](https://www.youtube.com/watch?v=J2X70jj_I1o&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=8)
- GFG: [link](https://www.geeksforgeeks.org/largest-rectangle-under-histogram/)
