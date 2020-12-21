//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int len = array.size();
        vector<int> res;
        if(len==0)  return res;
        int ahead = len-1;
        int behind =0;
        while(behind<ahead){
            int sumTwo = array[behind]+array[ahead];
            if(sumTwo>sum){
                ahead--;
            }
            else if(sumTwo<sum){
                behind++;
            }else{
                res.push_back(array[behind]);
                res.push_back(array[ahead]);
                break;
            }
        }
        return res;
    }
};