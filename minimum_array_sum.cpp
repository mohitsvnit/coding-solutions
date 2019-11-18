//
// Created by Mohit sharma on 14/11/19.
//

#include <iostream>
#include <string>
#include <queue>
#include <math.h>
using namespace std;

string input_format = "\n--------------- INPUT FORMAT ---------------\n"
                      "First Line: N K -> N: Number of array Elements, K: Number of operations\n"
                      "Second Line: a1 a2 a3 ... aN -> array elements\n"
                      "For Example: \n"
                      "3 4\n"
                      "10 20 7\n"
                      "------------------- END --------------------\n";

priority_queue<int> arr; // Max heap

int main() {
    cout << input_format << endl;

    int n, k, x;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.push(x);
    }
    int ele;
    for(int i = 0; i < k; i++) {
        ele = arr.top();
        arr.pop();
        ele = ceil((ele*1.0)/2.0);
        if(ele > 0) {
            arr.push(ele);
        }
        if(arr.empty()) {
            break;
        }
    }

    int ans = 0;
    while(!arr.empty()) {
        ans = ans + arr.top();
        arr.pop();
    }

    cout << ans << endl;


    return 0;
}

