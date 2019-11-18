//
// Created by Mohit sharma on 17/11/19
// https://practice.geeksforgeeks.org/problems/maximum-profit/0

#include <iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<limits.h>

using namespace std;
#define FAST_INPUT_OUTPUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Write your code below
#define MAX_SIZE 50
#define MAX_K 13
int arr[MAX_SIZE];
int dp[MAX_K][MAX_SIZE];

void solve() {
    int t, k, n;
    memset(dp, 0, MAX_SIZE * MAX_K * sizeof(int));
    cin >> t;
    int max_const;
    while(t--) {
        cin >> k >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];

        for(int i = 1; i <= k; i++) {
            max_const = -arr[0];
            for(int j = 1; j < n; j++) {
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), arr[j]+max_const);
                max_const = max(max_const, dp[i-1][j-1]-arr[j]);
            }
        }

        cout << dp[k][n-1] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}