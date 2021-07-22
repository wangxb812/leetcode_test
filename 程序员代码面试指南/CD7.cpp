/*
 * @Author: m1ng
 * @Date: 2021-07-22 00:39:46
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-23 01:33:09
 * @FilePath: \leetcode_test\程序员代码面试指南\CD7.cpp
 * @Description: header
 */
#include<stack>
#include<iostream>
using namespace std;
class Solution
{
public:
//返回栈底元素
    int getEndRemove(stack<int> st){
        int res=st.top();
        st.pop();
        if(st.empty())  return res;
        else{
            int last = getEndRemove(st);
            st.push(res);
            return last;
        }
    }
    void reverseStack(stack<int> st)
    {
        if(st.empty())  return;
        int i = getEndRemove(st);
        reverseStack(st);
        st.push(i);
    }
    Solution(){
        ;
    }
};
static Solution obj;
int main(){
    int n=0;
    int s=0;
    stack<int> st;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        st.push(s);
    }
    obj.reverseStack(st);
    for(int i=0;i<st.size();i++)
    {
        printf("%n",st.top());
        st.pop();
    }
    return 0;
}