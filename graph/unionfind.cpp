#include <iostream>
#include <vector>
using namespace std;
class disjointset
{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
public:
    disjointset(int n)
    {
        rank.resize(n+1,0);
        size.resize(n + 1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
        
    int findUpar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }

    void unionbyrank(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbysize(int u, int v) {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    disjointset ds(7);
    ds.unionbyrank(1,2);
    ds.unionbyrank(2,3);
    ds.unionbyrank(4,5);
    ds.unionbyrank(6,7);
    ds.unionbyrank(5,6);
    
    if(ds.findUpar(3)==ds.findUpar(7))
    {
        cout<<"Same"<<endl;
    }
    else
    {
        cout<<"nOT SAME"<<endl;
    }

    ds.unionbyrank(3,7);

    if(ds.findUpar(3)==ds.findUpar(7))
    {
        cout<<"same"<<endl;
    }
    else
    {
        cout<<"not same"<<endl;
    }
    return 0;
}


class disjointset
{
    vector<int> rank;
    vector<int> size;
    vector<int> parent;

    public:
    disjointset(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=i;
        }
    }

    int findUpar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }


    void unionbysize(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};