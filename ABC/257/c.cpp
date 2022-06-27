#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int a = 0;
    rep(i, N) if (S[i] == '1') a++;

    vector<ll> W(N); rep(i, N) cin >> W[i];

    vector<pair<ll, char>> V;
    rep(i, N) V.push_back({W[i], S[i]});
    sort(V.begin(), V.end());

    int ans = a;
    int c = 0;
    for (int i = 0; i < N;) {
        int j = i;
        while (j < N && V[i].first == V[j].first) {
            if (V[j].second == '0') c++;
            else if (V[j].second == '1') a--;
            j++;
        }
        ans = max(ans, c + a);
        i = j;
    }
    cout << ans << endl;
}