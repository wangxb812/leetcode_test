#include<vector>
#include<stack>
#include<string>
#include<iostream>
using namespace std;
class solution
{
public:
    stack<int> stack1;
    stack<int> stack2;
    void add(int a)
    {
        stack1.push(a);
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }
    int poll(){
        if(stack1.empty() && !stack1.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty())  return 0;
        int res=stack2.top();
        stack2.pop();
        return res;
    }
    int peek(){
            if(stack2.empty() && !stack1.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty()) return 0;
        return stack2.top();
    }
};
void main(string args[]){
    int n =0;
    cin>>n;
}