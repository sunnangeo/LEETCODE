#include "HashTable.h"

HASHTABLE hashtable;

bool HASHTABLE::isAnagram(string s, string t) {
	unordered_map<char, int> map;
	if (s.size() != t.size()) return false;
	for (int i = 0; i < s.size(); i++) {
		++map[s[i]];
		--map[t[i]];
	}
	for (auto it = map.begin(); it != map.end(); it++) {
		if (it->second != 0) {
			return false;
		}
	}
	return true;
}

vector<vector<string>> HASHTABLE::groupAnagrams(vector<string>& strs)
{
	unordered_map<string, vector<string>> map;
	vector<vector<string>> result;
	for (int i = 0; i < strs.size(); ++i) {
		string s = strs[i];
		sort(s.begin(), s.end());
		map[s].push_back(strs[i]);
	}

	for (auto it = map.begin(); it != map.end(); ++it) {
		result.push_back(it->second);
	}
	return result;
}
vector<int> HASHTABLE::findAnagrams(string s, string p) {
	vector<int> result;
	vector<int> svec(26);
	vector<int> pvec(26);
	int len_s = s.size();
	int len_p = p.size();
	if (len_p > len_s) return result;
	for (int i = 0; i < p.size(); i++) {
		svec[s[i] - 'a']++;
		pvec[p[i] - 'a']++;
	}
	if (svec == pvec) result.push_back(0);

	for (int i = 0; i < len_s - len_p; i++) {
		--svec[s[i] - 'a'];
		++svec[s[i + len_p] - 'a'];

		if (svec == pvec) result.push_back(i + 1);
	}
	return result;
}
vector<int> HASHTABLE::intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_set<int> result;
	unordered_set<int> nums_set(nums1.begin(), nums1.end());

	for (auto num : nums2) {
		if (nums_set.find(num) != nums_set.end()) {
			result.insert(num);
		}
	}

	return vector<int>(result.begin(), result.end());
}
vector<int> HASHTABLE::intersect(vector<int>& nums1, vector<int>& nums2)
{
	if (nums1.size() > nums2.size()) {
		return intersect(nums2, nums1);
	}
	unordered_map<int, int> map;
	for (int num : nums1) {
		map[num]++;
	}
	vector<int> result;
	for (int num : nums2) {
		if (map.count(num)) {
			result.push_back(num);
			map[num]--;
			if (map[num] == 0) {
				map.erase(num);
			}
		}
	}
	return result;
}

int getSum(int n) {
	int sum = 0;
	while (n) {
		sum += (n % 10) * (n % 10);
		n /= 10;
	}
	return sum;
}
bool HASHTABLE::isHappy(int n)
{
	unordered_set<int> set;
	while (1) {
		int num = getSum(n);
		if (num == 1) {
			return true;
		}
		if (set.find(num) != set.end()) {
			return false;
		}
		else {
			set.insert(num);
		}
		n = num;
	}
}
vector<int> HASHTABLE::twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	if (nums.size() == 0) return result;
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i) {
		auto it = map.find(target - nums[i]);
		if (it != map.end()) {
			return { it->second, i };
		}
		map.insert(pair<int, int>(nums[i], i));
	}
	return {};
}
int HASHTABLE::fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
	unordered_map<int, int> map;
	for (int i = 0; i < nums1.size(); i++) {
		for (int j = 0; j < nums2.size(); j++) {
			++map[nums1[i] + nums2[j]];
		}
	}
	int count = 0;
	for (int i = 0; i < nums3.size(); i++) {
		for (int j = 0; j < nums4.size(); j++) {
			auto it = map.find(0 - (nums3[i] + nums4[j]));
			if (it != map.end()) {
				count += it->second;
			}
		}
	}
	return count;
}
bool HASHTABLE::canConstruct(string ransomNote, string magazine)
{
	int hash[26] = { 0 };
	for (char m : magazine) {
		hash[m - 'a']++;
	}
	for (char r : ransomNote) {
		hash[r - 'a']--;
		if (hash[r - 'a'] < 0) {
			return false;
		}
	}
	return true;
}
vector<vector<int>> HASHTABLE::threeSum(vector<int>& nums)
{
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > 0) return result;
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		int l = i + 1;
		int r = nums.size() - 1;

		while (l < r) {
			if (nums[i] + nums[l] + nums[r] > 0) {
				r--;
				while (l < r && nums[r] == nums[r + 1]) r--;
			}
			else if (nums[i] + nums[l] + nums[r] < 0) {
				l++;
				while (l < r && nums[l] == nums[l - 1]) l++;
			}
			else {
				result.push_back(vector<int>{nums[i], nums[l], nums[r]});		
				r--;
				l++;
				while (l < r && nums[r] == nums[r + 1]) r--;
				while (l < r && nums[l] == nums[l - 1]) l++;
			}
		}
	}
	return result;
}
vector<vector<int>> HASHTABLE::fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		for (int j = i + 1; j < nums.size(); j++) {
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			int l = j + 1;
			int r = nums.size() - 1;
			while (r > l)
				if (nums[i] + nums[j] > target - (nums[l] + nums[r])) {
					r--;
					while (r > l && nums[r] == nums[r + 1]) r--;
				}
				else if (nums[i] + nums[j] < target - (nums[l] + nums[r])) {
					l++;
					while (r > l && nums[l] == nums[l - 1]) l++;
				}
				else {
					result.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
					r--;
					l++;
					while (r > l && nums[r] == nums[r + 1]) r--;
					while (r > l && nums[l] == nums[l - 1]) l++;
				}
		}
	}
	return result;
}
int HASHTABLE::longestConsecutive(vector<int>& nums)
{
	int longSeq = 0;
	unordered_set<int> seq(nums.begin(), nums.end());
	for (int num : seq) {
		if (!seq.count(num - 1)) {
			int curSeq = 1;
			while (seq.count(num + 1)) {
				num++;
				curSeq += 1;
			}
			longSeq = max(longSeq, curSeq);
		}
	}

	return longSeq;
}
vector<int> HASHTABLE::findDisappearedNumbers(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
	}
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		if (nums[i] > 0) {
			res.push_back(i + 1);
		}
	}
	return res;
}
int HASHTABLE::subarraySum(vector<int>& nums, int k)
{
	unordered_map<int, int> mp;
	mp[0] = 1;
	int count = 0, pre = 0;
	for (auto& x : nums) {
		pre += x;
		if (mp.find(pre - k) != mp.end()) {
			count += mp[pre - k];
		}
		mp[pre]++;
	}
	return count;
}
int HASHTABLE::findRepeatNumber(vector<int>& nums)
{
	unordered_map<int, int> map;
	int result;
	for (int i = 0; i < nums.size(); i++) {
		map[nums[i]]++;
		if (map[nums[i]] > 1) {
			result = nums[i];
		}
	}
	return result;
}
int HASHTABLE::majorityElement(vector<int>& nums)
{
	unordered_map<int, int> map;
	int number = 0;
	int count = 0;
	for (auto num : nums) {
		++map[num];
		if (map[num] > count) {
			number = num;
			count = map[num];
		}
	}
	return number;
}
int HASHTABLE::lengthOfLongestSubstring(string s)
{
	unordered_set<char> set;
	int left = 0;
	int result = 0;
	for (int right = 0; right < s.size(); ++right) {
		while (set.find(s[right]) != set.end()) {
			set.erase(s[left]);
			left++;
		}

		set.insert(s[right]);
		result = max(result, right - left + 1);
	}

	return result;
}
char HASHTABLE::firstUniqChar(string s)
{
	unordered_map<char, int> map;
	for (int i = 0; i < s.size(); ++i) {
		++map[s[i]];
	}
	for (int i = 0; i < s.size(); ++i) {
		if (map[s[i]] == 1) {
			return s[i];
		}
	}
	return ' ';
}

