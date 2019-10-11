//
// Created by Mohit sharma on 11/09/19.
// https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence/0

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
#define MAX_SIZE 1005
string str;
string pat;

int dp[MAX_SIZE][MAX_SIZE];

int subsequenceCount(string S, string T)
{
    str = S;
    pat = T;
    memset(dp, 0, MAX_SIZE*MAX_SIZE* sizeof(int));

    for(int i = 0; i < str.length(); i++) dp[0][i] = 1;
    for(int i = 1; i <= pat.length(); i++) {
        for(int j = 1; j <= str.length(); j++) {
            if(str[j-1] != pat[i-1]){
                dp[i][j] = dp[i][j-1];
            }else{
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
        }
    }

    return dp[pat.length()][str.length()];
}


void solve() {
    int t;
    int n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> str >> pat;
        cout << subsequenceCount(str, pat) << endl;
    }
}




// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}