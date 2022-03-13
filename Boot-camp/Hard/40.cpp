#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> T;
    int size = T.size();
    S = T;
    reverse(T.begin(), T.end());

    string s = "", t = "";
    vector<int> s_v, t_v;
    for (int i = 0; i < size; i++) {
        if (S.at(i) != 'x') {
            s += S.at(i);
            s_v.push_back(i);
        }
    }
    
    for (int i = 0; i < size; i++) {
        if (T.at(i) != 'x') {
            t += T.at(i);
            t_v.push_back(i);
        }
    }

    if (s == t) {
        int siz = (int)s_v.size();
        int ans = 0;
        ans += abs(s_v.at(0) - t_v.at(0));
        for (int i = 1; i < siz; i++) {
            ans += abs((s_v.at(i) - s_v.at(i - 1)) - (t_v.at(i) - t_v.at(i - 1)));
        }
        ans += abs((siz - 1) - s_v.at(siz - 1) - ((siz - 1) - t_v.at(siz - 1)));

        cout << ans / 2 << endl;
    }
    else cout << -1 << endl;
}