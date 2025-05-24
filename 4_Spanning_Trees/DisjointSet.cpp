#include<bits/stdc++.h>
using namespace std;
class UnionFind{
    private:
        vector<int> parent;
    public:
        UnionFind(int size){
            parent.resize(size);
            for(int i=0;i<size;i++){
                parent[i] = i;
            }
        }
        int find(int q){
            // if element is parent of itself
            if(parent[q] == q){
                return q;
            }
            // Recursively find parent of Q
            return find(parent[q]);
        }
        void unite(int a, int b){
            int aGrp = find(a);
            int bGrp = find(b);
            // Find parent of 'A' Group and make it
            // Parent of 'B' group as well.
            parent[bGrp] = aGrp;
        }
};
void solve(){
    int size;
    cout<<"Size of entities\n";
    cin>>size;
    UnionFind uF(size);
    int com=1;
    do
    {   
        /* code */
        cout<<"Input:\n 1. find \n 2. unite\n 0. Exit\n";
        cin>>com;
        switch (com)
        {
        case 1:
            /* Find Parent of query */
            int temp; cin>>temp;
            cout<<"Final Parent of "<<temp<<" -> "<<uF.find(temp)<<'\n';
            break;
        case 2: 
            /* Unite both inputs */
            int a, b; cin>>a>>b;
            uF.unite(a, b);
            cout<<"Union complete. "<<'\n';
            break;
        default:
            break;
        }
    } while (com!=0);
    
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}