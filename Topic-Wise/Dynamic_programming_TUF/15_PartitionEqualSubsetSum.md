# [Partition Equal Subset Sum](https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980) 🌟🌟

-   If we carefully think of this problem, we can see that it is similar to the subset sum problem.
-   Here we just need to divide array into two parts and find if its sum is equal to half of the total sum of array.
-   If sum of array is odd then we can't divide it into two parts with equal sum.
-   All the solutions for subset sum problem can be used here.

### Solution

````cpp
bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for(int i = 0; i< n; i++){
        sum+=arr[i];
    }
    if(sum%2==1) return false;
    return subsetSumToK(n,sum/2,arr);
}
````
