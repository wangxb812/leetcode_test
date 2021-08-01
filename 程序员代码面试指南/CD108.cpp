/*
 * @Author: m1ng
 * @Date: 2021-08-01 02:07:31
 * @LastEditors: m1ng
 * @LastEditTime: 2021-08-02 00:44:21
 * @FilePath: \leetcode_test\程序员代码面试指南\CD108.cpp
 * @Description: header
 */
# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(void)
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


list_node * reverse_list(list_node * head, int L, int R)
{
    list_node *pre = nullptr;
    list_node *next = nullptr;
    int i=0;
    while(head!=nullptr)
    {
        if(i>=L-1 && i<=R-1)
        {
            next=head->next;
            head->next =pre;
            pre=head;
            head=next;
        }
        else{
            next = head->next;
            pre = head;
            head = next;
            pre = head;
        }
        i++;
    }
    return pre;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}


int main ()
{
    int L, R;
    list_node * head = input_list();
    scanf("%d%d", &L, &R);
    list_node * new_head = reverse_list(head, L, R);
    print_list(new_head);
    return 0;
}