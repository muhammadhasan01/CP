#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, d;

long long ceil(long long x, long long y) {
  return (x + y - 1) / y;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> d;
    long long l = 0, r = n, ans = 0;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (mid * mid <= d) {
        l = mid + 1;
        ans = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << (n >= (ans - 1) + ceil(d, ans) ? "YES" : "NO") << '\n';
  }

  return 0;
}
