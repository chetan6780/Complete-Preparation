# [119. Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/) 🌟

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown

### Recursive Solution

1. What we know?
    - We Know that, if `rowIndex==0` (first row) then we only have `{1}` in the row.
    - We also know that first and last element of our row will be `1` **always**.
    - We also Know that we can find `currentRow[i]` by adding `previousRow[i]` and `previousRow[i+1]`.
2. Data for recursion,
    - from above discussion, now we can get 2 important things for recursion
    1. **Base Case:** `if(rowIndex==0) return {1};`
    2. **Recurrence Relation:** `currentRow[i] = (previousRow[i-1]+previousRow[i]);`
> Before reading out please give it a try now.
3. Algorithm
    - We can start with `currentRow[0] = 1`
    - Now **believe** that, we get the previous row with recursive call `previousRow = getRow(rowIndex-1);`
    - Then fill the remaining elements of current row with recurrence relation 
        `currentRow[i] = (previousRow[i-1]+previousRow[i]);`
    - As we know, last element of row is 1, push 1 in the vector.
    - Return the current row i.e. `currentRow`.

### Code

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return {1}; // Base Case

        vector<int> currentRow = {1}; // current row with 1 value in it
        vector<int> previousRow = getRow(rowIndex-1); // get the previous row

        // Now fill the current row based on previous row
        for(int i=1;i<rowIndex;i++){
            currentRow.push_back(previousRow[i-1]+previousRow[i]);
        }

        currentRow.push_back(1); // fill the last element of current row
        return currentRow;
    }
};
```
