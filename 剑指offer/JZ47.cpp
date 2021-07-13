class Solution {
public:
    int Sum_Solution(int n) {
        //逻辑与，如果前面为假，则后面不计算
        n>1 && (n+=Sum_Solution(n-1));
        return n;
    }
};