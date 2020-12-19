//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
#include<vector>
using namespace std;
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len = data.size();
        if(len <2)  return;
        int res=0;
        for(int i=0;i<len;i++){
            res^=data[i];
        }
        int index = FindFirstBitIs1(res);
        *num1=*num2=0;
        for(int i=0;i<len;i++)
        {
            if(IsBit1(data[i],index))   *num1^=data[i];
            else
            {
                *num2^=data[i];
            }
            
        }
    }
    int FindFirstBitIs1(int num){
        int index =0;
        while((num&1)==0 &&(index<8*sizeof(int))){
            num=num>>1;
            index++;
        }
        return index;
    }
    bool IsBit1(int num,int index){
        num=num>>index;
        return num&1;
    }
};   