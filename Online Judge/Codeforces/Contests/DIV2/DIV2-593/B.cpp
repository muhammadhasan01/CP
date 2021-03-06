#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9 + 7;
long long n, m;

long long fast(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) {
            ret = (ret * x) % M;
        }
        y >>= 1;
        x = (x * x) % M;
    }
    return (ret % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    long long g = ((fast(2, m) - 1) % M + M) % M;
    g = fast(g, n);
    cout << (g % M + M) % M << '\n';

    return 0;
}
