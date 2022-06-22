#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class STRING
{
public:
	void reverseString(vector<char>& s);//344
	bool isLongPressedName(string name, string typed);//925
	bool backspaceCompare(string s, string t);//844
	string reverseStr(string s, int k);//541
	string replaceSpace(string s);//offer05
	string reverseWords(string s);//151
	string reverseLeftWords(string s, int n);//offer58II
	int strToInt(string str);//8
};

extern STRING String;

void test_344();//反转字符串
void test_541();//反转字符串II
void test_offer05();//替换空格
void test_151();//翻转字符串里的单词 | Offer 58 - I. 翻转单词顺序
void test_offer58II();// 左旋转字符串
void test_offer20();//表示数值的字符串
void test_8();//字符串转换整数 (atoi) | Offer 67. 把字符串转换成整数
void test_925();//长按键入
void test_844();//比较含退格的字符串

