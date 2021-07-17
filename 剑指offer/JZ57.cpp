/*
 * @Author: m1ng
 * @Date: 2021-07-17 23:28:14
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-18 01:29:46
 * @FilePath: \leetcode_test\剑指offer\JZ57.cpp
 * @Description: 给定一个二叉树其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的next指针。下图为一棵有9个节点的二叉树。树中从父节点指向子节点的指针用实线表示，从子节点指向父节点的用虚线表示
 */
#include <vector>
using namespace std;
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {
        
    }
};
class Solution {
public:
//求出根节点；中序遍历整个树；找到当前节点
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode *root = nullptr;
        TreeLinkNode *temp = pNode;
        while(temp)//next指向父节点
        {
            root=temp;
            temp = temp->next;
        }
        vector<TreeLinkNode *>v;
        pre_order(root,v);
        int len = v.size();
        for(int i=0;i<len;i++){
            if(v[i]==pNode && i!=len-1)
            {
                return v[i+1];
            }
        }
        return nullptr;
    }
    void pre_order(TreeLinkNode* root,vector<TreeLinkNode*> &v){
        if(!root)
        {
            return ;
        }
        pre_order(root->left,v);
        v.push_back(root);
        pre_order(root->right,v);
    }
//更新解法，规律
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(!pNode)  return pNode;
        if(pNode->right){
            pNode=pNode->right;
            while(pNode->left){
                pNode=pNode->left;
            }
            return pNode;
        }
        while (pNode->next)
        {
            TreeLinkNode *root = pNode->next;
            if(root->left == pNode) return root;
            pNode = pNode->next;
        }
        return nullptr;
    }
};