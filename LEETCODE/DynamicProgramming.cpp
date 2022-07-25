#include "DynamicProgrammingi.h"
#include "DynamicProgramming.h"

int DYNAMICPROGRAMMING::fib(int n)
{
	if (n < 1) return 0;
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int DYNAMICPROGRAMMING::climbStairs(int n)
{
	if (n <= 1) return 1;
	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int row;
int col;
bool dfs_79(vector<vector<char>>& board, string& word, int i, int j, int index) {
	if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != word[index]) return false;
	if (index == word.size() - 1) return true;

	board[i][j] = '#';

	for (int k = 0; k < 4; ++k) {
		if (dfs_79(board, word, i + dx[k], j + dy[k], index + 1)) return true;
	}

	board[i][j] = word[index];
	return false;

}
bool DYNAMICPROGRAMMING::exist(vector<vector<char>>& board, string word)
{
	row = board.size();
	col = board[0].size();

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (dfs_79(board, word, i, j, 0)) return true;
		}
	}

	return false;
}

//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { 1, 0, -1, 0 };
int num = 0;

void dfs_offer13(int x, int y, int m, int n, int k, vector<vector<int>> &visited) {
	if (x < 0 || y < 0 || y >= n || x >= m || visited[x][y] == 1 ||
		(x / 10 + x % 10 + y / 10 + y % 10) > k) return;

	num++;
	visited[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		dfs_offer13(x + dx[i], y + dy[i], m, n, k, visited);
	}
}
int DYNAMICPROGRAMMING::movingCount(int m, int n, int k)
{
	vector<vector<int>> visited(m, vector<int>(n));
	dfs_offer13(0, 0, m, n, k, visited);
	return num;
}

int DYNAMICPROGRAMMING::minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 && j == 0) continue;
			else if (i == 0) grid[i][j] += grid[0][j - 1];
			else if (j == 0) grid[i][j] += grid[i - 1][0];
			else {
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
	}

	return grid[m - 1][n - 1];
}

void dfs_200(vector<vector<char>>& grid, int i, int j) {
	if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1') return;

	grid[i][j] = '0';

	for (int k = 0; k < 4; ++k) {
		dfs_200(grid, i + dx[k], j + dy[k]);
	}
}
int DYNAMICPROGRAMMING::numIslands(vector<vector<char>>& grid)
{
	row = grid.size();
	col = grid[0].size();
	int result = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (grid[i][j] == '1') {
				dfs_200(grid, i, j);
				result++;
			}
		}
	}

	return result;
}

int DYNAMICPROGRAMMING::maxValue(vector<vector<int>>& grid)
{
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<int>> dp(row, vector<int>(col));
	dp[0][0] = grid[0][0];
	for (int k = 1; k < row; ++k) dp[k][0] = dp[k - 1][0] + grid[k][0];
	for (int k = 1; k < col; ++k) dp[0][k] = dp[0][k - 1] + grid[0][k];

	for (int i = 1; i < row; ++i) {
		for (int j = 1; j < col; ++j) {
			dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[row - 1][col - 1];
}

int DYNAMICPROGRAMMING::minDistance(string word1, string word2)
{
	vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));

	for (int k = 0; k <= word1.size(); ++k) dp[k][0] = k;
	for (int k = 0; k <= word2.size(); ++k) dp[0][k] = k;

	for (int i = 1; i <= word1.size(); ++i) {
		for (int j = 1; j <= word2.size(); ++j) {
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min({ dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1, dp[i - 1][j] + 1 });
			}
		}
	}

	return dp[word1.size()][word2.size()];

}

int DYNAMICPROGRAMMING::integerBreak(int n)
{
	vector<int> dp(n + 1);
	dp[2] = 1;
	for (int i = 3; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			dp[i] = max(dp[i], max(j *(i - j), j * dp[i - j]));
		}
	}

	return dp[n];
}

int DYNAMICPROGRAMMING::maxSubArray(vector<int>& nums)
{
	vector<int> dp(nums.size());
	int result = nums[0];
	dp[0] = nums[0];

	for (int i = 1; i < nums.size(); ++i) {
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
		result = result > dp[i] ? result : dp[i];
	}

	return result;
}

int DYNAMICPROGRAMMING::translateNum(int num)
{
	string str = to_string(num);
	vector<int> dp(str.size() + 1);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= str.size(); ++i) {
		int a = stoi(str.substr(i - 2, 2));
		if (a >= 10 && a < 26) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
}

int DYNAMICPROGRAMMING::maxProfit(vector<int>& prices)
{
	int low = INT_MAX;
	int result = 0;
	for (int i = 0; i < prices.size(); ++i) {
		low = min(prices[i], low);
		result = max(result, prices[i] - low);
	}

	return result;
}



void extend(string &s, int i, int j, int n, int& left, int& right, int maxLength) {
	while (i >= 0 && j <= n && s[i] == s[j]) {
		if (j - i + 1 > maxLength) {
			left = i;
			right = j;
			maxLength = j - i + 1;
		}
		i--;
		j++;
	}
}
string DYNAMICPROGRAMMING::longestPalindrome(string s)
{
	int left = 0;
	int right = 0;
	int maxLength = 0;
	
	for (int i = 0; i < s.size(); ++i) {
		extend(s, i, i, s.size() - 1, left, right, maxLength);
		extend(s, i, i + 1, s.size() - 1, left, right, maxLength);
	}

	return s.substr(left, maxLength);
}

int DYNAMICPROGRAMMING::numTrees(int n)
{
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}

	return dp[n];
}

int DYNAMICPROGRAMMING::uniquePaths(int m, int n)
{
	vector<vector<int>> dp(m, vector<int>(n));
	for (int k = 0; k < m; ++k) dp[k][0] = 1;
	for (int k = 0; k < n; ++k) dp[0][k] = 1;

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[m - 1][n - 1];
}
