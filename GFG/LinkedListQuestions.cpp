#include <bits/stdc++.h>
using namespace std;

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

// Print Linked List elements ------------------------------------------------------------------
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Reverse a linked list(3 pointer) --------------------------------------------------------------
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

// Reverse a linked list(Recursive)
struct Node *reverse(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = reverse(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}

// Occurence of an integer in a Linked List (Non-recursive) -------------------------------------------
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

// Occurence of an integer in a Linked List (Recursive)
int countRec(struct Node *head, int search_for)
{
    if (head == NULL)
        return 0;
    if (head->data == search_for)
        return 1 + countRec(head->next, search_for);
    return countRec(head->next, search_for);
}

// Pairwise swap elements of a linked list by changing links (non-recursive) ----------------------------
Node *pairWiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = head;
    Node *curr = head->next;

    head = curr;

    while (true)
    {
        Node *next = curr->next;
        curr->next = prev;

        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }

        prev->next = next->next;

        prev = next;
        curr = prev->next;
    }
    return head;
}

// Add two numbers represented by linked lists ---------------------------------------------------------
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void addBack(Node *&head, Node *&last, int data)
{

    Node *newNode = new Node(data);

    if (last == NULL)
        head = newNode;
    else
        last->next = newNode;

    last = newNode;
}
Node *addTwoLists(Node *first, Node *second)
{

    Node *head1 = reverse(first);
    Node *head2 = reverse(second);
    Node *res = NULL;

    Node *last = NULL; // Last node of new list
    int total, carry = 0;

    while (head1 || head2)
    {

        int a = (head1) ? (head1->data) : (0);
        int b = (head2) ? (head2->data) : (0);

        total = (a + b + carry);
        carry = (total / 10);
        total = total % 10;

        addBack(res, last, total);

        if (head1)
            head1 = head1->next;

        if (head2)
            head2 = head2->next;
    }
    if (carry != 0)
        addBack(res, last, carry);

    res = reverse(res);
    return res;
}

// Sorted insert for circular linked list -------------------------------------------------------------

// 1 2 4 --> 1 2 2 4

struct Node *sortedInsert(struct Node *head, int data)
{
    //code here
    Node *current = head;
    Node *newNode = new Node(data);

    if (current == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    // New node is inserted before head (first node)
    else if (current->data >= newNode->data)
    {
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        return newNode;
    }
    // New node is inserted after head
    else
    {
        while (current->next->data < newNode->data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        return head;
    }
}

// Split a Circular Linked List into two halves -----------------------------------------------------------
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if (head == NULL)
        return;

    while (fast_ptr->next != head && fast_ptr->next->next != head)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    // for even number of elements
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    *head1_ref = head;

    if (head->next != head)
        *head2_ref = slow_ptr->next;

    fast_ptr->next = slow_ptr->next;

    slow_ptr->next = head;
}
