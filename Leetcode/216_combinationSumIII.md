# [216. Combination Sum III](https://leetcode.com/problems/combination-sum-iii/description/) 🌟🌟

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

### Backtracking Solution

-   For this problem as we have to try all the numbers to check if they can form the sum or not, we can use backtracking.
-   Create a helper function which takes the size of the combination, the sum, the answer vector, the temporary vector and the starting number.
-   If the sum is 0 and the size of the temporary vector is equal to the size of the combination, we found the combination, so we push it to the answer vector and return.
-   If the sum is less than 0 or the size of the temporary vector is greater than the size of the combination, we can't form the sum, so we return.
-   Now we try all the numbers from the starting number to 9.
-   We push the number to the temporary vector and call the helper function with the sum - number, as we have used the number.
-   After the recursive call we pop the number from the temporary vector.
-   **TC:O(2^n)**
-   **SC:O(k)**

### Code

```cpp
class Solution {
    void helper(int k, int n, vector<vector<int>>& ans, vector<int>& temp, int start)
    {
        // if n is 0 and we found the combination of size k
        if (n == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // if n is less than 0 or we found the combination of size greater than k
        if (n <= 0 || temp.size() >= k) {
            return;
        }

        // try all possible numbers from start to 9
        for (int i = start; i <= 9; i++) {
            temp.push_back(i);
            helper(k, n - i, ans, temp, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(k, n, ans, temp, 1);
        return ans;
    }
};
``
```
