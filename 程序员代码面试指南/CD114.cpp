# include <bits/stdc++.h>
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


list_node* revered_list(list_node* head){
    if(head == NULL || head->next == NULL) return head;
    else{
        list_node* temp = head->next;
        head->next = NULL;
        list_node* new_head = revered_list(temp);
        temp->next = head;
        return new_head;
    }
}

list_node * add_list(list_node * head1, list_node * head2, int n, int m)
{
    //////在下面完成代码
    head1 = revered_list(head1);
    head2 = revered_list(head2);
    int cur = 0;
    int flag = 0;
    int num1, num2, new_num;
    list_node* ans = new list_node();
    ans->val = 0;
    ans->next = NULL;
    list_node* cur_node = ans;
    while(cur < n || cur < m){
        if(head1){
            num1 = head1->val;
            head1 = head1->next;
        }
        else 
            num1 = 0;
        if(head2){
            num2 = head2->val;
            head2 = head2->next;
        }
        else 
            num2 = 0;
        new_num = num1 + num2 + flag;
        if(new_num >= 10) flag = 1;
        else flag = 0;
        new_num = new_num % 10;
        list_node* temp = new list_node();
        temp->val = new_num;
        temp->next = NULL;
        cur_node->next = temp;
        cur_node = cur_node->next;
        cur++;
    }
    if(flag){
        list_node* temp = new list_node();
        temp->val = 1;
        temp->next = NULL;
        cur_node->next = temp;
    }
    ans = revered_list(ans->next);
    return ans;
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
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2,n,m);
    print_list(new_head);
    return 0;
}