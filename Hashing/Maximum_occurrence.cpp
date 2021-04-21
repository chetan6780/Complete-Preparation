// ? https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/maximum-occurrence-9/

// in this example we simply use map so we can get frequency of charecter in increasing order of thier ASCII value then we simply update our ans and charecter and then lastly print them

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