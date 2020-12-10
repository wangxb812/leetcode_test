//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    /*
    利用辅助栈方式：
    初始化：用指针i指向pushV的第一个位置， 指针j指向popV的第一个位置
    如果pushV[i] != popV[j]， 那么应该将pushV[i]放入栈中， ++i
    否则，pushV[i]==popV[j], 说明这个元素是放入栈中立马弹出，所以，++i, ++j，然后应该检查popV[j]
    与栈顶元素是否相等，如果相等，++j, 并且弹出栈顶元素
    4，重复2，3， 如果i==pushV.size(), 说明入栈序列访问完，此时检查栈是否为空，如果为空，说明匹配，斗则不匹配。
    如下图：
    */
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int len = pushV.size();
        stack<int> st;
        int i=0,j=0;
        while(i<len){
            if(pushV[i]!=popV[j]){
                st.push(pushV[i]);
                i++;
            }else{
                i++;j++;
                while (!st.empty() && st.top() == popV[j]) {
                    st.pop();
                    ++j;
                }
            }
        }
        return st.empty();
    }
};