/*
 * @Author: m1ng
 * @Date: 2021-08-05 01:09:57
 * @LastEditors: m1ng
 * @LastEditTime: 2021-08-07 22:47:41
 * @FilePath: \leetcode_test\程序员代码面试指南\CD109.cpp
 * @Description: header
 */
#include<list>
#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
};
Node* josephuKill(Node *head,int m)
{
    if(head == nullptr || head->next == head || m<1)
    {
        return 0;
    }
    Node *last = head;
    while (last->next!=head)
    {
        last=last->next;
    }
    
    int count=0;
    while(head!=last)
    {
        if(++count==m){
            last->next = head->next;
            count=0;
        }
        else{
            last=last->next;
        }
        head=head->next;
    }
    return head;
}

int main()
{
    int n,m;
    cin>>n>>m;
    Node* head = nullptr;
    Node* p = nullptr;
    for (int i = 1; i <= n; i++) {
        if (head == nullptr) {
            head = new Node;
            head->val = i;
            head->next = nullptr;
            p = head;
            continue;
        }
        p->next = new Node;
        p = p->next;
        p->val = i;
        p->next = nullptr;
    }
    p->next = head;
    Node* node1 = josephuKill(head, m);
    cout << node1->val << endl;
    system("pause");
    return 0;
}