# [1578. Minimum Time to Make Rope Colorful](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/) 🌟🌟

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

### Two Pointer

### Code

```cpp
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int n = colors.size();
        int i = 0, j = 0;
        int currTotal = 0, currMax = 0;
        int res = 0;
        while (i < n && j < n) {
            if(colors[i]!=colors[j]){
                res += currTotal - currMax;
                currTotal = 0;
                currMax = 0;
                i = j;
            }else{
                currTotal += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }

        }
        res += currTotal - currMax;
        return res;
    }
};
```

### One pass

### Code

```cpp
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0, currMaxTime = 0;
        int n = colors.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && colors[i] != colors[i - 1]) {
                currMaxTime = 0;
            }

            totalTime += min(currMaxTime, neededTime[i]);
            currMaxTime = max(currMaxTime, neededTime[i]);
        }

        return totalTime;
    }
};
```
