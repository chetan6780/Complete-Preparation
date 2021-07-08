# Count Nodes in Binary tree

Given a Binary Tree of size N , You have to count leaves in it.

### Algorithm

1. If node itself is null return 0;
2. If left and right node both are null retrun 1;
3. Recursively count the number of nodes for left and right child.

### Code

```cpp
int countLeaves(Node *root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}
```
