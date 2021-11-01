# [130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/) 🌟🌟

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

### DFS Approach complex

- This [video](https://www.youtube.com/watch?v=0ZJViJEdtEc) explains both the approaches and code.
- 1st approach is complex while 2nd is easy.

### DFS Approach more efficient

- Pick all O's from boundary (Top/Bottom row, Leftmost/Rightmost column)
- Make all connected O's to some intermediate value (1 in my case).
- Now remaining all O's are surrounded by X (otherwise they should have been converted to 1).
- Convert remaining all O to X.
- Revert all intermediate values. (1 to O).

- **Time Complexity** - **O(m \* n)**
- **Space Complexity** - **O(1)** if we ignore recursive stack calls else **O(m \* n)**

### Code

```cpp
class Solution{
private:
	vector<int> dirs = {1, 0, -1, 0, 1};

	void dfs(vector<vector<char>> &board, int i, int j)
	{
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') return;

		board[i][j] = '1';
		for (int k = 0; k < 4; k++){
			int nr = i + dirs[k], nc = j + dirs[k + 1];
			dfs(board, nr, nc);
		}
	}

public:
	void solve(vector<vector<char>> &board)
	{
		int r = board.size();
		int c = board[0].size();

		for (int i = 0; i < r; i++){ // first and last col
			dfs(board, i, 0);
			dfs(board, i, c - 1);
		}
		for (int j = 0; j < c; j++){ // first and last row
			dfs(board, 0, j);
			dfs(board, r - 1, j);
		}

		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				board[i][j] = (board[i][j] == '1') ? 'O' : 'X';
			}
		}
	}
};
```
