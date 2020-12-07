//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //使用辅助空间，时间复杂度：O(n)。空间复杂度：O(n)
    void reOrderArray_usingTemp(vector<int> &array) {
        int len = array.size();
        vector<int> temp;
        if(len == 0)    return;
        for(int i=0;i<len;i++)
        {
            if(array[i]%2==1){
                temp.push_back(array[i]);
            }
        }
        for(int i=0;i<len;i++)
        {
            if(array[i]%2==0){
                temp.push_back(array[i]);
            }
        }
        copy(temp.begin(),temp.end(),array.begin());
    }
    //插入排序
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        if(len == 0)    return;
        int i=0;
        while(i < len)
        {
            int j=i+1;
            if(array[i]%2 == 0){
                while(array[j]%2==0){
                    if(j == len-1)
                        return;
                    j++;
                }
                int count = j-i;
                int temp=array[i];
                array[i]=array[j];
                while(count<1){
                    array[i+count]=array[i+count-1];
                    count--;
                }
                array[i+1]=temp;
            }
            i++;
        }
    }
    //可以思考从数组最后位置开始交换的方式
};