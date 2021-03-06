#include <bits/stdc++.h>

using namespace std;

const int N = 35005;

int n, k;
int a[N];
int pre[N], last[N], dp[N];
int t[4 * N], lazy[4 * N];

void build(int v, int s, int e) {
    lazy[v] = 0;
    if (s == e) {
        t[v] = dp[s - 1];
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

void push(int v, int s, int e) {
    if (s == e) return;
    if (lazy[v] == 0) return;
    t[v << 1] += lazy[v];
    t[v << 1 | 1] += lazy[v];
    lazy[v << 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int s, int e, int l, int r) {
    if (l > r) return;
    if (l == s && e == r) {
        t[v] += 1;
        lazy[v] += 1;
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    update(v << 1, s, mid, l, min(mid, r));
    update(v << 1 | 1, mid + 1, e, max(mid + 1, l), r);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (l > r) return 0;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    return max(get(v << 1, s, mid, l, min(mid, r)),
               get(v << 1 | 1, mid + 1, e, max(mid + 1, l), r));
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }
    for (int i = 1; i <= k; i++) {
        build(1, 1, n);
        for (int j = 1; j <= n; j++) {
            update(1, 1, n, pre[j] + 1, j);
            dp[j] = get(1, 1, n, 1, j);
        }
    }
    cout << dp[n] << '\n';

    return 0;
}


