#include <bits/stdc++.h>
using namespace std;
int ans=0;
int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
{
    // int ans=0;
    if(i<0 || j<0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s1[i]==s2[j])
    {
        dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
        // ans = max(ans, dp[i][j]);
    }
    else
    {
        dp[i][j]=0;
        // return max(res,max(f(i-1,j,s1,s2,dp,0),f(i,j-1,s1,s2,dp,0)));
    }
    f(i-1,j,s1,s2,dp);
    f(i,j-1,s1,s2,dp);
    ans=max(ans,dp[i][j]);
    return dp[i][j];
    // return ans;
}
int main()
{
    string s1="abzd";
    string s2="abcd";
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    cout<<f(n-1,m-1,s1,s2,dp);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
}