# [1732. Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)

There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

### O(N) Time and O(1) Space solution

- Start from 0, add each altitude and store max altitude.

### Code

```cpp
class Solution{
public:
    int largestAltitude(vector<int> &gain)
    {
        int mx = 0, alt = 0;

        for (auto &x : gain){
            alt += x;
            mx = max(mx, alt);
        }
        return mx;
    }
};
```
