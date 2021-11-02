# Egg Dropping Puzzle

You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below.

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

### Recursive Approach

k ==> Number of floors
n ==> Number of Eggs

eggDrop(n, k) ==> Minimum number of trials needed to find the critical
floor in worst case.
eggDrop(n, k) = 1 + min{max(eggDrop(n – 1, x – 1), eggDrop(n, k – x)), where x is in {1, 2, …, k}}

**Concept of worst case:**
For example : Let there be ‘2’ eggs and ‘2’ floors then:

If we try throwing from ‘1st’ floor:
Number of tries in worst case= 1+max(0, 1)
0=>If the egg breaks from first floor then it is threshold floor (best case possibility).
1=>If the egg does not break from first floor we will now have ‘2’ eggs and 1 floor to test which will give answer as
‘1’.(worst case possibility)
We take the worst case possibility in account, so 1+max(0, 1)=2

If we try throwing from ‘2nd’ floor:
Number of tries in worst case= 1+max(1, 0)
1=>If the egg breaks from second floor then we will have 1 egg and 1 floor to find threshold floor.(Worst Case)
0=>If egg does not break from second floor then it is threshold floor.(Best Case)
We take worst case possibility for surety, so 1+max(1, 0)=2.

The final answer is **min(1st, 2nd, 3rd….., kth floor)**

### Code

```cpp
int eggDrop(int egg, int floor)
{
    // if there is 1 floor or no floor,then 1 and 0 trials required
    if (floor == 1 || floor == 0)
        return floor;

    // if there is one egg we try it from gnd to top(no. of floors)
    if (egg == 1)
        return floor;

    int mn = INT_MAX;
    for (int k = 1; k <= floor; k++)
    {
        int temp = 1 + max(eggDrop(egg - 1, k - 1), eggDrop(egg, floor - k)); // max because we have asked worst case
        mn = min(mn, temp);
    }
    return mn;
}
```

### Complexity Analysis

- _Time Complexity_: As there is a case of overlapping sub-problems the time complexity is **exponential**.
- _Auxiliary Space_: **O(1)**, As there was no use of any data structure for storing values.

---

# DP APPROACHES

### A) Memoization

- We take 2D dp array to store the states
- IF state is already calculated then we return the value from dp array
- ELSE we calculate the state and store it in dp array

### Code

```cpp
int dp[201][201];

int eggDropMem(int egg, int floor)
{
    if (floor == 1 || floor == 0)
        return floor;

    if (egg == 1)
        return floor;

    if(dp[egg][floor] != -1)
        return dp[egg][floor];

    int mn = INT_MAX;
    for (int k = 1; k <= floor; k++)
    {
        int temp = 1 + max(eggDropMem(egg - 1, k - 1), eggDropMem(egg, floor - k)); // max because we have asked worst case
        mn = min(mn, temp);
    }
    return dp[egg][floor] = mn;
}

int eggDrop(int n, int k)
{
    memset(dp, -1, sizeof(dp));
    return eggDropMem(n, k);
}
```

### Complexity Analysis

- _Time Complexity_: **O(N\*K)**
- _Auxiliary Space_: **O(N\*K)**

---

### B) Memoization Optimization(Binary Search)

- Instead of linear search we can use binary search to find the threshold floor.

### Code

```cpp
int dp[201][201];
int eggDropMem(int egg, int floor)
{
    if (floor == 1 || floor == 0)
        return floor;

    if (egg == 1)
        return floor;

    if (dp[egg][floor] != -1)
        return dp[egg][floor];

    int mn = INT_MAX, l = 1, r = floor;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int left = eggDropMem(egg - 1, mid - 1); //egg broken check for down floors of mid
        int right = eggDropMem(egg, floor - mid); // not broken check for up floors of mid

        int temp = 1 + max(left, right);
        mn = min(mn, temp);

        if (left > right) //left > right so we will go downward
            r = mid - 1;
        else
            l = mid + 1;
    }
    return dp[egg][floor] = mn;
}

int eggDrop(int n, int k)
{
    memset(dp, -1, sizeof(dp));
    return eggDropMem(n, k);
}
```

### Complexity Analysis

- _Time Complexity_: **O(N\*log K)**

---

### C) Memoization slight more Optimization

- We can check state for left and right in dp array, if present we substitute them else we calculate new state.

### Code

```cpp

int eggDropMem(int egg, int floor)
{
    if (floor == 1 || floor == 0)
        return floor;

    if (egg == 1)
        return floor;

    if (dp[egg][floor] != -1)
        return dp[egg][floor];

    int mn = INT_MAX, l = 1, r = floor;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int left = (dp[egg - 1][mid - 1] != -1 ? dp[egg - 1][mid - 1] : eggDropMem(egg - 1, mid - 1));
        int right = (dp[egg][floor - mid] != -1 ? dp[egg][floor - mid] : eggDropMem(egg, floor - mid));

        int temp = 1 + max(left, right);
        mn = min(mn, temp);

        if (left > right)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return dp[egg][floor] = mn;
}

int eggDrop(int n, int k)
{
    memset(dp, -1, sizeof(dp));
    return eggDropMem(n, k);
}
```

### Reference

- GFG: [Egg Dropping Puzzle](https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/)
- GFG: [Egg Dropping Puzzle optimized](https://www.geeksforgeeks.org/eggs-dropping-puzzle-binomial-coefficient-and-binary-search-solution/)
- YouTube: [AV - Egg Dropping Puzzle](https://www.youtube.com/watch?v=S49zeUjeUL0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=42)
