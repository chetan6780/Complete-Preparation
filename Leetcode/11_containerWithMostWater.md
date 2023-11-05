# [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/description) 🌟🌟

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

### Brute force (TLE)

-   Try all possible combinations of lines and find the maximum area out of them.
-   take min of heights of two lines and multiply it with the distance between them.
-   **Time complexity:** O(n^2)
-   **Space complexity:** O(1)

### Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int mx = 0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mx = max(mx, min(height[i], height[j]) * (j - i));
            }
        }
        return mx;
    }
};
```

### Two pointer approach

-   To optimize the brute force approach, we can use two pointer approach.
-   we need to maximize the area, so we will start with the maximum width possible.
-   take one pointer at the start and one at the end.
-   calculate or update the area.
-   now we got an area but can we do better? may be we find more taller line and area will increase.
-   to do it, lets move the pointer which is pointing to the shorter line to the next line.
-   repeat the process until both the pointers meet.
-   **Time complexity:** O(n)
-   **Space complexity:** O(1)

### Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxWater = 0;
        while (i < j) {
            maxWater = max(maxWater, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxWater;
    }
};
```
