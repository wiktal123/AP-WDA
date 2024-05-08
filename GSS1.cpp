#include <bits/stdc++.h>

using namespace std;

struct Node {
    int totalSum, prefixMaxSum, suffixMaxSum, maxSubarraySum;
    Node() {}
    Node(int val) {
        totalSum = maxSubarraySum = prefixMaxSum = suffixMaxSum = val;
    }
};

int const N = 5e4+1;
int n, mid, arr[N], l, r;
Node tree[N*4];

Node merge(Node left, Node right) {
    Node parent;
    parent.totalSum = left.totalSum + right.totalSum;
    parent.prefixMaxSum = max(left.prefixMaxSum, left.totalSum + right.prefixMaxSum);
    parent.suffixMaxSum = max(right.suffixMaxSum, right.totalSum + left.suffixMaxSum);
    parent.maxSubarraySum = max({left.maxSubarraySum, right.maxSubarraySum, left.suffixMaxSum + right.prefixMaxSum});
    return parent;
}

void create_tree( int node, int start, int end) {
    if (start == end) {
        tree[node] = Node(arr[start]);
        return;
    } else {
        int mid = (start + end) / 2;
        create_tree( 2 * node, start, mid);
        create_tree( 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

Node query(int node, int start, int end) {
    if (r < start || l > end)
        return Node(-9999999); 

    if (l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    return merge(query(2 * node, start, mid), query(2 * node + 1, mid + 1, end));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    
    create_tree(1, 1, n);
    
    cin >> mid;
    while (mid--!=0) {
        cin >> l >> r;
        Node result = query(1, 1, n);
        cout << result.maxSubarraySum << '\n';
    }
    return 0;
}
