#include <bits/stdc++.h>

using namespace std;
int f(int ind,int W,vector<vector<int>> &dp,vector<int> &wt,vector<int> &val)
{
    if(ind==0)
    {
        if(wt[ind]<=W)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }
    if(dp[ind][W]!=-1)
    {
        return dp[ind][W];
    }
    int nottake=0+f(ind-1,W,dp,wt,val);
    int take=INT_MIN;
    if(wt[ind]<=W)
    {
        take=val[ind]+f(ind-1,W-wt[ind],dp,wt,val);
    }
    return dp[ind][W]=max(take,nottake);
}
int main()
{
    vector<int> wt={1,2,4,5};
    vector<int> val={5,4,8,6};
    int n=wt.size();
    int W=5;
    vector<vector<int>> dp(n,vector<int> (W+1,-1));
    int ans=f(n-1,W,dp,wt,val);
    cout<<ans;
}