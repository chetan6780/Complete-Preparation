# [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) 🌟🌟

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

### sliding window + hashmap

-   We can maintain a sliding window of size equal to `p.size()` and check if `window == p`.
-   We need to use hashmap not hashset because we need to keep track of duplicate counts.
-   **TC: O(N)**, N is the length of the string s.
-   **SC: O(N)**, extra hashmap.

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<int> ans;
        unordered_map<char, int> pmap;
        unordered_map<char, int> smap;

        for (auto x : p) pmap[x]++;
        for (int i = 0; i < m; i++) smap[s[i]]++;

        if (smap == pmap) ans.push_back(0);

        for (int i = 1; i <= n - m; i++) {
            int prevCharCount = smap[s[i - 1]];
            if (prevCharCount == 1) {
                smap.erase(s[i - 1]);
            } else {
                smap[s[i - 1]]--;
            }
            smap[s[i + m - 1]]++;
            if (smap == pmap) ans.push_back(i);
        }
        return ans;
    }
};
```

### sliding window + array [constant space]

-   Since in the question it is given that input string has only lowercase letters, we can use a 26-element array to represent the sliding window.Hence the space complexity will be O(26)-->O(1).
-   **TC: O(N)**, N is the length of the string s.
-   **SC: O(1)**, constant space. O(26).

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(), m=p.size();
        if(m>n) return {};
        vector<int> ans;

        vector<int> sCnt(26,0);
        vector<int> pCnt(26,0);

        for(auto x:p) pCnt[x-'a']++;
        for(int i=0;i<m;i++) sCnt[s[i]-'a']++;
        if(sCnt==pCnt) ans.push_back(0);

        for(int i=1;i<=n-m;i++){
            sCnt[s[i-1]-'a']--;
            sCnt[s[i+m-1]-'a']++;
            if(sCnt==pCnt) ans.push_back(i);
        }
        return ans;
    }
};
```
