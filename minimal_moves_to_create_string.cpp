//
// Created by Mohit sharma on 22/09/19.
// https://practice.geeksforgeeks.org/problems/minimal-moves-to-form-a-string/0

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <string.h>
using namespace std;
#define FAST_INPUT_OUTPUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Write your code below
#define MAX_SIZE 100500

int dp[MAX_SIZE];

void solve() {
    int t;
    string str;
    cin >> t;
    while(t--) {
        cin >> str;
        dp[0] = 1;
        for(int i = 1; i < str.length(); i++) {
            if(i%2 == 0) dp[i] = dp[i-1]+1;
            else {
                if(str.substr(0,i/2+1) == str.substr(i/2+1, i/2+1)) dp[i] = min(dp[i-1]+1, dp[i/2]+1);
                else dp[i] = dp[i-1]+1;
            }
        }
        cout << dp[str.length()-1] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}