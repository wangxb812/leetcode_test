/*
 * @Author: m1ng
 * @Date: 2021-07-15 23:04:25
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-19 00:38:54
 * @FilePath: \leetcode_test\剑指offer\JZ54.cpp
 * @Description: header
 */
#include<queue>
#include<unordered_map>
using namespace std;
class Solution
{
public:
    queue<char> q;
    unordered_map<char, int> mp;
    void Insert(char ch)
    {
         // 如果是第一次出现， 则添加到队列中
         if (mp.find(ch) == mp.end()) {
             q.push(ch);
         }
         // 不管是不是第一次出现，都进行计数
         ++mp[ch];
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while (!q.empty()) {
            char ch = q.front();
            // 拿出头部，如果是第一次出现，则返回
            if (mp[ch] == 1) {
                return ch;
            }
            // 不是第一次出现，则弹出，然后继续判断下一个头部
            else {
                q.pop();
            }
        }
        return '#';
    }
};