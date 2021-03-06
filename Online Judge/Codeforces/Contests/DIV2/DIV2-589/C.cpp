#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
long long x, n;

long long fast(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % M;
        }
        y >>= 1;
        x = (x * x) % M;
    }
    return (res % M + M) % M;
}

long long g(long long p) {
    long long ret = 0;
    long long m = n;
    while (m > 0) {
        ret += (m / p);
        m /= p;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> n;
    long long res = 1;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = (res * fast(i, g(i))) % M;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        res = (res * fast(x, g(x))) % M;
    }
    cout << (res % M + M) % M << '\n';

    return 0;
}
