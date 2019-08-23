//
// Created by Mohit sharma on 2019-08-23.
//

// Question: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

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
/* You have to complete this function*/
/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    if(N <= 0) return;
    queue<int> que;
    set<int> st;
    que.push(0);
    st.insert(0);
    int ele;
    while(!que.empty()) {
        ele = que.front();
        que.pop();
        st.erase(ele);
        vis[ele] = true;
        cout << ele << " ";

        for(int child : adj[ele]) {
            if((!vis[child]) && (st.find(child) == st.end())) {
                que.push(child);
                st.insert(child);
            }
        }
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
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        bfs(0, adj, vis, N);
        cout<<endl;
    }
}
