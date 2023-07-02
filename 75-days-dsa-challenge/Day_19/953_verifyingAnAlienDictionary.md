# [953. Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)

### Solution

### Code

```cpp
class Solution {
public:
    unordered_map<char, char> mp;
    bool isAlienSorted(vector<string>& words, string order)
    {
        int n = order.size();
        for (int i = 0; i < n; i++)
            mp[order[i]] = i + 'a';
        for (auto& word : words)
            for (auto& c : word)
                c = mp[c];
        return is_sorted(begin(words), end(words));
    }
};
```
