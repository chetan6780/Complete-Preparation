# [380. Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) (Medium)

### Vector + Map

### Code

```cpp
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.count(val))
            return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (mp.count(val) == 0)
            return false;
        int last = nums.back();
        mp[last] = mp[val];
        nums[mp[val]] = last;
        nums.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};
```
