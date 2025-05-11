#include<bits/stdc++.h>
using namespace std;
/*
    ADJACENCY LIST REPRESENTATION
    * Unweighted
    * Bi-directional
*/
void solve(){
    int V, E;
    cin>>V>>E;
    vector<vector<int>> adj(V, vector<int>());
    for(int i=0;i<E;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
int main(){
    int tc; cin>>tc;
    while(tc>0){
        solve();
        tc--;
    }
    return 0;
}