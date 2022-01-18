# [605. Can Place Flowers](https://leetcode.com/problems/can-place-flowers/) 🌟

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in **adjacent** plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

### Greedy Solution-I

-   The code is self explanatory.
-   **Time Complexity:** O(N)
-   **Space Complexity:** O(1)

### Code

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int m = flowerbed.size();
        if (m == 1 && flowerbed[0] == 0) // if only one flowerbed and it is empty
            return n <= 1;

        for (int i = 0; i < m; i++) {
            if (i == 0) { // first element
                if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    --n;
                }
            } else if (i == m - 1) { // last element
                if (flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    --n;
                }
            } else { // other elements
                if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }

        return n <= 0;
    }
};
```

### Greedy Solution-II

-   Solution by using `pre` for previous element and `next` for next element.
-   **Time Complexity:** O(N)
-   **Space Complexity:** O(1)

### Code

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int m = flowerbed.size();
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0) {
                int prev = (i == 0) ? 0 : flowerbed[i - 1];
                int next = (i == m - 1) ? 0 : flowerbed[i + 1];
                if (next == 0 && prev == 0) {
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }
        return n <= 0;
    }
};
```
