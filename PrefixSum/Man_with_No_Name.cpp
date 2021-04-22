// ? https://www.codechef.com/problems/BLONDIE

// Below are 2 solutions both passes all testcases
// But Editorials solution 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// ---------------------------------------------------------------------------------------------------------

// the main idea is to calculate prefix sum , BUT for -1 we will add sumOfPrev+(sumOfPrev/totalTravel)
// print arr i.e. b[i]-b[i-1]

// My solution:

// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n;
//         cin >> n;
//         vector<ll> b(n);
//         for (ll i = 0; i < n; i++)
//         {
//             cin >> b[i];
//         }

//         for (ll i = 1; i < n; i++)
//         {
//             if (b[i] == -1)
//                 b[i] = (b[i - 1] / i) + b[i - 1] ;
//             else
//                 b[i] = b[i] + b[i - 1];
//         }

//         cout << b[0] << " ";
//         for (ll i = 1; i < n; i++)
//         {
//             cout << b[i] - b[i - 1] << " ";
//         }

//         cout << '\n';
//     }
//     return 0;
// }
// ---------------------------------------------------------------------------------------------------------
// Editorial solution
// time complexity: O(N)
// space complexity:O(1)
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;

        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;

            if (temp < 0)
            {
                temp = sum / i;
            }
            cout << temp << ' ';
            sum += temp;
        }
        cout << '\n';
    }
    return 0;
}