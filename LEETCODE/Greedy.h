#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class GREEDY
{
public:
	int maxArea(vector<int>& height);//11. 盛最多水的容器
	bool canJump(vector<int>& nums);////55. 跳跃游戏
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people);//406. 根据身高重建队列
	int findUnsortedSubarray(vector<int>& nums);//581. 最短无序连续子数组
	string minNumber(vector<int>& nums);//剑指 Offer 45. 把数组排成最小的数

};

extern GREEDY greedy;

void test_11();//11. 盛最多水的容器
void test_55();//55. 跳跃游戏
void test_406();//406. 根据身高重建队列
void test_581();//581. 最短无序连续子数组
void test_621();//621. 任务调度器
void test_offer45();//剑指 Offer 45. 把数组排成最小的数