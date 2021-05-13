#include<bits/stdc++.h>
using namespace std;
class Graph // Graph class with inbuild functionality for Strongly connected components. 
{
    private:
        int V; // *
        vector<int> *adj; // *
        void DFSutil(int cur,vector<bool> &proc); // 
        void Fillorder(int x,vector<bool> &proc,stack<int> &s); // *
    public:
        Graph(int V); // *
        ~Graph(); // *
        void addEdge(int s,int e); // *
        void printSCC(); // *
        Graph transposeFunc(); // *
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new vector<int>[V];
}

Graph::~Graph()
{
}

void Graph::addEdge(int s,int e)
{
    adj[s].push_back(e);
}

void Graph::printSCC()
{
    stack<int> stk;
    vector<bool> proc(V,false);

    for(int i=0;i<V;i++)
    {
        if(!proc[i]) Fillorder(i,proc,stk);
    }
    Graph gt = transposeFunc();

    proc.assign(V,false);
    while(!stk.empty())
    {
        int vert=stk.top();
        stk.pop();
        if(proc[vert] == false)
        {
            gt.DFSutil(vert,proc);
            cout<<endl;
        }
    }
}

void Graph::Fillorder(int x,vector<bool> &proc,stack<int> &s)
{
    proc[x]=true;
    for(int e:adj[x])
    {
        if(proc[e]==false) Fillorder(e,proc,s);
    }
    s.push(x);
}

Graph Graph::transposeFunc()
{
    Graph tran(V);
    for(int i=0;i<V;i++)
    {
        vector<int>::iterator e;
        for(e=adj[i].begin();e!=adj[i].end();++e)
        {
            tran.adj[*e].push_back(i);
        }
    }
    return tran;
}

void Graph::DFSutil(int cur,vector<bool> &proc)
{
    proc[cur]=true;
    cout<<cur<<" ";
    for(int e:adj[cur])
    {
        if(proc[e]==false)
        {
            DFSutil(e,proc);
        }
    }
}

int main()
{
    int V,E;
    cin>>V>>E;
    Graph g(V);
    while(E--)
    {
        int s,e;
        cin>>s>>e;
        g.addEdge(s,e);
    }
    g.printSCC();
    return 0;
}
