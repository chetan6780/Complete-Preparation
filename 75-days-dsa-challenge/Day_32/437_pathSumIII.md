# [437. Path Sum III](https://leetcode.com/problems/path-sum-iii/)

### O(N^2) Brute force

-   The problem is similar to array problem - subarray sum equals k.
-   So in like in array problem, we can traverse all the paths of the tree and count the number of paths that sum up to k.
-   **Time complexity: O(N^2)**

### Code

```cpp
class Solution {
private:
    int ans = 0;

    void findPathSum(TreeNode* root, int targetSum, long long currSum)
    {
        if (root == nullptr) return;

        // Add root's value in currSum.
        currSum += root->val;
        // if we found the sum incriment ans
        if (currSum == targetSum) ans++;
        // traverse left ans right
        findPathSum(root->left, targetSum, currSum);
        findPathSum(root->right, targetSum, currSum);
    }

public:
    int pathSum(TreeNode* root, int targetSum)
    {
        if (root == NULL) return 0;

        findPathSum(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ans;
    }
};
```

### O(N) Optimized

-   Like the optimization in array problem, Here also we use same technique.
-   We traverse all the path in the tree and keep track of the sum of the path in hashmap.
-   If we found `currSum - targetSum` in the hashmap, then we found a path that sum up to targetSum and we increment ans by its frequency.
-   increment the frequency of currSum in the hashmap.
-   Traverse left and right.
-   Decrement the frequency of currSum in the hashmap, if 0 erase it.
-   The above step, because we want to find the next path so the current path will be unvisited and the currSum will not have it's root's value in it.
-   **Time complexity: O(N)**
-   **Space complexity: O(N)**

### Code

```cpp

class Solution {
private:
    int ans = 0;
    map<int, int> mp;
    void findPathSum(TreeNode* root, long long currSum, int targetSum)
    {
        if (root == NULL) return;

        // Add root's value in currSum.
        currSum += root->val;

        // found the path
        if (mp.count(currSum - targetSum)) ans += mp[currSum - targetSum];

        // traverse all the paths by going left and right
        mp[currSum]++;
        findPathSum(root->left, currSum, targetSum);
        findPathSum(root->right, currSum, targetSum);
        mp[currSum]--;

        // erase if frequency is 0
        if (mp[currSum] == 0) mp.erase(currSum);
        return;
    }

public:
    int pathSum(TreeNode* root, int targetSum)
    {
        if (root == NULL)
            return 0;

        mp[0] = 1;
        findPathSum(root, 0, targetSum);
        return ans;
    }
};
```
