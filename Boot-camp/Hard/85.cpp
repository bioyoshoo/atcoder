#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> X(N), Y(N), H(N);
    for (int i = 0; i < N; i++) cin >> X.at(i) >> Y.at(i) >> H.at(i);
    
    int ans_x = 0, ans_y = 0, ans_h = 0;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int64_t h = 1;
            for (int i = 0; i < N; i++) if (H.at(i) > 0) h = H.at(i) + abs(X.at(i) - cx) + abs(Y.at(i) - cy);
            bool ok = true;
            for (int i = 0; i < N; i++) if (max(h - abs(X[i] - cx) - abs(Y[i] - cy), (int64_t)0) != H.at(i)) ok = false;

            if (ok) {
                ans_x = cx;
                ans_y = cy;
                ans_h = h;
                goto OUT;
            }
        }
    }

OUT:
    cout << ans_x << " " << ans_y << " " << ans_h << endl;
}