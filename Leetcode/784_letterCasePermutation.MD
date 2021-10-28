# [784. Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) 🌟🌟

Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

### Backtracking

### Code

```cpp
class Solution{
	void backtrack(string &s, int i, vector<string> &res){
		if (i == s.size()){
			res.push_back(s);
			return;
		}
		backtrack(s, i + 1, res);
		if (isalpha(s[i])){
			// toggle case
			s[i] ^= 32; // (1<<5)
			backtrack(s, i + 1, res);
		}
	}

public:
	vector<string> letterCasePermutation(string S){
		vector<string> res;
		backtrack(S, 0, res);
		return res;
	}
};
```
