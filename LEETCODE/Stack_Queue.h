#pragma once

#pragma once
#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;
//232
class MyQueue {
public:
	stack<int> in;
	stack<int> out;
	MyQueue() {

	}

	void push(int x) {
		in.push(x);
	}

	int pop() {
		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.top());
				in.pop();
			}
		}
		int result = out.top();
		out.pop();
		return result;
	}

	int peek() {
		int result = this->pop();
		out.push(result);
		return result;
	}

	bool empty() {
		return  in.empty() && out.empty();
	}
};
class Myqueue {
public: deque<int> dque;
		void pop(int value) {
			if (!dque.empty() && dque.front() == value) {
				dque.pop_front();
			}
		}

		void push(int value) {
			while (!dque.empty() && dque.back() < value) {
				dque.pop_back();
			}

			dque.push_back(value);
		}

		int front() {
			return dque.front();
		}
};
class MinStack {
public:
	stack<int> st;
	stack<int> st_min;
	MinStack() {
		st_min.push(INT_MAX);
	}

	void push(int val) {
		st.push(val);
		st_min.push(min(st_min.top(), val));
	}

	void pop() {
		st.pop();
		st_min.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return st_min.top();
	}
};
class MaxQueue {
public:
	deque<int> dque;
	queue<int> que;
	MaxQueue() {

	}

	int max_value() {
		return dque.empty() ? -1 : dque.front();
	}

	void push_back(int value) {
		while (!dque.empty() && value > dque.back()) {
			dque.pop_back();
		}
		dque.push_back(value);
		que.push(value);
	}

	int pop_front() {
		if (dque.empty()) return -1;
		int ret = que.front();
		if (ret == dque.front()) {
			dque.pop_front();
		}

		que.pop();
		return ret;
	}
};
class STACKQUEUE
{
public:
	bool isValid(string s);//20. ��Ч������
	string removeDuplicates(string s);//1047. ɾ���ַ����е����������ظ���
	int evalRPN(vector<string>& tokens);//150. �沨�����ʽ��ֵ
	vector<int> maxSlidingWindow(vector<int>& nums, int k);//239. �����������ֵ
	vector<int> topKFrequent(vector<int>& nums, int k);//347.ǰ K ����ƵԪ��
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped);//946. ��֤ջ���� | ��ָ Offer 31. ջ��ѹ�롢��������

};

extern STACKQUEUE stackqueue;

void test_232();//232.��ջʵ�ֶ���
void test_20();//20. ��Ч������
void test_1047();//1047. ɾ���ַ����е����������ظ���
void test_150();//150. �沨�����ʽ��ֵ
void test_239();//239. �����������ֵ
void test_347();//347.ǰ K ����ƵԪ��
void test_155();//155. ��Сջ | ��ָ Offer 30. ����min������ջ
void test_946();//946. ��֤ջ���� | ��ָ Offer 31. ջ��ѹ�롢��������
void test_offer59();//��ָ Offer 59 - II.���е����ֵ