#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
void _Util(bool visited[],vector<int> edges[],int str)
{
    queue<int> q;
    q.push(str);
    visited[str]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(int k=0;k<edges[x].size();k++)
        {
            if(visited[edges[x][k]]==false){
                visited[edges[x][k]]=true;
                q.push(edges[x][k]);
            }
        }
    }
}
void BFS(vector<int> edges[],int V)
{
    bool visited[V]={false};
    int count=0;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            _Util(visited,edges,i);
            count++;
        }
    }
    cout<<endl;
    cout<<"count of islands: "<<count<<'\n';
}
int main()
{
    IOS;
    int V,E;
    cin>>V>>E;
    vector<int> edges[V];
    while(E--)
    {
        int a,b;
        cin>>a>>b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    BFS(edges,V);
    return 0;
}