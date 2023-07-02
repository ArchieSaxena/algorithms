#include <bits/stdc++.h>

using namespace std;
int f(int i,int j,vector<vector<int>> &dp,vector<int> &mat)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int ans=f(i,k,dp,mat)+f(k+1,j,dp,mat)+mat[i-1]*mat[k]*mat[j];
        mini=min(ans,mini);
    }
    return mini;
}
int main()
{
    vector<int> mat = {10, 20, 30, 40, 50};
    int n=5;
    vector<vector<int>> dp(n,vector<int> (n,-1));
    int ans=f(1,n-1,dp,mat);
    cout<<ans;

}