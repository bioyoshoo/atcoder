#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    string S; cin >> S;

    vector<ll> V;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            int num_A = 0, num_C = 0;
            
            int j = i - 1;
            while (j >= 0 && S[j] == 'A') j--;
            num_A = i - j - 1;

            int k = i + 1;
            while (k <= N && S[k] == 'C') k++;
            num_C = k - i - 1;

            int potential = min(num_A, num_C);
            V.push_back(potential);
        }
    }
    int ans = 0;
    if (V.size() > 0) {
        sort(V.rbegin(), V.rend());
        int right = 0, left = V.size() - 1;
        int order = 0;
        while (right <= left) {
            if (order == 0) {
                if (V[right] == 0) break;
                V[right]--;
                if (V[right] == 0) right++;
                order = 1 - order;
                ans++;
            }
            else if (order == 1) {
                if (V[left] == 0) break;
                V[left] = 0;
                left--;
                order = 1 - order;
                ans++;
            }
        }
    }
    cout << ans << endl;
}