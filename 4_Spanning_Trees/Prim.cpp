#include<bits/stdc++.h>
using namespace std;
// -----
struct edge{
    int w=INT_MAX, to=-1;
    bool operator<(edge const &other) const
    {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};
int Prim(vector<edge> edges[],int V)
{
    // final answer
    int minSpan=0;
    // declaration of library data structures
    vector<bool> visited(V,false);
    set<edge> hset;
    vector<edge> min_edge(V);
    // modifing data
    min_edge[0].w=0;
    hset.insert({0,0});
    for(int i=0;i<V;i++)
    {
        if(hset.empty())
        {
            cout<<"No MST possible\n";
            exit(0);
        }
        int v=hset.begin()->to;
        visited[v] = true;
        minSpan=minSpan+hset.begin()->w;
        hset.erase(hset.begin());

        if(min_edge[i].to != -1)
        {
            cout<<i<<" "<<min_edge[i].to<<" "<<min_edge[i].w<<'\n';
        }

        for(edge e:edges[v])
        {
            if (!visited[e.to] && e.w < min_edge[e.to].w) {
                hset.erase({min_edge[e.to].w, e.to});
                min_edge[e.to] = {e.w, v};
                hset.insert({e.w, e.to});
            }
        }
    }
    return minSpan;
}
/*
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        bool vis[V]={false};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum=0;
        while(!pq.empty())
        {
            pair<int, int> p=pq.top();
            pq.pop();
            int k=p.second;
            if(vis[k]) continue;
            vis[k]=true;
            sum+=p.first;
            for(int i=0; i<adj[k].size(); i++)
            {
                if(!vis[adj[k][i][0]]) pq.push({adj[k][i][1], adj[k][i][0]});
            }
        }
        return sum;
    }
*/
int main()
{
    int V,E;
    cin>>V>>E;
    vector<edge> edges[V];
    while(E--)
    {
        int s,e,w;
        cin>>s>>e>>w;
        edge tmp; tmp.to=e; tmp.w=w;
        edges[s].push_back(tmp);
    }
    int dist = Prim(edges,V);
    cout<<dist<<" ";
    return 0;
}