# [551. Student Attendance Record I](https://leetcode.com/problems/student-attendance-record-i/) 🌟

You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

-   'A': Absent.
-   'L': Late.
-   'P': Present.

The student is eligible for an attendance award if they meet both of the following criteria:

-   The student was absent ('A') for strictly fewer than 2 days total.
-   The student was never late ('L') for 3 or more consecutive days.

Return true if the student is eligible for an attendance award, or false otherwise.

### Iterative Solution

-   We count 'A' and 'L' from the string.
-   If at any point we break the chain of consecutive 'L' we set `lCnt=0`.
-   If count of 'A' exceeds 1 or count of 'L' = 3 we return false, else true.
-   **TC: O(N)**, Where n is length of the string.
-   **SC: O(1)**, No extra space required.

```cpp
class Solution {
public:
    bool checkRecord(string s)
    {
        int n = s.size();
        int aCnt = 0, lCnt = 0;
        for (auto& x : s) {
            if (x == 'L') lCnt++;
            else lCnt = 0;

            if (x == 'A') aCnt++;

            if ((aCnt > 1) || (lCnt >= 3))
                return false;
        }
        return true;
    }
};
```

### Using Builtin Functions

-   We can get same results with inbuilt functions of C++ STL.

```cpp
class Solution {
public:
    bool checkRecord(string s)    {
        return !((s.find("LLL") != string::npos) || (count(s.begin(), s.end(), 'A') > 1));
    }
};
```

### Recursive Solution

-   Code is self explanatory.
-   **TC: O(N)**, Where n is length of string.
-   **SC: O(N)**, Recursive stack space.

```cpp
class Solution {
    bool checkRecordRec(string s, int aCnt, int lCnt, int i) {
        if(i>s.size()) return true;
        if((aCnt>1)||(lCnt>=3)) return false;

        if(s[i]=='A') {aCnt++;lCnt=0;}
        else if(s[i]=='L') lCnt++;
        else lCnt=0;

        return checkRecordRec(s,aCnt,lCnt,i+1);
    }
public:
    bool checkRecord(string s) {
        return checkRecordRec(s,0,0,0);
    }
};
```
