# [290. Word Pattern](https://leetcode.com/problems/word-pattern/description/) 🌟

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

### Hashmap Solution

-   Maintain 2 hash maps, one mapping pattern to string and another mapping string to pattern.
-   Using c++ stringstream we can easily get each word in string on the fly.
-   Initialize a variable say `i` with 0 to count words in given string.
-   We traverse the stringstream and check if the word is in the hashmap.
    -   If it is not in the hashmap1,
        -   check if the word is in hashmap2,i.e if its mapped already with other character or not.
            -   If it is then map the word with character in the pattern and map character in the patter with the word. Increase the i.
            -   else return `false`.
    -   else the word in the hashmap1
        -   Check if the word is mapped with the same character or not.
            -   If its not return `false`.
        -   Increment the i, i.e.words count.
-   Finally return of `i==pattern.size()`, i.e. count of words in string and pattern same or not.
-   **TC: O(N)**
-   **SC: O(N)**, O(N)+O(N) 2 hashmaps.

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        stringstream ss(s);
        string word;
        int i = 0;
        while (ss >> word) {
            if (mp.count(pattern[i]) == 0) {
                if (mp2.count(word) == 0) {
                    mp[pattern[i]] = word;
                    mp2[word] = pattern[i];
                    i++;
                } else {
                    return false;
                }
            } else {
                if (mp[pattern[i]] != word) {
                    return false;
                }
                i++;
            }
        }
        return i == pattern.size();
    }
};
```
