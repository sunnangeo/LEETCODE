#include "String.h"

STRING String;
void test_344()
{
	vector<char> s = { 'h', 'e', 'l', 'l', 'o' };
	String.reverseString(s);
}

void test_541()
{
	string s = "abcdefg"; 
	int k = 2;

}

void test_offer05()
{
	string s = "We are happy.";
	string result = String.replaceSpace(s);
}

void test_151()
{
	string s = "  hello world  ";
	string result = String.reverseWords(s);
}

void test_offer58II()
{
	string s = "sadfrv";
	int n = 2;
	string result = String.reverseLeftWords(s, n);
}

void test_offer20()
{
}

void test_8()
{
	string s = "   -42";
	int result = String.strToInt(s);
}

void test_925()
{
	string name = "alex", typed = "aaleex";
	bool result = String.isLongPressedName(name, typed);
}

void test_844()
{
	string s = "ab#c", t = "ad#c";
	bool result = String.backspaceCompare(s, t);
}

void STRING::reverseString(vector<char>& s)
{
	for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
		swap(s[i], s[j]);
	}
}

bool STRING::isLongPressedName(string name, string typed)
{
	int i = 0, j = 0;
	while (i < name.size() && j < typed.size()) {
		if (name[i] == typed[j]) {
			i++;
			j++;
		}
		else {
			if (j == 0) return false;
			while (j < typed.size() && typed[j] == typed[j - 1]) j++;
			if (name[i] == typed[j]) {
				i++;
				j++;
			}
			else return false;
		}
	}

	if (i < name.size()) return false;
	while (j < typed.size()) {
		if (typed[j] == typed[j - 1]) j++;
		else return false;
	}

	return true;
}
string build(string& str) {
	int slow = 0;
	int fast = 0;
	string result;
	for (; fast < str.size(); fast++) {
		if (str[fast] != '#') {
			result.push_back(str[fast]);
		}
		else if (!result.empty()) {
			result.pop_back();
		}
	}
	return result;
}
bool STRING::backspaceCompare(string s, string t)
{
	return build(s) == build(t) ? true : false;
}

string STRING::reverseStr(string s, int k)
{
	for (int i = 0; i < s.size(); i += 2 * k) {
		if (i + k <= s.size()) {
			reverse(s.begin() + i, s.begin() + i + k);
		}
		else {
			reverse(s.begin() + i, s.end());
		}
	}
	return s;
}

string STRING::replaceSpace(string s)
{
	int count = 0;
	int oldsize = s.size();
	for (int i = 0; i < oldsize; i++) {
		if (s[i] == ' ') {
			count++;
		}
	}

	int newsize = oldsize + 2 * count;
	s.resize(newsize);
	for (int i = newsize - 1, j = oldsize - 1; j < i; i--, j--) {
		if (s[j] != ' ') {
			s[i] = s[j];
		}
		else {
			s[i] = '0';
			s[i - 1] = '2';
			s[i - 2] = '%';

			i -= 2;
		}
	}

	return s;
}
void cancelSpace(string &s) {
	int fast = 0;
	int slow = 0;
	while (s.size() > 0 && fast < s.size() && s[fast] == ' ') fast++;
	for (; fast < s.size(); fast++) {
		if (fast > 1 && s[fast] == ' ' && s[fast] == s[fast - 1]) continue;
		else s[slow++] = s[fast];
	}
	if (slow > 1 && s[slow - 1] == ' ') {
		s.resize(slow - 1);
	}
	else {
		s.resize(slow);
	}
}
string STRING::reverseWords(string s)
{
	cancelSpace(s);
	reverse(s.begin(), s.end());

	for (int frontIndex = 0, backIndex = 0; frontIndex < s.size(); frontIndex++) {
		if (s[frontIndex] == ' ') {
			reverse(s.begin() + backIndex, s.begin() + frontIndex);
			backIndex = frontIndex + 1;
		}
		if (frontIndex == s.size() - 1) {
			reverse(s.begin() + backIndex, s.end());
		}
	}

	return s;
}

string STRING::reverseLeftWords(string s, int n)
{
	reverse(s.begin(), s.begin() + n);
	reverse(s.begin() + n, s.end());
	reverse(s.begin(), s.end());

	return s;
}

int STRING::strToInt(string str)
{
	long result = 0;
	bool neg = false;
	int i = 0;
	while (str[i] == ' ') i++;
	if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-') return 0;
	if (str[i] == '-') { neg = true; i++; }
	else if (str[i] == '+') i++;
	while (isdigit(str[i])) {
		result = result * 10 + str[i] - '0';
		if (neg == false && result > INT_MAX) return INT_MAX;
		else if (neg == true && -result < INT_MIN) return INT_MIN;
		i++;
	}

	return neg == false ? result : -result;
}
