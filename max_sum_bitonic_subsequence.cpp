//
// Created by Mohit sharma on 18/09/19.
// https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0

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

int dplr[60]; // max sum increasing order from left to right
int dprl[60]; // max sum increasing order from right to left

void solve() {
    int t,n, arr[60];
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < n; i++){
            dplr[i] = arr[i];
            for(int j = i-1; j >= 0; j--) if(arr[j] < arr[i]) dplr[i] = max(dplr[i], dplr[j]+arr[i]);
        }

        for(int i = n-1; i >= 0; i--){
            dprl[i] = arr[i];
            for(int j = i+1; j < n; j++) if(arr[j] < arr[i]) dprl[i] = max(dprl[i], dprl[j]+arr[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, dplr[i]+dprl[i]-arr[i]);
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