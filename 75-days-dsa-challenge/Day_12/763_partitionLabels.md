# [763. Partition Labels](https://leetcode.com/problems/partition-labels/)

### Solution

-   We store the last occurrence of each character in a hashmap/vector.
-   We iterate through the string and keep track of the maximum index of the occurrence of each character.
-   If current index is the max index then we can calculate the length by `max_index - prev_last_index + 1` and add it to the result.
-   increment the `prev_last_index` by 1;

### Code

```cpp
class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> res;
        vector<int> charIdx(26, 0);
        int n = s.size();
        // store the last index of the character
        for (int i = 0; i < n; i++) {
            charIdx[s[i] - 'a'] = i;
        }

        int maxIdx = -1, lastIdx = 0;
        for (int i = 0; i < n; i++) {
            maxIdx = max(maxIdx, charIdx[s[i] - 'a']);
            // if current index is the maximum index of the character,
            if (i == maxIdx) {
                res.push_back(maxIdx - lastIdx + 1);
                lastIdx = i + 1;
            }
        }
        return res;
    }
};
```
