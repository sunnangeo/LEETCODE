#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>

#include "BinaryTree.h"
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};

//707
class MyLinkedList {
public:
	// ��������ڵ�ṹ��
	struct LinkedNode {
		int val;
		LinkedNode* next;
		LinkedNode(int val) :val(val), next(nullptr) {}
	};

	// ��ʼ������
	MyLinkedList() {
		_dummyHead = new LinkedNode(0); // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
		_size = 0;
	}

	// ��ȡ����index���ڵ���ֵ�����index�ǷǷ���ֱֵ�ӷ���-1�� ע��index�Ǵ�0��ʼ�ģ���0���ڵ����ͷ���
	int get(int index) {
		if (index > (_size - 1) || index < 0) {
			return -1;
		}
		LinkedNode* cur = _dummyHead;
		while (index--) { // ���--index �ͻ�������ѭ��
			cur = cur->next;
		}
		return cur->next->val;
	}

	// ��������ǰ�����һ���ڵ㣬������ɺ��²���Ľڵ�Ϊ������µ�ͷ���
	void addAtHead(int val) {
		//LinkedNode* newNode = new LinkedNode(val);
		//newNode->next = _dummyHead->next;
		//_dummyHead->next = newNode;
		//_size++;
		LinkedNode* newNode = new LinkedNode(val);
		newNode->next = _dummyHead->next;
		_dummyHead->next = newNode;
		_size++;
	}

	// ��������������һ���ڵ�
	void addAtTail(int val) {
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = newNode;
		_size++;
	}

	// �ڵ�index���ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
	// ���index ��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β���
	// ���index��������ĳ��ȣ��򷵻ؿ�
	void addAtIndex(int index, int val) {
		if (index > _size) {
			return;
		} 
		if (index < 0) index = 0;
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (index--) {
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		_size++;
	}

	// ɾ����index���ڵ㣬���index ���ڵ�������ĳ��ȣ�ֱ��return��ע��index�Ǵ�0��ʼ��
	void deleteAtIndex(int index) {
		if (index >= _size || index < 0) {
			return;
		}
		LinkedNode* cur = _dummyHead;
		while (index--) {
			cur = cur->next;
		}
		LinkedNode* tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		_size--;
	}

	// ��ӡ����
	void printLinkedList() {
		LinkedNode* cur = _dummyHead;
		while (cur->next != nullptr) {
			cout << cur->next->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
private:
	int _size;
	LinkedNode* _dummyHead;

};

//146
class LRUCache {
public:
	LRUCache(int capacity) : _capacity(capacity) {

	}

	int get(int key) {
		auto it = _table.find(key);
		if (it != _table.end()) {
			_lru.splice(_lru.begin(), _lru, it->second);
			return it->second->second;
		}
		return -1;
	}

	void put(int key, int value) {
		auto it = _table.find(key);
		if (it != _table.end()) {
			_lru.splice(_lru.begin(), _lru, it->second);
			it->second->second = value;
			return;
		}

		_lru.emplace_front(key, value);
		_table[key] = _lru.begin();

		if (_table.size() > _capacity) {
			_table.erase(_lru.back().first);
			_lru.pop_back();
		}
	}
private:
	unordered_map<int, std::list<std::pair<int, int>>::iterator> _table;
	std::list<std::pair<int, int>> _lru;
	int _capacity;
};
ListNode* createList(vector<int>& nums);
void print_list(ListNode *head);
class LINKEDLIST
{
public:
	ListNode* removeElements(ListNode* head, int val);//203
	ListNode* reverseList(ListNode* head);//206
	ListNode* swapPairs(ListNode* head);//24
	ListNode* removeNthFromEnd(ListNode* head, int n);//19
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);//0209
	bool hasCycle(ListNode *head);//141
	ListNode* detectCycle(ListNode *head);//142
	bool isPalindrome(ListNode* head);//234
	void reorderList(ListNode* head);//143
	ListNode* middleNode(ListNode* head);//876
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);//21
	ListNode* mergeKLists(vector<ListNode*>& lists);//23
	Node* copyRandomList(Node* head);//138
	TreeNode* treeToDoublyList(TreeNode* root);//426
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);//2
	void flatten(TreeNode* root);//114
	ListNode* sortList(ListNode* head);//148
};

extern LINKEDLIST linkedlist;

void test_203();//�Ƴ�����Ԫ�� | offer18.ɾ������Ľڵ�
void test_707();//�������
void test_206();//��ת���� | offer06.��ͷ��β��ӡ���� | offer24.��ת����
void test_24();//�������������еĽڵ�
void test_19();//ɾ������ĵ�����N���ڵ� | offer22.�����е�����k���ڵ�
void test_160();//�����ཻ | 0209������ | Offer52.��������ĵ�һ�������ڵ���������ĵ�һ�������ڵ�
void test_141();//��������
void test_142();//��������II
void test_234();//��������
void test_876();//������м�ڵ�
void test_143();//��������
void test_21();//�ϲ�������������� | offer25.�ϲ��������������
void test_23();//�ϲ�K����������
void test_138();//���ƴ����ָ������� | offer35.��������ĸ���
void test_426();//������������ת��Ϊ�����˫������ | Offer36.������������˫������
void test_2();//�������
void test_114();//������չ��Ϊ����
void test_146();//LRU����
void test_148();//��������

