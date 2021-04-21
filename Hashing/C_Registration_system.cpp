// ? https://codeforces.com/problemset/problem/4/C

// we will use unordered_map since order does not matter for this problem

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    unordered_map<string, int> mp;
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        if (mp[v[i]] == 0)
            cout << "OK" << nl;
        else
            cout << v[i] << mp[v[i]] << nl;

        mp[v[i]]++;
    }

    return 0;
}