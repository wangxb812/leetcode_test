/*
 * @Author: m1ng
 * @Date: 2021-10-03 22:13:28
 * @LastEditors: m1ng
 * @LastEditTime: 2021-10-04 00:33:33
 * @FilePath: \leetcode_test\程序员代码面试指南\CD156.cpp
 * @Description: header
 */
# include <bits/stdc++.h>
#include <queue>
using namespace std;

struct double_list_node{
    int val;
    struct double_list_node * pre, * next;
};

struct BST{
    int val;
    struct BST * lch, * rch;
};

BST * input_BST()
{
    int n, fa, lch, rch;
    scanf("%d", &n);
    BST * root, * new_node;
    map<int, BST *> mp;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &fa, &lch, &rch);
        if (mp.find(fa) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[fa] = new_node;
            new_node->val = fa;
            if (i == 1) root = new_node;
        }
        if (lch && mp.find(lch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[lch] = new_node;
            new_node->val = lch; new_node->lch = new_node->rch = NULL;
        }
        if (rch && mp.find(rch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[rch] = new_node;
            new_node->val = rch; new_node->lch = new_node->rch = NULL;
        }
        mp[fa]->lch = (lch ? mp[lch] : NULL);
        mp[fa]->rch = (rch ? mp[rch] : NULL);
    }
    return root;
}

void inOrderToQueue(BST *root,queue<int> q)
{
    if(root == nullptr)
        return;
    inOrderToQueue(root->lch,q);
    q.push(root->val);
    inOrderToQueue(root->rch,q);
}

double_list_node * convert(BST * root)
{
    queue<int> q;
    inOrderToQueue(root,q);
    double_list_node * ret= nullptr;
    if(root==nullptr)   return nullptr;
    ret->val = q.front();
    ret->pre = nullptr;
    double_list_node *next = nullptr;
    double_list_node *pre = nullptr;
    ret->next = next;
    while(!q.empty())
    {
        next->val = q.front();
        q.pop();
        pre = next;
        next->pre = pre;
        next = next->next;
    }

    return ret;
}

void print_double_list(double_list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    BST * root = input_BST();
    double_list_node * new_double_head = convert(root);
    print_double_list(new_double_head);
    return 0;
}