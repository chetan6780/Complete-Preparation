#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

// infix to postfix conversion using stack ---------------------------------------------------------

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '-' || c == '+')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } else {
            while (!st.empty() && precedence(st.top()) > precedence(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

// Evauate postfix expression using stack (//*Numbers are only one digit) ---------------------------------------------
int evaluatePostfix(char* exp)
{
    stack<int> st;

    int i;

    for (i = 0; exp[i]; ++i) {
        if (isdigit(exp[i]))
            st.push(exp[i] - '0');

        else {
            int val1 = st.top();
            st.pop();

            int val2 = st.top();
            st.pop();

            switch (exp[i]) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }
    return st.top();
}

// Evauate postfix expression using stack (//*Numbers are more than one digits) ------------------------------------
int evaluatePostfix(char* exp)
{
    stack<int> st;
    int i;

    for (i = 0; exp[i]; ++i) {
        if (exp[i] == ' ')
            continue;

        else if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }

            i--;

            st.push(num);
        }

        else {
            int val1 = st.top();
            st.pop();

            int val2 = st.top();
            st.pop();

            switch (exp[i]) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }

    return st.top();
}

// Reverse a string using stack -----------------------------------------------------------------------------
// return the address of the string
char* reverse(char* S, int len)
{
    char* arr = new char[len + 1];
    arr[len] = '\0';
    // we need to create a new string of length n+1 and assign \0 to its last index so it will terminate

    stack<char> st;

    for (int i = 0; i < len; i++) {
        st.push(S[i]);
    }
    for (int i = 0; i < len; i++) {
        arr[i] = st.top();
        st.pop();
    }
    return arr;
}

// sort the stack -----------------------------------------------------------------------------------------------------------
// void insert(stack<int> &s, int t)
// {
//     if (s.size() == 0 || t >= s.top())
//     {
//         s.push(t);
//         return;
//     }
//     int val = s.top();
//     s.pop();
//     insert(s, t);
//     s.push(val);
//     return;
// }
// void SortedStack ::sort()
// {
//     if (s.size() == 1)
//         return;
//     int temp = s.top();
//     s.pop();
//     sort();
//     insert(s, temp);
//     return;
// }

// DESIGN a stack to Get the minimum element in O(1) time using O(1) space ---------------------------------------------
/*returns min element from stack*/
// int _stack ::getMin()
// {
//     if (s.empty())
//         return -1;
//     return s.top();
// }
// /*returns poped element from stack*/
// int _stack ::pop()
// {
//     if (s.empty())
//         return -1;
//     s.pop();

//     int temp = s.top();
//     s.pop();
//     if (!s.empty())
//         minEle = s.top();
//     return temp;
// }
// /*push element x into the stack*/
// void _stack::push(int x)
// {
//     if (s.empty())
//         minEle = INT_MAX;
//     if (x < minEle)
//         minEle = x;
//     s.push(x);
//     s.push(minEle);
// }

// Paranthesis checker -------------------------------------------------------------------------------------------------
bool areBracketsBalanced(string expr)
{
    stack<char> s;
    char x;
    int l = expr.length();
    for (int i = 0; i < l; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }

        if (s.empty())
            return false;

        switch (expr[i]) {
        case ')':

            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    return (s.empty());
}

// Max rectangle ---------------------------------------------------------------------------------
int histogramArea(int* arr, int n)
{
    stack<int> s;
    int max_area = 0, area = 0;
    int i = 0;
    while (i < n) {
        if (s.empty() or arr[s.top()] <= arr[i]) {
            s.push(i);
            i++;
        } else {
            int top = s.top();
            s.pop();
            if (s.empty()) {
                area = arr[top] * i;
            } else {
                area = arr[top] * (i - s.top() - 1);
            }
            max_area = max(area, max_area);
        }
    }
    /// When array becomes empty, pop all the elements of stack:
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        area = arr[top] * (s.empty() ? i : (i - s.top() - 1));
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    // Your code here
    int max_area = 0;
    int* arr = new int[m];
    for (int j = 0; j < m; j++) {
        arr[j] = M[0][j];
    }
    int curr_area = histogramArea(arr, m);
    max_area = max(curr_area, max_area);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 0) {
                arr[j] = 0;
            } else {
                arr[j] += M[i][j];
            }
        }
        curr_area = histogramArea(arr, m);
        max_area = max(curr_area, max_area);
    }
    return max_area;
}

// Next greater element
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
}