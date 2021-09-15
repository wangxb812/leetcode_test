#include<vector>
#include<iostream>
# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

int pivot;

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d%d", &n, &pivot);
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


list_node * list_partition(list_node * head, int pivot)
{
    //////在下面完成代码
    list_node *p =head;
    vector<int> xiaoyu;
    vector<int> dengyu;
    vector<int> dayu;
    while(p)
    {
        if(p->val==pivot)
        {
            dengyu.push_back(p->val);
        }
        else if(p->val>pivot)
        {
            dayu.push_back(p->val);
        }
        else xiaoyu.push_back(p->val);
        
        p=p->next;
    }
    int len = xiaoyu.size();
    p=head;
    for(int i=0;i<len;i++)
    {
        cout<<xiaoyu[i]<<' ';
    }
    len=dengyu.size();
    for(int i=0;i<len;i++)
    {
        cout<<dengyu[i]<<' ';
    }
    len=dayu.size();
    for(int i=0;i<len;i++)
    {
        cout<<dayu[i]<<' ';
    }
    return head;
}


int main ()
{
    list_node * head = input_list();
    list_partition(head, pivot);
    return 0;
}