#include<iostream>
#include<stack>
# include <bits/stdc++.h>
using namespace std; 
struct list_node{
    int val;
    struct list_node * next;
};
stack<int> st;
list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        st.push(val);
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


list_node * check(list_node * head)
{
    list_node *p=head;
    while(p)
    {
        if(st.top()!=p->val)
        {
            cout<<"false";
            return head;
        }
        st.pop();
        p=p->next;
    }
    cout<<"true";
    return head;
}


int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}