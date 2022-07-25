#include "BackTracking.h"

void dfs_77(int n, int k, int startIndex, vector<vector<int>>& result, vector<int>& path) {
	if (path.size() == k) {
		result.push_back(path);
		return;
	}

	for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i) {
		path.push_back(i);
		dfs_77(n, k, i + 1, result, path);
		path.pop_back();
	}
}
vector<vector<int>> BACKTRACKING::combine(int n, int k)
{
	return vector<vector<int>>();
}
void dfs_216(int target, int k, int sum, int startIndex, vector<vector<int>> &result, vector<int> &path) {
	if (target == sum && path.size() == k) {
		result.push_back(path);
		return;
	}

	for (int i = startIndex; i <= 9; ++i) {
		sum += i;
		path.push_back(i);
		dfs_216(target, k, sum, i + 1, result, path);
		path.pop_back();
		sum -= i;
	}
}
vector<vector<int>> BACKTRACKING::combinationSum3(int k, int n)
{
	vector<vector<int>> result;
	vector<int> path;
	dfs_216(n, k, 0, 1, result, path);
	return result;
}
const string letterMap[10] = {
	"", // 0
	"", // 1
	"abc", // 2
	"def", // 3
	"ghi", // 4
	"jkl", // 5
	"mno", // 6
	"pqrs", // 7
	"tuv", // 8
	"wxyz", // 9
};
void dfs_17(string& digits, int index, vector<string> &result, string &s) {
	if (digits.size() == index) {
		result.push_back(s);
		return;
	}

	string letters = letterMap[digits[index] - '0'];

	for (int i = 0; i < letters.size(); ++i) {
		s.push_back(letters[i]);
		dfs_17(digits, index + 1, result, s);
		s.pop_back();
	}
}
vector<string> BACKTRACKING::letterCombinations(string digits)
{
	vector<string> result;
	string s;
	if (digits.size() == 0) {
		return result;
	}
	dfs_17(digits, 0, result, s);
	return result;
}
void dfs_39(vector<int>& candidates, int target, int sum, int startIndex, vector<vector<int>>& result, vector<int> &path) {
	if (sum > target) {
		return;
	}
	if (target == sum) {
		result.push_back(path);
		return;
	}

	for (int i = startIndex; i < candidates.size(); ++i) {
		sum += candidates[i];
		path.push_back(candidates[i]);
		dfs_39(candidates, target, sum, i, result, path);
		path.pop_back();
		sum -= candidates[i];
	}
}
vector<vector<int>> BACKTRACKING::combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	vector<int> path;
	dfs_39(candidates, target, 0, 0, result, path);
	return result;
}
void dfs_40(vector<int>& candidates, int target, int startIndex, int sum, vector<vector<int>>& result, vector<int> &path) {
	if (sum > target) return;
	if (sum == target) {
		result.push_back(path);
		return;
	}

	for (int i = startIndex; i < candidates.size(); ++i) {
		if (i > startIndex && candidates[i] == candidates[i - 1]) {
			continue;
		}
		sum += candidates[i];
		path.push_back(candidates[i]);
		dfs_40(candidates, target, i + 1, sum, result, path);
		path.pop_back();
		sum -= candidates[i];
	}
}
vector<vector<int>> BACKTRACKING::combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	vector<int> path;
	sort(candidates.begin(), candidates.end());
	dfs_40(candidates, target, 0, 0, result, path);
	return result;
}
bool isPalindrome(const string& s, int start, int end) {
	for (int i = start, j = end; i < j; i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}
void dfs_131(vector<vector<string>> &result, vector<string>& path, int startIndex, string s) {
	if (startIndex >= s.size()) {
		result.push_back(path);
		return;
	}

	for (int i = startIndex; i < s.size(); ++i) {
		if (isPalindrome(s, startIndex, i)) {
			string str = s.substr(startIndex, i - startIndex + 1);
			path.push_back(str);
		}
		else {
			continue;
		}

		dfs_131(result, path, i + 1, s);
		path.pop_back();
	}
}
vector<vector<string>> BACKTRACKING::partition(string s)
{
	vector<vector<string>> result;
	vector<string> path;
	dfs_131(result, path, 0, s);
	return result;
}
void dfs_78(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startIndex) {
	result.push_back(path);

	for (int i = startIndex; i < nums.size(); ++i) {
		path.push_back(nums[i]);
		dfs_78(result, path, nums, i + 1);
		path.pop_back();
	}
}
vector<vector<int>> BACKTRACKING::subsets(vector<int>& nums)
{
	return vector<vector<int>>();
}
void dfs_90(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startIndex, vector<bool>& used) {
	result.push_back(path);
	for (int i = startIndex; i < nums.size(); ++i) {
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
			continue;
		}
		used[i] = true;
		path.push_back(nums[i]);
		dfs_90(result, path, nums, i + 1, used);
		path.pop_back();
		used[i] = false;
	}
}
vector<vector<int>> BACKTRACKING::subsetsWithDup(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> path;
	vector<bool> used(nums.size(), false);
	sort(nums.begin(), nums.end());
	dfs_90(result, path, nums, 0, used);
	return result;
}
void dfs_46(vector<vector<int>> &result, vector<int> &path, vector<bool> &used, vector<int>& nums) {
	if (path.size() == nums.size()) {
		result.push_back(path);
		return;
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (used[i] == true) {
			continue;
		}
		path.push_back(nums[i]);
		used[i] = true;
		dfs_46(result, path, used, nums);
		used[i] = false;
		path.pop_back();
	}
}
vector<vector<int>> BACKTRACKING::permute(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> path;
	vector<bool> used(nums.size(), false);
	dfs_46(result, path, used, nums);
	return result;
}
void dfs_47(vector<vector<int>>& result, vector<int>& path, vector<bool>& used, vector<int>& nums) {
	if (path.size() == nums.size()) {
		result.push_back(path);
		return;
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
			continue;
		}

		if (used[i] == false) {
			path.push_back(nums[i]);
			used[i] = true;
			dfs_47(result, path, used, nums);
			used[i] = false;
			path.pop_back();
		}
	}
}
vector<vector<int>> BACKTRACKING::permuteUnique(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> path;
	vector<bool> used(nums.size(), false);
	sort(nums.begin(), nums.end());
	dfs_47(result, path, used, nums);
	return result;
}

void test_77()
{
}

void test_216()
{
}

void test_17()
{
}

void test_39()
{
}

void test_40()
{
}

void test_131()
{
}

void test_93()
{
}

void test_78()
{
}

void test_90()
{
}

void test_491()
{
}

void test_46()
{
}

void test_47()
{
}

void test_22()
{
}
