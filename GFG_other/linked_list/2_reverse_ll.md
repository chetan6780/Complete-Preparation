# Reverse a Linked List

Given a linked list of N nodes. The task is to reverse this list.

### 1. Itterative

### Algorithm

- Initialize three pointers prev as NULL, curr as head and next as NULL.
- Iterate through the linked list. In loop, do following.
  // Before changing next of current, store next node
  next = curr->next
  // Now change next of current This is where actual reversing happens
  curr->next = prev
  // Move prev and curr one step forward
  prev = curr
  curr = next

### Code

```cpp
struct Node *reverseList(struct Node *head)
{
    Node *curr = head;
    Node *prev = NULL, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
```

### 2. Recursive

### Algorithm

1. Divide the list in two parts - first node and
   rest of the linked list.
2. Call reverse for the rest of the linked list.
3. Link rest to first.
4. Fix head pointer

### Code

```cpp
struct Node *reverse(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = reverse(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}
```

### Reference

- GFG: [Reverse a Linked List](https://www.geeksforgeeks.org/reverse-a-linked-list/)
