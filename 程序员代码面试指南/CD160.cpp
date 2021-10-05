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



list_node * relocate(list_node * head)
{
    if(head == NULL || head->next == NULL) return head;
    list_node * pre = head;
    list_node * cur = head;
    list_node * preMid = NULL;
    while(cur && cur->next){
        preMid = pre;
        pre = pre->next;
        cur = cur->next->next;
    }//取到中间值
    preMid->next = NULL; //断开链表
    cur = head;
    list_node * dummy = new list_node();
    list_node * preNode = dummy;
    int flag = 0;
    //按顺序merge两个链表
    while(pre && cur){
        if(flag == 0){
            preNode->next = cur;
            cur = cur->next;
            flag = 1;
        }else{
            preNode->next = pre;
            pre = pre->next;
            flag = 0;
        }
        preNode = preNode->next;
    }
    preNode->next = pre ? pre : cur;
    return dummy->next;
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
    list_node * new_head = relocate(head);
    print_list(new_head);
    return 0;
}