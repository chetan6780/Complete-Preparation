# [424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) (Medium)

### Sliding Window

-   Suppose we have not given constraint k, then what are the minimum operations are required to convert given string to string of same characters.
-   the answer will be `length_of_string - max_frequency_of_a_character_in_string`
-   Now in above approach we will add constraint of k, so how we can solve the problem.
-   we can maintain a sliding window such that
    `length_of_string - max_frequency_of_a_character_in_string <= k`
-   **TC: O(N)**
-   **SC: O(26)=O(1)**

### Code

```cpp
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        unordered_map<char, int> mp;
        int ans = 0;
        int maxFreq = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            maxFreq = max(maxFreq, mp[s[i]]);
            if (i - j - maxFreq + 1 > k) {
                mp[s[j]]--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
```
