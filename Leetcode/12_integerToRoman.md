# [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/) 🌟🌟

Given a number in the range 1 to 3999, return the number in Roman numeral format.

### Greedy solution

-   Ask interviewer if there could be negative numbers or 0.
-   Ask if the number is guaranteed to be in the range 1 to 3999.
-   We create 2 arrays to store the Roman numerals and their corresponding values.
-   Greedily we try to subtract largest possible number from the input number, and assign their corresponding Roman numeral to the result string.
-   We repeat this process until the input number becomes 0.
-   **Time complexity: O(n)=O(1)**, where n is the number of Roman numerals, here constant because we know the number of Roman numerals is 13.
-   **Space complexity: O(n)=O(1)**, where n is the number of Roman numerals, here constant because we know the number of Roman numerals is 13.

### Code

```cpp
class Solution {
public:
    string intToRoman(int num)
    {
        // Check for invalid inputs
        if (num < 1 || num > 3999) return "";

        vector<int> values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> romans = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

        string res = "";
        int i = 0;
        while (num > 0) {
            if (num - values[i] >= 0) {
                res += romans[i];
                num -= values[i];
            } else {
                i++;
            }
        }
        return res;
    }
};
```

### Fun solution

-   As human being came so far they evolved and they created some flexing solutions, but just don't flex this solution before interviewer.
-   **TC: O(1)**, indeed.
-   **SC: O(1)**, indeed.
-   Don't evolve more and create 4\*10 array to store all the Roman numerals.

### Code

```cpp
class Solution {
public:
    string intToRoman(int num)
    {
        vector<string> ones = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
        vector<string> tens = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        vector<string> hundreds = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        vector<string> thousands = { "", "M", "MM", "MMM" };
        return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};
```
