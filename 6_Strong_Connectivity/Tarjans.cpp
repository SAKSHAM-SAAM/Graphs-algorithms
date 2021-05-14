// Tarjans Algorithm for Strongly Connected Componenets
#include<bits/stdc++.h>
using namespace std;
void util(vector<int> adj[],int cur,vector<int> &disc,vector<int> &low,vector<bool> &inStk,stack<int> &stk)
{
    static int time=0;
    disc[cur]=low[cur]=++time;
    stk.push(cur);
    inStk[cur]=true;

    vector<int>::iterator i;
    for(i=adj[cur].begin(); i!=adj[cur].end();++i)
    {
        int v=*i;
        if(disc[v]==-1)
        {
            util(adj,v,disc,low,inStk,stk);
            low[cur]=min(low[cur],low[v]);
        }
        else if(inStk[v]==true)
        {
            low[cur]=min(low[cur],disc[v]);
        }
    }

    int w=0;
    if(low[cur] == disc[cur])
    {
        while(stk.top()!=cur)
        {
            w=stk.top();
            stk.pop();
            inStk[w]=false;
            cout<<w<<" ";
        }
        w=stk.top();
        stk.pop();
        inStk[w]=false;
        cout<<w<<"\n";
    }
}
void tarjans(vector<int> adj[],int V)
{
    vector<int> disc(V,-1);
    vector<int> low(V,-1);
    vector<bool> inStk(V,false);
    stack<int> stk;

    for(int i=0;i<V;i++)
    {
        if(disc[i]==-1) util(adj,i,disc,low,inStk,stk);
    }
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    int a,b;
    while(E--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    tarjans(adj,V);
    return 0;
}