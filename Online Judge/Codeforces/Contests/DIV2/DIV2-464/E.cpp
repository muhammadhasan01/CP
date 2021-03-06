#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int Q;
long double p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(10);

    cin >> Q;
    long double sum = 0, n = 1, maks = 0, last = 0;
    int k = 0, cur = 1;
    while (Q--) {
        int q;
        cin >> q;
        if (q == 1) {
            long long x;
            cin >> x;
            p[++k] = x;
            maks = x;
        } else if (q == 2) {
            sum -= last;
            sum += maks;
            while (cur < k) {
                if (p[cur] * n < sum) {
                    sum += p[cur];
                    cur++;
                    n++;
                } else {
                    break;
                }
            }
            cout << maks - (long double) sum / n << '\n';
            last = maks;
        }
    }

    return 0;
}
