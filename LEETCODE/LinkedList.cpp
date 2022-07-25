#include"LinkedList.h"
#include<unordered_map>

LINKEDLIST linkedlist;

ListNode* LINKEDLIST::removeElements(ListNode* head, int val) {
	ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
	dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
	ListNode* cur = dummyHead;
	while (cur->next != NULL) {
		if (cur->next->val == val) {
			ListNode* tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
		}
		else {
			cur = cur->next;
		}
	}
	head = dummyHead->next;
	delete dummyHead;
	return head;
}

ListNode* LINKEDLIST::reverseList(ListNode* head) {
	ListNode* temp; // 保存cur的下一个节点
	ListNode* cur = head;
	ListNode* pre = NULL;
	while (cur) {
		temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
		cur->next = pre; // 翻转操作
		// 更新pre 和 cur指针
		pre = cur;
		cur = temp;
	}
	return pre;
}

ListNode* LINKEDLIST::swapPairs(ListNode* head) {
	ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
	dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
	ListNode* cur = dummyHead;
	while (cur->next != nullptr && cur->next->next != nullptr) {
		ListNode* tmp = cur->next; // 记录临时节点
		ListNode* tmp1 = cur->next->next->next; // 记录临时节点

		cur->next = cur->next->next;    // 步骤一
		cur->next->next = tmp;          // 步骤二
		cur->next->next->next = tmp1;   // 步骤三

		cur = cur->next->next; // cur移动两位，准备下一轮交换
	}
	return dummyHead->next;
}

ListNode* LINKEDLIST::removeNthFromEnd(ListNode* head, int n) {
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode* slow = dummyHead;
	ListNode* fast = dummyHead;
	while (n-- && fast != NULL) {
		fast = fast->next;
	}
	fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	slow->next = slow->next->next;
	return dummyHead->next;
}

ListNode* LINKEDLIST::getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode* curA = headA;
	ListNode* curB = headB;
	int lenA = 0, lenB = 0;
	while (curA != NULL) { // 求链表A的长度
		lenA++;
		curA = curA->next;
	}
	while (curB != NULL) { // 求链表B的长度
		lenB++;
		curB = curB->next;
	}
	curA = headA;
	curB = headB;
	// 让curA为最长链表的头，lenA为其长度
	if (lenB > lenA) {
		swap(lenA, lenB);
		swap(curA, curB);
	}
	// 求长度差
	int gap = lenA - lenB;
	// 让curA和curB在同一起点上（末尾位置对齐）
	while (gap--) {
		curA = curA->next;
	}
	// 遍历curA 和 curB，遇到相同则直接返回
	while (curA != NULL) {
		if (curA == curB) {
			return curA;
		}
		curA = curA->next;
		curB = curB->next;
	}
	return NULL;
}

bool LINKEDLIST::hasCycle(ListNode *head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		// 快慢指针相遇，说明有环
		if (slow == fast) return true;
	}
	return false;
}

ListNode* LINKEDLIST::detectCycle(ListNode *head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		// 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
		if (slow == fast) {
			ListNode* index1 = fast;
			ListNode* index2 = head;
			while (index1 != index2) {
				index1 = index1->next;
				index2 = index2->next;
			}
			return index2; // 返回环的入口
		}
	}
	return NULL;
}

