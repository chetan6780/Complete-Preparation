# [1286. Iterator for Combination](https://leetcode.com/problems/iterator-for-combination/) 🌟🌟

Design the `CombinationIterator` class:

-   `CombinationIterator(string characters, int combinationLength)` Initializes the object with a string `characters` of **sorted distinct** lowercase English letters and a number `combinationLength` as arguments.
-   `next()` Returns the next combination of length `combinationLength` in **lexicographical order**.
-   `hasNext()` Returns true if and only if there exists a next combination.

---
### Prerequisites:
- **Backtracking**
- **77. Combinations**

### Backtracking Solution (Efficient)

-   First, in the initialization, we recompute all the combinations of given string , and store the
    string of `combinationLength` in the `combination` vector. It will be done in **O(2^n)** time and also in **Dictionary order**.
-   In the `next()` function, from the `combination` vector, we return the next combination.
-   In the `hasNext()` function, we check if the `combination` vector has the next combination or not.

### Code

```cpp
class CombinationIterator {
private:
    vector<string> comb;
    int ptr;
    void backtrackComb(string s, int n, int pos, int len, string res)
    {
        if (len == 0) { // curr string is of req len, include it.
            comb.push_back(res);
            return;
        }
        if (pos >= n) { // out of bound
            return;
        }

        // include string in lexicographical order
        res += s[pos];
        backtrackComb(s, n, pos + 1, len - 1, res); // include character
        res.pop_back();
        backtrackComb(s, n, pos + 1, len, res); // exclude character
    }

public:
    CombinationIterator(string characters, int combinationLength)
    {
        backtrackComb(characters, characters.size(), 0, combinationLength, ""); // O(2^N)
        ptr = 0;
    }

    string next() // O(1)
    {
        return comb[ptr++];
    }

    bool hasNext() // O(1)
    {
        return ptr < comb.size() ? true : false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

### Bitmasking Solution (Not more efficient)

-   Here change is, we use bitmasking to compute all the combinations. takes **O(2^n)** time.
-   but we need to have additional map to store the combinations in sorted order. takes **O(log N)** time.

```cpp

class CombinationIterator {
    map<string, int> comb; //Store all combinations formed (MAP keeps in ASC order)
    map<string, int>::iterator ptr; //Points to current string to be returned
public:
    CombinationIterator(string characters, int combinationLength)
    {
        int n = characters.size();
        int mask = 1 << n; //Max MASK value
        int len = combinationLength;

        // O(2^N.log N): 2^n for all combinations, log N for map to store all combinations
        for (int i = 1; i < mask; ++i) { //Try all 2^N combinations
            int curr = i;
            int j = 0;
            string s = "";
            while (curr) //For each combination
            {
                if (curr & 1)
                    s.push_back(characters[j]);
                curr >>= 1;
                j += 1;
            }
            if (s.size() == len) //Currently found string is of length len (required)
                comb[s]++;
        }
        ptr = comb.begin(); //ptr is pointing to 1st string
    }

    string next() // O(1)
    {
        auto temp = ptr;
        ptr++;
        return temp->first;
    }

    bool hasNext() // O(1)
    {
        return ptr != comb.end() ? true : false;
    }
};
```
