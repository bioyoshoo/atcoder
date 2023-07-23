#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, H, W; cin >> N >> H >> W;
    vector<int> A;
    rep(i, N) {
        int a, b; cin >> a >> b;
        A.push_back(a - 1); A.push_back(b - 1);
    }

    int sum = 0;
    rep(i, 2*N) sum = sum ^ A[i];

    if (sum == 0) cout << "Second" << endl;
    else cout << "First" << endl;
}
