# Letter case permutation

Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any

### Algorithm

1. letterCasePermutations function.

   - Get the ip/op string, initialize Input with s and output with empty string.
   - Create a vector to store the answer and call getPermutaions.
   - Returns the vector with all the permutations of the input string.

1. getPermutaions function.
   - If input is empty, push back the output and return.
   - If the first character of the string is alphabet, then we do following...
     - Initialize two outputs with original oputput string.
     - In the first output, push the lowercase of first character of string.
     - In the second output, push the uppercase of first character of string.
     - Erase the first character of the input string, i.e. reduce the input.
     - Recursively call the function to get permutations of op1 and op2 strings.
   - else the first character is number.
     - Initialize new output with original output value.
     - Push the first character in original output.
     - Erase the first character from input string.
     - Get permutations for op1.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void getPermutaions(string ip, string op, vector<string> &v)
{
    if (ip.length() == 0)
    {
        v.push_back(op);
        return;
    }

    if (isalpha(ip[0]))
    {
        string op1 = op;
        string op2 = op;

        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));

        ip.erase(ip.begin() + 0);

        getPermutaions(ip, op1, v);
        getPermutaions(ip, op2, v);
    }
    else
    {
        string op1 = op;

        op.push_back(ip[0]);

        ip.erase(ip.begin() + 0);

        getPermutaions(ip, op1, v);
    }
}

vector<string> letterCasePermutations(string s)
{
    string ip = s;
    string op = "";

    vector<string> v;
    getPermutaions(ip, op, v);

    return v;
}
```

### References

- Leetcode: [Letter case permutation](https://leetcode.com/problems/letter-case-permutation/)
- Youtube: [Letter case permutation](https://www.youtube.com/watch?v=4eOPYDOiwFo)
