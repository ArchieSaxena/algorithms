#include <iostream>
#include <vector>
using namespace std;
int f(int i,int j,vector<vector<int> > &mat,vector<vector<int> > &dp)
{
    if(i==0 && j==0)
    {
        return mat[0][0];
    }
    if(i<0 || j<0)
    {
        return 1e9;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int up=mat[i][j]+f(i-1,j,mat,dp);
    int left=mat[i][j]+f(i,j-1,mat,dp);

    return dp[i][j]=min(up,left);
}
int main()
{
    vector<vector<int> > matrix 
    {
        {5,9,6},
        {11,5,2}
    };
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int> > dp(n,vector<int> (m,-1));
    cout<<f(n-1,m-1,matrix,dp);
}