# [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/) 🌟🌟

### Hash map + sorting

-   By sorting s[i] we can use it as key for out hashmap.
-   Store the sorted string as key and the original string as value.
-   **TC: O(NKlogK)**, where N is the length of strs, and K is the maximum length of a string in strs. The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(KlogK) time.
-   **SC: O(N)**, the total information content stored in res.

### Code

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (string& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        for (auto m : mp) {
            res.push_back(m.second);
        }
        return res;
    }
};
```
