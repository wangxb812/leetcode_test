/*
 * @Author: m1ng
 * @Date: 2021-07-18 01:53:47
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-19 23:54:24
 * @FilePath: \leetcode_test\剑指offer\JZ67.cpp
 * @Description: 给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m<=n），每段绳子的长度记为k[1],...,k[m]。请问k[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
 */
#include<vector>
using namespace std;
class Solution {
public:
    int cutRope(int number) {
        if (number == 2) {
            return 1;
        }
        else if (number == 3) {
            return 2;
        }
 
        vector<int> f(number + 1, -1);
        for (int i = 1; i <= 4; ++i) {
            f[i] = i;
        }
        for (int i = 5; i <= number; ++i) {
            for (int j = 1; j < i; ++j) {
                f[i] = max(f[i], j * f[i - j]);
            }
        }
        return f[number];
    }
};