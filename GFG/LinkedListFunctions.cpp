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

// ==================================================================================================================

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

// Rotate linked list clockwise ---------------------------------------

Node* rightRotate(Node* head, int k)
{
 
    if (!head)
        return head;
 
    Node* tmp = head;
    int len = 1;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        len++;
    }
 
    if (k > len)
        k = k % len;
 
    k = len - k;
 
    if (k == 0 || k == len)
        return head;
 
    Node* current = head;
    int cnt = 1;
    while (cnt < k && current != NULL) {
        current = current->next;
        cnt++;
    }
 
    if (current == NULL)
        return head;
 
    Node* kthnode = current;
 
    tmp->next = head;
 
    head = kthnode->next;
 
    kthnode->next = NULL;
 
    return head;
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
// to avoid some confusion *head1_ref = temp1 ,  head2_ref = temp2
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

// Detect loop in a linked list(Floyd’s Cycle-Finding Algorithm) FASTEST method (O(n),O(1)) ------------------
bool detectLoop(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
            return true;
    }
    return false;
}

// using hashing (O(n),O(n))
bool detectLoop(Node *head)
{
    unordered_set<Node *> s;

    while (head != NULL)
    {
        if (s.find(head) != s.end())
            return true;
        s.insert(head);

        head = head->next;
    }
    return false;
}

// simple approach (O(n),O(1))
// This is the simplest approach of the given problem, the only thing we have to do is to assign a new value to each data of node in the linked list which is not in the given constrins of data.
bool detectLoop(Node *head)
{
    if (!head)
        return false;

    while (head != NULL)
    {
        if (head->data == -1)
            return true;
        else
        {
            head->data = -1;
            head = head->next;
        }
    }
    return false;
}

// Delete Middle of Linked List ---------------------------------------------------------------------------------------------
Node *deleteMid(struct Node *head)
{
    // Base cases
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *slow_ptr = head;
    Node *fast_ptr = head;

    Node *prev;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    // Delete the middle node
    prev->next = slow_ptr->next;
    delete slow_ptr;

    return head;
}

// Deletion at different positions in a Circular Linked List ------------------------------------------------
Node *deleteAtPosition(Node *head, int pos)
{
    Node *prev = head;
    if (pos == 1)
    {
        while (prev->next != head)
            prev = prev->next;
        Node *temp = head;
        prev->next = temp->next;
        head = prev->next;
        free(temp);
        return head;
    }

    for (int i = 1; i < pos - 1; i++)
        prev = prev->next;
    Node *temp = prev->next;
    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to delete a node without any reference to head pointer -------------------------------------------
void deleteNode(Node *pos)
{
    Node *temp = pos->next;

    pos->data = pos->next->data;

    pos->next = pos->next->next;

    free(temp);
}

// Reverse a Linked List in groups of given size O(n) & O(n/k)-------------------------------------------------
Node *reverse(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    Node *curr = head;
    Node *prev = NULL, *next = NULL;

    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
        head->next = reverse(next, k);

    return prev;
}

// Intersection point in y shaped linked list (Below is a link where 8 method are described) ----------------------
// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

// Method 3 (Using difference of node counts) ==== O(m+n), O(1) ====
int length(Node *head)
{
    Node *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int getIntersection(Node *head1, Node *head2, int d)
{
    Node *curr1 = head1;
    Node *curr2 = head2;

    for (int i = 0; i < d; i++)
    {
        // if there is no intersection then return -1;
        if (curr1 == NULL)
            return -1;
        curr1 = curr1->next;
    }

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 == curr2)
            return curr1->data;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return -1;
}

int intersectPoint(Node *head1, Node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d;

    if (l1 > l2)
    {
        d = l1 - l2;
        return getIntersection(head1, head2, d);
    }
    else
    {
        d = l2 - l1;
        return getIntersection(head2, head1, d);
    }
}

// Method 8( 2-pointer technique ) ==== O(m+n), O(1) ====

Node *intersectionPoint(Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;

    // if there is no intersection point
    if (curr1 == NULL || curr2 == NULL)
        return NULL;

    while (curr1 != curr2)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;

        if (curr1 == curr2)
            return curr1;

        // if they reach to the end of there respective linked list then
        // assign them alternate heads this time
        if (curr1 == NULL)
            curr1 = head2;
        if (curr2 == NULL)
            curr2 = head1;
    }
    // if first position itself is intersection point then this return statement work
    return curr1;
}

// QuickSort on Singly Linked List -----------------------------------------------------------------------------

Node *getTail(Node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

Node *quickSortRecur(Node *head, Node *end)
{
    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

// Clone a linked list with next and random pointer O(n),O(1),modified LL ----------------------------------------------------
struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *start)
{
    Node *curr = start, *temp;

    while (curr)
    {
        temp = curr->next;

        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = start;

    while (curr)
    {
        if (curr->next)
            curr->next->arb = curr->arb ? curr->arb->next : curr->arb;

        curr = curr->next ? curr->next->next : curr->next;
    }

    Node *original = start, *copy = start->next;

    temp = copy;

    while (original && copy)
    {
        original->next =
            original->next ? original->next->next : original->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}

// merge sort on linked list -------------------------------------------------------------------------------------

// doubly LL
struct Node
{
    int data;
    struct Node *next, *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

Node *split(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

Node *merge(Node *first, Node *second)
{
    if (!first)
        return second;

    if (!second)
        return first;

    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

// QuickSort on Doubly Linked List -------------------------------------------------------------------------
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

Node *partition(Node *l, Node *h)
{
    int x = h->data;

    Node *i = l->prev;

    for (Node *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            i = (i == NULL) ? l : i->next;

            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL) ? l : i->next; 
    swap(&(i->data), &(h->data));
    return i;
}

void _quickSort(Node *l, Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

void quickSort(Node *head)
{
    Node *h = lastNode(head);

    _quickSort(head, h);
}

// ================================================== END ===========================================================