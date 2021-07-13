//JZ47
#include<vector>
using namespace std;
class Solution {
public:
    int Sum_Solution(int n) {
        int sum=0;
        //逻辑与，如果前面为假，则后面不计算
        sum && (sum+=Sum_Solution(n-1));
        return sum;
    }
};
