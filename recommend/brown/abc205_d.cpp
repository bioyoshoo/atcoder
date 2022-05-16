#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<ll> B(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) B[0] = A[0] - 1;
        else B[i] = A[i] - A[i - 1] - 1;
    }
    for (int i = 1; i < N; i++) B[i] += B[i - 1];

    for (int i = 0; i < Q; i++) {
        ll K; cin >> K;
        
        ll ans = 0;
        int ind = lower_bound(B.begin(), B.end(), K) - B.begin();
        if (ind > 0) {
            ind -= 1;
            ans = A[ind] + (K - B[ind]);
        }
        else ans = K;
        
        cout << ans << endl;
    }
}