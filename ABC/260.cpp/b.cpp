#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

int main() {
    int N, X, Y, Z; cin >> N >> X >> Y >> Z;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vector<bool> result(N, false);
    vector<pair<int, int>> math(N), eng(N), sum(N);
    rep(i, N) math[i] = {A[i], i};
    rep(i, N) eng[i] = {B[i], i};
    rep(i, N) sum[i] = {A[i] + B[i], i};

    sort(math.begin(), math.end(), cmp);
    sort(eng.begin(), eng.end(), cmp);
    sort(sum.begin(), sum.end(), cmp);

    rep(i, X) {
        int id;
        tie(ignore, id) = math[i];
        result[id] = true;
    }

    int cnt = 0;
    rep(i, N) {
        if (cnt == Y) break;

        int id;
        tie(ignore, id) = eng[i];
        if (result[id]) continue;
        else {
            result[id] = true;
            cnt++;
        }
    }

    cnt = 0;
    rep(i, N) {
        if (cnt == Z) break;

        int id;
        tie(ignore, id) = sum[i];
        if (result[id]) continue;
        else {
            result[id] = true;
            cnt++;
        }
    }

    rep(i, N) {
        if (result[i]) cout << i + 1 << endl;
    }
}