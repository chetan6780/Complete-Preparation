# Rest in peace 21

### Problem Link: [Hackerearth-RIP21](https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/rest-in-peace-21-1/)

### Approach

- The problem is simple you just need to find that number mul of 21 or in its string representation '21' is present

### TODO:

learn [RABIN-KARP ALGORITHM](https://cp-algorithms.com/string/rabin-karp.html) of string matching.

### Code

```cpp

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s = to_string(n);
        if ((n % 21 == 0) || (s.find("21") <= s.length()))
        {
            cout << "The streak is broken!" << endl;
        }
        else
            cout << "The streak lives still in our heart!" << endl;
    }
    return 0;
}
```
