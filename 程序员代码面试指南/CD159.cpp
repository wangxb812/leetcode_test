# include <bits/stdc++.h>
#include <vector>
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


list_node * merge_list(list_node * head1, list_node * head2)
{
    list_node * p = nullptr;
    list_node * phead = p;
    if(head1 == nullptr)    return head2;
    if(head2 == nullptr)    return head1;
    phead = head1->val<head2->val?head1:head2;
    while(head1!=nullptr && head2!=nullptr)
    {
        if(head1->val>head2->val)
        {
            phead->val=head2->val;
            phead->next=head2->next;
            head2 = head2->next;
        }
        else{
            phead->val=head1->val;
            phead->next=head1->next;
            head1 = head1->next;
        }
    }
    return p;
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
    list_node * head1 = input_list();
    list_node * head2 = input_list();
    list_node * new_head = merge_list(head1, head2);
    print_list(new_head);
    return 0;
}