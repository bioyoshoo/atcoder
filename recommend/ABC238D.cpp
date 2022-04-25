#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<bool> ans(T);

    for (int i = 0; i < T; i++) {
        int64_t a, s;
        cin >> a >> s;

        int64_t x = 0, power = 1;
        set<int> residual;
        for (int k = 0; k <= 60; k++) {
            if (a & (1LL << k)) x += power;
            else residual.insert(k);
            power *= 2;
        }

        int64_t y = s - 2 * x;
        if (y >= 0) {
            bool flag = true;
            for (int k = 0; k <= 60; k++) {
                if ((y & (1LL << k)) && !residual.count(k)) flag = false;
            }
            if (flag) ans.at(i) = true;
            else ans.at(i) = false;
        }
        else ans.at(i) = false;
    }

    for (int i = 0; i < T; i++) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}