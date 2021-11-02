# Root to leaf path sum

Given a binary tree and an integer S, check whether there is root to leaf path with its sum as S.

### Algorithm

Recursively check if left or right child has path sum equal to ( number – value at current node).

### Code

```cpp
bool hasPathSum(Node *root, int S)
{
    bool ans = false;
    int subSum = S - root->data;

    // If we reach to the leaf node and sum is 0 return true
    if (subSum == 0 && root->left == NULL && root->right == NULL)
        return 1;

    // check for both subtree
    if (root->left)
        ans = ans || hasPathSum(root->left, subSum);
    if (root->right)
        ans = ans || hasPathSum(root->right, subSum);

    return ans;
}
```
