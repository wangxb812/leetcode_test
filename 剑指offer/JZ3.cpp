#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) { }
 };
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
class Solution {
public:
    //顺序存入后再进行vector翻转
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res ;
        if(head==nullptr){
            return res;
        }
        while(head!=NULL){
            res.push_back(head->val);
            head = head->next;
        }
        //std::reverse(res.begin(),res.end());
        //翻转数组
        return res;
    }
    //也可以用stack栈的形式来实现先入后出
    void printListFromTailToHead2(ListNode* head){
        stack<int> res;
        if(head == nullptr){
            return;
        }
        while(head!=NULL)
        {
            res.push(head->val);
            head=head->next;
        }
        while(!res.empty()){
            res.pop();
        }
    }
    //此处还可以使用栈进行递归函数的完成
};