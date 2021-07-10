# Sum tree

Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return 0.

### Algorithm

1. If the node is null or it's left node then return 1.
2. Check for sum tree on left and right subtree.
   - If subtree is null return 0.
   - else If subtree is left node return it's data.
   - else return 2\*(subtree data)
   - Finally return if node->data is equal to left sum+right sum.
3. Return 0.

### Code

```cpp
// check if its a leaf node or not.
int isLeaf(Node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

int isSumTree(Node *node)
{
    int ls, rs;

    if (node == NULL || isLeaf(node))
        return 1;

    if (isSumTree(node->left) && isSumTree(node->right))
    {
        // Get the sum of nodes in left subtree
        if (node->left == NULL)
            ls = 0;
        else if (isLeaf(node->left))
            ls = node->left->data;
        else
            ls = 2 * (node->left->data);

        // Get the sum of nodes in right subtree
        if (node->right == NULL)
            rs = 0;
        else if (isLeaf(node->right))
            rs = node->right->data;
        else
            rs = 2 * (node->right->data);

        return (node->data == ls + rs);
    }
    return 0;
}
```
