#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

class Sort {
public:
	int search(vector<int>& nums, int target);//704. 二分查找
	void moveZeroes(vector<int>& nums);//283.移动零
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);//240. 搜索二维矩阵 II | 剑指 Offer 04. 二维数组中的查找
	int minArray(vector<int>& numbers);//剑指 Offer 11. 旋转数组的最小数字
	vector<int> printNumbers(int n); //剑指 Offer 17. 打印从1到最大的n位数
	vector<int> exchange(vector<int>& nums);//剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
	vector<int> spiralOrder(vector<vector<int>>& matrix);//剑指 Offer 29. 顺时针打印矩阵
	int singleNumbers(vector<int>& nums);//剑指 Offer 56 - I.数组中数字出现的次数
	int singleNumber(vector<int>& nums);//剑指 Offer 56 - II.数组中数字出现的次数
	bool isStraight(vector<int>& nums);//剑指 Offer 61. 扑克牌中的顺子
	vector<int> constructArr(vector<int>& a);//剑指 Offer 66. 构建乘积数组
	vector<int> getLeastNumbers(vector<int>& arr, int k);//面试题40.最小的k个数
};


void test_704(); //704. 二分查找
void test_283(); //283.移动零
void test_76(); //76. 最小覆盖子串
void test_240();//240. 搜索二维矩阵 II | 剑指 Offer 04. 二维数组中的查找
void test_154();//剑指 Offer 11. 旋转数组的最小数字
void test_offer17();// 剑指 Offer 17. 打印从1到最大的n位数
void test_offer21();//剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
void test_54();//剑指 Offer 29. 顺时针打印矩阵
void test_offer56(); //剑指 Offer 56 - I.数组中数字出现的次数
void test_offer61(); //剑指 Offer 61. 扑克牌中的顺子
void test_offer66(); //剑指 Offer 66. 构建乘积数组
void test_mianshi40(); //面试题40.最小的k个数