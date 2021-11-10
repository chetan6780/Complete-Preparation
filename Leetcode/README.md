# Leetcode problem hints and solutions

### Difficulty level:

-   🌟 **- Easy**
-   🌟🌟 **- Medium**
-   🌟🌟🌟 **- Hard**

---

# [1. Two Sum](./1_twoSum.md) 🌟

### O(N^2) Time Constant space

-   Brute force - check every pair of numbers.

### O(N) Time and O(N) space

-   The basic idea is to maintain a hash table for each element num in nums
-   using num as key and its index (0-based) as value. For each num, search for target - num in the hash table.
-   If it is found and is not the same element as num, then we are done.

---

# [3. Longest Substring Without Repeating Characters](./3_longestSubstringWithoutRepeatingCharacters.md) 🌟🌟

### O(N^3) Time, O(N) space

-   Brute force
-   We can consider all substrings one by one and check for each substring whether it contains all unique characters or not.
-   There will be n\*(n+1)/2 substrings.
-   Whether a substring contains all unique characters or not can be checked in linear time by scanning it from left to right and keeping a map of visited characters.
-   Time complexity of this solution would be O(n^3).

### O(N^2) Time O(N) space, Sliding window

-   For every i in string we check, **How long the substring starting with index i have unique characters**

### O(N) Time O(N) space, Sliding window

-   We keep track of unique characters in a hashmap(unordered_set).
-   l is left index and r is right index, these indicates unique substring's start and end.
-   if r'th character is not present in set, we add it and increment r also update `maxLength = max(maxLength, r-l);`
-   if r'th character is present in set, we remove it from set and increment l pointer.
-   finally return maxLength.

---

# [15. 3Sum](./15_3sum.md) 🌟🌟

### O(N^3 Log m) Brute force

-   Travel all the triplets which sums to 0.
-   Pseudo code

```
    for(i=0,n-1)
        for(j=i+1,n-1)
            for(k=j+1,n-1)
                a+b+c==0, cnt++
```

-   To get unique triplets, we can use set data structure.
-   N^3 for for loop and Log M for inserting unique triplets in the set.
-   **SC:** O(M), M is all unique triplets.

### O(N^2 Log M) Time and O(N)+O(M) Space

-   we can run 2 for loops for a and b.
-   store c in hashmap with its frequency
-   while running loops we have to decrease frequency of a and b inorder to find unique c.
-   then we find c=-(a+b) in the hashmap.
-   store the 3 numbers in sorted order in set so we will not have duplicates.
-   O(N^2) for 2 loops, Log(M) for inserting in set.
-   O(N) for map and O(M) For set.

### Two pointers.

-   Sort the array.
-   Fix a and you just need to find b+c=-a which is two sum problem.
-   To not get duplicates we increment pointer in such way that they are not equal to their previous values.
-   **TC:O(N\*N)**
-   **SC:O(M)**, M is the number of triplets.

---

# [19. Remove Nth Node From End of List](./19_removeNthNodeFromEndOfList.md) 🌟🌟

### O(N) Time and O(1) Space Complexity

-   Get the length of the linked list.
-   if n = length then return head->next
-   n = length - n
-   go to n-1th node then set its next to its next->next.
-   delete the space of removed node, else it will cause memory leak.
-   return head

### O(N) Time and O(1) Space Complexity, two pointers

-   We take 2 pointers, fast and slow. (here both move equally i.e. 1 node at a time)
-   move fast pointer n times.
-   if fast is null return head->next
-   now move slow and fast pointers together until fast->next != NULL.
-   slow->next = slow->next->next
-   Delete deleted node.
-   **NOTE:** This method have same complexity as above method.

---

# [20. Valid Parentheses](./20_validParentheses.md) 🌟

### O(N) Time and O(N) Space, straightforward solution

-   if the string is empty, return true
-   if the string has an odd number of characters, return false
-   Create a stack to store parenthesis.
-   if character is any opening parenthesis, push it to the stack
-   after first if, if stack is empty, which means the character is closing parenthesis, return false
-   else
    -   current character is matching parenthesis of top char of stack, pop that opening character from stack.
    -   else push it in the stack.
-   return true if stack is empty else false.

### Some slight simplification

-   we don't need to push extra closing parenthesis in the stack, if extra parenthesis appears return false.

---

# [21. Merge Two Sorted Lists](./21_mergeTwoSortedList.md) 🌟

### O(N+M) Time and O(N+M) space

-   If any list is empty, return the other list
-   Create dummy node to store new sorted lists
-   traverse until one of the list is empty
    -   if l1 is smaller, add l1 to new list, and move l1 to its next node
    -   if l2 is smaller, add l2 to new list, and move l2 to its next node
    -   move dummy pointer
-   if l2 is empty, add l1 to new list
-   if l1 is empty, add l2 to new list
-   Return next pointer of dummy node

### O(N+M) Time and O(1) space, in-place

-   if any list is empty, return the other list
-   l1 will always contain list of smaller value
    -   l1 will contain smaller val always;
    -   store l1 in result;
-   until any list is empty, run loop
    -   Create a temp node which points to nullptr
    -   while l1 has smaller element than l2, add l1 to temp
    -   after loop l2 will have smaller value than l1
    -   by swapping l1 and l2, l1 will contain smaller value
-   return final result which is pointer to l1 list

### O(N+M) Time and O(1) Space, Recursive

-   We will recursively join two linked list such that they will be always sorted.

---

# [35. Search Insert Position](./35_searchInsertPosition.md)

### O(log N) Time solution

-   Modification of BS.
-   l<r
    -   if target greater than element at mid.
        -   l = mid+1
    -   else
        -   r = mid // not mid-1;
-   return l

---

# [36. Valid Sudoku](./36_validSudoku.md) 🌟🌟

### Implementation

---

# [46. Permutations](./46_permutations.md) 🌟🌟

### Backtracking

-   Backtracking is a general technique for solving problems that uses DFS and finds **ALL POSSIBLE SOLUTIONS**.
-   General idea:
    ```
    Step 1: DO
    Step 2: RECUR
    Step 3: UNDO
    ```
    Make sure to use base conditions.

### MUST READ:

