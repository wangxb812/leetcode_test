/*
 * @Author: m1ng
 * @Date: 2021-07-14 00:04:12
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-14 00:43:52
 * @FilePath: \leetcode_test\剑指offer\JZ51.cpp
 * @Description: header
 */
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len=A.size();
        vector<int>ret(len,1);
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(i!=j)    ret[i] *=A[j];
            }
        }
        return ret;
    }
};