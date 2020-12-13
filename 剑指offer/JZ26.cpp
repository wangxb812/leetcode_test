//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
    TreeNode* pre = nullptr;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree) return pRootOfTree;
        TreeNode* p = pRootOfTree;
        // 记录表头位置
        while ( p && p->left) p = p->left;
 
        inorder(pRootOfTree);
        return p;
    }
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        /******中序部分*****/
        // 使用当前节点的left去指向上一个访问的节点，不能用right，因为它还未访问
        root->left = pre;
        if (pre)
            // 同理，之前访问过的节点的left已经被用了，因此用right
            pre->right = root;
        pre = root;
        inorder(root->right);
    }
};