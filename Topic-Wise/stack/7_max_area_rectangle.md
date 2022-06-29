# Max Area Rectangle

### Statement

Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.

### Prerequisite

1. This problem is based on maximum area histogram Problem which you can refer from [here](6_maximum_area_of_histogram.md).

### Pseudo code

1. We convert the 2D array in 1D array to solve this problem with the help of maximum area of histogram problem.
2. We copy first row as it is in new vector.
3. From 2nd row(index = 1),For each row, if element is 1 we add it to previous element of vector else it is 0 so we assign 0 to that element of vector(hight = 0). And calculate its MAH.
4. Update maxArea for every row.
5. Return maximum area.

### Code

```cpp

// get the nearest smallest element INDEX from left
vector<int> NSL(int arr[], int n)
{
    vector<int> ans;
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        int val = arr[i];

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
vector<int> NSR(int arr[], int n)
{
    vector<int> ans;
    stack<pair<int, int>> st;

    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i];

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

// get the maximum area of histogram
int MAH(int arr[], int n)
{
    vector<int> left = NSL(arr, n), right = NSR(arr, n);
    vector<int> wArr;

    int maxA = INT_MIN;

    for (int i = 0; i < n; i++)
        wArr.push_back(right[i] - left[i] - 1);

    for (int i = 0; i < n; i++)
        maxA = max(maxA, wArr[i] * arr[i]);

    return maxA;
}

// get the maximum area of rectangle
int maxArea(int arr[1000][1000], int n, int m)
{
    int *newArr = new int[m];
    for (int j = 0; j < m; j++)
    {
        newArr[j] = arr[0][j];
    }

    int maxArea = MAH(newArr, m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                newArr[j] = 0;
            }
            else
            {
                newArr[j]++; // newArr[j] += arr[i][j];
            }
        }
        maxArea = max(maxArea, MAH(newArr, m));
    }

    return maxArea;
}
```

### Some optimization in MAH

```cpp

// OPTIMIZED MAH
int MAH(int *arr, int n)
{
    stack<int> s;
    int max_area = 0, area = 0;
    int i = 0;
    while (i < n)
    {
        if (s.empty() || arr[s.top()] <= arr[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            int top = s.top();
            s.pop();
            if (s.empty())
            {
                area = arr[top] * i;
            }
            else
            {
                area = arr[top] * (i - s.top() - 1);
            }
            max_area = max(area, max_area);
        }
    }

    // When array becomes empty, pop all the elements of stack:
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        area = arr[top] * (s.empty() ? i : (i - s.top() - 1));
        max_area = max(area, max_area);
    }
    return max_area;
}

```



### References

- Youtube: [link](https://www.youtube.com/watch?v=St0Jf_VmG_g&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=8)
- GFG: [link](https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/)
