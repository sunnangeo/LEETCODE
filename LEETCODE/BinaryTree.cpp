#include "BinaryTree.h"
BINARYTREE binarytree;
TreeNode * BINARYTREE::buildtree(vector<int> array, int index)
{
	TreeNode* root = nullptr;

	if (index < array.size() && array[index] != NULL)
	{
		root = new TreeNode(array[index]);
		root->left = buildtree(array, 2 * index + 1);
		root->right = buildtree(array, 2 * index + 2);
	}
	return root;
}
vector<int> BINARYTREE::preorderTraversal(TreeNode * root)
{
	vector<int> result;
 	if (root == nullptr) return result;

	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		result.push_back(st.top()->val);
		st.pop();
		if (node->right) st.push(node->right);
		if (node->left) st.push(node->left);
	}
	return result;
}

vector<int> BINARYTREE::postorderTraversal(TreeNode * root)
{
	vector<int> result;
	if (root == nullptr) return result;

	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		result.push_back(st.top()->val);
		st.pop();
		
		if (node->left) st.push(node->left);
		if (node->right) st.push(node->right);
	}
	reverse(result.begin(), result.end());
	return result;
}

vector<int> BINARYTREE::inorderTraversal(TreeNode * root)
{
	vector<int> result;
	if (root == nullptr) return result;
	stack<TreeNode *> st;
	while (!st.empty() || root != nullptr) {
		if (root != nullptr) {
			st.push(root);
			root = root->left;
		} else {
			root = st.top();
			st.pop();
			result.push_back(root->val);
			root = root->right;
		}
	}
	return result;
}

vector<vector<int>> BINARYTREE::levelOrder(TreeNode * root)
{
	queue<TreeNode *> que;
	if (root != nullptr) que.push(root);
	vector<vector<int>> result;

	while (!que.empty()) {
		int size = que.size();
		vector<int> vec;
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			vec.push_back(node->val);
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		result.push_back(vec);
	}
	return result;
}

vector<vector<int>> BINARYTREE::levelOrderBottom(TreeNode * root)
{
	queue<TreeNode*> que;
	vector<vector<int>> result;
	if (root == NULL) return result;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec;
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			vec.push_back(node->val);
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		result.push_back(vec);
	}
	reverse(result.begin(), result.end());
	return result;
}

vector<int> BINARYTREE::rightSideView(TreeNode * root)
{
	queue<TreeNode*> que;
	vector<int> result;
	if (root == NULL) return result;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();

		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (i == size - 1) {
				result.push_back(node->val);
			}
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return result;
}

vector<double> BINARYTREE::averageOfLevels(TreeNode * root)
{
	vector<double> result;
	queue<TreeNode*> que;
	if (root == NULL) return result;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		double sum = 0;
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			sum += node->val;
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}

		result.push_back(sum / size);
	}
	return result;
}

vector<vector<int>> BINARYTREE::levelOrder(Node1 * root)
{
	vector<vector<int>> result;
	if (root == nullptr) return result;
	queue<Node1*> que;
	que.push(root);
	while (!que.empty()) {
		vector<int> vec;
		int size = que.size();
		for (int i = 0; i < size; ++i) {
			Node1* node = que.front();
			que.pop();
			vec.push_back(node->val);
			for (int j = 0; j < node->children.size(); ++j) {
				if (node->children[j]) que.push(node->children[j]);
			}
		}
		result.push_back(vec);


	}
	return result;
}

vector<int> BINARYTREE::largestValues(TreeNode * root)
{
	queue<TreeNode*> que;
	vector<int> result;
	if (root == NULL) return result;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		int max = INT_MIN;
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			max = node->val > max ? node->val : max;
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		result.push_back(max);
	}
	return result;
}

