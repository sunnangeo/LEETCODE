#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BACKTRACKING
{
public:
	vector<vector<int>> combine(int n, int k);//77. 组合
	vector<vector<int>> combinationSum3(int k, int n);//216. 组合总和 III
	vector<string> letterCombinations(string digits);//17. 电话号码的字母组合
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);//39. 组合总和
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);//40. 组合总和 II
	vector<vector<string>> partition(string s);//131
	vector<vector<int>> subsets(vector<int>& nums);//78
	vector<vector<int>> subsetsWithDup(vector<int>& nums);//90
	vector<vector<int>> permute(vector<int>& nums);//46
	vector<vector<int>> permuteUnique(vector<int>& nums);//47
};

extern BACKTRACKING backtracking;

void test_77();//组合
void test_216();//组合总和III
void test_17();//电话号码的字母组合
void test_39();//组合总和
void test_40();//组合总和II
void test_131();//分割回文串
void test_93();//复原IP地址
void test_78();//子集
void test_90();//子集II
void test_491();//递增子序列
void test_46();//全排列
void test_47();//全排列 II
void test_22();//括号生成



