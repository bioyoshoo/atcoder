#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    sort(A.rbegin(), A.rend());

    ll ans = 0;
    priority_queue<ll> pq;
    pq.push(A[0]);
    for (int i = 1; i < N; i++) {
        ans += pq.top();
        pq.pop();
        for (int r = 0; r < 2; r++) pq.push(A[i]);
    }
    cout << ans << endl;
}