-   [A general approach to backtracking questions in Java (Subsets, Permutations, Combination Sum, Palindrome Partitioning)](<https://leetcode.com/problems/permutations/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning)>)

-   [Backtrack Summary: General Solution for 10 Questions!!!!!!!! Python (Combination Sum, Subsets, Permutation, Palindrome)](<https://leetcode.com/problems/permutations/discuss/18284/Backtrack-Summary%3A-General-Solution-for-10-Questions!!!!!!!!-Python-(Combination-Sum-Subsets-Permutation-Palindrome)>)

---

# [53. Maximum Subarray](./53_maximumSubarray.md) 🌟

### O(N) time constant space(DP)

-   We maintain a maximum sum and current sum(if element itself is max)
-   for each i=(0,n)
    -   add current element to current sum
    -   mx = max(current sum , mx);
    -   current sum will be max(0,current sum);
-   finally we return mx

---

# [56. Merge Intervals](./56_mergeIntervals.md) 🌟🌟

### O(N^2) Time Solution

-   Brute force.
-   sort the intervals by start time.(NlogN Time)
-   for every interval i, check if it overlaps with any interval j.
-   if it does, merge the two intervals.
-   if it doesn't, add it to the result.

### O(NlogN) Time O(N) Space Solution

-   Check for invalid case.
-   Sort the intervals by start time.
-   Take first pair of interval.
-   iterate over intervals and check if they overlap or not.
-   if they overlap, then change temp pair to `max(temp[1],x[1])`.
-   else push temp pair to result and change temp pair to x.

### O(NlogN) Time O(1) Space Solution

-   If we not consider the vector ans, which we have to return this problem can be solved without using temp vector.
-   We can simply use vector.back and do the operations on it.

---

# [62. Unique Paths](./62_uniquePaths.md) 🌟🌟

### Recursive Solution (TLE)

-   **Time Complexity**: O(2^n)

### Recursive + Memoization

-   Giving TLE , that should not happen , but it is happening.
-   **Time complexity**: m x n
-   **Space complexity**: m x n

### Tabulation Solution

-   **Time complexity**: m x n
-   **Space complexity**: m x n

### Combinatorics Solution

-   **Time complexity**: liner O(m)
-   Explained in [striver's video](https://www.youtube.com/watch?v=t_f0nwwdg5o&t=23s).

### READ

-   [Recursive, memoization and dynamic programming solutions](https://leetcode.com/problems/unique-paths/discuss/182143/Recursive-memoization-and-dynamic-programming-solutions)

---

# [63. Unique Paths II](./63_uniquePathII.md) 🌟🌟

---

# [70. Climbing Stairs](./70_climbingStairs.md) 🌟

### Dynamic Programming

---

# [74. Search a 2D Matrix](./74_search2DMatrix.md) 🌟🌟

### O(N\*M) Time and constant space solution

-   Brute force.
-   Traverse through the matrix and check for the target.
-   If the target is found, return true.
-   finally return false.

### O(N\*logM) Time and constant space solution

-   Search using binary search.

### O(log(N\*M)) Time and O(1) space

-   Complete Binary search on matrix.
-   mid/m : row , mid%m : column

---

# [75. Sort Colors](./75_sortColors.md) 🌟🌟

### O(N log N) Time Complexity with sort function.

-   sort the vector using stl `sort()` function.

### O(N)+O(N) Time using counting sort.

-   count number of 0's, 1's, and 2's and push them in increasing order according to their frequency.

### O(N) Time, 3 Pointers, dutch national flag algorithm.

-   We take 3 pointers low, mid and high.
-   low and mid points to 0 while high points to the last element.
-   we assume following conditions.
    -   Towards the left of low everything is 0.
    -   Towards the right of high everything is 2.
    -   In between low and high, everything is 1.
-   while(mid<=high) we do following.
    -   When we encounter 0.
        -   we swap low and mid.
        -   we increment low and mid.
    -   When we encounter 1.
        -   we increment mid.
    -   When we encounter 2.
        -   we swap mid and high.
        -   we decrement high.

---

# [77. Combinations](./77_combinations.md) 🌟🌟

### Backtracking

-   Backtracking is a general technique for solving problems that uses DFS and finds **ALL POSSIBLE SOLUTIONS**.
-   General idea:
    ```
    Step 1: DO
    Step 2: RECUR
    Step 3: UNDO
    ```
    Make sure to use base conditions.

---

# [83. Remove Duplicates from Sorted List](./removeDuplicatesFromSortedList.md) 🌟

### O(N) Time and O(1) Space

-   if value of current node is equal to the value of the next node, delete the next node
-   else traverse next node,

---

# [88. Merge Sorted Array](./88_mergeSortedArray.md) 🌟

### O(M+N) Time and O(M+N) space

-   Create new array with m+n elements.
-   Traverse through both the given array, find min and insert in the new array.

### O(M\*N) without using extra Space

-   Traverse through both the given array
-   If arr1[i]>arr2[i] then swap the elements and sort the second array.(here sorting means just put swapped element at its right position not real sorting)

### O(M+N) Time and O(1) Space

-   Code is self explanatory on leetcode

### Using GAP algorithm

-   O(Log2N \* O(N)) time and O(1) space
-   We Will take GAP between two pointers and if the are not sorted we swap them.
-   first GAP = ceil(n1+n2/2) then next time it will be half of previous GAP.
-   If GAP is 1 then next time we stop.
-   [Striver Video 7:47](https://youtu.be/hVl2b3bLzBw?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&t=467)

---

# [94. Binary Tree Inorder Traversal](./94_binaryTreeInorderTraversal.md) 🌟

### O(N) Time and O(N) auxillary space, recursive

-   if root is null, Return.
-   Traverse Left subtree.
-   Visit the root (store data).
-   Traverse Right subtree.

### O(N) Time and O(N) Space, iterative

-   if root is null, Return.
-   while true
    -   if left node present, then traverse all the way left.& push node in the stack.
    -   if stack is empty, break the loop.
    -   get the top in node variable and push it in ans vector.
    -   now move to the right.
-   return inorder(ans) vector.

### O(N) Time and O(1) Space, Morris Traversal

**Soon...**

<!-- TODO: Morris traversal -->

---

# [96. Unique Binary Search Trees](./96_uniqueBinarySearchTrees.md) 🌟🌟

### MUST READ 👇:

-   There are a few ways to solve this problem. I have explained all the solutions and approach to optimize it from Brute-Force to Dynamic Programming to solving using Catalan formula in: ✅[ Simple Solution w/ Explanation | Optimization from Brute-Force to DP](https://leetcode.com/problems/unique-binary-search-trees/discuss/1565543/Simple-Solution-w-Explanation-or-Optimization-from-Brute-Force-to-DP)

1. **Brute-Force**                 `( Time: O(3^N), Space: O(N) )`
1. **Dynamic Programming - Memoization**    `( Time: O(N^2), Space: O(N) )`
1. **Dynamic Programming - Tabulation**     `( Time: O(N^2), Space: O(N) )`
1. **Catalan Numbers**             `( Time: O(N), Space: O(1) )`
1. **Catalan Numbers (2nd Approach)**      `( Time: O(N), Space: O(1) )`

-   [C++ Easy & Clean Solution | Fastest | All (4+) Methods | Detailed Explanation & Comments](<https://leetcode.com/problems/unique-binary-search-trees/discuss/1565544/C%2B%2B-Easy-and-Clean-Solution-or-Fastest-or-All-(3%2B)-Methods-or-Detailed-Explanation-and-Comments>)

### DP Solution(Tabulation)

-   We have base conditions of `dp[0] = dp[1] = 1.`
-   Then we calculate result for each number of nodes `i` from `2...n.`
-   For `i` nodes. we can consider each of the node `j` from `1...i` as the root node.
-   Considering the jth node as the root node in BST having total of `i` nodes, the result is summation for all `j` from `1...i` of `dp[j-1] * dp[i-j]`. (Comparing to above solution `dp[j-1] = numTrees(j-1) and dp[i-j]=numTrees(i-j)`)

---

# [98. Validate Binary Search Tree](./98_validateBinarySearchTree.md) 🌟🌟

### O(N) Time and O(N) space

-   Inorder traversal of the binary tree gives sorted array.
-   we can traverse the tree inorder and check if the array is sorted or not.

### O(N) Time solution

-   we will check if value is less than maximum and greater than minimum
-   Refer [This](https://www.youtube.com/watch?v=s6ATEkipzow) , if you are not able to understand.

---

# [101. Symmetric Tree](./101_symmetricTree.md) 🌟

### O(N) Time solution

-   we will traverse left and right subtrees of the root with the same type of traversal.
-   we compare the value of left with right or value of right with left , if they are not equal we return false.
-   we recurse for left's left with right's right and left's right with right's left.

### O(N) Time, using 2 queue, iterative solution

-   Same recursive solution can be converted to iterative solution by using queue.
-   Remember while using 2 queue we push `left->left,left->right` in 1st queue and `right->right,right->left` in 2nd queue.

### O(N) Time, using 1 queue, iterative solution

-   We can use 1 queue instead of 2.
-   remember that while using 1 queue we do `left->left,right->right,left->right,right->left.`

---

# [102. Binary Tree Level Order Traversal](./102_btLevelOrderTraversal.md) 🌟🌟

### O(N) Time and O(N) Space

-   Create an empty queue q.
-   Push the root node of tree to q.
-   Loop while the queue is not empty:
    -   get all the elements of q.
    -   push their left and right nodes in the queue.
    -   push_back these elements in the vector.
    -   pus_back this vector in main 2d vector.
-   return 2d vector.

---

# [104. Maximum Depth of Binary Tree](./104_maxDepthBinaryTree.md) 🌟

### O(N) Time and O(H) Space,(DFS) More proffered than iterative

-   Worst case, if tree is skewed then it will take **O(N)** else **O(h)** space, where h is the height of the tree.

-   If root is null then return 0.
-   else return 1 + maximum depth of(left subtree, right subtree)

### O(N) Time and O(N) Space (BFS), using level order traversal

-   Same like level order traversal, but we need to keep track of the depth.

---

# [112. Path Sum](./112_pathSum.md) 🌟

### O(N) Time , recursive

-   if root is null return false
-   if roots left and right both are null return `root->val==targetSum`.
-   else recursively find `targetSum - root->val` in left and right subtree.

### O(N) Time , iterative

**soon...**

<!-- TODO: iterative solution -->

---

# [116. Populating Next Right Pointers in Each Node](./116_populatingNextRightPointer.md) 🌟🌟

### O(N) Time and O(N) space

-   Using level order traversal technique and NULL.
-   if current node is null and q is not empty, then push NULL into q.
-   else set current node's next to q's front.
-   push left and right in the queue , if they are not NULL.

### O(N) Time and O(1) space

## <!-- TODO: Explanation -->

---

# [118. Pascal's Triangle](./118_pascalsTriangle.md) 🌟

### Straightforward solution

---

# [120. Triangle](./120_triangle.md) 🌟🌟

### Dynamic Programming

-   [Video](https://www.youtube.com/watch?v=O2eaAdBpZBQ)

---

# [121. Best Time to Buy and Sell Stock](./121_bestTimeToBuyAndSellStock.md) 🌟

### O(N^2) Time and O(1) Space

-   Brute force:
-   For each day, find the max profit that can be made by buying at that day and selling at the next j days.

### O(N) Time and O(N) Space

-   We try to sell stock each day.
-   For each day from last we store maximum stock price that will appear.
-   then for each day we calculate by selling the stock.

### O(N) Time and O(1) Space

-   We try to buy stock each day.
-   For each day we keep track of the minimum price of the stock that appeared before it.
-   if todays stock price is minimum we will update it.
-   return max profit.

### Optimized inner loop : 33% less time.

-   If the price of the stock that day less than minimum price so far then there is no chance to get profit so we only update minimum price.
-   else we can get profit, update maxProfit.

---

# [122. Best Time to Buy and Sell Stock II](./122_bestTimeToBuySellStockII.md) 🌟🌟

### Greedy - O(N) Time O(1) space (Valley-peak approach)

-   O(2^N) and O(N^2) approaches
-   For each time at lowest cost(valley) we buy stock and at highest cost(peak) we sell stock.

### Code-1

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int i = 0, profit = 0, buy, sell, N = prices.size()-1;
        while (i < N) {
            while (i < N && prices[i + 1] <= prices[i]) {
                i++;
            }
            buy = prices[i];
            while (i < N && prices[i + 1] > prices[i]) {
                i++;
            }
            sell = prices[i];
            profit += sell - buy;
        }
        return profit;
    }
};
```

-   for each day we buy and on next day we sell, **If it is profitable**

### Code-2

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] < prices[i])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};
```

### READ:

-   [✅ [Java] Simple & Clean DP solutions for all 6 Buy & Sell Stock questions on LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/1569081/Java-Simple-and-Clean-DP-solutions-for-all-6-Buy-and-Sell-Stock-questions-on-LeetCode)

---

# [129. Sum Root to Leaf Numbers](./129_sumRootToLeafNumbers.md) 🌟🌟

### O(N) Time recursive

-   We recursively traverse to the all leaf node.
-   Multiply val by 10 and add curr val in it.
-   if both left and right child is null, we add the current node value to the sum.
-   else recurse for left anf right subtree.
-   Stack can grow upto the height of the tree so that we can explore the path from root to leaf node.
-   Thus, **Space Complexity = O(Height of the tree)**
-   **Time Complexity:O(N)** --> All Nodes will be visited once.

### Useful Comment:

1. List of problems you need to master the concept :
    - [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
    - [110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)
    - [111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
    - [112. Path Sum](https://leetcode.com/problems/path-sum/)
    - [113. Path Sum II](https://leetcode.com/problems/path-sum-ii/)
    - [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
    - [257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)
    - [437. Path Sum III](https://leetcode.com/problems/path-sum-iii/)
    - [559. Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)
    - [687. Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/)
    - [988. Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/)
    - [1376. Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/)

If you find more problems, please comment it below :)

---

# [130. Surrounded Regions](./130_surroundedRegions.md) 🌟🌟

### DFS Approach complex

-   This [video](https://www.youtube.com/watch?v=0ZJViJEdtEc) explains both the approaches and code.
-   1st approach is complex while 2nd is easy.

### DFS Approach more efficient

-   Pick all O's from boundary (Top/Bottom row, Leftmost/Rightmost column)
-   Make all connected O's to some intermediate value (1 in my case).
-   Now remaining all O's are surrounded by X (otherwise they should have been converted to 1).
-   Convert remaining all O to X.
-   Revert all intermediate values. (1 to O).

-   **Time Complexity** - **O(m \* n)**
-   **Space Complexity** - **O(1)** if we ignore recursive stack calls else **O(m \* n)**

---

# [136. Single Number](./136_singleNumber.md) 🌟

### Sorting array

### Using Map

### Using XOR (^)

-   XOR of same numbers is 0;
-   XOR of 0 with a number is the number;

---

# [141. Linked List Cycle](./141_linkedListCycle.md) 🌟

### O(N) Time and O(N) space

-   If there is a cycle in given linked list then same node must appear more than once.
-   so, we create an unordered_set of nodes ands while traversing the list we check if the node is already present in the linked list.
-   if its present we return true else we insert it into the unordered_set.
-   finally after completing loop we return false. because there is no cycle.

### O(N) Time and O(1) space - floyd's cycle detection algorithm

-   Here fast pointer move 2 steps and slow pointer moves one step.
-   If they meet each other while traversing then loop that means there is a cycle else not.

---

# [144. Binary Tree Preorder Traversal](./144_binaryTreePreorderTraversal.md) 🌟

### O(N) Time O(N) space (function call stack), Recursive

-   if root is null, Return.
-   Visit the root (store data).
-   Traverse Left subtree.
-   Traverse Right subtree.

### O(N) Time and O(N) extra space

-   Create a vector to store values and stack for operations
-   if tree is empty, return empty vector
-   else push root into stack
-   while stack is not empty
    -   pop the top element from stack
    -   push the value of the popped element into vector
    -   we want left node to the top of stack, so we store it last so it appear on the top of stack
    -   if right node is not empty, push it into stack
    -   if left node is not empty, push it into stack

### Morris traversal - O(N) time and O(N) space.

**Explanation soon...**

## <!-- TODO: morris traversal -->

---

# [145. Binary Tree Postorder Traversal](./145_binaryTreePostorderTraversal.md) 🌟

### O(N) Time and O(2N) space, Iterative

**NOTE:** _Here instead of ***2 Stack*** I have used ***1 Stack and 1 vector*** and reversed the vector at the end._

More detail explanation watch [this](https://www.youtube.com/watch?v=2YBhNLodD8Q) 4 min video.

### O(N) Time and O(N) Space, Iterative (1 stack)

**This is bit tricky.Dry run 2-3 trees to understand**
Watch [this](https://www.youtube.com/watch?v=NzIGLLwZBS8) Video.

### O(N) Time and O(1) Space, Morris traversal

**soon...**

## <!-- TODO: Morris traversal -->

---

# [155. Min Stack](./155_minStack.md) 🌟

### TIP

-   Solving a question to implement stack using stack is possible , but not a good idea.
-   you can use 2 vector, 1 vector, vector of pair or map to implement the stack.

### Time Complexity: O(1) for all the solutions.

### Space Complexity: Extra O(N) Space used.

### Using 2 Vectors

-   We maintain 2 vectors, 1 for stack implementation and another for min stack.push `INT_MAX` to min stack in declaration.
-   `push` operation:
    -   push element to stack.
    -   push min element to min stack.
-   `pop` operation:
    -   pop element from stack.
    -   pop min element from min stack.
-   `top` operation:
    -   return top element from stack.
-   `getMin` operation:
    -   return top element from min stack.

### Using 1 vector

-   Instead of 2 vectors, we can use 1 vector to implement the stack.
-   `push` operation:
    -   if minElement is greater or equal to val, push minElement to stack and update minElement to val.
    -   then push val in the stack.
-   `pop` operation:
    -   pop the top of the stack.
    -   if top is equal to minElement, minElement will be top(next top) of the stack and pop the top(next top) from stack.

### Using vector of pair

-   Self explanatory code

---

# [167. Two Sum II - Input array is sorted](./167_twoSumII_inputArrayIsSorted.md) 🌟

### O(N) Time 2-pointers solution

-   We maintain 2 pointers, one at the start and one at the end.
-   We iterate over the array.
    -   If Sum if equal to target, return the indices.
    -   else if sum is greater than target we decrement the end pointer.
    -   else we increment the start pointer.

---

# [189. Rotate Array](./189_rotateArray.md) 🌟

### O(N) Time and O(N) space

-   Create new array
-   copy the original array
-   Rotate the array by (i+k)%n.

### O(N) Time and O(1) Space

-   k%=nums.size(), because if k>n so we need to do only k%n operations.
-   reverse the array.
-   reverse the first k elements.
-   reverse the rest of the array.

---

# [190. Reverse Bits](./190_reverseBits.md) 🌟

### Using lsb

-   `n&1` will give us lsb.
-   we will shift lsb to left by `31-i` bits and it will be our reverseLsb.
-   we will or reverseLsb with result.
-   shift n by 1 to right.
-   [Reference Video](https://www.youtube.com/watch?v=LJiMk8lPJNc)

---

# [191. Number of 1 Bits](./191_numberOf1Bits.md) 🌟

### Using \_\_builtin_popcount

### Using n=n&(n-1) trick

-   Each time of "n &= n - 1", we delete one '1' from n.

### READ:

-   [[Python] n & (n-1) trick + even faster, explained](<https://leetcode.com/problems/number-of-1-bits/discuss/1044775/Python-n-and-(n-1)-trick-%2B-even-faster-explained>)
-   [Short code of C++, O(m) by time, m is the count of 1's, and another several method of O(1) time](<https://leetcode.com/problems/number-of-1-bits/discuss/55120/Short-code-of-C%2B%2B-O(m)-by-time-m-is-the-count-of-1's-and-another-several-method-of-O(1)-time>)

---

# [198. House Robber](./198_houseRobber.md) 🌟🌟

### Dynamic Programming

---

# [203. Remove Linked List Elements](./203_removeLinkedListElement.md) 🌟

### O(N) Time and O(1) Space

-   Implementation

### O(N) Time and O(1) Space, recursive

-   if head is null return null.
-   if value of current node is val we not include it else we include it.

---

# [206. Reverse Linked List](./206_reverseLinkedList.md) 🌟

### O(N) Time and O(1) space, iterative

-   Initialize three pointers prev as NULL, curr as head and next as NULL.
-   Iterate through the linked list. In loop, do following.
    -   Before changing next of current, store next node
        next = curr->next
    -   Now change next of current This is where actual reversing happens
        curr->next = prev
    -   Move prev and curr one step forward
        prev = curr
        curr = next

### O(N) Time and O(1) space, recursive

1. Divide the list in two parts - first node and
   rest of the linked list.
2. Call reverse for the rest of the linked list.
3. Link rest to first.
4. Fix head pointer

---

# [217. Contains Duplicate](./217_containsDuplicate.md) 🌟

### O(N^2) Time and constant space

-   Check for every element, if it is present in the array using 2 loops.

### O(N log N) Time and constant space

-   We can sort the array, so duplicate elements will be next to each other.

### O(N) Time and O(N) Space

-   We can use a hash table to store the elements.

---

# [222. Count Complete Tree Nodes](./222_countCompleteTreeNodes.md) 🌟🌟

### O(N) Time

-   we Can traverse the whole tree and count the number of nodes.

### O(log N \* log N) Time

-   The idea behind the algorithm is - A complete binary tree has `2^h - 1` nodes, where `h` is the height of the tree.
-   so we get the left and right hight of the tree.
-   if the are equal, then we can directly return `2^(left) - 1`
-   else we check for its right and left subtree and return `1 + countNodes(root->left) + countNodes(root->right);`

---

# [226. Invert Binary Tree](./226_invertBinaryTree.md) 🌟

### O(N) Time recursive solution

-   if root is null return null
-   we just need to swap the left and right children of each node recursively.we can use inbuilt swap function or implement our own swap function.
-   We can travel in preorder as well as postorder , both solutions are accepted.(here is preorder solution)

### O(N) Time O(N) stack iterative solution

-   We use stack instead of recursive stack.

---

# [231. Power of Two](./231_powerOfTwo.md) 🌟

-   Go To above link.

---

# [232. Implement Queue using Stacks](./232_implementQueueUsingStacks.md) 🌟

### O(1) AMORTIZED Time solution

-   **AMORTIZED**: Most of the times operations are O(1) time. Sometimes it will be O(n) time. But total time for all the operations will be O(1).
-   Using 2 stacks; one is used for read and another for write.

---

# [235. Lowest Common Ancestor of a Binary Search Tree](./235_lowestCommonAncestorOfBst.md) 🌟

### O(N) Time recursive solution

-   we traverse the tree and find p and q;
-   if one of child node is null return another
-   else both are not null return the root(curr node), that means left and right are p and q.
-   Reference: [link](https://www.youtube.com/watch?v=_-QHfMDde90) for recursive solution.

### O(N) Time iterative solution

-   Self Explanatory.

---

# [236. Lowest Common Ancestor of a Binary Tree](./236_lowestCommonAncestorOfABinaryTree.md) 🌟🌟

### O(N) Time and O(N) Space

-   Find the path from the root node to node n1 and store it in a vector or array.
-   Find the path from the root node to node n2 and store it in another vector or array.
-   Traverse both paths until the values in arrays are same. Return the common element just before the mismatch.

### O(N) Time recursive solution

-   we traverse the tree and find p and q;
-   if one of child node is null return another
-   else both are not null return the root(curr node), that means left and right are p and q.
-   Reference: [link](https://www.youtube.com/watch?v=_-QHfMDde90) for recursive solution.

---

# [242. Valid Anagram](./242_validAnagram.md) 🌟

### O(N logN) Time and constant space

-   Sort both strings and compare them.
-   if they are equal, return true else false.

### O(N) Time and O(N)=O(26) constant space

-   We store frequency of each character in a hash table.
-   Decrement the frequency of each character in hash table which is in the t.
-   If any frequency is not zero, return false.

### Only 2 loops

-   First confirm sizes of both strings is same.
-   We can avoid 3rd loop by checking if the frequency of each character less than 0 then return false.
-   return true by default.

---

# [260. Single Number III](./260_singleNumberIII.md) 🌟🌟

### O(N^2) Time

-   Brute force

### O(NlogN) Time Sorting solution

-   Since we have condition that `exactly two elements appear only once and all the other elements appear exactly twice.`
-   First we sort the nums array.
-   if we found duplicates we increase i by 2 else we add number in ans.
-   if ans.size()==2 thn we can break loop, since we have only 2 unique elements.

### O(N) Time HashMap solution

-   We can use `set` or `map` to solve this problem in O(N) time.

### O(N) Time O(1) Bit Manipulation solution

Idea is to use property of XOR:

```
1. xor(a, a) = 0
2. xor(a, 0) = xor(0, a) = a
3. xor(1, 1) = xor(0, 0) = 0
4. xor(1, 0) = xor(0, 1) = 1
5. xor(a, b) = c => xor(a, c) = b and xor(b, c) = a
```

Let two distinct elements be: first and sec. Now, firstXorSec := xor(first, sec) = xor(nums[i], 0), 0 <= i < [n:= nums.size()], why? because nums has odd and even freq. elements, doing xor will cancel out elements with even freq. using the 1. property of xor. So, at the end, xor of only odd freq. elements i.e first and sec remains.

Now, first != sec => there is at least 1 set bit in firstXorSec. Using 4. property of xor, one of first and sec, must have a set bit (Let it be first). We find/ denote this rightmost set bit using mask: has all bits 0 except the rightmost set bit in firstXorSec. So, we can divide the elements in nums in two groups A and B, where:

```
1. groupA: (num & mask) == 1 i.e bit is set
2. groupB: (num & mask) == 0 i.e bit is not set
```

Clearly, both first and sec belong to different groups and since, all other elements occurs in pair, so, we can safely again use 1. property of xor to generate first. Finally, using 5. property of xor, we have `sec = xor(firstXorSec, first)`

---

# [268. Missing Number](./268_missingNumber.md) 🌟

### O(NlogN) by Sorting

-   With sorting we can get missing number.

### O(N) Time

-   Calculate the sum of all elements in the array.
-   Subtract the sum of all elements in the array from the sum of all elements in the range 1 to n.

---

# [278. First Bad Version](./278_firstBadVersion.md) 🌟

### O(log N) Time solution

-   Slight modification of binary search.
-   l=1,r=n;

---

# [283. Move Zeroes](./283_moveZeros.md) 🌟

### O(N) Time solution

-   We will shift all non zero elements at front
-   Then remaining elements will be filled with zeros

### O(N) Time snowball solution

-   The idea is that we go through the array and gather all zeros on our road.
-   If element is 0, increase size of snowball by 1.
-   else we swap it with (i-snowball)th element.
-   **NOTE:** here we used temp variable instead of direct swapping for avoiding unnecessary swapping. For ex.`[1]` no swap required.

---

# [287. Find the Duplicate Number](./287_findDuplicateNumber.md) 🌟🌟

### O(N^2) Brute force

-   check for all numbers if duplicate number exists.

### O(NlogN) Sorting

-   Sort the array and duplicate numbers will be next to each other.

### O(N) Time O(N) space, Hash Table

-   With the help of hash (set/map/vector) we can find the duplicate number.

### O(N) Time O(1) space, Floyd's Cycle Detection Algorithm

---

# [344. Reverse String](./344_reverseString.md) 🌟

### O(N) time and O(1) space, using stack

-   Using stack we can reverse the string.

### O(N) Time , recursive

-   if i is the middle then we can stop (it's base condition)
-   else we swap ith and n-i-1th element
-   we recur for next position of i, i.e i+1.

### O(N) Time two pointer solution

-   swap start and end pointers.

---

# [350. Intersection of Two Arrays II](./350_intersectionOfTwoArraysII.md) 🌟

### O(N\*M) Time and O(N) Space

-   Brute force
-   for every element in nums1, check if it exists in nums2
-   if it exists then add it to the ans and set it to -1 and break inner loop, so duplicate will not be included.
-   return ans

---

# [383. Ransom Note](./383_ransomNote.md) 🌟

### same as is_subsequence problem.

### O(N) Time O(N)=O(26) constant space

-   calculate frequency of each letter in magazine
-   iterate over ransomNote and decrement frequency of each letter
-   if any letter frequency is less than 0, return false

---

# [387. First Unique Character in a String](./387_firstUniqueCharacterInAString.md) 🌟

### O(N^2) Time and O(1) space

-   Brute force
-   For every character check if it appears in the string more than once

### O(N) Time and O(N)=O(26) constant space

-   Store frequency of every character in a hash table
-   Iterate through the hash table and check if the character is Unique

---

# [404. Sum of Left Leaves](./404_sumOfLeftLeaves.md) 🌟

### Simple recursive dfs

-   We want sum of left leaf nodes only, so we can take additional boolean variable to specify whether it is left or not.
-   we recursively go to left and right leaf node, if leaf node is left then we return its value else return 0.
-   return dfs for left and right of tree.
-   **Time Complexity:** O(n), we traverse the tree once
-   **Space Complexity:** O(1) if we don't consider recursion stack, **O(height-of-tree)** if we do.

---

# [441. Arranging Coins](./441_arrangingCoins.md) 🌟

### Simulation

-   We can just simulate the process of building the staircase.
-   Assume we have k as result, `1+2+...+i = N`, then `i*(i+1) = 2N => i^2 = N => i = sqrt(N)`
-   **Time Complexity: O(sqrt(n))**

### Binary Search

-   The problem can be converted into - Find the maximum k such that `k*(k+1)/2 <= n`.
-   **Time Complexity: O(logN)**

### Math solution

-   As we know the number of coins in each staircase are forming an AP `Eg :- 1+2+3+...+a = n`
    Sum of all terms of AP :- `(1+a)a/2 = n`
    n is given to us in question, we have to find a
-   ```
    ===> a ^ 2 + a = 2 n
    ===> x ^ 2 + a + 1/4 = 2 n +1/4
    ===> (a + 1/2 ) ^ 2 = 2n + 1/4
    ===> (a + 0.5) = sqrt( 2n + 1/4 )
    ===> a = -0.5 + sqrt( 2n + 1/4 )
    ```
-   We have calculated the value of `a = -0.5 + sqrt( 2\*n + 1/4 )`
-   **Time Complexity: O(1)**

---

# [542. 01 Matrix](./542_01Matrix.md) 🌟🌟

### BFS solution

-   Firstly, we can see that the distance of all zero-cells are 0.
-   Same idea with Topology Sort, we process zero-cells first, then we use queue data structure to keep the order of processing cells, so that cells which have the smaller distance will be processed first. Then we expand the unprocessed neighbors of the current processing cell and push into our queue.
-   After all, we can achieve the minimum distance of all cells in our matrix.

**Complexity:**

-   Time: `O(M * N)`, where M is number of rows, N is number of columns in the matrix.
-   Space: `O(M * N)`, space for the queue.

### DP Solution

-   Firstly, we can see that the distance of all zero-cells are 0, so we skip zero-cells, we process one-cells only.
-   In DP, we can only use previous values if they're already computed.
-   In this problem, a cell has at most 4 neighbors that are left, top, right, bottom. If we use dynamic programming to compute the distance of the current cell based on 4 neighbors simultaneously, it's impossible because we are not sure if distance of neighboring cells is already computed or not.
-   That's why, we need to compute the distance one by one:
    -   Firstly, for a cell, we restrict it to only 2 directions which are left and top. Then we iterate cells from **top to bottom**, and from **left to right**, we calculate the distance of a cell **based on its left and top neighbors**.
    -   Secondly, for a cell, we restrict it only have 2 directions which are right and bottom. Then we iterate cells from **bottom to top**, and from **right to left**, we update the distance of a cell **based on its right and bottom neighbors**.

**Complexity:**

-   Time: `O(M * N)`, where M is number of rows, N is number of columns in the matrix.
-   Space: `O(1)`

---

# [557. Reverse Words in a String III](./557_reverseWordsInString.md) 🌟

### O(N\*M) Time and O(M) Space

-   We can use stack to reverse each word.
-   Traverse the string and push each character in the stack until we encounter a space.
-   if space is encountered, empty the stack by popping the top character and append it to the result string.

---

# [566. Reshape the Matrix](./566_reshapeMatrix.md) 🌟

### O(N\*M) Time and O(N\*M)+O(N\*M) Space

-   naive approach
-   store 2D array in 1D temporary array.
-   Create new r\*c matrix and fill it with the values from the temporary array.

### O(N\*M) Time and O(N\*M) Space (Row-First Approach

-   M[i] => M[i/n][i%n] it will result in right mapping
-   `i/c` will give us the row number of output matrix. We will move to New row after every c elements and thus dividing by c will give the row number.
-   `i%c` will give us the column number of output matrix. We will be begin from start of new row after every c elements and this the remainder will give column of current row.
-   The same happens in i/n and i%n but for the mat matrix).

### O(N\*M) Time and O(N\*M) Space (Column-First Approach)

### <!-- TODO: (Column-First Approach) -->

soon...

---

# [567. Permutation in String](./567_permutationInString.md) 🌟🌟

### O(N) Time and O(1) Space

-   Permutation of string is the anagram of itself.
-   So, the problem become, find the anagram of the string1 in the string2.
-   We can find it with maintaining two frequency arrays for s1 and s2.
-   If at any point their frequencies are equal, then return true.
-   else by maintaining window size(s1.size()), try for next substring.
-   finally, return false, because there is no anagram of string1 in string2.

---

# [617. Merge Two Binary Trees](./617_mergeTwoBinaryTrees.md) 🌟

### DFS - Recursive

-   if both nodes are null returns null.
-   if one of the node null, return the other node.
-   else Create new node with value = t1->val+t2->val.
-   set new nodes left = merge(t1->left, t2->left)
-   set new nodes right = merge(t1->right, t2->right)
-   return new node;

**Time complexity**: **O(n)**. A total of n nodes need to be traversed. Here, n represents the minimum number of nodes from the two given trees.
**Space complexity**: **O(n)**. The depth of the recursion tree can go upto n in the case of a skewed tree. In average case, depth will be **O(log n)**.

### BFS - Iterative

-   Base condition as in recursion
-   Create 2 queues for BFS and push root nodes in them.
-   While both queues are not empty
    -   Store the front nodes and Pop from both queues
    -   Add value of 2nd node in 1st
    -   if node1's left is null and node2's left is not null, then add node1's left to node2's left
    -   else if both's left not null then push them in respective queues
    -   if node1's right is null and node2's right is not null, then add node1's right to node2's right
    -   else if both's right not null then push them in respective queues.

**Time complexity**: **O(n)**. A total of n nodes need to be traversed. Here, n represents the minimum number of nodes from the two given trees.
**Space complexity**: **O(n)**. The size of queue can go upto n in the case of a skewed tree.

### MUST READ:

-   [~100.00% fast in run-time and memory Recursive/Iterative/BFS/DFS](https://leetcode.com/problems/merge-two-binary-trees/discuss/588123/~100.00-fast-in-run-time-and-memory-RecursiveIterativeBFSDFS)

---

# [653. Two Sum IV - Input is a BST](./653_twoSumIV.md) 🌟

### O(N) Time and O(N) space

-   This method also works for those who are not BSTs.
-   The idea is to use a hashtable to save the values of the nodes in the BST. Each time when we insert the value of a new node into the hashtable, we check if the hashtable contains k - node.val.

### O(N) Time and O(N) space

-   The idea is to use a sorted array to save the values of the nodes in the BST by using an inorder traversal.
-   Then, we use two pointers which begins from the start and end of the array to find if there is a sum k.

### O(hn) Time and O(h) space

-   `h` is the height of the tree, which is `log n` at best case, and `n` at worst case.
-   The idea is to use binary search method.
-   For each node, we check if k - node.val exists in this BST.

---

# [695. Max Area of Island](./695_maxAreaOfIsland.md) 🌟🌟

### DFS - Recursive

-   For each cell we check, if it is 1, then we call a dsf on it

-   **DFS Function:**

    -   we pass grid, i and j in dfs.
    -   if the cell is valid we call dfs on its four sides.

-   **Complexity:**

    -   Time: **O(M \* N)**, where M is number of rows, N is number of columns in the grid.
    -   Space: **O(M \* N)**, the space used by the depth stack during our recursion, in worst case is **O(M \* N)**.

### BFS - Iterative

-   For each cell we check, if it is 1,then we call a **bsf** on it

-   **BFS Function**

    -   We use q for bfs and push the first pair of i&j in q
    -   While q is not empty
    -   for top of the queue, we go on four directions and set `grid[nr][nc]=0` and increase the area count.
    -   return the area.

-   **Complexity:**

    -   Time: **O(M \* N)**, where M is number of rows, N is number of columns in the grid.
    -   Space: **O(M \* N)**, the space used by the queue in bfs, in worst case is **O(M \* N)**, can check this discussion:[stackoverflow](https://stackoverflow.com/a/50912382/4084297)

---

# [700. Search in a Binary Search Tree](./700_searchInABinarySearchTree.md) 🌟

### O(N) Time, Recursive solution

-   if root is null return null.
-   if root's value == val return the root.
-   if required value is less than root's value, recurse on left subtree.
-   else recurse on right subtree.

### O(N) Time, Iterative solution

-   Same as recursion.

---

# [701. Insert into a Binary Search Tree](./701_insertIntoABinarySearchTree.md) 🌟🌟

### O(N) Time solution

-   We append the new node to leaf node where it can be place without violating the BST property.
-   if value of new node is less than root we try for right child
-   else we try for left child.

---

# [704. Binary Search](./704_binarySearch.md) 🌟

### O(log N) Time algorithm

-   **NOTE:** _Array must be sorted.if not then sort array first._
-   Point two variables l and r to the first and last position of array.
-   while(l<=r)
    -   if middle element is target then return middle index
    -   if middle element is greater than target then r = middle - 1
    -   if middle element is less than target then l = middle + 1
-   if we cant find element in array, return -1.

---

# [784. Letter Case Permutation](./784_letterCasePermutation.md) 🌟🌟

### Backtracking

---

# [733. Flood Fill](./733_floodFill.md) 🌟

### DFS - Recursive

-   **Main function:**

    -   if current color is not new color, call the dfs algorithm.
    -   else return original image.

-   **DFS function:**

    -   check for invalid row and column numbers.
    -   check if current color is not old color or is already new color.
    -   for both the cases return.
    -   set current color to new color.
    -   call the function for all the 4 directions.

-   **Complexity:**

    -   Time: **O(M \* N)**, where `M <= 50` is number of rows, `N <= 50` is number of columns in the matrix.
    -   Space: **O(M \* N)**, it's the depth stack memory, in worst case is **O(M \* N)**, can check this discussion on [stackoverflow](https://stackoverflow.com/a/50912382/4084297).

### BFS - Iterative

-   **Main function:BFS**

    -   if current color is already new color, return original image
    -   We need a 2D direction vector and a queue for BFS (q of pairs).
    -   push starting point in the queue.
    -   while queue is not empty run loop.
        -   get the row and column index form the front of the queue, and pop it.
        -   set current color to new color
        -   for all directions push {r,c} in the queue if it's valid.

-   **Complexity:**

    -   Time: **O(M \* N)**, where `M <= 50` is number of rows, `N <= 50` is number of columns in the matrix.
    -   Space: **O(M \* N)**, it's the depth stack memory, in worst case is **O(M \* N)**, can check this discussion on [stackoverflow](https://stackoverflow.com/a/50912382/4084297).

### MUST READS:

-   [How do you think about solving a question using DFS [ Learn before you Code ]](https://leetcode.com/problems/flood-fill/discuss/442143/How-do-you-think-about-solving-a-question-using-DFS-Learn-before-you-Code)

-   [[C++] standard solution, schema you can apply to other tasks: list + visited](https://leetcode.com/problems/flood-fill/discuss/627915/C%2B%2B-standard-solution-schema-you-can-apply-to-other-tasks%3A-list-%2B-visited)

---

# [832. Flipping an Image](./832_flippingAnImage.md) 🌟

### O(N^2) Time and O(1) Space

-   Use inbuilt reverse() function to reverse the vector.
-   To Toggle we can use either `y=1-y` or `y^=1`

---

# [867. Transpose Matrix](./867_transposeMatrix.md) 🌟

### O(N\*M) Time and O(N\*M) space

-   Get no of rows and columns of given matrix.
-   Create a new matrix of with no.rows=no.columns and no.columns=no.rows.
-   Iterate over the matrix and copy the values from the given matrix to the new matrix `ans[j][i]=matrix[i][j]`;
-   Space can be optimizes in case of square matrix, where we can use in place swapping of rows and columns.

---

# [876. Middle of the Linked List](./876_middleOfTheLinkedList.md) 🌟

### O(N) Time solution

-   We can traverse through the whole linked list and count the number of node.
-   Then we travel from start until we reach to the middle.
-   Then return temp, which is the middle node.

### O(N) Slow and Fast pointer

-   **NOTE: It works for all `Find middle` Questions.**
-   Each time, slow go 1 steps while fast go 2 steps.
-   When fast arrives at the end, slow will arrive right in the middle.
-   `fast != NULL` for odd number of nodes.
-   `fast->next != NULL` for even number of nodes.

---

# [977. Squares of a Sorted Array](./977_squaresOfASortedArray.md) 🌟

### O(N*log*N) Time solution

-   Create new array and push_back squares of each element in it.
-   Sort the new array.
-   Return the new array.

### O(N) Time solution

-   We use two pointer method to solve this problem.
-   set two array l=0 and r=arr.size()-1.
-   traverse through the array and set max abs values square at last position.
-   return the array.

---

# [980. Unique Paths III](./980_uniquePathsIII.md) 🌟🌟🌟

### DFS + Backtracking

-   Below solution is explained [in this video](https://www.youtube.com/watch?v=XNKCkX_tHhM) also on must read no-1.
-   We don't need zero++ for backtracking, because it is local variable.

### MUST READ

-   [Java Easy Solution || DFS + Backtracking || Explanation (Simplified)](<https://leetcode.com/problems/unique-paths-iii/discuss/1553873/Java-Easy-Solution-oror-DFS-%2B-Backtracking-oror-Explanation-(Simplified)>)
-   [C++ Simple and Clean DFS Solution, Explained, 0ms Faster than 100%](https://leetcode.com/problems/unique-paths-iii/discuss/1553805/C%2B%2B-Simple-and-Clean-DFS-Solution-Explained-0ms-Faster-than-100)

---

# [989. Add to Array-Form of Integer](./989_addToArrayFormOfInteger.md) 🌟

### O(N) Time and O(1) Space

-   We use k itself as carry.
-   From last to first we fill array with addition and mod.
-   If after loop, k have some carry we insert k to the start of array until it becomes 0.

---

# [994. Rotting Oranges](./994_rotatingOranges.md) 🌟🌟

### BFS solution

-   simple application of bfs.
-   Watch [Striver's short video](https://www.youtube.com/watch?v=pUAPcVlHLKA) for better explanation.
-   **Time complexity: O(M\*N)**

---

# [1178. Number of Valid Words for Each Puzzle](./1178_numberOfValidWordsForEachPuzzle.md) 🌟🌟🌟

### Bit masking with hashmap

-   We set all the bits of the corresponding indices of each letter, then we easily see if it's a submask.
-   we create a hashmap to keep the frequency of each mask, so that if we have two words with the same letter we will count both.
-   we iterate through the puzzles
-   We need to find all combinations of submasks to check. This is the faster than iterating through all the words because each puzzle is only 7 letters.
-   For that we just do (submask-1) & mask - we are turning off a bit by subtracting one which sets the lowest 1 to 0 and all 0s in the right to 1s, and then we do & with the original mask to get only the desired bits.

### Interview Tips

<details>
        <summary><b>Interview Tip-1</b></summary>
In a real interview, if you are unsure how to solve the problem, a good first step is to remain calm and reread the problem description looking for hidden clues.
  Also, remember to ask the interviewer about the problem constraints. The constraints are very important for solving problems as they can help us determine which data structures and algorithms can feasibly be used to solve the problem.
  However, if the interviewer chooses to deliberately hide the constraints, then they likely want you to find different methods under different assumed constraints. Although, on rare occasions, a problem may be too simple to provide constraints.
</details>

<details>
        <summary><b>Interview Tip-2</b></summary>
A constraint under `10` usually accepts a method with `N!` time complexity with respect to this constraint. Factorial time complexities can occur for operations like finding all permutations from a set or using brute-force to solve the traveling salesman problem.
  A constraint under `30` usually accepts a method with `2^N` time complexity at worst with respect to this constraint. Some examples include iterating over all combinations or subsets from a set or some brute-force solutions that use `DFS`.
  However, a solution with better time complexity can still exist even when the constraints are small. One should use the constraints to estimate the complexity of the worst acceptable solution, not the best solution.
</details>

<details>
        <summary><b>Interview Tip-3</b></summary>
When you still do not have any idea after rereading the problem, you can try a brute-force method that works but may have an unacceptable time complexity.
  Then you can either try to improve on the brute-force method or gain some insight from the brute-force method.
</details>

<details>
        <summary><b>Interview Tip-4</b></summary>
In an interview, if the first solution that comes to mind involves a complex data structure, you can wait a minute and try thinking of other similar methods. In a real-world setting, we typically prioritize efficiency and readability. We prioritize these characteristics in an interview setting as well, however, we also value solutions that we are less likely to make a mistake while coding and solutions that do not require a long time to code.
  In this problem, you should consider your level of familiarity with the trie data structure before choosing between implementing a solution using a trie or a set. If the more comfortable approach is not the most efficient, then you should also weigh the increased chance of making a mistake versus the gain of having a more efficient solution.
  Worry not, as we will cover both methods in this article.
</details>

### Must Read:

-   [Video sumit sir](https://www.youtube.com/watch?v=9jV0CC_C26s)
-   [✅ [C++] Clean & Easy Solution w/ Detailed Explanation | Bit-masking Approach](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/discuss/1567324/C%2B%2B-Clean-and-Easy-Solution-w-Detailed-Explanation-or-Bit-masking-Approach)
-   [C++ Simple and Clean Solution, Easy Explanation](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/discuss/1567291/C%2B%2B-Simple-and-Clean-Solution-Easy-Explanation)
-   [Leetcode Solution](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/solution/)

---

# [1295. Find Numbers with Even Number of Digits](./1295_findNumbersWithEvenNumberOfDigits.md`) 🌟

### O(N\*length(num)) Time and O(1) Space

-   Implementation.

### O(N) Time and O(1) Space

-   Using log10(num) to find the length of the number.
-   log10(num) gives length(num)-1.

---

# [1365. How Many Numbers Are Smaller Than the Current Number](./1365_howMenyNumbersAreSmallerThanTheCurrentNumber.md) 🌟

### O(N^2) Time solution

-   Brute force for each array element.

### O(N) Time O(N) space optimization

-   Store the count in a bucket and take the running sum.

---

# [1389. Create Target Array in the Given Order](./1389_createTargetArrayInTheGivenOrder.md) 🌟

### O(N^2) Time solution

-   Brute force

### O(N\*logN) based on "smaller elements after self".

-   It is HARD level problem
-   Will be added soon...
<!-- TODO:ADD O(N*logN) Solution -->

---

# [1431. Kids With the Greatest Number of Candies](./1431_kidsWithTheGreatestNumberOfCandies.md) 🌟

### O(N) Time and O(N) Space Solution:

-   Use greedy approach. For each kid check if candies[i] + extraCandies ≥ maximum in all Candies

---

# [1470. Shuffle the Array](./1470_shuffleTheArray.md) 🌟

### O(N) Time and O(N) Space solution

-   Use two pointers to create the new array of 2n elements. The first starting at the beginning and the other starting at (n+1)th position. Alternate between them and create the new array.

---

# [1480. Running Sum of 1d Array](./1480_runningSumArr.md) 🌟

### O(N) Time and O(N) Space solution

-   Create a sum variable to store current sum in it ans push back it in the result array.

### O(N) Time and O(1) Space optimization

-   We can modify input array directly

---

# [1512. Number of Good Pairs](./1512_numberOfGoodPairs.md) 🌟

### O(N^2) Time O(1) Space solution

-   Check for each element of array and return the ans.

### O(N) Time O(N) Space optimization

-   Use map to store if the number appeared before or not.
-   If it appeared add frequency to ans.else add it to map.

---

# [1572. Matrix Diagonal Sum](./1572_matrixDiagonalSum.md) 🌟

### O(N) Time O(1) Space solution

-   Smart Implementation😉

---

# [1672. Richest Customer Wealth](./1672_richestCustomerWealth.md) 🌟

### O(N^2) Time and O(1) Space solution

-   Use inbuilt accumulate function to get the sum of all the elements in the array

---

# [1732. Find the Highest Altitude](./1732_findHighestAltitude.md) 🌟

### O(N) Time and O(1) Space solution

-   Start from 0, add each altitude and store max altitude.

---

# [1773. Count Items Matching a Rule](./1773_countItemsMatchingARule.md) 🌟

### O(N) Time and O(1) Space solution

-   Implementation.

---

# [1832. Check if the Sentence Is Pangram](./1832_checkIfSentenceIsPanagram.md) 🌟

### O(N) Time O(N) Space Solution

-   Create a set and check if its length is exactly 26 or not.

---

# [1854. Maximum Population Year](./1854_maximumPopulationYear.md) 🌟

### O(N) Time and O(N) Space

-   We can mark the start and end of each life as +1 and -1 on the timeline.
-   Then, we go through timeline from 1950 to 2050 and accumulate the current population for each year.

---

# [1886. Determine Whether Matrix Can Be Obtained By Rotation](./1886_determineWhetherMatrixCanBeObtainedByRotation.md) 🌟

### O(N^2) Time solution

-   Suppose we are at index i, j, let us find a relation of this position with it's position in various rotations. i. e

```
- 0 deg rotation : i, j will point to i, j
- 90 deg rotation : i, j will point to j, n - i - 1
- 180 deg rotation : i, j will point to n - i - 1, n - j - 1
- 270 deg rotation : i, j will point to n - j - 1, i
```

-   We denote these rotations by boolean variables, initially we assume all these rotations are valid, so we set them all to true. Here

```
c[0] -> 0 deg rotation,
c[1] -> 90 deg,
c[2] -> 180 deg,
c[3] -> 270 deg
```

-   Then, we loop over all elements and check if that particular rotation is valid or not. If not, we turn it to false.
-   In the end, we simply check if any of the rotations is still possible or not.

---

# [1920. Build Array from Permutation](./1920_buildArrayFromPermutation.md) 🌟

### O(N) Time and O(N) Space solution

-   For i=0 to n , simply do what they have asked to.
-   Push_back(nums[nums[i]])

### O(N) Time and O(1) Space optimization

-   This is done to keep both old and new value together.
-   going by the example of [5,0,1,2,3,4], n = 6(size of array)
-   `nums[i] = nums[i]+(n*(nums[nums[i]]%n));`
-   after this nums[0] will be 5 + 6\*(4%6) = 5 + 24 = 29;
-   now for next index calculation we might need the original value of num[0] which can be obtain by num[0]%6 = 29%6 = 5;
-   if we want to get just the new value of num[0], we can get it by num[0]/6 = 29/6 = 4

---

# [1929. Concatenation of Array](./1929_ConcatenationOfArray.md) 🌟

### O(N) Time and O(N) Space solution

-   We will use inbuilt function `vector.insert()` to concatenate the arrays.
