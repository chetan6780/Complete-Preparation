# Sort an array using recursion.

### Algorithm

1. Sort function.
   - if vector contains only one element, it is sorted in itself.return.
   - Get the last element of the vector.
   - Reduce the size of input for recursion.
   - Recursively sort remaining the vector which has one element less.
   - Insert the element in sorted vector at its right position.
2. Insert function.
   - if vector is empty _OR_ temp is the largest element, then we can directly insert it at last position.
   - else we need to insert temp at it's correct position.
   - Get the last element of the vector and reduce its size by 1.
   - Insert temp recursively.
   - finally insert value which is poped.

It's like insertion sort.

### Code

```cpp

void insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v[v.size() - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }

    int val = v[v.size() - 1];
    v.pop_back();

    insert(v, temp);
    v.push_back(val);
}

void sortArr(vector<int> &v)
{
    if (v.size() == 1)
        return;

    int temp = v[v.size() - 1];
    v.pop_back();

    sortArr(v);
    insert(v, temp);
}
```

### References

- YouTube: [Sort An array using Recursion](https://www.youtube.com/watch?v=AZ4jEY_JAVc&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=6)
