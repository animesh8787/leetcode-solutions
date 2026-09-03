// Accounts Merge
// Difficulty: Medium   Solved: 2026-09-03
// https://leetcode.com/problems/accounts-merge/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return;

            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;
        };

        unordered_map<string, int> emailOwner;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailOwner.count(email))
                    unite(i, emailOwner[email]);
                else
                    emailOwner[email] = i;
            }
        }

        unordered_map<int, vector<string>> groups;

        for (auto &[email, owner] : emailOwner) {
            groups[find(owner)].push_back(email);
        }

        vector<vector<string>> result;

        for (auto &[root, emails] : groups) {
            sort(emails.begin(), emails.end());

            vector<string> account;
            account.push_back(accounts[root][0]);

            for (auto &email : emails)
                account.push_back(email);

            result.push_back(account);
        }

        return result;
    }
};
