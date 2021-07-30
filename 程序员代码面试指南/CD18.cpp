/*
 * @Author: m1ng
 * @Date: 2021-07-30 00:02:07
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-31 01:06:20
 * @FilePath: \leetcode_test\程序员代码面试指南\CD18.cpp
 * @Description: header
 */
//详情请见左神书籍，这个算法碉堡了
//我针对一些代码写些注释方便理解
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main()
{
	long long n; long long num;
	cin >> n >> num;
	vector<long long> datas(n, 0);
	for (int i = 0; i<n; i++)
	{
		long long x;
		cin >> x;
		datas[i] = x;
	}
        //以上用于输入
	deque<int> dq1;//最大值队列
	deque<int> dq2;//最小值队列
	int res = 0;
	int j = 0;
	int i = 0;
	for (; i<datas.size(); i++)
	{ //以i为起始位置的子数组
        for (; j<datas.size(); j++)
		{
			while (!dq1.empty() && datas[j] >= datas[dq1.back()])
				dq1.pop_back();
			dq1.push_back(j);
			while (!dq2.empty() && datas[j] <= datas[dq2.back()])
				dq2.pop_back();
			dq2.push_back(j);
                        //如果最大值减去最小值大于num就break，此时最大值
                        //减去最小值大于num一定是由于j的插入
			if (datas[dq1.front()] - datas[dq2.front()]>num)
				break;
		}
		if (dq1.front() == i)//如果队头是i位置的元素，i加一后就过期删掉
			dq1.pop_front();
		if (dq2.front() == i)
			dq2.pop_front();
		res += j - i;//以i为开头的小于num的子数组长度j-i
	}
	cout <<res <<endl;
}