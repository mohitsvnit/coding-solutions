//
// Created by Mohit sharma on 11/11/19
// https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1

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
#define MAX_SIZE 100050
ll dp[MAX_SIZE];

void preProcess(){
    dp[0] = dp[1] = 1;
    for(int i = 2; i < MAX_SIZE; i++) {
        dp[i] = dp[i-2] + 1;
    }
}

void solve() {
    int t, n;
    preProcess();
    cin >> t;
    while(t--){
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