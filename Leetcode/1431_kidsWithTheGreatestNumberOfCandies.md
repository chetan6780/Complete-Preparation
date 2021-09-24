# [1431. Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) 🌟

There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

### O(N) Time and O(N) Space Solution:

- Use greedy approach. For each kid check if candies[i] + extraCandies ≥ maximum in all Candies

### Code

```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=*max_element(candies.begin(),candies.end());
        vector<bool> ans;
        for(auto &x:candies){
            ans.push_back(x+extraCandies>=mx?true:false);
        }
        return ans;
    }
};
```
