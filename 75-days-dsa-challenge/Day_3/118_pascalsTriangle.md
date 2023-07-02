# [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) (Easy)

### Solution

-   For the i'th row we will create a temp array of size i+1(i is 0 based|row is 1 based) of all elements 1 in it.
-   push this temp array in ans.
-   for the pascals triangle we know that `currNum = numOnPrevRowAndPrevCol + numOnPrevRowAndSameCol` for all numbers except first and last.
-   we calculate all the numbers with above formula.
-   finally return the ans.


### Code

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};
```
