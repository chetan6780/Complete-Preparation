# RSL - Raja Software Labs (Pune) (On-campus)

## Problems:

**1. Check whether two strings are anagram of each other**
An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “abcd” and “dabc” are an anagram of each other.

**Solutions:**

1. Sorting - **O(nlogn),O(1)**
2. count characters 2 array, check (v1==v2) - **O(n),O(1)** max chars=26
3. count using only 1 array/hashmap, increase-decrease frequency, **O(n),o(1)**

---

**2. Check if two numbers are equal without using arithmetic and comparison operators**
Given two numbers, the task is to check if two numbers are equal without using Arithmetic and Comparison Operators or String functions.

**Solutions:**

1. XOR, XOR of two numbers is 0, **O(1)**
2. Using compliment(~) and bitwise AND(&), **O(1)**

```cpp
    if ((a & ~b) == 0)
        cout << "Same";
    else
        cout << "Not Same";
```

---

**3. Calculate the angle between hour hand and minute hand.**
This problem is known as Clock angle problem where we need to find angle between hands of an analog clock at a given time.

**Solutions:**

-   Hr hand = 360/12 = 30 degrees per hr => 0.5 degrees per min
-   Min hand = 360/60 = 6 degrees per min => 6 degrees per min
-   In H hr and M min
    -   Hr hand = (h\*60+m)\*0.5 degree (total min\*0.5)
    -   Min hand = (m)\*6 degree (total min\*6) , There is error in gfg explanation
-   `float angle = abs(hour_angle - minute_angle);`
-   `angle = min(360 - angle, angle);`

-   [Full GFG Solution](https://www.geeksforgeeks.org/calculate-angle-hour-hand-minute-hand/)

---

**4. Find first non repeating character in string.**
Given a string, find the first non-repeating character in it. For example, if the input string is “GeeksforGeeks”, then the output should be ‘f’ and if the input string is “GeeksQuiz”, then the output should be ‘G’.

**Solutions:**

1. Brute force, check if every character appears only once, **O(n^2)**
2. Hashmap, freq not equal to 1, **O(n),O(n)**

---

**5. Write a function that takes an input parameter as a string and return the alternate words in it with “abc”. Words are separated by dots.**

Note: Avoid using inbuilt functions

```
Input: "i.like.this.program.very.much"
Output: "i.abc.this.abc.very.abc"
```

**Solution:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> ans;
    string s, temp;
    cin >> s;
    temp = "";
    for (auto x : s) {
        if (x != '.') {
            temp += x;
        } else {
            ans.push_back(temp);
            temp = "";
        }
    }
    ans.push_back(temp); // DON'T forget to put last word in ans

    int n = ans.size();
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            ans[i] = "abc";
        }
    }
    string anss = "";
    for (auto x : ans) {
        anss += x + '.';
    }
    anss.pop_back();
    cout << anss << endl;
    return 0;
}
```

---

**6. Write a function that takes a number as input if the given number is a Fibonacci number, prints the number otherwise, print the sum of all even Fibonacci numbers less than the given number.**

```
Input: 20
Output: 10
Input: 21
Output: 21
```

**Solution:**

```cpp
// function to calculate all fibonacci numbers till n
vector<int> fibonacci(int n)
{
    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i = 2; i <= n; i++) {
        fibo.push_back(fibo[i - 1] + fibo[i - 2]);
    }
    return fibo;
}

// Using formula directly calculate n'th fibonacci number in O(log n) time
// phi^n takes O(log n) time.
int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

// Actual ans below ----------------------
bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s == x);
}

// Returns true if n is a Fibonacci Number, else false
bool isFibonacci(int n)
{
    // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or both
    // is a perfect square
    return isPerfectSquare(5*n*n + 4) ||
           isPerfectSquare(5*n*n - 4);
}
```

---

**7. Write a function that takes a string as an input and you have to return the frequency of characters.**

**Solutions:**

-   Simple array or hashmap count

---

**8. Write a function that takes an array of integers as input and prints the second maximum difference between any two elements from an array.**

**Solutions:**

1. Sort the array and return `arr[1]`.
2. traverse array twice
3. Single traversal, if size is less than 2 there is no second max.

```cpp
1) Initialize the first as 0(i.e, index of arr[0] element
2) Start traversing the array from array[1],
   a) If the current element in array say arr[i] is greater
      than first. Then update first and second as,
      second = first
      first = arr[i]
   b) If the current element is in between first and second,
      then update second to store the value of current variable as
      second = arr[i]
3) Return the value stored in second.
```

-   [GFG solution](https://www.geeksforgeeks.org/find-second-largest-element-array/)

---

**9. Write a function that takes an array of integers and prints the numbers that have a remainder of 4 when divided by 5.**
**Solutions:**

-   Simple

---

**10. Write a function that takes an integer as an input and returns the nearest prime number.**

```
Input: 7
Output: 7
Input: 13
Output:11
```

**Solution:**

-   [GFG Solution](https://www.geeksforgeeks.org/nearest-prime-less-given-number-n/)

---

**11. Write a function that takes two inputs, year, and n and returns n leap year after the given year.**
**Solutions:**

-   Below program checks if the given year is a leap year or not using 1 loop which is another RSL question.
-   Using is we can solve above problem, just think over it.

```cpp
bool isLeapYear(int n){
    if((n%4==0 && n%100!=0) || n%400==0)
        return true;
    else
        return false;
}
```

---

**12. Write a function that takes a string as an input and returns the first non-repeating character.**
**Solutions:**

1. Sorting
2. hashmap

---

**13. Write a function that takes a string as input and replace the space with “%?”**

```
Input: "welcome to geeksforgeeks"
Output: "welcome%?to%?geeksforgeeks"
```

**You have to make changes in the given string only.**

**Solution:**

-   Asked in 2nd technical interview.
-   [Similar question GFG](https://www.geeksforgeeks.org/urlify-a-given-string-replace-spaces-with-%20/)

---

## Previous Year DSA and Aptitude questions random

-   fibonacci numbers
-   star pattern
-   sorting algorithm
-   stringstream
-   input a line with spaces in cpp
-   count spaces and other characters
-   modular operation
-   prime numbers

---

-   find leap year using single if condition
-   reverse string separated by dots

---

-   standard ds questions
-   counting continuous max occurrences of 1 in a string
-   Star pattern

---

-   **decimal to binary/ also using recursion**
-   second largest element in the array
-   puzzle - GFG horse
-   print 2345 as 2000, 300, 40, 5

---

-   find the angle between hr hand and min hand of a clock e.g int CalculateAngle(int hr_hand, int min_hand){}
-   Balanced Parentheses
-   Stock buy and sell simple
-   String to int without inbuilt functions

---

-   a) Sum of a digit of a number like 467=17
-   b) check whether string is unique or not.
-   c) print string with corresponding frequency.
-   d) Merge Two arrays
-   e) reverse whole string not a single word of a string like “i.like” = “like.i”

---

-   General Aptitude: This section contains two subsections the first section has 18 questions for 1 mark which contains questions based on speed, profit-loss, geometry, maths and logical thinking. The second section contains two questions each for 2 marks.
-   lcm, hcf
-   Above was old pattern
-   In new pattern 20 mcqs in 30 min

---

-   The interview started with my short introduction. After that the interviewer asked some computer fundamentals basic questions on DSA, OOPs. What is the use of dsa, Type of data structure you know, main difference between linear and non-linear data structures. define stacks and its real time example, define linked list, Why oops is important, define abstraction, encapsulation and inheritance.
