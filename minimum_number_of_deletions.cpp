//
// Created by Mohit sharma on 31/10/19
// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions/0

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

void solve() {
    int t, n, l;
    cin >> t;
    string str;
    memset(dp, 0, MAX_SIZE*MAX_SIZE* sizeof(int));
    while(t--) {
        cin >> n;
        cin >> str;
        l = str.length()+1;
        for(int i = 1; i < l; i++) {
            for(int j = 1; j < l; j++) {
                if(str[i-1] == str[l-1-j]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        cout << l-1-dp[l-1][l-1] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}