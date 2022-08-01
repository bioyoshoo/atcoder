#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    map<string, int> mp;
    rep(i, N) {
        string S; cin >> S;
        if (mp[S] == 0) cout << S << endl;
        else {
            int x = mp[S];
            string Sout = S + '(' + to_string(x) + ')';
            cout << Sout << endl;
        }
        mp[S]++;
    }
}