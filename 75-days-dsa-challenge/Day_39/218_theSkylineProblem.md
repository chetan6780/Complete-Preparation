# [218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)

### Code

```cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        vector<vector<int>> res;
        multiset<int> pq;
        int prevMax = 0, currentMax = 0;
        for (int index = 0; index < buildings.size(); index++) {
            edges.push_back(make_pair(buildings[index][0], -buildings[index][2]));
            edges.push_back(make_pair(buildings[index][1], buildings[index][2]));
        }
        sort(edges.begin(), edges.end());
        pq.insert(0);
        for (int index = 0; index < edges.size(); index++) {
            if (edges[index].second < 0) {
                pq.insert(-edges[index].second);
            }
            else {
                pq.erase(pq.find(edges[index].second));
            }
            currentMax = *(pq.rbegin());
            if (currentMax != prevMax) {
                res.push_back({edges[index].first, currentMax});
                prevMax = currentMax;
            }
        }
        return res;
    }
};
```
