#include<bits/stdc++.h>
using namespace std;
void _Util(vector<int> adj[],vector<bool> &visited,vector<int> &disc,vector<int> &low,vector<int> &parent, vector<bool> &arc,int cur)
{
    int children = 0;
    visited[cur] = true;
    static int time=0;
    disc[cur] =low[cur] =++time;
    //*time++;
    vector<int>:: iterator i;
    for(i=adj[cur].begin(); i!=adj[cur].end();++i)
    {
        int v=*i;
        if(visited[v]==false)
        {
            children++;
            parent[v]=cur;
            _Util(adj,visited,disc,low,parent,arc,v);
            low[cur]=min(low[cur],low[v]);

            if(children > 1 && parent[cur]==-1) arc[cur]=true;
            if(parent[cur] != -1 && low[v] >= disc[cur])  arc[cur]=true;
        }else if(v != parent[cur]){
            low[cur]=min(low[cur],disc[v]);
        }
    }
}
void articulation(vector<int> adj[], int V)
{
    // prequisites
    vector<bool> visited(V,false);
    vector<int> disc(V,-1);
    vector<int> low(V,-1);
    vector<int> parent(V,-1);
    vector<bool> artic(V,false);
    // int time = 0;

    for(int i=0;i<V;i++)
    {
        if(visited[i] == false)
        {
            _Util(adj,visited,disc,low,parent,artic,i);
        }
    }
    cout<<endl;
    for(int i=0;i<V;i++)
    {
        if(artic[i])
        cout<<i<<" ";
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
    articulation(adj,V);
    return 0;
}