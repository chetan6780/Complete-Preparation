# [Largest Divisible Subset](https://www.codingninjas.com/codestudio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟

**Subset:** A subset is a set that is obtained by removing some or no elements from another set. For example, the set {5, 1, 4} is a subset of {1, 2, 3, 4, 5}.

-   Every subsequence is a subset, but not every subset is a subsequence.

### Modified LIS

-   Modified print LIS code.
-   Sort the input array.
-   While checking for the LIS, we need to check if the current element is divisible by the previous element.
-   Why sort? It ensures that the current element is greater than previous element so we can check divisibility.
-   **TC: O(N^2)**
-   **SC: O(N)**

### Code

```cpp
vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end()); // sort the array
    vector<int> dp(n, 1),idxHash(n);
    int ans = 1, lastIdx = 0;

    for (int i = 0; i < n; i++) {
        idxHash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(arr[i] % arr[prev] == 0){ // changed here
                if(dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    idxHash[i] = prev;
                }
            }
        }
        if(dp[i] > ans){
            ans = dp[i];
            lastIdx = i;
        }
    }
    vector<int> res;
    res.push_back(arr[lastIdx]);
    while(lastIdx != idxHash[lastIdx]){
        lastIdx = idxHash[lastIdx];
        res.push_back(arr[lastIdx]);
    }
    reverse(res.begin(), res.end());
    return res;
}
```
