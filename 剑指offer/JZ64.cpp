/*
 * @Author: m1ng
 * @Date: 2021-07-10 11:05:11
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-11 01:09:37
 * @FilePath: \leetcode_test\剑指offer\JZ64.cpp
 * @Description: header
 */
#include<vector>
#include<queue>
#include<deque>
using namespace std;
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        int len = num.size();
        for (int i = 0; i + size - 1 < len; ++i) {
            int j = i + size - 1;
            int max_val = num[j];
            for (int k = i; k < j; ++k) {
                max_val = max(max_val, num[k]);
            }
            res.push_back(max_val);
        }
        return res;
    }
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> maxInWindows;
        if(num.size()>=size &&size>=1){
            deque<int>index;
            for(int i=0;i<size;i++){
                while(!index.empty()&& num[i]>=num[index.back()]){
                    index.pop_back();
                }
                index.push_back(i);
            }
            for(int i=size;i<num.size();i++){
                maxInWindows.push_back(num[index.front()]);
                while(!index.empty()&& num[i]>=num[index.back()])
                    index.pop_back();
                if(!index.empty()&& index.front()<=(int)(i-size))
                    index.pop_front();
                index.push_back(i);
            }
            maxInWindows.push_back(num[index.front()]);
        }
        return maxInWindows;
    }
};