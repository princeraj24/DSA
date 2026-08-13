class Solution {
public:

    struct Node {
        int len;
        int longest;
        int pref;
        int suff;
        char left;
        char right;

        Node() {
            len = 0;
            longest = 0;
            pref = 0;
            suff = 0;
            left = 0;
            right = 0;
        }

        Node(int len, int longest, int pref, int suff, char left, char right) {
            this->len = len;
            this->longest = longest;
            this->pref = pref;
            this->suff = suff;
            this->left = left;
            this->right = right;
        }
    };

    // Make merge static
    static Node merge(Node &L, Node &R) {

        int len = L.len + R.len;

        int longest = max(L.longest, R.longest);

        bool canJoin = (L.right == R.left);

        if(canJoin) {
            longest = max(longest, L.suff + R.pref);
        }

        int pref = L.pref;

        if(L.pref == L.len && canJoin) {
            pref += R.pref;
        }

        int suff = R.suff;

        if(R.suff == R.len && canJoin) {
            suff += L.suff;
        }

        return Node(
            len,
            longest,
            pref,
            suff,
            L.left,
            R.right
        );
    }

    class SegTree {
    public:

        int n;
        int size;

        vector<Node> tree;

        SegTree(string &s) {

            n = s.size();

            size = 1;

            while(size < n) {
                size *= 2;
            }

            tree.resize(2 * size);

            // Build leaves
            for(int i = 0; i < n; i++) {

                char c = s[i];

                tree[size + i] = Node(
                    1,
                    1,
                    1,
                    1,
                    c,
                    c
                );
            }

            // Build tree
            for(int i = size - 1; i >= 1; i--) {

                tree[i] = merge(
                    tree[2 * i],
                    tree[2 * i + 1]
                );
            }
        }

        void update(int idx, char c) {

            idx += size;

            tree[idx] = Node(
                1,
                1,
                1,
                1,
                c,
                c
            );

            idx /= 2;

            while(idx >= 1) {

                tree[idx] = merge(
                    tree[2 * idx],
                    tree[2 * idx + 1]
                );

                idx /= 2;
            }
        }

        int getLongest() {
            return tree[1].longest;
        }
    };

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        SegTree seg(s);

        int k = queryIndices.size();

        vector<int> ans(k);

        for(int i = 0; i < k; i++) {

            seg.update(
                queryIndices[i],
                queryCharacters[i]
            );

            ans[i] = seg.getLongest();
        }

        return ans;
    }
};