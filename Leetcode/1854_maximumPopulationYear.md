# [1854. Maximum Population Year](https://leetcode.com/problems/maximum-population-year/) 🌟

You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.

### O(N) Time and O(N) Space

- We can mark the start and end of each life as +1 and -1 on the timeline.
- Then, we go through timeline from 1950 to 2050 and accumulate the current population for each year.

### Code

```cpp
class Solution {
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        int numLine[2051] = {}, ans = 0;
        for (auto &l : logs)
        {
            numLine[l[0]]++;
            numLine[l[1]]--;
        }
        for (auto i = 1950; i < 2050; ++i)
        {
            numLine[i] += numLine[i - 1];
            ans = numLine[i] > numLine[ans] ? i : ans;
        }
        return ans;
    }
};
```
