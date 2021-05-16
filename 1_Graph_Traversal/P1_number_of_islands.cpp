#include<bits/stdc++.h>
using namespace std;
#define COL 5
// ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** 
int isSafe(int M[][COL], int row, int col,int V,bool visited[][COL])
{
    // row number is in range, column
    // number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < V) && (col >= 0) && (col < V) && (M[row][col] && !visited[row][col]);
}
void DFS(int M[][COL],int V, int row, int col,bool visited[][COL])
{
    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
    // Mark this cell as visited
    visited[row][col] = true;
 
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k],V, visited))
            DFS(M,V, row + rowNbr[k], col + colNbr[k], visited);
}
int islands(int map[][COL],int V)
{
    bool visit[COL][COL];
    memset(visit,0,sizeof(visit));
    int cnt=0;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(map[i][j] && !visit[i][j])
            {
                DFS(map,V,i,j,visit);
                ++cnt;
            }
        }
    }
    return cnt;
}
int main()
{
    int V;
    cin>>V;
    int map[COL][COL];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>map[i][j];
        }
    }
    int count=islands(map,V);
    cout<<"Number of Islands-> "<<count<<'\n';
    return 0;
}