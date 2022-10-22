# [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) 🌟🌟🌟

### Sliding Window + Hashmap

-   We use sliding window with hashmap and counter for this problem.
-   counter indicates if characters are present in the window or not. if positive then present, if negative then not present.
-   Other Code is self explanatory.
-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp;

        // store count of characters from t in map
        for (auto c : t) mp[c]++;

        // two pointer for sliding window
        int left = 0, right = 0;

        // counter represents the number of chars of t to be found in s.
        int counter = t.size(), strStart = 0, minLen = INT_MAX;

        // Move right to find a valid window.
        while (right < s.size()) {
            // If char in s exists in t, decrease counter
            if (mp[s[right]] > 0) counter--;

            // If char does not exist in t, mp[s[right]] will be negative.
            // So Decrease mp[s[right]].
            mp[s[right]]--;

            // When we found a valid window, move left to find smaller window.
            while (counter == 0) {
                // update minimum length
                int currLen = right - left + 1;
                if (currLen < minLen) {
                    strStart = left;
                    minLen = currLen;
                }

                // increase frequency of character at 'left' position of s
                mp[s[left]]++;

                // When frequency is positive, char will exists in t, increase counter.
                if (mp[s[left]] > 0) counter++;

                // move left to find smaller window.
                left++;
            }

            // increase right to increase window size
            right++;
        }
        if (minLen != INT_MAX)
            return s.substr(strStart, minLen);
        return "";
    }
};
```
