# Deletion in binary tree

Given a Binary Tree and a node to be deleted from this tree. The task is to delete the given node from it.

### Cases

1. If node to be deleted is leaf node.
2. If node to be deleted is internal node.
3. If node to be deleted is root node.

- for 1 we just delete leaf node directly.
- for 2 and 3 we need to follow the algorithm

### Algorithm

1. Find the **deepest and rightmost node** in binary tree and node which we want to delete.
2. Replace the deepest rightmost node’s data with the node to be deleted.
3. Then delete the deepest rightmost node.

### Code
The code is self explanatory.

```cpp

// Function to delete the given deepest node (d_node) in binary tree
void deletDeepest(Node *root, Node *d_node)
{
    queue<Node *> q;
    q.push(root);

    // level order traversal until last node
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->right)
        {
            // if this is node to be deleted, delete it
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            // if this is node to be deleted, delete it
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

// Function to delete element in binary tree
void deletion(Node *root, int key)
{
    queue<Node *> q;
    q.push(root);

    Node *deepNode;
    Node *key_node = NULL;

    // Last node of level order traversal is the deepest rightmost node, So
    // level order traversal to find deepest node(deepNode) and node to be deleted (key_node)
    while (!q.empty())
    {
        // store front in deepNode variable
        deepNode = q.front();
        q.pop();

        // find node to be deleted by comparing given data with node's data
        if (deepNode->key == key)
            key_node = deepNode;

        // Enqueue left and right node in queue
        if (deepNode->left)
            q.push(deepNode->left);
        if (deepNode->right)
            q.push(deepNode->right);
    }

    // copy data of deepest rightmost node.
    int x = deepNode->key;

    // delete deepest node
    deletDeepest(root, deepNode);

    // set copied value of deepest node to node to be deleted
    key_node->key = x;
}
```
