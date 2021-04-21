// ? https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/mannas-first-name-4/

#include <bits/stdc++.h>
using namespace std;

int countSubstring(const string &str, const string &subst)
{
    if (subst.length() == 0)
        return 0;

    int cnt = 0;

    // loop from position where you find substring them update it with curr_pos+length of substr to find next occurance
    for (int pos = str.find(subst); pos != string::npos;
         pos = str.find(subst, pos + subst.length()))
    {
        cnt++;
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int suvo = countSubstring(s, "SUVO");
        int suvojit = countSubstring(s, "SUVOJIT");
        cout << "SUVO = " << (suvo - suvojit) << ", SUVOJIT = " << suvojit << "\n";
    }
    return 0;
}