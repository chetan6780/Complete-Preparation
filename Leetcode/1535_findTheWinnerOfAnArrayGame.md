# [1535. Find the Winner of an Array Game](https://leetcode.com/problems/find-the-winner-of-an-array-game/) 🌟🌟

Given an integer array arr of distinct integers and an integer k.

A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]). In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0, and the smaller integer moves to the end of the array. The game ends when an integer wins k consecutive rounds.

Return the integer which will win the game.

It is guaranteed that there will be a winner of the game.

### Simulation

-   If k >= n, then the max element will always win the game, as it will not change its position from 0 index.
-   If k < n, then we need to simulate the game.
-   We need to keep track of the current winner and the number of consecutive wins.
-   If the current winner wins, then we increment the number of consecutive wins.
-   If the current winner loses, then we set the number of consecutive wins to 1.
-   If the number of consecutive wins is equal to k, then we return the current winner.
-   Else, we return the last winner.
-   **TC:** O(n)
-   **SC:** O(1)

### Code

```cpp
class Solution {
public:
    int getWinner(vector<int>& arr, int k)
    {
        int n = arr.size();
        if (k >= n) {
            return *max_element(arr.begin(), arr.end());
        }
        int cnt = 0;
        int curr = arr[0];
        for (int i = 1; i < n; i++) {
            if (curr > arr[i]) {
                cnt++;
            } else {
                curr = arr[i];
                cnt = 1;
            }
            if (cnt == k) {
                return curr;
            }
        }
        return curr;
    }
};
```
