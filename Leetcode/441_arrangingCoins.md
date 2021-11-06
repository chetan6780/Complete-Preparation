# [441. Arranging Coins](https://leetcode.com/problems/arranging-coins/) 🌟

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

### Simulation

- We can just simulate the process of building the staircase.
- Assume we have k as result, `1+2+...+i = N`, then `i*(i+1) = 2N => i^2 = N => i = sqrt(N)`
- **Time Complexity: O(sqrt(n))**

### Code

```cpp
class Solution{
public:
    int arrangeCoins(int n){
        long i = 0, sum = 0;
        while (sum <= n){
            i++;
            sum += i;
        }
        return i - 1;
    }
};
```

### Binary Search

- The problem can be converted into - Find the maximum k such that `k*(k+1)/2 <= n`.
- **Time Complexity: O(logN)**

### Code

```cpp
class Solution{
public:
    int arrangeCoins(int n){
        long long l = 0, r = n;
        long long mid = 0, total = 0;
        while (l <= r){
            mid = l + (r - l) / 2;
            total = mid * (mid + 1) / 2;
            if (total == n)
                return ((int)mid);
            if (n < total)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return ((int)r);
    }
};
```

### Math solution

- As we know the number of coins in each staircase are forming an AP `Eg :- 1+2+3+...+a = n`
  Sum of all terms of AP :- `(1+a)a/2 = n`
  n is given to us in question, we have to find a
- ```
  ===> a ^ 2 + a = 2 n
  ===> x ^ 2 + a + 1/4 = 2 n +1/4
  ===> (a + 1/2 ) ^ 2 = 2n + 1/4
  ===> (a + 0.5) = sqrt( 2n + 1/4 )
  ===> a = -0.5 + sqrt( 2n + 1/4 )
  ```
- We have calculated the value of `a = -0.5 + sqrt( 2\*n + 1/4 )`
- **Time Complexity: O(1)**

### Code

```cpp
class Solution{
public:
    int arrangeCoins(int n){
        return floor(-0.5 + sqrt((double)2 * n + 0.25));
    }
};
```
