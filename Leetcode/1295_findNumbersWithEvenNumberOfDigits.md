# [1295. Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/) 🌟

Given an array nums of integers, return how many of them contain an even number of digits.

### O(N\*length(num)) Time and O(1) Space

- Implementation.

### Code

```cpp
class Solution {
int length(int n){
    int ans=0;
    while(n!=0){
        n/=10;
        ans++;
    }
    return ans;
}
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto &x: nums){
            ans+=(length(x)&1)?0:1;
        }
        return ans;
    }
};
```

### O(N) Time and O(1) Space

- Using log10(num) to find the length of the number.
- log10(num) gives lenght(num)-1.

### Code

```cpp

```
