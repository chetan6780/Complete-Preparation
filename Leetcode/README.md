# Leetcode problem hints and solutions

#### Difficulty level:

- 🌟 **- Easy**
- 🌟🌟 **- Medium**
- 🌟🌟🌟 **- Hard**

---

# [832. Flipping an Image](./832_flippingAnImage.md)

### O(N^2) Time and O(1) Space

- Use inbuilt reverse() function to revese the vector.
- To Toggle we can use either `y=1-y` or `y^=1`

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
