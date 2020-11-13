#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/** END OF TEMPLATE DEBUGGER **/

const int N = 1e3 + 5;

int n;
int a[N];
vector<pair<int, int>> p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) {
                p[i].emplace_back(a[j], j);
                ++cnt;
            }
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        sort(p[i].begin(), p[i].end());
        for (int j = (int) p[i].size() - 1; j >= 0; j--) {
            cout << i << ' ' << p[i][j].second << '\n';
        }
    }

    return 0;
}