//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
#include<vector>
#include<set>
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
};