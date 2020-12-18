//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
//在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
//平衡二叉树（Balanced Binary Tree），具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
#include<map>
using namespace std;
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot ==nullptr) return true;
        int left = Treedepth(pRoot->left);
        int right = Treedepth(pRoot->right);
        int diff = left-right;
        if(diff>1 || diff<-1)   return false;
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth =0;
        return IsBalanced(pRoot,&depth);
    }
    bool IsBalanced(TreeNode* pRoot,int *depth) {
        if(pRoot==nullptr) {
            *depth =0;
            return true;
        }
        int left,right;
        if(IsBalanced(pRoot->left,&left)&&(pRoot->right,&right)){
            int diff = left -right;
            if(diff <=1 &&diff>=-1){
                *depth=1+(left>right?left:right);
                return true;
            }
        }
        return false;
    }
    //使用map   hash<TreeNode*, int>来存以每个结点的树的高度。
    map<TreeNode*, int> hs;
    int depth(TreeNode *root) {
        if (!root) return 0;
        if (hs.find(root) != hs.end()) return hs[root];
        int ldep = depth(root->left);
        int rdep = depth(root->right);
        return hs[root] = max(ldep, rdep) + 1;
    }
    bool judge(TreeNode *root) {
        if (!root) return true;
        return abs(hs[root->left] - hs[root->right]) <= 1 && 
        judge(root->left) && judge(root->right);
    }
    bool IsBalanced_Solution(TreeNode* root) {
        depth(root);
        return judge(root);
    }
};