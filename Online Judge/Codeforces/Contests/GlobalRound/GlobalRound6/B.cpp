#include <bits/stdc++.h>

using namespace std;

int tc;
long long x;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> x;
    int k = x % 14;
    cout << (x >= 15 && 1 <= k &&  k <= 6 ? "YES" : "NO") << '\n';
  }

  return 0;
}
