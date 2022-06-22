#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
using namespace std;

class Node1 {
public:
	int val;
	vector<Node1*> children;

	Node1() {}

	Node1(int _val) {
		val = _val;
	}

	Node1(int _val, vector<Node1*> _children) {
		val = _val;
		children = _children;
	}
};
class Node2 {
public:
	int val;
	Node2* left;
	Node2* right;
	Node2* next;

	Node2() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node2(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node2(int _val, Node2* _left, Node2* _right, Node2* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class ReturnData_101 {
public:
	bool isSymmetric;
	//int value;
	ReturnData_101(bool isS) : isSymmetric(isS) {}
};
class ReturnData_100 {
public:
	bool isSameTree;
	ReturnData_100(bool isS) : isSameTree(isS) {}
};
class ReturnData_110 {
public:
	bool isBalanced;
	int height;

	ReturnData_110(bool isB, int h) : isBalanced(isB), height(h) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class BINARYTREE
{
public:
	TreeNode* buildtree(vector<int> array, int index);


	vector<int> preorderTraversal(TreeNode* root);//144
	vector<int> postorderTraversal(TreeNode* root);//145
	vector<int> inorderTraversal(TreeNode* root);//94

	vector<vector<int>> levelOrder(TreeNode* root);//102
	vector<vector<int>> levelOrderBottom(TreeNode* root);//107
	vector<int> rightSideView(TreeNode* root);//199
	vector<double> averageOfLevels(TreeNode* root);//637
	vector<vector<int>> levelOrder(Node1* root);//429
	vector<int> largestValues(TreeNode* root);//515
	Node2* connect(Node2* root);//116/117
	int maxDepth(TreeNode* root);//104
	int minDepth(TreeNode* root);//111
	int maxDepth(Node1* root);//559
	int countNodes(TreeNode* root);//222
	int findBottomLeftValue(TreeNode* root);//513
	bool isCompleteTree(TreeNode* root);//958
	int sumOfLeftLeaves(TreeNode* root);//404
	bool isSymmetric(TreeNode* root);//101
	bool isSameTree(TreeNode* p, TreeNode* q);//100
	bool isBalanced(TreeNode* root);//110
	vector<string> binaryTreePaths(TreeNode* root);//257
	bool hasPathSum(TreeNode* root, int targetSum);//112
	vector<vector<int>> pathSum(TreeNode* root, int targetSum);//113
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);//106
	TreeNode* buildTree(int p, vector<int>& preorder, vector<int>& inorder);//105
	TreeNode* constructMaximumBinaryTree(vector<int>& nums);//654
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);//617

};

extern BINARYTREE binarytree;

void test_144();//��������ǰ�����
void test_145();//�������ĺ������
void test_94();//���������������
void test_589();//N������ǰ�����
void test_590();//N�����ĺ������

void test_102();//�������Ĳ������ | ��ָ Offer 32 - I. ���ϵ��´�ӡ������ | ��ָ Offer 32 - I. ���ϵ��´�ӡ������
void test_107();//�������Ĳ�α���II | ��ָ Offer 32 - III. ���ϵ��´�ӡ������ III
void test_199();//������������ͼ
void test_637();//�������Ĳ�ƽ��ֵ
void test_429();//N�����Ĳ������
void test_515();//��ÿ�������������ֵ
void test_116();//���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
void test_117();//���ÿ���ڵ����һ���Ҳ�ڵ�ָ��II
void test_104();//�������������� | ��ָ Offer 55 - I. �����������
void test_111();//����������С���
void test_559();//n������������
void test_222();//��ȫ�������Ľڵ����
void test_513();//�������½ǵ�ֵ
void test_226();//��ת������ | ��ָ Offer 27. �������ľ���
void test_958();//958. ����������ȫ�Լ���
void test_404();//��Ҷ��֮��

void test_101();// �Գƶ����� | ��ָ Offer 28. �ԳƵĶ�����
void test_100();//��ͬ����
void test_572();//��һ���������� | ��ָ Offer 26. �����ӽṹ
void test_110();//ƽ������� | ��ָ Offer 55 - II. ƽ�������
void test_257();//������������·��
void test_112();//·���ܺ�
void test_113();//·���ܺ�ii | ��ָ Offer 34. �������к�Ϊĳһֵ��·��
void tesr_437();//·���ܺ�iii***********
void test_106();//�����������������й��������
void test_105();//��ǰ��������������й�������� | ��ָ Offer 07. �ؽ�������
void test_654();//��������
void test_617();//�ϲ�������
void test_543();//��������ֱ��

void test_700();//�����������е�����
void test_98();//��֤����������
void test_530();//��������������С���Բ�
void test_501();//�����������е�����
void test_236();//������������������� | ��ָ Offer 68 - II. �������������������
void test_235();//����������������������� | ��ָ Offer 68 - I. �����������������������
void test_701();//�����������еĲ������
void test_450();//ɾ�������������еĽڵ�
void test_669();//�޼�����������
void test_108();//����������ת��Ϊ����������
void test_538();//�Ѷ���������ת��Ϊ�ۼ���
void test_426();//��ָ Offer 36. ������������˫������
void test_offer54();//��ָ Offer 54. �����������ĵ�k��ڵ�
void test_offer33();//��ָ Offer 33. �����������ĺ����������


