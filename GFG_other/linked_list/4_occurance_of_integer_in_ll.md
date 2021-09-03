# Occurance of an integer in linked lists

## 1. Itterative

### Algorithm

1. Initialize count as zero.
2. Loop through each element of linked list:
   - If element data is equal to the passed number then
     increment the count.
3. Return count.

### Code

```cpp
int count(struct Node *head, int search_for)
{
    struct Node *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        if (temp->data == search_for)
            cnt++;
        temp = temp->next;
    }
    return cnt;
}
```

## 2. Recursive

### Algorithm

```
count(head, key);
if head is NULL
return frequency
if(head->data==key)
increase frequency by 1
count(head->next, key)
```

### Code

```cpp
int countRec(struct Node *head, int search_for)
{
    if (head == NULL)
        return 0;
    if (head->data == search_for)
        return 1 + countRec(head->next, search_for);
    return countRec(head->next, search_for);
}
```

### Time Complexity: O(N)

### References

- GFG: [Occurance of an integer in linked lists](https://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/)
