//
// Created by Mohit sharma on 2019-08-22.
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

void swap(vector<int> &arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int getPivot(vector<int> &arr, int start, int end) {
    int pivot = end-1;
    int i = start-1;
    int j = start;
    while(j < pivot) {
        if(arr[j] < arr[pivot]) {
            i+=1;
            swap(arr,i,j);
        }
        j+=1;
    }
    i+=1;
    swap(arr, i, pivot);
    return i;
}

void quickSort(vector<int> &arr, int start, int end) {
    if((end-start) <= 1) return;
    int pivot = getPivot(arr, start, end);
    quickSort(arr,start, pivot);
    quickSort(arr, pivot+1, end);
}



void solve() {
    vector<int> arr = {3,6,98,192,345,285,94,3989,23,45,2,311};
    quickSort(arr,0,arr.size());
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}


// END Code
int main() {
    FAST_INPUT_OUTPUT;
    solve();
    return 0;
}