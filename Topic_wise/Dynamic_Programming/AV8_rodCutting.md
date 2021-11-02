# Rod cutting

### This is unbounded knapsack problem with change in problem statement.

| Unbounded knapsack 👍        | Rod Cutting                    |
| ---------------------------- | ------------------------------ |
| N: size of the array         | N: size of the rod             |
| Val[]: value of each element | Val[]: value of each length    |
| wt[]: weight of each element | len[]: length of array         |
| W: weight limit              | max_len: lenght of main rod(n) |

```cpp
// Knapsack code here

int cutRod(int price[], int n)
{
    int len[n];
    for (int i = 0; i < n; i++)
        len[i] = i + 1;
    int max_len = n;
    return knapSack(n, max_len, price, len);
}
```

### Complexity Analysis

- Same as unbounded knapsack problem.

### References

- GFG: [Rod cutting](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/)
- Youtube: [AV - Rod cutting](https://www.youtube.com/watch?v=SZqAQLjDsag&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=14)
