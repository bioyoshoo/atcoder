#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int k; cin >> k;
    vector<int> X(k), Y(k);
    rep(i, k) cin >> X[i] >> Y[i];

    vector<int> C(8);
    rep(i, 8) C[i] = i;

    do {
        bool check = true;
        rep(i, k) {
            bool find = false;
            rep(j, 8) if (X[i] == j && Y[i] == C[j]) find = true;
            if (!find) check = false;
        }
        if (!check) continue;

        set<int> st1, st2;
        bool check2 = true;
        rep(r, 8) {
            int m = r - C[r];
            if (st1.count(m)) {
                check2 = false;
                break;
            }
            else st1.insert(m);

            int p = r + C[r];
            if (st2.count(p)) {
                check2 = false;
                break;
            }
            else st2.insert(p);
        }

        if (check2) break;

    } while (next_permutation(C.begin(), C.end()));

    vector<vector<char>> ans(8, vector<char>(8, '.'));
    rep(i, 8) ans[i][C[i]] = 'Q';

    rep(i, 8) rep(j, 8) {
        cout << ans[i][j];
        if (j == 7) cout << endl;
    }
}