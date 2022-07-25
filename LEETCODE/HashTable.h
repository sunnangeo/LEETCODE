#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class HASHTABLE
{
public:
	bool isAnagram(string s, string t);//242
	vector<vector<string>> groupAnagrams(vector<string>& strs);//49
	vector<int> findAnagrams(string s, string p);//438
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);//349
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2);//350
	bool isHappy(int n);//202
	vector<int> twoSum(vector<int>& nums, int target);//1
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);//454
	bool canConstruct(string ransomNote, string magazine);//383
	vector<vector<int>> threeSum(vector<int>& nums);//15
	vector<vector<int>> fourSum(vector<int>& nums, int target);//18
	int longestConsecutive(vector<int>& nums);//128
	vector<int> findDisappearedNumbers(vector<int>& nums);//448
	int subarraySum(vector<int>& nums, int k);//560**************
	int findRepeatNumber(vector<int>& nums);//offer03
	int majorityElement(vector<int>& nums);//169
	int lengthOfLongestSubstring(string s);//3
	char firstUniqChar(string s);//offer50
	int search(vector<int>& nums, int target);//34
	int missingNumber(vector<int>& nums);//offer53
	bool isIsomorphic(string s, string t);//205

};

extern HASHTABLE hashtable;

void test_242();//有效的字母异位词
void test_49();//字母异位词分组
void test_438();//找到字符串中所有字母异位词
void test_349();//两个数组的交集
void test_350();//两个数组的交集 II
void test_202();//快乐数
void test_1();//两数之和
void test_454();//四数相加II
void test_383();//赎金信
void test_15();//三数之和
void test_18();//四数之和
void test_128();//最长连续序列
void test_448();//找到所有数组中消失的数字
void test_560();//和为K的子数组
void test_621();//任务调度器
void test_offer03();//数组中重复的数字
void test_169();//多数元素 | Offer 39. 数组中出现次数超过一半的数字
void test_3();//无重复字符的最长子串 | Offer 48. 最长不含重复字符的子字符串
void test_offer50();//第一个只出现一次的字符
void test_34();//在排序数组中查找元素的第一个和最后一个位置 | offer53I 在排序数组中查找数字I
void test_offer53II();//0～n-1中缺失的数字
void test_205();//同构字符串


