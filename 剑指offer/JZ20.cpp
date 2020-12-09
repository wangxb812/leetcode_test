//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数
//（时间复杂度应为O（1））。
#include<stack>
using namespace std;
class Solution {
public:
    //使用辅助栈
    stack<int> min,normal;
    void push(int value) {
        normal.push(value);
        if(min.empty()){
            min.push(value);
        }else{
            if(value<=min.top()){
                min.push(value);
            }
            else{
                min.push(min.top());
            }
        }
    }
    void pop() {
        normal.pop();
        min.pop();
    }
    int top() {
        return normal.top();
    }
    int min() {
        return min.top();
    }
};