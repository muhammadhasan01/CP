#include <bits/stdc++.h>

using namespace std;

int tc, n;
string t, rt;
string pre, suf;
string ans;

vector<int> LPS(const string& s) {
  int m = s.size();
  vector<int> lps(m);
  for (int i = 1, j = 0; i < m; i++) {
    j = lps[i - 1];
    while (j > 0 && s[j] != s[i]) j = lps[j - 1];
    if (s[j] == s[i]) j++;
    lps[i] = j;
  }
  return lps;
}

void checkFront(const string& s, const string& rs) {
  string k = s + "#" + rs;
  vector<int> lps = LPS(k);
  int m = k.size();
  if (lps[m - 1] + 2 * (int) pre.size() > (int) ans.size()) {
    ans = pre + k.substr(0, lps[m - 1]) + suf;
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> t;
    rt = t;
    reverse(rt.begin(), rt.end());
    ans = pre = suf = "";
    checkFront(t, rt);
    if ((int) ans.size() == (int) t.size()) {
      cout << ans << '\n';
      continue;
    }
    checkFront(rt, t);
    int pos = -1;
    int len = t.size();
    for (int i = 0; i < len; i++) {
      if (t[i] == t[len - i - 1]) {
        pos = i;
      } else {
        break;
      }
    }
    if (pos != -1) {
      pre = t.substr(0, pos + 1);
      suf = pre;
      reverse(suf.begin(), suf.end());
      t = t.substr(pos + 1, len - 2 * (pos + 1));
      rt = rt.substr(pos + 1, len - 2 * (pos + 1));
      checkFront(t, rt);
      checkFront(rt, t);
    }
    cout << ans << '\n';
  }

  return 0;
}