#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
long long t;
long long a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> t;
  long long tim = 86400;
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    t -= (tim - a[i]);
    if (t <= 0) {
      ans = min(ans, i);
    }
  }
  cout << ans << '\n';

  return 0;
}
