/*
 * @Author: m1ng
 * @Date: 2021-07-08 23:18:51
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-08 23:55:41
 * @FilePath: \leetcode_test\剑指offer\JZ63.cpp
 * @Description: header
 */
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> stream;
    void Insert(int num) {
        stream.push_back(num);
    }

    double GetMedian() { 
        double res;
        int len=stream.size();
        sort(stream.begin(),stream.end());
        if(len==1)  {res=stream[0];}
        else if(len%2==0){
            res=(stream[len/2]+stream[len/2-1])/2.0;
        }
        else if(len!=1 && len%2==1){
            res=stream[len/2.0];
        }
        return res;
    }
//二叉树解法

};