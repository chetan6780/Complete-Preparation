# Word ladder I & II

-   [GFG](https://practice.geeksforgeeks.org/problems/word-ladder/1)
-   [Leetcode](https://leetcode.com/problems/word-ladder/)

### Word ladder I

### Code

```cpp
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList)
    {
        queue<pair<string, int>> q;
        q.push({ startWord, 1 });
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if (word == targetWord)
                return level;
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.find(word) != st.end()) {
                        q.push({ word, level + 1 });
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
```
