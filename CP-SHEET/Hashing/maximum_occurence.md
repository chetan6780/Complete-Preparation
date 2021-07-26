# Maximum occurence

Given a string find out which character occurs the maximum number of times and the number of its occurrence, in the given string. If two characters occur equal number of times, you have to output the character with the lower ASCII value.

### Problem link: [Hackerearth-MO9](https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/maximum-occurrence-9/)

### Approach

- In this example we simply use map so we can get frequency of charecter in increasing order of their ASCII value.
- We simply update our ans and charecter and then print them.

### Code

```cpp

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    char ans;
    int mx = INT_MIN;
    for (auto x : mp)
    {
        if (mx < x.second)
        {
            mx = x.second, ans = x.first;
        }
    }
    cout << ans << ' ' << mx;

    return 0;
}
```
