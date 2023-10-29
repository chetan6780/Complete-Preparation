# [Palindrome Reorder](https://cses.fi/problemset/task/1755/)

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

### Explanation

-   we can form palindrome if there are same number of characters if we divide the string into two parts.
-   The catch is if string is odd length then we can have any 1 character with odd frequency.
-   Just check frequency of each character and if there is more than 1 character with odd frequency then print "NO SOLUTION".
-   else print the string in this order: `even frequency characters + odd frequency character + reverse of even frequency characters`.

### Code

```cpp
// ff: first, ss: second
void solve()
{
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto& i : s) {
        mp[i]++;
    }
    int odd = 0;
    string ans;
    for (auto& i : mp) {
        if (i.ss & 1) {
            odd++;
            if (odd > 1) {
                print("NO SOLUTION");
                return;
            }
            ans += i.ff;
            i.ss--;
        }
    }

    string temp = "";
    for (auto& i : mp) {
        for (int j = 0; j < i.ss / 2; j++) {
            temp += i.ff;
        }
    }
    ans = temp + ans;
    reverse(all(temp));
    ans += temp;
    print(ans);

    return;
}

```
