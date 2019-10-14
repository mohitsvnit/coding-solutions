//
// Created by Mohit sharma on 14/10/19.
// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <limits.h>
using namespace std;
#define FAST_INPUT_OUTPUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Write your code below
#define MAX_SIZE 1000010
int dp[11][MAX_SIZE];
vector<int> coins = { 0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
void preProcess() {
    for(int i = 0; i < MAX_SIZE; i++) dp[0][i] = INT_MAX;
    for(int i = 0; i < coins.size(); i++) dp[i][0] = 0;

    for(int i = 1; i < coins.size(); i++) {
        for(int j = 1; j < MAX_SIZE; j++) {
            if(j >= coins[i])
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1);
            else dp[i][j] = dp[i-1][j];
        }
    }
}

void traverse(int maxCoin, int n, vector<int> &result) {
    if((maxCoin == 0) || (n <= 0)) return;
    if(dp[maxCoin-1][n] >= dp[maxCoin][n-coins[maxCoin]]) {
        result.push_back(coins[maxCoin]);
        traverse(maxCoin, n-coins[maxCoin], result);
    }else{
        traverse(maxCoin-1, n, result);
    }
}

vector<int> ans;
void solve() {
    preProcess();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        ans.clear();
        traverse(coins.size()-1, n, ans);
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}