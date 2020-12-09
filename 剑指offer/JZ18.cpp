//操作给定的二叉树，将其变换为源二叉树的镜像。
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
    //递归实现
    void Mirror(TreeNode *pRoot) {
        if((pRoot == nullptr )|| (pRoot->left == nullptr && pRoot->right ))
            return;
        TreeNode * temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        if(pRoot->left){
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);
        }
    }
    //循环实现
    void Mirror_2(TreeNode *pRoot){
        if((pRoot == nullptr )|| (pRoot->left == nullptr && pRoot->right ))
            return;
       queue<TreeNode*> pq;
        pq.push(pRoot);
        while (!pq.empty()) {
            int sz = pq.size();
            while (sz--) {
                TreeNode *node = pq.front();
                pq.pop();
 
                if (node->left) pq.push(node->left);
                if (node->right) pq.push(node->right);
                // our tasks
                TreeNode *cur = node->left; // 需要保存一下
                node->left = node->right;
                node->right = cur;
 
 
            } // end inner while
 
        } // end outer while
    }
};