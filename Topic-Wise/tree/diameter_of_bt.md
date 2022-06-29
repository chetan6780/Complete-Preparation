# Diameter of binary tree

The diameter ( width ) of a tree is the number of nodes on the longest path between two end nodes.

### Algorithm

The longest path between leaves that goes through a particular node say, nd can be calculated as:
**1 + height of left subtree of nd + height of right subtree of nd**

Therefore, final Diameter of a node can be calculated as:
**Diameter = maximum(lDiameter, rDiameter, 1 + lHeight + rHeight)**

### Code

```cpp

int height(node *node)
{
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

int diameter(node *tree)
{
    if (tree == NULL)
        return 0;

    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    int lheight = height(tree->left);
    int rheight = height(tree->right);

    return max({ldiameter, rdiameter, lheight + rheight + 1});
}
```
### complexity
- Time Complexity: O(N^2)