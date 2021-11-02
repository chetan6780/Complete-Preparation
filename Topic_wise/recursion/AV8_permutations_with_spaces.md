# Permutaions with spaces

Given a string print all the permutations of string with/without spaces.

### Approach

1. Main function.

   - Initialize empty string.
   - Push first character of string into the output.
   - Remove first character from string.
   - Call recursive function.

2. Recursive function(here getPermutations).
   - If string is empty then we print the output string.
   - We have two choices , either we can choose to add space or do not add space.
   - For op1 we will add space.
   - For op2 we will not add space.
   - Erase the first character from the string.
   - Recursively call getPermutations with reduced input and op1, op2.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void getPermutations(string s, string op)
{
    if (s.size() == 0)
    {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back(' ');
    op1.push_back(s[0]);

    op2.push_back(s[0]);

    s.erase(s.begin() + 0);

    getPermutations(s, op1);
    getPermutations(s, op2);
    return;
}

int main()
{
    string s;
    cin >> s;

    string op = "";
    op.push_back(s[0]);
    s.erase(s.begin() + 0);

    getPermutations(s, op);
    return 0;
}
```

### References

- GFG: [Permutaions with spaces](https://www.geeksforgeeks.org/print-possible-strings-can-made-placing-spaces/)
- YouTube: [Permutaions with spaces](youtube.com/watch?v=1cspuQ6qHW0&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=14)
