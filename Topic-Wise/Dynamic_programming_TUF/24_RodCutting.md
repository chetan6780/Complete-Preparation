# [Rod cutting](https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?leftPanelTab=0) 🌟🌟

### Solution

-   same as [Unbounded Knapsack](./23_UnboundedKnapsack.md) problem.
-   weight array in knapsack = length array in rod cutting.
-   value array in knapsack = price array in rod cutting

### Code

```cpp
int cutRod(vector<int> &price, int n)
{
    vector<int> len(n,0);
    for (int i = 0; i < n; i++)
        len[i] = i + 1;
    int maxLen = n;
	return unboundedKnapsack(n, maxLen, price, len);
}
```
