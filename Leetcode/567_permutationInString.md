# [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/) 🌟🌟

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

### O(N) Time and O(1) Space

- Permutation of string is the anagram of itself.
- So, the problem become, find the anagram of the string1 in the string2.
- We can find it with maintaining two frequency arrays for s1 and s2.
- If at any point their frequencies are equal, then return true.
- else by maintaining window size(s1.size()), try for next substring.
- finally, return false, because there is no anagram of string1 in string2.

### Code

```cpp
class Solution{
public:
    bool checkInclusion(string s1, string s2){
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < m; i++){
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        if (cnt1 == cnt2) return true;

        for (int i = m; i < n; i++){
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - m] - 'a']--;
            if (cnt1 == cnt2) return true;
        }
        return false;
    }
};
```
