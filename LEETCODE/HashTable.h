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

void test_242();//��Ч����ĸ��λ��
void test_49();//��ĸ��λ�ʷ���
void test_438();//�ҵ��ַ�����������ĸ��λ��
void test_349();//��������Ľ���
void test_350();//��������Ľ��� II
void test_202();//������
void test_1();//����֮��
void test_454();//�������II
void test_383();//�����
void test_15();//����֮��
void test_18();//����֮��
void test_128();//���������
void test_448();//�ҵ�������������ʧ������
void test_560();//��ΪK��������
void test_621();//���������
void test_offer03();//�������ظ�������
void test_169();//����Ԫ�� | Offer 39. �����г��ִ�������һ�������
void test_3();//���ظ��ַ�����Ӵ� | Offer 48. ������ظ��ַ������ַ���
void test_offer50();//��һ��ֻ����һ�ε��ַ�
void test_34();//�����������в���Ԫ�صĵ�һ�������һ��λ�� | offer53I �����������в�������I
void test_offer53II();//0��n-1��ȱʧ������
void test_205();//ͬ���ַ���


