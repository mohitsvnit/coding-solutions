//
// Created by Mohit sharma on 03/11/19
// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0

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
#define MAX_SIZE 1050

int dp[MAX_SIZE][MAX_SIZE];
int weight[MAX_SIZE];
int value[MAX_SIZE];
void solve() {
    int t, n, w;
    cin >> t;
    memset(dp, 0, MAX_SIZE*MAX_SIZE* sizeof(int));
    while(t--) {
        cin >> n >> w;
        for(int i = 0; i < n; i++) cin >> value[i];
        for(int i = 0; i < n; i++) cin >> weight[i];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= w; j++) {
                if(j < weight[i-1]) {
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i-1]] + value[i-1]);
                }
            }
        }

        cout << dp[n][w] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}