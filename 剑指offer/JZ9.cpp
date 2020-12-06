//一只青蛙一次可以跳上1级台阶，也可以跳上2级...它也可以跳上n级
//求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
#include<iostream>
using namespace std;
class Solution {
public:
    //不能看作是扩展的斐波那契。f[n] = f[n-1] + f[n-2] + ... + f[0]
    int jumpFloorII(int number) {
        if(number==0 || number == 1)   return 1;
        int a=1,b;
        for(int i=2;i<=number;i++) {
            b=a<<1;
            a=b;
        }
        return b;
    }
};