//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
class Solution {
public:
	/*
	使用队列
	初始化：一个队列queue<TreeNode*> q， 将root节点入队列q
	如果队列不空，做如下操作：
	弹出队列头，保存为node，将node的左右非空孩子加入队列
	做2,3步骤，知道队列为空
	*/
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if(!root)	return res;
		queue<TreeNode *> q;
		q.push(root);
		while(!q.empty()){
			TreeNode* pNode = q.front();
			q.pop();
			res.push_back(pNode->val);
			if(pNode->left)	q.push(pNode->left);
			if(pNode->right)	q.push(pNode->right);
		}
		return res;
    }
};