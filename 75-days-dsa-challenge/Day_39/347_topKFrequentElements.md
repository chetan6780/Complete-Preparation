# [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

### Using map

-   count the frequency of each element in map, store `(element, frequency)` in a vector.
-   Sort vector by frequency in descending order.
-   Return the first k elements in the vector.
-   **Time complexity: O(n)**
-   **Space complexity: O(n)**

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

### Priority Queue

-   The same approach as above can be implemented using a priority queue.
