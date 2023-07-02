# [Minimum number of Coins](https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1/)

### Algorithm

1. Sort the array of coins in decreasing order.
2. Initialize result as empty.
3. Find the largest denomination that is smaller than current amount.
4. Add found denomination to result. Subtract value of found denomination from amount.
5. If amount becomes 0, then print result.
6. Else repeat steps 3 and 4 for new value of V.

-   GFG: [Link](https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/)

### Code

```cpp

void findMin(int v)
{
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;

    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        while (v >= deno[i])
        {
            v -= deno[i];
            ans.push_back(deno[i]);
        }
    }
    int len = ans.size();
    for (int i = 0; i < len; i++)
        cout << ans[i] << " ";
}
```

### Complexity

-   Time Complexity: O(V)
-   Space Complexity: O(V)
