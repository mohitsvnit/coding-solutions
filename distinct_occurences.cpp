//
// Created by Mohit sharma on 11/09/19.
// https://practice.geeksforgeeks.org/problems/distinct-occurrences/1

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

string str;
string pat;

int dp[110][110];

int distinctOccurences(int ind, int patLen) {
    if(patLen == pat.length()) return 1;
    if(ind >= str.length()) return 0;
    if(dp[ind][patLen] != -1) return dp[ind][patLen];
    int ans = 0;
    if(str[ind] == pat[patLen]){
        ans += distinctOccurences(ind+1, patLen+1);
    }
    ans+= distinctOccurences(ind+1, patLen);
    dp[ind][patLen] = ans;
    return dp[ind][patLen];
}

int subsequenceCount(string S, string T)
{
    str = S;
    pat = T;
    memset(dp, 0, 110*110* sizeof(int));

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
    cin >> t;
    while(t--) {
        cin >> str >> pat;
        memset(dp, -1, 110*110* sizeof(int));
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