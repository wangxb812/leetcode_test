//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
//栈 先进后出，队列先进先出
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
    //stack1元素弹出到stack2中，则变成正常顺序
    int pop() {
        if(stack2.size()<=0){
            while(stack1.size()>0){
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        if(stack2.size()==0) return 0;
        int popnum = stack2.top();
        stack2.pop();
        return popnum;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};