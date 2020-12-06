//输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
#include<iostream>
using namespace std;
class Solution {
public:
     int  NumberOf1(int n) {
         int num=0;
         unsigned int flag =1;
         while(flag){
             if(n&flag) num++;
             flag=flag<<1;
         }
         return num;
     }
     //把整数减去1，再和原数做与运算，就会让最右边的1变成0
     int  NumberOf1_2(int n) {
         int count=0;
         while(n){
             count++;
             n=(n-1)&n;
         }
         return count;
     }
};