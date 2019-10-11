//
// Created by Mohit sharma on 28/09/19.
// https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference/0

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


void solve() {
    int t, n, k;
    int arr[105];
    int dp[105];
    cin >> t;
    int ans = 0;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        sort(arr, arr+n);
        ans = 0;
        dp[0] = 0;
        if(n > 1) {
            if(arr[1]-arr[0] < k) dp[1] = arr[0]+arr[1];
            else dp[1] = 0;
            for(int i = 2; i < n; i++) {
                dp[i] = dp[i-1];
                if(arr[i]-arr[i-1] < k) {
                    dp[i] = max(dp[i], dp[i-2]+arr[i]+arr[i-1]);
                }
            }
            ans = dp[n-1];
        }

        cout << ans << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}

