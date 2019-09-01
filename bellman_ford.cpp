//
// Created by Mohit sharma on 2019-09-01.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>

using namespace std;
#define FAST_INPUT_OUTPUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Write your code below
#define pi pair<int,int>
#define FROM 0
#define TO 1
#define WEIGHT 2


vector<vector<int>> edges;
vector<int> distances;

void initEdges(int vertexCount, int edgeCount);

void solve() {
    int t;
    int v,e;
    t = v = e = 0;
    cin >> t;
    while(t--) {
        cin >> v >> e;
        initEdges(v, e);
        distances[0] = 0;
        bool ans = false;
        bool isRefreshed = false;
        for(int i = 0; i <= v; i++) {
            isRefreshed = false;
            for(int j = 0; j < e; j++) {
                if((distances[edges[j][FROM]]+edges[j][WEIGHT]) < distances[edges[j][TO]]){
                    distances[edges[j][TO]] = (distances[edges[j][FROM]]+edges[j][WEIGHT]);
                    isRefreshed = true;
                }
            }
            ans = ((i == v)&isRefreshed);
        }
        if(ans) cout << "1" << endl;
        else cout << "0" << endl;
    }
}

void initEdges(int vertexCount, int edgeCount) {
    int x,y,z;
    edges.clear();
    edges.resize(edgeCount, vector<int>(3));
    for(int i = 0; i < edgeCount; i++){
        cin >> x >> y >> z;
        edges[i][FROM] = x;
        edges[i][TO] = y;
        edges[i][WEIGHT] = z;
    }

    distances.clear();
    distances.resize(vertexCount);
    for(int i = 0; i < vertexCount; i++) distances[i] = 99999999;
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}