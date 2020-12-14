//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
#include<vector>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    //排序。时间复杂度：O(nlogn)。空间复杂度：O(1)
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(),input.end());
        vector<int> res;
        if(k==0 || k>input.size())  return res;
        return vector<int>({input.begin(),input.begin()+k});
    }
    //快速排序
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>res;
        int n = input.size();
        if(n==0 || k>n)   return res;
        int start =0,end = n-1;
        while(start<n){
            int p=Partition(input,start,n);
            if(p+1==k){
                return vector<int>({input.begin(),input.begin()+k});
            }
            if(p+1<k){
                start = p+1;
            }
            else{
                n=p;
            }
        }
        return res;
    }
    int Partition(vector<int> &input,int l, int r){
        int pivot = input[r-1];
        int i=l;
        for(int j=l;j<r-1;j++){
            if(input[j]<pivot){
                swap(input[i],input[j]);
                i++;
            }
        }
        swap(input[i],input[r-1]);
        return l;
    }
    //堆排序时间复杂度：O(nlongk), 插入容量为k的大根堆时间复杂度为O(longk), 一共遍历n个元素.空间复杂度：O(k)
    //建立一个容量为k的大根堆的优先队列。遍历一遍元素，如果队列大小<k,就直接入队，否则，让当前元素与队顶元素相比，如果队顶元素大，则出队，将当前元素入队
     vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if (k==0 || k > input.size()) return ret;
        priority_queue<int, vector<int>> pq;
        for (const int val : input) {
            if (pq.size() < k) {
                pq.push(val);
            }
            else {
                if (val < pq.top()) {
                    pq.pop();
                    pq.push(val);
                }
 
            }
        }
        while (!pq.empty()) {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};