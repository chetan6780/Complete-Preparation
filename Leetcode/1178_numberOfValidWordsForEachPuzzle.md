# [1178. Number of Valid Words for Each Puzzle](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/) 🌟🌟🌟

With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:

- word contains the first letter of puzzle.
- For each letter in word, that letter is in puzzle.
  - For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
  - invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).
    Return an array answer, where answer[i] is the number of words in the given word list words that is valid with respect to the puzzle puzzles[i].

### Bit masking with hashmap

- We set all the bits of the corresponding indices of each letter, then we easily see if it's a submask.
- we create a hashmap to keep the frequency of each mask, so that if we have two words with the same letter we will count both.
- we iterate through the puzzles
- We need to find all combinations of submasks to check. This is the faster than iterating through all the words because each puzzle is only 7 letters.
- For that we just do (submask-1) & mask - we are turning off a bit by subtracting one which sets the lowest 1 to 0 and all 0s in the right to 1s, and then we do & with the original mask to get only the desired bits.

### Code

```cpp
class Solution
{
public:
    int maskWord(string word) // n|(1<<i) : set i'th bit
    {
        int mask = 0;
        for (auto c : word)
            mask |= (1 << c - 'a');
        return mask;
    }

    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        vector<int> res;
        unordered_map<int, int> mask_freq; // map of bitmasks
        for (auto word : words)
            mask_freq[(maskWord(word))]++;

        for (auto puzzle : puzzles)
        {
            int mask = maskWord(puzzle), submask = mask;
            int first = (1 << puzzle[0] - 'a'), curr = 0;

            while (submask)
            {
                if (submask & first)
                    curr += mask_freq[submask];

                submask = (submask - 1) & mask;
            }

            res.push_back(curr);
        }
        return res;
    }
};
```

### Interview Tips

- **Interview Tip:** _In a real interview, if you are unsure how to solve the problem, a good first step is to remain calm and reread the problem description looking for hidden clues.
  Also, remember to ask the interviewer about the problem constraints. The constraints are very important for solving problems as they can help us determine which data structures and algorithms can feasibly be used to solve the problem.
  However, if the interviewer chooses to deliberately hide the constraints, then they likely want you to find different methods under different assumed constraints. Although, on rare occasions, a problem may be too simple to provide constraints._

- **Interview Tip:** _A constraint under `10` usually accepts a method with `N!` time complexity with respect to this constraint. Factorial time complexities can occur for operations like finding all permutations from a set or using brute-force to solve the traveling salesman problem.
  A constraint under `30` usually accepts a method with `2^N` time complexity at worst with respect to this constraint. Some examples include iterating over all combinations or subsets from a set or some brute-force solutions that use `DFS`.
  However, a solution with better time complexity can still exist even when the constraints are small. One should use the constraints to estimate the complexity of the worst acceptable solution, not the best solution._

- **Interview Tip:** _When you still do not have any idea after rereading the problem, you can try a brute-force method that works but may have an unacceptable time complexity.
  Then you can either try to improve on the brute-force method or gain some insight from the brute-force method._

- **Interview Tip:** _In an interview, if the first solution that comes to mind involves a complex data structure, you can wait a minute and try thinking of other similar methods. In a real-world setting, we typically prioritize efficiency and readability. We prioritize these characteristics in an interview setting as well, however, we also value solutions that we are less likely to make a mistake while coding and solutions that do not require a long time to code.
  In this problem, you should consider your level of familiarity with the trie data structure before choosing between implementing a solution using a trie or a set. If the more comfortable approach is not the most efficient, then you should also weigh the increased chance of making a mistake versus the gain of having a more efficient solution.
  Worry not, as we will cover both methods in this article._

### Must Read:

- [Video sumit sir](https://www.youtube.com/watch?v=9jV0CC_C26s)
- [✅ [C++] Clean & Easy Solution w/ Detailed Explanation | Bit-masking Approach](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/discuss/1567324/C%2B%2B-Clean-and-Easy-Solution-w-Detailed-Explanation-or-Bit-masking-Approach)
- [C++ Simple and Clean Solution, Easy Explanation](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/discuss/1567291/C%2B%2B-Simple-and-Clean-Solution-Easy-Explanation)
- [Leetcode Solution](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/solution/)
