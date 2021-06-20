// ? https://www.spoj.com/problems/CSUMQ/

// simple prifix sum problem
// Prefix sum: example
// 3 7 -4 5 -1 -4 7 -->prefix sum array-->add a[i]+a[i-1]
// 3 10 6 11 10 6 13
// complexity O(1) for 1d
// complexity O(n) for 2d

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
        a[i] = a[i] + a[i - 1];

    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        if (l > 0)
            cout << a[r] - a[l - 1] << '\n';
        else
            cout << a[r] << '\n';
    }

    return 0;
}