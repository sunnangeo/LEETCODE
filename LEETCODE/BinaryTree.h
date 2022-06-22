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

void test_144();//二叉树的前序遍历
void test_145();//二叉树的后序遍历
void test_94();//二叉树的中序遍历
void test_589();//N叉树的前序遍历
void test_590();//N叉树的后序遍历

void test_102();//二叉树的层序遍历 | 剑指 Offer 32 - I. 从上到下打印二叉树 | 剑指 Offer 32 - I. 从上到下打印二叉树
void test_107();//二叉树的层次遍历II | 剑指 Offer 32 - III. 从上到下打印二叉树 III
void test_199();//二叉树的右视图
void test_637();//二叉树的层平均值
void test_429();//N叉树的层序遍历
void test_515();//在每个树行中找最大值
void test_116();//填充每个节点的下一个右侧节点指针
void test_117();//填充每个节点的下一个右侧节点指针II
void test_104();//二叉树的最大深度 | 剑指 Offer 55 - I. 二叉树的深度
void test_111();//二叉树的最小深度
void test_559();//n叉树的最大深度
void test_222();//完全二叉树的节点个数
void test_513();//找树左下角的值
void test_226();//翻转二叉树 | 剑指 Offer 27. 二叉树的镜像
void test_958();//958. 二叉树的完全性检验
void test_404();//左叶子之和

void test_101();// 对称二叉树 | 剑指 Offer 28. 对称的二叉树
void test_100();//相同的树
void test_572();//另一个树的子树 | 剑指 Offer 26. 树的子结构
void test_110();//平衡二叉树 | 剑指 Offer 55 - II. 平衡二叉树
void test_257();//二叉树的所有路径
void test_112();//路径总和
void test_113();//路径总和ii | 剑指 Offer 34. 二叉树中和为某一值的路径
void tesr_437();//路径总和iii***********
void test_106();//从中序与后序遍历序列构造二叉树
void test_105();//从前序与中序遍历序列构造二叉树 | 剑指 Offer 07. 重建二叉树
void test_654();//最大二叉树
void test_617();//合并二叉树
void test_543();//二叉树的直径

void test_700();//二叉搜索树中的搜索
void test_98();//验证二叉搜索树
void test_530();//二叉搜索树的最小绝对差
void test_501();//二叉搜索树中的众数
void test_236();//二叉树的最近公共祖先 | 剑指 Offer 68 - II. 二叉树的最近公共祖先
void test_235();//二叉搜索树的最近公共祖先 | 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
void test_701();//二叉搜索树中的插入操作
void test_450();//删除二叉搜索树中的节点
void test_669();//修剪二叉搜索树
void test_108();//将有序数组转换为二叉搜索树
void test_538();//把二叉搜索树转换为累加树
void test_426();//剑指 Offer 36. 二叉搜索树与双向链表
void test_offer54();//剑指 Offer 54. 二叉搜索树的第k大节点
void test_offer33();//剑指 Offer 33. 二叉搜索树的后序遍历序列


