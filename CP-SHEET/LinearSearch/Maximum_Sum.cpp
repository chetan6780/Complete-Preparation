// ? https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/maximum-sum-4-f8d12458/

// You just need to iterate over all elements of the array and choose those which have a value of greater than or equal to 0. One just needs to avoid silly mistakes and consider corner cases. One such corner case is when all the numbers of the array are negative. In that case, you need to output the maximum number of the array.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    int cnt = 0, mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // if number is positive add to sum and increment count
        if (x >= 0)
        {
            sum += x;
            cnt++;
        }
        // upadte max element from (INT_MIN, elem )
        mx = max(mx, x);
    }

    // if count is increased then print the sum and count else max element and 1
    if (cnt)
        cout << sum << " " << cnt << endl;
    else
        cout << mx << " " << 1 << endl;

    return 0;
}