//一小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ret;
        int tmp = 0;
        for (int i=1; i<=sum/2; ++i) {
            for (int j=i; j<sum; ++j) {
                tmp += j;
                if (sum == tmp) {
                    vector<int> ans;
                    for (int k=i; k<=j; ++k) ans.push_back(k);
                    ret.push_back(ans);
                }
                else if (tmp > sum) {
                    // 提前剪枝
                    tmp = 0;
                    break;
                }
            }
        }
        return ret;
    }
};