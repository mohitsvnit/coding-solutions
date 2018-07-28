// Question link: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/little-deepu-and-array/

#include <bits/stdc++.h>
#define scan(i) scanf("%d",&i)
#define print(i) printf("%d\n", i)
#define ll long long
using namespace std;
#define INF 1<<30
int maxi(int a, int b){ return a>b?a:b; }
int mini(int a, int b){return a< b?a:b;}

#define MAXLEN 15//200500

typedef struct {
    int start = -1;
    int end = -1;
    int evenCount = 0;
    int oddCount = 0;

} Node;

Node nodes[MAXLEN];
int ind;
int evenArray[MAXLEN];
int oddArray[MAXLEN];
int arr[MAXLEN];

void createSegmentedTree(int node, int low, int high);

int query(int currentNode, int low, int high, int type){
    int start = nodes[currentNode].start;
    int end = nodes[currentNode].end;

    if(start >= low && end <= high){
        if(type == 1) return nodes[currentNode].evenCount;
        else return nodes[currentNode].oddCount;
    }else if(end < low || start > high){
        return 0;
    }else{
        return query(currentNode*2+1, low, high, type) + query(currentNode*2+2, low, high, type);
    }
}

void update(int currentNode, int ind){
    int start = nodes[currentNode].start;
    int end = nodes[currentNode].end;

    if(start == end && start == ind){
        if(arr[ind]%2 == 0){
            nodes[currentNode].evenCount = 1;
            nodes[currentNode].oddCount = 0;
        }else{
            nodes[currentNode].evenCount = 0;
            nodes[currentNode].oddCount = 1;
        }
    }else {

        int mid = start + (end - start) / 2;
        if (mid >= ind) {
            update(currentNode*2 + 1, ind);
        } else {
            update(currentNode*2 + 2, ind);
        }

        nodes[currentNode].oddCount = nodes[currentNode*2+1].oddCount + nodes[currentNode*2 + 2].oddCount;
        nodes[currentNode].evenCount = nodes[currentNode*2+1].evenCount + nodes[currentNode*2+2].evenCount;
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc, i, j, k, n, q, x, y, l, r;
    scan(n);
    evenArray[0] = 0;
    oddArray[0] = 0;
    for(i = 0; i < n; i++){
        scan(arr[i]);
    }

    ind = 0;
    createSegmentedTree(0, 0, n-1);

    scan(q);
    int ans;
    while(q--){
        scan(r);
        scan(x);
        scan(y);

        switch(r){
            case 0:
                arr[x-1] = y;
                update(0, x-1);
                break;
            case 1:
                ans = query(0, x-1, y-1, 1);
                print(ans);
                break;
            case 2:
                ans = query(0, x-1, y-1, 2);
                print(ans);
                break;
        }
    }


    return 0;
}

void createSegmentedTree(int node, int low, int high) {

    if(low != high){
        int mid = low + ((high-low)/2);
        createSegmentedTree(node*2 + 1, low, mid);
        createSegmentedTree(node*2 + 2, mid+1, high);
        nodes[node].start = low;
        nodes[node].end = high;

        nodes[node].oddCount = nodes[node*2+1].oddCount + nodes[node*2 + 2].oddCount;
        nodes[node].evenCount = nodes[node*2+1].evenCount + nodes[node*2+2].evenCount;
    }else{
        nodes[node].start = low;
        nodes[node].end = high;
        if(arr[low]%2 == 0 && arr[low] != 1){
            nodes[node].evenCount = 1;
            nodes[node].oddCount = 0;
        }else{
            nodes[node].oddCount = 1;
            nodes[node].evenCount = 0;
        }
    }
}




