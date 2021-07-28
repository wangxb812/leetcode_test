/*
 * @Author: m1ng
 * @Date: 2021-07-28 00:41:21
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-29 00:09:59
 * @FilePath: \leetcode_test\程序员代码面试指南\CD15_pro.cpp
 * @Description: 双端队列
 */
#include <vector>
#include <iostream>
#include <deque>
using namespace std;
void getMaxWindow(vector<int> &nums,vector<int> &res,int w)
{
    if(nums.size()==0 || w<1||nums.size()<w)
    return;
    deque<int> q;
    for(int i=0;i<nums.size();++i)
    {
        while(!q.empty() && nums[i]>nums[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
        if(q.front()==i-w)
        {
            q.pop_front();
        }
        if(i>=w-1)
        {
            res.push_back(nums[q.front()]);
        }
    }
}
int main()
{
    int n,w;
    while(cin>>n>>w)
    {
        vector<int> nums(n);
        for(int i=0i<n;i++)
        {
            cin>>nums[i];
        }
        vector<int> res;
        getMaxWindow(nums,res,w);
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}