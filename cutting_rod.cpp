//
// Created by Mohit sharma on 21/09/19.
// https://practice.geeksforgeeks.org/problems/rod-cutting/0

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
#define MAX_SIZE 105
int costs[MAX_SIZE];
int dp[MAX_SIZE];

void solve() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> costs[i];
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = costs[i];
            for(int j = i-1; j > 0; j--) {
                dp[i] = max(dp[i], dp[j]+dp[abs(i-j)]);
            }
        }

        cout << dp[n] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}