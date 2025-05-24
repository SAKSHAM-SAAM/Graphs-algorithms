#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
// 
void dfsUtil(vector<vector<int>> &adj, int currV , vector<bool>& vis){
    vis[currV] = true;
    cout<<currV<<" | ";
    for(int i=0; i< adj[currV].size() ; i++){
        if(!vis[adj[currV][i]]){
            dfsUtil(adj, adj[currV][i], vis);
        }
    }
}
void DFS(vector<vector<int>> adj)// DFS function: \n adjacency list DFS based function
{
    int V = adj.size();
    vector<bool> vis(V, false);
    dfsUtil(adj, 0, vis);
}
// zero based vertices to be used as inputs
void solve(){
    int V, E;
    cin>>V>>E;
    vector<vector<int>> adj(V, vector<int>());
    for(int i=0;i<E;i++){
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    DFS(adj);
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