//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法
#include<iostream>
using namespace std;
class Solution {
public:
    // f(n) = f(n-1) + f(n-2)， (n > 2) 典型的斐波那契
    int rectCover(int number) {
        if(number <= 0) return 0;
        if(number == 1 || number ==2)   return number;
        return rectCover(number-1)+rectCover(number-2);
    }
    //时间复杂度：O（n）
    int rectCover(int n) {
        if (n==0 || n==1 || n==2) return n;
        int a = 1, b = 2, c;
        for (int i=3; i<=n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};