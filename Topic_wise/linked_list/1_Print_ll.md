w# Print Linked List

### Code

```cpp
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
```

### Time Complexity
**O(N)**, where **N** is the number of nodes in the linked list.