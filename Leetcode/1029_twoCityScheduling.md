# [1029. Two City Scheduling](https://leetcode.com/problems/two-city-scheduling/) 🌟🌟

A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

### sorting + greedy solution

-   sort the costs by the difference between a and b.
-   add A's cost in first half and B's cost in second half.
-   return the ans.
-   **TC: O(nlogn)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        int n = costs.size();
        int half = n / 2;
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        int ans = 0;
        for (int i = 0; i < half; i++) {
            ans += costs[i][0];
        }
        for (int i = half; i < n; i++) {
            ans += costs[i][1];
        }
        return ans;
    }
};
```
