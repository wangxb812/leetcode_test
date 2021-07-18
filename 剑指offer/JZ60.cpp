/*
 * @Author: m1ng
 * @Date: 2021-07-18 01:52:44
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-18 13:28:55
 * @FilePath: \leetcode_test\剑指offer\JZ60.cpp
 * @Description: header
 */
#include<vector>
#include<queue>
using namespace std;
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector <int>>ret;
            if(!pRoot)  return ret;
            queue<TreeNode *>q;
            q.push(pRoot);int level = 0;
            while(!q.empty()){
                int sz = q.size();
                vector<int>ans;
                while(sz--)
                {
                    TreeNode *node=q.front();
                    q.pop();
                    ans.push_back(node->val);
                    if(node->left)  q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                ret.push_back(ans);
            }
            return ret;
        }
    
};