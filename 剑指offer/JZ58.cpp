/*
 * @Author: m1ng
 * @Date: 2021-07-18 01:30:15
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-18 01:48:59
 * @FilePath: \leetcode_test\剑指offer\JZ58.cpp
 * @Description: 请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if(!pRoot)  return true;
        return isSame(pRoot,pRoot);
    }
    bool isSame(TreeNode *root1,TreeNode *root2){
        if(!root1 && !root2)    return true;
        if(!root1 || !root2)    return false;
        return root1->val == root2->val && isSame(root1->left,root2->right)&&isSame(root1->right,root2->left);
    }

};