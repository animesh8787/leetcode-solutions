// Product of the Last K Numbers
// Difficulty: Medium   Solved: 2026-11-23
// https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
public:
    vector<int> pre;

    ProductOfNumbers() {
        pre.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            pre.clear();
            pre.push_back(1);
        } else {
            pre.push_back(pre.back() * num);
        }
    }

    int getProduct(int k) {
        int sz = pre.size();
        if (k >= sz) return 0;
        return pre.back() / pre[sz - 1 - k];
    }
};
