# [981. Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)

### Binary search and map

-   The code is self explanatory.

### Code

```cpp
class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;
    TimeMap() { }

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto it = mp[key].upper_bound(timestamp);
        if (it == mp[key].begin())
            return "";
        it--;
        return it->second;
    }
};
```
