# Kth symbol in grammar

We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

### Code

```cpp
int kthGrammar(int n, int k)
{
    if (n == 1 && k == 1)
        return 0;

    int mid = pow(2, n - 1) / 2;
    if (k <= mid)
        return kthGrammar(n - 1, k);
    else
        return !kthGrammar(n - 1, k - mid);
}
```

### References

- Leetcode: [Kth symbol in grammar](https://leetcode.com/problems/k-th-symbol-in-grammar/)
- YouTube: [Kth symbol in grammar](https://www.youtube.com/watch?v=5P84A0YCo_Y&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=11)
