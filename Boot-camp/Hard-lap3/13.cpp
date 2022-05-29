#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

string padding(string S) {
    int rep = 3 - S.size();
    string add = "";
    for (int r = 0; r < rep; r++) add += '0';
    string res = add + S;
    return res;
}

int main() {
    int N; cin >> N;
    string S; cin >> S;

    ll ans = 0;
    for (int i = 0; i < 1000; i++) {
        string T = to_string(i);
        T = padding(T);

        int cur = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == T[cur]) cur++;
        }
        if (cur == 3) ans++;
    }
    cout << ans << endl;
}