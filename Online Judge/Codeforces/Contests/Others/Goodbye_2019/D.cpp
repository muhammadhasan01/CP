#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int n, k;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= k + 1; i++) {
    cout << "? ";
    for (int j = 1; j <= k + 1; j++)
      if (i != j) cout << j << " ";
    cout << endl;
    int pos;
    cin >> pos >> a[i];
  }
  int maks = a[1];
  for (int i = 2; i <= k + 1; i++) {
    maks = max(maks, a[i]);
  }
  int m = 0;
  for (int i = 1; i <= k + 1; i++) {
    if (a[i] == maks) m++;
  }
  cout << "! " << m << endl;

  return 0;
}
