# [Count subsets with target sum](https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟

### Solution

-   Same Problem as [subset sum equals to K](./14_subsetSumEqualsK.md) problem.
-   We just need to take addition of take and notTake, and take all variables as int.
-   All solutions of subset sum equals to K can be modified to solve this problem, here I am using optimal solution.

### Code

```cpp
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = 1;
    curr[0] = 1;
    if(arr[0]<=k) prev[arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            int take = 0;
            if (arr[i] <= target)
                take = prev[target - arr[i]];
            int notTake = prev[target];
            curr[target] = (take + notTake);
        }
        prev = curr;
    }

    return prev[k];
}
```
