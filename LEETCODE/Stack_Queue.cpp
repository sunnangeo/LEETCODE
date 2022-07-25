#include "Stack_Queue.h"

void test_232()
{
}

void test_20()
{
}

void test_1047()
{
}

void test_150()
{
}

void test_239()
{
}

void test_347()
{
}

void test_155()
{
}

void test_946()
{
}

void test_offer59()
{
}

bool STACKQUEUE::isValid(string s)
{
	stack<int> st;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') st.push(')');
		else if (s[i] == '{') st.push('}');
		else if (s[i] == '[') st.push(']');
		else if (st.empty() || s[i] != st.top()) return false;
		else st.pop();
	}

	return st.empty();
}

string STACKQUEUE::removeDuplicates(string s)
{
	string result;
	for (char S : s) {
		if (result.empty() || result.back() != S) {
			result.push_back(S);
		}
		else {
			result.pop_back();
		}
	}

	return result;
}

int STACKQUEUE::evalRPN(vector<string>& tokens)
{
	stack<int> st;
	for (int i = 0; i < tokens.size(); ++i) {
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			if (tokens[i] == "+") st.push(num2 + num1);
			if (tokens[i] == "-") st.push(num2 - num1);
			if (tokens[i] == "*") st.push(num2 * num1);
			if (tokens[i] == "/") st.push(num2 / num1);
		}
		else {
			st.push(stoi(tokens[i]));
		}
	}
	return st.top();
}

vector<int> STACKQUEUE::maxSlidingWindow(vector<int>& nums, int k)
{
	Myqueue que;
	vector<int> result;
	if (nums.size() == 0) return result;

	for (int i = 0; i < k; ++i) {
		que.push(nums[i]);
	}
	result.push_back(que.front());
	for (int i = k; i < nums.size(); ++i) {
		que.pop(nums[i - k]);
		que.push(nums[i]);
		result.push_back(que.front());
	}

	return result;
	return vector<int>();
}

vector<int> STACKQUEUE::topKFrequent(vector<int>& nums, int k)
{
	vector<int> result(k, 0);
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i) {
		map[nums[i]]++;
	}
	auto f = [](const pair<int, int> &left, const pair<int, int> &right) {
		return left.second > right.second; };
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> pri_que(f);

	for (auto it = map.begin(); it != map.end(); it++) {
		pri_que.push(*it);
		if (pri_que.size() > k) {
			pri_que.pop();
		}
	}


	for (int i = k - 1; i >= 0; --i) {
		result[i] = pri_que.top().first;
		pri_que.pop();
	}

	return result;
}

bool STACKQUEUE::validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
	stack<int> st;
	int i = 0;
	for (auto num : pushed) {
		st.push(num);
		while (!st.empty() && popped[i] == st.top()) {
			st.pop();
			i++;
		}
	}

	return st.empty();
}
