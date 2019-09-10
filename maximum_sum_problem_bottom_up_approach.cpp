//
// Created by Mohit sharma on 08/09/19.
//
// Question: https://practice.geeksforgeeks.org/problems/maximum-sum-problem/0

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
#define MAX_SIZE 100500
ll memo[MAX_SIZE];

//ll max_sum(ll n) {
//    if(n <= 2) return n;
//    if(memo[n] != -1);
//    ll ans = max(n, max_sum(n/2) + max_sum(n/3) + max_sum(n/4));
//    memo[n] = ans;
//    return memo[n];
//}


void solve() {
    int t = 0;
    ll n = 0;
    cin >> t;

    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 3;
    for(ll i = 4; i < MAX_SIZE; i++) {
        memo[i] = max(i, max(memo[i/2],i/2)+max(memo[i/3], i/3)+max(memo[i/4], i/4));
    }

    while(t--) {
        cin >> n;
        cout << memo[n] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}