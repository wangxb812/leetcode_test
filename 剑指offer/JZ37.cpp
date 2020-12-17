//统计一个数字在升序数组中出现的次数。
#include<vector>
using namespace std;
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0)  return 0;
        int res=0;
        for(int i=0;i<data.size();i++){
            if(data[i]==k)  res++;
        }
        return res;
    }
    //二分查找
    int GetNumberOfK(vector<int> data ,int k) {
        int len = data.size();
        if(len==0)  return 0;
        int res=0,start =0,end = len;
        while(start<end)
        {
            int mid = start+(end-start)/2;
            if(data[mid]<k){
                start = mid+1;
            }else{
                end=mid;
            }
        }
        int start_num = start;
        start =0,end = len;
        while(start<end)
        {
            int mid = start+(end-start)/2;
            if(data[mid]<=k){
                start = mid+1;
            }else{
                end=mid;
            }
        }
        int end_num =start;
        return end_num-start_num;
    }
};