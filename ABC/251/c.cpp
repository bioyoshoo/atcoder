#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    map<string, ll> cnt, origin_score, origin_id;
    for (int i = 0; i < N; i++) {
        string S;
        ll T;
        cin >> S >> T;
        cnt[S]++;
        if (cnt[S] == 1) {
            origin_score[S] = T;
            origin_id[S] = i + 1;
        }
    }
    ll best_score = -1;
    string best_s;
    for (auto s: origin_score) {
        if (best_score < s.second) {
            best_score = s.second;
            best_s = s.first;
        }
        else if (best_score == s.second) {
            if (origin_id[best_s] > origin_id[s.first]) {
                best_score = s.second;
                best_s = s.first;
            }
        }
    }
    cout << origin_id[best_s] << endl;
}