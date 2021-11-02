# Mirror Tree

### Algorithm

- The idea is to recursively call for left and right subtrees of a given node.
- On each recursive call swap the pointers of the children nodes.

### Code

```cpp
void mirror(Node *node)
{
    if (node == NULL)
        return;
    else
    {
        Node *temp;

        // Recur for subtrees
        mirror(node->left);
        mirror(node->right);

        // swap the pointers in this node
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
```
