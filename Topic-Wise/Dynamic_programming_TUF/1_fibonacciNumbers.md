# [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/) 🌟

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given `n`, calculate `F(n)`.

### Recursive Solution

-   We know that `F(0) = 0` and `F(1) = 1`.
-   And we can also find that `F(n) = F(n - 1) + F(n - 2)` for `n > 1`.
-   We can simply calculate `F(n)` by using the above formula in a recursive way.

### Code

```cpp
class Solution {
public:
    int fib(int n)
    {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};
```

### Memoization(Top-Down) Method

-   We can observe that in the recursive code we are doing the same calculations over and over again.
-   We can store these calculations in an array or vector, so next time if we encounter the same problem we can directly return the stored result for that problem.
-   Here we initialize a vector of size `n + 1` and fill it with `-1` to indicate that we have not calculated the value for that index yet.
-   Every time we call recursively, we store the calculated value in the vector.
-   If we encounter a value that has already been calculated, we simply return the stored value.
-   **TC: O(N)**
-   **SC: O(N)+O(N) = ~O(N)**, a recursion stack space(O(N)) and an array (again O(N))

### code

```cpp
class Solution {
private:
    int fibHelper(int n, vector<int>& dp)
    {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n]; // Return the Value, if already calculated
        return dp[n] = fibHelper(n - 1, dp) + fibHelper(n - 2, dp); // Calculate and store the value
    }

public:
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return fibHelper(n, dp);
    }
};
```

### Tabulation(Bottom-Up) Method

-   we can also use a tabulation method to solve this problem.
-   Store `dp[0]=0` and `dp[1]=1` in dp array or vector.
-   Now we can iterate from 2 to n inclusive and find `dp[i] = dp[i - 1] + dp[i - 2]`
-   Here we need base case for n=0.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    int fib(int n)
    {
        if(n<=1) return n; // Base condition require, if n=0 the dp[1] will give error
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```

### Space Optimized DP Solution

-   From above DP solution we are just calculating the `current value` by adding `previous` and `previous's previous value`.
-   So we don't need to store all `n` elements in an array, we can use `prev2` to store previous's previous value and `prev` to store previous value.
-   We can calculate current value by `curr = prev + prev2`.
-   next, we store prev in `prev2` and curr in `prev`.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int fib(int n)
    {
        if (n <= 1) return n;
        int prev2 = 0, prev = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
```
