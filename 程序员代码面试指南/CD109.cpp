/*
 * @Author: m1ng
 * @Date: 2021-08-05 01:09:57
 * @LastEditors: m1ng
 * @LastEditTime: 2021-08-05 01:23:42
 * @FilePath: \leetcode_test\程序员代码面试指南\CD109.cpp
 * @Description: header
 */
#include<list>
#include<iostream>
public class Node
{
public:
    int value;
    Node next;
    Node(int data){
        this->value=data;
    }
};
Node josephuKill(Node head,int m)
{
    if(head == null || head->next == head || m<1)
    {
        return 0;
    }
    Node last = head;
    while(head !=last)
    {
        if(++count==m){
            last->next = head->next;
            count=0;
        }
        else{
            last=last->head;
        }
        head=head->next;
    }
    return head;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int ret;
    Node head = nullptr;
    for(int i=1;i<=n;i++)
    {
        
    }
    cout<<ret;
    return 0;
}