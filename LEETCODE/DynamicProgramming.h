#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class DYNAMICPROGRAMMING
{
public:
	int fib(int n);//509. 斐波那契数 | 剑指 Offer 10- I. 斐波那契数列
	int climbStairs(int n);//70. 爬楼梯 | 剑指 Offer 10- II. 青蛙跳台阶问题
	bool exist(vector<vector<char>>& board, string word);// 79. 单词搜索 | 剑指 Offer 12. 矩阵中的路径
	
	int uniquePaths(int m, int n);//62. 不同路径
	int movingCount(int m, int n, int k);//剑指 Offer 13. 机器人的运动范围
	int minPathSum(vector<vector<int>>& grid);//64. 最小路径和
	int numIslands(vector<vector<char>>& grid);//200. 岛屿数量
	int maxValue(vector<vector<int>>& grid);///剑指 Offer 47. 礼物的最大价值
	int minDistance(string word1, string word2);//72. 编辑距离
	int integerBreak(int n);//343. 整数拆分 | 剑指 Offer 14- I. 剪绳子
	int maxSubArray(vector<int>& nums);//53. 最大子数组和 | 剑指 Offer 42. 连续子数组的最大和
	int translateNum(int num);//剑指 Offer 46. 把数字翻译成字符串
	int maxProfit(vector<int>& prices);//剑指 Offer 63. 股票的最大利润
	string longestPalindrome(string s);//5. 最长回文子串
	int numTrees(int n);//96. 不同的二叉搜索树
};

extern DYNAMICPROGRAMMING dynamicprogramming;

void test_509();//509. 斐波那契数 | 剑指 Offer 10- I. 斐波那契数列
void test_70();//70. 爬楼梯 | 剑指 Offer 10- II. 青蛙跳台阶问题
void test_79();// 79. 单词搜索 | 剑指 Offer 12. 矩阵中的路径
void test_62();//62. 不同路径
void test_offer13();//剑指 Offer 13. 机器人的运动范围
void test_64();//64. 最小路径和
void test_200();// 200. 岛屿数量
void test_offer47();//剑指 Offer 47. 礼物的最大价值
void test_72();//72. 编辑距离
void test_343 ();//343. 整数拆分 | 剑指 Offer 14- I. 剪绳子
void test_53();//53. 最大子数组和 | 剑指 Offer 42. 连续子数组的最大和
//void test_233();//剑指 Offer 43. 1～n 整数中 1 出现的次数
void test_offer46();//剑指 Offer 46. 把数字翻译成字符串
void test_121();//剑指 Offer 63. 股票的最大利润
void test_5();//5. 最长回文子串
void test_22();//22. 括号生成
void test_96();//96. 不同的二叉搜索树


