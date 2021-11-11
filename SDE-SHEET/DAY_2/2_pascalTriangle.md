# [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) 🌟

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

### Straightforward solution

### Code

```cpp
class Solution{
public:
    vector<vector<int>> generate(int n){
        vector<vector<int>> ans;
        if (n >= 1) ans.emplace_back({1});
        if (n >= 2) ans.emplace_back({1, 1});

        for (int i = 2; i < n; i++){
            vector<int> temp;
            temp.emplace_back(1);
            for (int j = 1; j < ans[i - 1].size(); j++){
                temp.emplace_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            temp.emplace_back(1);
            ans.emplace_back(temp);
        }
        return ans;
    }
};
```

### Code

```cpp
class Solution{
public:
    vector<vector<int>> generate(int n){
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++){
            ans.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++)
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        return ans;
    }
};
```

#### We can find any element(a[i][j]) in O(1) time using the formula (r-1)C(c-1) i.e (r-1)!/(c-1)!

-   Ex. 3rd element of 5th row -> c=2,r=4 -> (4\*3)/(2\*1) = 6.
