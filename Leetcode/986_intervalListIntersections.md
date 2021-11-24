# [986. Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) 🌟🌟

You are given two lists of closed intervals, firstList and secondList, where `firstList[i] = [starti, endi]` and `secondList[j] = [startj, endj]`. Each list of intervals is pairwise **disjoint** and in **sorted order**.

Return the intersection of these two interval lists.

A `closed interval` [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The **intersection** of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

### 2-pointer Solution

-   [[Python] Two Pointer Approach + Thinking Process Diagrams](https://leetcode.com/problems/interval-list-intersections/discuss/647482/Python-Two-Pointer-Approach-%2B-Thinking-Process-Diagrams)
<!-- TODO: Add explanation -->

### Code

```cpp
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
    {
        vector<vector<int>> ans;
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            int l = max(firstList[i][0], secondList[j][0]);
            int u = min(firstList[i][1], secondList[j][1]);
            if (l <= u)
                ans.push_back({ l, u });
            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};
```
