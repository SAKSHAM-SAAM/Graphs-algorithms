#include<bits/stdc++.h>
using namespace std; 
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define INF 9999999
/*
 Bellman Ford ALGORITHM FOR SHORTEST DISTANCE
 * Undirected
 * Weighted
*/
class Edge
{
private:
    int from, to, weight;

public:
    Edge()
    {
    }
    Edge(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    int getFrom(){ return from;}
    int getTo(){ return to;}
    int getWeight(){ return weight;}

    void setFrom(int from){ this->from = from;}
    void setTo(int to){ this->to = to;}
    void setWeight(int weight){this->weight = weight;}
};
vector<int> bellmanFord(vector<Edge> &adj,int V, int src)
{
    vector<int> dist(V, INF);
    dist[src] = 0;
    for(int i=0;i<V;i++){
        for(Edge E:adj){
            int from= E.getFrom();
            int to  = E.getTo();
            int wt  = E.getWeight();
            if(dist[to]>dist[from] + wt ){
                dist[to] = dist[from] + wt;
            }
        }
    }
    return dist;
}
void solve()
{
    int V,E; cin>>V>>E;
    vector<Edge> adj;
    for(int i=0;i<E;i++){
        int a,b,w;
        cin>>a>>b>>w;
        Edge temp(a, b, w);
        adj.pb(temp);
        Edge temp2(b,a,w);
        adj.pb(temp2);
    }
    vector<int> minDist = bellmanFord(adj ,V ,0);
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