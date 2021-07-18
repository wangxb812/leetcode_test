/*
 * @Author: m1ng
 * @Date: 2021-07-18 01:52:59
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-18 22:10:40
 * @FilePath: \leetcode_test\剑指offer\JZ61.cpp
 * @Description: 请实现两个函数，分别用来序列化和反序列化二叉树，不对序列化之后的字符串进行约束，但要求能够根据序列化之后的字符串重新构造出一棵与原二叉树相同的树。
 */
#include<string>
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
    char* Serialize(TreeNode *root) {    
        if(!root)   return "#";
        string res=to_string(root->val);
        res.push_back(',');
        char *left = Serialize(root->left);
        char *right = Serialize(root->right);
        char *ret = new char[strlen(left)+strlen(right)+res.size()];
        strcpy(ret,res.c_str());
        strcat(ret,left);
        strcat(ret,right);
 
        return ret;
    }
    TreeNode* Deserialize(char *str) {
        return deseri(str);
    }
    TreeNode* deseri(char *&s) {
    if (*s == '#') {
        ++s;
        return nullptr;
    }
 
    // 构造根节点值
    int num = 0;
    while (*s != ',') {
        num = num * 10 + (*s - '0');
        ++s;
    }
    ++s;
    // 递归构造树
    TreeNode *root = new TreeNode(num);
    root->left = deseri(s);
    root->right = deseri(s);
 
    return root;
    }
};