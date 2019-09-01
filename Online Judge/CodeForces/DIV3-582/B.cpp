#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int tc;
int n, a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int mins = a[n];
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] > mins) {
                ans++;
            }
            mins = min(mins, a[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}
