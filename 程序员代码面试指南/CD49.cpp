/*
 * @Author: m1ng
 * @Date: 2021-07-31 01:26:46
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-31 17:34:34
 * @FilePath: \leetcode_test\程序员代码面试指南\CD49.cpp
 * @Description: header
 */
# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

int K;

list_node * input_list(void) //读入链表
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d %d", &n, &K);
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

list_node * remove_last_kth_node(list_node * head, int K)
{
     list_node *node = head;
     int n=0;
     while(node)
     {
         n++;
         node = node ->next;
     }
     node =head;
     int num = n-K+1;
     while(node)
     {
        num--;
        if(num==0)
        {
            list_node *a =node->next;
            node->val = a->val;
            node->next = a->next;
        }
        else{
            cout<<node->val<<" ";
            node=node->next;
        }
     }
return node;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main ()
{
    list_node * head = input_list(); // 链表的头节点
    list_node * rhead = remove_last_kth_node(head, K);
    print_list(rhead);
    return 0;
}