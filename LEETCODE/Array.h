#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

class Sort {
public:
	int search(vector<int>& nums, int target);//704. ���ֲ���
	void moveZeroes(vector<int>& nums);//283.�ƶ���
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);//240. ������ά���� II | ��ָ Offer 04. ��ά�����еĲ���
	int minArray(vector<int>& numbers);//��ָ Offer 11. ��ת�������С����
	vector<int> printNumbers(int n); //��ָ Offer 17. ��ӡ��1������nλ��
	vector<int> exchange(vector<int>& nums);//��ָ Offer 21. ��������˳��ʹ����λ��ż��ǰ��
	vector<int> spiralOrder(vector<vector<int>>& matrix);//��ָ Offer 29. ˳ʱ���ӡ����
	int singleNumbers(vector<int>& nums);//��ָ Offer 56 - I.���������ֳ��ֵĴ���
	int singleNumber(vector<int>& nums);//��ָ Offer 56 - II.���������ֳ��ֵĴ���
	bool isStraight(vector<int>& nums);//��ָ Offer 61. �˿����е�˳��
	vector<int> constructArr(vector<int>& a);//��ָ Offer 66. �����˻�����
	vector<int> getLeastNumbers(vector<int>& arr, int k);//������40.��С��k����
};


void test_704(); //704. ���ֲ���
void test_283(); //283.�ƶ���
void test_76(); //76. ��С�����Ӵ�
void test_240();//240. ������ά���� II | ��ָ Offer 04. ��ά�����еĲ���
void test_154();//��ָ Offer 11. ��ת�������С����
void test_offer17();// ��ָ Offer 17. ��ӡ��1������nλ��
void test_offer21();//��ָ Offer 21. ��������˳��ʹ����λ��ż��ǰ��
void test_54();//��ָ Offer 29. ˳ʱ���ӡ����
void test_offer56(); //��ָ Offer 56 - I.���������ֳ��ֵĴ���
void test_offer61(); //��ָ Offer 61. �˿����е�˳��
void test_offer66(); //��ָ Offer 66. �����˻�����
void test_mianshi40(); //������40.��С��k����