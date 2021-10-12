# Leetcode problem hints and solutions

#### Difficulty level:

- 🌟 **- Easy**
- 🌟🌟 **- Medium**
- 🌟🌟🌟 **- Hard**

---

# [1. Two Sum](./1_twoSum.md) 🌟

### O(N^2) Time Constant space

- Brute force - check every pair of numbers.

### O(N) Time and O(N) space

- The basic idea is to maintain a hash table for each element num in nums
- using num as key and its index (0-based) as value. For each num, search for target - num in the hash table.
- If it is found and is not the same element as num, then we are done.

---

# [20. Valid Parentheses](./20_validParentheses.md) 🌟

### O(N) Time and O(N) Space, straightforward solution

- if the string is empty, return true
- if the string has an odd number of characters, return false
- Create a stack to store paranthesis.
- if character is any opening paranthesis, push it to the stack
- after first if, if stack is empty, which means the character is closing paranthesis, return false
- else
  - current character is matching paranthesis of top char of stach, pop that opening character from stack.
  - else push it in the stack.
- return true if stack is empty else false.

### Some slight simpification

- we dont need to push extra closing paranthesis in the stak, if extra paranthesis appears return false.

---

# [21. Merge Two Sorted Lists](./21_mergeTwoSortedList.md) 🌟

### O(N+M) Time and O(N+M) space

- If any list is empty, return the other list
- Create dummy node to store new sorted lists
- travese until one of the list is empty
  - if l1 is smaller, add l1 to new list, and move l1 to its next node
  - if l2 is smaller, add l2 to new list, and move l2 to its next node
  - move dummy pointer
- if l2 is empty, add l1 to new list
- if l1 is empty, add l2 to new list
- Return next pointer of dummy node

### O(N+M) Time and O(1) space, in-place

- if any list is empty, return the other list
- l1 will always contain list of smaller value
  - l1 will contain smaller val always;
  - store l1 in result;
- until any list is empty, run loop
  - Create a temp node which points to nullptr
  - while l1 has smaller element than l2, add l1 to temp
  - after loop l2 will have smaller value than l1
  - by swapping l1 and l2, l1 will contain smaller value
- return final result which is pointer to l1 list

### O(N+M) Time and O(1) Space, Recursive

- We will recursively join two linked list such that they will be aways sorted.

---

# [35. Search Insert Position](./35_searchInsertPosition.md)

### O(log N) Time solution

- Modification of BS.
- l<r
  - if target greater than element at mid.
    - l = mid+1
  - else
    - r = mid // not mid-1;
- return l

---

# [36. Valid Sudoku](./36_validSudoku.md) 🌟🌟

### Implementation

---

# [53. Maximum Subarray](./53_maximumSubarray.md) 🌟

### O(N) time constant space(DP)

- We maintain a maximum sum and current sum(if element itself is max)
- for each i=(0,n)
  - add current element to current sum
  - mx = max(current sum , mx);
  - current sum will be max(0,current sum);
- finally we return mx

---

# [74. Search a 2D Matrix](./74_search2DMatrix.md) 🌟🌟

### O(N\*M) Time and constant space solution

- Brute force.
- Traverse through the matrix and check for the target.
- If the target is found, return true.
- finally return false.

### O(N\*logM) Time and constant space solution

- Search using binary search.

### O(log(N\*M)) Time and O(1) space

- Complete Binary search on matrix.
- mid/m : row , mid%m : column

---

# [83. Remove Duplicates from Sorted List](./removeDuplicatesFromSortedList.md) 🌟

### O(N) Time and O(1) Space

- if value of current node is equal to the value of the next node, delete the next node
- else traverse next node,

---

# [88. Merge Sorted Array](./88_mergeSortedArray.md) 🌟

### O(M+N) Time and O(M+N) space

- Create new array with m+n elements.
- Traverse through both the given array, find min and insert in the new array.

### O(M\*N) without using extra Space

- Traverse through both the given array
- If arr1[i]>arr2[i] then swap the elements and sort the second array.(here sorting means just put swapped element at its right position not real sorting)

### O(M+N) Time and O(1) Space

- Code is self explanetory on leetcode

### Using GAP algorithm(striver)

**Here soon**

## <!-- TODO: Write GAP algo -->

---

# [94. Binary Tree Inorder Traversal](./94_binaryTreeInorderTraversal.md) 🌟

### O(N) Time and O(N) auxillary space, recursive

- if root is null, Return.
- Traverse Left subtree.
- Visit the root (store data).
- Traverse Right subtree.

### O(N) Time and O(N) Space, itterative

- if root is null, Return.
- while true
  - if left node present, then traverse all the way left.& push node in the stack.
  - if stack is empty, break the loop.
  - get the top in node variable and push it in ans vector.
  - now move to the right.
- return inorder(ans) vector.

### O(N) Time and O(1) Space, Morris Traversal

**Soon...**

<!-- TODO: Morris traversal -->

---

# [118. Pascal's Triangle](./118_pascalsTriangle.md) 🌟

### Straightforward solution

---

# [121. Best Time to Buy and Sell Stock](./121_bestTimeToBuyAndSellStock.md) 🌟

### O(N^2) Time and O(1) Space

- Brute force:
- For each day, find the max profit that can be made by buying at that day and selling at the next j days.

### O(N) Time and O(N) Space

- We try to sell stock each day.
- For each day from last we store maximum stock price that will appeare.
- then for each day we calculate by selling the stock.

### O(N) Time and O(1) Space

- We try to buy stock each day.
- For each day we keep track of the minimum price of the stock that appeared before it.
- if todays stock price is minimum we will update it.
- return max profit.

### Optimized inner loop : 33% less time.

- If the price of the stock that day less than minimun price so far then there is no chance to get profit so we only update minimum price.
- else we can get profit, update maxProfit.

---

# [141. Linked List Cycle](./141_linkedListCycle.md) 🌟

### O(N) Time and O(N) space

- If there is a cycle in given linked list then same node must appear more than once.
- so, we create an unordered_set of nodes ands while traversing the list we check if the node is already present in the linked list.
- if its present we return true else we insert it into the unordered_set.
- finally after completing loop we return false. because there is no cycle.

### O(N) Time and O(1) space - floyds cycle detection algorithm

- Here fast pointer move 2 steps and slow pointer moves one step.
- If they meet each other while traversing then loop that means there is a cycle else not.

---

# [144. Binary Tree Preorder Traversal](./144_binaryTreePreorderTraversal.md) 🌟

### O(N) Time O(N) space (function call stack), Recursive

- if root is null, Return.
- Visit the root (store data).
- Traverse Left subtree.
- Traverse Right subtree.

### O(N) Time and O(N) extra space

- Create a vector to store values and stack for operations
- if tree is empty, return empty vector
- else push root into stack
- while stack is not empty
  - pop the top element from stack
  - push the value of the popped element into vector
  - we want left to the top of stack, so we store it last so it appear on the top of stack
  - if right node is not empty, push it into stack
  - if left node is not empty, push it into stack

### Morris traversal - O(N) time and O(N) space.

**Explaination soon...**

## <!-- TODO: morris traversal -->

---

# [145. Binary Tree Postorder Traversal](./145_binaryTreePostorderTraversal.md) 🌟

### O(N) Time and O(2N) space, Itterative

**NOTE:** _Here instead of ***2 Stack*** I have used ***1 Stack and 1 vector*** and reversed the vector at the end._

More detail explaination watch [this](https://www.youtube.com/watch?v=2YBhNLodD8Q) 4 min video.

### O(N) Time and O(N) Space, Itterative (1 stack)

**This is bit tricky.Dry run 2-3 trees to understand**
Watch [this](https://www.youtube.com/watch?v=NzIGLLwZBS8) Video.

### O(N) Time and O(1) Space, Morris traversal

**soon...**

## <!-- TODO: Morris traversal -->

# [167. Two Sum II - Input array is sorted](./167_twoSumII_inputArrayIsSorted.md) 🌟

### O(N) Time 2-pointers solution

- We maintain 2 pointers, one at the start and one at the end.
- We itterate over the array.
  - If Sum if equal to target, return the indices.
  - else if sum is greater than target we decrement the end pointer.
  - else we increment the start pointer.

---

# [189. Rotate Array](./189_rotateArray.md) 🌟

### O(N) Time and O(N) space

- Create new array
- copy the original array
- Rotate the array by (i+k)%n.

### O(N) Time and O(1) Space

- k%=nums.size(), because if k>n so we need to do only k%n operations.
- reverse the array.
- reverse the first k elements.
- reverse the rest of the array.

---

# [203. Remove Linked List Elements](./203_removeLinkedListElement.md) 🌟

### O(N) Time and O(1) Space

- Implimentation

### O(N) Time and O(1) Space, recursive

- if head is null return null.
- if value of current node is val we not include it else we include it.

---

# [206. Reverse Linked List](./206_reverseLinkedList.md) 🌟

### O(N) Time and O(1) space, itterative

Given the head of a singly linked list, reverse the list, and return the reversed list.

- Initialize three pointers prev as NULL, curr as head and next as NULL.
- Iterate through the linked list. In loop, do following.
  - Before changing next of current, store next node
    next = curr->next
  - Now change next of current This is where actual reversing happens
    curr->next = prev
  - Move prev and curr one step forward
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

- Cheak for every element, if it is present in the array using 2 loops.

### O(N log N) Time and constant space

- We can sort the array, so duplicate elements will be next to each other.

### O(N) Time and O(N) Space

- We can use a hash table to store the elements.

---

# [232. Implement Queue using Stacks](./232_implementQueueUsingStacks.md) 🌟

### O(1) AMORTIZED Time solution

- **AMORTIZED**: Most of the times operations are O(1) time. Sometimes it will be O(n) time. But total time for all the operations will be O(1).
- Using 2 stacks; one is used for read and another for write.

---

# [242. Valid Anagram](./242_validAnagram.md) 🌟

### O(N logN) Time and constant space

- Sort both strings and compare them.
- if they are equal, return true else false.

### O(N) Time and O(N)=O(26) constant space

- We store frequency of each character in a hash table.
- Decrement the frequency of each character in hash table which is in the t.
- If any frequency is not zero, return false.

### Only 2 loops

- First confirm sizes of both strings is same.
- We can avoid 3rd loop by checking if the frequency of each character less than 0 then return false.
- return true by default.

---

# [278. First Bad Version](./278_firstBadVersion.md) 🌟

### O(log N) Time solution

- Slight modification of binary search.
- l=1,r=n;

---

# [283. Move Zeroes](./281_moveZeros.md) 🌟

### O(N) Time solution

- We will shift all non zero elements at front
- Then remaining elements will be filled with zeros

### O(N) Time snowball solution

- The idea is that we go through the array and gather all zeros on our road.
- If element is 0, increase size of snowball by 1.
- else we swap it with (i-snowball)th element.
- **NOTE:** here we used temp variable instead of direct swapping for avoiding unnecessary swapplin. For ex.`[1]` no swap required.

---

# [344. Reverse String](./344_reverseString.md) 🌟

### O(N) Time two pointer solution

- swap start and end pointers.

---

# [350. Intersection of Two Arrays II](./350_intersectionOfTwoArraysII.md) 🌟

### O(N\*M) Time and O(N) Space

- Brute force
- for every element in nums1, check if it exists in nums2
- if it exists then add it to the ans and set it to -1 and break inner loop, so duplicats will not be included.
- return ans

---

# [383. Ransom Note](./383_ransomNote.md) 🌟

### same as is_subsequence problem.

### O(N) Time O(N)=O(26) constant space

- calculate frequency of each letter in magazine
- iterate over ransomNote and decrement frequency of each letter
- if any letter frequency is less than 0, return false

---

# [387. First Unique Character in a String](./387_firstUniqueCharacterInAString.md) 🌟

### O(N^2) Time and O(1) space

- Brute force
- For every character check if it appears in the string more than once

### O(N) Time and O(N)=O(26) constant space

- Store frequency of every character in a hash table
- Iterate through the hash table and check if the character is Unique

---

# [557. Reverse Words in a String III](./557_reverseWordsInString.md) 🌟

### O(N\*M) Time solution

- Where N: lenght of string and M: lenght of substring splited by space.
- The idea is to reverse the substring splitted by spaces, so the final result will be possible.

---

# [566. Reshape the Matrix](./566_reshapeMatrix.md) 🌟

### O(N\*M) Time and O(N\*M)+O(N\*M) Space

- naive approach
- store 2D array in 1D temporary array.
- Create new r\*c matrix and fill it with the values from the temporary array.

### O(N\*M) Time and O(N\*M) Space (Row-First Approach

- M[i] => M[i/n][i%n] it will result in right mapping
- `i/c` will give us the row number of output matrix. We will move to New row after every c elements and thus dividing by c will give the row number.
- `i%c` will give us the column number of output matrix. We will be begin from start of new row after every c elements and this the remainder will give column of current row.
- The same happens in i/n and i%n but for the mat matrix).

### O(N\*M) Time and O(N\*M) Space (Column-First Approach)

### <!-- TODO: (Column-First Approach) -->

soon...

---

# [704. Binary Search](./704_binarySearch.md) 🌟

### O(log N) Time algorithm

- **NOTE:** _Array must be sorted.if not then sort array first._
- Point two variables l and r to the first and last position of array.
- while(l<=r)
  - if middle element is target then return middle index
  - if middle element is greater than target then r = middle - 1
  - if middle element is less than target then l = middle + 1
- if we cant find element in array, return -1.

---

# [832. Flipping an Image](./832_flippingAnImage.md) 🌟

### O(N^2) Time and O(1) Space

- Use inbuilt reverse() function to revese the vector.
- To Toggle we can use either `y=1-y` or `y^=1`

---

# [867. Transpose Matrix](./867_transposeMatrix.md) 🌟

### O(N\*M) Time and O(N\*M) space

- Get no of rows and columns of given matrix.
- Create a new matrix of with no.rows=no.columns and no.columns=no.rows.
- Iterate over the matrix and copy the values from the given matrix to the new matrix `ans[j][i]=matrix[i][j]`;
- Space can be optimizes in case of square matrix, where we can use in place swapping of rows and columns.

---

# [977. Squares of a Sorted Array](./977_squaresOfASortedArray.md) 🌟

### O(NlogN) Time solution

- Create new array and push_back squares of each element in it.
- Sort the new array.
- Return the new array.

### O(N) Time solution

- We use two pointer method to solve this problem.
- set two array l=0 and r=arr.size()-1.
- traverse throught the array and set max abs values square at last position.
- return the array.

---

# [989. Add to Array-Form of Integer](./989_addToArrayFormOfInteger.md) 🌟

### O(N) Time and O(1) Space

- We use k itself as carry.
- From last to first we fill array with addition and mod.
- If after loop, k have some carry we insert k to the start of array untill it becomes 0.

---

# [1295. Find Numbers with Even Number of Digits](./1295_findNumbersWithEvenNumberOfDigits.md`) 🌟

### O(N\*length(num)) Time and O(1) Space

- Implementation.

### O(N) Time and O(1) Space

- Using log10(num) to find the length of the number.
- log10(num) gives lenght(num)-1.

---

# [1365. How Many Numbers Are Smaller Than the Current Number](./1365_howMenyNumbersAreSmallerThanTheCurrentNumber.md) 🌟

### O(N^2) Time solution

- Brute force for each array element.

### O(N) Time O(N) space optimization

- Store the count in a bucket and take the running sum.

---

# [1389. Create Target Array in the Given Order](./1389_createTargetArrayInTheGivenOrder.md) 🌟

### O(N^2) Time solution

- Brute force

### O(N\*logN) based on "smaller elements after self".

- It is HARD level problem
- Will be added soon...
<!-- TODO:ADD O(N*logN) Solution -->

---

# [1431. Kids With the Greatest Number of Candies](./1431_kidsWithTheGreatestNumberOfCandies.md) 🌟

### O(N) Time and O(N) Space Solution:

- Use greedy approach. For each kid check if candies[i] + extraCandies ≥ maximum in all Candies

---

# [1470. Shuffle the Array](./1470_shuffleTheArray.md) 🌟

### O(N) Time and O(N) Space solution

- Use two pointers to create the new array of 2n elements. The first starting at the beginning and the other starting at (n+1)th position. Alternate between them and create the new array.

---

# [1480. Running Sum of 1d Array](./1480_runningSumArr.md) 🌟

### O(N) Time and O(N) Space solution

- Create a sum variable to store current sum in it ans push back it in the result array.

### O(N) Time and O(1) Space optimization

- We can modify input array directy

---

# [1512. Number of Good Pairs](./1512_numberOfGoodPairs.md) 🌟

### O(N^2) Time O(1) Space solution

- Check for each element of array and return the ans.

### O(N) Time O(N) Space optimization

- Use map to store if the number appeard before or not.
- If it appeard add frequency to ans.else add it to map.

---

# [1572. Matrix Diagonal Sum](./1572_matrixDiagonalSum.md) 🌟

### O(N) Time O(1) Space solution

- Smart Implimentation😉

---

# [1672. Richest Customer Wealth](./1672_richestCustomerWealth.md) 🌟

### O(N^2) Time and O(1) Space solution

- Use inbuilt accumulate function to get the sum of all the elements in the array

---

# [1732. Find the Highest Altitude](./1732_findHighestAltitude.md) 🌟

### O(N) Time and O(1) Space solution

- Start from 0, add each altitude and store max altitude.

---

# [1773. Count Items Matching a Rule](./1773_countItemsMatchingARule.md) 🌟

### O(N) Time and O(1) Space solution

- Implementation.

---

# [1832. Check if the Sentence Is Pangram](./1832_checkIfSentenceIsPanagram.md) 🌟

### O(N) Time O(N) Space Solution

- Create a set and check if its length is exactly 26 or not.

---

# [1854. Maximum Population Year](./1854_maximumPopulationYear.md) 🌟

### O(N) Time and O(N) Space

- We can mark the start and end of each life as +1 and -1 on the timeline.
- Then, we go through timeline from 1950 to 2050 and accumulate the current population for each year.

---

# [1886. Determine Whether Matrix Can Be Obtained By Rotation](./1886_determineWhetherMatrixCanBeObtainedByRotation.md) 🌟

### O(N^2) Time solution

- Suppose we are at index i, j, let us find a relation of this position with it's position in various rotations. i. e

```
- 0 deg rotation : i, j will point to i, j
- 90 deg rotation : i, j will point to j, n - i - 1
- 180 deg rotation : i, j will point to n - i - 1, n - j - 1
- 270 deg rotation : i, j will point to n - j - 1, i
```

- We denote these rotations by boolean variables, initially we assume all these rotations are valid, so we set them all to true. Here

```
c[0] -> 0 deg rotation,
c[1] -> 90 deg,
c[2] -> 180 deg,
c[3] -> 270 deg
```

- Then, we loop over all elements and check if that particular rotation is valid or not. If not, we turn it to false.
- In the end, we simply check if any of the rotations is still possible or not.

---

# [1920. Build Array from Permutation](./1920_buildArrayFromPermutation.md) 🌟

### O(N) Time and O(N) Space solution

- For i=0 to n , simply do what they have asked to.
- Push_back(nums[nums[i]])

### O(N) Time and O(1) Space optimization

- This is done to keep both old and new value together.
- going by the example of [5,0,1,2,3,4], n = 6(size of array)
- `nums[i] = nums[i]+(n*(nums[nums[i]]%n));`
- after this nums[0] will be 5 + 6\*(4%6) = 5 + 24 = 29;
- now for next index calulation we might need the original value of num[0] which can be obtain by num[0]%6 = 29%6 = 5;
- if we want to get just the new value of num[0], we can get it by num[0]/6 = 29/6 = 4

---

# [1929. Concatenation of Array](./1929_ConcatinationOfArray.md) 🌟

### O(N) Time and O(N) Space solution

- We will use inbuilt function `vector.insert()` to concatenate the arrays.
