/*
 * @Author: m1ng
 * @Date: 2021-07-31 01:08:11
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-31 01:25:56
 * @FilePath: \leetcode_test\程序员代码面试指南\CD48.cpp
 * @Description: header
 */
# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

list_node * input_list(void) //读入链表
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

void sol(list_node * a, list_node * b)
{
    list_node *a_head=a;
    list_node *b_head=b;
    while(a_head && b_head)
    {
        if(a_head->val == b_head->val)
        {
            cout<<a_head->val<<" ";
            a_head=a_head->next;
            b_head=b_head->next;
        }
        else if(a_head->val>b_head->val)
        {
            b_head=b_head->next;
            if(b_head==nullptr) return;
        }
        else{
            a_head=a_head->next;
            if(a_head==nullptr) return;
        }
    }
}

int main ()
{
    list_node * a_head = input_list(); // A 链表的头节点
    list_node * b_head = input_list(); // B 链表的头节点
    sol(a_head, b_head);
    return 0;
}