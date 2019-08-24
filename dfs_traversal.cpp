//
// Created by Mohit sharma on 2019-08-24.
//

//Question: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
//Position this line where user code will be pasted.

/*This is a function problem.You only need to complete the function given below*/
/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/
void dfs(int s, vector<int> g[], bool vis[])
{
    cout << s << " ";
    vis[s] = true;
    for(int child: g[s]){
        if(!vis[child]) dfs(child, g, vis);
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,g,vis);

        cout<<endl;
    }
}
