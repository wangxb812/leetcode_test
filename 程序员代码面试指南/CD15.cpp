/*
 * @Author: m1ng
 * @Date: 2021-07-28 00:19:22
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-28 00:37:40
 * @FilePath: \leetcode_test\程序员代码面试指南\CD15.cpp
 * @Description: header
 */
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
class Solution
{
public:
    vector<int> arr;
    int w;
    vector<int> getMaxWindow()
    {
        vector<int> ret;
        queue<int(w)> q;
        if(arr.size()<w)
        {
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]>q.top())
                    q.push(arr[i]);
            }
            ret.push_back(q.top());
        }
        else{
            for(int i=0;i<n-w;i++)
            {
                for(int j=i;j<w+i;j++)
                {
                    if(arr[j]>q.top())
                        q.push(arr[i]);
                }
                ret.push_back(q.top());
            }
        }
        return ret;
    }
};
const Solution sol;
int main()
{
    int n,w;
    cin>>n>>w;
    sol.w=w;
    sol.arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>sol.arr[i];
    }
    vector<int> ret = sol->getMaxWindow();
    for(int i=0;i<ret.size();i++)
    {
        cout<<ret[i]<<" ";
    }
    return 0;
}
