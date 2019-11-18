//
// Created by Mohit sharma on 17/11/19
// https://practice.geeksforgeeks.org/problems/unique-bsts/1

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
#define ll long long int
#define MAX_SIZE 13
ll dp[MAX_SIZE];

void preProcess() {
    dp[0] = dp[1] = 1;
    for(int i = 2; i < MAX_SIZE; i++) {
        ll count = 0;
        for(int j = 1; j <= i; j++) {
            count+= ((dp[j-1])*(dp[i-j]));
        }
        dp[i] = count;
    }
}

void solve() {
    preProcess();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}