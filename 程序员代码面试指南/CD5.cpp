/*
 * @Author: m1ng
 * @Date: 2021-07-21 00:55:00
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-22 00:38:02
 * @FilePath: \leetcode_test\程序员代码面试指南\CD5.cpp
 * @Description: 实现一个特殊功能的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。
 */
#include<stack>
#include<string>
#include<iostream>
using namespace std;
class solution
{
private:
    stack<int> stacknum;
    stack<int>  stackmin;
public:
    void push(int num){
        if(stackmin.empty())    stackmin.push(num);
        else if(stackmin.top()>=num)    stackmin.push(num);
        stacknum.push(num);
    }
    void pop(){
        if(stacknum.empty())    return;
        int val=stacknum.top();
        stacknum.pop();
        if(val == getmin()) stackmin.pop();
        return ;
    }
    int getmin()
    {
        if(stackmin.empty())    return;
        return stackmin.top();
    }
};
//上述为第一种方法，只压入一次；第二种方法，重复压入最小值，两个栈大小一致。
static solution obj;
int main()
{
    int n,value;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        if(s=="push")
        {
            cin>>value;
            obj.push(value);
        }
        else if(s=="getMin")
        {
            cout<<obj.getmin()<<endl;
        }
        else
        {
            obj.pop();
        }
    }
    return 0;
}