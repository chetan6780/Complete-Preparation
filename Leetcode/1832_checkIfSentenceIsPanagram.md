# [1832. Check if the Sentence Is Pangram](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

### O(N) Time O(N) Space Solution

- Create a set and check if its length is exactly 26 or not.

### Code

```cpp
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st;
        int n = sentence.size();
        for(int i=0;i<n;i++){
            st.insert(sentence[i]);
        }
        return (st.size()==26?true:false);
    }
};
```
