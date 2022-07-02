#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using cord = pair<int, int>;

int main() {
    int N; cin >> N;
    
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) {
        ll a; cin >> a;
        for (int j = N - 1; j >= 0; j--) {
            A[i][j] = a % 10;
            a /= 10;
        }
    }
    vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<ll> ans;
    
    rep(i, N) {
        rep(j, N) {
            rep(r, 8) {
                ll cand = A[i][j] * pow(10, N - 1);
                int x = i, y = j;
                for (int k = N - 2; k >= 0; k--) {
                    int next_x = (x + dx[r]) % N, next_y = (y + dy[r]) % N;
                    if (next_x < 0) next_x += N;
                    if (next_y < 0) next_y += N;
                    cand += A[next_x][next_y] * pow(10, k);
                    x = next_x; y = next_y;
                }
                ans.push_back(cand);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans[0] << endl;
}