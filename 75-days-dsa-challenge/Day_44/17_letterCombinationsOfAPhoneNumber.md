# [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

### Backtracking

-   Map all the possible characters to the corresponding digits.
-   For each number, generate all the possible combinations.
-   We try for each letter in value by adding it and then removing it from the string.

### Code

```cpp
class Solution {
public:
    void letterCombinations_helper(string digits, string& output, int index, vector<string>& map, vector<string>& ans)
    {
        if (index >= digits.size()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = map[number];

        for (int i = 0; i < value.size(); i++) {
            output.push_back(value[i]);
            letterCombinations_helper(digits, output, index + 1, map, ans);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.size()==0)return {};
        vector<string> ans;
        int index = 0;
        string output = "";
        vector<string> map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        letterCombinations_helper(digits, output, index, map, ans);
        return ans;
    }
};
```
