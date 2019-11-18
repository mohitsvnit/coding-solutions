//
// Created by Mohit sharma on 30/10/19
// https://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number/0

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

ll factor[] = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111, 11111111111, 111111111111};

ll sumOfAllSubstring(ll num) {
    ll ans = 0;
    ll lastSum = 0;
    ll currentSum = 0;
    int ind = 0;
    while(num > 0) {
        ind+=1;
        lastSum = (num%10)*factor[ind] + lastSum;
        ans+=lastSum;
        num/=10;
    }

    return ans;
}

void solve() {
    int t;
    ll num;
    cin >> t;
    while(t--) {
        cin >> num;
        cout << sumOfAllSubstring(num) << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}