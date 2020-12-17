//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
#include<vector>
using namespace std;
class Solution {
public:
    const int kmod = 1000000007;
    //归并排序.归并排序（升序）的时候遇到左边需要调整到右边去的元素时既可以计算逆序对的个数了，
    int InversePairs(vector<int> data) {
        int res=0;
        vector<int> temp(data.size());
        merge_sort(data,temp,0,data.size()-1,res);
        return res;
    }
    void merge_sort(vector<int> &arr,vector<int> &temp,int l,int r,int &ret){
        if(l>=r)    return;
        int mid=l+((r-1)>>2);
        merge_sort(arr,temp,l,mid,ret);
        merge_sort(arr,temp,mid+1,r,ret);
        merge_(arr,temp,l,mid,r,ret);
    }
    void merge_(vector<int> &arr,vector<int> &tmp, int l, int mid, int r, int &ret){
                int i = l, j = mid + 1, k = 0;
 
        while (i <= mid && j <= r) {
            if (arr[i] > arr[j]) {
                tmp[k++] = arr[j++];
                ret += (mid - i + 1);
                ret %= kmod;
            }
            else {
                tmp[k++] = arr[i++];
            }
        }
 
        while (i <= mid) {
            tmp[k++] = arr[i++];
        }
        while (j <= r) {
            tmp[k++] = arr[j++];
        }
 
        for (k = 0, i = l; i <= r; ++i, ++k) {
            arr[i] = tmp[k];
        }
    }
};