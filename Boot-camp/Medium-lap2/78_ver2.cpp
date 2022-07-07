#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int N = S.size();
    ll K; cin >> K;
    
    map<char, int> mp;
    for (auto s: S) mp[s]++;

    ll ans;
    if (mp.size() != 1) {
        ll block = 0;
        int right = 0;
        for (int left = 0; left < N;) {
            while (right < N && S[left] == S[right]) right++;
            block += (right - left) / 2;
            if (right == left) right++;
            left = right;
        }

        string T = S + S;
        ll two_blocks = 0;
        right = 0;
        for (int left = 0; left < 2 * N;) {
            while (right < 2 * N && T[left] == T[right]) right++;
            two_blocks += (right - left) / 2;
            if (right == left) right++;
            left = right;
        }

        int joint = 2 * block - two_blocks;
        ans = K * block - (K - 1) * joint;
    }
    else ans = K * (ll)S.size() / 2;

    cout << ans << endl;
}