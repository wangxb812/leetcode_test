//一只青蛙一次可以跳上1级台阶，也可以跳上2级。
//求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
#include<iostream>
using namespace std;
class Solution {
public:
    //可以跳一层也可以跳两层。那么对于n层，有两种分解问题的方式
    //1：跳一层+剩下(n-1)层的总跳法，2:跳两层和（n-2）层总跳法
    int jumpFloor(int number) {
        if(number==0 || number == 1)   return 1;
        return jumpFloor(number-1)+jumpFloor(number-2);
    }
};