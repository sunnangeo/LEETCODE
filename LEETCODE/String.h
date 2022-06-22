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

void test_344();//��ת�ַ���
void test_541();//��ת�ַ���II
void test_offer05();//�滻�ո�
void test_151();//��ת�ַ�����ĵ��� | Offer 58 - I. ��ת����˳��
void test_offer58II();// ����ת�ַ���
void test_offer20();//��ʾ��ֵ���ַ���
void test_8();//�ַ���ת������ (atoi) | Offer 67. ���ַ���ת��������
void test_925();//��������
void test_844();//�ȽϺ��˸���ַ���

