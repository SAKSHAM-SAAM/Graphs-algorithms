#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> edges[],int a,int b,int c)
{
    edges[a].push_back({c,b});
}
vector<int> DAG(vector<pair<int,int>> edges[],int V,int src)
{
    vector<int> dist(V,INT_MAX);
    queue<pair<int,int>> q; // pair stored in queue as {weight,destination vertex}
    q.push({0,src});
    dist[src]=0;
    while(q.empty() == false)
    {
        int dest = q.front().second;
        q.pop();
        for(auto i:edges[dest])
        {
            dist[i.second] = min(dist[i.second], dist[dest]+i.first);
            q.push(i);
        }
    }
    return dist;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>> edges[V];
    while(E--)
    {
        int a,b,c; // edge from 'a' to 'b' of weight 'c'
        cin>>a>>b>>c;
        addEdge(edges,a,b,c);
    }
    int src;
    cin>>src;
    vector<int> dist = DAG(edges,V,src);
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<dist[i]<<"\n";
    }
    return 0;
}