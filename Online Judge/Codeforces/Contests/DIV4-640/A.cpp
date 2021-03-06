#include <bits/stdc++.h>

using namespace std;

int tc;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> ha(10);
    ha[0] = 1;
    for (int i = 1; i < 10; i++) {
        ha[i] = 10 * ha[i - 1];
    }
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        vector<int> ans;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                int cur = s[i] - '0';
                ans.push_back(cur * ha[n - i - 1]);
            }
        }
        cout << ans.size() << '\n';
        for (auto& e : ans) {
            cout << e << " ";
        }
        cout << '\n';
    }

    return 0;
}