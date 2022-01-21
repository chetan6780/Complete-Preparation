# [134. Gas Station](https://leetcode.com/problems/gas-station/) 🌟🌟

There are n gas stations along a circular route, where the amount of gas at the ith station is `gas[i]`.

You have a car with an unlimited gas tank and it costs `cost[i]` of gas to travel from the `i`th station to its next `(i + 1)`th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return `-1`. If there exists a solution, it is **guaranteed** to be **unique**

### Greedy Solution

-   The sum of `gas[i] - cost[i]` (which is the current balance state) from start point should always be `>= 0`, otherwise, we can't move to the next point.
-   **TC: O(N)**
-   **SC: O(1)**

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int start = 0, currBalance = 0, remBalance = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            currBalance += gas[i] - cost[i];
            if (currBalance < 0) {
                start = i + 1;
                remBalance += currBalance;
                currBalance = 0;
            }
        }
        return currBalance + remBalance >= 0 ? start : -1;
    }
};
```
