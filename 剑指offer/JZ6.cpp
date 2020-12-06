//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
//时间复杂度O(n)
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)   return 0;
        int len = rotateArray.size();
        for(int i=0;i<len-1;i++){
            if(rotateArray[i] < rotateArray[i+1])
            {
                int temp = rotateArray[i];
                rotateArray[i] = rotateArray[i+1];
                rotateArray[i+1]=temp;
            }
        }
        return rotateArray[len-1];
    }
    //二分查找,二分法主要考虑指针的移位，时间复杂度O(logn)
    int minNumberInRotateArray_BinarySearch(vector<int> rotateArray){
        int len = rotateArray.size();
        if(len == 0)    return 0;
        int start = 0,end = len-1,mid = 0;
        while(rotateArray[start]>=rotateArray[end])
        {
            if(end-start==1){
                mid=end;
                break;
            }
            mid = (start+end)/2;
            if(rotateArray[start]<=rotateArray[mid]){
                start = mid;
            }
            else if(rotateArray[mid]<=rotateArray[end]){
                end=mid;
            }
        }
        return rotateArray[mid];
    }
};