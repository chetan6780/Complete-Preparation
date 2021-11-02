# Diameter of binary tree
Given a Binary Tree, find diameter of it.

### Algorithm
Code is self explanatory.

### Code

```cpp
int height(Node *root)
{
    if (root == NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(struct Node *root)
{
    // code here
    if (root == NULL) return 0;

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max({ldiameter, rdiameter, lheight + rheight + 1});
}
```
