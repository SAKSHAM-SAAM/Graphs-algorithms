#include<bits/stdc++.h>
using namespace std;
void _dfs(vector<int> adj[],vector<bool> &state,vector<int> &jobs,int x)
{
    state[x]=true;
    for(auto e:adj[x])
    {   
        if(state[e]==false){
            _dfs(adj,state,jobs,e);
        }
    }
    jobs.push_back(x);
}
vector<int> TopoSort(vector<int> adj[], int V)
{
    vector<int> jobs;
    vector<bool> state(V,false);
    // utility
    for(int i=0;i<V;i++)
    {
        if(state[i]==false){
            cout<<"dfs-> "<<i<<"\n";
            _dfs(adj,state,jobs,i);
        }
    }
    reverse(jobs.begin(),jobs.end());
    return jobs;
}
/// main function 
int main()
{
    // taking vertices and edge count as input 
    int V,E;
    cin>>V>>E;
    // increasing vertex count by one to start vertices with base zero
    V=V+1;
    // adjacency list declaration -> array of vectors
    vector<int> adj[V]; // or can use -> vector<vector<int>> adj(V);
    // taking input of edges
    while(E--)
    {
        int s,e;
        cin>>s>>e;
        adj[s].push_back(e);
    }
    cout<<"all edges added.\n";
    // call function
    vector<int> srt = TopoSort(adj,V);
    for(int i=0;i<V;i++)
    {
        cout<<srt[i]<<" ";
    }
    return 0;
}