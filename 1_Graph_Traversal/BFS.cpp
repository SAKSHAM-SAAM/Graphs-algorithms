#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
void BFS(vector<vector<int>> adj)
{
    int V = adj.size();
    // Main BFS logic
    queue<int> q;
    q.push(0);
    vector<bool> vis(V, false);
    vis[0] = true;
    int qs = q.size();
    while(!q.empty()){
        int vert = q.front();
        q.pop();
        for(int v=0; v < adj[vert].size() ; v++){
            int newVert = adj[vert][v];
            if(!vis[newVert]){
                q.push(newVert);
                vis[newVert] = true;
            }
        }

        cout<<vert;
        (q.empty())?(cout<<" : "):(cout<<" - ");
    }
}
void solve(){
    // input the graph
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V, vector<int>());
    for(int i=0;i<E;i++){
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // call BFS on graph
    BFS(adj);
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