#include<bits/stdc++.h>
using namespace std; 
vector<int> dijkstra(vector<pair<int,int>> adj[],int V,int src)
{
    vector<int> dist(V,INT32_MAX);
    priority_queue<pair<int,int>> q;
    vector<bool> visited(V,false);
    dist[src]=0;
    q.push({0,src});
    while(!q.empty())
    {
        int cur=q.top().second;
        q.pop();
        if(visited[cur]) continue;
        visited[cur]=true;
        for(auto x:adj[cur])
        {
            int to=x.second;
            int wt=(x.first);
            if(dist[to] > wt+dist[cur])
            {
                dist[to] = wt+dist[cur];
                q.push({-dist[to],to});
            }
        }
    }
    return dist;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>> adj[V];
    while(E--)
    {
        int s,e,w;
        cin>>s>>e>>w;
        adj[s].push_back({w,e});
    }
    int src;cin>>src;
    vector<int> dist=dijkstra(adj,V,src);
    cout<<"source -> "<<src<<"\n";
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<dist[i]<<'\n';
    }
    return 0;
}