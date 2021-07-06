# Binary Tree Traversals

1. Preorder (DLR)
2. Inorder (LDR)
3. Postorder (LRD)

## 1. Preorder (DLR)

### Algorithm

```
1. Visit the root (print data).
2. Traverse Left subtree.
3. Traverse Right subtree.
```

### code

```cpp
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
```

## 2. Inorder (LDR)

### Algorithm

```
1. Traverse Left subtree.
2. Visit the root (print data).
3. Traverse Right subtree.
```

### code

```cpp

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
```

## 3. Postorder (LRD)

### Algorithm

```
1. Traverse Left subtree.
2. Traverse Right subtree.
3. Visit the root (print data).
```

### code

```cpp

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
```
