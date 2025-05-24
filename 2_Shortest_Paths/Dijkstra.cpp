#include<bits/stdc++.h>
using namespace std; 
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
/*
 DJIKSTRA ALGORITHM FOR SHORTEST DISTANCE
 * Undirected
 * Weighted
*/
 vector<int> dijkstra(vector<vector<vector<int>>> &adj,int V,int src)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> vis(V, false);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int from = pq.top()[1];
        pq.pop();
        if(vis[from]) continue;
        vis[from] = true;
        for(int i=0 ; i<adj[from].size() ; i++){
            vector<int> nextVec = adj[from][i];
            int to = nextVec[0];
            int wt = nextVec[1];
            if( dist[to] >  wt + dist[from]){
                dist[to] = wt + dist[from];
                pq.push({wt, to});
            }
        }
    }
    return dist;
}
void solve()
{
    int V,E; cin>>V>>E;
    vector<vector<vector<int>>> adj(V, vector<vector<int>> ());
    for(int i=0;i<E;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    vector<int> minDist = dijkstra(adj, V, 0);
    cout<<"From source 0 , distance to all vertices is : "<<endl;
    for(int i=0; i<V; i++){
        cout<<i<<" = "<<minDist[i]<<"\n";
    }
}
int main()
{
    IOS;
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}