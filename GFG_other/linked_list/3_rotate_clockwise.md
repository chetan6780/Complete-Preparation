# Rotate linked list clockwise

### Algorithm

- If linked list is empty return head.
- Calculate the length of the linked list.
- If k is greater than the length of the linked list then deduct k by using modulo.
- Substract k from length so the problem becomes left rotation of linked list.
- if k is 0 or equal to length of ll return original ll head.
- Get to the last(kth) node.Current will either point to kth or NULL after this loop.
- Current points to null then dont change the ll.
- Current points to the kth node.(Original logic)
  - Change next of last node to previous head.
  - Change head to (k+1)th node.
  - Change next of kth node to NULL.
  - Return the updated head pointer.

### Code

```cpp
Node *rightRotate(Node *head, int k)
{
    // if linked list is empty return head
    if (!head)
        return head;

    // calculate the length of the linked list
    Node *temp = head;
    int len = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }

    // if k is greater than the length of the linked list then deduct k by using modulo
    if (k > len)
        k = k % len;

    // substract k from length so the problem becomes left rotation of linked list
    k = len - k;

    // if k is 0 or equal to length of ll return original ll head
    if (k == 0 || k == len)
        return head;

    // Get to the last(kth) node
    // current will either point to kth or NULL after this loop
    Node *current = head;
    int cnt = 1;
    while (cnt < k && current != NULL)
    {
        current = current->next;
        cnt++;
    }

    // Current points to null then dont change the ll
    if (current == NULL)
        return head;

    // Current points to the kth node
    Node *kthnode = current;

    // Change next of last node to previous head
    temp->next = head;

    // Change head to (k+1)th node
    head = kthnode->next;

    // Change next of kth node to NULL
    kthnode->next = NULL;

    // Return the updated head pointer
    return head;
}
```

### Time Complexity: O(n)

### References

- GFG: [Rotate linked list clockwise](https://www.geeksforgeeks.org/clockwise-rotation-of-linked-list/)
