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


list_node * check(list_node * head)
{
    if(head==nullptr || head->next==nullptr){
        cout<<"true";
        return head ;
    }
    list_node *right=head->next;
    list_node* p =head;
    while(p->next !=nullptr && p->next->next!=nullptr)
    {
        right = right->next;
        p=p->next->next;
    }
    stack<int>st;
    while(right!=nullptr)
    {
        st.push(right->val);
        right=right->next;
    }
    while(!st.empty())
    {
        if(head->val!=st.top())
        {
            cout<<"false";
            return head ;
        }
        st.pop();
        head=head->next;
    }
    cout<<"true";
    return head ;
}


int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}