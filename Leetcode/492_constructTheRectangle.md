# [492. Construct the Rectangle](https://leetcode.com/problems/construct-the-rectangle/) 🌟

A web developer needs to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:

1. The area of the rectangular web page you designed must equal to the given target area.
2. The width W should not be larger than the length L, which means L >= W.
3. The difference between length L and width W should be as small as possible.

Return an array [L, W] where L and W are the length and width of the web page you designed in sequence.

### Iterative Solution

-   Since `l >= w` always, w will not be larger than sqrt(area).
-   If we can find w then `l = area / w`.
-   We just simulate the process from sqrt(area) to 1, since in the condition it is given that the difference between L and W should be as small as possible.
-   **TC: O(k)** where k is the sqrt of the area.
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    vector<int> constructRectangle(int area)
    {
        int k = sqrt(area);
        for (int i = k; i >= 1; i--) {
            if (area % i == 0) return { area / i, i };
        }
        return {};
    }
};
```

### Recursive Solution

-   From above iterative solution, we can also write recursive solution.
-   **TC: O(k)** where k is the sqrt of the area.
-   **SC: O(k)** because of recursive stack.

### Code

```cpp
class Solution {
    vector<int> constructRectangleRec(int area, int k)
    {
        if (area % k == 0) return { area / k, k };
        return constructRectangleRec(area, k - 1);
    }

public:
    vector<int> constructRectangle(int area)
    {
        int k = sqrt(area);
        return constructRectangleRec(area, k);
    }
};
```
