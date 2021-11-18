# [668. Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) 🌟🌟🌟

Nearly everyone has used the `Multiplication Table`. The multiplication table of size `m x n` is an integer matrix `mat` where `mat[i][j] == i * j` (1-indexed).

Given three integers `m`, `n`, and `k`, return the `kth` smallest element in the `m x n` multiplication table.

### Brute Force

-   We create a 2D matrix of multiplication table then convert it to a 1D array.
-   We sort the array and return the `k`th element.
-   **TC: O(N^2)**
-   **SC: O(M\*N)+O(M+N)**- For extra 2D and 1D arrays.

### Brute force with reduced space

-   Instead of creating a 2D array, we can create a 1D array of size `m+n` and fill it with the multiplication table.
-   Then We sort the array and return the `k`th element.
-   **TC: O(N^2)**
-   **SC: O(M+N)**- For 1D array.

```cpp
class Solution {
public:
    int findKthNumber(int m, int n, int k){
        vector<int> a;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a.push_back((i + 1) * (j + 1));
            }
        }
        sort(a.begin(), a.end());
        return a[k - 1];
    }
};
```

### Binary Search

```cpp

class Solution {
    bool smallest(int num, int m, int n, int k){
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(num / i, n);
        }
        return count >= k;
    }

public:
    int findKthNumber(int m, int n, int k){
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (smallest(mid, m, n, k))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
```