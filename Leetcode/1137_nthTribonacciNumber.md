# [1137. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) 🌟

The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

-   **Same Question as fibonacci sequence**

### Recursive Solution(TLE)

### Code

```cpp
class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};
```

### Memoization(Top-Down) (5ms-AC)

### Code

```cpp
class Solution {
private:
    int tribMemo(vector<int>&memo, int n){
        if(n<=1) return n;
        if(n==2) return 1;
        if(memo[n]!=-1) return memo[n];
        return memo[n]=tribMemo(memo,n-1)+tribMemo(memo,n-2)+tribMemo(memo,n-3);
    }
public:
    int tribonacci(int n) {
        vector<int> memo(n+1,-1);
        return tribMemo(memo,n);
    }
};
```

### Tabulation (Bottom-Up) (0ms-AC)

### Code

```cpp
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+3);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};
```

### Optimized Space (0ms-AC)

### Code

```cpp
class Solution {
public:
    int tribonacci(int n)
    {
        if(n<2) return n;
        int first = 0;
        int second = 1;
        int third = 1;
        for (int i = 3; i <= n; i++) {
            int curr = first + second + third;
            first = second;
            second = third;
            third = curr;
        }
        return third;
    }
};
```
