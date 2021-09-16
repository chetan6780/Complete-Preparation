# 0-1 Knapsack Problem

### Method 1: Recursion by Brute-Force algorithm OR Exhaustive Search.

### Brute Solution:

- Base case - If n is 0 or w is 0, then return 0
- if weight of last item(nth item) is less than or equal to W we can add it else not.
  - Return the maximum of two cases: (1) not included (2) nth(last) item included
- else Don't include the nth item and reduce the input, call recursion with reduced inputs.

### Code

```cpp
/* A Naive recursive implementation of 0-1 Knapsack problem */
int knapSack(int W, int wt[], int val[], int n)
{

    // Base case - If n is 0 or w is 0, then return 0
    if (n == 0 || W == 0)
        return 0;

    // choice diagram code
    // if weight of last item(nth item) is less than or equal to W we can add it else not.
    if (wt[n - 1] <= W)
    {
        // Return the maximum of two cases: (1) nth item included (2) not included
        return max(knapSack(W, wt, val, n - 1), val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        // Don't include the nth item and reduce the input
        return knapSack(W, wt, val, n - 1);
    }
}
```

### Complexity Analysis:

- Time Complexity : **O(2^n)** - As there are redundant subproblems.
- Auxiliary Space : **O(1)** - As no extra data structure has been used for storing values.

---

## DP APPROACHES

### A) Memorization (Top Down)

- Initialize 2D array with -1.
- Base case.
- If this state is previously present we return it.
- else
  - if nth weight is less than or equal to We
    - store the maximum of included weight and not include weight in the 2D array.
    - store new state in dp array and return it.
  - else
    - store not include weight in the 2D array
    - store new state in dp array and return it.

```cpp

int dp[1002][1002];
void initialize()
{
    for (int i = 0; i < 1002; i++)
        for (int j = 0; j < 1002; j++)
            dp[i][j] = -1;
}

int knapSackRec(int W, int wt[], int val[], int n)
{

    // Base case - If n is 0 or w is 0, then return 0
    if (n == 0 || W == 0)
        return 0;

    // If this state is previously present we return it.
    if (dp[n][W] != -1)
        return dp[n][W];

    // if weight of last item(nth item) is less than or equal to W we can add it else not.
    if (wt[n - 1] <= W)
    {
        // Return the maximum of two cases: (1) nth item included (2) not included
        return dp[n][W] = max(knapSackRec(W, wt, val, n - 1), val[n - 1] + knapSackRec(W - wt[n - 1], wt, val, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        // Don't include the nth item and reduce the input
        return dp[n][W] = knapSackRec(W, wt, val, n - 1);
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    initialize();
    return knapSackRec(W, wt, val, n);
}
```

### Complexity Analysis:

- Time Complexity: **O(N\*W)** - As redundant calculations of states are avoided.
- Auxiliary Space: **O(N\*W)** - The use of 2D array data structure for storing intermediate states-:

---

### B) Tabulation (Bottom Up)

- Declare 2D array dp[n+1][w+1] globally which inititalizes it with 0.
- for i (1 to n+1)
  - for j(1 to W+1)
    - if nth weight is less than or equal to W we can add or not add it.
      - Store the maximum of these two cases in dp.
    - else we not add weight.
      - store the previous state in dp.
- TIP: if we start from i=0 and j==0 include this condition.no need to initialize.
  - if(i==0 || j==0) dp[i][j] = 0;
- retrun dp[n][w]

### Code

```cpp

// dp[n+1][W+1] - Global declaration initialise it with 0 , no need for initialization, n = i, W = j
int dp[1002][1002];

int knapSack(int W, int wt[], int val[], int n)
{

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            // if(i==0 || j==0)dp[i][j] = 0; if we start from i=0 and j==0 include this condition.
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1]) + dp[i - 1][j - wt[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}
```

### Complexity Analysis:

- Time Complexity: **O(N\*W)** - where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
- Auxiliary Space: **O(N\*W)** - The use of 2-D array of size ‘N\*W’.

---

### (C) DP with optimized space compexity

- We can use 1D array of size W+1 instead of 2D array.
- for i (1 to n+1)
  - for j (W to 0)
    - if weight of item is less than j i.e. W(total remaining weight)
      - store the max of (dp[j], dp[j - wt[i - 1]] + val[i - 1]) in dp[j]
- return dp[W]

```cpp
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = W; j >= 0; j--)
        {
            if (wt[i - 1] <= j)
                dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}
```

### Complexity Analysis:

- Time Complexity: **O(N\*W)** As redundant calculations of states are avoided.

- Auxiliary Space: **O(W)** As we are using 1-D array instead of 2-D array.

---

### References

- GFG: [0-1 Knapsack Problem](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
- Youtube: [Aditya Verma](https://www.youtube.com/playlist?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go)
