# Maximum Path Sum in a Binary Tree

Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.

### Code

```cpp
int solve(Node *root, int &sum)
{
    if (root == NULL)
        return 0;

    int l = solve(root->left, sum);
    int r = solve(root->right, sum);

    int temp = max(max(l, r) + root->value, root->value);
    int ans = max(temp, l + r + root->value);
    sum = max(sum, ans);

    return temp;
}

int maxSum(Node *root)
{
    int sum = INT_MIN;
    solve(root, sum);
    return sum;
}
```

### Time Complexity: O(n) where n is number of nodes in Binary Tree.

### References

- GFG: [Maximum Path Sum in a Binary Tree](https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/)
- Youtube: [AV - Maximum Path Sum in a Binary Tree](https://www.youtube.com/watch?v=Osz-Vwer6rw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=48)
