//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
//前序：根左右；中序：左根右
    if(pre.size()==0||vin.size()==0)
        return NULL;
    vector<int> pre_left, pre_right, vin_left, vin_right;
    TreeNode* resTree = new TreeNode(pre[0]);
    int n = 0;
    //返回根节点在vin中的下标，也可以用vector中的find找
    for(int i=0;i<vin.size();i++)
    {
        if(vin[i]==pre[0]){
            n=i;break;
        }
    }
    //leftTree
    for(int i=0;i<n;i++)
    {
        vin_left.push_back(vin[i]);
        pre_left.push_back(pre[i+1]);
    }
    //rightTree
    for(int i=n+1;i<vin.size();i++)
    {
        vin_right.push_back(vin[i]);
        pre_left.push_back(pre[i]);
    }
    //递归
    resTree->left = reConstructBinaryTree(pre_left,vin_left);
    resTree->right = reConstructBinaryTree(pre_right,vin_right);
    return resTree;
    }
};