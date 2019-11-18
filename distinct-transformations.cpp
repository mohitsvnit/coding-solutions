//
// Created by Mohit sharma on 18/11/19
// https://practice.geeksforgeeks.org/problems/distinct-transformations/0

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

#define MAX_SIZE_A 1050
#define MAX_SIZE_B 105

int dp[MAX_SIZE_A][MAX_SIZE_B];

void solve() {
    int t;
    string s1, s2;
    cin >> t;
    for(int i = 0; i < MAX_SIZE_B; i++) dp[0][i] = 0;
    for(int i = 0; i < MAX_SIZE_A; i++) dp[i][0] = 1;
    while(t--) {
        cin >> s1 >> s2;
        for(int i = 1; i <= s1.length(); i++) {
            for(int j = 1; j <= s2.length(); j++) {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        cout << dp[s1.length()][s2.length()] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}