# [387. First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/) 🌟

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

### O(N^2) Time and O(1) space

- Brute force
- For every character check if it appears in the string more than once

### O(N) Time and O(N)=O(26) constant space

- Store frequency of every character in a hash table
- Iterate through the hash table and check if the character is Unique

### Code

```cpp
class Solution{
public:
    int firstUniqChar(string s){
        unordered_map<char, int> mp;
        int n = s.size();
        for (auto &x : s) mp[x]++;
        for (int i = 0; i < n; i++){
            if (mp[s[i]] == 1) return i;
        }
        return -1;
    }
};
```
