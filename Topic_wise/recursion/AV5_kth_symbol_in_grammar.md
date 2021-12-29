# Kth symbol in grammar

We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

-   **Observation skills recursion Question**

### Approach:

-   We can observe that every row is double of its previous row, i.e. every row is power of 2(2^n-1). Ex. 1, 2, 4, 8, ...
-   Also we can observe that for every row, first half is same as previous row, and the second half is complement of previous row. Ex. 0, 01, 0110, 01101001, ...
-   So to find k'th symbol in n'th row, We can find prev-k'th symbol in n-1'th row
-   What is **prev-k'th symbol** in grammar?'
    -   from 2'nd we can conclude that,
    -   if k <= mid of row, then k is same (k==k);
    -   else if k > mid of row, then k is `!(k-mid)`,because previous row is half of current row and 2nd half of current row is complement of first row.

### Code

```cpp
int kthGrammar(int n, int k)
{
    if (n == 1 && k == 1)
        return 0;

    int mid = pow(2, n - 1) / 2; // middle of the current row

    if (k <= mid)
        return kthGrammar(n - 1, k);
    else
        return !kthGrammar(n - 1, k - mid);
}
```

### References

-   Leetcode: [Kth symbol in grammar](https://leetcode.com/problems/k-th-symbol-in-grammar/)
-   YouTube:
<iframe width="560" height="315" src="https://www.youtube.com/embed/5P84A0YCo_Y?start=289" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
