#include <iostream>
#include <vector>
using namespace std;
void f(int i,int j,vector<vector<int> > &m,int n,vector<string> &ans,string move,vector<vector<int> > &vis)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(move);
        return;
    }
    
    //down
    if(i+1<n && !vis[i+1][j] && m[i+1][j]==1)
    {
        vis[i][j]=1;
        f(i+1,j,m,n,ans,move+'D',vis);
        vis[i][j]=0;
    }
    //left 
    if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1)
    {
        vis[i][j]=1;
        f(i,j-1,m,n,ans,move+'L',vis);
        vis[i][j]=0;
    }
    //right 
    if(j+1<n && !vis[i][j+1] && m[i][j+1]==1)
    {
        vis[i][j]=1;
        f(i,j+1,m,n,ans,move+'R',vis);
        vis[i][j]=0;
    }
    //up
    if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1)
    {
        vis[i][j]=1;
        f(i-1,j,m,n,ans,move+'U',vis);
        vis[i][j]=0;
    }
}
int main()
{
    int n=4;
    vector<string> ans;
    string move="";
    vector<vector<int> > m={{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    vector<vector<int> > vis(n,vector<int> (n,0));
    if(m[0][0]==1)
    {
        f(0,0,m,n,ans,"",vis);
    }
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
        cout<<" ";
    }
    cout<<endl;
}