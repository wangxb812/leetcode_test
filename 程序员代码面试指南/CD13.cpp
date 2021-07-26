/*
 * @Author: m1ng
 * @Date: 2021-07-22 00:40:55
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-25 02:03:33
 * @FilePath: \leetcode_test\程序员代码面试指南\CD13.cpp
 * @Description: header
 */
#include<stack>
using namespace std;
void sortStackByStack(stack<int> st){
    stack<int>temp;
    while(!st.empty()){
        int cur= st.top();
        st.pop();
        while(!temp.empty() && temp.top()>cur)
        {
            st.push(temp.top());
            temp.pop();
        }
        temp.push(cur);
    }
    while(!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}