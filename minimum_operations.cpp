//
// Created by Mohit sharma on 14/09/19.
//

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
ll dp[10500];

void solve() {
    int t, n;
    cin >> t;
    dp[0] = 0;
    for(int i = 1; i < 10500; i++) {
        if(i%2==0) dp[i] = min(dp[i-1], dp[i/2])+1;
        else dp[i] = dp[i-1]+1;
    }
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

