//
// Created by Mohit sharma on 13/11/19
// https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1

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
#include <utility>

using namespace std;
/* A binary tree node has data, pointer to left child and a pointer to
right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
// you are required to complete this function
// function should return the size of the
// Largest Independent set in the tree
int LISS(struct Node *root);
/* Driver program to test size function*/
int main()
{
    freopen("input_data.txt", "r", stdin);
    int t;
    struct Node *child;
    scanf("%d", &t);
    while (t--)
    {
        map<int, Node*> m;
        int n;
        scanf("%d",&n);
        struct Node *root = NULL;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2]  = child;
        }
        cout<<LISS(root)<<endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
// you are required to complete this function
// function should return the size of the
// Largest Independent set in the tree

map<pair<Node*, bool>, int> dp;

int maxSet(struct Node* node, bool canTakeNode) {
    if(node == NULL) return 0;
    pair<Node*, bool> pair = make_pair(node, canTakeNode);

    if(dp.find(pair) != dp.end()) return dp.find(pair)->second;

    int ans = 0;
    if(canTakeNode) {
        ans = (maxSet(node->left, !canTakeNode) + maxSet(node->right, !canTakeNode) + 1);
        ans = max(ans, maxSet(node->left, canTakeNode) + maxSet(node->right, canTakeNode));
    }else {
        ans = max(ans, maxSet(node->left, !canTakeNode) + maxSet(node->right, !canTakeNode));
    }

    dp.insert({pair, ans});
    int res = dp.find(pair)->second;
    return res;
}

int LISS(struct Node *root)
{
    dp.clear();
    int ans = max(maxSet(root, true), maxSet(root, false));
    return ans;
}