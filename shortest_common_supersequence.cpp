//
// Created by Mohit sharma on 24/09/19.
// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;
#define FAST_INPUT_OUTPUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Write your code below
int dp[105][105];
string a, b;
int getShortestSuperSequenceLength(int x, int y) {
    if(x == a.length() && y == b.length()) return 0;
    if(x == a.length()) return b.length()-y;
    if(y == b.length()) return a.length()-x;

    if(dp[x][y] != -1) return dp[x][y];

    int res = 0;
    if(a[x] == b[y]) res = getShortestSuperSequenceLength(x+1, y+1)+1;
    else res = min(getShortestSuperSequenceLength(x+1, y), getShortestSuperSequenceLength(x,y+1)) + 1;
    dp[x][y] = res;
    return dp[x][y];
}
void solve() {
    int t;
    cin >> t;
    for(int i = 0; i < 105; i++) dp[0][i] = dp[i][0] = i;
    while(t--) {
        cin >> a >> b;
        for(int i = 1; i <= a.length(); i++) {
            for(int j = 1; j <= b.length(); j++) {
                dp[i][j] = 0;
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[a.length()][b.length()] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}