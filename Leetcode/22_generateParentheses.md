# [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) 🌟🌟

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

### Backtracking

-   For each time we have the choice of choking opening or closing parenthesis.
-   We can choose opening parenthesis when it is greater than 0.
-   We can choose closing parenthesis when it is greater than the number of opening parenthesis.
-   and if both opening parenthesis and closing parenthesis are 0 then we got the answer, push-back it in the ans vector.

```cpp
class Solution {
private:
    void backtrack(vector<string>& ans, string& s, int open, int close)
    {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open > 0) {
            s.push_back('(');
            backtrack(ans, s, open - 1, close);
            s.pop_back();
        }
        if (close > open) {
            s.push_back(')');
            backtrack(ans, s, open, close - 1);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s;
        backtrack(ans, s, n, n);
        return ans;
    }
};
```
