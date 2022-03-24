# [881. Boats to Save People](https://leetcode.com/problems/boats-to-save-people/) 🌟🌟

You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

### Greedy Two pointer

-   Code is self explanatory.
-   **TC: O(N log N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        int n = people.size();
        sort(people.begin(), people.end());
        int i = 0, j = n - 1;
        int cnt = 0;
        while (i <= j) {
            if (people[j] == limit) {
                cnt++;
                j--;
            } else if (people[i] + people[j] <= limit) {
                cnt++;
                i++;
                j--;
            } else {
                cnt++;
                j--;
            }
        }
        return cnt;
    }
};
```
