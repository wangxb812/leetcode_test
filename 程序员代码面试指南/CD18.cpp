/*
 * @Author: m1ng
 * @Date: 2021-07-30 00:02:07
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-30 00:41:36
 * @FilePath: \leetcode_test\程序员代码面试指南\CD18.cpp
 * @Description: header
 */
#include<queue>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,num;
    cin>>n>>num;
    vector<int> arr(num);
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
}
int getSonNum(vector<int> arr,int n)
{
    int res;
    if(arr.size()==0)   return 0;
    vector<vector<int>> sonArray;
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=i;j<arr.sise();j++)
        {
            sonArray[i].push_back(arr[j]);
        }
    }

}