#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BACKTRACKING
{
public:
	vector<vector<int>> combine(int n, int k);//77. ���
	vector<vector<int>> combinationSum3(int k, int n);//216. ����ܺ� III
	vector<string> letterCombinations(string digits);//17. �绰�������ĸ���
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);//39. ����ܺ�
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);//40. ����ܺ� II
	vector<vector<string>> partition(string s);//131
	vector<vector<int>> subsets(vector<int>& nums);//78
	vector<vector<int>> subsetsWithDup(vector<int>& nums);//90
	vector<vector<int>> permute(vector<int>& nums);//46
	vector<vector<int>> permuteUnique(vector<int>& nums);//47
};

extern BACKTRACKING backtracking;

void test_77();//���
void test_216();//����ܺ�III
void test_17();//�绰�������ĸ���
void test_39();//����ܺ�
void test_40();//����ܺ�II
void test_131();//�ָ���Ĵ�
void test_93();//��ԭIP��ַ
void test_78();//�Ӽ�
void test_90();//�Ӽ�II
void test_491();//����������
void test_46();//ȫ����
void test_47();//ȫ���� II
void test_22();//��������



