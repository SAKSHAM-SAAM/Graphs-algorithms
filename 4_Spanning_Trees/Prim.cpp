#include<bits/stdc++.h>
using namespace std;
#define pb push_back
class Edge{
    public:
        int to;
        int weight;
        Edge(int to, int wt){
            this->to        = to;
            this->weight    = wt;
        }
};

class Compare{
    public: 
        bool operator()(Edge a, Edge b){
            return a.weight > b.weight;
        }
};

int Prim(vector<Edge> adj[], int verts){
    vector<bool> visited(verts, false);
    vector<int> minDist(verts, INT16_MAX);
    int mst = 0;
    priority_queue<Edge, vector<Edge> , Compare > pq;
    pq.push(Edge(0,0));
    cout<<"line 27 : code to enter loop"<<endl;
    while(!pq.empty()){
        Edge curr  = pq.top(); pq.pop();
        int to      = curr.to;
        int weight  = curr.weight;  
        cout<<"line 32 : values of to "<<to<<" and weight "<<weight<<endl;
        if(visited[to]) continue;
        visited[to] = true;
        mst = mst + weight;
        cout<<"MST value "<<mst<<endl;
        cout<<"size of ADJ "<<adj[to].size()<<endl;
        for(int i=0;i<adj[to].size();i++){
            cout<<"visted Status of vert "<<adj[to][i].to<<" is "<<visited[adj[to][i].to];
            if(!visited[adj[to][i].to]){
                pq.push(adj[to][i]);
            }
        }   
    }
    /*PRINT PQ DATA
    for(auto x:adj){
        pq.push(x);
    }
    while(!pq.empty()){
        Edge tmp = pq.top(); pq.pop();
        cout<<tmp.from<<" - "<<tmp.to<<" - "<<tmp.weight<<endl;
    }*/
    return mst;
}
void solve(){
    int verts, edges;
    cin>>verts>>edges;
    vector<Edge> adj[verts];
    int from, to, wt;
    for(int i=0; i<edges ; i++){
        cin>>from>>to>>wt;

        adj[from].pb(Edge(to, wt));
        adj[to].pb(Edge(from, wt));
    }
    int minDist = Prim(adj, verts);
    cout<<"MIN DIST = "<<minDist<<endl;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}