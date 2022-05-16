#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    string S; cin >> S;

    ll ans = -1;
    for (int i = 1; i <= N; i++) {
        if (N % i != 0) continue;
        
        int change = 0;
        for (int s = 0; s < i; s++) {
            vector<int> cnt(26, 0);
            for (int j = s; j < N; j += i) cnt[S[j] - 'a']++;
            int mx = 0;
            for (int j = 0; j < 26; j++) mx = max(mx, cnt[j]);
            change += N / i - mx;
        }

        if (change <= K) {
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;
}