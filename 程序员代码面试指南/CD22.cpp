/*
 * @Author: m1ng
 * @Date: 2021-07-22 00:42:29
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-26 00:47:05
 * @FilePath: \leetcode_test\程序员代码面试指南\CD22.cpp
 * @Description: header
 */
#include <iostream>
#include<string>
using namespace std;
int cnt = 0;

void Hanota(int n,string a,string b,string c){
    if(n==1)
    {
        printf("Move %d from %s to %s\n", n, a.c_str(), b.c_str());
        printf("Move %d from %s to %s\n", n, b.c_str(), c.c_str());
    }
    else{
        Hanota(n-1, a, b, c);
        printf("Move %d from %s to %s\n", n, a.c_str(), b.c_str());
        Hanota(n-1, c, b, a);
        printf("Move %d from %s to %s\n", n, b.c_str(), c.c_str());
        Hanota(n-1, a, b, c);
    }
    cnt+=2;
}
int main()
{
    int n;
    cin>>n;
    Hanota(n, "left", "mid", "right");
    printf("It will move %d steps.\n", cnt);
    return 0;
}