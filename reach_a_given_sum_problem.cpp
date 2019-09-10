//
// Created by Mohit sharma on 10/09/19.
//
// Question: https://practice.geeksforgeeks.org/problems/reach-a-given-score/0

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

vector<vector<int>> dp;
vector<int> points = {0,3,5,10};
void solve() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        n+=1;
        dp.clear();
        dp.resize(points.size(), vector<int>(n));
        for(int i = 0; i < n; i++) dp[0][i] = 0;
        for(int i = 0; i < points.size(); i++) dp[i][0] = 1;

        for(int i = 1; i < points.size(); i++) {
            for(int j = 1; j < n; j++) {
                if(j < points[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-points[i]];
            }
        }

        cout << dp[points.size()-1][n-1] << endl;

    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}