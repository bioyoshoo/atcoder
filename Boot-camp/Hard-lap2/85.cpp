#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> X(N), Y(N), H(N);
    for (int i = 0; i < N; i++) cin >> X.at(i) >> Y.at(i) >> H.at(i);

    int64_t ans_cx, ans_cy, ans_h;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            for (int i = 0; i < N; i++) {
                int64_t h = H[i] + abs(X[i] - cx) + abs(Y[i] - cy);
                
            }
            if () {
                ans_cx = cx; ans_cy = cy; ans_h = cand_h;
                goto OUT;
            }
        }
    }
OUT:
    cout << ans_cx << " " << ans_cy << " " << ans_h << endl;
}