# Determine if Two Trees are Identical

Given two binary trees, the task is to find if both of them are identical or not.

### Algorithm

1. if node is null return true.
2. return
   - both node are not null.
   - there data is same and.
   - Recur for left and right node.

### Code

```cpp
bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;
    return (r1 && r2) && (r1->data == r2->data) &&
            isIdentical(r1->left, r2->left) &&
            isIdentical(r1->right, r2->right);
}
```
