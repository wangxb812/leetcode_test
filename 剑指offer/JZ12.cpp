//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//保证base和exponent不同时为0
#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    //需要考虑到输入是0或者是负数的情况
    double Power(double base, int exponent) {
        double res;
        res=pow(base,exponent);
        return res;
    }
    //非递归的快速幂,时间复杂度：O(logn)
    double Power_2(double b, int n) {
        if (n < 0) {
            b = 1 / b;
            n = -n;
        }
        double x = b; // 记录x^0, x^1, x^2 ...
        double ret = 1.0;
        while (n) {
            if (n&1) {
                ret *= x; // 二进制位数是1的，乘进答案。
            }
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};