//
// Created by Mohit sharma on 04/11/19
// https://practice.geeksforgeeks.org/problems/temple-offerings/0

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

#define MAX_SIZE 1000500

int arr[MAX_SIZE];
int offerings[MAX_SIZE];

void solve() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        memset(offerings, 0, n* sizeof(int));
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }

        offerings[0] = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) offerings[i] = offerings[i-1]+1;
            else offerings[i] = 1;
        }

        for(int i = n-2; i >= 0; i--) {
            if(arr[i] > arr[i+1]) offerings[i] = max(offerings[i], offerings[i+1]+1);
            else offerings[i] = max(offerings[i], 1);
        }


        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += offerings[i];
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