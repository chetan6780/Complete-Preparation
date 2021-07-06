# Level Order Traversal in Binary Tree

The Level Order Traversal can be implemented efficiently using a Queue.

### Algorithm

1. Create an empty queue q.
2. Push the root node of tree to q.
3. Loop while the queue is not empty:
   - Pop the top node from queue and print the node.
   - Enqueue node's children (first left then right children) to q
   - Repeat the process until queue is not empty.

### Code

```cpp

void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue
    queue<Node *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";

        // Enqueue left child and then right child
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
```

### Time Complexity:

**O(N)**, where N = number of nodes in the Tree.

### Auxiliary Space:

**O(N)**
