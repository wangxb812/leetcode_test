//输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为 O(n).
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        if(len == 0) return 0;
        int sum = 0,res =0x80000000;
        for(int i=0;i<len;i++){
            if(sum<=0)  sum=array[i];
            else    sum+=array[i];
            if(sum>res) res = sum;
        }
        return res;
    }
    //动态规划
    int FindGreatestSumOfSubArray(vector<int> array){
        int len=array.size();
        if(len == 0)    return 0;
        vector<int> sum;sum[0]=0;
        for(int i=0;i<len;i++)
        {
            if(i=0 || sum[i-1]<=0)  sum[i]=array[i];
            if(i!=0 && sum[i-1]>0)  sum[i]=sum[i-1]+array[i];
        }
        return *max_element(sum.begin(),sum.end());
    }
};