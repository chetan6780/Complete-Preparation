# [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

### Solution

-   We can sort the map by value and then take the top k elements.

### Code

```cpp
class Solution {
private:
    static bool sortByVal(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> mp;
        for(auto x: nums){
            mp[x]++;
        }
        vector<pair<int, int>> v;
        for(auto x: mp){
            v.push_back(make_pair(x.first, x.second));
        }
        sort(v.begin(), v.end(), sortByVal);
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};
```
