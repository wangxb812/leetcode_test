/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if (!pRoot1 || !pRoot2) return false;
		return dfs(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
	bool dfs(TreeNode *r1, TreeNode *r2) {
		if (!r2) return true;
		if (!r1) return false;
		return r1->val==r2->val && dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
	}
};