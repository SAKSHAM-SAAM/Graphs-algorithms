#include<bits/stdc++.h>
using namespace std;
void articulation(vector<int> adj[], int V)
{
    // prequisites
    vector<bool> visited(V,false);
    vector<int> disc(V,-1);
    vector<int> low(V,-1);
    vector<int> parent(V,-1);
    vector<bool> artic(V,false);

}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    int a,b;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    articulation(adj,V);
    return 0;
}