#include <bits/stdc++.h>
using namespace std;
#define pb push_back
///@brief
/// Public Class to handle tuple data
/// from--to (weight) per edge input
/// current implmentation is non-directed
class Edge
{
    public:
        int from, to, wt;
        Edge(){

        }
        Edge(int f, int t, int w)
        {
            this->from  = f;
            this->to    = t;
            this->wt    = w;
        }
        void display()
        {
            cout << "\t-> " << from << " - " << to << " (" << wt << ")\n";
        }
};
///@brief union Find Class to handle
/// disjoint set implmentation.
class unionFind
{
public:
    vector<int> parent;
    vector<int> height;
    unionFind(int size)
    {
        parent.resize(size);
        height.resize(size);
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            height[i] = 1;
        }
    }
    int find(int q)
    {
        if (parent[q] == q)
            return q;
        return find(parent[q]);
    }
    void unite(int a, int b)
    {
        int aGrp = find(a);
        int bGrp = find(b);
        if (height[aGrp] > height[bGrp])
        {
            parent[aGrp] = bGrp;
            height[bGrp] = height[bGrp] + height[aGrp];
        }
        else
        {
            parent[bGrp] = aGrp;
            height[aGrp] = height[bGrp] + height[aGrp];
        }
    }
};
/// @brief
/// Custom comparator for Edge class
/// used to sort priority queue
/// @return boolean
bool compare(Edge &a, Edge &b)
{
    return a.wt < b.wt;
}
/// @brief Implementation of Kruskal's Minimum Spanning Tree algorithm
/// @param adj - (Vector container with all the edges)
/// @param verts - (INTEGER for number of vertices)
/// @return (INTEGER) minDist (minimum MST weight)
int kruskal(vector<Edge> &adj, int verts)
{
    unionFind uF(verts);
    int minDist = 0;
    sort(adj.begin(), adj.end(), compare);
    for(int i=0 ; i<adj.size() ; i++){
        int from= uF.find(adj[i].from);
        int to  = uF.find(adj[i].to);
        if(from != to){
            uF.unite(from, to);
            minDist = minDist + adj[i].wt;
        }
    }
    return minDist;
}
/// @brief Main function running per test case
/// @param void
/// @return void
void solve()
{
    int verts, edges;
    cin >> verts >> edges;
    vector<Edge> adj;
    for (int i = 0; i < edges; i++)
    {
        int from, to, wt;
        cin >> from >> to >> wt;
        Edge tmp(from, to, wt);
        adj.pb(tmp);
    }
    int minDist = kruskal(adj, verts);
    cout << "MST weight : " << minDist << endl;
}
int main()
{
    int tst;
    cin >> tst;
    while (tst--)
    {
        solve();
    }
    return 0;
}