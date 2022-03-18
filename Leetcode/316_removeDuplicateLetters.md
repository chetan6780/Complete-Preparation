# [316. Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/) 🌟🌟

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

### NOTE: This question is same as [1081](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

### Solution

-   We store the frequency of characters in a hashmap or vector.
-   Create an answer string to store the result.
-   for every character in the string.
    -   Decrement the frequency of the character.
    -   If its already visited the continue.
    -   else remove all characters from ans string that are greater than current character.
    -   Add current character in the answer string.
    -   mark visited as true.
-   Return the answer string.
-   **TC: O(N)**
-   **SC: O(26)=O(1)**

### Code

````cpp
class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.size();
        vector<int> cnt(26, 0); // frequencies
        vector<bool> vis(26, false); // visited

        // count the frequencies of characters form string
        for (char c : s)
            cnt[c - 'a']++;

        string ans;
        for (char c : s) {
            cnt[c - 'a']--; // decrease the frequency of current character
            if (vis[c - 'a'] == true)
                continue;
            // remove all characters in ans that are greater than c
            while (!ans.empty() && ans.back() > c && cnt[ans.back() - 'a'] >= 1) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            // add c in the ans string
            ans += c;
            vis[c - 'a'] = true;
        }
        return ans;
    }
};```
````
