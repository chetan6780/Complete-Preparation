# [557. Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/) 🌟

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

### O(N\*M) Time solution

- Where N: lenght of string and M: lenght of substring splited by space.
- The idea is to reverse the substring splitted by spaces, so the final result will be possible.

### Code

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l=0,r;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                r=i-1;
                while(l<r){
                    swap(s[l++],s[r--]);
                }
                l=i+1;
            }
        }
        r=n-1;
        while(l<r){
            swap(s[l++],s[r--]);
        }
        return s;
    }
};
```
