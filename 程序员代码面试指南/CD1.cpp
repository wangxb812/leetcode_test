#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int N,M,K;
    cin>> N >> M >> K;
    vector<vector<int>> matrix(N,vector<int>(M));
    bool res = false;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j] == K)
                res=true;
        }
    }
    if(res==true)
    {
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}