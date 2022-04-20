#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
    if (a < b) a = b;
    return;
}

void chmin(int &a, int b) {
    if (a > b) a = b;
    return;
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    int x1 = 0, x2 = W, y1 = 0, y2 = H;
    
    for (int i = 0; i < N; i++) {
        int x, y, a;
        cin >> x >> y >> a;

        if (a == 1) chmax(x1, x);
        else if (a == 2) chmin(x2, x);
        else if (a == 3) chmax(y1, y);
        else if (a == 4) chmin(y2, y);
    }

    cout << max(0, x2 - x1) * max(0, y2 - y1) << endl;
}