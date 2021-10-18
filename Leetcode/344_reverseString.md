# [344. Reverse String](https://leetcode.com/problems/reverse-string/) 🌟

Write a function that reverses a string. The input string is given as an array of characters s.

### O(N) time and O(1) space, using stack

- Using stack we can reverse the string.

### O(N) Time , recursive

- if i is the middle then we can stop (it's base condition)
- else we swap ith and n-i-1th element
- we recur for next position of i, i.e i+1.

```cpp
class Solution{
public:
    void reverseString(vector<char> &s, int i = 0){
        int n = s.size();
        if (i == n / 2) return;

        swap(s[i], s[n - 1 - i]);
        reverseString(s, i + 1);
    }
};
```

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
