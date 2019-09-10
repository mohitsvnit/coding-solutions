//
// Created by Mohit sharma on 11/09/19.
//
// Question: https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0

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

ll dp[1005][2][3];

ll countNumberOfString(int n, int b, int c) {
    if(n == 0) return 1;
    if(dp[n][b][c] != -1) return dp[n][b][c];
    ll res = 0;
    res += countNumberOfString(n-1, b, c);
    if(b > 0) res += countNumberOfString(n-1, b-1, c);
    if(c > 0) res += countNumberOfString(n-1, b, c-1);
    dp[n][b][c] = res;
    return dp[n][b][c];
}

void solve() {
    int t, n;
    cin >> t;
    for(int i = 0; i < 1005; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 3; k++)
                dp[i][j][k] = -1;
    while(t--) {
        cin >> n;
        cout << countNumberOfString(n, 1, 2) << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}
