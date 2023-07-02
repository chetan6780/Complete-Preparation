# [381. Insert Delete GetRandom O(1) - Duplicates allowed](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)

### Solution

-   This question is similar to **Insert Delete GetRandom O(1)**, but here we allow duplicates.
-   To store the indexes of the element, we can use a set.
-   Other code is self explanatory.

### Code

```cpp
class RandomizedCollection {
private:
    vector<int> v;
    unordered_map<int, unordered_set<int>> mp;

public:
    RandomizedCollection() { }

    bool insert(int val)
    {
        v.push_back(val); // push value
        mp[val].insert(v.size() - 1); // push index
        return mp[val].size() == 1;
    }
    bool remove(int val)
    {
        auto it = mp.find(val);
        if (it != end(mp)) {
            auto free_pos = *it->second.begin(); // get free position

            v[free_pos] = v.back(); // copy last value to free position
            it->second.erase(it->second.begin()); // remove first index from set
            mp[v.back()].insert(free_pos); // insert index (free position) in set
            mp[v.back()].erase(v.size() - 1); // remove last index from set of the last value

            v.pop_back(); // remove last value from vector

            // if set is empty, remove the element from the map
            if (it->second.size() == 0)
                mp.erase(it);

            return true;
        }
        return false;
    }
    int getRandom() { return v[rand() % v.size()]; }
};
```
