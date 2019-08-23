//
// Created by Mohit sharma on 2019-08-23.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define FAST_INPUT_OUTPUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Write your code below

int binarySearch(vector<int> &arr, int val) {
    int low = 0, high = arr.size(), mid = 0;
    while((high-low) > 1) {
        mid = low + (high-low)/2;
        if(arr[mid] <= val) {
            low = mid;
        }else{
            high = mid;
        }
    }
    return arr[low] == val?low:-1;
}

void solve() {
    vector<int> arr = {2,4,5,7,9,12,15,25};
    cout << binarySearch(arr, 5) << endl;
    cout << binarySearch(arr, 25) << endl;
    cout << binarySearch(arr, 2) << endl;
    cout << binarySearch(arr, 1) << endl;
    cout << binarySearch(arr, 30) << endl;
    cout << binarySearch(arr, -5) << endl;

}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    solve();
    return 0;
}