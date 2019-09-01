//
// Created by Mohit sharma on 2019-08-29.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define FAST_INPUT_OUTPUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Write your code below


vector<vector<int>> weaveArrays(vector<int> &a, vector<int> &b) {
    vector<vector<int>> result;
    if((a.size() == 0) && (b.size() == 0)) return result;
    if(a.size() == 0) {
        result.push_back(b);
        return result;
    }
    if(b.size() == 0){
        result.push_back(a);
        return result;
    }

    int val = a[0];
    a.erase(a.begin());
    for(vector<int> arr: weaveArrays(a, b)){
        arr.insert(arr.begin(), val);
        result.push_back(arr);
    }
    a.insert(a.begin(), val);
    val = b[0];
    b.erase(b.begin());
    for(vector<int> arr: weaveArrays(a, b)){
        arr.insert(arr.begin(), val);
        result.push_back(arr);
    }
    b.insert(b.begin(), val);
    return result;
}

vector<vector<int>> findAllWays(int node, vector<vector<int>> &tree) {
    if(node == -1) return vector<vector<int>>();
    vector<vector<int>> result;
    vector<vector<int>> leftWays = findAllWays(tree[node][0], tree);
    vector<vector<int>> rightWays = findAllWays(tree[node][1], tree);

    for(vector<int> a: leftWays) {
        for(vector<int> b: rightWays) {
            vector<vector<int>> weavedArray = weaveArrays(a,b);
            for(vector<int> arr: weavedArray){
                arr.insert(arr.begin(), node);
                result.push_back(arr);
            }
        }
    }

    if(result.size() == 0) result.push_back({node});
    return result;
}

void solve() {
    vector<vector<int>> tree = {
            {1,2},
            {3,4},
            {5,6},
            {-1,-1},
            {-1,-1},
            {-1,-1},
            {-1,-1}
    };

    for(vector<int> arr: findAllWays(0,tree)){
        for(int ele: arr) cout << ele << " ";
        cout << "\n";
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    solve();
    return 0;
}