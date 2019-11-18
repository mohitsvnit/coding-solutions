//
// Created by Mohit sharma on 29/10/19.
// https://practice.geeksforgeeks.org/problems/high-effort-vs-low-effort/0

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <limits.h>
using namespace std;
#define FAST_INPUT_OUTPUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Write your code below

#define MAX_SIZE 100050

int hi[MAX_SIZE];
int li[MAX_SIZE];
int dp[MAX_SIZE][2];
int size = 0;
int maxWork(int ind, bool canHigh) {
    if(ind == size) return 0;
    if(dp[ind][canHigh] != -1) return dp[ind][canHigh];
    int ans = 0;
    if(canHigh) {
        ans = max(ans, maxWork(ind+1, false) + hi[ind]);
    }

    ans = max(ans, maxWork(ind+1, false) + li[ind]);
    ans = max(ans, maxWork(ind+1, true));

    dp[ind][canHigh] = ans;
    return dp[ind][canHigh];
}

int maxWorkB2T() {
    if(size <= 0) return 0;
    dp[0][0] = 0;

    dp[1][0] = max(hi[0], li[0]);

    for(int i = 2; i <= size; i++) {
        dp[i][0] = max(dp[i-1][0]+li[i-1], dp[i-2][0]+hi[i-1]);
    }

    return dp[size][0];

}

void solve() {
    int t;
    cin >> t;
    //memset(dp, -1, MAX_SIZE*2* sizeof(int));
    while(t--) {
        cin >> size;
        for(int i = 0; i < size; i++) cin >> hi[i];
        for(int i = 0; i < size; i++) cin >> li[i];
        cout << maxWorkB2T() << endl;
        //memset(dp, -1, size*2* sizeof(int));
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}