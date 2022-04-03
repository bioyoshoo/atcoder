#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int64_t N = (int64_t)S.size();

    vector<pair<char, int64_t>> V;
    for (int64_t i = 0; i < N;) {
        int64_t j = i + 1;
        while (j < N && S[i] == S[j]) j++;
        V.push_back({S[i], j - i});
        i = j;
    }
    int64_t n = (int64_t)V.size();

    int64_t ans = 0;
    for (int64_t i = 0; i < n; i++) {
        ans += V[i].second * (V[i].second + 1) / 2;
        if (i + 1 < n && V[i].first == '<' && V[i + 1].first == '>') {
            ans -= min(V[i].second, V[i + 1].second);
        }
    }

    cout << ans << endl;
}