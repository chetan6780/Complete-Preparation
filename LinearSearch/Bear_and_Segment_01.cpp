// ? https://www.codechef.com/problems/SEGM01

// this is simple problem we'll check if 1 appear 1ce and then if it apperas after o agin the ans will be no otherwise yes

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        bool flag = false;
        int cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1' && flag == false)
            {
                cnt++;
                flag = true;
            }
            else if (s[i] == '0')
                flag = false;
        }

        if (cnt == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}