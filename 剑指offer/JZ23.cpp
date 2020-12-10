//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true,否则返回false。假设输入的数组的任意两个数字都互不相同。
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    //二叉搜索树是一种节点值之间具有一定数量级次序的二叉树，对于树中每个节点：
    //若其左子树存在，则其左子树中每个节点的值都不大于该节点值；
    //若其右子树存在，则其右子树中每个节点的值都不小于该节点值

    // 请检查是否存在数组、列表等越界非法访问，内存非法访问等情况
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len=sequence.size();
        if(len == 0)
            return false;
        int root = sequence[len-1];
        int i,j;
        for(i=0;i<len-1;i++){
            if(sequence[i]>root)
                break;
        }
        for(j=i;j<len-1;j++){
            if(sequence[j]<root)
                return false;
        }
        bool left = true;
        vector<int> leftTree (sequence.begin(),sequence.begin()+i-1);
        if(i>0) left = VerifySquenceOfBST(leftTree);
        bool right = true;
        vector<int> rightTree (sequence.begin()+i,sequence.end()-i);
        if(i>0) right = VerifySquenceOfBST(rightTree);
        return (left && right);
    }
    bool VerifySquenceOfBST_2(vector<int> sequence) {
    if(sequence.size()==0){
        return false;
    }
    int sum = sequence.size()-1;
    int count = 0;
    while(sum){
        while(sequence[count] < sequence[sum]){
            ++count;
        }
        while(sequence[count] > sequence[sum]){
            ++count;
        }
        if(count < sum){
            return false;
        }
        --sum;
        count = 0;
    }
    return true;
    }
};