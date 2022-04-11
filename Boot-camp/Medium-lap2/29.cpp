#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int s_n = s.size(), t_n = t.size();
    int min_n = min(s_n, t_n);

    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());

    string ans = "";
    for (int i = 0; i < min_n; i++) {
        if (s[i] - '0' > t[i] - '0') {
            ans = "No";
            break;
        }
        else if (s[i] - '0' < t[i] - '0') {
            ans = "Yes";
            break;
        }
    }
    if (ans == "") {
        if (s_n < t_n) ans = "Yes";
        else ans = "No";
    }

    cout << ans << endl;
}