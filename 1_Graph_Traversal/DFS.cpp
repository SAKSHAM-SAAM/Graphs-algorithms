#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// 
void _Util(bool visited[],vector<int> edges[], int x)
{
    cout<<x<<" ";
    for(int i=0;i<edges[x].size();i++)
    {
        if(visited[edges[x][i]]==false){
            visited[edges[x][i]] = true;
            _Util(visited,edges,edges[x][i]);
        }
    }
}
void DFS(vector<int> edges[],int V)// DFS function: \n adjacency list DFS based function
{
    bool visited[V]={false};
    int count=0; // island counts
    for(int i=0;i<V;i++)
    {
        if(!visited[i]){
            visited[i]=true;
            _Util(visited,edges,i);
            count++;
        }
    }
    cout<<endl;
    cout<<"count of islands: "<<count<<'\n';
    return;
}
// zero based vertices to be used as inputs
int main()
{
    int V,E;
    cin>>V>>E; 
    vector<int> edges[V];
    while(E--)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    DFS(edges,V);
    return 0;
}