int HASHTABLE::search(vector<int>& nums, int target)
{
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i) {
		++map[nums[i]];
	}
	if (map.find(target) != map.end()) {
		return map.find(target)->second;
	}
	else {
		return 0;
	}
}

int HASHTABLE::missingNumber(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == mid) left = mid + 1;
		else right = mid - 1;
	}
	return left;
}

bool HASHTABLE::isIsomorphic(string s, string t)
{
	unordered_map<char, char> map1;
	unordered_map<char, char> map2;
	for (int i = 0; i < s.size(); ++i) {
		if (map1.find(s[i]) == map1.end()) {
			map1[s[i]] = t[i];
		}
		if (map2.find(t[i]) == map2.end()) {
			map2[t[i]] = s[i];
		}
		if (map1[s[i]] != t[i] || map2[t[i]] != s[i]) {
			return false;
		}
	}
	return true;
}

/****************************************************/

void test_242()
{
	string s = "anagram";
	string t = "nagaram";
	bool result = hashtable.isAnagram(s,t);
}

void test_49()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> result = hashtable.groupAnagrams(strs);
}

void test_438()
{
	string s = "cbaebabacd",  p = "abc";
	vector<int> result = hashtable.findAnagrams(s, p);
}

void test_349()
{
	vector<int> nums1 = { 1, 2, 2, 1 }, nums2 = { 2, 2 };
	vector<int> result = hashtable.intersection(nums1,nums2);
}

void test_350()
{
	vector<int> nums1 = { 1, 2, 2, 1 }, nums2 = { 2, 2 };
	vector<int> result = hashtable.intersect(nums1, nums2);
}

void test_202()
{
	int n = 19;
	bool result = hashtable.isHappy(n);
}

void test_1()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> result = hashtable.twoSum(nums, target);
}

void test_454()
{
	vector<int> nums1 = { 1, 2 }, nums2 = { -2, -1 }, nums3 = { -1, 2 }, nums4 = { 0, 2 };
	int result = hashtable.fourSumCount(nums1, nums2, nums3, nums4);
}

void test_383()
{
	string ransomNote = "aa", magazine = "aab";
	bool result = hashtable.canConstruct(ransomNote, magazine);
}

void test_15()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result = hashtable.threeSum(nums);
}

void test_18()
{
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	int target = 0;
	vector<vector<int>>result = hashtable.fourSum(nums, target);
}

void test_128()
{
	vector<int> nums = { 100, 4, 200, 1, 3, 2 };
	int result = hashtable.longestConsecutive(nums);
}

void test_448()
{
	vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> result = hashtable.findDisappearedNumbers(nums);
}

void test_560()
{
	vector<int> nums = { 1, 2, 3 };
	int k = 3;
	int result = hashtable.subarraySum(nums, k);
}

void test_621()
{
}

void test_offer03()
{
	vector<int> nums = { 2, 3, 1, 0, 2, 5, 3 };
	int result = hashtable.findRepeatNumber(nums);
}

void test_169()
{
	vector<int> nums = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int result = hashtable.majorityElement(nums);
}

void test_3()
{
	string str = "pwwkew";
	int result = hashtable.lengthOfLongestSubstring(str);
}

void test_offer50()
{
	string s = "abaccdeff";
	char result = hashtable.firstUniqChar(s);
}

void test_34()
{
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;
	int result = hashtable.search(nums, target);
}

void test_offer53II()
{
	vector<int> nums = { 0, 1, 2, 3, 4, 5, 6, 7, 9 };
	int result = hashtable.missingNumber(nums);
}

void test_205()
{
	string s = "egg", t = "add";
	bool result = hashtable.isIsomorphic(s, t);
}
