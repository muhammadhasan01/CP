#include<bits/stdc++.h>
using namespace std;

// Credits to : https://codeforces.com/profile/yoganteng

const int N = 3e5 + 5;
int n, a[N], p[N];
struct Trie {
    struct Node {
        Node *child[2];
        int cnt;
        Node() {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };

    Node *head;

    Trie() {
        head = new Node();
    }

    void insert(int val) {
        Node *cur = head;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            ++cur -> cnt;
            if (cur -> child[v] == NULL) {
                cur -> child[v] = new Node();
            }
            cur = cur -> child[v];
        }
        ++cur -> cnt;
    }

    void erase(int val) {
        Node *cur = head;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            --cur -> cnt;
            cur = cur -> child[v];
        }
        --cur -> cnt;
    }

    int getMinXOR(int val, int &id) {
        Node *cur = head;
        int res = 0, valz = val;
        for (int i = 30; i >= 0; i--) {
            bool v = val & (1 << i);
            if (cur -> child[v] != NULL && cur -> child[v] -> cnt != 0) {
                cur = cur -> child[v];
            } else {
                cur = cur -> child[v ^ 1];
                res += (1 << i);
                valz ^= (1 << i);
            }
        }
        id = lower_bound(p + 1, p + 1 + n, valz) - p;
        return res;
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Trie trie;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        trie.insert(p[i]);
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        int id = 0;
        int res = trie.getMinXOR(a[i], id);
        cout << res << (i == n ? '\n' : ' ');
        trie.erase(p[id]);
    }

    return 0;
}
