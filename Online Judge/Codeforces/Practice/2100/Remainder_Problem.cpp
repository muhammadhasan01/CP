#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int L = sqrt(N);

int q;
int t;
long long x, y;
long long a[N];
long long dp[L + 5][L + 5];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> q;
  while (q--) {
    cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (int i = 1; i <= L; i++) {
        dp[i][x % i] += y;
      }
    } else if (t == 2) {
      if (x <= L) {
        cout << dp[x][y] << '\n';
      } else {
        long long ans = 0;
        for (int i = y; i < N; i += x) {
          ans += a[i];
        }
        cout << ans << '\n';
      }
    }
  }

  return 0;
}