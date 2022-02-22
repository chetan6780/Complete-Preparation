# [171. Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) 🌟

Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
```

### Intuitive Solution (AC)

-   We can observe that the number formed is like 26 base number system represented in capital letters.
-   We can for number with `char*26+carry` formula.

### Code

```cpp
class Solution {
public:
    int titleToNumber(string columnTitle)
    {
        int ans = 0;
        for (auto x : columnTitle) {
            int temp = x - 'A' + 1; // 'A'-'A' will be 0 so add 1 in it.
            ans = ans * 26 + temp;
        }
        return ans;
    }
};
```
