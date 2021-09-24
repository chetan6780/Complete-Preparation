# [1773. Count Items Matching a Rule](https://leetcode.com/problems/count-items-matching-a-rule/)

You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

- ruleKey == "type" and ruleValue == typei.
- ruleKey == "color" and ruleValue == colori.
- ruleKey == "name" and ruleValue == namei.
  Return the number of items that match the given rule.

### O(N) Time and O(1) Space

- Implementation.

### Code

```cpp
class Solution{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int ans = 0;

        int k = (ruleKey == "type" ? 0 : (ruleKey == "color" ? 1 : 2));

        for (auto &x : items)
            if (x[k] == ruleValue)
                ans++;

        return ans;
    }
};
```
