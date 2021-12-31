# Subsets of the String

Print all subsets of a given string using recursion.

### Approach

1. Main function.

   - Get string as input.
   - Initialize empty output string.
   - Call the recursive function which gets all the substrings.

2. Recursive function(here getSubstring).

   - If string is empty, then print output string and return.
   - Create two string for which we choose option to take input or not.
   - for op1 we choose not to take input.
   - for op2 we choose to take input(i.e. first character of string(ip)).
   - Erase the first character of the string because we have taken it in op2.
   - Call recursively with reduced input(i.e. string).

3. If want only unique subsets then store the values in unordered_set/set and you can print them later.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void getSubstring(string s, string op)
{
    if (s.size() == 0)
    {
        cout << op << ' ';
        return;
    }

    string op1 = op;
    string op2 = op;
    op2.push_back(s[0]);

    s.erase(s.begin() + 0);

    getSubstring(s, op1);
    getSubstring(s, op2);
    return;
}

int main()
{
    string s;
    cin >> s;

    string op = "";

    getSubstring(s, op);
    return 0;
}
```

### References

- GFG: [Subsets of the String](https://www.geeksforgeeks.org/recursive-program-to-generate-power-set/)
- Youtube: [Subsets of the String](https://www.youtube.com/watch?v=Yg5a2FxU4Fo&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=12)
