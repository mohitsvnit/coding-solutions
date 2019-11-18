//
// Created by Mohit sharma on 18/11/19
// https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0

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
#define ll long long int
#define MAX_SIZE_N 1050
#define MAX_SUM 1050
ll dp[MAX_SIZE_N][MAX_SUM];
int arr[MAX_SIZE_N];

void solve() {
    int t, n, k;
    cin >> t;

    for(int i = 0; i < MAX_SUM; i++) dp[0][i] = 0;
    for(int i = 0; i < MAX_SIZE_N; i++) dp[i][0] = 1;

    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j<= k; j++) {
                dp[i][j] = 0;
                if(j < arr[i-1]) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                }
            }
        }
        cout << dp[n][k] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}