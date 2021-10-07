# [383. Ransom Note](https://leetcode.com/problems/ransom-note/) 🌟

Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote

### same as is_subsequence problem.

### O(N) Time O(N)=O(26) constant space

- calculate frequency of each letter in magazine
- iterate over ransomNote and decrement frequency of each letter
- if any letter frequency is less than 0, return false

### Code

```cpp
class Solution{
public:
    bool canConstruct(string ransomNote, string magazine)    {
        vector<int> a(26, 0);
        for (auto &x : magazine)
            a[x - 'a']++;
        for (auto &x : ransomNote)        {
            if (--a[x - 'a'] < 0)
                return false;
        }
        return true;
    }
};
```
