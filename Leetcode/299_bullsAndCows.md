# [299. Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/description/) 🌟🌟

You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

### Counting Solution

-   We can simply count the number of bulls and cows.
-   Take count vector to store the count of each digit in secret.
-   Traverse the secret and guess string and if the digit is same we increment the bulls.
-   If the digit is not same we increment the count of that digit in secret and decrement the count of that digit in guess.while incrementing the cows both time.
-   Finally we return the bulls and cows is required format.
-   **TC: O(N)**
-   **SC: O(1)**, since the count vector is of constant size.

### Code

```cpp
class Solution {
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0, cows = 0;
        int n = secret.size();
        vector<int> cnt(10, 0);
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                if (cnt[secret[i] - '0']++ < 0) {
                    cows++;
                }
                if (cnt[guess[i] - '0']-- > 0) {
                    cows++;
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```
