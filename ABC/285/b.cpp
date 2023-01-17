#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string S; cin >> S;

    for (int i = 1; i <= N - 1; i++) {
        int l = 0;
        rep(j, N) {
            if (j + i < N && S[j] != S[j + i]) l++;
            else break;
        }
        cout << l << endl;
    }
}