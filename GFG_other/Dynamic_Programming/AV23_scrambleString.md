# Check if a string is a scrambled form of another string

Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.

### Scrambled string

Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
**_Note: Scrambled string is not same as an Anagram_**
Below is one possible representation of str = "coder":

```
    coder
   /    \
  co    der
 / \    /  \
c   o  d   er
           / \
          e   r
```

To scramble the string, we may choose any non-leaf node and swap its two children.
Suppose, we choose the node "co" and swap its two children, it produces a scrambled string “ocder”.

```
    ocder
   /    \
  oc    der
 / \    /  \
o   c  d   er
           / \
          e   r
```

Thus, "ocder" is a scrambled string of "coder".
Similarly, if we continue to swap the children of nodes "der" and "er", it produces a scrambled string "ocred".

```
    ocred
   /    \
  oc    red
 / \    /  \
o   c  re  d
       / \
      r   e
```

Thus, "ocred" is a scrambled string of "coder".

### Divide and Conquer / Recursive Approach

- if both string are of different length, then there is no way that they can be scramble
- if characters of both strings are different, then there is no way that they can be scramble
  i.e. check if they are anagram or not
- if both string are same or their length is 0 then they are scramble
- Check from i=1 to n-1
  - Check for first half of both strings and then second half
  - Check for alternate half of both strings
- Non of the conditions are not satisfied, strings are not scramble

### Code

```cpp
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
bool isScramble(string a, string b)
{
    // if both string are of different length, then there is no way that they can be scramble
    if (a.length() != b.length())
        return false;

    // if characters of both strings are different, then there is no way that they can be scramble
    // check if they are anagram or not
    if (isAnagram(a, b) == false)
        return false;

    int n = a.length();

    // if both string are same or their length is 0 then they are scramble
    if (a == b || n == 0)
        return true;

    // Check from i=1 to n-1
    for (int i = 1; i <= n - 1; i++)
    {
        // Check for first half of both strings and then second half
        if (isScramble(a.substr(0, i), b.substr(0, i)) && isScramble(a.substr(i, n - 1), b.substr(i, n - 1)))
            return true;
        // Check for alternate half of both strings
        if (isScramble(a.substr(0, i), b.substr(n - 1, i)) && isScramble(a.substr(i, n - 1), b.substr(0, n - 1)))
            return true;
    }
    // Non of the conditions are not satisfied, strings are not scramble
    return false;
}
```

# DP Approach

### Memoization

- Use of MAP

### Code

```cpp
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
unordered_map<string, bool> mp;
bool isScramble(string a, string b)
{
    if (a.length() != b.length())
        return false;

    if (isAnagram(a, b) == false)
        return false;

    int n = a.length();

    if (a == b || n == 0)
        return true;

    string key = (a + '_' + b);
    if (mp.find(key) != mp.end())
        return mp[key];

    bool flag = false;

    for (int i = 1; i <= n - 1; i++)
    {
        if (isScramble(a.substr(0, i), b.substr(0, i)) && isScramble(a.substr(i, n - 1), b.substr(i, n - 1)))
        {
            flag = true;
            return true;
        }
        if (isScramble(a.substr(0, i), b.substr(n - 1, i)) && isScramble(a.substr(i, n - 1), b.substr(0, n - 1)))
        {
            flag = true;
            return true;
        }
    }
    mp[key] = flag;
    return false;
}
```

### Complexity Analysis

- Time Complexity: **O(N^2)**, where N is the length of the given strings.
- Auxiliary Space: **O(N^2)**, As we need to store O(N^2) string in our mp map.

### References

- GFG: [Scramble String](https://www.geeksforgeeks.org/check-if-a-string-is-a-scrambled-form-of-another-string/)
- YouTube: [AV - Scramble String](https://www.youtube.com/watch?v=SqA0o-DGmEw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40)
