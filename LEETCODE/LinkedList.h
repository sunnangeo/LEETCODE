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
	// 定义链表节点结构体
	struct LinkedNode {
		int val;
		LinkedNode* next;
		LinkedNode(int val) :val(val), next(nullptr) {}
	};

	// 初始化链表
	MyLinkedList() {
		_dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
		_size = 0;
	}

	// 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
	int get(int index) {
		if (index > (_size - 1) || index < 0) {
			return -1;
		}
		LinkedNode* cur = _dummyHead;
		while (index--) { // 如果--index 就会陷入死循环
			cur = cur->next;
		}
		return cur->next->val;
	}

	// 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
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

	// 在链表最后面添加一个节点
	void addAtTail(int val) {
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = newNode;
		_size++;
	}

	// 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
	// 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
	// 如果index大于链表的长度，则返回空
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

	// 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
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

	// 打印链表
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

void test_203();//移除链表元素 | offer18.删除链表的节点
void test_707();//设计链表
void test_206();//反转链表 | offer06.从头到尾打印链表 | offer24.反转链表
void test_24();//两两交换链表中的节点
void test_19();//删除链表的倒数第N个节点 | offer22.链表中倒数第k个节点
void test_160();//链表相交 | 0209面试题 | Offer52.两个链表的第一个公共节点两个链表的第一个公共节点
void test_141();//环形链表
void test_142();//环形链表II
void test_234();//回文链表
void test_876();//链表的中间节点
void test_143();//重排链表
void test_21();//合并两个排序的链表 | offer25.合并两个排序的链表
void test_23();//合并K个升序链表
void test_138();//复制带随机指针的链表 | offer35.复杂链表的复制
void test_426();//将二叉搜索树转化为排序的双向链表 | Offer36.二叉搜索树与双向链表
void test_2();//两数相加
void test_114();//二叉树展开为链表
void test_146();//LRU缓存
void test_148();//排序链表

