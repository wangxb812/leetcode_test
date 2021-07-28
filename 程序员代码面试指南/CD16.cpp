/*
 * @Author: m1ng
 * @Date: 2021-07-29 00:13:15
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-29 01:31:12
 * @FilePath: \leetcode_test\程序员代码面试指南\CD16.cpp
 * @Description: header
 */
#include <stack>
#include <iostream>
using namespace std;
int getOneNumber()
{

}
int main()
{
    int n,m;
    cin>>n>>m;
}
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int getMin(vector<vector<int>>& map) {

    int MAX = 0;
    vector<int> height(map[0].size(), 0);
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[0].size(); ++j) {
            if (map[i][j] == 0) {
                height[j] = 0;
            }
            else {
                height[j] += map[i][j];
            }
        }
        //单调栈(严格满足单调递减)
        stack<int> s;
        int length = height.size();
        for (int k = 0; k < height.size(); ++k) {
            //如果当前的元素比栈顶的元素小于等于栈顶元素，则记录当前元素的下标
            while (!s.empty() && height[k] < height[s.top()]) {
                int cur = s.top();
                s.pop();
                int l = s.empty() ? -1 : s.top();
                MAX = max((k - l - 1) * height[cur], MAX);
            }
            s.push(k);

        }
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            int l = s.empty() ? -1 : s.top();
            MAX = max((length - l - 1) * height[cur], MAX);
        }
    }
    return MAX;
}
int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    cout << getMin(map) << endl;

    return 0;
}