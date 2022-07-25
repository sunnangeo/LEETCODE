#include "Array.h"

int Sort::search(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] > target) {
			right = mid - 1;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

void Sort::moveZeroes(vector<int>& nums)
{
	int slow = 0;
	int fast = 0;

	for (; fast < nums.size(); ++fast) {
		if (nums[fast] != 0) {
			nums[slow++] = nums[fast];
		}
	}

	for (int i = slow; i < nums.size(); ++i) {
		nums[i] = 0;
	}
}

bool Sort::findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
	int i = matrix.size() - 1;
	int j = 0;
	while (i >= 0 && j < matrix[0].size()) {
		if (matrix[i][j] > target) {
			i--;
		}
		else if (matrix[i][j] < target) {
			j++;
		}
		else return true;
	}

	return false;
}

int Sort::minArray(vector<int>& numbers)
{
	int left = 0;
	int right = numbers.size() - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (numbers[mid] > numbers[right])  left = mid + 1;
		else if (numbers[mid] < numbers[right]) right = mid;
		else right--;
	}
	return numbers[left];
}

vector<int> Sort::printNumbers(int n)
{
	vector<int> result;
	for (int i = 1; i < pow(10, n); ++i) {
		result.push_back(i);
	}
	return result;
}

vector<int> Sort::exchange(vector<int>& nums)
{
	int i = 0;
	int j = nums.size() - 1;

	while (i < j) {
		while (i < j && (nums[i] & 1) == 1) i++;
		while (i < j && (nums[j] & 1) == 0) j--;
		swap(nums[i], nums[j]);
	}
	return nums;
}

vector<int> Sort::spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> result;
	if (matrix.size() == 0) return result;
	int u = 0;
	int d = matrix.size() - 1;
	int l = 0;
	int r = matrix[0].size() - 1;
	while (1) {
		for (int i = l; i <= r; ++i) result.push_back(matrix[u][i]);
		if (++u > d) break;
		for (int i = u; i <= d; ++i) result.push_back(matrix[i][r]);
		if (--r < l) break;
		for (int i = r; i >= l; --i) result.push_back(matrix[d][i]);
		if (--d < u) break;
		for (int i = d; i >= u; --i) result.push_back(matrix[i][l]);
		if (++l > r) break;
	}
	return result;
}

int Sort::singleNumbers(vector<int>& nums)
{
	int ret = 0;
	for (int num : nums) {
		ret ^= num;
	}

	int key = 1;
	while ((ret & key) == 0) {
		key <<= 1;
	}

	int a = 0;
	int b = 0;
	for (int num : nums) {
		if ((num & key) == 0) {
			a ^= num;
		}
		else {
			b ^= num;
		}
	}

	return a;
}

int Sort::singleNumber(vector<int>& nums)
{
	unordered_map<int, int> map;
	for (int num : nums) {
		map[num]++;
	}
	for (auto& s : map) {
		if (s.second == 1) {
			return s.first;
		}
	}

	return -1;
}

bool Sort::isStraight(vector<int>& nums)
{
	set<int> st;
	for (int num : nums) {
		if (num == 0) continue;
		if (st.find(num) != st.end()) return false;
		st.insert(num);
	}

	return (*st.rbegin() - *st.begin()) >= 5 ? false : true;
}

vector<int> Sort::constructArr(vector<int>& a)
{
	vector<int> b(a.size());
	int left = 1;
	for (int i = 0; i < a.size(); ++i) {
		b[i] = left;
		left *= a[i];
	}
	int right = 1;
	for (int i = a.size() - 1; i >= 0; --i) {
		b[i] *= right;
		right *= a[i];
	}

	return b;
}

vector<int> Sort::getLeastNumbers(vector<int>& arr, int k)
{
	vector<int> result;
	if (k == 0) return result;
	priority_queue<int> Q;
	for (int i = 0; i < k; ++i) {
		Q.push(arr[i]);
	}
	for (int i = k; i < arr.size(); ++i) {
		if (arr[i] < Q.top()) {
			Q.pop();
			Q.push(arr[i]);
		}
	}

	for (int i = 0; i < k; ++i) {
		result.push_back(Q.top());
		Q.pop();
	}

	return result;
}
