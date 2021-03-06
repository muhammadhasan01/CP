#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int M = 1e9 + 7;
int n;
int a[N];
ll ans = 1;
vector<int> g[N];
int tin[N], low[N], tim;
stack<int> st;
bool onStack[N];

ll fast(ll x, int y) {
  ll ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return (ret % M + M) % M;
}

void tarjan(int u) {
  tin[u] = low[u] = ++tim;
  onStack[u] = 1;
  st.push(u);
  for (auto v : g[u]) {
    if (tin[v] == 0) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (onStack[v]) {
      low[u] = min(low[u], tin[v]);
    }
  }
  if (low[u] == tin[u]) {
    int w = 0, cnt = 0;
    do {
      w = st.top(); st.pop();
      onStack[w] = false;
      cnt++;
    } while (w != u && !st.empty());
    if (cnt == 1) {
      ans = (ans * 2) % M;
    } else {
      ans = (ans * (fast(2, cnt) - 2)) % M;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g[i].push_back(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!tin[i])
      tarjan(i);
  }
  cout << (ans % M + M) % M << '\n';

  return 0;
}
