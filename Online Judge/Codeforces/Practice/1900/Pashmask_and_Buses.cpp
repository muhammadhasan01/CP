#include <bits/stdc++.h>
using namespace std;

int n, k, d;
vector<deque<int>> ans;

void bf(deque<int> temp, int cnt) {

    if (cnt == d) {
        ans.push_back(temp);
        if ((int)ans.size() == n) {
            for (int i = 0; i < d; i++) {
                for (int j = 0; j < n; j++) {
                    cout << ans[j][i] << (j == n - 1 ? '\n' : ' ');
                }
            }
            exit(0);
        }
        return;
    }

    for (int i = 1; i <= k; i++) {
        temp.push_back(i);
        bf(temp, cnt + 1);
        temp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> d;
    deque<int> t;
    bf(t, 0);

    if ((int)ans.size() < n) {
        cout << -1 << '\n';
        return 0;
    }

    return 0;
}
