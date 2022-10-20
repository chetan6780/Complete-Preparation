# [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) 🌟

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

### Tip by striver to find if a problem can be solved by dp.

-   Problem asks all possible ways, min/max ways, use dp.

### Shortcut to write dp solution

1. Try to represent problem in terms of indexes.
2. Do all possible operations on that index according to steps.
3. Sum/find min/ find max of all steps according to the problem description.

### Solution

-   This problem is same as fibonacci series. `F(n) = F(n-1) + F(n-2)`, so all solution of fibonacci is also solution of this question.
-   Just in codestudio, you need to use matrix exponentiation in order to get AC as range of input there is 10^18.
