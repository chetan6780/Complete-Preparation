# Matrix Chain Multiplication

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

### Method 1: Recursive Approach

- If we start from i=0 then we will have dimension of resultant array as arr[i-1] x arr[i] where arr[i-1] is negative and not possible, so we start from i=i+1.
- if j will start from j resulting array will be arr[j-1] x arr[j] which is possible so we can take j.
- We can recure k as,

```
1) k=i to j-1 then, recure for i to k , k+1 to j  OR
2) k=i+1 to j then, recure for i to k-1 , k to j
```

- Take minimum for every k in a loop.
- Return the minimum value.

### Code

```cpp
int matrixChainMultiplication(int a[], int i, int j)
{
    if (i >= j)
        return 0;

    int temp = 0, mn = INT_MAX;

    for (int k = i; k < j; k++)
    {
        temp = matrixChainMultiplication(a, i, k) + matrixChainMultiplication(a, k + 1, j) + a[i - 1] * a[k] * a[j];

        mn = min(mn, temp);
    }
    return mn;
}
int matrixMultiplication(int N, int arr[])
{
    matrixChainMultiplication(arr, 1, N - 1);
}
```

---

# DP APPROACHES

### A) Memoization(Top-Down)

### Code

```cpp
int dp[101][101];
int matrixChainMultiplication(int *a, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = matrixChainMultiplication(a, i, k) + matrixChainMultiplication(a, k + 1, j) + a[i - 1] * a[k] * a[j];

        dp[i][j] = min(dp[i][j], temp);
    }
    return dp[i][j];
}

int matrixMultiplication(int N, int arr[])
{
    memset(dp, -1, sizeof(dp));
    matrixChainMultiplication(arr, 1, N - 1);
}
```

### Complexity Analysis

- Time Complexity: **O(n^3)**
- Auxiliary Space: **O(n^2)**

### References

- GFG: [Matrix Chain Multiplication](https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/)
- GFG: [Matrix Chain Multiplication O(n^2) solution](https://www.geeksforgeeks.org/matrix-chain-multiplication-a-on2-solution/)
- YouTube: [AV - Matrix Chain Multiplication Recursive](https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33)
- YouTube: [AV - Matrix Chain Multiplication Memoization](https://www.youtube.com/watch?v=9uUVFNOT3_Y&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=34)
