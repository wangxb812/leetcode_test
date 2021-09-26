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

list_node * getSmallestPreNode(list_node *head)
{
    list_node * smallPre = nullptr;
    list_node * small = head;
    list_node * pre =head;
    list_node *cur = head->next;
    while(cur !=nullptr)
    {
        if(cur->val<small->val)
        {
            smallPre = pre;
            small = cur;
        }
        pre = cur;
        cur = cur->next;
    }
    return smallPre;
}


list_node * selection_sort(list_node * head)
{
    list_node *tail = nullptr;
    list_node *cur = head;
    list_node *smallPre = nullptr;
    list_node *small = nullptr;
    while(cur !=nullptr)
    {
        small = cur;
        smallPre = getSmallestPreNode(cur);
        if(smallPre!=nullptr)
        {
            small = smallPre->next;
            smallPre->next= small->next;
        }
        cur =cur ==small?cur->next:cur;
        if(tail == nullptr)
        {
            head = small;
        }
        else 
        {
            tail->next = small;
        }
        tail = small;
    }
    return head;


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
    list_node * head = input_list();
    list_node * new_head = selection_sort(head);
    print_list(new_head);
    return 0;
}