#include <bits/stdc++.h>

using namespace std;
bool f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp)
{
    if(ind==0)
    {
        return true;
    }
    if(ind==0)
    {
        return (arr[0]==target);
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int nottake=f(ind-1,target,arr,dp);
    int take=false;
    if(arr[ind]<=target)
    {
        take=f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[i][j]=take|nottake;
}
int main()
{
    vector<int> arr={1,2,3,4};
    int n=wt.size();
    int k=4;
    vector<vector<int>> dp(n,vector<int> (n,-1));
    return f(ind,target,arr,dp);
}