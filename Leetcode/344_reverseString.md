# [344. Reverse String](https://leetcode.com/problems/reverse-string/) 🌟

Write a function that reverses a string. The input string is given as an array of characters s.

### O(N) Time two pointer solution

- swap start and end pointers.

### Code

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0,r=s.size()-1;
        while(l<r){
            swap(s[l++],s[r--]);
        }
    }
};
```
