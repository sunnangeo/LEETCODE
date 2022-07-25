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
	bool isValid(string s);//20. 有效的括号
	string removeDuplicates(string s);//1047. 删除字符串中的所有相邻重复项
	int evalRPN(vector<string>& tokens);//150. 逆波兰表达式求值
	vector<int> maxSlidingWindow(vector<int>& nums, int k);//239. 滑动窗口最大值
	vector<int> topKFrequent(vector<int>& nums, int k);//347.前 K 个高频元素
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped);//946. 验证栈序列 | 剑指 Offer 31. 栈的压入、弹出序列

};

extern STACKQUEUE stackqueue;

void test_232();//232.用栈实现队列
void test_20();//20. 有效的括号
void test_1047();//1047. 删除字符串中的所有相邻重复项
void test_150();//150. 逆波兰表达式求值
void test_239();//239. 滑动窗口最大值
void test_347();//347.前 K 个高频元素
void test_155();//155. 最小栈 | 剑指 Offer 30. 包含min函数的栈
void test_946();//946. 验证栈序列 | 剑指 Offer 31. 栈的压入、弹出序列
void test_offer59();//剑指 Offer 59 - II.队列的最大值