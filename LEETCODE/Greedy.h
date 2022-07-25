#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class GREEDY
{
public:
	int maxArea(vector<int>& height);//11. ʢ���ˮ������
	bool canJump(vector<int>& nums);////55. ��Ծ��Ϸ
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people);//406. ��������ؽ�����
	int findUnsortedSubarray(vector<int>& nums);//581. �����������������
	string minNumber(vector<int>& nums);//��ָ Offer 45. �������ų���С����

};

extern GREEDY greedy;

void test_11();//11. ʢ���ˮ������
void test_55();//55. ��Ծ��Ϸ
void test_406();//406. ��������ؽ�����
void test_581();//581. �����������������
void test_621();//621. ���������
void test_offer45();//��ָ Offer 45. �������ų���С����