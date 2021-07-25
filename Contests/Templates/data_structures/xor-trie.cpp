struct Trie {
    static const int K = 2;

    struct Node {
        int next[K];
        int cnt = 0;

        Node() {
            fill(begin(next), end(next), -1);
        }
    };

    vector<Node> trie;

    Trie() {
        trie = vector<Node>(1);
    }

    void insert(const int &num) {
        int v = 0;
        for(int bit = 30; bit >= 0; bit--) {
            int parity = (num >> bit) & 1;
            if(trie[v].next[parity] == -1) {
                trie[v].next[parity] = int(trie.size());
                trie.emplace_back();
            }
            v = trie[v].next[parity];
            trie[v].cnt++;
        }
    }

    void remove(const int &num) {
        int v = 0;
        for(int bit = 30; bit >= 0; bit--) {
            int parity = (num >> bit) & 1;
            v = trie[v].next[parity];
            trie[v].cnt--;
        }
    }

    int max_xor(const int &num) {
        int ans = 0;
        int v = 0;
        for(int bit = 30; bit >= 0; bit--) {
            int parity = (num >> bit) & 1;
            int nxt = trie[v].next[!parity];
            if(nxt != -1 && trie[nxt].cnt > 0) {
                ans += (1 << bit);
                v = nxt;
            } else {
                v = trie[v].next[parity];
            }
        }
        return ans;
    }
};