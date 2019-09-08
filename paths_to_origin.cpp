//
// Created by Mohit sharma on 2019-09-08.
//
//Question: https://practice.geeksforgeeks.org/problems/paths-to-reach-origin/0

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
#define ll long long int
#define MAX_LIMIT 26

ll memo[MAX_LIMIT][MAX_LIMIT];

ll paths_to_origin(int x, int y) {
    if(x < 0 || y < 0) return 0;
    if(x == 0 && y == 0) return 1;
    if(memo[x][y] != -1) return memo[x][y];
    ll ans = 0;
    ans = paths_to_origin(x-1, y) + paths_to_origin(x, y-1);
    memo[x][y] = ans;
    return memo[x][y];
}

void solve() {
    int t, m, n;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        for(int i = 0; i < MAX_LIMIT; i++)
            memset(memo[i], -1, MAX_LIMIT* sizeof(ll));
        cout << paths_to_origin(m,n) << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}