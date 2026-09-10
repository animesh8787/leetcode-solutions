// Implement Trie (Prefix Tree)
// Difficulty: Medium   Solved: 2026-09-10
// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                node->child[idx] = new Node();

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                return false;

            node = node->child[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (!node->child[idx])
                return false;

            node = node->child[idx];
        }

        return true;
    }
};