bool LINKEDLIST::isPalindrome(ListNode * head)
{
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* pre = head;
	while (fast != nullptr && fast->next != nullptr) {
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = nullptr;

	ListNode* cur1 = head;
	ListNode* cur2 = reverseList(slow);

	while (cur1 != nullptr) {
		if (cur1->val != cur2->val) return false;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	return true;
}

void mergeList(ListNode* l1, ListNode* l2) {
	ListNode* l1_tmp;
	ListNode* l2_tmp;
	while (l1 != nullptr && l2 != nullptr) {
		l1_tmp = l1->next;
		l2_tmp = l2->next;

		l1->next = l2;
		l1 = l1_tmp;

		l2->next = l1;
		l2 = l2_tmp;
	}
}
void LINKEDLIST::reorderList(ListNode * head)
{
	if (head == nullptr) return;
	ListNode* mid = linkedlist.middleNode(head);
	ListNode* l1 = head;
	ListNode* l2 = mid->next;
	mid->next = nullptr;
	l2 = reverseList(l2);
	mergeList(l1, l2);
}


ListNode * LINKEDLIST::mergeTwoLists(ListNode * l1, ListNode * l2)
{
	ListNode* node = new ListNode(-1);
	ListNode* preNode = node;
	while (l1 != NULL && l2 != NULL) {
		if (l1->val < l2->val) {
			preNode->next = l1;
			l1 = l1->next;
		}
		else {
			preNode->next = l2;
			l2 = l2->next;
		}
		preNode = preNode->next;
	}
	preNode->next = l1 == NULL ? l2 : l1;
	return node->next;
}

ListNode * LINKEDLIST::mergeKLists(vector<ListNode*>& lists)
{
	ListNode* result = nullptr;
	for (int i = 0; i < lists.size(); ++i) {
		result = mergeTwoLists(result, lists[i]);
	}

	return result;
}

Node * LINKEDLIST::copyRandomList(Node * head)
{
	if (head == NULL) return head;
	unordered_map<Node*, Node*> map;
	Node* cur = head;
	while (cur != nullptr) {
		map[cur] = new Node(cur->val);
		cur = cur->next;
	}
	cur = head;

	while (cur != nullptr) {
		map[cur]->next = map[cur->next];
		map[cur]->random = map[cur->random];

		cur = cur->next;
	}

	return map[head];
}

extern TreeNode* pre;
TreeNode* head;
void dfs(TreeNode* cur) {
	if (cur == NULL) return;
	dfs(cur->left);

	cur->left = pre;
	if (pre == NULL) {
		head = cur;
	}
	else {
		pre->right = cur;

	}
	pre = cur;

	dfs(cur->right);
}
TreeNode * LINKEDLIST::treeToDoublyList(TreeNode * root)
{
	if (root == NULL) return root;
	dfs(root);
	pre->right = head;
	head->left = pre;
	return head;
}

ListNode * LINKEDLIST::addTwoNumbers(ListNode * l1, ListNode * l2)
{
	ListNode* result = new ListNode(0);
	ListNode* cur = result;
	int flag = 0;
	while (l1 != NULL || l2 != NULL) {

		int x = l1 == NULL ? 0 : l1->val;
		int y = l2 == NULL ? 0 : l2->val;

		int sum = x + y + flag;
		flag = sum / 10;
		sum = sum % 10;

		cur->next = new ListNode(sum);
		cur = cur->next;
		if (l1 != NULL) l1 = l1->next;
		if (l2 != NULL) l2 = l2->next;
	}

	if (flag == 1) {
		cur->next = new ListNode(flag);
	}


	return result->next;
}

void LINKEDLIST::flatten(TreeNode * root)
{
	if (root == nullptr) return;
	while (root != nullptr) {
		if (root->left != nullptr) {
			auto most_right = root->left;
			while (most_right->right != nullptr) most_right = most_right->right;
			most_right->right = root->right;
			root->right = root->left;
			root->left = nullptr;
		}
		root = root->right;
	}
}
void merge(vector<ListNode*>& vec, int l, int m, int r) {
	vector<ListNode*> result(r - l + 1);
	int i = 0;
	int p1 = l;
	int p2 = m + 1;
	while (p1 <= m && p2 <= r) result[i++] = vec[p1]->val <= vec[p2]->val ? vec[p1++] : vec[p2++];
	while (p1 <= m) result[i++] = vec[p1++];
	while (p2 <= r) result[i++] = vec[p2++];
	for (int i = 0; i < result.size(); i++) vec[l + i] = result[i];
}
void mergeSort(vector<ListNode*>& vec, int l, int r) {
	if (l == r) return;
	int mid = l + (r - l) / 2;
	mergeSort(vec, l, mid);
	mergeSort(vec, mid + 1, r);
	merge(vec, l, mid, r);
}
ListNode * LINKEDLIST::sortList(ListNode * head)
{
	vector<ListNode*> vec;
	while (head != nullptr) {
		vec.push_back(head);
		head = head->next;
	}
	mergeSort(vec,0,vec.size() - 1);

	int i = 0;
	for (i = 1; i < vec.size(); ++i) {
		vec[i - 1]->next = vec[i];
	}
	vec[i - 1]->next = nullptr;

	return vec[0];
}

ListNode * LINKEDLIST::middleNode(ListNode * head)
{
	ListNode* fast = head;
	ListNode* slow = head;

	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;

}

ListNode* createList(vector<int>& nums) {
	ListNode* h = new ListNode(-1);
	ListNode* t;
	t = h;

	for (int i = 0; i < nums.size(); ++i) {
		t->next = new ListNode(nums[i]);
		t = t->next;
	}
	return h->next;
}
void print_list(ListNode *head)
{
	while (head != nullptr)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

void test_203()
{
	vector<int> arr= { 1, 2, 6, 3, 4, 5, 6 };
	ListNode* head = createList(arr);
	ListNode* result;
	int val = 6;
	result = linkedlist.removeElements(head, val);
	print_list(result);

}

void test_707()
{
	MyLinkedList linkedList;
	linkedList.addAtHead(1);
	linkedList.addAtTail(3);
	linkedList.addAtIndex(-1, 2);   //链表变为2 -> 1 -> 3
	int result1 = linkedList.get(1);            //返回1
	linkedList.deleteAtIndex(2);  //现在链表是2 -> 1
	int result2 = linkedList.get(1);            //返回1
}

void test_206()
{
	vector<int> arr = { 1, 2, 3, 4, 5 };
	ListNode* head = createList(arr);
	ListNode* result;
	result = linkedlist.reverseList(head);
	print_list(result);
}
void test_24()
{
	vector<int> arr = { 1, 2, 3, 4, 5 };
	ListNode* head = createList(arr);
	ListNode* result;
	result = linkedlist.swapPairs(head);
	print_list(result);
}
void test_19()
{
	vector<int> arr = { 1, 2, 3, 4, 5 };
	ListNode* head = createList(arr);
	int n = 2;
	ListNode* result;
	result = linkedlist.removeNthFromEnd(head,n);
	print_list(result);
}
void test_160()
{
	vector<int> arr1 = { 4, 1, 8, 4, 5 };
	vector<int> arr2 = { 5, 0, 1, 8, 4 ,5 };
	ListNode* head1 = createList(arr1);
	ListNode* head2 = createList(arr2);

	ListNode* result;

	result = linkedlist.getIntersectionNode(head1, head2);
	print_list(result);
}

void test_141()
{
	vector<int> arr = { 1, 2 ,3 };
	ListNode* head = createList(arr);
	bool result = linkedlist.hasCycle(head);
}

void test_142()
{
	vector<int> arr = { 1, 2 ,3 };
	ListNode* head = createList(arr);
	ListNode* result = linkedlist.detectCycle(head);
	print_list(result);
}

void test_234()
{
	vector<int> arr = { 1, 2 ,3,2, 1 };
	ListNode* head = createList(arr);
	bool result = linkedlist.isPalindrome(head);
}

void test_143()
{
	vector<int> arr = { 1, 2 ,3, 4 ,5};
	ListNode* head = createList(arr);
	linkedlist.reorderList(head);
}

void test_21()
{
	vector<int> arr1 = { 1, 2 ,4 };
	vector<int> arr2 = { 1, 3 ,4 };

	ListNode* head1 = createList(arr1);
	ListNode* head2 = createList(arr2);

	ListNode* result = linkedlist.mergeTwoLists(head1,head2);
}

void test_23()
{
	vector<int> arr1 = { 1, 4 ,5 };
	vector<int> arr2 = { 1, 3 ,4 };
	vector<int> arr3 = { 2, 6 };

	ListNode* head1 = createList(arr1);
	ListNode* head2 = createList(arr2);
	ListNode* head3 = createList(arr3);
	vector<ListNode*> lists{ head1, head2, head3 };
	ListNode* result = linkedlist.mergeKLists(lists);
}

void test_138()
{
	Node *head = new Node(7);
	Node node1(7);
	Node node2(13);
	Node node3(11);
	Node node4(10);
	Node node5(1);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = NULL;
	node1.random = NULL;
	node2.random = &node1;
	node3.random = &node5;
	node4.random = &node3;
	node5.random = &node1;
	Node* result = linkedlist.copyRandomList(&node1);
}

void test_426()
{
	TreeNode* tode1 = new TreeNode(1);
	TreeNode* tode2 = new TreeNode(2);
	TreeNode* tode3 = new TreeNode(3);
	TreeNode* tode4 = new TreeNode(4);
	TreeNode* tode5 = new TreeNode(5);

	tode4->left = tode2;
	tode4->right = tode5;
	tode2->left = tode1;
	tode2->right = tode3;

	TreeNode *result = linkedlist.treeToDoublyList(tode4);

}


void test_2()
{
	vector<int> arr1 = { 9,9,9,9,9,9,9 };
	vector<int> arr2 = { 9,9,9,9 };

	ListNode* head1 = createList(arr1);
	ListNode* head2 = createList(arr2);

	ListNode* result = linkedlist.addTwoNumbers(head1, head2);
}

void test_114()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);

	node1->left = node2;
	node1->right = node5;
	node2->left = node3;
	node2->right = node4;
	node5->right = node6;

	linkedlist.flatten(node1);
}

void test_146()
{
	LRUCache *lRUCache = new LRUCache(2);
	lRUCache->put(1, 1); // 缓存是 {1=1}
	lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
	lRUCache->get(1);    // 返回 1
	lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
	lRUCache->get(2);    // 返回 -1 (未找到)
	lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
	lRUCache->get(1);    // 返回 -1 (未找到)
	lRUCache->get(3);    // 返回 3
	lRUCache->get(4);    // 返回 4

}

void test_148()
{
	vector<int> arr = { 4, 2 ,1, 3 };
	ListNode* head = createList(arr);
	linkedlist.sortList(head);
}

void test_876()
{
	vector<int> arr = { 1, 2 ,3, 4, 5 };
	ListNode* head = createList(arr);
	linkedlist.middleNode(head);
}

