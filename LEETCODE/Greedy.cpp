#include "Greedy.h"

int GREEDY::maxArea(vector<int>& height)
{
	int i = 0;
	int j = height.size() - 1;
	int result = 0;
	while (i < j) {
		result = height[i] < height[j] ?
			max((j - i) * height[i++], result) :
			max((j - i) * height[j--], result);
	}

	return result;
}

bool GREEDY::canJump(vector<int>& nums)
{
	int cover = 0;
	for (int i = 0; i <= cover; ++i) {
		cover = max(cover, i + nums[i]);
		if (cover >= nums.size() - 1) return true;
	}

	return false;
}

vector<vector<int>> GREEDY::reconstructQueue(vector<vector<int>>& people)
{
	sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
		if (a[0] == b[0]) return a[1] < b[1];
		return a[0] > b[0];
	});
	vector<vector<int>> que;
	for (int i = 0; i < people.size(); i++) {
		int position = people[i][1];
		que.insert(que.begin() + position, people[i]);
	}
	return que;
}

int GREEDY::findUnsortedSubarray(vector<int>& nums)
{
	if (is_sorted(nums.begin(), nums.end())) {
		return 0;
	}

	vector<int> SortNums(nums);
	sort(SortNums.begin(), SortNums.end());

	int i = 0;
	while (SortNums[i] == nums[i]) {
		i++;
	}

	int j = nums.size() - 1;
	while (SortNums[j] == nums[j]) {
		j--;
	}

	return j - i + 1;
}

string GREEDY::minNumber(vector<int>& nums)
{
	vector<string> str;
	for (int num : nums) {
		str.push_back(to_string(num));
	}
	sort(str.begin(), str.end(), [](const string &a, const string &b) -> bool {
		return a + b < b + a;
	});
	string result;
	for (auto s : str) {
		result += s;
	}
	return result;
}
