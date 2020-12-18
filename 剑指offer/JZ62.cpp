//给定一棵二叉搜索树，请找出其中的第k小的结点。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    //递归
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==nullptr && k==0){
            return nullptr;
        }
        return KthNodeCore(pRoot,k);
    }
    TreeNode* KthNodeCore(TreeNode *pRoot,int &k){
        TreeNode* target =nullptr; 
        if(pRoot->left !=nullptr)
            target = KthNodeCore(pRoot,k);
        if(target == nullptr)
        {
            if(k==1)    target =pRoot;
            k--;
        }
        if(target == nullptr && pRoot->right!=nullptr){
            target = KthNodeCore(pRoot->right,k);
        }
        return target;
    }
    //非递归
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot) return nullptr;
        stack<TreeNode *> res;
        TreeNode* p =pRoot;
        while(!res.empty() || p ){//res是空 and 遍历到空节点
            while(p){
                res.push(p);
                p = p->left;
            }
            TreeNode* node = res.top();
            res.pop();
            if((--k)==0) return node;
            p = node->right;
        }
        return nullptr;
    }
};