# Find the maximum path sum between two leaves of a binary tree

Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.

Note: Here Leaf node is a node which is connected to exactly one different node.

### Code

```cpp
int solve(Node *root, int &sum)
{
    if (root == NULL)
        return 0;

    int l = solve(root->left, sum);
    int r = solve(root->right, sum);

    int temp = max(l, r) + root->value;
    if(root->left==NULL && root->right==NULL)
        temp = max(temp, root->value);
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

### Complexity Analysis

- Time Complexity: **O(N)**
- Auxiliary Space: **O(Height of Tree)**

### References

- GFG: [maximum path sum between two leaves](https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/)
- Youtube: [AV - maximum path sum between two leaves](https://www.youtube.com/watch?v=ArNyupe-XH0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=49)