Node2 * BINARYTREE::connect(Node2 * root)
{
	if (root == NULL) return NULL;
	queue<Node2*> que;
	que.push(root);
	while (!que.empty()) {
		Node2* pre = nullptr;
		//Node* cur;
		int size = que.size();
		for (int i = 0; i < size; i++) {
			Node2* node = que.front();
			que.pop();
			if (i == 0) pre = node;
			else {
				pre->next = node;
				pre = pre->next;
			}

			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return root;
}

int BINARYTREE::maxDepth(TreeNode * root)
{
	queue<TreeNode*> que;
	int result = 0;
	if (root != NULL) que.push(root);
	while (!que.empty()) {
		int size = que.size();
		result++;
		for (int i = 0; i < size; ++i) {
			TreeNode* node = que.front();
			que.pop();
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}

	return result;
}

int BINARYTREE::minDepth(TreeNode * root)
{
	queue<TreeNode*> que;
	int depth = 0;
	if (root == NULL) return depth;
	que.push(root);
	while (!que.empty()) {
		depth++;
		int size = que.size();
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
			if (node->left == NULL && node->right == NULL) {
				return depth;
			}
		}
	}
	return depth;
}

int BINARYTREE::maxDepth(Node1 * root)
{
	queue<Node1*> que;
	int depth = 0;
	if (root == NULL) return depth;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		depth++;
		for (int i = 0; i < size; i++) {
			Node1* node = que.front();
			que.pop();
			for (int j = 0; j < node->children.size(); j++) {
				if (node->children[j]) que.push(node->children[j]);
			}
		}
	}
	return depth;
}

int BINARYTREE::countNodes(TreeNode * root)
{
	queue<TreeNode*> que;
	int count = 0;
	if (root == NULL) return count;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			count++;
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return count;
}

int BINARYTREE::findBottomLeftValue(TreeNode * root)
{
	queue<TreeNode*> que;
	int result = 0;
	if (root != NULL) que.push(root);
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (i == 0) result = node->val;
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return result;
}

bool BINARYTREE::isCompleteTree(TreeNode * root)
{
	if (root == nullptr) return true;
	queue<TreeNode*> que;
	que.push(root);
	bool leaf = false;
	while (!que.empty()) {	
		TreeNode* node = que.front();
		que.pop();

		if ((node->left == nullptr && node->right != nullptr)
			||
			(leaf && (node->left != nullptr || node->right != nullptr))) return false;





		if (node->left) que.push(node->left);
		if (node->right) que.push(node->right);
		if (node->left == nullptr || node->right == nullptr) leaf = true;
	}
	return true;
}

ReturnData_101* dfs_101(TreeNode* left, TreeNode* right) {
	if (left == nullptr && right == nullptr) return new ReturnData_101(true);
	if (left == nullptr && right != nullptr) return new ReturnData_101(false);
	if (left != nullptr && right == nullptr) return new ReturnData_101(false);

	ReturnData_101* In = dfs_101(left->left, right->right);
	ReturnData_101* Out = dfs_101(left->right, right->left);

	if (In->isSymmetric == false || Out->isSymmetric == false || left->val != right->val)
		return new ReturnData_101(false);

	return new ReturnData_101(true);
}

bool BINARYTREE::isSymmetric(TreeNode * root)
{
	return dfs_101(root->left, root->right)->isSymmetric;
}
ReturnData_100* dfs_100(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr) return new ReturnData_100(true);
	if (p == nullptr && q != nullptr) return new ReturnData_100(false);
	if (p != nullptr && q == nullptr) return new ReturnData_100(false);

	ReturnData_100* left = dfs_100(p->left, q->left);
	ReturnData_100* right = dfs_100(p->right, q->right);

	if (left->isSameTree == false || right->isSameTree == false || p->val != q->val)
		return new ReturnData_100(false);

	return new ReturnData_100(true);
}
bool BINARYTREE::isSameTree(TreeNode * p, TreeNode * q)
{
	return dfs_100(p, q)->isSameTree;
}


