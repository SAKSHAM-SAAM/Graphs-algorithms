#include<bits/stdc++.h>
using namespace std;
void _Util(vector<int> adj[],int cur,vector<bool> &visited,vector<int> &disc,vector<int> &low,vector<int> &parent)
{
    visited[cur] = true;
    static int time=0;
    disc[cur]=low[cur]=++time;
    vector<int>::iterator i;
    for(i=adj[cur].begin();i<adj[cur].end();++i)
    {
        int v=*i;
        if(!visited[v])
        {
            parent[v]=cur;
            _Util(adj,v,visited,disc,low,parent);
            low[cur]=min(low[cur],low[v]);
            if(low[v] > disc[cur])
            {
                cout<<"edge b/w -> vertex "<<cur<<" and "<<v<<'\n';
            }
        }else if(parent[cur]!= v)
        {
            low[cur]=min(disc[v],low[cur]);
        }
    }
}
void bridges(vector<int> adj[],int V)
{
    vector<bool> visited(V,false);
    vector<int> disc(V,-1);
    vector<int> low(V,-1);
    vector<int> parent(V,-1);

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            _Util(adj,i,visited,disc,low,parent);
        }
    }
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    int a,b;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bridges(adj,V);
    return 0;
}