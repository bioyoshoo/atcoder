#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    set<ll> ans;
    for (int i = 0; i < N; i++) {
        if (A[i] <= W) ans.insert(A[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll sum = A[i] + A[j];
            if (sum <= W) ans.insert(sum);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                ll sum = A[i] + A[j] + A[k];
                if (sum <= W) ans.insert(sum);
            }
        }
    }
    cout << ans.size() << endl;
}