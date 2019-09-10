//
// Created by Mohit sharma on 11/09/19.
//
// Question: https://practice.geeksforgeeks.org/problems/number-of-unique-paths/0

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
ll mat[20][20];

void solve() {
    int t, r, c;
    cin >> t;
    while(t--) {
        cin >> r >> c;
        mat[1][1] = 1;
        int st = 2;
        for(int i = 1; i <= r; i++) {
            for(int j = st; j <= c; j++) {
                mat[i][j] = mat[i][j-1]+mat[i-1][j];
            }
            st = 1;
        }

        cout << mat[r][c] << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}