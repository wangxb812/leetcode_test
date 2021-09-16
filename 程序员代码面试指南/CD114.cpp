# include <bits/stdc++.h>
#include <vector>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(int n)
{
    int val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
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


list_node * add_list(list_node * head1, list_node * head2)
{
    list_node * newhead = new list_node();
    list_node * p=head1;
    int len1=0,len2=0;
    int head1=0,head2=0;
    while(p)
    {
        head1=head1*10+p->val;
        p=p->next;
    }
    p=head2;
    while(p)
    {
        head2=head2*10+p->val;
        p=p->next;
    }
    int res=head1+head2;
    vector<int> ret;
    while(res>=10)
    {
        ret.push_back(res%10);
        res/=10;
    }
    for(int i=0;i<ret.size();i++)
    {
        newhead->val=ret[ret.size()-i-1];
        newhead = newhead->next;
    }
    return newhead;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}
    int n, m;
int main ()
{
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}