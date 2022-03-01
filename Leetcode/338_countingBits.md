# [338. Counting Bits](https://leetcode.com/problems/counting-bits/) 🌟

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

### STL

### Code

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};
```

### DP

-   Even numbers have same set bits as n/2.
-   Odd numbers have set bits prev+1.

### Code

```cpp
class Solution {
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num);
        res.push_back(0);

        if (num == 0)  return res;

        for (int i = 1; i <= num; i++) {
            if(i&1){
                res[i] = res[i-1] + 1;
            }
            else{
                res[i] = res[i/2];
            }
        }
        return res;
    }
};
```
