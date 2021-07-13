/*
 * @Author: m1ng
 * @Date: 2021-07-14 00:04:01
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-14 00:27:30
 * @FilePath: \leetcode_test\剑指offer\JZ49.cpp
 * @Description: header
 */
#include<string>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        if(str.length()==0 )    return 0;
        int ret =0 ;bool IsZero = true;
        for(int i=0;i<str.length();i++){
            if(str[i]=='+'&&i==0)
            {
                continue;
            }
            else if(str[i]=='-'&&i==0){
                IsZero=false;continue;
            }
            else{
                if(str[i]-'0'>=0 && str[i]-'9'<=0){
                    ret = ret*10 + str[i]-'0';
                }
                else{
                    return 0;
                }
            }
        }
        return IsZero ? ret: -ret;
    }
};