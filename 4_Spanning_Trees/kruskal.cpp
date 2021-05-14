#include<bits/stdc++.h>
using namespace std;
struct Disjoint{
    int *link,*size;
    int n;

    Disjoint(int v)
    {
        this->n = v;
        link = new int[n+1];
        size = new int[n+1];
        for(int i=0;i<=n;i++)
        {
            link[i]=i;
            size[i]=0;
        }
    }

    int find(int x)
    {
        while(x!=link[x]) x=link[x];
        return x;
    }

    void unite(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(size[a]>size[b]) link[b]=a;
        else link[a]=b;
        if(size[a] == size[b]) size[b]++;
    }
};
int kruskal(vector<pair<int,pair<int,int>>> edges,int V)
{
    int mst_wt=0;

    sort(edges.begin(),edges.end());

    Disjoint ds(V);

    vector<pair<int,pair<int,int>>>:: iterator i;
    for(i=edges.begin();i!=edges.end();++i)
    {
        int s=i->second.first;
        int e=i->second.second;

        int linkS = ds.find(s);
        int linkE = ds.find(e);

        if(linkE!=linkS)
        {
            cout<<s<<" - "<<e<<'\n';
            mst_wt=mst_wt+i->first;

            ds.unite(linkE,linkS);
        }
    }
    return mst_wt;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<pair<int,pair<int,int>>> edges;
    while(E--)
    {
        int s,e,w;
        cin>>s>>e>>w;
        edges.push_back({w,{s,e}});
    }
    int wt = kruskal(edges,V);
    cout<<wt<<'\n';
    return 0;
}