# [Minimum subset sum difference](https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0)

Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

-   This problem is similar to [subset sum equals to K](./14_subsetSumEqualsK.md) problem.

### Solution

-   Suppose `totalSum` = sum of all elements in the array.
-   `s1` is sum of first subset and `s2` is sum of second subset.
-   To minimize difference, `abs(s1 - s2) = min`.
-   we have,
    -   `abs(s1 - s2) = min`
    -   `abs((totalSum - s1) - s2) = min`
    -   `abs(totalSum - 2*s1) = min`
-   So we need to find such `s1`(subset sum of first subset) that `abs(totalSum - 2*s1)` is minimum.
-   From [subset sum equals to K](./14_subsetSumEqualsK.md) problem we have data if it is possible to have subset sum equals to `K`, we can use to solve this problem.
-   We check for every `K` (= `s1`) , minimum value.
-   And it can be proved that we don't need to check all the `K`'s as after half iteration values will start repeating.
-   All solutions of subset sum equals to `K` can be modified to solve this problem, here I am using optimal solution.

### Code

```cpp
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int k = accumulate(arr.begin(),arr.end(), 0); // New code

    // Previous code for subset sum equals to K Problem
	vector<bool> prev(k + 1, false), curr(k + 1, false);
    prev[0] = true;
    curr[0] = true;
    if(arr[0]<=k) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        prev[0] = true; // from base case
        for (int target = 1; target <= k; target++) {
            bool take = false;
            if (arr[i] <= target)
                take = prev[target - arr[i]];
            bool notTake = prev[target];
            curr[target] = (take || notTake);
        }
        prev = curr;
    }

    // New code below
    int res = INT_MAX;
    for(int currSum = 0; currSum<=k/2; currSum++){
        if(prev[currSum]==true){
            res = min(res, k-2*currSum);
        }
    }
    return res;
}
```
