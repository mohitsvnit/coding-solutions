//
// Created by Mohit sharma on 06/10/19.
// https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence/0

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
#define MAX_SIZE 1005
int arr[MAX_SIZE];
int dp1[MAX_SIZE];
int dp2[MAX_SIZE];
int dp1Max;
int dp2Max;


void solve() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;

        if(n <= 0) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < n; i++) cin >> arr[i];
        dp1[0] = 1;
        dp2[0] = 1;
        dp1Max = 1;
        dp2Max = 1;
        for (int i = 1; i < n; i++) {
            dp1[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (dp1[j] % 2 == 0) {
                    if(arr[i] < arr[j]) dp1[i] = max(dp1[i], dp1[j]+1);
                } else {
                    if(arr[i] > arr[j]) dp1[i] = max(dp1[i], dp1[j]+1);
                }
            }
            dp1Max = max(dp1Max, dp1[i]);
        }

        for (int i = 1; i < n; i++) {
            dp2[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (dp2[j] % 2 != 0) {
                    if(arr[i] < arr[j]) dp2[i] = max(dp2[i], dp2[j]+1);
                } else {
                    if(arr[i] > arr[j]) dp2[i] = max(dp2[i], dp2[j]+1);
                }
            }
            dp2Max = max(dp2Max, dp2[i]);
        }

        cout << max(dp1Max, dp2Max) << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}
