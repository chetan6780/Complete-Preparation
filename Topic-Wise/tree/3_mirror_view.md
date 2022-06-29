# Are mirror views?

Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.

### Algorithm
1. if first and second nodes are null return true.
2. If Data of first and second nodes is not equal return false.
3. Else recursively check if left and right nodes are mirror or not.

### Code

```cpp
int areMirror(Node *a, Node *b)
{
    if (a == NULL && b == NULL) return 1;
    if (a->data != b->data) return 0;
    return areMirror(a->left, b->right) && areMirror(a->right, b->left);
}
```
