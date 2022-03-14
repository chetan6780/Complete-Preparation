# [71. Simplify Path](https://leetcode.com/problems/simplify-path/) 🌟🌟

Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

### Using stack

-   We create stringstream objects to store the path
-   We use a stack to store the directories
-   Iterate those the path,
    -   if it is "." or ""(we get "" when multiple '//' appears) continue
    -   if it is ".." and stack is not empty, pop the stack.
    -   if it is a directory, push it to the stack
-   append the stack to the result string.
-   **NOTE:** Appending from front is O(N^2) operation, we can reduce it by reversing the stack and appending to last of result string.
-   If result string is empty, return "/" else return result string.
-   **TC: O(N^2)** OR reverse the stack **O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    string simplifyPath(string path)
    {
        string res, temp;
        stack<string> st;
        stringstream ss(path);
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") continue;
            if (temp == ".." && !st.empty()) st.pop();
            else if (temp != "..") st.push(temp);
        }
        while (!st.empty()) {
            res = "/" + st.top() + res; // <-- O(N^2): appending '/' from front of string(like inserting element at front of vector)
            st.pop();
        }
        return (res == "") ? "/" : res;
    }
};
```
