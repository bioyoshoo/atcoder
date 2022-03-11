#include <bits/stdc++.h>
using namespace std;
using p = pair<int64_t, int64_t>;
const int64_t MIN = -1e10;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;
    vector<p> Robo(N);
    for (int i = 0; i < N; i++) {
        int64_t X, L;
        cin >> X >> L;
        Robo.push_back(make_pair(X + L, X - L));
    }

    sort(Robo.begin(), Robo.end());

    int64_t ans = 0;
    int64_t cur = MIN;
    for (int i = 0; i < N; i++) {
        if (cur <= Robo.at(i).second) {
            cur = Robo.at(i).first;
            ans++;
        }
    }
    
    cout << ans << endl;
}