ReturnData_110* dfs_110(TreeNode* node) {
	if (node == nullptr) return new ReturnData_110(true, 0);

	ReturnData_110* leftData = dfs_110(node->left);
	ReturnData_110* rightData = dfs_110(node->right);

	if (leftData->isBalanced == false || rightData->isBalanced == false || abs(leftData->height - rightData->height) > 1) return new ReturnData_110(false, 0);;

	int height = max(leftData->height, rightData->height) + 1;


	return new ReturnData_110(true, height);
}
bool BINARYTREE::isBalanced(TreeNode * root)
{
	return dfs_110(root)->isBalanced;
}
void traverse_257(TreeNode* root, vector<string>& result, vector<int>& path) {
	path.push_back(root->val);
	if (root->left == nullptr && root->right == nullptr) {
		string path_s = "";
		for (int i = 0; i < path.size(); ++i) {
			path_s += to_string(path[i]);
			path_s += "->";
		}
		path_s.resize(path_s.size() - 2);
		result.push_back(path_s);
	}

	if (root->left) {
		traverse_257(root->left, result, path);
		path.pop_back();
	}
	if (root->right) {
		traverse_257(root->right, result, path);
		path.pop_back();
	}
}
vector<string> BINARYTREE::binaryTreePaths(TreeNode * root)
{
	vector<string> result;
	vector<int> path;
	traverse_257(root, result, path);
	return result;
}
bool traverse_112(TreeNode* root, int sum) {
	if (root->left == nullptr && root->right == nullptr && sum == 0) return true;
	if (root->left == nullptr && root->right == nullptr) return false;

	if (root->left) {
		sum -= root->left->val;
		if (traverse_112(root->left, sum)) return true;
		sum += root->left->val;
	}
	if (root->right) {
		sum -= root->right->val;
		if (traverse_112(root->right, sum)) return true;
		sum += root->right->val;
	}
	return false;
}
bool BINARYTREE::hasPathSum(TreeNode * root, int targetSum)
{
	if (root == nullptr) return false;
	return traverse_112(root, targetSum - root->val);
}
void traversal_113(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int targetSum) {
	path.push_back(root->val);
	if (root->left == NULL && root->right == NULL) {
		int sum = 0;
		for (int i = 0; i < path.size(); i++) {
			sum = sum + path[i];
		}
		if (sum == targetSum) {
			result.push_back(path);
		}
	}

	if (root->left) {
		traversal_113(root->left, result, path, targetSum);
		path.pop_back();
	}
	if (root->right) {
		traversal_113(root->right, result, path, targetSum);
		path.pop_back();
	}
}
vector<vector<int>> BINARYTREE::pathSum(TreeNode * root, int targetSum)
{
	vector<vector<int>> result;
	vector<int> path;
	if (root == NULL) return result;
	traversal_113(root, result, path, targetSum);
	return result;
}

TreeNode * BINARYTREE::buildTree(vector<int>& inorder, vector<int>& postorder)
{
	if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
	int postValue = postorder[postorder.size() - 1];
	TreeNode* node = new TreeNode(postValue);
	if (postorder.size() == 1) return node;

	int splitIn = 0;
	for (int i = 0; i < inorder.size(); ++i) {
		splitIn = inorder[i] == postValue ? i : splitIn;
	}

	vector<int> leftInorder(inorder.begin(), inorder.begin() + splitIn);
	vector<int> rightInorder(inorder.begin() + splitIn + 1, inorder.end());

	postorder.resize(postorder.size() - 1);

	vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftInorder.size());
	vector<int> rightpostorder(postorder.begin() + leftInorder.size(), postorder.end());

	node->left = buildTree(leftInorder, leftpostorder);
	node->right = buildTree(rightInorder, rightpostorder);
	return node;
}

TreeNode * BINARYTREE::buildTree(int p, vector<int>& preorder, vector<int>& inorder)
{
	if (inorder.size() == 0 || preorder.size() == 0) return nullptr;
	int preValue = preorder[0];
	TreeNode* node = new TreeNode(preValue);

	if (preorder.size() == 1) return node;

	int splitIn = 0;
	for (int i = 0; i < inorder.size(); ++i) {
		splitIn = inorder[i] == preValue ? i : splitIn;
	}

	vector<int> leftInorder(inorder.begin(), inorder.begin() + splitIn);
	vector<int> rightInorder(inorder.begin() + splitIn + 1, inorder.end());

	vector<int> newPre(preorder.begin() + 1, preorder.end());

	vector<int> leftpreorder(newPre.begin(), newPre.begin() + leftInorder.size());
	vector<int> rightpreorder(newPre.begin() + leftInorder.size(), newPre.end());

	node->left = buildTree(leftpreorder, leftInorder);
	node->right = buildTree(rightpreorder, rightInorder);
	return node;
}

