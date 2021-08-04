/*
 * @Author: m1ng
 * @Date: 2021-08-01 02:07:31
 * @LastEditors: m1ng
 * @LastEditTime: 2021-08-05 00:58:34
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
        }
        i++;
    }
    return pre;
}

list_node * reverse_list(list_node * head, int L, int R)
{
    //////在下面完成代码
    if(head == nullptr || R < L || L < 1)
        return head;
    list_node * p = head;
    list_node * pre = nullptr;//
    list_node * pos = nullptr;
    int len = 0;
    while(p){
        len++;
        pre = (len == L -1 ? p : pre);
        pos = (len == R + 1 ? p : pos);
        p = p->next;
    }
    if(R > len)
        return head;
    list_node *node1 = (pre == nullptr ? head : pre->next);
    list_node *node2 = node1->next;
    node1->next = pos;
    list_node *next = nullptr;
    while(node2 != pos){
        next = node2->next;
        node2->next = node1;
        node1 = node2;
        node2 = next;
    }
    if(pre != nullptr){
        pre->next = node1;
        return head;
    }
    return node1;
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