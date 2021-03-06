#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int k = s.size();
        vector<char> ans;
        for (int i = 0; i < 26; i++) {
            char x = char(int('a') + i);
            int l = 0;
            bool ok = false;
            for (int j = 0; j < k; j++) {
                if (s[j] == x) {
                    l++;
                } else {
                    if (l & 1) {
                        ok = true;
                        break;
                    }
                    l = 0;
                }
            }
            if (l & 1) ok = true;
            if (ok) ans.push_back(x);
        }
        sort(ans.begin(), ans.end());
        for (auto e : ans) cout << e;
        cout << '\n';
    }


    return 0;
}
