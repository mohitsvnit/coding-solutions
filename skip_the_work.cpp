//
// Created by Mohit sharma on 11/09/19.
// https://practice.geeksforgeeks.org/problems/skip-the-work/0

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
#define ll long long int

int arr[40];
int N;

void solve() {
    int t;
    cin >> t;
    ll a, b, c;
    while(t--) {
        cin >> N;
        for(int i = 0; i < N; i++) cin >> arr[i];

        a = 0;
        b = arr[0];
        for(int i = 1; i < N; i++) {
            c = b;
            b = arr[i]+min(a, b);
            a = c;
        }
        cout << min(a,b) << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}
