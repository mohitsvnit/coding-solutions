//
// Created by Mohit sharma on 11/10/19.
// https://practice.geeksforgeeks.org/problems/get-minimum-squares/0

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
#define MAX_SIZE 10050
int dp[MAX_SIZE];

int getMinSquares(int n) {
    if(dp[n] != -1) return dp[n];
    int ans = INT_MAX;
    for(int i = 1; i*i <= n; i++) {
        ans = min(ans, getMinSquares(n-(i*i))+1);
    }
    dp[n] = ans;
    //cout << n << " -> " << dp[n] << endl;
    return dp[n];
}

void solve() {
    memset(dp, -1, MAX_SIZE* sizeof(int));
    dp[0] = 0;
    dp[1] = 1;
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << getMinSquares(n) << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}