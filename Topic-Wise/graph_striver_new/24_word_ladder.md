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

### Word ladder II

### Code

```cpp
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        //* Creating an unordered_set of string type to store every word.

        vector<string> usedWords;
        //* words that are used will be used in usedWords.

        vector<vector<string>> ans;
        //* Storing all the possible sequences that can be formed.

        queue<vector<string>> q;
        //* Queue of vector<string> type to store the sequences.

        q.push({ beginWord });
        usedWords.push_back(beginWord);
        //* beginWord is pushed into the queue , hence adding it to the usedWords vector

        bool flag = false;
        //* A small check to break the while loop (when the endWord is found at any level in a vector)

        while (!q.empty()) {
            int size = q.size();

            for (string delWords : usedWords) {
                wordSet.erase(delWords);
                //? Deleting all the previously used words from the wordSet.
                //* Ensures that the same word isn't used again.
            }

            usedWords.clear();

            //? This for loop ensures that all vectors of same size or at same level are checked in one go.
            //* Else wordSet will no longer have the words that can be used in another vector.
            //* eg : in vector {abp , adp , kdp, kdz} we already used "KDP" but another vector v2 {abp , kbp, kdp, kdz};
            //* Can be formed with same endWord and same length but we wont be able to used KDP again if we dont use the for loop for each levels.
            for (int i = 0; i < size; i++) {
                //*Storing the current vector.
                vector<string> qWordlist = q.front();
                q.pop();

                //? Checks for the endWord which should be present at the last index in the vector
                if (qWordlist.back() == endWord) {
                    //* If present , add the vector that has the correct sequence
                    ans.push_back(qWordlist);

                    flag = true;

                    //* Skip the addition of any word since we already found our endWord.
                    continue;
                }

                //* Last word -> transform it to another word , stored in the queue
                string lastWord = qWordlist.back();

                int len = lastWord.size(); // can define outside queue as well , since all word size = beginWord.size().

                //? For loop runs for the number of characters.
                for (int idx = 0; idx < len; idx++) {
                    char original_char = lastWord[idx];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        lastWord[idx] = ch;

                        if (wordSet.find(lastWord) != wordSet.end()) {
                            //*If the modified word is found , push it (into the vector then into the queue ) as well as (in the usedWord vector).
                            qWordlist.push_back(lastWord);
                            q.push(qWordlist);
                            usedWords.push_back(lastWord);

                            //?Removal of the added lastWord , since in the next iteration we do not want to add a new word to updated qWordList.
                            qWordlist.pop_back();
                        }
                    }

                    lastWord[idx] = original_char;
                }
            }

            if (flag)
                break;
        }

        return ans;
    }
};
```
