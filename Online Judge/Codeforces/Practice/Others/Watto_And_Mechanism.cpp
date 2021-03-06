#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 5;
const int P = 7e5 + 5;
const int M = 1e9 + 7;
int pr[3] = {-1, 31, 37};
int n, m;
string a[N];
ll pre[P][3], hsh[N][3];
set<pair<ll, ll>> s1[4], s2[4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0][1] = pre[0][2] = 1;
    for (int i = 1; i <= P - 5; i++) {
        for (int t = 1; t <= 2; t++) {
            pre[i][t] = pre[i - 1][t] * pr[t];
            pre[i][t] %= M;
        }
    }

    cin >> n >> m;
    int len = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int k = s.size();
        hsh[k + 1][1] = hsh[0][1] = hsh[k + 1][2] = hsh[0][2] = 0;
        for (int t = 1; t <= 2; t++) {
            for (int i = 1; i <= k; i++) {
                hsh[i][t] = hsh[i - 1][t] + (s[i - 1] - 'a' + 1) * pre[i][t];
                hsh[i][t] %= M;
            }
            for (int i = 1; i <= k; i++) {
                int pos = s[i - 1] - 'a';
                ll cur = ((hsh[k][t] - hsh[i][t]) % M + M) % M;
                if (t == 1) s1[pos].insert({hsh[i - 1][t], cur});
                else if (t == 2) s2[pos].insert({hsh[i - 1][t], cur});
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        int k = s.size();
        hsh[k + 1][1] = hsh[0][1] = hsh[k + 1][2] = hsh[0][2] = 0;
        for (int t = 1; t <= 2; t++) {
            for (int i = 1; i <= k; i++) {
                hsh[i][t] = hsh[i - 1][t] + (s[i - 1] - 'a' + 1) * pre[i][t];
                hsh[i][t] %= M;
            }
        }
        bool ok = false;
        for (int i = 1; i <= k; i++) {
            int pos = s[i - 1] - 'a';
            ll cur1 = ((hsh[k][1] - hsh[i][1]) % M + M) % M;
            ll cur2 = ((hsh[k][2] - hsh[i][2]) % M + M) % M;
            for (int j = 0; j < 3; j++) {
                if (pos == j) continue;
                if (s1[j].find({hsh[i - 1][1], cur1}) == s1[j].end()) continue;
                if (s2[j].find({hsh[i - 1][2], cur2}) == s2[j].end()) continue;
                ok = true;
                if (ok) break;
            }
            if (ok) break;
        }
        puts(ok ? "YES" : "NO");
    }

    return 0;
}
