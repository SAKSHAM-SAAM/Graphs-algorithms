#include<bits/stdc++.h>
using namespace std;
/*
    ADJACENCY Matrix REPRESENTATION
    * Unweighted
    * Bi-directional
*/
void solve(){
    int V, E;
    cin>>V>>E;
    vector<vector<int>> adj(V, vector<int>(V,0));
    for(int i=0;i<E;i++){
        int a,b; cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
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