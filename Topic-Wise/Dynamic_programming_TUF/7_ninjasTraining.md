# [Ninja's Training](https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=0) 🌟🌟

### Recursive solution

-   `lastTask` is the task performed by ninja for last day. values of lastTask -> [0,3], i means ith task is performed, 3 means no task performed.
-   For starting day(n-1th) `lastTask` will be 3 as no tasks are performed by ninja.
-   For every day we can perform all tasks except `lastTask`.
    `f(day, task) = max(f(day, task), pts[day][task] + f(day-1,task))`

### Code

```cpp
int helper(vector<vector<int>>& pts, int day, int lastTask)
{
    int mxPoints = 0;
    if (day == 0) {
        for (int task = 0; task < 3; task++) {
            if (task != lastTask) {
                mxPoints = max(mxPoints, pts[day][task]);
            }
        }
        return mxPoints;
    }

    for (int task = 0; task < 3; task++) {
        if (task != lastTask) {
            int currPoints = pts[day][task] + helper(pts, day - 1, task);
            mxPoints = max(mxPoints, currPoints);
        }
    }
    return mxPoints;
}

int ninjaTraining(int n, vector<vector<int>>& points)
{
    return helper(points, n - 1, 3);
}
```

### Memoization(top-down)

-   The recursive solution calculate the same subproblems again and again. So we can use memoization to optimize it.
-   If the result for the subproblem is stored, return it, else calculate and store it.
-   **TC: O(n\*4\*3) = O(n)**
-   **SC: O(n\*4) + O(n) = O(n)**

### Code

```cpp
int helper(vector<vector<int>>& pts, vector<vector<int>>& memo, int day, int lastTask)
{
    int mxPoints = 0;
    if (day == 0) {
        for (int task = 0; task < 3; task++) {
            if (task != lastTask) {
                mxPoints = max(mxPoints, pts[day][task]);
            }
        }
        return memo[day][lastTask] = mxPoints;
    }

    if (memo[day][lastTask] != -1) return memo[day][lastTask];

    for (int task = 0; task < 3; task++) {
        if (task != lastTask) {
            int points = pts[day][task] + helper(pts, memo, day - 1, task);
            mxPoints = max(mxPoints, points);
        }
    }
    return memo[day][lastTask] = mxPoints;
}

int ninjaTraining(int n, vector<vector<int>>& points)
{
    vector<vector<int>> memo(n, vector<int>(4, -1));
    return helper(points, memo, n - 1, 3);
}
```

### Tabulation(bottom-up)

-   The memoization solution passes but we can reduce the recursive stack space by using tabulation.
-   write all base cases first and then fill the table.
-   Our day was going from n-1 to 1, then reached 0(base case), write loop for day(1->n).
-   For each day we were calculating points for all possible lastTasks, so write loop for lastTasks(0->4).
-   For each lastTask we could have performed all tasks except lastTask, so write loop for tasks(0->3).
-   Calculate points for each task and update the max points.
-   Return last element of dp table.
-   **TC: O(n\*4\*3) = O(n)**
-   **SC: O(n\*4) = O(n)**

### Code

```cpp
int ninjaTraining(int n, vector<vector<int>>& points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({ points[0][0], points[0][1], points[0][2] });

    for (int day = 1; day < n; day++) {
        for (int lastTask = 0; lastTask < 4; lastTask++) {
            dp[day][lastTask] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != lastTask) {
                    int curr = points[day][task] + dp[day - 1][task];
                    dp[day][lastTask] = max(curr, dp[day][lastTask]);
                }
            }
        }
    }
    return dp[n - 1][3];
}
```

### Space Optimized Tabulation

-   If we observe the table, to calculate the current day's points we only need the previous day's points.
-   So we just need to have track of previous day's points in 1d `prev` array of size 4 as there are 4 possible lastTasks(0,1,2,3).
-   Store all base cases in `prev` array.
-   We can store current day's points in 1d `curr` array of size 4.
-   After each day we will update `prev` array with `curr` array.
-   Final answer will be stored in `prev[3]`.
-   **TC: O(n\*4\*3) = O(n)**
-   **SC: O(4) = O(1)**

### Code

```cpp
int ninjaTraining(int n, vector<vector<int>>& points)
{
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({ points[0][0], points[0][1], points[0][2] });

    for (int day = 1; day < n; day++) {
        vector<int> curr(4, 0);
        for (int lastTask = 0; lastTask < 4; lastTask++) {
            curr[lastTask] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != lastTask) {
                    curr[lastTask] = max(curr[lastTask], points[day][task] + prev[task]);
                }
            }
        }
        prev = curr;
    }
    return prev[3];
}
```
