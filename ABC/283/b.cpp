#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    int Q; cin >> Q;
    rep(i, Q) {
        int a, k; cin >> a >> k;
        k--;
        if (a == 1) {
            int x; cin >> x;
            A[k] = x;
        }
        else if (a == 2) {
            cout << A[k] << endl;
        }
    } 
}