TreeNode * BINARYTREE::constructMaximumBinaryTree(vector<int>& nums)
{
	TreeNode* node = new TreeNode(0);
	int maxIndex = 0;
	int maxValue = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > maxValue) {
			maxValue = nums[i];
			maxIndex = i;
		}
	}
	node->val = maxValue;
	if (maxIndex > 0) {
		vector<int> newnums(nums.begin(), nums.begin() + maxIndex);
		node->left = constructMaximumBinaryTree(newnums);
	}
	if (maxIndex < nums.size() - 1) {
		vector<int> newnums(nums.begin() + maxIndex + 1, nums.end());
		node->right = constructMaximumBinaryTree(newnums);
	}
	return node;
}

TreeNode * BINARYTREE::mergeTrees(TreeNode * root1, TreeNode * root2)
{
	if (root1 == NULL) return root2;
	if (root2 == NULL) return root1;
	TreeNode* node = new TreeNode(0);
	node->val = root1->val + root2->val;
	node->left = mergeTrees(root1->left, root2->left);
	node->right = mergeTrees(root1->right, root2->right);

	return node;
}

int BINARYTREE::sumOfLeftLeaves(TreeNode * root)
{
	int result = 0;
	if (root == nullptr) return result;
	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty()) {


		TreeNode* node = que.front();
		que.pop();

		if (node->left) {
			if (node->left->left == nullptr && node->left->right == nullptr) result = result + node->left->val;
			else que.push(node->left);
		}
		if (node->right) que.push(node->right);


	}

	return result;
}

/*			1
		2		3
	4		5
*/      



void test_144()
{
	vector<int> arr = { 1,2,3,4,5 };
	TreeNode* root = binarytree.buildtree(arr,0);

	vector<int> result = binarytree.preorderTraversal(root);
}

void test_145()
{
	vector<int> arr = { 1,2,3,4,5 };
	TreeNode* root = binarytree.buildtree(arr, 0);

	vector<int> result = binarytree.postorderTraversal(root);
}

void test_94()
{
	vector<int> arr = { 1,2,3,4,5 };
	TreeNode* root = binarytree.buildtree(arr, 0);

	vector<int> result = binarytree.inorderTraversal(root);
}

void test_589()
{

}

void test_590()
{
}

void test_102()
{
	vector<int> arr = { 1,2,3,4,5 };
	TreeNode* root = binarytree.buildtree(arr, 0);

	vector<vector<int>> result = binarytree.levelOrder(root);
}

void test_107()
{
}

void test_199()
{
}

void test_637()
{
}

void test_429()
{
}

void test_515()
{
}

void test_116()
{
}

void test_117()
{
}

void test_104()
{
}

void test_111()
{
}

void test_559()
{
}

void test_222()
{
}

void test_513()
{
}

void test_offer33()
{
}

void test_226()
{
}

void test_958()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(5);
	TreeNode* node5 = new TreeNode(7);
	TreeNode* node6 = new TreeNode(8);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node3->left = node5;
	node3->right = node6;

	bool result = binarytree.isCompleteTree(node1);

}

void test_101()
{
}

void test_100()
{
}

void test_572()
{
}

void test_110()
{
}

void test_404()
{
	TreeNode* node1 = new TreeNode(3);
	TreeNode* node2 = new TreeNode(9);
	TreeNode* node3 = new TreeNode(20);
	TreeNode* node4 = new TreeNode(15);
	TreeNode* node5 = new TreeNode(7);

	node1->left = node2;
	node1->right = node3;

	node3->left = node4;
	node3->right = node5;

	int result = binarytree.sumOfLeftLeaves(node1);
}

void test_257()
{
}

void test_112()
{
}

void test_113()
{
}

void tesr_437()
{
}

void test_106()
{
}

void test_105()
{
}

void test_654()
{
}

void test_617()
{
}

void test_543()
{
}
