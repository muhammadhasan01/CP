#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n, k;
int a[N];
int pre[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 2; i <= n - 1; i++) {
            pre[i] = pre[i - 1];
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                pre[i]++;
            }
        }
        int ans = 0;
        int idx = 1;
        for (int i = 1; i <= n - k + 1; i++) {
            int cur = pre[max(i, i + k - 2)] - pre[i];
            if (cur > ans) {
                ans = cur;
                idx = i;
            }
        }
        cout << ans + 1 << " " << idx << '\n';
    }

    return 0;
}