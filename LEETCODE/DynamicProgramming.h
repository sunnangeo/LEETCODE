#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class DYNAMICPROGRAMMING
{
public:
	int fib(int n);//509. 쳲������� | ��ָ Offer 10- I. 쳲���������
	int climbStairs(int n);//70. ��¥�� | ��ָ Offer 10- II. ������̨������
	bool exist(vector<vector<char>>& board, string word);// 79. �������� | ��ָ Offer 12. �����е�·��
	
	int uniquePaths(int m, int n);//62. ��ͬ·��
	int movingCount(int m, int n, int k);//��ָ Offer 13. �����˵��˶���Χ
	int minPathSum(vector<vector<int>>& grid);//64. ��С·����
	int numIslands(vector<vector<char>>& grid);//200. ��������
	int maxValue(vector<vector<int>>& grid);///��ָ Offer 47. ���������ֵ
	int minDistance(string word1, string word2);//72. �༭����
	int integerBreak(int n);//343. ������� | ��ָ Offer 14- I. ������
	int maxSubArray(vector<int>& nums);//53. ���������� | ��ָ Offer 42. ���������������
	int translateNum(int num);//��ָ Offer 46. �����ַ�����ַ���
	int maxProfit(vector<int>& prices);//��ָ Offer 63. ��Ʊ���������
	string longestPalindrome(string s);//5. ������Ӵ�
	int numTrees(int n);//96. ��ͬ�Ķ���������
};

extern DYNAMICPROGRAMMING dynamicprogramming;

void test_509();//509. 쳲������� | ��ָ Offer 10- I. 쳲���������
void test_70();//70. ��¥�� | ��ָ Offer 10- II. ������̨������
void test_79();// 79. �������� | ��ָ Offer 12. �����е�·��
void test_62();//62. ��ͬ·��
void test_offer13();//��ָ Offer 13. �����˵��˶���Χ
void test_64();//64. ��С·����
void test_200();// 200. ��������
void test_offer47();//��ָ Offer 47. ���������ֵ
void test_72();//72. �༭����
void test_343 ();//343. ������� | ��ָ Offer 14- I. ������
void test_53();//53. ���������� | ��ָ Offer 42. ���������������
//void test_233();//��ָ Offer 43. 1��n ������ 1 ���ֵĴ���
void test_offer46();//��ָ Offer 46. �����ַ�����ַ���
void test_121();//��ָ Offer 63. ��Ʊ���������
void test_5();//5. ������Ӵ�
void test_22();//22. ��������
void test_96();//96. ��ͬ�Ķ���������


