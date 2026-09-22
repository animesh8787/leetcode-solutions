// Find X Value of Array II
// Difficulty: Hard   Solved: 2026-09-22
// https://leetcode.com/problems/find-x-value-of-array-ii/

class Solution {
public:
    struct Node {
        int prod;
        int pref[5];
    };

    int k;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res{};
        res.prod = (a.prod * b.prod) % k;

        for (int i = 0; i < k; i++)
            res.pref[i] = a.pref[i];

        for (int i = 0; i < k; i++) {
            int r = (a.prod * i) % k;
            res.pref[r] += b.pref[i];
        }

        return res;
    }

    Node makeNode(int x) {
        Node res{};
        res.prod = x % k;
        res.pref[res.prod] = 1;
        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[node] = makeNode(nums[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = makeNode(val);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        if (r < ql || qr < l) {
            Node empty{};
            empty.prod = 1;
            return empty;
        }

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.pref[x]);
        }

        return ans;
    }
};
