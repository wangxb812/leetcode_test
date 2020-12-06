#include<iostream>
using namespace std;
class Solution {
public:
    int Fibonacci(int n) {
        int Fibonum=0,a=0,b=1;
        if(n==0 || n==1){
            return n;
        }
        for(int i=2;i<=n;i++) {
            Fibonum = a + b;
            a = b;
            b = Fibonum;
        }
        return Fibonum;
    }
    //递归问题，考虑性能、栈溢出.常规思路会耗费很大的内存和临时空间
    int Fibonacci_normal(int n){
        if(n<=0)    return 0;
        if(n==1)    return 1;
        return Fibonacci_normal(n-1)+Fibonacci_normal(n-2);
    }
    //时间复杂度O(logn)的解法，需要用到一个生僻的数学公式
};
