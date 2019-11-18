//
// Created by Mohit sharma on 13/11/19
// https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0

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


void solve() {
    int t, a, b, c;
    string str;
    cin >> t;
    while (t--) {
        a = b = c = 0;
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            switch(str[i]){
                case 'a':
                    a += (a+1);
                    break;
                case 'b':
                    b += (a+b);
                    break;
                case 'c':
                    c += (b+c);
                    break;
            }
        }
        cout << c << endl;
    }
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    freopen("./input_data.txt", "r", stdin);
    solve();
    return 0;
}