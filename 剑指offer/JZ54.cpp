/*
 * @Author: m1ng
 * @Date: 2021-07-15 23:04:25
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-16 00:49:54
 * @FilePath: \leetcode_test\剑指offer\JZ54.cpp
 * @Description: header
 */
#include<string>
using namespace std;
class Solution
{
public:
    string str;
    char hash[256] = {0};
  //Insert one char from stringstream
    void Insert(char ch) {
         str+=ch;
         hash[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for(int i=0;i<str.length();i++)
        {
            char ch=str[i];
            if(hash[ch]==1) return ch;
            else
                return '#';
        }
    }
};